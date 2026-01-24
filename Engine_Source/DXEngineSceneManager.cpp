#include "DXEngineSceneManager.h"

namespace DXEngine
{
	std::map<const std::wstring, Scene*> SceneManager::scenes;
	Scene* SceneManager::activeScene = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (activeScene != nullptr)
			activeScene->OnExit();
		std::map<const std::wstring, Scene*>::iterator iter = scenes.find(name);

		if (iter == scenes.end())
			return nullptr;

		activeScene = iter->second;
		activeScene->OnEnter();
		return iter->second;
	}

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

	void SceneManager::Release()
	{
		static std::map<std::wstring, Scene*> scene;

		for (auto& iter : scenes)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
}