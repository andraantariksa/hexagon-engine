#pragma once

#include "ITextureBase.hpp"

namespace Hx { namespace Renderer { namespace Backend {

	struct HX_NOVTABLE ITexture3D : public ITextureBase
	{
		virtual ~ITexture3D() { }

		//virtual void GetDesc(Texture3DDesc& info) = 0;

	protected:
		ITexture3D() { }
	};

}}}
