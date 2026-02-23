#include "DXEngineWindow.h"
#include "DXEngineApplicationEvent.h"

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
}