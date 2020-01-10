#pragma once

#include "../../Types.hpp"
#include "Common.hpp"

namespace Hx { namespace Renderer { namespace Backend {

	struct HX_NOVTABLE ITextureBase
	{
		virtual ~ITextureBase() { }

	protected:
		ITextureBase() { }
	};

}}}
