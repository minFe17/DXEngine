#pragma once
#include "CommonInclude.h"

namespace DXEngine
{
	class GameObject2
	{
	public:
		GameObject2();
		~GameObject2();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

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