#pragma once
#include "yaGameObject.h"

namespace ya
{
	class MonsterBullet : public GameObject
	{
	public:
		MonsterBullet();
		~MonsterBullet() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

		void SetDir(math::Vector2 dir) { mDirection = dir; }

	private:
		Vector2 mDirection;
	};
}

