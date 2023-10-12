#include "yaBomber.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaBomberScript.h"


namespace ya
{
	Bomber::Bomber() : Monster(1)
	{
	}
	Bomber::~Bomber()
	{
	}
	void Bomber::Initialize()
	{
		AddComponent<Transform>();
		AddComponent<Collider>();
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetColor(Vector4(255.f, 0.f, 0.f, 0.f));

		AddComponent<BomberScript>();
		GameObject::Initialize();
	}
	void Bomber::Update()
	{
		Monster::Update();
		GameObject::Update();
	}
	void Bomber::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Bomber::Render()
	{
		GameObject::Render();
	}
	void Bomber::OnCollisionEnter(Collider* other)
	{
		Monster::OnCollisionEnter(other);
	}
	void Bomber::OnCollisionStay(Collider* other)
	{
	}
	void Bomber::OnCollisionExit(Collider* other)
	{
	}
}