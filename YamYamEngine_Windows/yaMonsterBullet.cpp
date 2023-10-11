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
		startPos = Vector2::Zero;
		maxDistance = Vector2::Zero;
		isColorSet = false;
		ColorPalette = Vector3::Zero;
	}
	MonsterBullet::~MonsterBullet()
	{
	}
	void MonsterBullet::Initialize()
	{
		SetTag(enums::TAG::MonsterBullet);
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
		if (ColorPalette != Vector3::Zero && !isColorSet)
		{
			MeshRenderer* mr = AddComponent<MeshRenderer>();
			mr->SetColor(Vector4(ColorPalette.x, ColorPalette.y, ColorPalette.z, 0.f));
			isColorSet = true;
		}

		GameObject::Update();
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = (Vector2)tr->GetPosition();
		if (maxDistance != Vector2::Zero)
		{
			if (abs(startPos.x - pos.x) > maxDistance.x ||
				abs(startPos.y - pos.y) > maxDistance.y)
			{
				Destroy(this);
			}
		}

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
	}
	void MonsterBullet::OnCollisionStay(Collider* other)
	{
	}
	void MonsterBullet::OnCollisionExit(Collider* other)
	{
	}
}

