#include "DXEngineInput.h"
#include "DXEngineApplication.h"

extern DXEngine::Application application;

namespace DXEngine
{
	std::vector<Input::Key> Input::keys = {};
	Math::Vector2 Input::mousePosition = Math::Vector2::One;

	int ASCII[(UINT)EKeyCode::Max] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		VK_LBUTTON, VK_MBUTTON, VK_RBUTTON,
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
		for (size_t i = 0; i < (UINT)EKeyCode::Max; i++)
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
		std::for_each(keys.begin(), keys.end(),
			[](Key& key) -> void
			{
				UpdateKey(key);
			});
	}

	void Input::UpdateKey(Input::Key& key)
	{
		if (GetFocus())
		{
			if (IsKeyDown(key.keyCode))
				UpdateKeyDown(key);
			else
				UpdateKeyUp(key);

			GetMousePositionByWindow();
		}
		else
			ClearKeys();
	}

	bool Input::IsKeyDown(EKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void Input::UpdateKeyDown(Key& key)
	{
		if (key.isPressed == true)
			key.state = EKeyState::Pressed;
		else
			key.state = EKeyState::Down;

		key.isPressed = true;
	}

	void Input::UpdateKeyUp(Key& key)
	{
		if (key.isPressed == true)
			key.state = EKeyState::Up;
		else
			key.state = EKeyState::None;

		key.isPressed = false;
	}

	void Input::GetMousePositionByWindow()
	{
		POINT mousePos = { };
		GetCursorPos(&mousePos);
		ScreenToClient(application.GetHwnd(), &mousePos);

		UINT width = application.GetWidth();
		UINT height = application.GetHeight();

		mousePosition.x = -1;
		mousePosition.y = -1;

		if((UINT)mousePos.x > 0 && (UINT)mousePos.x < width)
			mousePosition.x = (float)mousePos.x;
		if ((UINT)mousePos.y > 0 && (UINT)mousePos.y < height)
			mousePosition.y = (float)mousePos.y;
	}

	void Input::ClearKeys()
	{
		for (Key& key : keys)
		{
			if (key.state == EKeyState::Down || key.state == EKeyState::Pressed)
				key.state = EKeyState::Up;
			else if (key.state == EKeyState::Up)
				key.state = EKeyState::None;

			key.isPressed = false;
		}
	}
}