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
			gameObjects[i]->Render(hdc);
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;
		gameObjects.push_back(gameObject);
	}
}