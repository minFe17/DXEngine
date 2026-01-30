#pragma once
#include "DXEngineUIBase.h"
#include "DXEngineTexture.h"

namespace DXEngine
{
	class UIButton : public UIBase
	{
	public:
		UIButton();
		~UIButton();

		void OnInit() override;
		void OnActive() override;
		void OnInActive() override;
		void OnUpdate() override;
		void OnLateUpdate() override;
		void OnRender(HDC hdc) override;
		void OnClear() override;

		virtual void ButtonClick();

	private:
		Graphcis::Texture* texture;
		Event onClick;
	};
}