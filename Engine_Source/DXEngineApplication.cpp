#include "DXEngineApplication.h"
#include "DXEngineInput.h"

namespace DXEngine
{
	Application::Application() : hWnd(nullptr), hdc(nullptr)
	{

	}

	Application::~Application()
	{

	}

	void Application::Init(HWND hwnd)
	{
		hWnd = hwnd;
		hdc = GetDC(hwnd);

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
		time.Render(hdc);
		player.Render(hdc);
	}
}