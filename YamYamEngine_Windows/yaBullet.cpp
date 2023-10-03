#include "yaBullet.h"
#include "..\YamYamEngine_SOURCE\yaResources.h"
#include "..\YamYamEngine_SOURCE\yaTime.h"
#include "..\YamYamEngine_SOURCE\yaCamera.h"
#include "..\YamYamEngine_SOURCE\yaTransform.h"
#include "..\YamYamEngine_SOURCE\yaCollider.h"
#include "..\YamYamEngine_SOURCE\yaMeshRenderer.h"
#include "yaInput.h"

namespace ya
{
	Bullet::Bullet()
	{
	}
	Bullet::~Bullet()
	{
	}
	void Bullet::Initialize()
	{
		AddComponent<Transform>();
		AddComponent<Collider>();
		AddComponent<MeshRenderer>();


		GameObject::Initialize();
	}
	void Bullet::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		math::Vector2 pos = (Vector2)tr->GetPosition();

		pos += mDirection * 10.f * Time::DeltaTime();

		tr->SetPosition(Camera::CalculatePosition((Vector3)pos));

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
	}
	void Bullet::OnCollisionStay(Collider* other)
	{
	}
	void Bullet::OnCollisionExit(Collider* other)
	{
	}
}