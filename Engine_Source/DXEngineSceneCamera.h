#pragma once
#include "DXEngineCamera.h"

namespace DXEngine
{
	class SceneCamera : public Camera
	{
	public:
		SceneCamera();
		virtual ~SceneCamera();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(const Matrix& view, const Matrix& projection) override;
		void OnEvent(Event& e);

	private:

	};
}