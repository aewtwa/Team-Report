#pragma once
#include "CommonInclude.h"
#include "yaEnums.h"
#include "yaCollider.h"


namespace ya
{	
	union ColliderId
	{
		struct
		{
			UINT left;
			UINT right;
		};
		UINT64 id;
	};

	class ColliderManager
	{
	public:
		static void Init();
		static void Update();
		static void Release();

		static void Clear();

		static void CollisionLayerCheck(enums::LAYER left, enums::LAYER right, bool enable);
		static void LayerCollision(class Scene* scene, enums::LAYER left, enums::LAYER right);
		static void ColliderCollision(Collider* left, Collider* right);
		static bool Intersect(Collider* left, Collider* right);

		static void MouseCollisionLayerCheck(enums::LAYER layer, bool enable) { mMouseLayerMap[(UINT)layer] = enable; }
		static void MouseLayerCollision(class Scene* scene, enums::LAYER layer);
		static void MouseIntersect(Collider* collider);

		static void SetRender(bool value) { render = value; }
		static bool GetRender() { return render; }

	private:
		static std::map<UINT64, bool> mCollisionMap;
		static std::bitset<(UINT)LAYER::End>  mMouseLayerMap;
		static std::bitset<(UINT)enums::LAYER::End> mLayerMatrix[(UINT)enums::LAYER::End];
		static bool render;
	};
}

