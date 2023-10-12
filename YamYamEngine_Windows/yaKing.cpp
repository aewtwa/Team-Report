#include "yaKing.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaKingScript.h"



namespace ya
{
	King::King() : Monster(80.f)
	{
		SetTag(TAG::Monster);
	}
	King::~King()
	{
	}
	void King::Initialize()
	{
		AddComponent<Transform>();
		AddComponent<Collider>();
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetColor(Vector4(0xed, 0x00, 0x86, 0.f));
		AddComponent<KingScript>();

		GameObject::Initialize();
	}
	void King::Update()
	{
		GameObject::Update();
		Monster::Update();
	}
	void King::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void King::Render()
	{
		GameObject::Render();
	}
	void King::OnCollisionEnter(Collider* other)
	{
		Monster::OnCollisionEnter(other);
	}
	void King::OnCollisionStay(Collider* other)
	{
	}
	void King::OnCollisionExit(Collider* other)
	{
	}
}