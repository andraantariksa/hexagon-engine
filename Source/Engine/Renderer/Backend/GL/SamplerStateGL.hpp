#pragma once

#include "../ISamplerState.hpp"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {

	class SamplerStateGL : public ISamplerState
	{
	public:
		SamplerStateGL(uint32 handle)
			: Handle(handle)
		{
		}

		~SamplerStateGL()
		{
		}

		uint32 GetHandle() { return this->Handle; }

	private:
		uint32 Handle;
	};

}}}}
