#pragma once

#include "Common.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct IContext
	{
		IContext() = delete;
		virtual ~IContext() { };

		virtual void ClearFrameBuffer(IFrameBuffer* frameBuffer) = 0;
		virtual void ClearDepthBuffer(IDepthBuffer* depthBuffer) = 0;
	};

}}}
