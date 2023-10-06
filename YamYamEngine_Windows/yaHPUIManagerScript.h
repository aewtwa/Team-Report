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

	private:
		HPUI* hpui[3] = {};

	};
}
