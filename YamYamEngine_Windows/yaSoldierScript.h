#pragma once
#include "yaScript.h"

namespace ya
{
	enum class SoldierState 
	{
		Following,
		Attack,
		RoundAttack,
		SpecialAttack,
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
		void SpecialAttack();

	private:
		//따라 다닐 오브젝트
		GameObject* mTarget;

		//무브 phase 와 기본 슈팅 phase
		float shot_time;
		float move_time;
		bool is_left;
		Vector3 origin_pos;

		//8방향 쏘는 phase
		float round_attack_time;
		bool switch_attack;
		int round_attack_count;
		Vector2 directions[8];

		//스페셜 어택
		float special_attack_direction;
		Vector2 right_angles[4];
		float special_attack_time;

		//기본 status
		SoldierState cur_state;
		float speed;
	};

}
