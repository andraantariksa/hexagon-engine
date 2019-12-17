#include "DeviceGL.h"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL { 

	DeviceGL::DeviceGL()
		: Context(nullptr)
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

	IDepthStencilState* DeviceGL::CreateDepthStencilState(const DepthStencilDesc& createDesc)
	{
		return nullptr;
	}

	IBuffer* DeviceGL::CreateBuffer(const BufferDesc& createDesc)
	{
		return nullptr;
	}

	IBuffer* DeviceGL::CreateVertexBuffer(ResourceUsage usage, size_t bufferSize, const void* bufferData)
	{
		uint32 handle = 0; 

		glGenBuffers(1, &handle);
		glBindBuffer(GL_ARRAY_BUFFER, handle);

		if (bufferSize > 0 && bufferData != nullptr)
			glBufferData(GL_ARRAY_BUFFER, bufferSize, bufferData, (GLenum)GLResourceUsageDraw[(uint32)usage]);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		return new BufferGL(handle);
	}

	IBuffer* DeviceGL::CreateIndexBuffer(ResourceUsage usage, ResourceFormat indexFormat, size_t bufferSize, const void* bufferData)
	{
		uint32 handle = 0;

		glGenBuffers(1, &handle);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle);

		if (bufferSize > 0 && bufferData != nullptr)
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferSize, bufferData, (GLenum)GLResourceUsageDraw[(uint32)usage]);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		return new BufferGL(handle);
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
		uint32 handle;
		GLint isize = size;
		GLint success = 0;

		if (size < 1 && compiledShader == nullptr)
			return nullptr;

		handle = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(handle, 1, (const GLchar**)&compiledShader, &isize);
		glCompileShader(handle);

		glGetShaderiv(handle, GL_COMPILE_STATUS, &success);
		if (success == GL_FALSE)
		{
			glDeleteShader(handle);
			return nullptr;
		}

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

	IBuffer* DeviceGL::CreateUniformBuffer(size_t bufferSize, const void* bufferData)
	{
		return nullptr;
	}

}}}}
