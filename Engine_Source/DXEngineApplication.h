#pragma once
#include "CommonInclude.h"

namespace DXEngine
{
	class Application
	{
	public:
		Application();
		~Application();
		void Init(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
	private:
		HWND hWnd;
		HDC hdc;

		float xPos;
		float yPos;
	};
}