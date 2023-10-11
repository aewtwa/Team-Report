#include "yaplayer.h"
#include "yaResources.h"
#include "yaShotScript.h"
#include "yaControllerScript.h"
#include "yaPlayerColorChangeScript.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaMeshRenderer.h"
#include "yaMonsterBullet.h"

namespace ya
{
	player::player()
		: HP(3)
		, FireRate(0.3f)
		, MoveSpeed(3.f)
		, PlayerColor(Vector3::Zero)
		, ShootType(ShootType::basic)
	{
		SetTag(enums::TAG::Player);
	}
	player::~player()
	{
	}
	void player::Initialize()
	{
		AddComponent<Transform>();
		Collider* col = AddComponent<Collider>();
		AddComponent<MeshRenderer>();

		AddComponent<ShotScript>();
		AddComponent<ControllerScript>();
		AddComponent<PlayerColorChangeScript>();

		col->SetSize(Vector2(1.f, 1.f));

		GameObject::Initialize();
	}
	void player::Update()
	{
		GameObject::Update();
	}
	void player::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void player::Render()
	{
		GameObject::Render();
	}
	void player::OnCollisionEnter(Collider* other)
	{
		if (other->GetOwner()->GetTag() == TAG::MonsterBullet)
		{
			MonsterBullet* monBullet = dynamic_cast<MonsterBullet*>(other->GetOwner());
			if (monBullet->GetColor() != PlayerColor)
			{
				HP--;
				Destroy(other->GetOwner());
			}
		}
		GameObject::OnCollisionEnter(other);
	}
	void player::OnCollisionStay(Collider* other)
	{
		GameObject::OnCollisionStay(other);
	}
	void player::OnCollisionExit(Collider* other)
	{
		GameObject::OnCollisionExit(other);
	}
}