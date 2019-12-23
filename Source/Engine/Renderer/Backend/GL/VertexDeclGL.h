#pragma once

#include "../../../Types.h"
#include "glad/glad.h"
#include "../IVertexDecl.h"
#include "../IShaderProgram.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {

	class VertexDeclGL : public IVertexDecl
	{
	public:
		VertexDeclGL(uint32 handle)
			: Handle(handle)
		{
		}

		~VertexDeclGL()
		{
			glDeleteVertexArrays(1, &this->Handle);
		}

		uint32 GetHandle() { return this->Handle; }

	private:
		uint32 Handle;
	};

}}}}
