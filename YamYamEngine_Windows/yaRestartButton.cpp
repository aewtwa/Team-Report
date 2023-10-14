#include "yaRestartButton.h"
#include "yaSceneManager.h"
#include "yaText.h"
#include "yaCollider.h"

namespace ya
{
	RestartButton::RestartButton()
	{
	}
	RestartButton::~RestartButton()
	{
	}
	void RestartButton::Initialize()
	{
		Button::Initialize();

		GetComponent<Collider>()->SetSize(Vector2(3, 1));

		Text* text = GetComponent<Text>();
		text->SetText(L"ReStart");
		text->SetStatic();
	}
	void RestartButton::Update()
	{
		Button::Update();
	}
	void RestartButton::LateUpdate()
	{
		Button::LateUpdate();
	}
	void RestartButton::Render()
	{
		Button::Render();
	}
	void RestartButton::OnCollisionEnter(Collider* other)
	{
		Button::OnCollisionEnter(other);
	}
	void RestartButton::OnCollisionStay(Collider* other)
	{
		Button::OnCollisionStay(other);
	}
	void RestartButton::OnCollisionExit(Collider* other)
	{
		Button::OnCollisionExit(other);
	}
	void RestartButton::OnClick()
	{
		Button::OnClick();

		SceneManager::LoadScene(L"PlayScene");
	}
}