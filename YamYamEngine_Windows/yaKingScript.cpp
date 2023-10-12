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
		, cur_state(KingState::RoundMoving)
		, origin_pos(Vector3::Zero)
		, Color_Palette{}
		, cur_color_index(0)
		, cur_degree(0)
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
			//Shoot();
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
	void KingScript::MoveAround()
	{
		
	}
	void KingScript::RoundShoot()
	{
	}
	void KingScript::SpecialAttack()
	{
	}
	void KingScript::RoundMoving()
	{
		Vector3 cur_pos = origin_pos;
		round_distance += Time::DeltaTime();
		cur_degree += 100.f * Time::DeltaTime();

		if (cur_degree >= 360.f)
		{
			cur_degree = 0.f;
		}

		cur_pos.x += cos(XMConvertToRadians(cur_degree)) * round_distance;
		cur_pos.y += sin(XMConvertToRadians(cur_degree)) * round_distance;

		GetOwner()->GetComponent<Transform>()->SetPosition(cur_pos);
	}
}