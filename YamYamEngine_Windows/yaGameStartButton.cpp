#include "yaGameStartButton.h"
#include "yaSceneManager.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaText.h"

namespace ya
{
	GameStartButton::GameStartButton()
	{
	}
	GameStartButton::~GameStartButton()
	{
	}
	void GameStartButton::Initialize()
	{
		Button::Initialize();

		///GetComponent<Transform>()->SetScale(Vector3(3, 1, 1));;
		GetComponent<Collider>()->SetSize(Vector2(3, 1));
		Text* text = GetComponent<Text>();
		text->SetText(L"Play");
		text->SetStatic();
	}
	void GameStartButton::Update()
	{
		Button::Update();
	}
	void GameStartButton::LateUpdate()
	{
		Button::LateUpdate();
	}
	void GameStartButton::Render()
	{
		Button::Render();
	}
	void GameStartButton::OnCollisionEnter(Collider* other)
	{
		Button::OnCollisionEnter(other);
	}
	void GameStartButton::OnCollisionStay(Collider* other)
	{
		Button::OnCollisionStay(other);
	}
	void GameStartButton::OnCollisionExit(Collider* other)
	{
		Button::OnCollisionExit(other);
	}
	void GameStartButton::OnClick()
	{
		Button::OnClick();

		SceneManager::LoadScene(L"PlayScene");
	}
}