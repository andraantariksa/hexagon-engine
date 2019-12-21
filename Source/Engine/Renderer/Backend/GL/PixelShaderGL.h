#pragma once

#include "../../../Types.h"
#include "../IPixelShader.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {

	class PixelShaderGL : public IPixelShader
	{
	public:
		PixelShaderGL(uint32 handle)
			: Handle(handle)
		{

		}

		~PixelShaderGL() = default;

		uint32 GetHandle() { return this->Handle; }

	private:
		uint32 Handle;
	};

}}}}
