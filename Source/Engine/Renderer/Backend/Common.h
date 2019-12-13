#pragma once

#include "../../Types.h"

namespace Hx { namespace Renderer { namespace Backend {

	enum class EBackendAPI : int8
	{
		DX11 = 0,
		OGL,

		Count
	};

	enum class EResourceUsage : int8
	{
		Default = 0,
		Constant,
		Dynamic,
		Staging,

		Count
	};

	enum class EResourceFormat : int16
	{
		Unknown = 0,
		R32G32B32A32_Typeless,
		R32G32B32A32_Float,
		R32G32B32A32_Uint,
		R32G32B32A32_Sint,
		R32_Typeless,
		R32_Float,
		R32_Uint,
		R32_Sint,
		R8G8B8A8_Unorm,
		R8G8B8A8_Unorm_Srgb,
		R8G8B8A8_Uint,
		R8G8B8A8_Snorm,
		R8G8B8A8_Sint,

		Count // Keep at last
	};

	enum class EResourceBindFlag : int8
	{
		VertexBuffer,
		IndexBuffer,
		ConstantBuffer,
		ShaderResource,
		StreamOutput,
		RenderTarget,
		UnorderedAccess,
		VideoDecoding,
		VideoEncoding,

		Count // Keep at last
	};

	enum class EResourceAccess : int8
	{
		Write,
		Read,

		Count // Keep at last
	};

	enum class EResourceMisc : int8
	{
		GenerateMipMaps,
		TextureCube,
		SharedResource,
		
		Count
	};

	enum class EClearFlag : int8
	{
		Depth,
		Stencil,

		Count
	};

	struct STexture1DResourceData
	{
		const void*		DataPtr = nullptr;
		uint32			Width = 0;
	};

	struct STexture2DResourceData
	{
		const void*		DataPtr = nullptr;
		uint32			Width = 0;
	};

	struct STexture3DResourceData
	{
		const void*		DataPtr = nullptr;
		uint32			Width = 0;
		uint32			TotalWH = 0;
	};

	struct SMultisampleDesc
	{
		uint32			Count;
		uint32			Quality;
	};

	struct STexture1DDesc
	{
		uint32				Length;
		uint32				MipMapLevels;
		uint32				ArrayLength;
		EResourceFormat		Format;
		SMultisampleDesc	MultisampleDesc;
		EResourceBindFlag	BindFlags;
		EResourceAccess		AccessFlags;
		EResourceMisc		MiscFlags;
	};

	struct STexture2DDesc
	{
		uint32				Width;
		uint32				Height;
		uint32				MipMapLevels;
		uint32				ArrayLength;
		EResourceFormat		Format;
		SMultisampleDesc	MultisampleDesc;
		EResourceUsage		Usage;
		EResourceBindFlag	BindFlags;
		EResourceAccess		AccessFlags;
		EResourceMisc		MiscFlags;
	};

	struct STexture3DDesc
	{
		uint32				Width;
		uint32				Height;
		uint32				Depth;
		uint32				MipMapLevels;
		EResourceFormat		Format;
		EResourceUsage		Usage;
		EResourceBindFlag	BindFlags;
		EResourceAccess		AccessFlags;
		EResourceMisc		MiscFlags;
	};

	struct SVertexElement
	{
		const char*			SemanticName;

	};

}}}
