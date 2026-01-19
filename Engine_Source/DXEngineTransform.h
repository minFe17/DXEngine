#pragma once
#include "CommonInclude.h"
#include "DXEngineComponent.h"

namespace DXEngine
{
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(float x, float y)
		{
			xPos = x;
			yPos = y;
		}

		float GetPositionX() { return xPos; }
		float GetPositionY() { return yPos; }

	private:
		float xPos;
		float yPos;
	};
}