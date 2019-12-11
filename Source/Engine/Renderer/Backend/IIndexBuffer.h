#pragma once

#include "../../Types.h"
#include "Common.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct IIndexBuffer
	{
		IIndexBuffer() = delete;
		virtual ~IIndexBuffer() { }
	};

}}}
