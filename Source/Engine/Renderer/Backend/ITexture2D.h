#pragma once

#include "ITextureBase.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct ITexture2D : public ITextureBase
	{
		virtual ~ITexture2D() { }

		virtual void GetDesc(Texture2DDesc& info) = 0;

	protected:
		ITexture2D() { }
	};

}}}
