#include "DXEnginePlayerScript.h"
#include <DXEngineInput.h>
#include <DXEngineGameObject.h>
#include <DXEngineTransform.h>
#include <DXEngineTime.h>
#include "DXEngineSpriteRenderer.h"
#include "DXEngineObject.h"
#include "DXEngineTexture.h"

namespace DXEngine
{
	PlayerScript::PlayerScript()
	{

	}

	PlayerScript::~PlayerScript()
	{

	}

	void PlayerScript::Init()
	{

	}

	void PlayerScript::Update()
	{
		static Vector3 postions = Vector3(-1, 1, 0);

		if (Input::GetKeyDown(EKeyCode::N))
		{
			projTile = Object::Instantiate<ProjectTile>(Enum::ELayerType::Background, postions);
			SpriteRenderer* sr = projTile->AddComponent<SpriteRenderer>();
			sr->SetSprite(Resources::Find<Graphics::Texture>(L"Player"));
			postions.x += 1.0f;
		}

		if (Input::GetKeyDown(EKeyCode::D))
		{
			Object::Destroy(projTile);
			projTile = nullptr;
		}
	}

	void PlayerScript::LateUpdate()
	{

	}

	void PlayerScript::Render(const Matrix& view, const Matrix& projection)
	{
		
	}
}