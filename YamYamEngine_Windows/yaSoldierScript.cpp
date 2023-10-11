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
		, origin_pos(Vector3::Zero)
		, move_time(3.f)
		, is_left(true)
	{
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

		if (move_time >= 0.f)
		{
			shot_time = 1.f;
			move_time -= Time::DeltaTime();
			MoveToTarget();
		}
		else
		{
			shot_time -= Time::DeltaTime();
			MoveAround();
			Shoot();
		}
		if (shot_time <= 0.f)
		{
			is_left = !is_left;
			move_time = 3.f;
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
		if (is_left)
		{
			cur_pos.x -= 10.f * Time::DeltaTime();
		}
		if (!is_left)
		{
			cur_pos.x += 10.f * Time::DeltaTime();
		}
		
		GetOwner()->GetComponent<Transform>()->SetPosition(cur_pos);

	}
}