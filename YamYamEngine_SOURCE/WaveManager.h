#pragma once
#include "CommonInclude.h"

namespace ya
{
	class WaveManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();

		static void WaveStart();
		static void SpawnMonster();
		static void GiveUp();

		static void MonsterCountDown() { curMonsterCount -= 1; }

	private:
		static bool StartCall;
		static bool inWave;
		static bool isClear;

		static unsigned int waveCount;
		static unsigned int WaveMonsterCount;
		static unsigned int curMonsterCount;
		static unsigned int prevMonsterCount;
	};
}