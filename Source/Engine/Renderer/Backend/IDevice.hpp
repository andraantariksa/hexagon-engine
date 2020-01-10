#pragma once

#include "../../Types.hpp"
#include "../../Window/Window.hpp"
#include "BackendAPI.hpp"
#include "Common.hpp"
#include "IBuffer.hpp"
#include "IDepthStencilState.hpp"
#include "ITexture1D.hpp"
#include "ITexture2D.hpp"
#include "ITexture3D.hpp"
#include "IVertexShader.hpp"
#include "IPixelShader.hpp"
#include "IShaderProgram.hpp"
#include "IVertexStream.hpp"
#include "IBuffer.hpp"
#include "IDeferredRenderContext.hpp"
#include "ISamplerState.hpp"

namespace Hx { namespace Renderer { namespace Backend {

	struct HX_NOVTABLE IDevice
	{
		virtual ~IDevice() { }

		virtual bool Create(Hx::Window::Window& window) = 0;
		virtual IDeferredRenderContext* CreateDeferredContext() = 0;
		virtual IDepthStencilState* CreateDepthStencilState(const DepthStencilDesc& desc) = 0;
		virtual IBuffer* CreateBuffer(const BufferDesc& createDesc, const void* bufferData) = 0;
		virtual IBuffer* CreateVertexBuffer(ResourceUsage usage, size_t bufferSize, const void* bufferData) = 0;
		virtual IBuffer* CreateIndexBuffer(ResourceUsage usage, ResourceFormat indexFormat, size_t bufferSize, const void* bufferData) = 0;
		virtual ITexture1D* CreateTexture1D(const Texture1DDesc& createDesc, const Texture1DResourceData* initialData) = 0;
		virtual ITexture2D* CreateTexture2D(const Texture2DDesc& createDesc, const Texture2DResourceData* initialData) = 0;
		virtual ITexture3D* CreateTexture3D(const Texture3DDesc& createDesc, const Texture3DResourceData* initialData) = 0;
		virtual ISamplerState* CreateSamplerState(const SamplerStateDesc& createDesc) = 0;
		virtual IVertexShader* CreateVertexShader(uint32 size, const void* compiledShader) = 0;
		virtual IPixelShader* CreatePixelShader(uint32 size, const void* compiledShader) = 0;
		virtual IShaderProgram* CreateShaderProgram(IVertexShader* vs, IPixelShader* ps) = 0;
		virtual IVertexStream* CreateVertexStream(IShaderProgram* program, const VertexElement* vertElems, uint32 numElems, IBuffer* vertexBuffer, IBuffer* indexBuffer) = 0;
		virtual IBuffer* CreateUniformBuffer(size_t bufferSize, const void* bufferData) = 0;
		virtual void SwapBuffers() = 0;
		virtual IRenderContext* GetImmediateContext() = 0;
		virtual IFrameBuffer* GetSwapBuffer() = 0;
		virtual BackendAPI GetBackendAPI() = 0;


	protected:
		IDevice() { }
	};

}}}
