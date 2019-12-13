#pragma once

namespace Hx { namespace Renderer { namespace Backend {

	struct IDepthStencilBuffer
	{
		IDepthStencilBuffer() = delete;
		virtual ~IDepthStencilBuffer() { }
	};

}}}
