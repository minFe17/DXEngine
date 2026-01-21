#include "DXEnginePlayerScript.h"
#include <DXEngineInput.h>
#include <DXEngineGameObject.h>
#include <DXEngineTransform.h>
#include <DXEngineTime.h>

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
		if (Input::GetKey(EKeyCode::Right))
		{
			Transform* transform = GetOwner()->GetComponent<Transform>();
			Vector2 pos = transform->GetPosition();
			pos.x += 100.0f * Time::DeltaTime();
			transform->SetPosition(pos);
		}
		if (Input::GetKey(EKeyCode::Left))
		{
			Transform* transform = GetOwner()->GetComponent<Transform>();
			Vector2 pos = transform->GetPosition();
			pos.x -= 100.0f * Time::DeltaTime();
			transform->SetPosition(pos);
		}
	}

	void PlayerScript::LateUpdate()
	{

	}

	void PlayerScript::Render(HDC hdc)
	{

	}


}