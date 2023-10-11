#include "yaMonster.h"
#include "yaWaveManager.h"
#include "..\YamYamEngine_Windows\yaBullet.h"

namespace ya
{
	Monster::Monster(float hp)
		: HP(hp)
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
			HP -= dynamic_cast<Bullet*>(other->GetOwner())->GetDamage();
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