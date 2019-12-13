#pragma once

#include "../../Types.h"
#include "../../Window/Window.h"
#include "Common.h"
#include "IVertexBuffer.h"
#include "IIndexBuffer.h"
#include "ITexture1D.h"
#include "ITexture2D.h"
#include "ITexture3D.h"
#include "IVertexShader.h"
#include "IPixelShader.h"
#include "IShaderProgram.h"

namespace Hx { namespace Renderer { namespace Backend {

	struct IDevice
	{
		IDevice() = delete;
		virtual IDevice() { }

		virtual void Create(const Hx::Window::Window& window) = 0;
		virtual IVertexBuffer* CreateVertexBuffer(EResourceUsage usage, size_t bufferSize, const void* bufferData) = 0;
		virtual IIndexBuffer* CreateIndexBuffer(EResourceUsage usage, EResourceFormat indexFormat, size_t bufferSize, const void* bufferData) = 0;
		virtual ITexture1D* CreateTexture1D(const STexture1DDesc& createDesc, const STexture1DResourceData& initialData) = 0;
		virtual ITexture2D* CreateTexture2D(const STexture2DDesc& createDesc, const STexture2DResourceData& initialData) = 0;
		virtual ITexture3D* CreateTexture3D(const STexture3DDesc& createDesc, const STexture3DResourceData& initialData) = 0;
		virtual IVertexShader* CreateVertexShader(uint32 size, const void* compiledShader) = 0;
		virtual IPixelShader* CreatePixelShader(uint32 size, const void* compiledShader) = 0;
		virtual IShaderProgram* CreateShaderProgram(IVertexShader* vs, IPixelShader* ps) = 0;
		virtual IVertexStructure* CreateVertexStructure(IShaderProgram* program, const SVertexElement* vertDescs, uint32 numDescs) = 0;
		virtual IUniformBuffer* CreateUniformBuffer() = 0;
		virtual EBackendAPI GetBackendAPI() = 0;
	};

}}}
