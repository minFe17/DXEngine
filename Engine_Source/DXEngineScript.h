#pragma once
#include "DXEngineComponent.h"

namespace DXEngine
{
	class Script : public Component
	{
	public:
		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}