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
			scene->Init();

			scenes.insert(std::make_pair(name, scene));
			return scene;
		}

		static Scene* LoadScene(const std::wstring& name)
		{
			std::map<const std::wstring, Scene*>::iterator iter = scenes.find(name);

			if (iter == scenes.end())
				return nullptr;

			activeScene = iter->second;
			return iter->second;
		}

		 static void Init();
		 static void Update();
		 static void LateUpdate();
		 static void Render(HDC hdc);

	private:
		static std::map<const std::wstring, Scene*> scenes;
		static Scene* activeScene;
	};
}