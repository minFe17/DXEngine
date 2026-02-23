#pragma once
#include "CommonInclude.h"
#include "DXEngineGameObject.h"
#include "DXEngineTime.h"
#include "DXEngineGraphicDevice_DX11.h"
#include "DXEngineEvent.h"
#include "DXEngineWindow.h"
#include "DXEngineApplicationEvent.h"
#include "DXEngineMouseEvent.h"
#include "DXEngineKeyEvent.h"

namespace DXEngine
{
	class Application
	{
	public:
		Application();
		~Application();
		void Init(HWND hwnd, int width, int height);
		void InitWindow(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
		void Present();
		void Release();
		void Destroy();

		void AdjustWindow(HWND hwnd, int width, int hewight);
		void ReszieGraphicDevice(WindowResizeEvent& e);
		void OnEvent(Event& e);
		void InitEtc();
		void Close();

		Window& GetWindow() { return window; }
		bool IsLoaded() const { return isLoad; }
		void IsLoaded(bool load) { isLoad = load; }
		bool IsRunning() const { return isRunning; }

	private:
		bool isLoad;
		bool isRunning;

		std::unique_ptr<Graphics::GraphicDevice_DX11> GraphicDevice;

		Window window;
	};
}