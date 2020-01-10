#pragma once

#include "../../../Types.hpp"
#include "glad/glad.h"
#include "../IVertexStream.hpp"
#include "../IShaderProgram.hpp"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {

	class VertexStreamGL : public IVertexStream
	{
	public:
		VertexStreamGL(uint32 handle)
			: Handle(handle)
		{
		}

		~VertexStreamGL()
		{
			glDeleteVertexArrays(1, &this->Handle);
		}

		uint32 GetHandle() { return this->Handle; }

	private:
		uint32 Handle;
	};

}}}}
