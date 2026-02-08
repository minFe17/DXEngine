#pragma once
#include "DXEngineCamera.h"
#include "DXEngineGraphicDevice_DX11.h"

#include "DXEngineConstantBuffer.h"

using namespace DXEngine::Math;
using namespace DXEngine::Graphics;

namespace DXEngine::Renderer
{
	extern Camera* mainCamera;
	extern Graphics::ConstantBuffer constantBuffers[(UINT)ECBType::Max];

	void Init();
	void Release();
}