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

			GameObject::EStateType state = gameObjects[i]->GetActive();
			if (state == GameObject::EStateType::Paused || state == GameObject::EStateType::Dead)
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

	void Layer::Render(HDC hdc)
	{
		for (size_t i = 0; i < gameObjects.size(); i++)
		{
			if (gameObjects[i] == nullptr)
				continue;

			GameObject::EStateType state = gameObjects[i]->GetActive();
			if (state == GameObject::EStateType::Paused || state == GameObject::EStateType::Dead)
				continue;

			gameObjects[i]->Render(hdc);
		}
	}

	void Layer::Destroy()
	{
		for (GameObjectIter iter = gameObjects.begin(); iter != gameObjects.end(); )
		{
			GameObject::EStateType state = (*iter)->GetActive();
			if (state == GameObject::EStateType::Dead)
			{
				GameObject* object = (*iter);
				iter = gameObjects.erase(iter);

				delete object;
				continue;
			}
			iter++;
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;
		gameObjects.push_back(gameObject);
	}
}