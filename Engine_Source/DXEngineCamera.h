#pragma once
#include "DXEngineComponent.h"

namespace DXEngine
{
	using namespace DXEngine::Math;
	class Camera : public Component
	{
	public:
		Vector2 CalculatePosition(Vector2 pos) const { return pos - distance; }

		Camera();
		~Camera();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void SetTarget(GameObject* target) { this->target = target; }

	private:
		class GameObject* target;
		Vector2 distance;
		Vector2 resolution;
		Vector2 lookPosition;
	};
}