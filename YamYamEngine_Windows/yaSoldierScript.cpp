#include "yaSoldierScript.h"
#include "yaTransform.h"
#include "yaSceneManager.h"
#include "yaScene.h"
#include "yaTime.h"
#include "yaMonsterBullet.h"
#include "yaobject.h"

namespace ya
{
	SoldierScript::SoldierScript() :
		mTarget(nullptr)
		, shot_time(1.f)
		, speed(2.f)
		, round_attack_time(0.3f)
		, origin_pos(Vector3::Zero)
		, move_time(3.f)
		, is_left(true)
		, cur_state(SoldierState::Following)
		, directions{}
		, round_attack_count(0)
	{
		for (int i = 0; i < 8; i++)
		{
			directions[i] = Vector2(cos(XMConvertToRadians(i * 45)),sin(XMConvertToRadians(i * 45)));
		}
	}
	SoldierScript::~SoldierScript()
	{
	}
	void SoldierScript::Initialize()
	{
	}
	void SoldierScript::Update()
	{
		if (mTarget == nullptr)
			FindTarget();

		switch (cur_state)
		{
		case ya::SoldierState::Following:
			MoveToTarget();
			break;
		case ya::SoldierState::Attack:
			MoveAround();
			Shoot();
			break;
		case ya::SoldierState::RoundAttack:
			RoundShoot();
			break;
		default:
			break;
		}

	}

	void SoldierScript::LateUpdate()
	{
	}

	void SoldierScript::Render()
	{
	}

	void SoldierScript::FindTarget()
	{
		GameObject* player = SceneManager::GetActiveScene()->GetPlayer();
		if (player != nullptr)
		{
			mTarget = player;
			return;
		}
	}

	void SoldierScript::MoveToTarget()
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
			move_time = 3.f;
			cur_state = SoldierState::Attack;
			is_left = !is_left;
		}
	}
	void SoldierScript::Shoot()
	{
		Vector2 pPos = (Vector2)mTarget->GetComponent<Transform>()->GetPosition(); //player Position
		Vector3 mPos = GetOwner()->GetComponent<Transform>()->GetPosition(); //monster Position

		Vector2 dir = pPos - (Vector2)mPos;
		dir.normalize(); // 플레이어를 바라보는 방향 벡터

		MonsterBullet* monsterBullet = object::Instantiate<MonsterBullet>(LAYER::Bullet, mPos);
		monsterBullet->SetDir(dir);
		monsterBullet->SetColor(Vector3(255, 165, 0));
	}

	void SoldierScript::MoveAround()
	{
		Vector3 cur_pos = GetOwner()->GetComponent<Transform>()->GetPosition();
		shot_time -= Time::DeltaTime();

		if (is_left)
		{
			cur_pos.x -= 10.f * Time::DeltaTime();
		}
		if (!is_left)
		{
			cur_pos.x += 10.f * Time::DeltaTime();
		}
		
		GetOwner()->GetComponent<Transform>()->SetPosition(cur_pos);

		if (shot_time <= 0.f)
		{
			shot_time= 1.f;
			cur_state = SoldierState::RoundAttack;
		}
	}


	void SoldierScript::RoundShoot()
	{
		if (round_attack_time <= 0.f)
		{
			Vector3 cur_pos = GetOwner()->GetComponent<Transform>()->GetPosition();
			for (int i = 0; i < 8; i++)
			{
				MonsterBullet* monBullet = object::Instantiate<MonsterBullet>(LAYER::Bullet, cur_pos);
				monBullet->SetDir(directions[i]);
				monBullet->SetColor(Vector3(0xff,0x00,0xff));
			}
			round_attack_time = 0.3f;
			round_attack_count++;
		}

		else
		{
			round_attack_time -= Time::DeltaTime();
		}

		if (round_attack_count > 5)
		{
			round_attack_count = 0;
			cur_state = SoldierState::Following;
		}
	}
}