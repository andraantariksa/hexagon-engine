#define ENABLE_THIS 1

#if ENABLE_THIS == 1
#include "../Source/Engine/Window/Window.hpp"
#include "../Source/Engine/Renderer/Backend/GL/DeviceGL.hpp"
#include "../Source/Hx.hpp"
#include "../Dependencies/SDL2/include/SDL.h"
#include <cstdio>
#include <iostream>
#include <DirectXMath.h>
#include <chrono>

#undef main

using namespace Hx::Renderer::Backend;

static const char cvs[] =
"#version 330 core\n"
"layout(location = 0) in vec3 pos;"
"layout(location = 1) in vec3 color;"
"layout(location = 2) in vec2 texcoord;"
"out vec3 outColor;"
"out vec2 outTexcoord;"
"layout(std140) uniform MyUniformBuffer"
"{"
"mat4 wvp;"
"};"
"void main()"
"{"
"gl_Position = wvp * vec4(pos, 1.0);"
"outColor = color;"
"outTexcoord = texcoord;"
"}";

static const char cps[] =
"#version 330 core\n"
"in vec3 outColor;"
"in vec2 outTexcoord;"
"out vec4 color;"
"uniform sampler2D tex;"
"uniform sampler2D tex1;"
"uniform sampler2D tex2;"
"void main()"
"{"
"color = vec4(texture(tex, outTexcoord).rgb, 1.0);"
"}";

static float vertexdata[] = {
	-0.5,-0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0,
	 0.5,-0.5, 0.0, 0.0, 1.0, 0.0, 0.5, 0.0,
	 0.0, 0.5, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0
};

struct MyUniformBuffer
{
	DirectX::XMMATRIX wvp;
};

MyUniformBuffer g_Buffer, g_Buffer2;

uint32 textureData[32 * 32];

VertexElement elem[3] = {
	{ "pos", nullptr, 0, ResourceFormat::R32G32B32_Float, 0 },
	{ "color", nullptr, 0, ResourceFormat::R32G32B32_Float, 12 },
	{ "texcoord", nullptr, 0, ResourceFormat::R32G32_Float, 24 }
};

typedef std::chrono::time_point<std::chrono::high_resolution_clock> HighResolutionClock;

