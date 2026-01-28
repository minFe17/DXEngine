#pragma once
#include "DXEngineCollider.h"

namespace DXEngine
{
	class BoxCollider2D : public Collider
	{
	public:
		BoxCollider2D();
		~BoxCollider2D();

	private:
		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		Vector2 size;
	};
}