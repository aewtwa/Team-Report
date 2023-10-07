#pragma once
#include "yaComponent.h"
#include "yaEnums.h"
#include "yaEntity.h"
#include "yaMath.h"
#include "yaCollider.h"

namespace ya
{
	class GameObject;
	class Script : public Entity
	{
	public:
		friend GameObject;

		Script();
		virtual ~Script();

		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void LateUpdate() = 0;
		virtual void Render() = 0;

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		GameObject* GetOwner() { return mOwner; }
		void SetOwner(GameObject* obj) { mOwner = obj; }

		bool GetActivate() { return isActivate; }
		void SetActivate(bool value) { isActivate = value; }

	private:
		GameObject* mOwner;

		bool isActivate;
	};
}

