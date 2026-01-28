#pragma once
#include "CommonInclude.h"
#include "DXEngineComponent.h"

namespace DXEngine
{
	class GameObject
	{
	public:
		enum class EStateType
		{
			Active,
			Paused,
			Dead,
			Max,
		};
		GameObject();
		~GameObject();

		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* component = new T();
			component->Init();
			component->SetOwner(this);

			components[(UINT)component->GetType()] = component;

			return component;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (size_t i = 0; i < components.size(); i++)
			{
				component = dynamic_cast<T*>(components[i]);
				if (component)
					break;
			}

			return component;
		}

		EStateType GetActive() { return stateType; }
		bool IsActive() { return stateType == EStateType::Active; }

		void SetActive(bool power)
		{
			if (power)
				stateType = EStateType::Active;
			else
				stateType = EStateType::Paused;
		}

		void Death() { stateType = EStateType::Dead; }

	private:
		void InitTransform();

	private:
		EStateType stateType;
		std::vector<Component*> components;
	};
}