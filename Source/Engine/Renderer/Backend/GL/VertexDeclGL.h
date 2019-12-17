#pragma once

#include "../../../Types.h"
#include "../IVertexDecl.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {

	class VertexDeclGL : public IVertexDecl
	{
	public:
		VertexDeclGL(uint32 handle)
			: Handle(handle)
		{

		}

		~VertexDeclGL() = default;

		size_t GetNumElements() override;
		void GetElements(VertexElement* elements) override;

		uint32 GetHandle() { return Handle; }

	private:
		uint32 Handle;
	};

}}}}
