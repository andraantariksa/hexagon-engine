#pragma once

#include "IRenderContext.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct HX_NOVTABLE IDeferredRenderContext : public IRenderContext
	{
		virtual ~IDeferredRenderContext() { }

	protected:
		IDeferredRenderContext() { }
	};

}}}
