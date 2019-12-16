#include "DeviceGL.h"
#include "glad/glad.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL { 

	DeviceGL::DeviceGL()
	{
	}

	DeviceGL::~DeviceGL()
	{
	}

	bool DeviceGL::Create(const Hx::Window::Window& window)
	{
		ContextHandle ctx = nullptr;
		OpenGLInitDesc initDesc;

		initDesc.MajorVer = 3;
		initDesc.MinorVer = 3;

		GLInit(window, initDesc, &ctx);
		if (ctx == nullptr)
			return false;

		if (gladLoadGL() == 0)
		{
			GLDestroy(&ctx);
			return false;
		}

		GLMakeCurrent(window, ctx);
		this->Context = new ContextGL(ctx);

		return true;
	}

	IDeferredContext* DeviceGL::CreateDeferredContext()
	{
		// TODO: Implement deferred context
		return nullptr;
	}

	IVertexBuffer* DeviceGL::CreateVertexBuffer(ResourceUsage usage, size_t bufferSize, const void* bufferData)
	{
		return nullptr;
	}

	IIndexBuffer* DeviceGL::CreateIndexBuffer(ResourceUsage usage, ResourceFormat indexFormat, size_t bufferSize, const void* bufferData)
	{
		return nullptr;
	}

	ITexture1D* DeviceGL::CreateTexture1D(const Texture1DDesc& createDesc, const Texture1DResourceData& initialData)
	{
		return nullptr;
	}

	ITexture2D* DeviceGL::CreateTexture2D(const Texture2DDesc& createDesc, const Texture2DResourceData& initialData)
	{
		return nullptr;
	}

	ITexture3D* DeviceGL::CreateTexture3D(const Texture3DDesc& createDesc, const Texture3DResourceData& initialData)
	{
		return nullptr;
	}

	IVertexShader* DeviceGL::CreateVertexShader(uint32 size, const void* compiledShader)
	{
		return nullptr;
	}

	IPixelShader* DeviceGL::CreatePixelShader(uint32 size, const void* compiledShader)
	{
		return nullptr;
	}

	IShaderProgram* DeviceGL::CreateShaderProgram(IVertexShader* vs, IPixelShader* ps)
	{
		return nullptr;
	}

	IVertexDecl* DeviceGL::CreateVertexDeclaration(IShaderProgram* program, const VertexElement* vertElems, uint32 numElems)
	{
		return nullptr;
	}

	IUniformBuffer* DeviceGL::CreateUniformBuffer()
	{
		return nullptr;
	}

}}}}
