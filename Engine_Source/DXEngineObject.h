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
	static T* Instantiate(DXEngine::Enum::ELayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(DXEngine::Enum::ELayerType type, Math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* transform = gameObject->GetComponent<Transform>();
		transform->SetPosition(position);

		return gameObject;
	}
}