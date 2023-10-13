#include "yaFireRateUI.h"
#include "yaTransform.h"
#include "yaText.h"

namespace ya
{
	FireRateUI::FireRateUI()
	{
	}
	FireRateUI::~FireRateUI()
	{
	}
	void FireRateUI::Initialize()
	{
		Transform* tr = AddComponent<Transform>();
		tr->SetPositionVec2(Vector2(-15, -4));
		Text* text = AddComponent<Text>();
		text->SetStatic();

		GameObject::Initialize();
	}
	void FireRateUI::Update()
	{
		GetComponent<Text>()->SetText(L"Firerate : " + std::to_wstring(target->GetFireRate()));
		GameObject::Update();
	}
	void FireRateUI::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void FireRateUI::Render()
	{
		GameObject::Render();
	}
}