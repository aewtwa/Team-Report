#include "yaZombieScript.h"
#include "yaTransform.h"
#include "yaSceneManager.h"
#include "yaScene.h"
#include "yaTime.h"
#include "yaMonsterBullet.h"
#include "yaobject.h"


namespace ya
{
	ZombieScript::ZombieScript() :
		  mTarget(nullptr)
		, speed(2.f)
		, shot_time(1.5f)
	{
	}
	ZombieScript::~ZombieScript()
	{
	}
	void ZombieScript::Initialize()
	{
	}
	void ZombieScript::Update()
	{
		shot_time -= Time::DeltaTime();
		if (shot_time <= 0.f)
		{
			Shoot();
			shot_time = 1.5f;
		}
		if (mTarget == nullptr)
			FindTarget();
		else
			MoveToTarget();
	}
	void ZombieScript::LateUpdate()
	{
	}
	void ZombieScript::Render()
	{
	}
	void ZombieScript::FindTarget()
	{
		GameObject* player = SceneManager::GetActiveScene()->GetPlayer();
		if (player != nullptr)
		{
			mTarget = player;
			return;
		}
	}
	void ZombieScript::MoveToTarget()
	{
		Vector2 pPos = (Vector2)mTarget->GetComponent<Transform>()->GetPosition(); //player Position
		Vector2 mPos = (Vector2)GetOwner()->GetComponent<Transform>()->GetPosition(); //monster Position

		Vector2 dir = pPos - mPos;
		dir.normalize();

		mPos += dir * speed * Time::DeltaTime();
		GetOwner()->GetComponent<Transform>()->SetPosition((Vector3)mPos);
	}

	void ZombieScript::Shoot()
	{
		Vector2 pPos = (Vector2)mTarget->GetComponent<Transform>()->GetPosition(); //player Position
		Vector3 mPos = GetOwner()->GetComponent<Transform>()->GetPosition(); //monster Position

		Vector2 dir = pPos - (Vector2)mPos;
		dir.normalize(); // 플레이어를 바라보는 방향 벡터

		MonsterBullet* monsterBullet = object::Instantiate<MonsterBullet>(LAYER::Bullet, mPos);
		monsterBullet->SetDir(dir);
		monsterBullet->SetColor(Vector3(255, 165, 0));

	}
}