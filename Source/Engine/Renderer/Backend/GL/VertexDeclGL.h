#pragma once

#include "../../../Types.h"
#include "../IVertexDecl.h"
#include "../IShaderProgram.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {

	class VertexDeclGL : public IVertexDecl
	{
	public:
		VertexDeclGL(uint32 handle, IShaderProgram* sp)
			: Handle(handle)
		{
		}

		~VertexDeclGL() = default;

		uint32 GetHandle() { return this->Handle; }

	private:
		uint32 Handle;
		IShaderProgram* ShaderProgram;
	};

}}}}
