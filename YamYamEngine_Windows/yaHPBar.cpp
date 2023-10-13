#include "yaHPBar.h"
#include "yaobject.h"
#include "yaSceneManager.h"
#include "yaplayer.h"
#include "yaTransform.h"
#include "yaHPUIManagerScript.h"
#include "yaHPUI.h"

namespace ya
{
	HPBar::HPBar()
		: target(nullptr)
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

		switch (target->GetHP())
		{
		case 0:
			{
				GetScript<HPUIManagerScript>()->HPUISetState(0, GameObject::eState::Paused);
				GetScript<HPUIManagerScript>()->HPUISetState(1, GameObject::eState::Paused);
				GetScript<HPUIManagerScript>()->HPUISetState(2, GameObject::eState::Paused);
			}
			break;

		case 1:
			{
				GetScript<HPUIManagerScript>()->HPUISetState(0, GameObject::eState::Active);
				GetScript<HPUIManagerScript>()->HPUISetState(1, GameObject::eState::Paused);
				GetScript<HPUIManagerScript>()->HPUISetState(2, GameObject::eState::Paused);
			}
			break;

		case 2:
			{
				GetScript<HPUIManagerScript>()->HPUISetState(0, GameObject::eState::Active);
				GetScript<HPUIManagerScript>()->HPUISetState(1, GameObject::eState::Active);
				GetScript<HPUIManagerScript>()->HPUISetState(2, GameObject::eState::Paused);
			}
			break;

		case 3:
			{
				GetScript<HPUIManagerScript>()->HPUISetState(0, GameObject::eState::Active);
				GetScript<HPUIManagerScript>()->HPUISetState(1, GameObject::eState::Active);
				GetScript<HPUIManagerScript>()->HPUISetState(2, GameObject::eState::Active);
			}
			break;
		}
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