#include "yaMonster.h"
#include "yaWaveManager.h"

namespace ya
{
	Monster::Monster()
	{
		SetTag(enums::TAG::Monster);
	}
	Monster::~Monster()
	{
		WaveManager::MonsterCountDecrease();
	}
	void Monster::OnCollisionEnter(Collider* other)
	{
		if (other->GetOwner()->GetTag() == TAG::PlayerBullet)
		{
			HP--;
		}
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