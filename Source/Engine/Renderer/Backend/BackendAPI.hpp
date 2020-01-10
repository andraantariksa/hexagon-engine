#pragma once

#include "../../Types.hpp"

namespace Hx { namespace Renderer { namespace Backend {

	enum class BackendAPI : int8
	{
		DX11 = 0,
		OGL,
		Vulkan,

		Count
	};

} } }
