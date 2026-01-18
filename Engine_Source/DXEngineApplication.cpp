#include "DXEngineApplication.h"
#include "DXEngineInput.h"

namespace DXEngine
{
	Application::Application() : hWnd(nullptr), hdc(nullptr), width(0), height(0), backHdc(NULL), backBuffer(NULL)
	{

	}

	Application::~Application()
	{

	}

	void Application::Init(HWND hwnd, UINT width, UINT height)
	{
		hWnd = hwnd;
		hdc = GetDC(hwnd);

		RECT rect = {0,0, width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		this->width = rect.right - rect.left;
		this->height = rect.bottom - rect.top;

		SetWindowPos(hWnd, nullptr, 0, 0, width, height, 0);
		ShowWindow(hWnd, true);

		// 윈도우 해상도에 맞는 백버퍼 생성
		backBuffer = CreateCompatibleBitmap(hdc, width, height);

		// 백버퍼를 가르킬 DC 생성
		backHdc = CreateCompatibleDC(hdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(backHdc, backBuffer);
		DeleteObject(oldBitmap);

		player.SetPosition(0, 0);

		Input::Init();
		Time::Init();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		player.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		Rectangle(backHdc, 0, 0, 1600, 900);

		time.Render(backHdc);
		player.Render(backHdc);

		// BackBuffer에 있는걸 원본 Buffer에 복사(그려준다)
		BitBlt(hdc, 0, 0, width, height, backHdc, 0, 0, SRCCOPY);
	}
}