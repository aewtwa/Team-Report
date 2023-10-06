#pragma once
#include "yaGameObject.h"

namespace ya
{
	class ShotgunBullet : public GameObject
	{
	public:
		ShotgunBullet();
		~ShotgunBullet() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

		void SetDir(math::Vector2 dir) { mDirection = dir; }

		void SetPlayerPos(Vector2 pos) { PlayerPos = pos; }

	private:
		Vector2 mDirection;
		Vector2 PlayerPos;
	};
}
