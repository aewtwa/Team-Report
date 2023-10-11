#pragma once
#include "yaScript.h"

namespace ya
{
	enum class SoldierState 
	{
		Following,
		Attack,
		RoundAttack,

	};


	class SoldierScript : public Script
	{
	public:
		SoldierScript();
		virtual ~SoldierScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void FindTarget();
		void MoveToTarget();
		void Shoot();
		void MoveAround();
		void RoundShoot();

	private:
		GameObject* mTarget;
		float shot_time;
		float move_time;
		float round_attack_time;
		float speed;
		bool is_left;
		int round_attack_count;
		SoldierState cur_state;
		Vector3 origin_pos;
		Vector2 directions[8];
	};

}
