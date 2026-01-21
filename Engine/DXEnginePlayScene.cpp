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
		background = Object::Instantiate<Player>(Enum::ELayerType::Background, Vector2(100, 100));

		SpriteRenderer* spriteRenderer = background->AddComponent<SpriteRenderer>();
		Graphcis::Texture* texture = Resources::Find<Graphcis::Texture>(L"Background");
		spriteRenderer->SetTexture(texture);

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