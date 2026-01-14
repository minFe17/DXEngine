#include "DXEngineGameObject.h"

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
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			xPos -= 0.01f;
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			xPos += 0.01f;
		if (GetAsyncKeyState(VK_UP) & 0x8000)
			yPos -= 0.01f;
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
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