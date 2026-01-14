#include "DXEngineGameObject2.h"

namespace DXEngine
{
	DXEngine::GameObject2::GameObject2()
	{

	}

	DXEngine::GameObject2::~GameObject2()
	{

	}

	void DXEngine::GameObject2::Update()
	{
		if (GetAsyncKeyState('A') & 0x8000)
			xPos -= 0.01f;
		if (GetAsyncKeyState('D') & 0x8000)
			xPos += 0.01f;
		if (GetAsyncKeyState('W') & 0x8000)
			yPos -= 0.01f;
		if (GetAsyncKeyState('S') & 0x8000)
			yPos += 0.01f;
	}

	void DXEngine::GameObject2::LateUpdate()
	{

	}

	void DXEngine::GameObject2::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Ellipse(hdc, 400 + xPos, 400 + yPos, 500 + xPos, 500 + yPos);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
	}
}