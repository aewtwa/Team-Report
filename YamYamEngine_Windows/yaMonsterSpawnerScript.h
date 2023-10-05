#pragma once
#include "yaScript.h"

namespace ya
{
	class MonsterSpawnerScript : public Script
	{
	public:
		MonsterSpawnerScript();
		~MonsterSpawnerScript() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:
		std::vector<GameObject*> mMonsters;

	};
}
