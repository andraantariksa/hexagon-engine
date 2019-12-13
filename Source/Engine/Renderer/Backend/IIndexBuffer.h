#pragma once

#include "../../Types.h"
#include "Common.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct IIndexBuffer
	{
		virtual ~IIndexBuffer() { }

	protected:
		IIndexBuffer() { }
	};

}}}
