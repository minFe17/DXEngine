#include "DXEngineLayer.h"

namespace DXEngine
{
	Layer::Layer() : gameObjects{}
	{
	}
	Layer::~Layer()
	{
		for (GameObject* gameObject : gameObjects)
		{
			if (gameObject == nullptr)
				continue;

			delete gameObject;
			gameObject = nullptr;
		}
	}

	void Layer::Init()
	{
		for (size_t i = 0; i < gameObjects.size(); i++)
		{
			if (gameObjects[i] == nullptr)
				continue;

			GameObject::EStateType state = gameObjects[i]->GetState();
			if (state == GameObject::EStateType::Paused || state == GameObject::EStateType::Destroyed)
				continue;

			gameObjects[i]->Init();
		}
	}

	void Layer::Update()
	{
		for (size_t i = 0; i < gameObjects.size(); i++)
		{
			if (gameObjects[i] == nullptr)
				continue;
			gameObjects[i]->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (size_t i = 0; i < gameObjects.size(); i++)
		{
			if (gameObjects[i] == nullptr)
				continue;
			gameObjects[i]->LateUpdate();
		}
	}

	void Layer::Render()
	{
	}

	void Layer::EndOfFrame()
	{
		
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;
		gameObjects.push_back(gameObject);
	}

	void Layer::EraseGameObject(GameObject* eraseGameObject)
	{
		GameObject* buffer = eraseGameObject;
		std::erase_if(gameObjects, [=](GameObject* gameObject)
			{
				return gameObject == eraseGameObject;
			});
		delete buffer;
		buffer = nullptr;
	}

	void Layer::FindDeadGameObjects(OUT std::vector<GameObject*>& findGameObjects)
	{
		for (GameObject* gameObject : gameObjects)
		{
			GameObject::EStateType active = gameObject->GetState();
			if (active == GameObject::EStateType::Destroyed)
				findGameObjects.push_back(gameObject);
		}
	}

	void Layer::DeleteGameObjects(std::vector<GameObject*> deleteObjects)
	{
		for (GameObject* object : deleteObjects)
		{
			delete object;
			object = nullptr;
		}
	}

	void Layer::EraseDeadGameObject()
	{
		std::erase_if(gameObjects, [](GameObject* gameObject)
			{
				return (gameObject)->IsDead();
			});
	}
}