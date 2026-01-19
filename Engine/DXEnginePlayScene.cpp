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
		Player* player = new Player();
		Transform* transform = player->AddComponent<Transform>();
		transform->SetPosition(300, 400);
		transform->SetName(L"TR");

		SpriteRenderer* spriteRenderer = player->AddComponent<SpriteRenderer>();
		spriteRenderer->SetName(L"SR");

		AddGameObject(player);
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