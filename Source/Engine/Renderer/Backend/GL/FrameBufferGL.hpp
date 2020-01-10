#pragma once

#include "glad/glad.h"
#include "../../../Types.hpp"
#include "../IFrameBuffer.hpp"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {

	class FrameBufferGL : public IFrameBuffer
	{
	public:
		FrameBufferGL(uint32 handle)
			: Handle(handle)
		{
		}

		~FrameBufferGL()
		{
			glDeleteBuffers(1, &this->Handle);
		}

		uint32 GetHandle() { return this->Handle; }

	private:
		uint32 Handle;
	};

} } } }
