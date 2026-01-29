#include "DXEngineRigidbody.h"
#include "DXEngineTime.h"
#include "DXEngineTransform.h"
#include "DXEngineGameObject.h"

namespace DXEngine
{
	Rigidbody::Rigidbody() : Component(Enum::EComponentType::Rigidbody), isGround(false), mass(1), friction(10), force(Vector2::Zero), accelation(Vector2::Zero), velocity(Vector2(0.0f, 800.0f)), limitedVelocity(Vector2(200.0f, 1000.0f)), gravity(Vector2::Zero)
	{

	}

	Rigidbody::~Rigidbody()
	{

	}

	void Rigidbody::Init()
	{

	}

	void Rigidbody::Update()
	{
		accelation = force / mass;
		velocity += accelation * Time::DeltaTime();

		if (isGround)
		{
			Vector2 gravityValue = gravity;
			gravityValue.Normalize();
			float dot = Vector2::Dot(velocity, gravityValue);
			velocity -= gravity * dot;
		}
		else
			velocity += gravity * Time::DeltaTime();

		Vector2 gravityValue = gravity;
		gravityValue.Normalize();
		float dot = Vector2::Dot(velocity, gravityValue);
		gravity = gravity * dot;

		Vector2 sideVelocity = velocity - gravity;
		if (limitedVelocity.y < gravity.Length())
		{
			gravity.Normalize();
			gravity *= limitedVelocity.y;
		}
		if (limitedVelocity.x < sideVelocity.Length())
		{
			sideVelocity.Normalize();
			sideVelocity *= limitedVelocity.x;
		}

		velocity = gravity + sideVelocity;

		if (!(velocity == Vector2::Zero))
		{
			Vector2 frictionValue = -velocity;
			frictionValue = frictionValue.Normalize() * friction * mass * Time::DeltaTime();

			if (velocity.Length() <= frictionValue.Length())
				velocity = Vector2::Zero;
			else
				velocity += frictionValue;
		}

		Transform* transform = GetOwner()->GetComponent<Transform>();
		Vector2 position = transform->GetPosition();
		position = position + velocity * Time::DeltaTime();
		transform->SetPosition(position);

		force.Clear();
	}

	void Rigidbody::LateUpdate()
	{

	}

	void Rigidbody::Render(HDC hdc)
	{

	}
}