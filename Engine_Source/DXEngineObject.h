#pragma once
#include "DXEngineComponent.h"
#include "DXEngineGameObject.h"
#include "DXEngineLayer.h"
#include "DXEngineScene.h"
#include "DXEngineSceneManager.h"
#include "DXEngineTransform.h"
#include "DXEngineApplication.h"
#include "DXEngineGameObjectEvent.h"
#include "DXEngineSceneManager.h"

extern DXEngine::Application application;

namespace DXEngine::Object
{
	template <typename T>
	static T* Instantiate(Enum::ELayerType type)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);

		Scene* activeScene = SceneManager::GetActiveScene();
		SceneManager::PushEvent(new DXEngine::GameObjectCreatedEvent(gameObject, activeScene));

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(Enum::ELayerType type, Math::Vector3 position)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);

		Transform* transform = gameObject->GetComponent<Transform>();
		transform->SetPosition(position);

		Scene* activeScene = SceneManager::GetActiveScene();
		SceneManager::PushEvent(new DXEngine::GameObjectCreatedEvent(gameObject, activeScene));

		return gameObject;
	}

	static void Destroy(GameObject* gameObject)
	{
		if (gameObject != nullptr)
			gameObject->Death();

		Scene* activeScene = SceneManager::GetActiveScene();
		SceneManager::PushEvent(new DXEngine::GameObjectDestroyedEvent(gameObject, activeScene));
	}

	static void DontDestroyOnLoad(GameObject* gameObject)
	{
		Scene* activeScene = SceneManager::GetActiveScene();
		activeScene->EraseGameObject(gameObject);

		Scene* dontDestroyOnLoad = SceneManager::GetDontDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(gameObject, gameObject->GetLayerType());
	}
}