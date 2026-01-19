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

	private:
		Vector2 position;
	};
}