#pragma once
#include "DXEngineEntity.h";
#include "DXEngineGameObject.h"

namespace DXEngine
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);

	private:
		std::vector<GameObject*> gameObjects;
	};
}