#pragma once

#include "../../../Types.h"
#include "glad/glad.h"
#include "../IVertexStream.h"
#include "../IShaderProgram.h"

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
