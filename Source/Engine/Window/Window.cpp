#include "Window.h"
#include "../../Config.h"

#ifdef HX_PLATFORM_SDL2
#include "Native/SDL2/WindowSDL2.h"
#endif

namespace Hx { namespace Window {

	Window::Window(int width, int height, const std::string& title, int posX, int posY)
#ifdef HX_PLATFORM_SDL2
		: NativeWindow(new Native::SDL2::WindowSDL2(width, height, title, posX, posY))
#else
		: NativeWindow(new Native::Null::WindowNull(width, height, title, posX, posY))
#endif
	{
	}

	Window::~Window()
	{
	}

}}
