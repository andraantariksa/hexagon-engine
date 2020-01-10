#pragma once

#include "IVertexShader.hpp"
#include "IPixelShader.hpp"

namespace Hx { namespace Renderer { namespace Backend {

	struct HX_NOVTABLE IShaderProgram
	{
		virtual ~IShaderProgram() { }

		virtual IVertexShader* GetVertexShader() = 0;
		virtual IPixelShader* GetPixelShader() = 0;

	protected:
		IShaderProgram() { }
	};

}}}
