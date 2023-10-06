#include "yaUIObject.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"

namespace ya
{
	UIObject::UIObject()
	{
	}
	UIObject::~UIObject()
	{
	}
	void UIObject::Initialize()
	{
		AddComponent<Transform>();
		AddComponent<MeshRenderer>();

		GameObject::Initialize();
	}
	void UIObject::Update()
	{
		GameObject::Update();
	}
	void UIObject::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void UIObject::Render()
	{
		GameObject::Render();
	}
	void UIObject::OnCollisionEnter(Collider* other)
	{
	}
	void UIObject::OnCollisionStay(Collider* other)
	{
	}
	void UIObject::OnCollisionExit(Collider* other)
	{
	}
}