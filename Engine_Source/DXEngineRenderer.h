#pragma once
#include "DXEngineCamera.h"
#include "DXEngineGraphicDevice_DX11.h"
#include "DXEngineVertexBuffer.h"

namespace DXEngine::Renderer
{
	extern Camera* mainCamera;

	extern std::vector<Graphics::Vertex> vertexes;
	extern std::vector<UINT> indices;

	extern Graphics::VertexBuffer vertexBuffer;
	extern ID3D11Buffer* indexBuffer;
	extern ID3D11Buffer* constantBuffer;

	extern ID3D11InputLayout* inputLayouts;

	void Init();
	void Release();
}