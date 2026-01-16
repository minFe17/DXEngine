#include "DXEngineInput.h"

namespace DXEngine
{
	std::vector<Input::Key> Input::keys = {};

	static const int KeyMap[(int)EKeyCode::Max] =
	{
		'Q','W','E','R','T','Y','U','I','O','P',
		'A','S','D','F','G','H','J','K','L',
		'Z','X','C','V','B','N','M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void Input::Init()
	{
		CreateKeys();
	}

	void Input::Update()
	{
		UpdateKeys();
	}

	void Input::CreateKeys()
	{
		for (int i = 0; i < (UINT)EKeyCode::Max; i++)
		{
			Key key = {};
			key.isPressed = false;
			key.state = EKeyState::None;
			key.keyCode = (EKeyCode)i;

			keys.push_back(key);
		}
	}

	void Input::UpdateKeys()
	{
		for (int i = 0; i < keys.size(); i++)
		{
			if (GetAsyncKeyState(KeyMap[i]) & 0x8000)
			{
				if (keys[i].isPressed == true)
					keys[i].state = EKeyState::Pressed;
				else
					keys[i].state = EKeyState::Down;

				keys[i].isPressed = true;
			}
			else
			{
				if (keys[i].isPressed == true)
					keys[i].state = EKeyState::Up;
				else
					keys[i].state = EKeyState::None;

				keys[i].isPressed = false;
			}
		}
	}
}