#pragma once

namespace Hx { namespace Renderer { namespace Backend {

	struct IFrameBuffer
	{
		virtual ~IFrameBuffer() { }

	protected:
		IFrameBuffer() { }
	};

}}}
