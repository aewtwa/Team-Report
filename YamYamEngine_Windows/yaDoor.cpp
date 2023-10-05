#include "yaDoor.h"
#include "yaResources.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"

namespace ya
{
	Door::Door()
	{
	}
	Door::~Door()
	{
	}
	void Door::Initialize()
	{
		AddComponent<Transform>();
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"TriangleMesh"));

		GameObject::Initialize();
	}
	void Door::Update()
	{
		GameObject::Update();
	}
	void Door::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Door::Render()
	{
		GameObject::Render();
	}
	void Door::OnCollisionEnter(Collider* other)
	{
	}
	void Door::OnCollisionStay(Collider* other)
	{
	}
	void Door::OnCollisionExit(Collider* other)
	{
	}
}