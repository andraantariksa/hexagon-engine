#pragma once

#include "glad/glad.h"
#include "Common.hpp"

namespace Hx { namespace Renderer { namespace Backend { namespace OpenGL {
	
	struct VertexAttribPointerFormat
	{
		uint32 Size;
		uint32 BaseType;
		bool Normalized;
	};

	static uint32 GLResourceUsageDraw[] = {
		GL_STATIC_DRAW,
		GL_STATIC_DRAW,
		GL_DYNAMIC_DRAW,
		GL_STATIC_DRAW
	};

	// GL_NONE == unsupported format
	static uint32 GLResourceInternalFormat[] = {
		GL_NONE,
		GL_RGBA32UI,
		GL_RGBA32F,
		GL_RGBA32UI,
		GL_RGBA32I,
		GL_RGB32I,
		GL_RGB32F,
		GL_RGB32UI,
		GL_RGB32I,
		GL_RGBA16UI,
		GL_RGBA16F,
		GL_RGBA16,
		GL_RGBA16UI,
		GL_RGBA16_SNORM,
		GL_RGBA16I,
		GL_RG32UI,
		GL_RG32F,
		GL_RG32I,
		GL_RG32UI,
		GL_NONE,
		GL_DEPTH32F_STENCIL8,
		GL_NONE,
		GL_NONE,
		GL_RGB10_A2UI,
		GL_RGB10_A2,
		GL_RGB10_A2UI,
		GL_R11F_G11F_B10F,
		GL_RGBA8UI,
		GL_RGBA8,
		GL_SRGB8_ALPHA8,
		GL_RGBA8UI,
		GL_RGBA8_SNORM,
		GL_RGBA8I,
		GL_RG16UI,
		GL_RG16F,
		GL_RG16,
		GL_RG16UI,
		GL_RG16_SNORM,
		GL_RG16I,
		GL_R32UI,
		GL_R32F,
		GL_DEPTH_COMPONENT32F,
		GL_R32UI,
		GL_R32I,
		GL_NONE,
		GL_DEPTH24_STENCIL8,
		GL_NONE,
		GL_NONE,
		GL_RG8UI,
		GL_RG8,
		GL_RG8UI,
		GL_RG8_SNORM,
		GL_RG8I,
		GL_R16UI,
		GL_R16F,
		GL_DEPTH_COMPONENT16,
		GL_R16,
		GL_R16UI,
		GL_R16_SNORM,
		GL_R16I,
		GL_R8UI,
		GL_R8,
		GL_R8UI,
		GL_R8_SNORM,
		GL_R8I,
		GL_NONE,
		GL_NONE,

	};

