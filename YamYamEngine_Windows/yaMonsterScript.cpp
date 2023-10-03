#include "yaMonsterScript.h"
#include "yaTransform.h"
#include "yaSceneManager.h"
#include "yaScene.h"
#include "yaTime.h"

namespace ya
{
	MonsterScript::MonsterScript()
		: mTarget(nullptr)
		, speed(1.f)
	{
	}
	MonsterScript::~MonsterScript()
	{
	}
	void MonsterScript::Initialize()
	{
	}
	void MonsterScript::Update()
	{
		if (mTarget == nullptr)
			FindTarget();
		else
			MoveToTarget();
	}
	void MonsterScript::LateUpdate()
	{
	}
	void MonsterScript::Render()
	{
	}

	void MonsterScript::FindTarget()
	{
		GameObject* player = SceneManager::GetActiveScene()->GetPlayer();
		if (player != nullptr)
		{
			mTarget = player;
			return;
		}
	}
	void MonsterScript::MoveToTarget()
	{
		Vector2 pPos = (Vector2)mTarget->GetComponent<Transform>()->GetPosition();
		Vector2 mPos = (Vector2)GetOwner()->GetComponent<Transform>()->GetPosition();
		
		Vector2 dir = pPos - mPos;
		//dir.y *= -1;
		dir.normalize();

		mPos += dir * speed * Time::DeltaTime();
		GetOwner()->GetComponent<Transform>()->SetPosition((Vector3)mPos);
	}
}