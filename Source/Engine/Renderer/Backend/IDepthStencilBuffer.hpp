#pragma once

#include "../../Types.hpp"

namespace Hx { namespace Renderer { namespace Backend {

	struct HX_NOVTABLE IDepthStencilBuffer
	{
		virtual ~IDepthStencilBuffer() { }

	protected:
		IDepthStencilBuffer() { }
	};

}}}
