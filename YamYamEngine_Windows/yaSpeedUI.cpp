#include "yaSpeedUI.h"
#include "yaTransform.h"
#include "yaText.h"

namespace ya
{
	SpeedUI::SpeedUI()
	{
	}
	SpeedUI::~SpeedUI()
	{
	}
	void SpeedUI::Initialize()
	{
		Transform* tr = AddComponent<Transform>();
		tr->SetPositionVec2(Vector2(-750, 150));
		Text* text = AddComponent<Text>();
		text->SetStatic();

		GameObject::Initialize();
	}
	void SpeedUI::Update()
	{
		GetComponent<Text>()->SetText(L"Speed : " + std::to_wstring(target->GetMoveSpeed()));
		GameObject::Update();
	}
	void SpeedUI::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void SpeedUI::Render()
	{
		GameObject::Render();
	}
}