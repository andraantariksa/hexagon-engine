#pragma once

#include "../../Types.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct HX_NOVTABLE IVertexShader
	{
		virtual ~IVertexShader() { }

	protected:
		IVertexShader() { }
	};

}}}
