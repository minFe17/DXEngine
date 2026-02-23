#pragma once
#include "DXEngineScene.h"
#include "DXEngineEventQueue.h"

namespace DXEngine
{
	class SceneManager
	{
	public:
		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scenes.insert(std::make_pair(name, scene));
			scene->SetName(name);

			return scene;
		}

		static void Init();
		static void Update();
		static void LateUpdate();
		static void Render();
		static void Release();
		static void EndOfFrame();

		static bool SetActiveScene(const std::wstring& name);
		static Scene* LoadScene(const std::wstring& name);

		static Scene* GetActiveScene() { return activeScene; }
		static Scene* GetDontDestroyOnLoad() { return dontDestroyScene; }
		static std::vector<GameObject*> GetGameObjects(Enum::ELayerType layer);

		static void InitEventHandlers();
		static void GameObjectCreated(GameObject* gameObject, Scene* scene);
		static void GameObjectDestroyed(GameObject* gameObject, Scene* scene);
		static void PushEvent(Event* e) { eventQueue.Push(e); }

	private:
		static std::map<const std::wstring, Scene*> scenes;
		static Scene* activeScene;
		static Scene* dontDestroyScene;
		static EventQueue eventQueue;
	};
}