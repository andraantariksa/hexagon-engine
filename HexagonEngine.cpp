#include "Source/Engine/Window/Window.h"
#include "Source/Engine/Renderer/Backend/GL/Common.h"
#include "Dependencies/SDL2/include/SDL.h"
#include <cstdio>

using namespace Hx::Renderer::Backend;

int main(int argc, char* argv[]) {
	std::printf("Starting the Hexagon Engine\n");
	Hx::Window::Window win = Hx::Window::Window::Builder()
		.SetSize(1280, 720)
		.Build();

	OpenGL::ContextHandle context;
	OpenGL::OpenGLInitDesc initDesc;
	initDesc.MajorVer = 3;
	initDesc.MinorVer = 3;

	OpenGL::GLInit(win, initDesc, &context);

	if (context != nullptr)
		std::printf("OpenGL initialized\n");

	SDL_Delay(3000);
	SDL_GL_DeleteContext(context);
	return 0;
}
