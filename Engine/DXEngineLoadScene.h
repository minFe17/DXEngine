#pragma once
#include "..\\Engine_Source\DXEngineSceneManager.h"
#include "DXEnginePlayScene.h"
#include "DXEngineTitleScene.h"

namespace DXEngine
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"TitleScene");
	}
}