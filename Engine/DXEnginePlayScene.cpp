#include "DXEnginePlayScene.h"
#include "DXEngineGameObject.h"
#include "DXEnginePlayer.h"
#include "DXEngineTransform.h"
#include "DXEngineSpriteRenderer.h"

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
		Player* background = new Player();
		Transform* transform = background->AddComponent<Transform>();
		transform->SetPosition(Vector2(0, 0));

		transform->SetName(L"TR");

		SpriteRenderer* spriteRenderer = background->AddComponent<SpriteRenderer>();
		spriteRenderer->SetName(L"SR");
		spriteRenderer->ImageLoad(L"Resources/CloudOcean.png");

		AddGameObject(background);
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}