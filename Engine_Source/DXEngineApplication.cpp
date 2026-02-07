#include "DXEngineApplication.h"
#include "DXEngineInput.h"
#include "DXEngineSceneManager.h"
#include "DXEngineResources.h"
#include "DXEngineRenderer.h"
#include "DXEngineCollisionManager.h"
#include "DXEngineUIManager.h"

namespace DXEngine
{
	Application::Application() : hWnd(nullptr), hdc(nullptr), width(0), height(0), backHdc(NULL), backBuffer(NULL), isLoad(false)
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
		InitEtc();

		GraphicDevice = std::make_unique<Graphics::GraphicDevice_DX11>();
		Renderer::Init();
		GraphicDevice->Init();

		Input::Init();
		Time::Init();

		CollisionManager::Init();
		UIManager::Init();
		SceneManager::Init();
	}

	void Application::Run()
	{
		if (isLoad == false)
			isLoad = true;

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
		UIManager::Update();
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		CollisionManager::LateUpdate();
		UIManager::LateUpdate();
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		Time::Render();
		CollisionManager::Render();
		UIManager::Render();
		SceneManager::Render();
	}

	void Application::Release()
	{
		SceneManager::Release();
		UIManager::Release();
		Resources::Release();
	}

	void Application::Destroy()
	{
		SceneManager::Destroy();
	}

	void Application::AdjustWindow(UINT width, UINT height)
	{
		RECT rect = { 0, 0, (LONG)width, (LONG)height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		this->width = rect.right - rect.left;
		this->height = rect.bottom - rect.top;

		SetWindowPos(hWnd, nullptr, 0, 0, width, height, 0);
		ShowWindow(hWnd, true);
	}

	void Application::InitEtc()
	{
	}
}