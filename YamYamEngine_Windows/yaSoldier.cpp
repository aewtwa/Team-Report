#include "yaSoldier.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaSoldierScript.h"

namespace ya
{
	Soldier::Soldier() : Monster(3)
	{
		SetTag(TAG::Monster);
	}
	Soldier::~Soldier()
	{

	}
	void Soldier::Initialize()
	{
		AddComponent<Transform>();
		AddComponent<Collider>();
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetColor(Vector4(0x00, 0xa3, 0xd2, 0.f));
		AddComponent<SoldierScript>();

		GameObject::Initialize();
	}
	void Soldier::Update()
	{
		GameObject::Update();
	}
	void Soldier::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Soldier::Render()
	{
		GameObject::Render();
	}
	void Soldier::OnCollisionEnter(Collider* other)
	{
	}
	void Soldier::OnCollisionStay(Collider* other)
	{
	}
	void Soldier::OnCollisionExit(Collider* other)
	{
	}
}