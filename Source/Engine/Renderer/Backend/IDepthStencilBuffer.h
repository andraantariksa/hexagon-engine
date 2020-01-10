#pragma once

#include "../../Types.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct HX_NOVTABLE IDepthStencilBuffer
	{
		virtual ~IDepthStencilBuffer() { }

	protected:
		IDepthStencilBuffer() { }
	};

}}}
