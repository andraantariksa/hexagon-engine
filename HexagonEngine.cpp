#include "Source/Engine/Window/Window.h"
#include "Dependencies/SDL2/include/SDL.h"
#include <cstdio>

int main(int argc, char* argv[]) {
	std::printf("Starting the Hexagon Engine");
	Hx::Window::Window win = Hx::Window::Window::Builder()
		.SetSize(1280, 720)
		.Build();

	SDL_Delay(3000);
	return 0;
}
