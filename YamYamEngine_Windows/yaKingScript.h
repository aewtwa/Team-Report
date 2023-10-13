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
		//따라 다닐 오브젝트
		GameObject* mTarget;

		//무브 phase 와 기본 슈팅 phase
		float shot_time;
		float move_time;
		Vector3 origin_pos;

		//기본 status
		KingState cur_state;
		float speed;

		//동그랗게 도는 phase
		float round_distance;
		bool is_left;



		//현재 컬러 인덱스
		int cur_color_index;

		//컬러 팔레트
		Vector3 Color_Palette[3];

		//일정 시간마다 컬러 바뀔수 있도록 통제하는 변수
		float color_change_time;

		//각도 저장용 변수
		float cur_degree;
	};

}
