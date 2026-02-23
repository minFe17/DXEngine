#include "DXEngineApplication.h"
#include "DXEngineInput.h"
#include "DXEngineSceneManager.h"
#include "DXEngineResources.h"
#include "DXEngineCollisionManager.h"
#include "DXEngineUIManager.h"
#include "DXEngineRenderer.h"

namespace DXEngine
{
	Application::Application() : isLoad(false), isRunning(false)
	{
		window.SetEventCallBack(DXENGINE_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::Init(HWND hwnd, int width, int height)
	{
		window.SetHwnd(hwnd);
		AdjustWindow(hwnd, width, height);
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
		SetWindowPos(hwnd, nullptr, window.GetXPos(), window.GetYPos(), window.GetWindowWidth(), window.GetWindowHeight(), 0);
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

	void Application::AdjustWindow(HWND hwnd, int width, int height)
	{
		RECT rect = { 0, 0, (LONG)width, (LONG)height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		RECT winRect;
		::GetWindowRect(window.GetHwnd(), &winRect);

		//window position
		window.SetPos(winRect.left, winRect.top);

		// window size
		window.SetWindowWidth(rect.right - rect.left);
		window.SetWindowHeight(rect.bottom - rect.top);

		window.SetWidth(width);
		window.SetHeight(height);

		InitWindow(hwnd);
	}

	void Application::ReszieGraphicDevice(WindowResizeEvent& e)
	{
		if (GraphicDevice == nullptr)
			return;

		D3D11_VIEWPORT viewport = {};
		viewport.TopLeftX = 0.0f;
		viewport.TopLeftY = 0.0f;
		viewport.Width = static_cast<float>(e.GetWidth());
		viewport.Height = static_cast<float>(e.GetHeight());
		viewport.MinDepth = 0.0f;
		viewport.MaxDepth = 1.0f;

		window.SetWidth(viewport.Width);
		window.SetHeight(viewport.Height);

		GraphicDevice->Resize(viewport);
		Renderer::FrameBuffer->Resize(viewport.Width, viewport.Height);
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowResizeEvent>([this](WindowResizeEvent& e) -> bool
			{
				ReszieGraphicDevice(e);
				return true;
			});
	}

	void Application::InitEtc()
	{
	}

	void Application::Close()
	{
		isRunning = false;
	}
}