#include "DXEngineApplication.h"
#include "DXEngineInput.h"
#include "DXEngineSceneManager.h"
#include "DXEngineResources.h"
#include <DXEngineCollisionManager.h>

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


		AdjustWindow(width, height);
		CreateBuffer();

		Input::Init();
		Time::Init();

		CollisionManager::Init();
		SceneManager::Init();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();

		Destroy();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();
		CollisionManager::Update();
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		CollisionManager::LateUpdate();
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		ClearRenderTarget();

		Time::Render(backHdc);
		CollisionManager::Render(backHdc);
		SceneManager::Render(backHdc);

		CopyRenderTarget(backHdc, hdc);
	}

	void Application::Release()
	{
		SceneManager::Release();
		Resources::Release();
	}

	void Application::Destroy()
	{
		SceneManager::Destroy();
	}

	void Application::AdjustWindow(UINT width, UINT height)
	{
		RECT rect = { 0,0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		this->width = rect.right - rect.left;
		this->height = rect.bottom - rect.top;

		SetWindowPos(hWnd, nullptr, 0, 0, width, height, 0);
		ShowWindow(hWnd, true);
	}

	void Application::CreateBuffer()
	{
		// 윈도우 해상도에 맞는 백버퍼 생성
		backBuffer = CreateCompatibleBitmap(hdc, width, height);

		// 백버퍼를 가르킬 DC 생성
		backHdc = CreateCompatibleDC(hdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(backHdc, backBuffer);
		DeleteObject(oldBitmap);
	}

	void Application::ClearRenderTarget()
	{
		HBRUSH brush = (HBRUSH)CreateSolidBrush(RGB(128, 128, 128));
		HBRUSH oldBrush = (HBRUSH)SelectObject(backHdc, brush);
		Rectangle(backHdc, -1, -1, 1601, 901);
	}

	void Application::CopyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, width, height, source, 0, 0, SRCCOPY);
	}
}