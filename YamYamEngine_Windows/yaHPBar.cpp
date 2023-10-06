#include "yaHPBar.h"
#include "yaobject.h"
#include "yaTransform.h"
#include "yaHPUIManagerScript.h"
#include "yaHPUI.h"

namespace ya
{
	HPBar::HPBar()
	{
	}
	HPBar::~HPBar()
	{
	}
	void HPBar::Initialize()
	{
		AddComponent<Transform>();
		AddComponent<HPUIManagerScript>();

		GameObject::Initialize();

		HPUIManagerScript* hm = GetScript<HPUIManagerScript>();
		hm->SetHPUI(object::Instantiate<HPUI>(enums::LAYER::UI)
					, object::Instantiate<HPUI>(enums::LAYER::UI)
					, object::Instantiate<HPUI>(enums::LAYER::UI));
	}
	void HPBar::Update()
	{
		GameObject::Update();
	}
	void HPBar::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void HPBar::Render()
	{
		GameObject::Render();
	}
}