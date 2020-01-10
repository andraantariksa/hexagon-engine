#pragma once

#include "../../../Types.hpp"
#include "glad/glad.h"
#include "../IVertexShader.hpp"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {

	class VertexShaderGL : public IVertexShader
	{
	public:
		VertexShaderGL(uint32 handle)
			: Handle(handle)
		{

		}

		~VertexShaderGL()
		{
			glDeleteShader(this->Handle);
		}

		uint32 GetHandle() { return this->Handle; }

	private:
		uint32 Handle;
	};

}}}}
