#pragma once

#include "IContext.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct IDeferredContext : public IContext
	{
		IDeferredContext() = delete;
		virtual ~IDeferredContext() { }
	};

}}}
