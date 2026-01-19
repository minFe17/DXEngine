#include "DXEnginePlayScene.h"
#include "DXEngineGameObject.h"
#include "DXEnginePlayer.h"
#include "DXEngineTransform.h"
#include "DXEngineSpriteRenderer.h"
#include "DXEngineInput.h"
#include "DXEngineSceneManager.h"

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
		background = new Player();
		Transform* transform = background->AddComponent<Transform>();
		transform->SetPosition(Vector2(0, 0));

		transform->SetName(L"TR");

		SpriteRenderer* spriteRenderer = background->AddComponent<SpriteRenderer>();
		spriteRenderer->SetName(L"SR");
		spriteRenderer->ImageLoad(L"Resources/CloudOcean.png");

		AddGameObject(background, ELayerType::Background);
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

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t text[50] = L"Play Scene";
		TextOut(hdc, 0, 0, text, 10);
	}

	void PlayScene::OnEnter()
	{
	}

	void PlayScene::OnExit()
	{
		
	}
}