	// GL_NONE == unsupported format
	static uint32 GLResourceBaseFormat[] = {
		GL_NONE,
		GL_RGBA,			//R32G32B32A32_Typeless,
		GL_RGBA,			//R32G32B32A32_Float,
		GL_RGBA_INTEGER,	//R32G32B32A32_Uint,
		GL_RGBA_INTEGER,	//R32G32B32A32_Sint,
		GL_RGB,				//R32G32B32_Typeless,
		GL_RGB,				//R32G32B32_Float,
		GL_RGB_INTEGER,		//R32G32B32_Uint,
		GL_RGB_INTEGER,		//R32G32B32_Sint,
		GL_RGBA,			//R16G16B16A16_Typeless,
		GL_RGBA,			//R16G16B16A16_Float,
		GL_RGBA,			//R16G16B16A16_Unorm,
		GL_RGBA_INTEGER,	//R16G16B16A16_Uint,
		GL_RGBA,			//R16G16B16A16_Snorm,
		GL_RGBA_INTEGER,	//R16G16B16A16_Sint,
		GL_RG,				//R32G32_Typeless,
		GL_RG,				//R32G32_Float,
		GL_RG_INTEGER,		//R32G32_Uint,
		GL_RG_INTEGER,		//R32G32_Sint,
		GL_NONE,			//R32G8X24_Typeless,
		GL_DEPTH_STENCIL,	//D32_Float_S8X24_Uint,
		GL_NONE,			//R32_Float_X8X24_Typeless,
		GL_NONE,			//X32_Typeless_G8X24_Uint,
		GL_RGBA_INTEGER,	//R10G10B10A2_Typeless,
		GL_RGBA,			//R10G10B10A2_Unorm,
		GL_RGBA_INTEGER,	//R10G10B10A2_Uint,
		GL_RGB,				//R11G11B10_Float,
		GL_RGBA_INTEGER,	//R8G8B8A8_Typeless,
		GL_RGBA,			//R8G8B8A8_Unorm,
		GL_RGBA,			//R8G8B8A8_Unorm_Srgb,
		GL_RGBA_INTEGER,	//R8G8B8A8_Uint,
		GL_RGBA,			//R8G8B8A8_Snorm,
		GL_RGBA_INTEGER,	//R8G8B8A8_Sint,
		GL_RG_INTEGER,		//R16G16_Typeless,
		GL_RG,				//R16G16_Float,
		GL_RG,				//R16G16_Unorm,
		GL_RG_INTEGER,		//R16G16_Uint,
		GL_RG,				//R16G16_Snorm,
		GL_RG_INTEGER,		//R16G16_Sint,
		GL_RED_INTEGER,		//R32_Typeless,
		GL_RED,				//D32_Float,
		GL_DEPTH_COMPONENT,	//R32_Float,
		GL_RED_INTEGER,		//R32_Uint,
		GL_RED_INTEGER,		//R32_Sint,
		GL_NONE,			//R24G8_Typeless,
		GL_DEPTH_STENCIL,	//D24_Unorm_S8_Uint,
		GL_NONE,			//R24_Unorm_X8_Typeless,
		GL_NONE,			//X24_Typeless_G8_Uint,
		GL_RG_INTEGER,		//R8G8_Typeless,
		GL_RG,				//R8G8_Unorm,
		GL_RG_INTEGER,		//R8G8_Uint,
		GL_RG,				//R8G8_Snorm,
		GL_RG_INTEGER,		//R8G8_Sint,
		GL_RED_INTEGER,		//R16_Typeless,
		GL_RED,				//R16_Float,
		GL_DEPTH_COMPONENT,	//D16_Unorm,
		GL_RED,				//R16_Unorm,
		GL_RED_INTEGER,		//R16_Uint,
		GL_RED,				//R16_Snorm,
		GL_RED_INTEGER,		//R16_Sint,
		GL_RED_INTEGER,		//R8_Typeless,
		GL_RED,				//R8_Unorm,
		GL_RED_INTEGER,		//R8_Uint,
		GL_RED,				//R8_Snorm,
		GL_RED_INTEGER,		//R8_Sint,
		GL_NONE,			//A8_Unorm,
		GL_NONE,			//R1_Unorm,
							//R9G9B9E5_SharedExp,
	};

