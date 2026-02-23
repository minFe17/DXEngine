#pragma once
#include "DXEngineEntity.h";
#include "DXEngineGameObject.h"
#include "DXEngineLayer.h"
#include "DXEngineCamera.h"

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
		virtual void Render();
		virtual void EndOfFrame();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObject, Enum::ELayerType type);
		void EraseGameObject(GameObject* gameObject);
		void AddCamera(Camera* camera);
		void RemoveCamera(Camera* camera);
		void CollectRenderables(std::vector<GameObject*>& opaqueList, std::vector<GameObject*>& cutoutList, std::vector<GameObject*>& transparentList) const;
		void SortByDistance(std::vector<GameObject*>& renderList, const Vector3& cameraPos, bool bAscending) const;
		void RenderRenderables(const std::vector<GameObject*>& renderList, const Matrix& view, const Matrix& projection) const;

		Layer* GetLayer(Enum::ELayerType type) { return layers[(UINT)type]; }

	private:
		void CreateLayers();

		std::vector<Layer*> layers;
		std::vector<Camera*> cameras;
	};
}