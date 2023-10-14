#include "yaReturnTitleButton.h"
#include "yaSceneManager.h"
#include "yaText.h"
#include "yaCollider.h"

namespace ya
{
	ReturnTitleButton::ReturnTitleButton()
	{
	}
	ReturnTitleButton::~ReturnTitleButton()
	{
	}
	void ReturnTitleButton::Initialize()
	{
		Button::Initialize();

		GetComponent<Collider>()->SetSize(Vector2(3, 1));

		Text* text = GetComponent<Text>();
		text->SetText(L"Return Title");
		text->SetStatic();
	}
	void ReturnTitleButton::Update()
	{
		Button::Update();
	}
	void ReturnTitleButton::LateUpdate()
	{
		Button::LateUpdate();
	}
	void ReturnTitleButton::Render()
	{
		Button::Render();
	}
	void ReturnTitleButton::OnCollisionEnter(Collider* other)
	{
		Button::OnCollisionEnter(other);
	}
	void ReturnTitleButton::OnCollisionStay(Collider* other)
	{
		Button::OnCollisionStay(other);
	}
	void ReturnTitleButton::OnCollisionExit(Collider* other)
	{
		Button::OnCollisionExit(other);
	}
	void ReturnTitleButton::OnClick()
	{
		Button::OnClick();

		SceneManager::LoadScene(L"TitleScene");
	}
}