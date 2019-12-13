#pragma once

#include "../../../Types.h"
#include "../../../../Config.h"
#include "../../../Window/Window.h"

#ifdef HX_PLATFORM_SDL2
#include <SDL.h>
#include "../../../Window/Native/SDL2/WindowSDL2.h"
#endif

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL { 
	
	typedef void* OpenGLContext;

	struct OpenGLInitDesc
	{
		int32 MajorVer;
		int32 MinorVer;

		// Swap buffer bits
		int32 RedBits = 8;
		int32 GreenBits = 8;
		int32 BlueBits = 8;
		int32 AlphaBits = 8;
		int32 DepthBits = 24;
		int32 StencilBits = 8;
	};

#ifdef HX_PLATFORM_SDL2
	// SDL2 Initialization
	void InitOpenGL_SDL2(
		SDL_Window* window,
		const OpenGLInitDesc& initDesc,
		OpenGLContext* outContext);
#endif

	void InitOpenGL(
		const Hx::Window::Window& window,
		const OpenGLInitDesc& initDesc,
		OpenGLContext* outContext);

}}}}
