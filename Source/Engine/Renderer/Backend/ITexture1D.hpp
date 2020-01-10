#pragma once

#include "ITextureBase.hpp"

namespace Hx { namespace Renderer { namespace Backend {

	struct HX_NOVTABLE ITexture1D : public ITextureBase
	{
		virtual ~ITexture1D() { }

		//virtual void GetDesc(Texture1DDesc& info) = 0;

	protected:
		ITexture1D() { }
	};

}}}
