#pragma once

#include "ITextureBase.hpp"

namespace Hx { namespace Renderer { namespace Backend {

	struct HX_NOVTABLE ITexture2D : public ITextureBase
	{
		virtual ~ITexture2D() { }

		//virtual void GetDesc(Texture2DDesc& info) = 0;

	protected:
		ITexture2D() { }
	};

}}}
