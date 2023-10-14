#pragma once
#include "yaEnums.h"
#include "yaEntity.h"
#include "yaLayer.h"

namespace ya
{
	using namespace ya::enums;

	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Setting();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Destroy();

		virtual void KillAllObj(LAYER layer)
		{
			std::vector<GameObject*> Gobjs = GetLayer((UINT)layer)->GetGameObjects();
			for (GameObject* obj : Gobjs)
			{
				ya::Destroy(obj);
			}
		}

		Layer* GetLayer(UINT index) { return &mLayers[index]; }
		void AddGameObject(GameObject* gameObject, UINT layerIndex);

		GameObject* GetPlayer() { return mLayers[(UINT)LAYER::Player].GetPlayer(); }

	private:
		Layer mLayers[(UINT)LAYER::End];
	};
}
