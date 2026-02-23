#include "DXEnginePlayScene.h"
#include "DXEngineGameObject.h"
#include "DXEnginePlayer.h"
#include "DXEngineSpriteRenderer.h"
#include "DXEngineObject.h"
#include "DXEngineTexture.h"
#include "DXEngineResources.h"
#include "DXEnginePlayerScript.h"
#include "DXEngineCamera.h"
#include "DXEngineRenderer.h"
#include "DXEngineSceneCamera.h"

namespace DXEngine
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{

	}

	void PlayScene::Init()
	{
		GameObject* camera = Object::Instantiate<GameObject>(Enum::ELayerType::None, Vector3(0.0f, 0.0f, -10.0f));

		SceneCamera* cameraComponent = camera->AddComponent<SceneCamera>();
		cameraComponent->SetProjectionType(Camera::EProjectionType::Perspective);
		cameraComponent->SetSize(200.0f);

		Renderer::mainCamera = cameraComponent;

		for (size_t i = 0; i < 1; i++)
		{
			GameObject* player = Object::Instantiate<Player>(Enum::ELayerType::Player);
			SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
			sr->SetSprite(Resources::Find<Texture>(L"Player"));

			player->AddComponent<PlayerScript>();

			if (Renderer::selectedObject == nullptr)
				Renderer::selectedObject = player;
		}

		Scene::Init();
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render()
	{
		Scene::Render();
	}

	void PlayScene::OnEnter()
	{
		Scene::OnEnter();
	}

	void PlayScene::OnExit()
	{

	}
}