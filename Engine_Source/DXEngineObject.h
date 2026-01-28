#pragma once
#include "DXEngineComponent.h"
#include "DXEngineGameObject.h"
#include "DXEngineLayer.h"
#include "DXEngineScene.h"
#include "DXEngineSceneManager.h"
#include "DXEngineTransform.h"

namespace DXEngine::Object
{
	template <typename T>
	static T* Instantiate(Enum::ELayerType type)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);

		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(Enum::ELayerType type, Math::Vector2 position)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);

		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* transform = gameObject->GetComponent<Transform>();
		transform->SetPosition(position);

		return gameObject;
	}

	static void Destroy(GameObject* gameObject)
	{
		gameObject->Death();
	}

	void DontDestroyOnLoad(GameObject* gameObject)
	{
		Scene* activeScene = SceneManager::GetActiveScene();
		activeScene->EraseGameObject(gameObject);

		Scene* dontDestroyOnLoad = SceneManager::GetDontDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(gameObject, gameObject->GetLayerType());
	}
}