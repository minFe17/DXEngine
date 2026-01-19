#include "DXEngineScene.h"

namespace DXEngine
{
	Scene::Scene() : gameObjects{}
	{
	}

	Scene::~Scene()
	{
	}

	void Scene::Init()
	{
	}

	void Scene::Update()
	{
		for (size_t i = 0; i < gameObjects.size(); i++)
			gameObjects[i]->Update();
	}

	void Scene::LateUpdate()
	{
		for (size_t i = 0; i < gameObjects.size(); i++)
			gameObjects[i]->LateUpdate();
	}

	void Scene::Render(HDC hdc)
	{
		for (size_t i = 0; i < gameObjects.size(); i++)
			gameObjects[i]->Render(hdc);
	}

	void Scene::AddGameObject(GameObject* gameObject)
	{
		gameObjects.push_back(gameObject);
	}
}