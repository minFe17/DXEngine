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
		virtual void Render();
		virtual void EndOfFrame();

		void AddGameObject(GameObject* gameObject);
		void EraseGameObject(GameObject* eraseGameObj);
		std::vector<GameObject*>& GetGameObjects() { return gameObjects; }

	private:
		void FindDeadGameObjects(OUT std::vector<GameObject*>& findGameObjects);
		void DeleteGameObjects(std::vector<GameObject*> deleteObjects);
		void EraseDeadGameObject();

	private:
		std::vector<GameObject*> gameObjects;
	};

	using GameObjectIter = std::vector<GameObject*>::iterator;
}