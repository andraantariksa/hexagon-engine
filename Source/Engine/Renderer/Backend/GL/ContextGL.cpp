#include "ContextGL.h"
#include "BufferGL.h"
#include "VertexStreamGL.h"
#include "ShaderProgramGL.h"
#include "FrameBufferGL.h"
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

	ContextGL::ContextGL(ContextHandle handle)
		: Context(handle), States({ 0 })
	{
	}

	ContextGL::~ContextGL()
	{
	}

	void ContextGL::ClearFrameBuffer(IFrameBuffer* frameBuffer, const float colorRGBA[4])
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

	void ContextGL::ClearDepthStencilBuffer(IDepthStencilBuffer* depthBuffer, ClearFlag clearFlags, float depth, uint8 stencil)
	{
	}

	void ContextGL::SetRenderBuffers(uint32 numSlots, IFrameBuffer* const* frameBuffers, IDepthStencilBuffer* depthBuffer)
	{
	}

	void ContextGL::SetViewport(uint32 numViewports, const Viewport* viewports)
	{
	}

	void ContextGL::SetShaderProgram(IShaderProgram* shaderProgram)
	{
		glUseProgram(static_cast<ShaderProgramGL*>(shaderProgram)->GetHandle());
		HX_CHECK_GL_ERROR();
	}

	void ContextGL::SetVertexStream(IVertexStream* vertexStream)
	{
		glBindVertexArray(static_cast<VertexStreamGL*>(vertexStream)->GetHandle());
		HX_CHECK_GL_ERROR();
	}

	void ContextGL::SetPrimitiveTopology(PrimitiveTopology mode)
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

	void ContextGL::Draw(uint32 vertexCount, uint32 startIndex)
	{
		glDrawArrays(this->States.PrimTopo, startIndex, vertexCount);
		HX_CHECK_GL_ERROR();
	}

	void ContextGL::DrawIndexed(uint32 indexCount, uint32 startIndex, uint32 baseIndex)
	{
	}

	int32 ContextGL::GetUniformBufferIndex(const char* uniformBlockName, size_t strSize)
	{
		return int32();
	}

	void ContextGL::SetUniformBufferData(IBuffer* uniformBuffer, int32 index, const void* data, size_t size)
	{
	}

}}}}
