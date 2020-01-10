#pragma once

#include "../../Types.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct HX_NOVTABLE IBuffer
	{
		virtual ~IBuffer() { }

	protected:
		IBuffer() { }
	};

}}}
