#pragma once
#include "..\YamYamEngine_SOURCE\yaScript.h"

namespace ya
{
	class MonsterScript : public Script
	{
	public:
		MonsterScript();
		~MonsterScript() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:

	};
}
