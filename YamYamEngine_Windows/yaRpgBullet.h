#pragma once
#include "..\YamYamEngine_SOURCE\yaGameObject.h"

namespace ya
{
	class RpgBullet : public GameObject
	{
	public:
		RpgBullet();
		~RpgBullet() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

		void SetDir(math::Vector2 dir) { mDirection = dir; }
		void SetStartPos(Vector2 pos) { startPos = pos; }
		void SetMaxDistance(Vector2 pos) { maxDistance = pos; }

	private:
		Vector2 mDirection;
		Vector2 startPos;
		Vector2 maxDistance;
		Vector2 explode_directions[15];
	};
}
