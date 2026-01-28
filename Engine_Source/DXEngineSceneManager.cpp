#include "DXEngineSceneManager.h"
#include "DXEngineDontDestroyOnLoad.h"

namespace DXEngine
{
	std::map<const std::wstring, Scene*> SceneManager::scenes;
	Scene* SceneManager::activeScene = nullptr;
	Scene* SceneManager::dontDestroyScene = nullptr;

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
		dontDestroyScene = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");
	}

	void SceneManager::Update()
	{
		activeScene->Update();
		dontDestroyScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		activeScene->LateUpdate();
		dontDestroyScene->LateUpdate();
	}

	void SceneManager::Render(HDC hdc)
	{
		activeScene->Render(hdc);
		dontDestroyScene->Render(hdc);
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

	void SceneManager::Destroy()
	{
		activeScene->Destroy();
		dontDestroyScene->Destroy();
	}
}