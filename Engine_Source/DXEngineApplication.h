#pragma once
#include "CommonInclude.h"
#include "DXEngineGameObject.h"
#include "DXEngineTime.h"
#include "DXEngineGraphicDevice_DX11.h"

namespace DXEngine
{
	class Application
	{
	public:
		Application();
		~Application();
		void Init(HWND hwnd, int width, int height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
		void Present();
		void Release();
		void Destroy();

		HWND GetHwnd() const { return hWnd; }
		HDC GetHdc() const { return hdc; }
		UINT GetWidth() const { return width; }
		UINT GetHeight() const { return height; }

		void AdjustWindow(int width, int hewight);
		void ReszieGraphicDevice(int width, int height);
		void InitEtc();
		void Close();

		bool IsLoaded() const { return isLoad; }
		void IsLoaded(bool load) { isLoad = load; }
		bool IsRunning() const { return isRunning; }

	private:
		bool isLoad;
		bool isRunning;
		std::unique_ptr<Graphics::GraphicDevice_DX11> GraphicDevice;

		HWND hWnd;
		HDC hdc;

		HDC backHdc;
		HBITMAP backBuffer;

		UINT width;
		UINT height;
	};
}