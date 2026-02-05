#include "DXEngineCircleCollider2D.h"
#include "DXEngineTransform.h"
#include "DXEngineGameObject.h"
#include "DXEngineRenderer.h"

namespace DXEngine
{
	CircleCollider2D::CircleCollider2D() : Collider(Enum::EColliderType::Circle2D), radius(0.0f)
	{

	}

	CircleCollider2D::~CircleCollider2D()
	{

	}

	void CircleCollider2D::Init()
	{

	}

	void CircleCollider2D::Update()
	{

	}

	void CircleCollider2D::LateUpdate()
	{

	}

	void CircleCollider2D::Render()
	{
		Transform* transform = GetOwner()->GetComponent<Transform>();
		Vector2 pos = transform->GetPosition();
	}
}