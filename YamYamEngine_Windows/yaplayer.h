#pragma once
#include "yaGameObject.h"

namespace ya
{
	class player : public GameObject
	{
	public:
		enum class ShootType
		{
			basic,
			shotgun,
			rpg
		};

		player();
		~player() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

		ShootType GetShootType() { return ShootType; }
		void SetShootType(ShootType input) { ShootType = input; }

		float GetFireRate() { return FireRate; }
		void SetFireRate(float fr) { FireRate = fr; }

		float GetMoveSpeed() { return MoveSpeed; }
		void SetMoveSpeed(float speed) { MoveSpeed = speed; }

		Vector3 GetPlayerColor() { return PlayerColor; }
		void SetPlayerColor(Vector3 input) { PlayerColor = input; }

	private:		
		ShootType	ShootType;

		int HP;
		float FireRate;
		float MoveSpeed;

		Vector3 PlayerColor;
	};
}