int main(int argc, char* argv[])
{
	Hx::Window::Window* window = new Hx::Window::Window();
	IDevice* device = new OpenGL::DeviceGL();
	IRenderContext* ctx;
	IFrameBuffer* swap;
	IVertexShader* vs;
	IPixelShader* ps;
	IShaderProgram* program;
	IVertexStream* vstream;
	IBuffer* vb;
	IBuffer* ub, *ub2;
	ITexture2D* tex;
	ISamplerState* smp;
	Hx::Math::Vec4F v = Hx::Math::Vec4F(1.0, 1.0, 1.0, 1.0);
	static const float f[4] = { 1.0f, 0.0f, 0.0f, 1.0f };

	if (device->Create(*window))
		std::cout << "OpenGL initialized\n";

	ctx = device->GetImmediateContext();
	swap = device->GetSwapBuffer();

	vs = device->CreateVertexShader(sizeof(cvs), cvs);
	ps = device->CreatePixelShader(sizeof(cps), cps);
	program = device->CreateShaderProgram(vs, ps);
	vb = device->CreateVertexBuffer(ResourceUsage::Default, sizeof(vertexdata), (void*)vertexdata);
	// we use auto-detect shader attribute for now, since we don't have manual configuration method, it'll comes later
	vstream = device->CreateVertexStream(program, elem, 3, vb, nullptr);
	ub = device->CreateUniformBuffer(sizeof(MyUniformBuffer), nullptr);
	ub2 = device->CreateUniformBuffer(sizeof(MyUniformBuffer), nullptr);

	Texture2DDesc texdesc;
	texdesc.Width = 32;
	texdesc.Height = 32;
	texdesc.MipMapLevels = 1;
	texdesc.ArrayLength = 1;
	texdesc.Format = ResourceFormat::R8G8B8A8_Unorm;
	texdesc.Multisample.Count = 1;
	texdesc.Multisample.Quality = 0;
	texdesc.Usage = ResourceUsage::Default;
	texdesc.BindFlags = ResourceBindFlag::ShaderResource;
	texdesc.AccessFlags = ResourceAccess::NoAccess;
	texdesc.MiscFlags = ResourceMisc::None;

	for(int i = 0; i < 32; i++)
	{
		for(int j = 0; j < 32; j++)
		{
			uint32 val = rand();
			textureData[i * 32 + j] = val;
			srand(val);
		}
	}

	Texture2DResourceData texResData;
	texResData.DataPtr = textureData;
	texResData.Width = 32 * 4;

	tex = device->CreateTexture2D(texdesc, &texResData);

	SamplerStateDesc samplerdesc;
	samplerdesc.Filter = TextureFilter::MinMagMipNearest;
	samplerdesc.AddressU = TextureAddressing::Wrap;
	samplerdesc.AddressV = TextureAddressing::Wrap;
	samplerdesc.AddressW = TextureAddressing::Wrap;
	samplerdesc.MipLodBias = 0.0f;
	samplerdesc.MaxAnisotropy = 1;
	samplerdesc.CompFunction = CmpFunction::Always;
	samplerdesc.BorderColor[0] = 0.0f;
	samplerdesc.BorderColor[1] = 0.0f;
	samplerdesc.BorderColor[2] = 0.0f;
	samplerdesc.BorderColor[3] = 0.0f;
	samplerdesc.MinLod = 0;
	samplerdesc.MaxLod = std::numeric_limits<float>::max();

	smp = device->CreateSamplerState(samplerdesc);

	ctx->SetShaderProgram(program);
	uint32 uloc = ctx->GetUniformBufferIndex("MyUniformBuffer");
	ctx->SetShaderProgram(nullptr);

	float t = 0.0f;
	DirectX::XMMATRIX scale = DirectX::XMMatrixScaling(0.3f, 0.3f, 0.3f);
	DirectX::XMMATRIX proj = DirectX::XMMatrixPerspectiveFovRH(DirectX::XM_PIDIV2, (float)window->GetWidth()/(float)window->GetHeight(), 0.1f, 100.f);
	DirectX::XMMATRIX view = DirectX::XMMatrixIdentity();
	view = DirectX::XMMatrixTranslation(0.0f, 0.0f, -2.0f);
	HighResolutionClock oldt = std::chrono::high_resolution_clock::now(); // initialize first!
	bool exit = false;
	while (!exit)
	{
		HighResolutionClock currTime;
		Hx::Window::Event e;
		
		currTime = std::chrono::high_resolution_clock::now();
		double deltaTime = std::chrono::duration<double>(currTime - oldt).count();
		currTime = oldt;
		oldt = std::chrono::high_resolution_clock::now();

		while (window->PollEvent(e))
		{
			switch (e.Type)
			{
			case Hx::Window::EventType::WindowClose:
				exit = true;
				break;
			}
		}
		ctx->ClearFrameBuffer(swap, f);

		g_Buffer.wvp = DirectX::XMMatrixRotationY(DirectX::XMConvertToRadians(t * 100.0f)) * view * proj;
		//g_Buffer.wvp = DirectX::XMMatrixIdentity();
		//g_Buffer2.wvp = DirectX::XMMatrixMultiply(scale, DirectX::XMMatrixTranslation(0.3f, 0.0f, 0.0f));

		ctx->SetShaderProgram(program);
		ctx->SetShaderResource(ShaderType::PixelShader, 0, tex);
		ctx->SetSamplerState(ShaderType::PixelShader, 0, smp);
		ctx->SetUniformBufferData(ub, uloc, (void*)&g_Buffer, sizeof(MyUniformBuffer));
		ctx->SetVertexStream(vstream);
		ctx->SetPrimitiveTopology(PrimitiveTopology::TriList);
		ctx->Draw(3, 0);

		//ctx->SetUniformBufferData(ub2, uloc, (void*)&g_Buffer2, sizeof(MyUniformBuffer));
		//ctx->Draw(3, 0);

		device->SwapBuffers();
		t += (float)deltaTime;
		std::cout << "FPS: " << 1.f / deltaTime << std::endl;
	}

	delete ub;
	delete ub2;
	delete vstream;
	delete vb;
	delete program;
	delete vs;
	delete ps;
	delete device;
	delete window;
	return 0;
}
#endif

#include <spdlog/spdlog.h>

#if !ENABLE_THIS
int main()
{
	spdlog::info("test!");
	return 0;
}
#endif
