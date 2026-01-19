#pragma once
#include "..\\Engine_Source\DXEngineGameObject.h"

namespace DXEngine
{
	class Player : public GameObject
	{
	public:
		void Init();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);
	};
}