#include "Common.h"
#include "Common.h"
#include "Common.h"

#ifdef HX_PLATFORM_SDL2
#include <SDL.h>
#include "../../../Window/Native/SDL2/WindowSDL2.h"
#endif

#include <cassert>

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {

	using Hx::Window::Window;
	
#if defined(HX_PLATFORM_SDL2)
	void GLInit_SDL2(
		SDL_Window* window,
		const OpenGLInitDesc& initDesc,
		ContextHandle* outContext);
#elif defined(HX_PLATFORM_WIN32)
	void GLInit_Win32(
		HWND hWnd,
		const OpenGLInitDesc& initDesc,
		ContextHandle* outContext);
#endif

	void GLInit(
		const Window& window,
		const OpenGLInitDesc& initDesc,
		ContextHandle* outContext)
	{
#ifdef HX_PLATFORM_SDL2
		using WindowSDL2 = Hx::Window::Native::SDL2::WindowSDL2;
		WindowSDL2* native = static_cast<WindowSDL2*>(window.GetNative());
		SDL_Window* sdlWindow = native->GetNativeHandle();
		GLInit_SDL2(sdlWindow, initDesc, outContext);
#endif
	}

	void GLMakeCurrent(
		const Window& window,
		ContextHandle context)
	{
		using WindowSDL2 = Hx::Window::Native::SDL2::WindowSDL2;
		assert(context != nullptr);
#if defined(HX_PLATFORM_SDL2)
		WindowSDL2* native = static_cast<WindowSDL2*>(window.GetNative());
		SDL_Window* sdlWindow = native->GetNativeHandle();
		SDL_GL_MakeCurrent(sdlWindow, (SDL_GLContext)context);
#endif
	}

	void GLDestroy(ContextHandle* outContext)
	{
		if (outContext == nullptr)
			return;

#if defined(HX_PLATFORM_SDL2)
		SDL_GL_DeleteContext(*outContext);
#endif

		*outContext = nullptr;
	}

	void GLSwapBuffers(Window& window)
	{
		using WindowSDL2 = Hx::Window::Native::SDL2::WindowSDL2;
#ifdef HX_PLATFORM_SDL2
		SDL_GL_SwapWindow(static_cast<WindowSDL2*>(window.GetNative())->GetNativeHandle());
#endif
	}

#if defined(HX_PLATFORM_SDL2)
	void GLInit_SDL2(
		SDL_Window* window,
		const OpenGLInitDesc& desc,
		ContextHandle* outContext)
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

		*outContext = (ContextHandle)context;
		
		SDL_GL_SetSwapInterval(1);
	}

#elif defined(HX_PLATFORM_WIN32)
	void GLInit_Win32(
		HWND window,
		const OpenGLInitDesc& desc,
		ContextHandle* outContext)
	{
		// TODO: Add Win32 opengl initialization
	}
#endif

}}}}
