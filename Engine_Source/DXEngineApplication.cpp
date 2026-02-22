#include "DXEngineApplication.h"
#include "DXEngineInput.h"
#include "DXEngineSceneManager.h"
#include "DXEngineResources.h"
#include "DXEngineCollisionManager.h"
#include "DXEngineUIManager.h"
#include "DXEngineRenderer.h"

namespace DXEngine
{
	Application::Application() : hWnd(nullptr), windowWidth(0), windowHeight(0), width(0), height(0), x(0), y(0), isLoad(false), isRunning(false)
	{

	}

	Application::~Application()
	{

	}

	void Application::Init(HWND hwnd, int width, int height)
	{
		hWnd = hwnd;

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

	void Application::InitWindow(HWND hwnd)
	{
		SetWindowPos(hwnd, nullptr, x, y, windowWidth, windowHeight, 0);
		ShowWindow(hwnd, SW_SHOWDEFAULT);
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
		GetDevice()->ClearRenderTargetView();
		GetDevice()->ClearDepthStencilView();
		GetDevice()->BindViewPort();
		GetDevice()->BindDefaultRenderTarget();

		Time::Render();
		CollisionManager::Render();
		UIManager::Render();
		SceneManager::Render();

		//copy back buffer
		Microsoft::WRL::ComPtr<ID3D11Texture2D> src = GetDevice()->GetFrameBuffer();
		Microsoft::WRL::ComPtr<ID3D11Texture2D> dst = Renderer::FrameBuffer->GetAttachmentTexture(0)->GetTexture();

		GetDevice()->CopyResource(dst.Get(), src.Get());
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

		RECT winRect;
		::GetWindowRect(hWnd, &winRect);

		//window position
		x = winRect.left;
		y = winRect.top;

		// window size
		windowWidth = rect.right - rect.left;
		windowHeight = rect.bottom - rect.top;

		this->width = width;
		this->height = height;

		InitWindow(hWnd);
	}

	void Application::ReszieGraphicDevice(int width, int height)
	{
		if (GraphicDevice == nullptr)
			return;

		RECT winRect;
		::GetClientRect(hWnd, &winRect);
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
		Renderer::FrameBuffer->Resize(this->width, this->height);
	}

	void Application::InitEtc()
	{
	}

	void Application::Close()
	{
		isRunning = false;
	}
}