#pragma once
#include "DXEngineEvent.h"
#include "DXEngineInput.h"

namespace DXEngine
{
	class KeyEvent : public Event
	{
	public:
		EKeyCode GetKeyCode() const { return keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(const EKeyCode keycode) : keyCode(keycode) {}
		EKeyCode keyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const EKeyCode keycode, bool isRepeat = false) : KeyEvent(keycode), isRepeat(isRepeat) {}
		bool IsRepeat() const { return isRepeat; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << static_cast<int>(keyCode) << " (repeat = " << isRepeat << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		bool isRepeat;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const EKeyCode keycode) : KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << static_cast<int>(keyCode);
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const EKeyCode keycode) : KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << static_cast<int>(keyCode);
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}