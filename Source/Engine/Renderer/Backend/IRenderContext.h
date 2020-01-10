#pragma once

#include "Common.h"
#include "IFrameBuffer.h"
#include "IDepthStencilBuffer.h"
#include "IShaderProgram.h"
#include "IVertexStream.h"
#include "IBuffer.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct HX_NOVTABLE IRenderContext
	{
		virtual ~IRenderContext() { };

		virtual void ClearFrameBuffer(IFrameBuffer* frameBuffer, const float colorRGBA[4]) = 0;
		virtual void SetFrameBuffer(IFrameBuffer* frameBuffer) = 0;
		virtual void SetViewport(uint32 numViewports, const Viewport* viewports) = 0;
		virtual void SetShaderProgram(IShaderProgram* shaderProgram) = 0;
		virtual void SetVertexStream(IVertexStream* vertexStream) = 0;
		virtual void SetPrimitiveTopology(PrimitiveTopology mode) = 0;
		virtual void Draw(uint32 vertexCount, uint32 startIndex) = 0;
		virtual void DrawIndexed(uint32 indexCount, uint32 startIndex, uint32 baseIndex) = 0;

		// Uniform-related function
		virtual int32 GetUniformBufferIndex(const char* uniformBlockName, size_t strSize = 0) = 0;
		virtual void SetUniformBufferData(IBuffer* uniformBuffer, int32 index, const void* data, size_t size) = 0;

		virtual IVertexStream* GetVertexStream() = 0;

	protected:
		IRenderContext() { }
	};

}}}
