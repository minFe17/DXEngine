#pragma once

namespace DXEngine::Graphics
{
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
}