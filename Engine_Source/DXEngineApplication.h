#pragma once
#include "CommonInclude.h"
#include "DXEngineGameObject.h"

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

		GameObject player;
	};
}