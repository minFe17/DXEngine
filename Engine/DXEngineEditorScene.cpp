#include "DXEngineEditorScene.h"
#include "DXEngineGameObject.h"
#include "DXEnginePlayer.h"
#include "DXEngineUIManager.h"
#include "DXEngineSpriteRenderer.h"
#include "DXEngineTitleScene.h"
#include "DXEngineObject.h"
#include "DXEngineTexture.h"
#include "DXEngineResources.h"
#include "DXEnginePlayerScript.h"
#include "DXEngineCamera.h"
#include "DXEngineRenderer.h"
#include "DXEngineSceneCamera.h"

namespace DXEngine
{
	EditorScene::EditorScene()
	{
	}

	EditorScene::~EditorScene()
	{
	}

	void EditorScene::Init()
	{
		Scene::Init();

		// main camera
		GameObject* camera = Object::Instantiate<GameObject>(ELayerType::None, Vector3(0.0f, 0.0f, -10.0f));

		SceneCamera* cameraComp = camera->AddComponent<SceneCamera>();
		cameraComp->SetProjectionType(Camera::EProjectionType::Perspective);
		cameraComp->SetSize(200.0f);

		Renderer::mainCamera = cameraComp;

		for (size_t i = 0; i < 1; i++)
		{
			GameObject* player = Object::Instantiate<Player>(ELayerType::Player);
			SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();
			sr->SetSprite(Resources::Find<Texture>(L"Player"));

			player->AddComponent<PlayerScript>();

			if (Renderer::selectedObject == nullptr)
				Renderer::selectedObject = player;
		}
	}

	void EditorScene::Update()
	{
		Scene::Update();
	}

	void EditorScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void EditorScene::Render()
	{
		Scene::Render();
	}

	void EditorScene::OnEnter()
	{
		Scene::OnEnter();
	}

	void EditorScene::OnExit()
	{
		Scene::OnExit();
	}
}