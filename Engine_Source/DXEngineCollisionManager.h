#pragma once
#include "CommonInclude.h"
#include "DXEngineCollider.h"

namespace DXEngine
{
	using namespace Enum;

	union CollisionID
	{
		struct
		{
			UINT32 left;
			UINT32 right;
		};

		UINT64 id;
	};

	class CollisionManager
	{
	public:
		static void Init();
		static void Update();
		static void LateUpdate();
		static void Render();
		static void Clear();

		static void CollisionLayerCheck(ELayerType left, ELayerType right, bool enable);
		static void LayerCollision(ELayerType left, ELayerType right);
		static void ColliderCollision(Collider* left, Collider* right);
		static bool Intersect(Collider* left, Collider* right);

	private:
		static std::bitset < (UINT)ELayerType::Max> collisionLayerMatrix[(UINT)ELayerType::Max];
		static std::unordered_map<UINT64, bool> collisionMap;

	};
}