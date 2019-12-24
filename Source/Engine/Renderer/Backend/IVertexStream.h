#pragma once

#include "Common.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct IVertexStream
	{
		virtual ~IVertexStream() { }

	protected:
		IVertexStream() { };
	};

}}}
