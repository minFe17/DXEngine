#pragma once
#pragma once
#include "..//Engine_SOURCE//DXEngineScene.h"

namespace DXEngine
{
	class EditorScene : public Scene
	{
	public:
		EditorScene();
		virtual ~EditorScene();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnEnter() override;
		void OnExit() override;

	private:
	};
}