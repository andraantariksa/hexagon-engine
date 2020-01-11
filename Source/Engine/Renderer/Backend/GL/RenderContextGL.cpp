#include "RenderContextGL.hpp"
#include "BufferGL.hpp"

#include <cassert>
#include <cstdio>

#ifndef NDEBUG
#define HX_CHECK_GL_ERROR() \
	int __glError = glGetError();					\
	assert(__glError == 0)
#else
#define HX_CHECK_GL_ERROR()
#endif

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL { 

	RenderContextGL::RenderContextGL(ContextHandle handle)
		: Context(handle), States({ 0 })
	{
	}

	RenderContextGL::~RenderContextGL()
	{
	}

	void RenderContextGL::ClearFrameBuffer(IFrameBuffer* frameBuffer, const float colorRGBA[4])
	{
		FrameBufferGL* fb = static_cast<FrameBufferGL*>(frameBuffer);
		uint32 handle = fb->GetHandle();
		static const GLenum drawBuffer = GL_COLOR_ATTACHMENT0;

		glBindFramebuffer(GL_FRAMEBUFFER, handle);

		if (handle != 0)
		{
			glDrawBuffers(1, &drawBuffer);
			glClearBufferfv(GL_COLOR, 0, colorRGBA);
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
		}
		else
		{
			glClearColor(
				colorRGBA[0],
				colorRGBA[1],
				colorRGBA[2],
				colorRGBA[3]);

			glClear(GL_COLOR_BUFFER_BIT);
		}

		HX_CHECK_GL_ERROR();
	}

	void RenderContextGL::SetFrameBuffer(IFrameBuffer* frameBuffer)
	{
		this->States.FrameBuffer = static_cast<FrameBufferGL*>(frameBuffer);
	}

	void RenderContextGL::SetViewport(uint32 numViewports, const Viewport* viewports)
	{
	}

	void RenderContextGL::SetShaderProgram(IShaderProgram* shaderProgram)
	{
		ShaderProgramGL* p = nullptr;
		
		if(shaderProgram)
		{
			p = static_cast<ShaderProgramGL*>(shaderProgram);
			glUseProgram(p->GetHandle());
		}

		this->States.ShaderProgram = p;
		HX_CHECK_GL_ERROR();
	}

	void RenderContextGL::SetShaderResource(ShaderType type, uint32 slot, ITexture1D* texture)
	{
		glActiveTexture(slot + GL_TEXTURE0);

		if (texture != nullptr)
		{
			glBindTexture(GL_TEXTURE_1D, static_cast<Texture1DGL*>(texture)->GetHandle());
		}
		else
		{
			glBindTexture(GL_TEXTURE_1D, 0);
		}
	}

	void RenderContextGL::SetShaderResource(ShaderType type, uint32 slot, ITexture2D* texture)
	{
		glActiveTexture(slot + GL_TEXTURE0);

		if (texture != nullptr)
		{
			glBindTexture(GL_TEXTURE_2D, static_cast<Texture2DGL*>(texture)->GetHandle());
		}
		else
		{
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}

	void RenderContextGL::SetShaderResource(ShaderType type, uint32 slot, ITexture3D* texture)
	{
		glActiveTexture(slot + GL_TEXTURE0);
		if (texture != nullptr)
		{
			glBindTexture(GL_TEXTURE_3D, static_cast<Texture3DGL*>(texture)->GetHandle());
		}
		else
		{
			glBindTexture(GL_TEXTURE_3D, 0);
		}
	}

	void RenderContextGL::SetShaderResource(ShaderType type, uint32 slot, IBuffer* buffer)
	{
	}

	void RenderContextGL::SetSamplerState(ShaderType shader, uint32 slot, ISamplerState* samplerState)
	{
		glBindSampler(slot, static_cast<SamplerStateGL*>(samplerState)->GetHandle());
	}

	void RenderContextGL::SetVertexStream(IVertexStream* vertexStream)
	{
		VertexStreamGL* vstr = nullptr;

		if(vertexStream)
		{
			vstr = static_cast<VertexStreamGL*>(vertexStream);
			glBindVertexArray(vstr->GetHandle());
		}

		this->States.VertexStream = vstr;
		HX_CHECK_GL_ERROR();
	}

	void RenderContextGL::SetPrimitiveTopology(PrimitiveTopology mode)
	{
		static uint32 toGL[] = {
			GL_NONE,
			GL_POINTS,
			GL_LINES,
			GL_LINE_STRIP,
			GL_TRIANGLES,
			GL_TRIANGLE_STRIP,
			GL_LINES_ADJACENCY,
			GL_LINE_STRIP_ADJACENCY,
			GL_TRIANGLES_ADJACENCY,
			GL_TRIANGLE_STRIP_ADJACENCY,
		};

		this->States.PrimTopo = toGL[(size_t)mode];
	}

	void RenderContextGL::Draw(uint32 vertexCount, uint32 startIndex)
	{
		glDrawArrays(this->States.PrimTopo, startIndex, vertexCount);
		HX_CHECK_GL_ERROR();
	}

	void RenderContextGL::DrawIndexed(uint32 indexCount, uint32 startIndex, uint32 baseIndex)
	{
	}

	int32 RenderContextGL::GetUniformBufferIndex(const char* uniformBlockName, size_t strSize)
	{
		uint32 handle = glGetUniformBlockIndex(this->States.ShaderProgram->GetHandle(), uniformBlockName);
		return handle;
	}

	void RenderContextGL::SetUniformBufferData(IBuffer* uniformBuffer, int32 index, const void* data, size_t size)
	{
		uint32 bufHandle = static_cast<BufferGL*>(uniformBuffer)->GetHandle();
		glBindBufferBase(GL_UNIFORM_BUFFER, index, bufHandle);

		glBindBuffer(GL_UNIFORM_BUFFER, bufHandle);
		glBufferSubData(GL_UNIFORM_BUFFER, 0, size, data);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);

		HX_CHECK_GL_ERROR();
	}

}}}}
