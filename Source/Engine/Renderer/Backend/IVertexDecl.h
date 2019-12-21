#pragma once

#include "Common.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct IVertexDecl
	{
		virtual ~IVertexDecl() { }

	protected:
		IVertexDecl() { };
	};

}}}
