#include "yaBullet.h"
#include "yaResources.h"
#include "yaTime.h"
#include "yaCamera.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaMeshRenderer.h"
#include "yaInput.h"

namespace ya
{
	Bullet::Bullet()
		: startPos(Vector2::Zero)
		, maxDistance(Vector2::Zero)
		, Damage(1.f)
	{
		SetTag(enums::TAG::PlayerBullet);
	}
	Bullet::~Bullet()
	{
	}
	void Bullet::Initialize()
	{
		Transform* tr = AddComponent<Transform>();
		tr->SetScale(Vector3(0.5f, 0.5f, 1.f));
		Collider* col = AddComponent<Collider>();
		col->SetSize(Vector2(0.5f, 0.5f));
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetColor(Vector4(0.f, 0.f, 255.f, 0.f));

		GameObject::Initialize();
	}
	void Bullet::Update()
	{
		Transform* tr = GetComponent<Transform>();
		math::Vector2 pos = (Vector2)tr->GetPosition();	

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
		GameObject::Update();

	}
	void Bullet::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Bullet::Render()
	{
		GameObject::Render();
	}
	void Bullet::OnCollisionEnter(Collider* other) 
	{
		if (other->GetOwner()->GetTag() == TAG::Wall)
		{
			Destroy(this);
		}
		if (other->GetOwner()->GetTag() == TAG::Monster)
		{
			Destroy(this);
		}
	}
	void Bullet::OnCollisionStay(Collider* other) 
	{
	}
	void Bullet::OnCollisionExit(Collider* other)
	{
	}
}