#include "DXEngineScene.h"
#include "DXEngineCollisionManager.h"

namespace DXEngine
{
	Scene::Scene() : layers{}
	{
		layers.resize((UINT)Enum::ELayerType::Max);

		for (size_t i = 0; i < (UINT)Enum::ELayerType::Max; i++)
			layers[i] = new Layer();
	}

	Scene::~Scene()
	{
		for (Layer* layer : layers)
		{
			delete layer;
			layer = nullptr;
		}
	}

	void Scene::Init()
	{
		for (size_t i = 0; i < layers.size(); i++)
		{
			if (layers[i] == nullptr)
				continue;
			layers[i]->Init();
		}
	}

	void Scene::Update()
	{
		for (size_t i = 0; i < layers.size(); i++)
		{
			if (layers[i] == nullptr)
				continue;
			layers[i]->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (size_t i = 0; i < layers.size(); i++)
		{
			if (layers[i] == nullptr)
				continue;
			layers[i]->LateUpdate();
		}
	}

	void Scene::Render()
	{
		for (size_t i = 0; i < layers.size(); i++)
		{
			if (layers[i] == nullptr)
				continue;
			layers[i]->Render();
		}
	}

	void Scene::Destroy()
	{
		for (size_t i = 0; i < layers.size(); i++)
		{
			if (layers[i] == nullptr)
				continue;
			layers[i]->Destroy();
		}
	}

	void Scene::OnEnter()
	{

	}

	void Scene::OnExit()
	{
		CollisionManager::Clear();
	}

	void Scene::AddGameObject(GameObject* gameObject, Enum::ELayerType type)
	{
		layers[(UINT)type]->AddGameObject(gameObject);
	}

	void Scene::EraseGameObject(GameObject* gameObject)
	{
		Enum::ELayerType layerType = gameObject->GetLayerType();
		layers[(UINT)layerType]->EraseGameObject(gameObject);
	}
}