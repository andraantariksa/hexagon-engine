#pragma once

#include "Common.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct IBuffer
	{
		virtual ~IBuffer() { }

	protected:
		IBuffer() { }
	};

}}}
