#pragma once
#include "CommonInclude.h"

namespace DXEngine
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

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