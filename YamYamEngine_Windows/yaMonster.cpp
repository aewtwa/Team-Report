#include "yaMonster.h"
#include "yaMonsterScript.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"

namespace ya
{
	Monster::Monster()
	{
		SetTag(enums::TAG::Monster);
	}
	Monster::~Monster()
	{
	}
	void Monster::Initialize()
	{
		AddComponent<Transform>();
		AddComponent<Collider>();
		AddComponent<MeshRenderer>();

		AddComponent<MonsterScript>();

		GameObject::Initialize();
	}
	void Monster::Update()
	{
		GameObject::Update();
	}
	void Monster::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Monster::Render()
	{
		GameObject::Render();
	}
	void Monster::OnCollisionEnter(Collider* other)
	{
		if (other->GetOwner()->GetTag() == TAG::PlayerBullet)
		{
			Destroy(this);
		}
	}
	void Monster::OnCollisionStay(Collider* other)
	{
	}
	void Monster::OnCollisionExit(Collider* other)
	{
	}
}