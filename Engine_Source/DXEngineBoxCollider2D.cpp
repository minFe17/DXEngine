#include "DXEngineBoxCollider2D.h"
#include "DXEngineTransform.h"
#include "DXEngineGameObject.h"

namespace DXEngine
{
	BoxCollider2D::BoxCollider2D() : Collider(Enum::EColliderType::Rect2D)
	{

	}

	BoxCollider2D::~BoxCollider2D()
	{

	}

	void BoxCollider2D::Init()
	{

	}

	void BoxCollider2D::Update()
	{

	}

	void BoxCollider2D::LateUpdate()
	{

	}

	void BoxCollider2D::Render(const Matrix& view, const Matrix& projection)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 position = tr->GetPosition();
	}
}