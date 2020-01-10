#if 0
#include "Source/Engine/Window/Window.h"
#include "Source/Engine/Renderer/Backend/GL/DeviceGL.h"
#include "Source/Hx.h"
#include "Dependencies/SDL2/include/SDL.h"
#include <cstdio>
#include <iostream>
#include <DirectXMath.h>
#include <chrono>

#undef main

using namespace Hx::Renderer::Backend;

static const char c[] =
"#version 330 core\n"
"in vec3 pos;"
"in vec3 color;"
"out vec3 outColor;"
"layout(std140) uniform MyUniformBuffer"
"{"
"mat4 wvp;"
"};"
"void main()"
"{"
"gl_Position = wvp * vec4(pos, 1.0);"
"outColor = color;"
"}";

static const char cps[] =
"#version 330 core\n"
"in vec3 outColor;"
"out vec4 color;"
"void main()"
"{"
"color = vec4(outColor, 1.0);"
"}";

static float vertexdata[] = {
	-0.5,-0.5, 0.0, 1.0, 0.0, 0.0,
	0.5,-0.5, 0.0, 0.0, 1.0, 0.0,
	0.0, 0.5, 0.0,0.0, 0.0, 1.0
};

struct MyUniformBuffer
{
	DirectX::XMMATRIX wvp;
};

MyUniformBuffer g_Buffer, g_Buffer2;

typedef std::chrono::time_point<std::chrono::high_resolution_clock> HighResolutionClock;

int main(int argc, char* argv[]) {
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
	Hx::Math::Vec4F v = Hx::Math::Vec4F(1.0, 1.0, 1.0, 1.0);
	static const float f[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

	if (device->Create(*window))
		std::cout << "OpenGL initialized\n";

	ctx = device->GetImmediateContext();
	swap = device->GetSwapBuffer();

	vs = device->CreateVertexShader(sizeof(c), c);
	ps = device->CreatePixelShader(sizeof(cps), cps);
	program = device->CreateShaderProgram(vs, ps);
	vb = device->CreateVertexBuffer(ResourceUsage::Default, sizeof(vertexdata), (void*)vertexdata);
	// we use auto-detect shader attribute for now, since we don't have manual configuration method, it'll comes later
	vstream = device->CreateVertexStream(program, nullptr, 0, vb, nullptr);
	ub = device->CreateUniformBuffer(sizeof(MyUniformBuffer), nullptr);
	ub2 = device->CreateUniformBuffer(sizeof(MyUniformBuffer), nullptr);

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

#if 1
int main()
{
	return 0;
}
#endif
