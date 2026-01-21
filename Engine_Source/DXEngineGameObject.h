#pragma once
#include "CommonInclude.h"
#include "DXEngineComponent.h"

namespace DXEngine
{
	class GameObject
	{
	public:
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
			components.push_back(component);

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

	private:
		void InitTransform();

	private:
		std::vector<Component*> components;
	};
}