#pragma once

namespace Hx { namespace Renderer { namespace Backend {

	struct IDepthStencilBuffer
	{
		virtual ~IDepthStencilBuffer() { }

	protected:
		IDepthStencilBuffer() { }
	};

}}}
