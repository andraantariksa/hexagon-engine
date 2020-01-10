#pragma once

#include "../ITexture1D.hpp"

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
		}

		uint32 GetHandle() { return this->Handle; }

	private:
		uint32 Handle;
	};

}}}}
