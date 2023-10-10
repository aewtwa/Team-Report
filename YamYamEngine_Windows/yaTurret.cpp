#include "yaTurret.h"
#include "yaMonsterScript.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaTurretScript.h"

namespace ya
{
	Turret::Turret() :
		  tr(nullptr)
		, col(nullptr)
		, mr(nullptr)
	{
		SetTag(enums::TAG::Monster);
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
	}
	void Turret::OnCollisionStay(Collider* other)
	{
	}
	void Turret::OnCollisionExit(Collider* other)
	{
	}
}
