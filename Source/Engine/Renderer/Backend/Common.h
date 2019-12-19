#pragma once

#include "../../Types.h"

namespace Hx { namespace Renderer { namespace Backend {

	enum class ResourceUsage : int8
	{
		Default = 0,
		Constant,
		Dynamic,
		Staging,

		Count
	};

	enum class ResourceFormat : int16
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

	enum class ResourceBindFlag : int8
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

	enum class ResourceAccess : int8
	{
		Write,
		Read,

		Count // Keep at last
	};

	enum class ResourceMisc : int8
	{
		GenerateMipMaps,
		TextureCube,
		SharedResource,
		
		Count // Keep at last
	};

	enum class ClearFlag : int8
	{
		Depth,
		Stencil,

		Count // Keep at last
	};

	enum class CmpFunction : int8
	{
		Never,
		Less,
		Equal,
		LessEqual,
		Greater,
		NotEqual,
		GreaterEqual,
		Always,

		Count
	};

	enum class StencilOp : int8
	{
		Keep,
		Zero,
		Replace,
		IncSat,
		DecSat,
		Inv,
		Inc,
		Dec,

		Count
	};

	enum class ElementClass
	{
		PerVertexData,
		PerInstanceData,

		Count
	};

	struct Viewport
	{
		float			TopLeftX;
		float			TopLeftY;
		float			Width;
		float			Height;
		float			MinDepth;
		float			MaxDepth;
	};
	
	struct Texture1DResourceData
	{
		const void*		DataPtr = nullptr;
		uint32			Width = 0;
	};

	struct Texture2DResourceData
	{
		const void*		DataPtr = nullptr;
		uint32			Width = 0;
	};

	struct Texture3DResourceData
	{
		const void*		DataPtr = nullptr;
		uint32			Width = 0;
		uint32			TotalWH = 0;
	};

	struct MultisampleDesc
	{
		uint32			Count;
		uint32			Quality;
	};

	struct DepthStencilDesc
	{
		typedef struct
		{
			StencilOp			StencilFailOp;
			StencilOp			StencilDepthFailOp;
			StencilOp			StencilPassOp;
			CmpFunction			StencilFunc;
		} StencilState;

		bool				DepthEnable;
		bool				CanWrite;
		CmpFunction			DepthFunction;
		bool				StencilEnable;
		uint8				StencilReadMask;
		uint8				StencilWriteMask;
		StencilState		FrontFace;
		StencilState		BackFace;
	};

	struct BufferDesc
	{
		uint32				Length;
		ResourceUsage		Usage;
		ResourceBindFlag	BindFlags;
		ResourceAccess		AccessFlags;
		ResourceMisc		MiscFlags;
		uint32				StrideSize;
	};

	struct Texture1DDesc
	{
		uint32				Length;
		uint32				MipMapLevels;
		uint32				ArrayLength;
		ResourceFormat		Format;
		MultisampleDesc		Multisample;
		ResourceBindFlag	BindFlags;
		ResourceAccess		AccessFlags;
		ResourceMisc		MiscFlags;
	};

	struct Texture2DDesc
	{
		uint32				Width;
		uint32				Height;
		uint32				MipMapLevels;
		uint32				ArrayLength;
		ResourceFormat		Format;
		MultisampleDesc		Multisample;
		ResourceUsage		Usage;
		ResourceBindFlag	BindFlags;
		ResourceAccess		AccessFlags;
		ResourceMisc		MiscFlags;
	};

	struct Texture3DDesc
	{
		uint32				Width;
		uint32				Height;
		uint32				Depth;
		uint32				MipMapLevels;
		ResourceFormat		Format;
		ResourceUsage		Usage;
		ResourceBindFlag	BindFlags;
		ResourceAccess		AccessFlags;
		ResourceMisc		MiscFlags;
	};

	struct VertexElement
	{
		const char*			Name;
		uint32				Index;
		ResourceFormat		Format;
		uint32				InputSlot;
		uint32				AlignedByteOffset;
		ElementClass		InputSlotClass;
		uint32				NumberOfInstance;
	};

}}}
