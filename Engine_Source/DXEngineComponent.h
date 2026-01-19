#pragma once
#include "DXEngineEntity.h"

namespace DXEngine
{
	class GameObject;
	class Component : public Entity
	{
	public:
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* gameObject) { owner = gameObject; }
		GameObject* GetOwner() { return owner; }

	private:
		GameObject* owner;
	};
}