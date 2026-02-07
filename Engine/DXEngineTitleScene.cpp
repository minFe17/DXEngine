#include "DXEngineTitleScene.h"
#include "DXEngineInput.h"
#include "DXEngineSceneManager.h"

namespace DXEngine
{
	TitleScene::TitleScene()
	{
	}

	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Init()
	{
		Scene::Init();
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input::GetKeyDown(EKeyCode::N))
			SceneManager::LoadScene(L"PlayScene");
	}

	void TitleScene::Render()
	{
	}

	void TitleScene::OnEnter()
	{
	}

	void TitleScene::OnExit()
	{
	}
}