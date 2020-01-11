#pragma once

#include "Common.hpp"
#include "IFrameBuffer.hpp"
#include "IDepthStencilBuffer.hpp"
#include "IShaderProgram.hpp"
#include "IVertexStream.hpp"
#include "IBuffer.hpp"
#include "ITexture1D.hpp"
#include "ITexture2D.hpp"
#include "ITexture3D.hpp"
#include "ISamplerState.hpp"

namespace Hx { namespace Renderer { namespace Backend {

	struct HX_NOVTABLE IRenderContext
	{
		virtual ~IRenderContext() { };

		virtual void ClearFrameBuffer(IFrameBuffer* frameBuffer, const float colorRGBA[4]) = 0;
		virtual void SetFrameBuffer(IFrameBuffer* frameBuffer) = 0;
		virtual void SetViewport(uint32 numViewports, const Viewport* viewports) = 0;
		virtual void SetShaderProgram(IShaderProgram* shaderProgram) = 0;
		virtual void SetShaderResource(ShaderType type, uint32 slot, ITexture1D* texture) = 0;
		virtual void SetShaderResource(ShaderType type, uint32 slot, ITexture2D* texture) = 0;
		virtual void SetShaderResource(ShaderType type, uint32 slot, ITexture3D* texture) = 0;
		virtual void SetShaderResource(ShaderType type, uint32 slot, IBuffer* buffer) = 0;
		virtual void SetSamplerState(ShaderType shader, uint32 slot, ISamplerState* samplerState) = 0;
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
