#include "yaGameStartButton.h"
#include "yaSceneManager.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaMeshRenderer.h"

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
		Transform* tr = AddComponent<Transform>();
		tr->SetScale(Vector3(3, 2, 1));
		Collider* col = AddComponent<Collider>();
		col->SetSize(Vector2(3, 2));
		AddComponent<MeshRenderer>();

		GameObject::Initialize();
	}
	void GameStartButton::Update()
	{
		GameObject::Update();
	}
	void GameStartButton::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void GameStartButton::Render()
	{
		GameObject::Render();
	}
	void GameStartButton::OnCollisionEnter(Collider* other)
	{
		GameObject::OnCollisionEnter(other);
	}
	void GameStartButton::OnCollisionStay(Collider* other)
	{
		GameObject::OnCollisionStay(other);
	}
	void GameStartButton::OnCollisionExit(Collider* other)
	{
		GameObject::OnCollisionExit(other);
	}
	void GameStartButton::OnClick()
	{
		GameObject::OnClick();

		SceneManager::LoadScene(L"PlayScene");
	}
}