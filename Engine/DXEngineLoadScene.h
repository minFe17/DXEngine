#pragma once
#include "..\\Engine_Source\DXEngineSceneManager.h"
#include "DXEnginePlayScene.h"

namespace DXEngine
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}