#pragma once

#include "../../Types.h"
#include "../../Window/Window.h"
#include "BackendAPI.h"
#include "Common.h"
#include "IBuffer.h"
#include "IBuffer.h"
#include "ITexture1D.h"
#include "ITexture2D.h"
#include "ITexture3D.h"
#include "IVertexShader.h"
#include "IPixelShader.h"
#include "IShaderProgram.h"
#include "IVertexDecl.h"
#include "IBuffer.h"
#include "IDeferredContext.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct IDevice
	{
		virtual ~IDevice() { }

		virtual bool Create(const Hx::Window::Window& window) = 0;
		virtual IDeferredContext* CreateDeferredContext() = 0;
		virtual IBuffer* CreateVertexBuffer(ResourceUsage usage, size_t bufferSize, const void* bufferData) = 0;
		virtual IBuffer* CreateIndexBuffer(ResourceUsage usage, ResourceFormat indexFormat, size_t bufferSize, const void* bufferData) = 0;
		virtual ITexture1D* CreateTexture1D(const Texture1DDesc& createDesc, const Texture1DResourceData& initialData) = 0;
		virtual ITexture2D* CreateTexture2D(const Texture2DDesc& createDesc, const Texture2DResourceData& initialData) = 0;
		virtual ITexture3D* CreateTexture3D(const Texture3DDesc& createDesc, const Texture3DResourceData& initialData) = 0;
		virtual IVertexShader* CreateVertexShader(uint32 size, const void* compiledShader) = 0;
		virtual IPixelShader* CreatePixelShader(uint32 size, const void* compiledShader) = 0;
		virtual IShaderProgram* CreateShaderProgram(IVertexShader* vs, IPixelShader* ps) = 0;
		virtual IVertexDecl* CreateVertexDeclaration(IShaderProgram* program, const VertexElement* vertElems, uint32 numElems) = 0;
		virtual IBuffer* CreateUniformBuffer() = 0;
		virtual IContext* GetImmediateContext() = 0;
		virtual BackendAPI GetBackendAPI() = 0;

	protected:
		IDevice() { }
	};

}}}