#pragma once

#include "Common.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL { 

	struct OpenGLContextState
	{
		IFrameBuffer* FrameBuffer;
		IShaderProgram* ShaderProgram;
		IVertexStream* VertexStream;
		IBuffer* VertexBuffer;
		IBuffer* IndexBuffer;

		uint32 PrimTopo;
	};

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
		void SetVertexStream(IVertexStream* vertexStream) override;
		void SetPrimitiveTopology(PrimitiveTopology mode) override;
		void Draw(uint32 vertexCount, uint32 startIndex) override;
		void DrawIndexed(uint32 indexCount, uint32 startIndex, uint32 baseIndex) override;
		int32 GetUniformBufferIndex(const char* uniformBlockName, size_t strSize) override;
		void SetUniformBufferData(IBuffer* uniformBuffer, int32 index, const void* data, size_t size) override;

		IVertexStream* GetVertexStream() override { return this->States.VertexStream; }

	private:
		ContextHandle Context;
		OpenGLContextState States;
	};

}}}}
