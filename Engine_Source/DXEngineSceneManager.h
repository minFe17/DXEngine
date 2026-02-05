#pragma once
#include "DXEngineScene.h"

namespace DXEngine
{
	class SceneManager
	{
	public:
		template <typename T> 
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);

			activeScene = scene;
			scene->Init();

			scenes.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name);
		static Scene* GetActiveScene() { return activeScene; }
		static Scene* GetDontDestroyOnLoad() { return dontDestroyScene; }
		static std::vector<GameObject*> GetGameObjects(Enum::ELayerType layer);

		 static void Init();
		 static void Update();
		 static void LateUpdate();
		 static void Render();
		 static void Release();
		 static void Destroy();

	private:
		static std::map<const std::wstring, Scene*> scenes;
		static Scene* activeScene;
		static Scene* dontDestroyScene;
	};
}