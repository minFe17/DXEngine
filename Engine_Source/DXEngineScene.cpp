#include "DXEngineScene.h"
#include "DXEngineCollisionManager.h"
#include "DXEngineMaterial.h"
#include "DXEngineSceneManager.h"
#include "DXEngineTransform.h"
#include "DXEngineRenderer.h"
#include "DXEngineSpriteRenderer.h"

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
		for (Camera* camera : cameras)
		{
			if (camera == nullptr)
				continue;

			Matrix viewMatrix = camera->GetViewMatrix();
			Matrix projectionMatrix = camera->GetProjectionMatrix();
			Vector3 cameraPos = camera->GetOwner()->GetComponent<Transform>()->GetPosition();

			std::vector<GameObject*> opaqueList = {};
			std::vector<GameObject*> cutoutList = {};
			std::vector<GameObject*> transparentList = {};

			// collect randerables(game objects)
			CollectRenderables(opaqueList, cutoutList, transparentList);

			// soring renderables by distance (between camera and game object)
			SortByDistance(opaqueList, cameraPos, true);
			SortByDistance(cutoutList, cameraPos, true);
			SortByDistance(transparentList, cameraPos, false);

			// render game objects
			RenderRenderables(opaqueList, viewMatrix, projectionMatrix);
			RenderRenderables(cutoutList, viewMatrix, projectionMatrix);
			RenderRenderables(transparentList, viewMatrix, projectionMatrix);
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

	void Scene::AddCamera(Camera* camera)
	{
		if (camera == nullptr)
			return;

		cameras.push_back(camera);
	}

	void Scene::RemoveCamera(Camera* camera)
	{
		if (camera == nullptr)
			return;

		auto iter = std::find(cameras.begin(), cameras.end(), camera);

		if (iter != cameras.end())
			cameras.erase(iter);
	}

	void Scene::CollectRenderables(std::vector<GameObject*>& opaqueList, std::vector<GameObject*>& cutoutList, std::vector<GameObject*>& transparentList) const
	{
		for (Layer* layer : layers)
		{
			if (layer == nullptr)
				continue;

			std::vector<GameObject*>& gameObjects = layer->GetGameObjects();

			for (GameObject* gameObj : gameObjects)
			{
				if (gameObj == nullptr)
					continue;

				SpriteRenderer* renderer = gameObj->GetComponent<SpriteRenderer>();
				if (renderer == nullptr)
					continue;

				switch (renderer->GetMaterial()->GetRenderingMode())
				{
				case Graphics::ERenderingMode::Opaque:
					opaqueList.push_back(gameObj);
					break;

				case Graphics::ERenderingMode::CutOut:
					cutoutList.push_back(gameObj);
					break;

				case Graphics::ERenderingMode::Transparent:
					transparentList.push_back(gameObj);
					break;
				}
			}
		}
	}

	void Scene::SortByDistance(std::vector<GameObject*>& renderList, const Vector3& cameraPos, bool bAscending) const
	{
		auto comparator = [cameraPos, bAscending](GameObject* a, GameObject* b)
			{
				float distA = Vector3::Distance(a->GetComponent<Transform>()->GetPosition(), cameraPos);
				float distB = Vector3::Distance(b->GetComponent<Transform>()->GetPosition(), cameraPos);
				return bAscending ? (distA < distB) : (distA > distB);
			};

		std::ranges::sort(renderList, comparator);
	}

	void Scene::RenderRenderables(const std::vector<GameObject*>& renderList, const Matrix& view, const Matrix& projection) const
	{
		for (auto* object : renderList)
		{
			if (object == nullptr)
				continue;

			object->Render(view, projection);
		}
	}

	void Scene::CreateLayers()
	{
		layers.resize(static_cast<UINT>(Enum::ELayerType::Max));
		for (size_t i = 0; i < static_cast<UINT>(Enum::ELayerType::Max); i++)
			layers[i] = new Layer();
	}
}