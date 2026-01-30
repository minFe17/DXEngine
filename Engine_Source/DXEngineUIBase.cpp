#include "DXEngineUIBase.h"

namespace DXEngine
{
	UIBase::UIBase(EUIType type) : uiType(type), isMouseOn(false)
	{
	}

	UIBase::~UIBase()
	{
	}

	void UIBase::Init()
	{
		OnInit();
	}

	void UIBase::Active()
	{
		isEnabled = true;
		OnActive();
	}

	void UIBase::InActive()
	{
		isEnabled = false;
		OnInActive();
	}

	void UIBase::Update()
	{
		if (isEnabled)
			OnUpdate();
	}

	void UIBase::LateUpdate()
	{
		if (isEnabled)
			OnLateUpdate();
	}

	void UIBase::Render(HDC hdc)
	{
		if (isEnabled)
			OnRender(hdc);
	}

	void UIBase::UIClear()
	{
		OnClear();
	}

	void UIBase::OnInit()
	{
	}

	void UIBase::OnActive()
	{
	}

	void UIBase::OnInActive()
	{
	}

	void UIBase::OnUpdate()
	{
	}

	void UIBase::OnLateUpdate()
	{
	}

	void UIBase::OnRender(HDC hdc)
	{
	}

	void UIBase::OnClear()
	{
	}
}