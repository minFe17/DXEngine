#include "DXEngineSceneManager.h"
#include "DXEngineDontDestroyOnLoad.h"
#include "DXEngineGameObjectEvent.h"

namespace DXEngine
{
	std::map<const std::wstring, Scene*> SceneManager::scenes;
	Scene* SceneManager::activeScene = nullptr;
	Scene* SceneManager::dontDestroyScene = nullptr;
	EventQueue SceneManager::eventQueue;

	void SceneManager::Init()
	{
		dontDestroyScene = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");
		InitEventHandlers();
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

	void SceneManager::Render()
	{
		activeScene->Render();
		dontDestroyScene->Render();
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

	void SceneManager::EndOfFrame()
	{
		activeScene->EndOfFrame();
		dontDestroyScene->EndOfFrame();

		eventQueue.Process();
	}

	bool SceneManager::SetActiveScene(const std::wstring& name)
	{
		std::map<const std::wstring, Scene*>::iterator iter = scenes.find(name);

		if (iter == scenes.end())
			return false;

		activeScene = iter->second;
		return true;
	}

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (activeScene)
			activeScene->OnExit();

		if (!SetActiveScene(name))
			return nullptr;

		activeScene->Init();
		activeScene->OnEnter();

		return activeScene;
	}

	std::vector<GameObject*> SceneManager::GetGameObjects(Enum::ELayerType layer)
	{
		std::vector<GameObject*> gameObjects = activeScene->GetLayer(layer)->GetGameObjects();
		std::vector<GameObject*> dontDestroyGameObjects = dontDestroyScene->GetLayer(layer)->GetGameObjects();

		gameObjects.insert(gameObjects.end(), dontDestroyGameObjects.begin(), dontDestroyGameObjects.end());

		return gameObjects;
	}

	void SceneManager::InitEventHandlers()
	{
		// 이벤트 핸들러 등록
		eventQueue.RegisterHandler<GameObjectCreatedEvent>([](GameObjectCreatedEvent& e) -> bool
			{
				SceneManager::GameObjectCreated(e.GetGameObject(), e.GetScene());
				return true;
			});

		eventQueue.RegisterHandler<GameObjectDestroyedEvent>([](GameObjectDestroyedEvent& e) -> bool
			{
				SceneManager::GameObjectDestroyed(e.GetGameObject(), e.GetScene());
				return true;
			});

		// 기본 핸들러 등록
		eventQueue.SetCallback([](Event& e)
			{
				std::cout << "[Application] Unhandled Event: " << e.ToString() << std::endl;
			});
	}

	void SceneManager::GameObjectCreated(GameObject* gameObject, Scene* scene)
	{
		scene->AddGameObject(gameObject, gameObject->GetLayerType());
	}

	void SceneManager::GameObjectDestroyed(GameObject* gameObject, Scene* scene)
	{
		scene->EraseGameObject(gameObject);
	}
}