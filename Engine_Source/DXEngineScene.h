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
		virtual void Destroy();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObject, Enum::ELayerType type);
		Layer* GetLayer(Enum::ELayerType type) { return layers[(UINT)type]; }

	private:
		std::vector<Layer*> layers;
	};
}