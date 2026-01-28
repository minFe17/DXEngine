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
		virtual void Destroy();

		void AddGameObject(GameObject* gameObject);
		const std::vector<GameObject*> GetGameObjects() { return gameObjects; }


	private:
		std::vector<GameObject*> gameObjects;
	};

	typedef std::vector<GameObject*>::iterator GameObjectIter;
}