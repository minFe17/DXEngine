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
		Object::DontDestroyOnLoad(background);
		SpriteRenderer* spriteRenderer = background->AddComponent<SpriteRenderer>();
		spriteRenderer->SetSprite(Resources::Find<Graphics::Texture>(L"Player"));
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
	}

	void PlayScene::OnEnter()
	{
		Scene::OnEnter();
	}

	void PlayScene::OnExit()
	{

	}
}