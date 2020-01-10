#pragma once

#include "../../../Types.hpp"
#include "../IBuffer.hpp"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {

	class BufferGL : public IBuffer
	{
	public:
		BufferGL(uint32 handle)
			: Handle(handle)
		{

		}

		~BufferGL() = default;

		uint32 GetHandle() { return Handle; }

	private:
		uint32 Handle;
	};

}}}}
