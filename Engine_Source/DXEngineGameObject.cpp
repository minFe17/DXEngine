#include "DXEngineGameObject.h"
#include "DXEngineInput.h"

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
		if (Input::GetKey(EKeyCode::Left))
			xPos -= 0.01f;
		if (Input::GetKey(EKeyCode::Right))
			xPos += 0.01f;
		if (Input::GetKey(EKeyCode::Up))
			yPos -= 0.01f;
		if (Input::GetKey(EKeyCode::Down))
			yPos += 0.01f;
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