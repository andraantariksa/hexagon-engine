#include "Window.h"
#include "../../Config.h"

#ifdef HX_PLATFORM_SDL2
#include "Native/SDL2/WindowSDL2.h"
#endif

namespace Hx { namespace Window {

	Window::Window(int32 width, int32 height, const std::string& title, int32 posX, int32 posY)
#ifdef HX_PLATFORM_SDL2
		: mNativeWindow(new Native::SDL2::WindowSDL2(width, height, title, posX, posY))
#else
		: mNativeWindow(new Native::Null::WindowNull(width, height, title, posX, posY))
#endif
	{
	}

	Window::~Window()
	{
	}

}}
