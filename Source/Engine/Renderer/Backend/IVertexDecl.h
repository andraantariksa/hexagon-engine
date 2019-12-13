#pragma once

#include "Common.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct IVertexDecl
	{
		IVertexDecl() = delete;
		virtual ~IVertexDecl() { }

		virtual size_t GetNumElements() = 0;
		virtual void GetElements(VertexElement* elements) = 0;
	};

}}}
