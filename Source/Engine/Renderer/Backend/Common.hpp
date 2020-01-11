#pragma once

#include "../../Types.hpp"

namespace Hx { namespace Renderer { namespace Backend {

	enum class ResourceUsage : uint32
	{
		Default = 0,
		Constant,
		Dynamic,
		Staging,

		Count
	};

	enum class ResourceFormat : uint32
	{
		Unknown = 0,
		R32G32B32A32_Typeless,
		R32G32B32A32_Float,
		R32G32B32A32_Uint,
		R32G32B32A32_Sint,
		R32G32B32_Typeless,
		R32G32B32_Float,
		R32G32B32_Uint,
		R32G32B32_Sint,
		R16G16B16A16_Typeless,
		R16G16B16A16_Float,
		R16G16B16A16_Unorm,
		R16G16B16A16_Uint,
		R16G16B16A16_Snorm,
		R16G16B16A16_Sint,
		R32G32_Typeless,
		R32G32_Float,
		R32G32_Uint,
		R32G32_Sint,
		R32G8X24_Typeless,
		D32_Float_S8X24_Uint,
		R32_Float_X8X24_Typeless,
		X32_Typeless_G8X24_Uint,
		R10G10B10A2_Typeless,
		R10G10B10A2_Unorm,
		R10G10B10A2_Uint,
		R11G11B10_Float,
		R8G8B8A8_Typeless,
		R8G8B8A8_Unorm,
		R8G8B8A8_Unorm_Srgb,
		R8G8B8A8_Uint,
		R8G8B8A8_Snorm,
		R8G8B8A8_Sint,
		R16G16_Typeless,
		R16G16_Float,
		R16G16_Unorm,
		R16G16_Uint,
		R16G16_Snorm,
		R16G16_Sint,
		R32_Typeless,
		D32_Float,
		R32_Float,
		R32_Uint,
		R32_Sint,
		R24G8_Typeless,
		D24_Unorm_S8_Uint,
		R24_Unorm_X8_Typeless,
		X24_Typeless_G8_Uint,
		R8G8_Typeless,
		R8G8_Unorm,
		R8G8_Uint,
		R8G8_Snorm,
		R8G8_Sint,
		R16_Typeless,
		R16_Float,
		D16_Unorm,
		R16_Unorm,
		R16_Uint,
		R16_Snorm,
		R16_Sint,
		R8_Typeless,
		R8_Unorm,
		R8_Uint,
		R8_Snorm,
		R8_Sint,
		A8_Unorm,
		R1_Unorm,
		R9G9B9E5_SharedExp,
		R8G8_B8G8_Unorm,
		G8R8_G8B8_Unorm,
		BC1_Typeless,
		BC1_Unorm,
		BC1_Unorm_Srgb,
		BC2_Typeless,
		BC2_Unorm,
		BC2_Unorm_Srgb,
		BC3_Typeless,
		BC3_Unorm,
		BC3_Unorm_Srgb,
		BC4_Typeless,
		BC4_Unorm,
		BC4_Snorm,
		BC5_Typeless,
		BC5_Unorm,
		BC5_Snorm,
		B5G6R5_Unorm,
		B5G5R5A1_Unorm,
		B8G8R8A8_Unorm,
		B8G8R8X8_Unorm,
		R10G10B10_XR_Bias_A2_Unorm,
		B8G8R8A8_Typeless,
		B8G8R8A8_Unorm_Srgb,
		B8G8R8X8_Typeless,
		B8G8R8X8_Unorm_Srgb,
		BC6H_Typeless,
		BC6H_UFloat16,
		BC6H_SFloat16,
		BC7_Typeless,
		BC7_Unorm,
		BC7_Unorm_Srgb,

		Count // Keep at last
	};

	enum class ResourceBindFlag : uint32
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

	enum class ResourceAccess : uint32
	{
		NoAccess,
		Write,
		Read,

		Count // Keep at last
	};

	enum class ResourceMisc : uint32
	{
		None,
		GenerateMipMaps,
		TextureCube,
		SharedResource,
		
		Count // Keep at last
	};

	enum class ClearFlag : uint32
	{
		Depth,
		Stencil,

		Count // Keep at last
	};

	enum class CmpFunction : uint32
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

	enum class StencilOp : uint32
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

	enum class PrimitiveTopology : uint32
	{
		Undefined = 0,
		Points,
		LineList,
		LineStrip,
		TriList,
		TriStrip,
		LineListAdj,
		LineStripAdj,
		TriListAdj,
		TriStripAdj,

		Count
	};

	enum class ElementClass : uint32
	{
		PerVertexData,
		PerInstanceData,

		Count
	};

	enum class TextureFilter : uint32
	{
		MinMagMipNearest = 0,
		MinMagNearestMipLinear,
		MinNearestMagLinearMipNearest,
		MinNearestMagMipLinear,
		MinLinearMagMipNearest,
		MinLinearMagNearestMipLinear,
		MinMagLinearMipNearest,
		MinMagMipLinear,
		Anisotropic,
		ComparisonMinMagMipNearest,
		ComparisonMinMagNearestMipLinear,
		ComparisonMinNearestMagLinearMipNearest,
		ComparisonMinNearestMagMipLinear,
		ComparisonMinLinearMagMipNearest,
		ComparisonMinLinearMagNearestMipLinear,
		ComparisonMinMagLinearMipNearest,
		ComparisonMinMagMipLinear,
		ComparisonAnisotropic,
		MinimumMinMagMipNearest,
		MinimumMinMagNearestMipLinear,
		MinimumMinNearestMagLinearMipNearest,
		MinimumMinNearestMagMipLinear,
		MinimumMinLinearMagMipNearest,
		MinimumMinLinearMagNearestMipLinear,
		MinimumMinMagLinearMipNearest,
		MinimumMinMagMipLinear,
		MinimumAnisotropic,
		MaximumMinMagMipNearest,
		MaximumMinMagNearestMipLinear,
		MaximumMinNearestMagLinearMipNearest,
		MaximumMinNearestMagMipLinear,
		MaximumMinLinearMagMipNearest,
		MaximumMinLinearMagNearestMipLinear,
		MaximumMinMagLinearMipNearest,
		MaximumMinMagMipLinear,
		MaximumAnisotropic,

		Count
	};

	enum class TextureAddressing : uint32
	{
		Wrap,
		Mirror,
		Clamp,
		Border,
		MirrorOnce,

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

	struct SamplerStateDesc
	{
		TextureFilter		Filter;
		TextureAddressing	AddressU;
		TextureAddressing	AddressV;
		TextureAddressing	AddressW;
		float				MipLodBias;
		uint32				MaxAnisotropy;
		CmpFunction			CompFunction;
		float				BorderColor[4];
		float				MinLod;
		float				MaxLod;
	};

}}}
