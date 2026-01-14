#include "DXEngineApplication.h"

namespace DXEngine
{
	Application::Application() : hWnd(nullptr), hdc(nullptr), xPos(0), yPos(0)
	{

	}

	Application::~Application()
	{

	}

	void Application::Init(HWND hwnd)
	{
		hWnd = hwnd;
		hdc = GetDC(hwnd);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
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

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Rectangle(hdc, 100 + xPos, 100 + yPos, 200 + xPos, 200+ yPos);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
	}
}