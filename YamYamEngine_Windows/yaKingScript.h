#pragma once
#include "yaScript.h"
#define KING_SPEED 2.0f
#define KING_MOVE_TIME 2.0f
#define KING_SHOT_TIME 5.0f
#define KING_COLOR_CHANGE_TIME 1.0f

namespace ya
{
	enum class KingState
	{
		Following,
		RoundMoving,
		FirstAttack,
		SecondAttack,
		MapAttack,
		Freeze
	};


	class KingScript : public Script
	{
	public:
		KingScript();
		virtual ~KingScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void FindTarget();
		void MoveToTarget();
		void Shoot();
		void RoundShoot();
		void FirstAttack();
		void SecondAttack();
		void RoundMoving();

	private:
		//���� �ٴ� ������Ʈ
		GameObject* mTarget;

		//���� phase �� �⺻ ���� phase
		float shot_time;
		float move_time;
		Vector3 origin_pos;

		//�⺻ status
		KingState cur_state;
		float speed;

		//���׶��� ���� phase
		float round_distance;
		bool is_left;



		//���� �÷� �ε���
		int cur_color_index;

		//�÷� �ȷ�Ʈ
		Vector3 Color_Palette[3];

		//���� �ð����� �÷� �ٲ�� �ֵ��� �����ϴ� ����
		float color_change_time;

		//���� ����� ����
		float cur_degree;
	};

}
