#pragma once

#include "Common.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL { 

	class ContextGL : public IContext
	{
	public:
		ContextGL(ContextHandle handle);
		~ContextGL();

		void ClearFrameBuffer(IFrameBuffer* frameBuffer, const float colorRGBA[4]) override;
		void ClearDepthStencilBuffer(IDepthStencilBuffer* depthBuffer, ClearFlag clearFlags, float depth, uint8 stencil) override;
		void SetRenderBuffers(uint32 numSlots, IFrameBuffer* const* frameBuffers, IDepthStencilBuffer* depthBuffer) override;
		void SetViewport(uint32 numViewports, const Viewport* viewports) override;
		void SetShaderProgram(IShaderProgram* shaderProgram) override;
		void SetVertexDeclaration(IVertexDecl* vertexDeclaration) override;
		void SetVertexBuffer(IVertexBuffer* vertexBuffer) override;
		void Draw(uint32 vertexCount, uint32 startIndex) override;
		void DrawIndexed(uint32 indexCount, uint32 startIndex, uint32 baseIndex) override;
		int32 GetUniformBufferIndex(const char* uniformBlockName, size_t strSize) override;
		void SetUniformBufferData(IUniformBuffer* uniformBuffer, int32 index, const void* data, size_t size) override;

	private:
		ContextHandle Context;
	};

}}}}
