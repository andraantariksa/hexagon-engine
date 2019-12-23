#include "Source/Engine/Window/Window.h"
#include "Source/Engine/Renderer/Backend/GL/DeviceGL.h"
#include "Source/Hx.h"
#include "Dependencies/SDL2/include/SDL.h"
#include <cstdio>
#include <iostream>

using namespace Hx::Renderer::Backend;

static const char c[] =
"#version 330\n"
"in vec3 pos;"
"in vec3 color;"
"out vec3 outColor;"
"void main()"
"{"
"gl_Position = vec4(pos, 1.0);"
"outColor = color;"
"}";

static const char cps[] =
"#version 330\n"
"in vec3 inColor;"
"layout(location = 0) out vec4 color;"
"void main()"
"{"
"color = vec4(inColor, 1.0);"
"}";

int main(int argc, char* argv[]) {
	Hx::Window::Window* window = new Hx::Window::Window();
	OpenGL::DeviceGL* device = new OpenGL::DeviceGL();
	OpenGL::OpenGLInitDesc initDesc;
	IContext* ctx;
	IFrameBuffer* swap;
	IVertexShader* vs;
	IPixelShader* ps;
	IShaderProgram* program;
	IVertexDecl* vd;
	static const float f[4] = { 1.0f, 0.0f, 0.0f, 1.0f };

	if (device->Create(*window))
		std::cout << "OpenGL initialized\n";

	ctx = device->GetImmediateContext();
	swap = device->GetSwapBuffer();

	vs = device->CreateVertexShader(sizeof(c), c);
	ps = device->CreatePixelShader(sizeof(cps), cps);
	program = device->CreateShaderProgram(vs, ps);
	vd = device->CreateVertexDeclaration(program, nullptr, 0); // auto-detect vertex declaration

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

		device->SwapBuffers();
	}

	delete vd;
	delete program;
	delete vs;
	delete ps;
	delete device;
	delete window;
	return 0;
}
