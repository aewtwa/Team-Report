#pragma once
#include "yaScript.h"
#define KING_SPEED 2.0f
#define KING_MOVE_TIME 2.0f
#define KING_SHOT_TIME 5.0f
#define FIRST_ATTACK_TIME 5.0f
#define SECOND_ATTACK_TIME 3.0f
#define SECOND_ATTACK_COUNT 10
#define SECOND_ITER_TIME 0.3f

namespace ya
{
	enum class KingState
	{
		Following,
		RoundMoving,
		FirstAttack,
		SecondAttack,
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
		void ManualShoot(Vector2 dir, Vector3 color);
		void RoundShoot();
		void ShotgunShoot();
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

		//first attack
		int first_bullet_index;
		float first_attack_time;
		float first_attacak_degree;

		//second attack
		float second_attack_time;
		float second_iter_time;
		int second_attack_count;

		//현재 컬러 인덱스
		int cur_color_index;

		//컬러 팔레트
		Vector3 Color_Palette[3];


		//각도 저장용 변수
		float cur_degree;

		
	};

}
