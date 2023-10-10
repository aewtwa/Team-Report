#pragma once
#include "yaScript.h"

namespace ya
{
	class WaveManagerScript : public Script
	{
	public:
		WaveManagerScript();
		~WaveManagerScript() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void WaveStart();
		void SpawnMonster();
		void GiveUp();

	private:
		bool StartCall;
		bool inWave;
		bool isClear;

		unsigned int waveCount;
		unsigned int curMonsterCount;
		unsigned int prevMonsterCount;

	};
}
