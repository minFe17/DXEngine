#pragma once
#include "CommonInclude.h"
#include "DXEngineEvent.h"

namespace DXEngine
{
	struct WindowProps
	{
		std::wstring Title;
		UINT Width;
		UINT Height;
		HWND Hwnd;

		WindowProps(const std::wstring& title = L"YamYam Engine", UINT width = 1600, UINT height = 900) : Title(title), Width(1600), Height(900), Hwnd(NULL)
		{
		}
	};

	class Window
	{
	public:
		struct WindowData
		{
			std::string Title;
			HWND Hwnd;

			//client
			unsigned int Width;
			unsigned int Height;
			// window size
			unsigned int WindowWidth;
			unsigned int WindowHeight;

			// window position
			unsigned int X;
			unsigned int Y;

			bool VSync;
			EventCallbackFn EventCallback;
		};

		void Init();
		void SetWindowResize(UINT width, UINT height);

		void SetEventCallBack(const EventCallbackFn& callback) { windowData.EventCallback = callback; }

		HWND GetHwnd() { return windowData.Hwnd; }
		void SetHwnd(HWND hwnd) { windowData.Hwnd = hwnd; }
		UINT GetWidth() { return windowData.Width; }
		void SetWidth(UINT width) { windowData.Width = width; }
		UINT GetHeight() { return windowData.Height; }
		void SetHeight(UINT height) { windowData.Height = height; }

		UINT GetWindowWidth() { return windowData.WindowWidth; }
		void SetWindowWidth(UINT width) { windowData.WindowWidth = width; }
		UINT GetWindowHeight() { return windowData.WindowHeight; }
		void SetWindowHeight(UINT height) { windowData.WindowHeight = height; }

		UINT GetXPos() { return windowData.X; }
		UINT GetYPos() { return windowData.Y; }
		void SetPos(UINT x, UINT y) { windowData.X = x; windowData.Y = y; }

	private:
		WindowData windowData;
	};
}