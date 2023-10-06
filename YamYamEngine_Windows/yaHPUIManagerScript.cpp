#include "yaHPUIManagerScript.h"
#include "yaGameObject.h"
#include "yaTransform.h"

namespace ya
{
	HPUIManagerScript::HPUIManagerScript()
	{
	}
	HPUIManagerScript::~HPUIManagerScript()
	{
	}

	void HPUIManagerScript::Initialize()
	{
	}
	void HPUIManagerScript::Update()
	{
		Vector2 mPos = GetOwner()->GetComponent<Transform>()->GetPositionVec2(); 

		if (hpui[0] != nullptr)
		{
			Transform* tr = hpui[0]->GetComponent<Transform>();

			Vector2 pos = Vector2(mPos.x - 1.5f, mPos.y);

			tr->SetPositionVec2(pos);			
		}

		if (hpui[1] != nullptr)
		{
			Transform* tr = hpui[1]->GetComponent<Transform>();

			Vector2 pos = Vector2(mPos.x, mPos.y);

			tr->SetPositionVec2(pos);
		}

		if (hpui[2] != nullptr)
		{
			Transform* tr = hpui[2]->GetComponent<Transform>();

			Vector2 pos = Vector2(mPos.x + 1.5f, mPos.y);

			tr->SetPositionVec2(pos);
		}
	}
	void HPUIManagerScript::LateUpdate()
	{
	}
	void HPUIManagerScript::Render()
	{
	}

	void HPUIManagerScript::SetHPUI(HPUI* ui1, HPUI* ui2, HPUI* ui3)
	{
		hpui[0] = ui1;
		hpui[1] = ui2;
		hpui[2] = ui3;
	}
}