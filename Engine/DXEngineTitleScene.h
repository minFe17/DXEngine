#pragma once
#include "..\\Engine_Source\DXEngineScene.h"

namespace DXEngine
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}