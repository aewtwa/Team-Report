#include "yaKingScript.h"
#include "yaTransform.h"
#include "yaSceneManager.h"
#include "yaScene.h"
#include "yaTime.h"
#include "yaMonsterBullet.h"
#include "yaobject.h"


namespace ya
{
	KingScript::KingScript() :
		  mTarget(nullptr)
		, shot_time(KING_SHOT_TIME)
		, move_time(KING_MOVE_TIME)
		, speed(KING_SPEED)
		, color_change_time(KING_COLOR_CHANGE_TIME)
		, cur_state(KingState::Following)
		, origin_pos(Vector3::Zero)
		, Color_Palette{}
		, cur_color_index(0)
		, cur_degree(0)
		, is_left(false)
	{
		Color_Palette[0] = Vector3(0, 255, 0);
		Color_Palette[1] = Vector3(255, 165, 0);
		Color_Palette[2] = Vector3(255, 0, 255);
	}
	KingScript::~KingScript()
	{
	}
	void KingScript::Initialize()
	{
	}
	void KingScript::Update()
	{
		if (mTarget == nullptr)
			FindTarget();

		switch (cur_state)
		{
		case ya::KingState::Following:
			MoveToTarget();
			break;
		case ya::KingState::RoundMoving:
			RoundMoving();
			RoundShoot();
			break;
		case ya::KingState::FirstAttack:
			Shoot();
			break;
		case ya::KingState::SecondAttack:
			Shoot();
			break;
		case ya::KingState::MapAttack:
			Shoot();
			break;
		case ya::KingState::Freeze:
			break;
		}

	}
	void KingScript::LateUpdate()
	{
	}
	void KingScript::Render()
	{
	}
	void KingScript::FindTarget()
	{
		GameObject* player = SceneManager::GetActiveScene()->GetPlayer();
		if (player != nullptr)
		{
			mTarget = player;
			return;
		}
	}
	void KingScript::MoveToTarget()
	{
		Vector2 pPos = (Vector2)mTarget->GetComponent<Transform>()->GetPosition(); //player Position
		Vector2 mPos = (Vector2)GetOwner()->GetComponent<Transform>()->GetPosition(); //monster Position

		Vector2 dir = pPos - mPos;
		dir.normalize();

		mPos += dir * speed * Time::DeltaTime();
		GetOwner()->GetComponent<Transform>()->SetPosition((Vector3)mPos);
		origin_pos = GetOwner()->GetComponent<Transform>()->GetPosition();

		move_time -= Time::DeltaTime();

		if (move_time <= 0.f)
		{
			move_time = KING_MOVE_TIME;
			cur_state = KingState::RoundMoving;
			cur_degree = XMConvertToDegrees(atan2(dir.y, dir.x));
		}


	}

	void KingScript::Shoot()
	{
		Vector2 pPos = (Vector2)mTarget->GetComponent<Transform>()->GetPosition(); //player Position
		Vector3 mPos = GetOwner()->GetComponent<Transform>()->GetPosition(); //monster Position

		Vector2 dir = pPos - (Vector2)mPos;
		dir.normalize(); // 플레이어를 바라보는 방향 벡터

		MonsterBullet* monsterBullet = object::Instantiate<MonsterBullet>(LAYER::Bullet, mPos);
		monsterBullet->SetDir(dir);


	}



	void KingScript::RoundShoot()
	{
		Vector2 pPos = (Vector2)mTarget->GetComponent<Transform>()->GetPosition(); //player Position
		Vector3 mPos = GetOwner()->GetComponent<Transform>()->GetPosition(); //monster Position

		Vector2 dir = pPos - (Vector2)mPos;
		dir.normalize(); // 플레이어를 바라보는 방향 벡터

		MonsterBullet* monsterBullet = object::Instantiate<MonsterBullet>(LAYER::Bullet, mPos);
		monsterBullet->SetDir(dir);
		is_left ? monsterBullet->SetColor(Color_Palette[2]) : monsterBullet->SetColor(Color_Palette[1]);
	}


	void KingScript::FirstAttack()
	{
		cur_degree = 0;
		for (int i = 0; i < 4; i++)
		{

			cur_degree += i * 90;
		}
	}

	void KingScript::SecondAttack()
	{

	}

	void KingScript::RoundMoving()
	{
		Vector3 pPos = mTarget->GetComponent<Transform>()->GetPosition();
		Vector3 mPos = GetOwner()->GetComponent<Transform>()->GetPosition(); //monster Position

		/*round_distance = 3.f * Time::DeltaTime();*/
		round_distance = sqrt(pow(abs(pPos.x - mPos.x) , 2) + pow(abs(pPos.y - mPos.y),2));

		move_time -= Time::DeltaTime();


		mPos.x = pPos.x + cos(XMConvertToRadians(cur_degree)) * round_distance;
		mPos.y = pPos.y + sin(XMConvertToRadians(cur_degree)) * round_distance;


		if (cur_degree >= 360.f)
		{
			cur_degree = 0.f;
		}
		if (cur_degree <= 0.f)
		{
			cur_degree = 360.f;
		}

		GetOwner()->GetComponent<Transform>()->SetPosition(mPos);

		is_left ? cur_degree += 120.f * Time::DeltaTime() : cur_degree -= 120.f * Time::DeltaTime();

		if (move_time <= 0.f)
		{
			move_time = KING_MOVE_TIME;
			cur_state = KingState::Following;
			round_distance = 0.f;
			cur_degree = 0.f;
			is_left = !is_left;
		}
	}
}