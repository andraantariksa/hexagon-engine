#pragma once

#include "../ITexture2D.hpp"

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
		}

		uint32 GetHandle() { return this->Handle; }

	private:
		uint32 Handle;
	};

}}}}
