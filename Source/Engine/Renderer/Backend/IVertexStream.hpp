#pragma once

#include "../../Types.hpp"

namespace Hx { namespace Renderer { namespace Backend {

	struct HX_NOVTABLE IVertexStream
	{
		virtual ~IVertexStream() { }

	protected:
		IVertexStream() { };
	};

}}}
