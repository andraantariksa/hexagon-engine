#pragma once

#include "Common.h"
#include "IFrameBuffer.h"
#include "IDepthStencilBuffer.h"
#include "IShaderProgram.h"
#include "IVertexDecl.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct IContext
	{
		virtual ~IContext() { };

		virtual void ClearFrameBuffer(IFrameBuffer* frameBuffer, const float colorRGBA[4]) = 0;
		virtual void ClearDepthStencilBuffer(IDepthStencilBuffer* depthBuffer, ClearFlag clearFlags, float depth, uint8 stencil) = 0;
		virtual void SetRenderBuffers(uint32 numSlots, IFrameBuffer* const* frameBuffers, IDepthStencilBuffer* depthBuffer) = 0;
		virtual void SetViewport(uint32 numViewports, Viewport* viewports) = 0;
		virtual void SetShaderProgram(IShaderProgram* shaderProgram) = 0;
		virtual void SetVertexDeclaration(IVertexDecl* vertexDeclaration) = 0;
		virtual void Draw(uint32 vertexCount, uint32 startIndex) = 0;
		virtual void DrawIndexed(uint32 indexCount, uint32 startIndex, uint32 baseIndex) = 0;

		// Uniform-related function
		virtual int32 GetUniformIndex(const char* uniformName, size_t strSize) = 0;
		virtual int32 GetUniformBufferIndex(const char* uniformBlockName, size_t strSize) = 0;
		virtual void SetUniformValueFloat(int32 index, float f) = 0;
		virtual void SetUniformValueFloat2(int32 index, float f[2]) = 0;
		virtual void SetUniformValueFloat3(int32 index, float f[3]) = 0;
		virtual void SetUniformValueFloat4(int32 index, float f[4]) = 0;
		virtual void SetUniformValueFloatArray(int32 index, const float* arr, size_t size) = 0;
		virtual void SetUniformValueInt(int32 index, int32 i) = 0;
		virtual void SetUniformValueInt2(int32 index, int32 i[2]) = 0;
		virtual void SetUniformValueInt3(int32 index, int32 i[3]) = 0;
		virtual void SetUniformValueInt4(int32 index, int32 i[4]) = 0;
		virtual void SetUniformValueIntArray(int32 index, const int32* arr, size_t size) = 0;
		virtual void SetUniformValueUint(int32 index, uint32 ui) = 0;
		virtual void SetUniformValueUint2(int32 index, uint32 ui[2]) = 0;
		virtual void SetUniformValueUint3(int32 index, uint32 ui[3]) = 0;
		virtual void SetUniformValueUint4(int32 index, uint32 ui[4]) = 0;
		virtual void SetUniformValueUintArray(int32 index, const uint32* arr, size_t size) = 0;
		virtual void SetUniformBufferData(IUniformBuffer* uniformBuffer, int32 index, const void* data, size_t size) = 0;

	protected:
		IContext() { }
	};

}}}
