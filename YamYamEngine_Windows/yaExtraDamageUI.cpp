#include "yaExtraDamageUI.h"
#include "yaTransform.h"
#include "yaText.h"

namespace ya
{
	ExtraDamageUI::ExtraDamageUI()
	{
	}
	ExtraDamageUI::~ExtraDamageUI()
	{
	}
	void ExtraDamageUI::Initialize()
	{
		Transform* tr = AddComponent<Transform>();
		tr->SetPositionVec2(Vector2(-750, 250));
		Text* text = AddComponent<Text>();
		text->SetStatic();

		GameObject::Initialize();
	}
	void ExtraDamageUI::Update()
	{
		GetComponent<Text>()->SetText(L"Extra Dmg : " + std::to_wstring(target->GetAdditionalDamage()));
		GameObject::Update();
	}
	void ExtraDamageUI::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void ExtraDamageUI::Render()
	{
		GameObject::Render();
	}
}