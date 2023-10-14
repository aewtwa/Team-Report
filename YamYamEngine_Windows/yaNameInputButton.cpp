#include "yaNameInputButton.h"
#include "yaApplication.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaText.h"
#include "yaInput.h"

extern ya::Application application;

namespace ya
{
	NameInputButton::NameInputButton() :
		  is_clicked(false)
	{
	}
	NameInputButton::~NameInputButton()
	{
	}
	void NameInputButton::Initialize()
	{
		Button::Initialize();

		GetComponent<Collider>()->SetSize(Vector2(3, 1));
		Text* text = GetComponent<Text>();
		text->SetText(L"Name : ");
	}
	void NameInputButton::Update()
	{
		if (is_clicked)
		{

		}
		Button::Update();
	}
	void NameInputButton::LateUpdate()
	{
		Button::LateUpdate();
	}
	void NameInputButton::Render()
	{
		Button::Render();
	}
	void NameInputButton::OnCollisionEnter(Collider* other)
	{
		Button::OnCollisionEnter(other);
	}
	void NameInputButton::OnCollisionStay(Collider* other)
	{
		Button::OnCollisionEnter(other);
	}
	void NameInputButton::OnCollisionExit(Collider* other)
	{
		Button::OnCollisionEnter(other);
	}
	void NameInputButton::OnClick()
	{
		NameInputButton::OnClick();
		is_clicked = true;
		SendMessage(application.GetHwnd(), WM_CLOSE, 0, 0);
	}
}