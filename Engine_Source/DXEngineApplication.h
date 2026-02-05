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
		void Init(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
		void Release();
		void Destroy();

		HWND GetHwnd() const { return hWnd; }
		HDC GetHdc() const { return hdc; }
		UINT GetWidth() const { return width; }
		UINT GetHeight() const { return height; }

	private:
		void AdjustWindow(UINT width, UINT hewight);
		void CreateBuffer();
		void ClearRenderTarget();
		void CopyRenderTarget(HDC source, HDC dest);
	private:
		std::unique_ptr<Graphics::GraphicDevice_DX11> GraphicDevice;

		HWND hWnd;
		HDC hdc;

		HDC backHdc;
		HBITMAP backBuffer;

		UINT width;
		UINT height;
	};
}