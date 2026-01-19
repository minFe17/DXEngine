#pragma once
#include "DXEngineEntity.h"
#include "CommonInclude.h"
#include "DXEngineGameObject.h"

namespace DXEngine
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);


	private:
		std::vector<GameObject*> gameObjects;
	};
}