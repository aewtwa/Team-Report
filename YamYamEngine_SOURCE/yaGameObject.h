#pragma once
#include "yaEntity.h"
#include "yaComponent.h"
#include "yaScript.h"
#include "yaCollider.h"


namespace ya
{
	class GameObject : public Entity
	{
	public:
		enum eState
		{
			Active,
			Paused,
			Dead,
			End
		};

		friend static __forceinline void Destroy(GameObject* gameObject);

		GameObject();
		virtual ~GameObject();

		template <typename T>
		T* AddComponent()
		{
			T* component = new T();
			Component* comp = dynamic_cast<Component*>(component);
			if (comp)
			{
				int myOrder = comp->GetUpdateOrder();
				mComponents[myOrder] = comp;
				mComponents[myOrder]->mOwner = this;
			}

			Script* script = dynamic_cast<Script*>(component);
			if (script != nullptr)
			{
				mScripts.push_back(script);
				script->SetOwner(this);
			}

			return component;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component;
			for (auto c : mComponents)
			{
				component = dynamic_cast<T*>(c);

				if (component != nullptr)
					return component;
			}

			return nullptr;
		}

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		eState GetState() { return mState; }
		void Pause() { mState = eState::Paused; }

		virtual Collider* GetCollider() {
			for (Component* comp : mComponents)
			{
				if (comp != nullptr 
					&& COMPONENTTYPE(comp->GetUpdateOrder()) == COMPONENTTYPE::COLLIDER)
					return dynamic_cast<Collider*>(comp);
			}

			return nullptr;
		}

		virtual enums::TAG GetTag() { return mTag; }
		virtual void SetTag(enums::TAG tag) { mTag = tag; }

	private:
		void death() { mState = eState::Dead; }

	private:
		eState mState;
		std::vector<Component*> mComponents;
		std::vector<Script*> mScripts;

		enums::TAG mTag;
	};

	static __forceinline void Destroy(GameObject* gameObject)
	{
		gameObject->death();
	}
}
