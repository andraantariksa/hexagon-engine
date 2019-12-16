#pragma once

#include "../../../Types.h"
#include "../../../../Config.h"
#include "../../../Window/Window.h"
#include "../IDevice.h"
#include "../IContext.h"


namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL { 
	
	typedef void* ContextHandle;

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

	void GLInit(
		const Hx::Window::Window& window,
		const OpenGLInitDesc& initDesc,
		ContextHandle* outContext);


	void GLMakeCurrent(
		const Hx::Window::Window& window,
		ContextHandle context);

	void GLDestroy(ContextHandle* outContext);

}}}}
