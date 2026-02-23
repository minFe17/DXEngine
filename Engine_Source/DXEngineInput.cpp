#include "DXEngineInput.h"
#include "DXEngineApplication.h"

extern DXEngine::Application application;

namespace DXEngine
{
	std::vector<Input::Key> Input::keys = {};
	Math::Vector2 Input::mousePosition = Math::Vector2::One;

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
		for (int vk = 0; vk <= 0xFF; ++vk)
		{
			EKeyCode keyCode = static_cast<EKeyCode>(vk);

			Key key = {};
			key.IsPressed = false;
			key.State = EKeyState::None;
			key.KeyCode = keyCode;
			key.VK_KeyCode = vk;

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
			if (IsKeyDown(key.KeyCode))
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
		return GetAsyncKeyState(static_cast<int>(code)) & 0x8000;
	}

	void Input::UpdateKeyDown(Key& key)
	{
		if (key.IsPressed == true)
			key.State = EKeyState::Pressed;
		else
			key.State = EKeyState::Down;

		key.IsPressed = true;
	}

	void Input::UpdateKeyUp(Key& key)
	{
		if (key.IsPressed == true)
			key.State = EKeyState::Up;
		else
			key.State = EKeyState::None;

		key.IsPressed = false;
	}

	void Input::GetMousePositionByWindow()
	{
		POINT mousePos = { };
		GetCursorPos(&mousePos);
		ScreenToClient(application.GetWindow().GetHwnd(), &mousePos);

		UINT width = application.GetWindow().GetWidth();
		UINT height = application.GetWindow().GetHeight();

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
			if (key.State == EKeyState::Down || key.State == EKeyState::Pressed)
				key.State = EKeyState::Up;
			else if (key.State == EKeyState::Up)
				key.State = EKeyState::None;

			key.IsPressed = false;
		}
	}
}