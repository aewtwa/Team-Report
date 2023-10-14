#include "yaScoreUI.h"
#include "yaWaveManager.h"
#include "yaTransform.h"
#include "yaText.h"

namespace ya
{
	ScoreUI::ScoreUI()
	{
	}
	ScoreUI::~ScoreUI()
	{
	}
	void ScoreUI::Initialize()
	{
		Transform* tr = AddComponent<Transform>();
		tr->SetPositionVec2(Vector2(0, 7));
		AddComponent<Text>()->SetStatic();

		GameObject::Initialize();
	}
	void ScoreUI::Update()
	{
		UIObject::Update();

		GetComponent<Text>()->SetText(L"Score : " + std::to_wstring(WaveManager::GetScore()));
	}
	void ScoreUI::LateUpdate()
	{
		UIObject::LateUpdate();
	}
	void ScoreUI::Render()
	{
		UIObject::Render();
	}
}