#pragma once

#include "Common.h"
#include "ContextGL.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL { 
	
	class DeviceGL : public IDevice
	{
	public:
		DeviceGL();
		~DeviceGL();

		bool Create(const Hx::Window::Window& window) override;
		IDeferredContext* CreateDeferredContext() override;
		IVertexBuffer* CreateVertexBuffer(ResourceUsage usage, size_t bufferSize, const void* bufferData) override;
		IIndexBuffer* CreateIndexBuffer(ResourceUsage usage, ResourceFormat indexFormat, size_t bufferSize, const void* bufferData) override;
		ITexture1D* CreateTexture1D(const Texture1DDesc& createDesc, const Texture1DResourceData& initialData) override;
		ITexture2D* CreateTexture2D(const Texture2DDesc& createDesc, const Texture2DResourceData& initialData) override;
		ITexture3D* CreateTexture3D(const Texture3DDesc& createDesc, const Texture3DResourceData& initialData) override;
		IVertexShader* CreateVertexShader(uint32 size, const void* compiledShader) override;
		IPixelShader* CreatePixelShader(uint32 size, const void* compiledShader) override;
		IShaderProgram* CreateShaderProgram(IVertexShader* vs, IPixelShader* ps) override;
		IVertexDecl* CreateVertexDeclaration(IShaderProgram* program, const VertexElement* vertElems, uint32 numElems) override;
		IUniformBuffer* CreateUniformBuffer() override;
		IContext* GetImmediateContext() override { return nullptr; }
		BackendAPI GetBackendAPI() override { return BackendAPI::OGL; }

	private:
		ContextGL* Context;
	};

} } } }
