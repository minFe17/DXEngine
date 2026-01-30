#include "DXEngineUIButton.h"
#include "DXEngineInput.h"

namespace DXEngine
{
	UIButton::UIButton() : UIBase(EUIType::Button)
	{

	}

	UIButton::~UIButton()
	{
	}

	void UIButton::OnInit()
	{
		SetPosition(Vector2(200.0f, 200.0f));
		SetSize(Vector2(200.0f, 200.0f));

		onClick = std::bind(&UIButton::ButtonClick, this);
	}

	void UIButton::OnActive()
	{
	}

	void UIButton::OnInActive()
	{
	}

	void UIButton::OnUpdate()
	{
		Vector2 mousePosition = Input::GetMousePosition();

		if (position.x <= mousePosition.x && mousePosition.x <= position.x + size.x && position.y <= mousePosition.y && mousePosition.y <= position.y + size.y)
			isMouseOn = true;
		else
			isMouseOn = false;

		if (Input::GetKeyDown(EKeyCode::LButton))
		{
			if (isMouseOn)
				onClick();
		}
	}

	void UIButton::OnLateUpdate()
	{
	}

	void UIButton::OnRender(HDC hdc)
	{
		Rectangle(hdc, (int)position.x, (int)position.y, position.x + size.x, position.y + size.y);
	}

	void UIButton::OnClear()
	{

	}

	void UIButton::ButtonClick()
	{
		int a = 0;
	}

}