#pragma once

#include "ITextureBase.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct ITexture2D : public ITextureBase
	{
		ITexture2D() = delete;
		virtual ~ITexture2D() { }

		virtual void GetDesc(STexture2DDesc& info) = 0;
	};

}}}
