#pragma once
#include "DXEngineCamera.h"
#include "DXEngineGraphicDevice_DX11.h"

#include "DXEngineConstantBuffer.h"

using namespace DXEngine::Math;
using namespace DXEngine::Graphics;

namespace DXEngine::Renderer
{
	extern Camera* mainCamera;
	extern GameObject* selectedObject;
	extern Graphics::ConstantBuffer* constantBuffers[(UINT)ECBType::Max];

	extern Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerStates[(UINT)ESamplerType::Max];
	extern Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[(UINT)ERasterizerState::Max];
	extern Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[(UINT)EBlendState::Max];
	extern Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[(UINT)EDepthStencilState::Max];

	void Init();
	void Release();
}