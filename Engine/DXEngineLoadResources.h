#pragma once
#include "..\\Engine_Source\DXEngineResources.h"
#include "..\\Engine_Source\DXEngineTexture.h"
#include "..\\Engine_Source\DXEngineRenderer.h"

namespace DXEngine
{
	void LoadResources()
	{
		Resources::Load<Graphics::Texture>(L"Player", L"Resources/CloudOcean.png");

		Renderer::Init();
	}
}