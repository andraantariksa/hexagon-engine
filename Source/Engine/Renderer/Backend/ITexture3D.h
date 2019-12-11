#pragma once

#include "ITextureBase.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct ITexture3D : public ITextureBase
	{
		ITexture3D() = delete;
		virtual ~ITexture3D() { }

		virtual void GetDesc(STexture3DDesc& info) = 0;
	};

}}}
