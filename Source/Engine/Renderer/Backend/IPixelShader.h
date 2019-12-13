#pragma once

namespace Hx { namespace Renderer { namespace Backend {

	struct IPixelShader
	{
		virtual ~IPixelShader() { }
	
	protected:
		IPixelShader() { }
	};

}}}
