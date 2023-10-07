#include "yaShield.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaMeshRenderer.h"
#include "yaShieldScript.h"

namespace ya
{	
	Shield::Shield()
	{
		SetTag(TAG::Shield);
	}
	
	Shield::~Shield()
	{
	}
	
	void Shield::Initialize()
	{
		Transform* tr = AddComponent<Transform>();
		Collider* col = AddComponent<Collider>();
		tr->SetScale(Vector3(3, 1, 1));
		col->SetSize(Vector2(3, 1));

		AddComponent<MeshRenderer>();

		AddComponent<ShieldScript>();
	
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
