#include "DeviceGL.h"
#include <cstring>
#include <cstdio>

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL { 

	void GLErrorMsgCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
	{
		std::printf("GL Error: %s\n", message);
	}

	DeviceGL::DeviceGL()
		: Context(nullptr),
		DefaultFrameBuffer(nullptr),
		DefaultDepthBuffer(nullptr),
		RenderWindow(nullptr)
	{
	}

	DeviceGL::~DeviceGL()
	{
	}

	bool DeviceGL::Create(Hx::Window::Window& window)
	{
		ContextHandle ctx = nullptr;
		OpenGLInitDesc initDesc;

		initDesc.MajorVer = 4;
		initDesc.MinorVer = 3;

		this->RenderWindow = &window;

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

#ifndef NDEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glDebugMessageCallback(GLErrorMsgCallback, nullptr);
#endif

		// Default framebuffer
		this->DefaultFrameBuffer = new FrameBufferGL(0);

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
			// TODO: Write error message log
			glDeleteShader(handle);
			return nullptr;
		}

		return new VertexShaderGL(handle);
	}

	IPixelShader* DeviceGL::CreatePixelShader(uint32 size, const void* compiledShader)
	{
		uint32 handle;
		GLint isize = size;
		GLint status = 0;

		if (size < 1 && compiledShader == nullptr)
			return nullptr;

		handle = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(handle, 1, (const GLchar **)& compiledShader, &isize);
		glCompileShader(handle);

		glGetShaderiv(handle, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE)
		{
			// TODO: Write error message log
			glDeleteShader(handle);
			return nullptr;
		}

		return new PixelShaderGL(handle);
	}

	IShaderProgram* DeviceGL::CreateShaderProgram(IVertexShader* vs, IPixelShader* ps)
	{
		uint32 handle;
		GLint status;
		GLint vertex = static_cast<VertexShaderGL*>(vs)->GetHandle();
		GLint pixel = static_cast<PixelShaderGL*>(ps)->GetHandle();
		
		handle = glCreateProgram();
		glAttachShader(handle, vertex);
		glAttachShader(handle, pixel);

		glLinkProgram(handle);
		glGetProgramiv(handle, GL_LINK_STATUS, &status);
		if (status == GL_FALSE)
		{
			glDeleteProgram(handle);
			return nullptr;
		}

		return new ShaderProgramGL(handle, vs, ps);
	}

	IVertexStream* DeviceGL::CreateVertexStream(IShaderProgram* program, const VertexElement* vertElems, uint32 numElems, IBuffer* vertexBuffer, IBuffer* indexBuffer)
	{
		typedef struct
		{
			char* attrName;
			GLint attrLen;
			GLint attrSize;
			GLenum attrType;
			GLenum attrBaseType;
			GLint attrId;
		} VertexAttributeInfo;

		uint32 handle;
		uint32 pr = static_cast<ShaderProgramGL*>(program)->GetHandle();

		if (vertexBuffer == nullptr)
			return nullptr;

		glGenVertexArrays(1, &handle);
		glBindVertexArray(handle); // bind

		glBindBuffer(GL_ARRAY_BUFFER, static_cast<BufferGL*>(vertexBuffer)->GetHandle());
		if (indexBuffer != nullptr)
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, static_cast<BufferGL*>(indexBuffer)->GetHandle());
		
		// auto-detect vertex declaration
		if (vertElems == nullptr || numElems == 0)
		{
			GLint size, maxChars;
			size_t strideSize = 0;
			size_t strideOffset = 0;
			VertexAttributeInfo* attribs;

			// retrieve attribute count and max chars of attributes
			glGetProgramiv(pr, GL_ACTIVE_ATTRIBUTES, &size);
			glGetProgramiv(pr, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxChars);
			attribs = new VertexAttributeInfo[size];

			// fetch all attribute info
			for (int i = 0; i < size; i++)
			{
				VertexAttributeInfo* info = &attribs[i];

				info->attrName = new char[maxChars];
				std::memset(info->attrName, 0, maxChars);
				glGetActiveAttrib(pr, i, maxChars, &info->attrLen, &info->attrSize, &info->attrType, info->attrName);
				info->attrId = glGetAttribLocation(pr, info->attrName);
				
				switch (info->attrType)
				{
				case GL_FLOAT:
					info->attrSize = 1;
					info->attrBaseType = GL_FLOAT;
					break;
				case GL_FLOAT_VEC2:
					info->attrSize = 2;
					info->attrBaseType = GL_FLOAT;
					break;
				case GL_FLOAT_VEC3:
					info->attrSize = 3;
					info->attrBaseType = GL_FLOAT;
					break;
				case GL_FLOAT_VEC4:
				case GL_FLOAT_MAT2:
					info->attrSize = 4;
					info->attrBaseType = GL_FLOAT;
					break;
				case GL_FLOAT_MAT3:
					info->attrSize = 9;
					info->attrBaseType = GL_FLOAT;
					break;
				case GL_FLOAT_MAT4:
					info->attrSize = 16;
					info->attrBaseType = GL_FLOAT;
					break;
				case GL_FLOAT_MAT2x3:
				case GL_FLOAT_MAT3x2:
					info->attrSize = 6;
					info->attrBaseType = GL_FLOAT;
					break;
				case GL_FLOAT_MAT2x4:
				case GL_FLOAT_MAT4x2:
					info->attrSize = 8;
					info->attrBaseType = GL_FLOAT;
					break;
				case GL_FLOAT_MAT3x4:
				case GL_FLOAT_MAT4x3:
					info->attrSize = 12;
					info->attrBaseType = GL_FLOAT;
					break;
				case GL_INT:
					info->attrSize = 1;
					info->attrBaseType = GL_INT;
					break;
				case GL_INT_VEC2:
					info->attrSize = 2;
					info->attrBaseType = GL_INT;
					break;
				case GL_INT_VEC3:
					info->attrSize = 3;
					info->attrBaseType = GL_INT;
					break;
				case GL_INT_VEC4:
					info->attrSize = 4;
					info->attrBaseType = GL_INT;
					break;
				case GL_UNSIGNED_INT:
					info->attrSize = 1;
					info->attrBaseType = GL_UNSIGNED_INT;
					break;
				case GL_UNSIGNED_INT_VEC2:
					info->attrSize = 2;
					info->attrBaseType = GL_UNSIGNED_INT;
					break;
				case GL_UNSIGNED_INT_VEC3:
					info->attrSize = 3;
					info->attrBaseType = GL_UNSIGNED_INT;
					break;
				case GL_UNSIGNED_INT_VEC4:
					info->attrSize = 4;
					info->attrBaseType = GL_UNSIGNED_INT;
					break;
				}

				strideSize += (size_t)info->attrSize * 4;
			}

			// specify attributes
			for (int i = size; i > 0; i--)
			{
				VertexAttributeInfo* info = &attribs[i - 1];

				switch(info->attrBaseType)
				{
				case GL_FLOAT:
					glVertexAttribPointer(info->attrId, info->attrSize, info->attrBaseType, GL_FALSE, (GLsizei)strideSize, (GLvoid*)strideOffset);
					break;
				case GL_INT:
				case GL_UNSIGNED_INT:
					glVertexAttribIPointer(info->attrId, info->attrSize, info->attrBaseType, (GLsizei)strideSize, (GLvoid*)strideOffset);
					break;
				}

				glEnableVertexAttribArray(info->attrId);
				
				// delete attribute name from memory
				delete[] info->attrName;
				info->attrName = nullptr;

				strideOffset += (size_t)info->attrSize * 4;
			}

			delete[] attribs;
		}
		
		// unbind
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		return new VertexStreamGL(handle);
	}

	IBuffer* DeviceGL::CreateUniformBuffer(size_t bufferSize, const void* bufferData)
	{
		return nullptr;
	}

	void DeviceGL::SwapBuffers()
	{
		GLSwapBuffers(*this->RenderWindow);
	}

}}}}
