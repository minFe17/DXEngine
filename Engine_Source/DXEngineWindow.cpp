#include "DXEngineWindow.h"
#include "DXEngineApplicationEvent.h"
#include "DXEngineMouseEvent.h"

namespace DXEngine
{
	void Window::Init()
	{

	}

	void Window::SetWindowResize(UINT width, UINT height)
	{
		windowData.Width = width;
		windowData.Height = height;

		WindowResizeEvent event(width, height);

		if (windowData.EventCallback)
			windowData.EventCallback(event);
	}

	void Window::SetCursorPos(double x, double y)
	{
		MouseMovedEvent event(x, y);

		if (windowData.EventCallback)
			windowData.EventCallback(event);
	}
}