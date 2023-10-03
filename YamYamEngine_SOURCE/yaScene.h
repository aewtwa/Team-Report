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
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Destroy();

		Layer* GetLayer(UINT index) { return &mLayers[index]; }
		void AddGameObject(GameObject* gameObject, UINT layerIndex);

		GameObject* GetPlayer() { return mLayers[LAYER::Player].GetPlayer(); }

	private:
		Layer mLayers[LAYER::End];
	};
}
