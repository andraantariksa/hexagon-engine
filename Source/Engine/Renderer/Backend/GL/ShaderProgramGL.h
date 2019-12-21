#pragma once

#include "../../../Types.h"
#include "../IShaderProgram.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {

	class ShaderProgramGL : public IShaderProgram
	{
	public:
		ShaderProgramGL(uint32 handle, IVertexShader* vs, IPixelShader* ps)
			: Handle(handle), VertexShader(vs), PixelShader(ps)
		{
		}

		~ShaderProgramGL() = default;

		IVertexShader* GetVertexShader() override { return this->VertexShader; }
		IPixelShader* GetPixelShader() override { return this->PixelShader; }

		uint32 GetHandle() { return this->Handle; }

	private:
		uint32 Handle;
		IVertexShader* VertexShader;
		IPixelShader* PixelShader;
	};

}}}}
