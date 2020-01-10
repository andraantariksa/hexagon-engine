#pragma once

#include "../../Types.hpp"

namespace Hx { namespace Renderer { namespace Backend {

	struct HX_NOVTABLE IBuffer
	{
		virtual ~IBuffer() { }

	protected:
		IBuffer() { }
	};

}}}
