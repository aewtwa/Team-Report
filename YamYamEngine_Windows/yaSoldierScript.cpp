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
		, switch_attack(false)
		, special_attack_direction(0.f)
		, right_angles{}
		, special_attack_time(1.5f)
	{
		for (int i = 0; i < 8; i++)
		{
			directions[i] = Vector2(cos(XMConvertToRadians(i * 45)),sin(XMConvertToRadians(i * 45)));
		}
		for (int i = 0; i < 4; i++)
		{
			right_angles[i] = Vector2(cos(XMConvertToRadians(i * 90)), sin(XMConvertToRadians(i * 90)));
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
		case ya::SoldierState::SpecialAttack:
			SpecialAttack();
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
		
		is_left ? monsterBullet->SetColor(Vector3(255, 165, 0)) : monsterBullet->SetColor(Vector3(0xff, 0x00, 0xff));
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
				if (switch_attack)
				{
					monBullet->SetColor(Vector3(0xff, 0x00, 0xff));
				}
				else
				{
					monBullet->SetColor(Vector3(255, 165, 00));
				}
			}
			round_attack_time = 0.3f;
			switch_attack = !switch_attack;
			round_attack_count++;
		}

		else
		{
			round_attack_time -= Time::DeltaTime();
		}

		if (round_attack_count > 5)
		{
			round_attack_count = 0;
			cur_state = SoldierState::SpecialAttack;
		}
	}
	void SoldierScript::SpecialAttack()
	{
		bool is_facing_down = false;
		
		if (special_attack_time >= 0.f)
		{
			Vector3 cur_pos = GetOwner()->GetComponent<Transform>()->GetPosition();
			Vector3 player_pos = mTarget->GetComponent<Transform>()->GetPosition();
			cur_pos.y - player_pos.y > 0.f ? is_facing_down = true : is_facing_down = false;

			is_facing_down ? special_attack_direction -= 3.f * Time::DeltaTime() : special_attack_direction += 3.f * Time::DeltaTime();
			for (int i = 0; i < 4; i++)
			{
				MonsterBullet* monBullet = object::Instantiate<MonsterBullet>(LAYER::Bullet, cur_pos);
				Vector2 cur_dir = right_angles[i];
				cur_dir.x += special_attack_direction;
				cur_dir.y += special_attack_direction;
				cur_dir = cur_dir.normalize();
				monBullet->SetDir(cur_dir);
				special_attack_time >= 0.7f ? monBullet->SetColor(Vector3(255,165,0)) : monBullet->SetColor(Vector3(0xff, 0x00, 0xff));
			}
			special_attack_time -= Time::DeltaTime();
		}
		else
		{
			special_attack_time = 1.5f;
			special_attack_direction = 0.f;
			cur_state = SoldierState::Following;
		}

	}
}