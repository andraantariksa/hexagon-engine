#pragma once

#include "../ITexture2D.hpp"
#include "glad/glad.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {

	class Texture2DGL : public ITexture2D
	{
	public:
		Texture2DGL(uint32 handle)
			: Handle(handle)
		{
		}

		~Texture2DGL()
		{
			glDeleteTextures(1, &this->Handle);
		}

		uint32 GetHandle() { return this->Handle; }

	private:
		uint32 Handle;
	};

}}}}
