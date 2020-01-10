#pragma once

#include "../ITexture3D.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {

	class Texture3DGL : public ITexture3D
	{
	public:
		Texture3DGL(uint32 handle)
			: Handle(handle)
		{
		}

		~Texture3DGL()
		{
		}

		uint32 GetHandle() { return this->Handle; }

	private:
		uint32 Handle;
	};

}}}}
