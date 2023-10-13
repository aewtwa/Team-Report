#pragma once
#include "yaScript.h"
#include "yaHPUI.h"

namespace ya
{
	class HPUIManagerScript : public Script
	{
	public:
		HPUIManagerScript();
		~HPUIManagerScript() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void SetHPUI(HPUI* ui1, HPUI* ui2, HPUI* ui3);

		void HPUISetState(int num, GameObject::eState states)
		{
			switch (states)
			{
			case ya::GameObject::Active:
				hpui[num]->Activate();
				break;
			case ya::GameObject::Paused:
				hpui[num]->Pause();
				break;
			default:
				break;
			}
		}

	private:
		HPUI* hpui[3] = {};

	};
}
