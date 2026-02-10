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
		
	}

	void Rigidbody::LateUpdate()
	{

	}

	void Rigidbody::Render()
	{

	}
}