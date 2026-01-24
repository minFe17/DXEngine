#pragma once
#include "CommonInclude.h"
#include "DXEngineComponent.h"

namespace DXEngine
{
	using namespace Math;
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(Vector2 pos) { position.x = pos.x, position.y = pos.y; }
		Vector2 GetPosition() { return position; }
		float GetRotation() { return rotation; }
		Vector2 GetScale() { return scale; }
		void SetRotation(float rotate) { rotation = rotate; }
		void SetScale(Vector2 scale) { this->scale = scale; }

	private:
		Vector2 position;
		float rotation;
		Vector2 scale;
	};
}