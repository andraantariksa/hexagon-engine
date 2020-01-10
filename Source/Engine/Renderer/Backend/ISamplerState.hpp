#pragma once

#include "../../Types.hpp"

namespace Hx { namespace Renderer { namespace Backend {

	struct HX_NOVTABLE ISamplerState
	{
	public:
		virtual ~ISamplerState() {}
	
	protected:
		ISamplerState() { }
	};

}}}
