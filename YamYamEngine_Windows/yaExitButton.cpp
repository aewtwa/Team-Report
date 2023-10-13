#include "yaExitButton.h"
#include "yaApplication.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaText.h"

extern ya::Application application;

namespace ya
{
	ExitButton::ExitButton()
	{
	}
	ExitButton::~ExitButton()
	{
	}
	void ExitButton::Initialize()
	{
		Button::Initialize();

		Transform* tr = GetComponent<Transform>();
		tr->SetScale(Vector3(3, 2, 1));
		tr->SetPositionVec2(Vector2(0, -3));
		GetComponent<Collider>()->SetSize(Vector2(3, 2));
		Text* text = GetComponent<Text>();
		text->SetText(L"Exit");
		text->SetStatic();
	}
	void ExitButton::Update()
	{
		Button::Update();
	}
	void ExitButton::LateUpdate()
	{
		Button::LateUpdate();
	}
	void ExitButton::Render()
	{
		Button::Render();
	}
	void ExitButton::OnCollisionEnter(Collider* other)
	{
		Button::OnCollisionEnter(other);
	}
	void ExitButton::OnCollisionStay(Collider* other)
	{
		Button::OnCollisionStay(other);
	}
	void ExitButton::OnCollisionExit(Collider* other)
	{
		Button::OnCollisionExit(other);
	}
	void ExitButton::OnClick()
	{
		Button::OnClick();
		SendMessage(application.GetHwnd(), WM_CLOSE, 0, 0);
	}
}