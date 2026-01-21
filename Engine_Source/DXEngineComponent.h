#pragma once
#include "DXEngineEntity.h"

namespace DXEngine
{
	class GameObject;
	class Component : public Entity
	{
	public:
		Component(Enum::EComponentType type);
		~Component();

		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* gameObject) { owner = gameObject; }
		GameObject* GetOwner() { return owner; }
		Enum::EComponentType GetType() { return type; }

	private:
		GameObject* owner;
		Enum::EComponentType type;
	};
}