#include "DXEngineGameObject.h"
#include "DXEngineInput.h"
#include "DXEngineTime.h"
#include "DXEngineCameraScript.h"

namespace DXEngine
{
	CameraScript::CameraScript()
	{
	}

	CameraScript::~CameraScript()
	{
	}

	void CameraScript::Init()
	{
	}

	void CameraScript::Update()
	{
		Transform* transform = GetOwner()->GetComponent<Transform>();

		Vector3 position = transform->GetPosition();

		if (Input::GetKey(EKeyCode::A))
			position += 20.0f * -transform->Right() * Time::DeltaTime();
		if (Input::GetKey(EKeyCode::W))
			position += 20.0f * transform->Foward() * Time::DeltaTime();
		if (Input::GetKey(EKeyCode::D))
			position += 20.0f * transform->Right() * Time::DeltaTime();
		if (Input::GetKey(EKeyCode::S))
			position += 20.0f * -transform->Foward() * Time::DeltaTime();
		if (Input::GetKey(EKeyCode::E))
			position += 20.0f * transform->Up() * Time::DeltaTime();
		if (Input::GetKey(EKeyCode::Q))
			position += 20.0f * -transform->Up() * Time::DeltaTime();

		transform->SetPosition(position);
	}

	void CameraScript::LateUpdate()
	{
	}

	void CameraScript::Render()
	{
	}
}