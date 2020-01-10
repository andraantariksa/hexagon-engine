#include "Window.hpp"
#include "../../Config.hpp"

#ifdef HX_PLATFORM_SDL2
#include "Native/SDL2/WindowSDL2.hpp"
#endif

namespace Hx { namespace Window {

	Window::Window(int32 width, int32 height, const std::string& title, int32 posX, int32 posY)
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
