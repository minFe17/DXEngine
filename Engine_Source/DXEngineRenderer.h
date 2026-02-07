#pragma once
#include "DXEngineCamera.h"
#include "DXEngineGraphicDevice_DX11.h"

#include "DXEngineMesh.h"
#include "DXEngineConstantBuffer.h"

using namespace DXEngine::Math;
using namespace DXEngine::Graphics;

namespace DXEngine::Renderer
{
	extern Camera* mainCamera;

	extern Mesh* mesh;
	extern Graphics::ConstantBuffer constantBuffers[(UINT)ECBType::Max];

	extern ID3D11Buffer* constantBuffer;

	extern ID3D11InputLayout* inputLayouts;

	void Init();
	void Release();
}