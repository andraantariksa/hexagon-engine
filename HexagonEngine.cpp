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
	IVertexShader* vs;
	IPixelShader* ps;
	IShaderProgram* program;
	IVertexDecl* vd;

	if (device->Create(*window))
		std::cout << "OpenGL initialized\n";

	vs = device->CreateVertexShader(sizeof(c), c);
	ps = device->CreatePixelShader(sizeof(cps), cps);
	program = device->CreateShaderProgram(vs, ps);
	vd = device->CreateVertexDeclaration(program, nullptr, 0);

	delete vd;
	delete program;
	delete vs;
	delete ps;
	delete device;
	delete window;
	return 0;
}
