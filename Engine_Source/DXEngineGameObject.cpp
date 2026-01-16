#include "DXEngineGameObject.h"
#include "DXEngineInput.h"
#include "DXEngineTime.h"

namespace DXEngine
{
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		const int speed = 100;

		if (Input::GetKey(EKeyCode::Left))
			xPos -= speed * Time::DeltaTime();
		if (Input::GetKey(EKeyCode::Right))
			xPos += speed * Time::DeltaTime();
		if (Input::GetKey(EKeyCode::Up))
			yPos -= speed * Time::DeltaTime();
		if (Input::GetKey(EKeyCode::Down))
			yPos += speed * Time::DeltaTime();
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Rectangle(hdc, 100 + xPos, 100 + yPos, 200 + xPos, 200 + yPos);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
	}
}