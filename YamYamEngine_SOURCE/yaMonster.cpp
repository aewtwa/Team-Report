#include "yaMonster.h"
#include "WaveManager.h"

namespace ya
{
	Monster::Monster()
	{
		SetTag(enums::TAG::Monster);
	}
	Monster::~Monster()
	{
		WaveManager::MonsterCountDown();
	}
	void Monster::OnCollisionEnter(Collider* other)
	{
		GameObject::OnCollisionEnter(other);
	}
	void Monster::OnCollisionStay(Collider* other)
	{
		GameObject::OnCollisionStay(other);
	}
	void Monster::OnCollisionExit(Collider* other)
	{
		GameObject::OnCollisionExit(other);
	}
}