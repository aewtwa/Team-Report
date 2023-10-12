#pragma once
#include "..\YamYamEngine_SOURCE\yaGameObject.h"

namespace ya
{
	class Bullet : public GameObject
	{
	public:
		Bullet();
		~Bullet() override;

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		virtual void SetDir(math::Vector2 dir) { mDirection = dir; }
		virtual void SetStartPos(Vector2 pos) { startPos = pos; }
		virtual void SetMaxDistance(Vector2 pos) { maxDistance = pos; }

		virtual float GetDamage() { return Damage; }
		virtual void SetDamage(float input) { Damage = input; }

	protected:
		Vector2 mDirection;
		Vector2 startPos;
		Vector2 maxDistance;

		float Damage;
	};
}
