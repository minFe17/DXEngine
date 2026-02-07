#include "DXEnginePlayScene.h"
#include "DXEngineGameObject.h"
#include "DXEnginePlayer.h"
#include "DXEngineTransform.h"
#include "DXEngineSpriteRenderer.h"
#include "DXEngineInput.h"
#include "DXEngineSceneManager.h"
#include "DXEngineObject.h"
#include "DXEngineTexture.h"
#include "DXEngineResources.h"
#include "DXEnginePlayerScript.h"
#include "DXEngineCamera.h"
#include "DXEngineRenderer.h"
#include "DXEngineAnimator.h"

namespace DXEngine
{
	PlayScene::PlayScene() : background(nullptr)
	{
	}

	PlayScene::~PlayScene()
	{

	}

	void PlayScene::Init()
	{
		background = Object::Instantiate<Player>(Enum::ELayerType::Background);
		SpriteRenderer* spriteRenderer = background->AddComponent<SpriteRenderer>();
		Graphics::Texture* texture = Resources::Find<Graphics::Texture>(L"Player");
		spriteRenderer->SetTexture(texture);

		GameObject* camera = Object::Instantiate<GameObject>(Enum::ELayerType::None);
		Camera* cameraComponent = camera->AddComponent<Camera>();
		Renderer::mainCamera = cameraComponent;
		camera->AddComponent<PlayerScript>();


		Scene::Init();
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(EKeyCode::N))
			SceneManager::LoadScene(L"TitleScene");
	}

	void PlayScene::Render()
	{
		Scene::Render();
		Graphics::GetDevice()->Draw();

	}

	void PlayScene::OnEnter()
	{
	}

	void PlayScene::OnExit()
	{
		
	}
}