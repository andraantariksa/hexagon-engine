#pragma once

#include "../../Types.h"
#include "Common.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct HX_NOVTABLE ITextureBase
	{
		virtual ~ITextureBase() { }

	protected:
		ITextureBase() { }
	};

}}}
