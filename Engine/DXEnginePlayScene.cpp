#include "DXEnginePlayScene.h"
#include "DXEngineGameObject.h"

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
		GameObject* gameobject = new GameObject();
		AddGameObject(gameobject);

		gameobject->SetPosition(0, 0);
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