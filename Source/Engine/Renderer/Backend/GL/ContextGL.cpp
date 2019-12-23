#include "ContextGL.h"
#include "BufferGL.h"
#include "VertexDeclGL.h"
#include "ShaderProgramGL.h"
#include "FrameBufferGL.h"

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
		static const GLenum drawBuffer = GL_COLOR_ATTACHMENT0;
		glBindFramebuffer(GL_FRAMEBUFFER, fb->GetHandle());
		glDrawBuffers(1, &drawBuffer);
		glClearBufferfv(GL_COLOR, 0, colorRGBA);
		if (fb->GetHandle() != 0)
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
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
	}

	void ContextGL::SetVertexDeclaration(IVertexDecl* vertexDeclaration)
	{
		glBindVertexArray(static_cast<VertexDeclGL*>(vertexDeclaration)->GetHandle());
	}

	void ContextGL::SetPrimitiveTopology(PrimitiveTopology mode)
	{
		static uint32 toGL[] = {
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

	void ContextGL::SetVertexBuffers(IBuffer* vertexBuffer)
	{
		glBindBuffer(GL_ARRAY_BUFFER, static_cast<BufferGL*>(vertexBuffer)->GetHandle());
	}

	void ContextGL::SetIndexBuffers(IBuffer* indexBuffer)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, static_cast<BufferGL*>(indexBuffer)->GetHandle());
	}

	void ContextGL::Draw(uint32 vertexCount, uint32 startIndex)
	{
		glDrawArrays(this->States.PrimTopo, startIndex, vertexCount);
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
