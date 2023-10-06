#include "yaColliderManager.h"
#include "yaSceneManager.h"

namespace ya
{
	std::map<UINT64, bool>  ColliderManager::mCollisionMap = {};
	std::bitset<(UINT)LAYER::End>  ColliderManager::mLayerMatrix[(UINT)LAYER::End] = {};
	bool ColliderManager::render = false;

	void ColliderManager::Init()
	{
	}
	void ColliderManager::Update()
	{
		Scene* curScene = SceneManager::GetActiveScene();

		for (int row = 0; row < (int)LAYER::End; row++)
		{
			for (int column = 0; column < (int)LAYER::End; column++)
			{
				if (mLayerMatrix[row][column] == true)
				{
					LayerCollision(curScene, (LAYER)row, (LAYER)column);
				}
			}
		}
	}
	void ColliderManager::Release()
	{
	}
	void ColliderManager::Clear()
	{
		mLayerMatrix->reset();
		mCollisionMap.clear();
	}

	void ColliderManager::CollisionLayerCheck(LAYER left, LAYER right, bool enable)
	{
		int row = -1;
		int col = -1;

		if (left > right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}

		mLayerMatrix[row][col] = enable;
	}

	void ColliderManager::LayerCollision(Scene* scene, LAYER left, LAYER right)
	{
		Layer* leftLayer = scene->GetLayer((UINT)left);
		std::vector<GameObject*> leftGobjs = leftLayer->GetGameObjects();

		Layer* rightLayer = scene->GetLayer((UINT)right);
		std::vector<GameObject*> rightGobjs = rightLayer->GetGameObjects();

		for (GameObject* leftObj : leftGobjs)
		{
			for (GameObject* rightObj : rightGobjs)
			{
				Collider* leftCol = leftObj->GetCollider();
				Collider* rightCol = rightObj->GetCollider();

				if (leftCol == nullptr || rightCol == nullptr)
					continue;
				if (leftObj == rightObj)
					continue;

				ColliderCollision(leftCol, rightCol);
			}
		}
	}

	void ColliderManager::ColliderCollision(Collider* left, Collider* right)
	{
		ColliderId id = {};

		if ((UINT)left < (UINT)right)
		{
			id.left = (UINT)left;
			id.right = (UINT)right;
		}
		else
		{
			id.left = (UINT)right;
			id.right = (UINT)left;
		}

		std::map<UINT64, bool>::iterator iter = mCollisionMap.find(id.id);

		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		if (Intersect(left, right))
		{
			if (iter->second == true)
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
				iter->second = true;
			}
			else
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
		}
		else
		{
			if (iter->second == true)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);
			}

			iter->second = false;
		}
	}

	bool ColliderManager::Intersect(Collider* left, Collider* right)
	{
		math::Vector2 leftPos = (math::Vector2)dynamic_cast<Collider*>(left)->GetPos();
		math::Vector2 leftSize = dynamic_cast<Collider*>(left)->GetSize();

		math::Vector2 rightPos = (math::Vector2)dynamic_cast<Collider*>(right)->GetPos();
		math::Vector2 rightSize = dynamic_cast<Collider*>(right)->GetSize();

		if ((fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.f + rightSize.x / 2.f))
			&& (fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.f + rightSize.y / 2.f)))
		{
			return true;
		}

		return false;
	}
}