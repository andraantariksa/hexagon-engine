#pragma once

namespace Hx { namespace Renderer { namespace Backend {

	struct IFrameBuffer
	{
		IFrameBuffer() = delete;
		virtual ~IFrameBuffer() { }
	};

}}}
