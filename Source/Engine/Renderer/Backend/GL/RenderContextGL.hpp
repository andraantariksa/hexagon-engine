#pragma once

#include "Common.hpp"

#include "VertexStreamGL.hpp"
#include "ShaderProgramGL.hpp"
#include "FrameBufferGL.hpp"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL { 

	struct OpenGLContextState
	{
		FrameBufferGL* FrameBuffer;
		ShaderProgramGL* ShaderProgram;
		VertexStreamGL* VertexStream;

		uint32 PrimTopo;
	};

	class RenderContextGL : public IRenderContext
	{
	public:
		RenderContextGL(ContextHandle handle);
		~RenderContextGL();

		void ClearFrameBuffer(IFrameBuffer* frameBuffer, const float colorRGBA[4]) override;
		void SetFrameBuffer(IFrameBuffer* frameBuffer) override;
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
