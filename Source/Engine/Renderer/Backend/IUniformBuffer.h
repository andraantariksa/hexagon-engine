#pragma once

namespace Hx { namespace Renderer { namespace Backend {

	struct IUniformBuffer
	{
		virtual ~IUniformBuffer() { }

	protected:
		IUniformBuffer() { }
	};

}}}
