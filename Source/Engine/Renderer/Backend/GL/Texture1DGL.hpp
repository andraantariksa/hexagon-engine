#pragma once

#include "../ITexture1D.hpp"
#include "glad/glad.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {

	class Texture1DGL : public ITexture1D
	{
	public:
		Texture1DGL(uint32 handle)
			: Handle(handle)
		{
		}

		~Texture1DGL()
		{
			glDeleteTextures(1, &this->Handle);
		}

		uint32 GetHandle() { return this->Handle; }

	private:
		uint32 Handle;
	};

}}}}
