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
		//���� �ٴ� ������Ʈ
		GameObject* mTarget;

		//���� phase �� �⺻ ���� phase
		float shot_time;
		float move_time;
		bool is_left;
		Vector3 origin_pos;

		//8���� ��� phase
		float round_attack_time;
		bool switch_attack;
		int round_attack_count;
		Vector2 directions[8];

		//����� ����
		float special_attack_direction;
		Vector2 right_angles[4];
		float special_attack_time;

		//�⺻ status
		SoldierState cur_state;
		float speed;
	};

}