	// GL_NONE == unsupported format
	static uint32 GLResourceTypeFormat[] = {
		GL_NONE,					
		GL_UNSIGNED_INT,					//R32G32B32A32_Typeless,
		GL_FLOAT,							//R32G32B32A32_Float,
		GL_UNSIGNED_INT,					//R32G32B32A32_Uint,
		GL_INT,								//R32G32B32A32_Sint,
		GL_UNSIGNED_INT,					//R32G32B32_Typeless,
		GL_FLOAT,							//R32G32B32_Float,
		GL_UNSIGNED_INT,					//R32G32B32_Uint,
		GL_INT,								//R32G32B32_Sint,
		GL_UNSIGNED_SHORT,					//R16G16B16A16_Typeless,
		GL_HALF_FLOAT,						//R16G16B16A16_Float,
		GL_UNSIGNED_SHORT,					//R16G16B16A16_Unorm,
		GL_UNSIGNED_SHORT,					//R16G16B16A16_Uint,
		GL_SHORT,							//R16G16B16A16_Snorm,
		GL_SHORT,							//R16G16B16A16_Sint,
		GL_UNSIGNED_INT,					//R32G32_Typeless,
		GL_FLOAT,							//R32G32_Float,
		GL_UNSIGNED_INT,					//R32G32_Uint,
		GL_INT,								//R32G32_Sint,
		GL_NONE,							//R32G8X24_Typeless,
		GL_FLOAT_32_UNSIGNED_INT_24_8_REV,	//D32_Float_S8X24_Uint,
		GL_NONE,							//R32_Float_X8X24_Typeless,
		GL_NONE,							//X32_Typeless_G8X24_Uint,
		GL_UNSIGNED_INT_10_10_10_2,			//R10G10B10A2_Typeless,
		GL_UNSIGNED_INT_10_10_10_2,			//R10G10B10A2_Unorm,
		GL_UNSIGNED_INT_10_10_10_2,			//R10G10B10A2_Uint,
		GL_UNSIGNED_INT_10F_11F_11F_REV,	//R11G11B10_Float,
		GL_UNSIGNED_BYTE,					//R8G8B8A8_Typeless,
		GL_UNSIGNED_BYTE,					//R8G8B8A8_Unorm,
		GL_UNSIGNED_BYTE,					//R8G8B8A8_Unorm_Srgb,
		GL_UNSIGNED_BYTE,					//R8G8B8A8_Uint,
		GL_BYTE,							//R8G8B8A8_Snorm,
		GL_BYTE,							//R8G8B8A8_Sint,
		GL_UNSIGNED_SHORT,					//R16G16_Typeless,
		GL_HALF_FLOAT,						//R16G16_Float,
		GL_UNSIGNED_SHORT,					//R16G16_Unorm,
		GL_UNSIGNED_SHORT,					//R16G16_Uint,
		GL_SHORT,							//R16G16_Snorm,
		GL_SHORT,							//R16G16_Sint,
		GL_UNSIGNED_INT,					//R32_Typeless,
		GL_FLOAT,							//D32_Float,
		GL_FLOAT,							//R32_Float,
		GL_UNSIGNED_INT,					//R32_Uint,
		GL_INT,								//R32_Sint,
		GL_UNSIGNED_INT_24_8,				//R24G8_Typeless,
		GL_NONE,							//D24_Unorm_S8_Uint,
		GL_NONE,							//R24_Unorm_X8_Typeless,
		GL_NONE,							//X24_Typeless_G8_Uint,
		GL_UNSIGNED_BYTE,					//R8G8_Typeless,
		GL_UNSIGNED_BYTE,					//R8G8_Unorm,
		GL_UNSIGNED_BYTE,					//R8G8_Uint,
		GL_BYTE,							//R8G8_Snorm,
		GL_BYTE,							//R8G8_Sint,
		GL_UNSIGNED_SHORT,					//R16_Typeless,
		GL_HALF_FLOAT,						//R16_Float,
		GL_UNSIGNED_SHORT,					//D16_Unorm,
		GL_UNSIGNED_SHORT,					//R16_Unorm,
		GL_UNSIGNED_SHORT,					//R16_Uint,
		GL_SHORT,							//R16_Snorm,
		GL_SHORT,							//R16_Sint,
		GL_UNSIGNED_BYTE,					//R8_Typeless,
		GL_UNSIGNED_BYTE,					//R8_Unorm,
		GL_UNSIGNED_BYTE,					//R8_Uint,
		GL_BYTE,							//R8_Snorm,
		GL_BYTE,							//R8_Sint,
		GL_UNSIGNED_BYTE,					//A8_Unorm,
		GL_NONE,							//R1_Unorm,
		GL_NONE,							//R9G9B9E5_SharedExp,
	};

	static int32 GLTextureFilterMin[] = {
		GL_NEAREST_MIPMAP_NEAREST,
		GL_NEAREST_MIPMAP_LINEAR,
		GL_NEAREST_MIPMAP_NEAREST,
		GL_NEAREST_MIPMAP_LINEAR,

		GL_LINEAR_MIPMAP_NEAREST,
		GL_LINEAR_MIPMAP_LINEAR,
		GL_LINEAR_MIPMAP_NEAREST,
		GL_LINEAR_MIPMAP_LINEAR,

		GL_LINEAR_MIPMAP_LINEAR,

		GL_NEAREST_MIPMAP_NEAREST,
		GL_NEAREST_MIPMAP_LINEAR,
		GL_NEAREST_MIPMAP_NEAREST,
		GL_NEAREST_MIPMAP_LINEAR,

		GL_LINEAR_MIPMAP_NEAREST,
		GL_LINEAR_MIPMAP_LINEAR,
		GL_LINEAR_MIPMAP_NEAREST,
		GL_LINEAR_MIPMAP_LINEAR,

		GL_LINEAR_MIPMAP_LINEAR,

		GL_NEAREST_MIPMAP_NEAREST,
		GL_NEAREST_MIPMAP_LINEAR,
		GL_NEAREST_MIPMAP_NEAREST,
		GL_NEAREST_MIPMAP_LINEAR,

		GL_LINEAR_MIPMAP_NEAREST,
		GL_LINEAR_MIPMAP_LINEAR,
		GL_LINEAR_MIPMAP_NEAREST,
		GL_LINEAR_MIPMAP_LINEAR,

		GL_LINEAR_MIPMAP_LINEAR,
	};

