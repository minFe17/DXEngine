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
		HWND hWnd;
		HDC hdc;

		HDC backHdc;
		HBITMAP backBuffer;

		UINT width;
		UINT height;

		GameObject player;
		Time time;
	};
}