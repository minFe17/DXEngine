#pragma once
#include "DXEngineComponent.h"

namespace DXEngine
{
	class Collider : public Component
	{
	public:
		Collider(Enum::EColliderType type);
		~Collider();

		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		UINT32 GetID() const { return id; }
		Vector2 GetOffset() const { return offset; }
		void SetOffset(Vector2 offset)  { this->offset = offset; }
		Vector2 GetSize() const { return size; }
		void SetSize(Vector2 size) { this->size = size; }
		Enum::EColliderType GetColliderType() const { return colliderType; }

	private:
		static UINT32 collisionID;
		UINT32 id;
		Vector2 offset;
		Vector2 size;
		Enum::EColliderType colliderType;
	};
}