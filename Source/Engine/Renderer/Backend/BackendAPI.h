#pragma once

#include "../../Types.h"

namespace Hx { namespace Renderer { namespace Backend {

	enum class BackendAPI : int8
	{
		DX11 = 0,
		OGL,
		Vulkan,

		Count
	};

} } }
