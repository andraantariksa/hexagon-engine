#pragma once

#include "IVertexShader.h"
#include "IPixelShader.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct IShaderProgram
	{
		virtual ~IShaderProgram() { }

		virtual IVertexShader* GetVertexShader() = 0;
		virtual IPixelShader* GetPixelShader() = 0;

	protected:
		IShaderProgram() { }
	};

}}}
