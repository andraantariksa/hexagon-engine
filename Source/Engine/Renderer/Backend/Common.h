#pragma once

#include "../../Types.h"

namespace Hx { namespace Renderer { namespace Backend {

	enum class EBackendAPI : Int8
	{
		DX11 = 0,
		OGL,

		Count
	};

	enum class EResourceUsage : Int8
	{
		Default = 0,
		Constant,
		Dynamic,
		Staging,

		Count
	};

	enum class EResourceFormat : Int16
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

	enum class EResourceBindFlag : Int8
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

	enum class EResourceAccess
	{
		Write,
		Read,

		Count // Keep at last
	};

	enum class EResourceMisc
	{
		GenerateMipMaps,
		TextureCube,
		SharedResource,
		
		Count
	};

	struct STexture1DResourceData
	{
		const void*		DataPtr = nullptr;
		Uint32			Width = 0;
	};

	struct STexture2DResourceData
	{
		const void*		DataPtr = nullptr;
		Uint32			Width = 0;
	};

	struct STexture3DResourceData
	{
		const void*		DataPtr = nullptr;
		Uint32			Width = 0;
		Uint32			TotalWH = 0;
	};

	struct SMultisampleDesc
	{
		Uint32			Count;
		Uint32			Quality;
	};

	struct STexture1DDesc
	{
		Uint32				Length;
		Uint32				MipMapLevels;
		Uint32				ArrayLength;
		EResourceFormat		Format;
		SMultisampleDesc	MultisampleDesc;
		EResourceBindFlag	BindFlags;
		EResourceAccess		AccessFlags;
		EResourceMisc		MiscFlags;
	};

	struct STexture2DDesc
	{
		Uint32				Width;
		Uint32				Height;
		Uint32				MipMapLevels;
		Uint32				ArrayLength;
		EResourceFormat		Format;
		SMultisampleDesc	MultisampleDesc;
		EResourceUsage		Usage;
		EResourceBindFlag	BindFlags;
		EResourceAccess		AccessFlags;
		EResourceMisc		MiscFlags;
	};

	struct STexture3DDesc
	{
		Uint32				Width;
		Uint32				Height;
		Uint32				Depth;
		Uint32				MipMapLevels;
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
