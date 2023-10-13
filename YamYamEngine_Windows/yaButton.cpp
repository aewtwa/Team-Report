#include "yaButton.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaText.h"

namespace ya
{
	Button::Button()
	{
		SetTag(TAG::Ui);
	}
	Button::~Button()
	{
	}
	void Button::Initialize()
	{
		AddComponent<Transform>();
		AddComponent<Collider>();
		AddComponent<Text>();
		GameObject::Initialize();
	}
	void Button::Update()
	{
		GameObject::Update();
	}
	void Button::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Button::Render()
	{
		GameObject::Render();
	}
	void Button::OnCollisionEnter(Collider* other)
	{
		GameObject::OnCollisionEnter(other);
	}
	void Button::OnCollisionStay(Collider* other)
	{
		GameObject::OnCollisionStay(other);
	}
	void Button::OnCollisionExit(Collider* other)
	{
		GameObject::OnCollisionExit(other);
	}
	void Button::OnClick()
	{
		GameObject::OnClick();
	}
}