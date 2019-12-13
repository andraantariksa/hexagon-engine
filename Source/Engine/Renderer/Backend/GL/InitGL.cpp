#include "Common.h"

#include <cassert>

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

	void InitOpenGL_SDL2(
		SDL_Window* window,
		const OpenGLInitDesc& desc,
		OpenGLContext* outContext)
	{
		SDL_GLContext context;
		assert(window != nullptr && "Error: Window is nullptr");

		// Set context attributes
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, desc.MajorVer); // Set OpenGL standard
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, desc.MinorVer);

		// Set swap buffer attributes
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, desc.RedBits);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, desc.BlueBits);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, desc.GreenBits);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, desc.AlphaBits);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, desc.DepthBits);
		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, desc.StencilBits);

		// Initialize context!
		context = SDL_GL_CreateContext(window);

		// if fail, then just make it null
		if (context == nullptr)
		{
			*outContext = nullptr;
			return;
		}

		*outContext = (OpenGLContext)context;
	}

}}}}
