#include "DXEngineScene.h"

namespace DXEngine
{
	Scene::Scene() : layers{}
	{
		layers.resize((UINT)ELayerType::Max);

		for (size_t i = 0; i < (UINT)ELayerType::Max; i++)
			layers[i] = new Layer();
	}

	Scene::~Scene()
	{
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

	void Scene::Render(HDC hdc)
	{
		for (size_t i = 0; i < layers.size(); i++)
		{
			if (layers[i] == nullptr)
				continue;
			layers[i]->Render(hdc);
		}
	}

	void Scene::OnEnter()
	{

	}

	void Scene::OnExit()
	{

	}

	void Scene::AddGameObject(GameObject* gameObject, ELayerType type)
	{
		layers[(UINT)type]->AddGameObject(gameObject);
	}
}