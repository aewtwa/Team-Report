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

		void Reset();
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

		void Heal() { HP++; }
		int GetHP() { return HP; }
		void Hit() { 
			if(HP > 0)
				HP -= 1;
		}

		void SetAdditionalFireRate(float fr) { Additional_Fire_Rate = fr; }
		float GetAdditionalFireRate() { return Additional_Fire_Rate; }

		void SetProjectile_Level(int level) { Projectile_Level = level; }
		int GetProjectile_Level() { return Projectile_Level; }

		void SetAdditionalDamage(float damage) { Additional_Damage = damage; }
		float GetAdditionalDamage() { return Additional_Damage; }

		bool GetIsDead() { return is_dead; }

		void SetScore(int input) { score = input; }
		int GetScore() { return score; }

	private:		
		ShootType	ShootType;

		int HP;
		float FireRate;
		float MoveSpeed;
		float Additional_Fire_Rate;
		int Projectile_Level;
		float Additional_Damage;
		int score;
		bool is_dead;


		Vector3 PlayerColor;


		class Text* text;
	};
}

