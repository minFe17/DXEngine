#include "DXEngineScene.h"
#include "DXEngineCollisionManager.h"
#include "DXEngineSceneManager.h"

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
		const std::wstring& sceneName = GetName();
		SceneManager::SetActiveScene(sceneName);
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

	void Scene::EndOfFrame()
	{
		for (size_t i = 0; i < layers.size(); i++)
		{
			if (layers[i] == nullptr)
				continue;
			layers[i]->EndOfFrame();
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
		layers[static_cast<UINT>(type)]->AddGameObject(gameObject);
	}

	void Scene::EraseGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		Enum::ELayerType layerType = gameObject->GetLayerType();
		layers[static_cast<UINT>(layerType)]->EraseGameObject(gameObject);
	}

	void Scene::CreateLayers()
	{
		layers.resize(static_cast<UINT>(Enum::ELayerType::Max));
		for (size_t i = 0; i < static_cast<UINT>(Enum::ELayerType::Max); i++)
			layers[i] = new Layer();
	}
}