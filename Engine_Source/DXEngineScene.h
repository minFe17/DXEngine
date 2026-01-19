#pragma once
#include "DXEngineEntity.h";
#include "DXEngineGameObject.h"
#include "DXEngineLayer.h"

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

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObject, ELayerType type);

	private:
		std::vector<Layer*> layers;
	};
}