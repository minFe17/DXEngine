#include "DXEngineSceneManager.h"

namespace DXEngine
{
	std::map<const std::wstring, Scene*> SceneManager::scenes;
	Scene* SceneManager::activeScene = nullptr;

	void SceneManager::Init()
	{
	}

	void SceneManager::Update()
	{
		activeScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		activeScene->LateUpdate();
	}

	void SceneManager::Render(HDC hdc)
	{
		activeScene->Render(hdc);
	}
}