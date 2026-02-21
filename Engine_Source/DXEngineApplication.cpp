#include "DXEngineApplication.h"
#include "DXEngineInput.h"
#include "DXEngineSceneManager.h"
#include "DXEngineResources.h"
#include "DXEngineCollisionManager.h"
#include "DXEngineUIManager.h"
#include "DXEngineRenderer.h"

namespace DXEngine
{
	Application::Application() : hWnd(nullptr), hdc(nullptr), width(0), height(0), backHdc(NULL), backBuffer(NULL), isLoad(false), isRunning(false)
	{

	}

	Application::~Application()
	{

	}

	void Application::Init(HWND hwnd, int width, int height)
	{
		hWnd = hwnd;
		hdc = GetDC(hwnd);

		AdjustWindow(width, height);
		InitEtc();

		GraphicDevice = std::make_unique<Graphics::GraphicDevice_DX11>();
		GraphicDevice->Init();
		Renderer::Init();

		Input::Init();
		Time::Init();

		CollisionManager::Init();
		UIManager::Init();
		SceneManager::Init();

		isRunning = true;
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
		Graphics::GetDevice()->ClearRenderTargetView();
		Graphics::GetDevice()->ClearDepthStencilView();
		Graphics::GetDevice()->BindViewPort();
		Graphics::GetDevice()->BindDefaultRenderTarget();

		Time::Render();
		CollisionManager::Render();
		UIManager::Render();
		SceneManager::Render();

	}

	void Application::Present()
	{
		Graphics::GetDevice()->Present();
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

	void Application::AdjustWindow(int width, int height)
	{
		RECT rect = { 0, 0, (LONG)width, (LONG)height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
		GetWindowRect(hWnd, &rect); // 현재 윈도우의 좌표와 크기를 가져옴

		int x = rect.left;
		int y = rect.top;

		this->width = rect.right - rect.left;
		this->height = rect.bottom - rect.top;

		SetWindowPos(hWnd, nullptr, x, y, width, height, 0);
		ShowWindow(hWnd, true);
	}

	void Application::ReszieGraphicDevice(int width, int height)
	{
		if (GraphicDevice == nullptr)
			return;

		RECT winRect;
		GetClientRect(hWnd, &winRect);
		D3D11_VIEWPORT viewport = {};
		viewport.TopLeftX = 0.0f;
		viewport.TopLeftY = 0.0f;
		viewport.Width = static_cast<float>(winRect.right - winRect.left);
		viewport.Height = static_cast<float>(winRect.bottom - winRect.top);
		viewport.MinDepth = 0.0f;
		viewport.MaxDepth = 1.0f;

		this->width = width;
		this->height = height;

		GraphicDevice->Resize(viewport);
	}

	void Application::InitEtc()
	{
	}

	void Application::Close()
	{
		isRunning = false;
	}
}