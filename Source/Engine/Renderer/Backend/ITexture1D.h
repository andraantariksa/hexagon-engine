#pragma once

#include "ITextureBase.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct ITexture1D : public ITextureBase
	{
		ITexture1D() = delete;
		virtual ~ITexture1D() { }

		virtual void GetDesc(Texture1DDesc& info) = 0;
	};

}}}
