#include "DXEngineCollider.h"
#include "DXEngineScript.h"
#include "DXEngineGameObject.h"

using namespace DXEngine::Enum;

namespace DXEngine
{
	UINT32 Collider::collisionID = 1;

	Collider::Collider(EColliderType type) : Component(Enum::EComponentType::Collider), id(collisionID++), size(Vector2::One)
	{

	}

	Collider::~Collider()
	{

	}

	void Collider::Init()
	{

	}

	void Collider::Update()
	{

	}

	void Collider::LateUpdate()
	{

	}

	void Collider::Render()
	{

	}

	void Collider::OnCollisionEnter(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionEnter(other);
	}

	void Collider::OnCollisionStay(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionStay(other);
	}

	void Collider::OnCollisionExit(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionExit(other);
	}
}