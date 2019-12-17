#pragma once

namespace Hx { namespace Renderer { namespace Backend {

	struct IDepthStencilState
	{
		virtual ~IDepthStencilState() { }

	protected:
		IDepthStencilState() { }
	};

}}}
