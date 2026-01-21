#pragma once
#include "..\\Engine_Source\DXEngineResources.h"
#include "..\\Engine_Source\DXEngineTexture.h"

namespace DXEngine
{
	void LoadResources()
	{
		Resources::Load<Graphcis::Texture>(L"Background", L"Resources/CloudOcean.png");
	}
}