#pragma once
#include "DXEngineCamera.h"
#include "DXEngineRenderTarget.h"

namespace DXEngine
{
	class EditorCamera : public Camera
	{
	public:
		EditorCamera();
		virtual ~EditorCamera();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(const Matrix& view, const Matrix& projection) override;
		void OnEvent(Event& e);

	private:
		Graphics::RenderTarget* renderTarget;
	};
}