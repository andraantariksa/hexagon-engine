#pragma once

#include "Common.h"
#include "BufferGL.h"
#include "ContextGL.h"
#include "VertexShaderGL.h"
#include "PixelShaderGL.h"
#include "ShaderProgramGL.h"
#include "VertexStreamGL.h"
#include "FrameBufferGL.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL { 
	
	class DeviceGL : public IDevice
	{
	public:
		DeviceGL();
		~DeviceGL();

		bool Create(Hx::Window::Window& window) override;
		IDeferredContext* CreateDeferredContext() override;
		IDepthStencilState* CreateDepthStencilState(const DepthStencilDesc& createDesc) override;
		IBuffer* CreateBuffer(const BufferDesc& createDesc) override;
		IBuffer* CreateVertexBuffer(ResourceUsage usage, size_t bufferSize, const void* bufferData) override;
		IBuffer* CreateIndexBuffer(ResourceUsage usage, ResourceFormat indexFormat, size_t bufferSize, const void* bufferData) override;
		ITexture1D* CreateTexture1D(const Texture1DDesc& createDesc, const Texture1DResourceData& initialData) override;
		ITexture2D* CreateTexture2D(const Texture2DDesc& createDesc, const Texture2DResourceData& initialData) override;
		ITexture3D* CreateTexture3D(const Texture3DDesc& createDesc, const Texture3DResourceData& initialData) override;
		IVertexShader* CreateVertexShader(uint32 size, const void* compiledShader) override;
		IPixelShader* CreatePixelShader(uint32 size, const void* compiledShader) override;
		IShaderProgram* CreateShaderProgram(IVertexShader* vs, IPixelShader* ps) override;
		IVertexStream* CreateVertexStream(IShaderProgram* program, const VertexElement* vertElems, uint32 numElems, IBuffer* vertexBuffer, IBuffer* indexBuffer) override;
		IBuffer* CreateUniformBuffer(size_t bufferSize, const void* bufferData) override;
		void SwapBuffers() override;
		IContext* GetImmediateContext() override { return this->Context; }
		IFrameBuffer* GetSwapBuffer() override { return static_cast<IFrameBuffer*>(this->DefaultFrameBuffer); }
		BackendAPI GetBackendAPI() override { return BackendAPI::OGL; }

	private:
		FrameBufferGL* DefaultFrameBuffer;
		FrameBufferGL* DefaultDepthBuffer;
		ContextGL* Context;
		Hx::Window::Window* RenderWindow;
	};

}}}}
