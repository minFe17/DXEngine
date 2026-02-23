#pragma once
#include "..\\Engine_Source\DXEngineSceneManager.h"
#include "DXEnginePlayScene.h"
#include "DXEngineTitleScene.h"
#include "DXEngineEditorScene.h"

namespace DXEngine
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<EditorScene>(L"EditorScene");
		SceneManager::LoadScene(L"TitleScene");
	}
}