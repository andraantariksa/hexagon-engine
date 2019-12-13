#include "Common.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {

	using Hx::Window::Window;
	
	void InitOpenGL(
		const Window& window,
		const OpenGLInitDesc& initDesc,
		OpenGLContext* outContext)
	{
#ifdef HX_PLATFORM_SDL2
		using WindowSDL2 = Hx::Window::Native::SDL2::WindowSDL2;
		WindowSDL2* native = dynamic_cast<WindowSDL2*>(window.GetNative());
		SDL_Window* sdlWindow = native->GetNativeHandle();
		InitOpenGL_SDL2(sdlWindow, initDesc, outContext);
#endif
	}

}}}}
