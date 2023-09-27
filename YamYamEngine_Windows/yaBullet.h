#pragma once
#include "..\YamYamEngine_SOURCE\yaGameObject.h"

namespace ya
{
	class Bullet : public GameObject
	{
	public:
		Bullet();
		~Bullet() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

	private:
		Vector2 mDirection;

	};
}
