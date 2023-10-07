#include "yaShield.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaCollider.h"

namespace ya
{
	Shield::Shield()
	{
	}
	Shield::~Shield()
	{
	}
	void Shield::Initialize()
	{
		Transform* tr = AddComponent<Transform>();
		tr->SetScale(Vector3(2, 1, 1));
		Collider* col = AddComponent<Collider>();
		col->SetSize(Vector2(2, 1));
		AddComponent<MeshRenderer>();

		GameObject::Initialize();
	}
	void Shield::Update()
	{
		GameObject::Update();
	}
	void Shield::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Shield::Render()
	{
		GameObject::Render();
	}
	void Shield::OnCollisionEnter(Collider* other)
	{
		GameObject::OnCollisionEnter(other);
	}
	void Shield::OnCollisionStay(Collider* other)
	{
		GameObject::OnCollisionStay(other);
	}
	void Shield::OnCollisionExit(Collider* other)
	{
		GameObject::OnCollisionExit(other);
	}
}