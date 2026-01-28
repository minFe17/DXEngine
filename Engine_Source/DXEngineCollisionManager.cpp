#include "DXEngineCollisionManager.h"
#include "DXEngineScene.h"
#include "DXEngineSceneManager.h"
#include "DXEngineGameObject.h"
#include "DXEngineTransform.h"

namespace DXEngine
{
	std::bitset < (UINT)ELayerType::Max> CollisionManager::collisionLayerMatrix[(UINT)ELayerType::Max] = {};
	std::unordered_map<UINT64, bool> CollisionManager::collisionMap = {};


	void CollisionManager::Init()
	{

	}

	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();
		for (UINT row = 0; row < (UINT)ELayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)ELayerType::Max; col++)
			{
				if (collisionLayerMatrix[row][col])
				{
					LayerCollision(scene, (ELayerType)row, (ELayerType)col);
				}
			}
		}
	}

	void CollisionManager::LateUpdate()
	{

	}

	void CollisionManager::Render(HDC hdc)
	{

	}

	void CollisionManager::CollisionLayerCheck(ELayerType left, ELayerType right, bool enable)
	{
		int row = 0;
		int col = 0;

		if (left <= right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}

		collisionLayerMatrix[row][col] = enable;
	}

	void CollisionManager::LayerCollision(Scene* scene, ELayerType left, ELayerType right)
	{
		const std::vector<GameObject*>& lefts = scene->GetLayer(left)->GetGameObjects();
		const std::vector<GameObject*>& rights = scene->GetLayer(right)->GetGameObjects();

		for (GameObject* leftGameObject : lefts)
		{
			if (leftGameObject->IsActive() == false)
				continue;

			Collider* leftCollider = leftGameObject->GetComponent<Collider>();
			if (leftCollider == nullptr)
				continue;

			for (GameObject* rightGameObject : rights)
			{
				if (leftGameObject == rightGameObject)
					continue;
				if (rightGameObject->IsActive() == false)
					continue;

				Collider* rightCollider = rightGameObject->GetComponent<Collider>();
				if (rightCollider == nullptr)
					continue;

				ColliderCollision(leftCollider, rightCollider);
			}
		}
	}

	void CollisionManager::ColliderCollision(Collider* left, Collider* right)
	{
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		auto iter = collisionMap.find(id.id);
		if (iter == collisionMap.end())
		{
			collisionMap.insert(std::make_pair(id.id, false));
			iter = collisionMap.find(id.id);
		}

		if (Intersect(left, right))
		{
			if (iter->second == false)
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			else
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			if (iter->second == true)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);
				iter->second = false;
			}
		}
	}

	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Transform* leftTransform = left->GetOwner()->GetComponent<Transform>();
		Transform* rightTransform = right->GetOwner()->GetComponent<Transform>();

		Vector2 leftPosition = leftTransform->GetPosition() + left->GetOffset();
		Vector2 rightPosition = rightTransform->GetPosition() + right->GetOffset();

		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 rightSize = right->GetSize() * 100.0f;

		// AABB Ãæµ¹
		Enum::EColliderType leftType = left->GetColliderType();
		Enum::EColliderType rightType = right->GetColliderType();

		if (leftType == Enum::EColliderType::Rect2D && rightType == Enum::EColliderType::Rect2D)
		{
			// rect - rect
			if (fabs(leftPosition.x - rightPosition.x) < fabs(leftSize.x / 2) + fabs(rightSize.x / 2)
				&& fabs(leftPosition.y - rightPosition.y) < fabs(leftSize.y / 2 + rightSize.y / 2))
			{
				return true;
			}
		}
		
		if (leftType == Enum::EColliderType::Circle2D && rightType == Enum::EColliderType::Circle2D)
		{
			// circle - circle
			Vector2 leftCirclePosition = leftPosition + (leftSize / 2.0f);
			Vector2 rightCirclePosition = rightPosition + (rightSize / 2.0f);

			float distance = (leftCirclePosition - rightCirclePosition).Length();
			if (distance <= (leftSize.x / 2.0f + rightSize.x / 2.0f))
				return true;
		}
		
		return false;
	}
}