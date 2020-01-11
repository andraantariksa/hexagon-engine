#pragma once

#include "../ISamplerState.hpp"
#include "glad/glad.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {

	class SamplerStateGL : public ISamplerState
	{
	public:
		SamplerStateGL(uint32 handle)
			: Handle(handle)
		{
		}

		~SamplerStateGL()
		{
			glDeleteSamplers(1, &this->Handle);
		}

		uint32 GetHandle() { return this->Handle; }

	private:
		uint32 Handle;
	};

}}}}
