#pragma once
#include "DXEngineEvent.h"

namespace DXEngine
{
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(const float x, const float y) : mouseX(x), mouseY(y) 
		{
		}

		float GetX() const { return mouseX; }
		float GetY() const { return mouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << mouseX << ", " << mouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float mouseX, mouseY;
	};

	// To do - add more events
	// mouse button pressed
	// mouse button released
	// mouse scrolled
	// ...
}