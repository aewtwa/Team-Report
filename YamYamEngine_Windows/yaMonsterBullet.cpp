#include "yaMonsterBullet.h"
#include "yaResources.h"
#include "yaTime.h"
#include "yaCamera.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaMeshRenderer.h"
#include "yaInput.h"


namespace ya
{
	MonsterBullet::MonsterBullet()
	{
		SetTag(enums::TAG::MonsterBullet);
	}
	MonsterBullet::~MonsterBullet()
	{
	}
	void MonsterBullet::Initialize()
	{
		Transform* tr = AddComponent<Transform>();
		tr->SetScale(Vector3(0.5f, 0.5f, 1.f));
		Collider* col = AddComponent<Collider>();
		col->SetSize(Vector2(0.5f, 0.5f));
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetColor(Vector4(255.f, 0.f, 0.f, 0.f));

		GameObject::Initialize();
	}
	void MonsterBullet::Update()
	{
		GameObject::Update();
		Transform* tr = GetComponent<Transform>();
		math::Vector2 pos = (Vector2)tr->GetPosition();

		pos += mDirection * 10.f * Time::DeltaTime();

		tr->SetPosition((Vector3)pos);
	}
	void MonsterBullet::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void MonsterBullet::Render()
	{
		GameObject::Render();
	}
	void MonsterBullet::OnCollisionEnter(Collider* other)
	{
		if (other->GetOwner()->GetTag() == TAG::Wall)
		{
			Destroy(this);
		}
		if (other->GetOwner()->GetTag() == TAG::Player)
		{
			Destroy(this);
		}
	}
	void MonsterBullet::OnCollisionStay(Collider* other)
	{
	}
	void MonsterBullet::OnCollisionExit(Collider* other)
	{
	}
}

