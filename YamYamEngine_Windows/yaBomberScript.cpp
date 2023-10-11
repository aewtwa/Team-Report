#include "yaBomberScript.h"
#include "yaTransform.h"
#include "yaSceneManager.h"
#include "yaScene.h"
#include "yaTime.h"
#include "yaMonsterBullet.h"
#include "yaobject.h"

namespace ya
{
	BomberScript::BomberScript() :
		  mTarget(nullptr)
		, speed(6.f)
		, explode_time(2.0f)
		, ownObj(nullptr)
	{
		for (int i = 0; i < 30; i++)
		{
			directions[i] = Vector2(cos(XMConvertToRadians(12 * i)), sin(XMConvertToRadians(12 * i)));
		}
	}
	BomberScript::~BomberScript()
	{
	}
	void BomberScript::Initialize()
	{
		ownObj = GetOwner();
	}
	void BomberScript::Update()
	{
		explode_time -= Time::DeltaTime();
		if (explode_time <= 0.f)
		{
			Explode();
			Destroy(ownObj);
		}
		if (mTarget == nullptr)
			FindTarget();
		else
			MoveToTarget();
	}
	void BomberScript::LateUpdate()
	{
	}
	void BomberScript::Render()
	{
	}
	void BomberScript::FindTarget()
	{
		GameObject* player = SceneManager::GetActiveScene()->GetPlayer();
		if (player != nullptr)
		{
			mTarget = player;
			return;
		}
	}
	void BomberScript::MoveToTarget()
	{
		Vector2 pPos = (Vector2)mTarget->GetComponent<Transform>()->GetPosition(); //player Position
		Vector2 mPos = (Vector2)GetOwner()->GetComponent<Transform>()->GetPosition(); //monster Position

		Vector2 dir = pPos - mPos;
		dir.normalize();

		mPos += dir * speed * Time::DeltaTime();
		GetOwner()->GetComponent<Transform>()->SetPosition((Vector3)mPos);
	}
	void BomberScript::Explode()
	{
		Vector3 cur_pos = ownObj->GetComponent<Transform>()->GetPosition();
		for (int i = 0; i < 30; i++)
		{
			MonsterBullet* monBullet = object::Instantiate<MonsterBullet>(LAYER::Bullet,cur_pos);
			monBullet->SetDir(directions[i]);
			monBullet->SetStartPos((Vector2)cur_pos);
			monBullet->SetMaxDistance((Vector2)(5.f));
		}
	}
}