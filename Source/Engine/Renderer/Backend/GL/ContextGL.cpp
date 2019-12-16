#include "ContextGL.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL { 

	ContextGL::ContextGL(ContextHandle handle)
		: Context(handle)
	{
	}

	ContextGL::~ContextGL()
	{
	}

	void ContextGL::ClearFrameBuffer(IFrameBuffer* frameBuffer, const float colorRGBA[4])
	{
	}

	void ContextGL::ClearDepthStencilBuffer(IDepthStencilBuffer* depthBuffer, ClearFlag clearFlags, float depth, uint8 stencil)
	{
	}

	void ContextGL::SetRenderBuffers(uint32 numSlots, IFrameBuffer* const* frameBuffers, IDepthStencilBuffer* depthBuffer)
	{
	}

	void ContextGL::SetViewport(uint32 numViewports, const Viewport* viewports)
	{
	}

	void ContextGL::SetShaderProgram(IShaderProgram* shaderProgram)
	{
	}

	void ContextGL::SetVertexDeclaration(IVertexDecl* vertexDeclaration)
	{
	}

	void ContextGL::SetVertexBuffer(IVertexBuffer* vertexBuffer)
	{
	}

	void ContextGL::Draw(uint32 vertexCount, uint32 startIndex)
	{
	}

	void ContextGL::DrawIndexed(uint32 indexCount, uint32 startIndex, uint32 baseIndex)
	{
	}

	int32 ContextGL::GetUniformBufferIndex(const char* uniformBlockName, size_t strSize)
	{
		return int32();
	}

	void ContextGL::SetUniformBufferData(IUniformBuffer* uniformBuffer, int32 index, const void* data, size_t size)
	{
	}

}}}}
