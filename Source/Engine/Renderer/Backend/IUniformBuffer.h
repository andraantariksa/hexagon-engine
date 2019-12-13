#pragma once

namespace Hx { namespace Renderer { namespace Backend {

	struct IUniformBuffer
	{
		IUniformBuffer() = delete;
		virtual ~IUniformBuffer() { }
	};

}}}
