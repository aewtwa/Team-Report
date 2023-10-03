#pragma once
#include "yaEntity.h"
#include "yaGameObject.h"

namespace ya
{
	class Layer : public Entity
	{
	public:
		Layer();
		virtual ~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Destroy();

		void AddGameObject(GameObject*  gameObject);

		std::vector<GameObject*> GetGameObjects() { return mGameObjects; }

		GameObject* GetPlayer() {
			for (GameObject* obj : mGameObjects)
			{
				if (obj->GetTag() == TAG::Player)
					return obj;
			}

			return nullptr;
		}

	private:
		std::vector<GameObject*> mGameObjects;
	};
}
