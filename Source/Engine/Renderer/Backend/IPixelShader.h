#pragma once

namespace Hx { namespace Renderer { namespace Backend {

	struct IPixelShader
	{
		IPixelShader() = delete;
		virtual ~IPixelShader() { }
	};

}}}
