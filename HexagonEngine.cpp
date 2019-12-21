#include "Source/Engine/Window/Window.h"
#include "Source/Engine/Renderer/Backend/GL/Common.h"
#include "Source/Hx.h"
#include "Dependencies/SDL2/include/SDL.h"
#include <cstdio>
#include <iostream>

using namespace Hx::Renderer::Backend;

int main(int argc, char* argv[]) {
	Hx::Math::Vec3F v(1, 2, 2);
	Hx::Math::Vec3F v1(1, 2, 1);
	Hx::Math::Vec3F v2(3, 2, 1);

	std::cout << Hx::Math::__Bruh<int, int, unsigned int>::i << std::endl;

	return 0;
}
