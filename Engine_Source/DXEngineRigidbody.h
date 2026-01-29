#pragma once
#include "DXEngineComponent.h"


namespace DXEngine
{
	class Rigidbody : public Component
	{
	public:
		Rigidbody();
		~Rigidbody();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetMass(float massValue) { mass = massValue; }
		void AddForce(Vector2 forceValue) { force = forceValue; }
		void SetIsGround(bool value) { isGround = value; }
		void SetVelocity(Vector2 velocityValue) { velocity = velocityValue; }
		Vector2 GetVelocity() { return velocity; }

	private:
		bool isGround;
		float mass;
		float friction;

		Vector2 force;
		Vector2 accelation;
		Vector2 velocity;
		Vector2 limitedVelocity;
		Vector2 gravity;
	};
}