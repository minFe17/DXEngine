#pragma once
#include "CommonInclude.h"
#include "DXEngineGameObject.h"
#include "DXEngineTime.h"

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

	private:
		void AdjustWindow(UINT width, UINT hewight);
		void CreateBuffer();
		void ClearRenderTarget();
		void CopyRenderTarget(HDC source, HDC dest);
	private:
		HWND hWnd;
		HDC hdc;

		HDC backHdc;
		HBITMAP backBuffer;

		UINT width;
		UINT height;

		Time time;
	};
}