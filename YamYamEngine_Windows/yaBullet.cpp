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
	{
		SetTag(enums::TAG::Projectile);
	}
	Bullet::~Bullet()
	{
	}
	void Bullet::Initialize()
	{
		Transform* tr = AddComponent<Transform>();
		tr->SetScale(Vector3(0.5f, 0.5f, 0.f));
		AddComponent<Collider>();
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetColor(Vector4(0.f, 0.f, 255.f, 0.f));

		GameObject::Initialize();
	}
	void Bullet::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		math::Vector2 pos = (Vector2)tr->GetPosition();		

		pos += mDirection * 10.f * Time::DeltaTime();

		tr->SetPosition((Vector3)pos);

		if (pos.x > 16.f || pos.y > 9.f ||
			pos.x < -16.f || pos.y < -9.f)
		{
			Destroy(this);
		}
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