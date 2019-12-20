#include "Source/Engine/Window/Window.h"
#include "Source/Engine/Renderer/Backend/GL/Common.h"
#include "Source/Hx.h"
#include "Dependencies/SDL2/include/SDL.h"
#include <cstdio>

using namespace Hx::Renderer::Backend;

int main(int argc, char* argv[]) {
	Hx::Math::Vec3D v(1, 1, 1);
	Hx::Math::Vec3F v1;

	v1 = v;

	std::printf("%f %f %f\n", v1.X, v1.Y, v1.Z);

	return 0;
}
