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
		void OnRender() override;
		void OnClear() override;

		virtual void ButtonClick();

	private:
		Graphics::Texture* texture;
		Event onClick;
	};
}