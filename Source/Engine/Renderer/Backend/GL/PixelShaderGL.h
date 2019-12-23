#pragma once

#include "../../../Types.h"
#include "glad/glad.h"
#include "../IPixelShader.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {

	class PixelShaderGL : public IPixelShader
	{
	public:
		PixelShaderGL(uint32 handle)
			: Handle(handle)
		{
		}

		~PixelShaderGL()
		{
			glDeleteShader(this->Handle);
		}

		uint32 GetHandle() { return this->Handle; }

	private:
		uint32 Handle;
	};

}}}}
