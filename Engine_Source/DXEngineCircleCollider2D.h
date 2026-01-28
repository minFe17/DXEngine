#pragma once
#include "DXEngineCollider.h"

namespace DXEngine
{
	class CircleCollider2D : public Collider
	{
	public:
		CircleCollider2D();
		~CircleCollider2D();

	private:
		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		float radius;
	};
}