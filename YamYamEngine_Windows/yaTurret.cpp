#include "yaTurret.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaTurretScript.h"

namespace ya
{
	Turret::Turret() : Monster(3)
		, tr(nullptr)
		, col(nullptr)
		, mr(nullptr)
	{
		SetTag(TAG::Monster);
	}
	Turret::~Turret()
	{
	}
	void Turret::Initialize()
	{
		tr = AddComponent<Transform>();
		col = AddComponent<Collider>();
		mr = AddComponent<MeshRenderer>();
		mr->SetColor(Vector4(0.f, 255.f, 0.f, 0.f));
		AddComponent<TurretScript>();

		GameObject::Initialize();

	}
	void Turret::Update()
	{
		if (GetHp() <= 0)
			Destroy(this);
		Monster::Update();
		GameObject::Update();
	}
	void Turret::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Turret::Render()
	{
		GameObject::Render();
	}
	void Turret::OnCollisionEnter(Collider* other)
	{
		Monster::OnCollisionEnter(other);
	}
	void Turret::OnCollisionStay(Collider* other)
	{
	}
	void Turret::OnCollisionExit(Collider* other)
	{
	}
}
