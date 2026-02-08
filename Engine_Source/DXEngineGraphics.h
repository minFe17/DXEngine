#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#include <wrl.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include "CommonInclude.h"

namespace DXEngine::Graphics
{
	struct Vertex
	{
		Math::Vector3 position;
		Math::Vector4 color;
		Math::Vector2 uv; //texture coordinate
	};
	enum class EShaderStage
	{
		VS,		// Vertex Shader
		HS,		// Hull Shader
		DS,		// Domain Shader
		GS,		// Geometry Shader
		PS,		// Pixel Shader
		CS,		// Compute Shader
		All,
		Max,
	};

	enum class ECBType
	{
		Transform,
		Max,
	};

	enum class ESamplerType
	{
		Point,
		Linear,
		Anisotropic,
		PostProcess,
		Max,
	};

	enum class ERenderingMode
	{
		Opaque,
		CutOut,
		Transparent,
		PostProcess,
		Max,
	};

	enum class ETextureType
	{
		Albedo,
		Normal,
		Specular,
		Smoothness,
		Metallic,
		Max,
	};

	struct GpuBuffer
	{
		Microsoft::WRL::ComPtr<ID3D11Buffer> buffer = nullptr;
		D3D11_BUFFER_DESC desc = {};

		GpuBuffer() = default;
		virtual ~GpuBuffer() = default;
	};
}