	static int32 GLTextureFilterMag[] = {
		GL_NEAREST,
		GL_NEAREST,
		GL_LINEAR,
		GL_LINEAR,

		GL_NEAREST,
		GL_NEAREST,
		GL_LINEAR,
		GL_LINEAR,

		GL_LINEAR
	};

	static int32 GLTextureAddressing[] = {
		GL_REPEAT,
		GL_MIRRORED_REPEAT,
		GL_CLAMP_TO_EDGE,
		GL_CLAMP_TO_BORDER,
		GL_MIRROR_CLAMP_TO_EDGE
	};

	static int32 GLCmpFunction[] = {
		GL_NEVER,
		GL_LESS,
		GL_EQUAL,
		GL_LEQUAL,
		GL_GREATER,
		GL_NOTEQUAL,
		GL_GEQUAL,
		GL_ALWAYS
	};

	static VertexAttribPointerFormat GLVertAttribFormat[] = {
		{ 4, GL_UNSIGNED_INT, false },					//R32G32B32A32_Typeless,
		{ 4, GL_FLOAT, false },							//R32G32B32A32_Float,
		{ 4, GL_UNSIGNED_INT, false },					//R32G32B32A32_Uint,
		{ 4, GL_INT, false },							//R32G32B32A32_Sint,
		{ 3, GL_UNSIGNED_INT, false },					//R32G32B32_Typeless,
		{ 3, GL_FLOAT, false },							//R32G32B32_Float,
		{ 3, GL_UNSIGNED_INT, false },					//R32G32B32_Uint,
		{ 3, GL_INT, false },							//R32G32B32_Sint,
		{ 4, GL_UNSIGNED_SHORT, false },				//R16G16B16A16_Typeless,
		{ 4, GL_HALF_FLOAT, false },					//R16G16B16A16_Float,
		{ 4, GL_UNSIGNED_SHORT, true },					//R16G16B16A16_Unorm,
		{ 4, GL_UNSIGNED_SHORT, false },				//R16G16B16A16_Uint,
		{ 4, GL_SHORT, true },							//R16G16B16A16_Snorm,
		{ 4, GL_SHORT, false },							//R16G16B16A16_Sint,
		{ 2, GL_UNSIGNED_INT, false },					//R32G32_Typeless,
		{ 2, GL_FLOAT, false },							//R32G32_Float,
		{ 2, GL_UNSIGNED_INT, false },					//R32G32_Uint,
		{ 2, GL_INT, false },							//R32G32_Sint,
		{ 0, GL_NONE, false },							//R32G8X24_Typeless,
		{ 0, GL_NONE, false },							//D32_Float_S8X24_Uint,
		{ 0, GL_NONE, false },							//R32_Float_X8X24_Typeless,
		{ 0, GL_NONE, false },							//X32_Typeless_G8X24_Uint,
		{ 4, GL_UNSIGNED_INT_2_10_10_10_REV, false },	//R10G10B10A2_Typeless,
		{ 4, GL_UNSIGNED_INT_2_10_10_10_REV, true },	//R10G10B10A2_Unorm,
		{ 4, GL_INT_2_10_10_10_REV, false },			//R10G10B10A2_Uint,
		{ 4, GL_UNSIGNED_INT_10F_11F_11F_REV, false },	//R11G11B10_Float,

		//R8G8B8A8_Typeless,
		//R8G8B8A8_Unorm,
		//R8G8B8A8_Unorm_Srgb,
		//R8G8B8A8_Uint,
		//R8G8B8A8_Snorm,
		//R8G8B8A8_Sint,
		//R16G16_Typeless,
		//R16G16_Float,
		//R16G16_Unorm,
		//R16G16_Uint,
		//R16G16_Snorm,
		//R16G16_Sint,
		//R32_Typeless,
		//D32_Float,
		//R32_Float,
		//R32_Uint,
		//R32_Sint,
		//R24G8_Typeless,
		//D24_Unorm_S8_Uint,
		//R24_Unorm_X8_Typeless,
		//X24_Typeless_G8_Uint,
		//R8G8_Typeless,
		//R8G8_Unorm,
		//R8G8_Uint,
		//R8G8_Snorm,
		//R8G8_Sint,
		//R16_Typeless,
		//R16_Float,
		//D16_Unorm,
		//R16_Unorm,
		//R16_Uint,
		//R16_Snorm,
		//R16_Sint,
		//R8_Typeless,
		//R8_Unorm,
		//R8_Uint,
		//R8_Snorm,
		//R8_Sint,
		//A8_Unorm,
	}

}}}}