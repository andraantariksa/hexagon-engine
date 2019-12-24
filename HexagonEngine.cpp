#include "Source/Engine/Window/Window.h"
#include "Source/Engine/Renderer/Backend/GL/DeviceGL.h"
#include "Source/Hx.h"
#include "Dependencies/SDL2/include/SDL.h"
#include <cstdio>
#include <iostream>

using namespace Hx::Renderer::Backend;

static const char c[] =
"#version 330 core\n"
"in vec3 pos;"
"in vec3 color;"
"out vec3 outColor;"
"void main()"
"{"
"gl_Position = vec4(pos, 1.0);"
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

int main(int argc, char* argv[]) {
	Hx::Window::Window* window = new Hx::Window::Window();
	OpenGL::DeviceGL* device = new OpenGL::DeviceGL();
	OpenGL::OpenGLInitDesc initDesc;
	IContext* ctx;
	IFrameBuffer* swap;
	IVertexShader* vs;
	IPixelShader* ps;
	IShaderProgram* program;
	IVertexStream* vstream;
	IBuffer* vb;
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

	bool exit = false;
	while (!exit)
	{
		Hx::Window::Event e;
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

		ctx->SetShaderProgram(program);
		ctx->SetVertexStream(vstream);
		ctx->SetPrimitiveTopology(PrimitiveTopology::TriList);
		ctx->Draw(3, 0);

		device->SwapBuffers();
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
