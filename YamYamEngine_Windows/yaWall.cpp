#include "yaWall.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"

namespace ya
{
	Wall::Wall()
	{
		SetTag(TAG::Wall);
	}
	Wall::~Wall()
	{
	}
	void Wall::Initialize()
	{
		Transform* tr = AddComponent<Transform>();
		tr->SetScale(Vector3::One);
		AddComponent<Collider>();
		AddComponent<MeshRenderer>();

		GameObject::Initialize();
	}
	void Wall::Update()
	{
		GameObject::Update();
	}
	void Wall::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Wall::Render()
	{
		GameObject::Render();
	}
	void Wall::OnCollisionEnter(Collider* other)
	{
	}
	void Wall::OnCollisionStay(Collider* other)
	{
	}
	void Wall::OnCollisionExit(Collider* other)
	{
	}
}