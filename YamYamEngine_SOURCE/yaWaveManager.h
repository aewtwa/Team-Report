#pragma once
#include "CommonInclude.h"
#include "..\YamYamEngine_Windows\yaWaveButton.h"

namespace ya
{
	class WaveManager
	{
	public:
		static void SetActivate(bool value) { isActivate = value; Setting(); }

		static void Setting();
		static void Update();
		static void LateUpdate();

		static void WaveStart();
		static void SpawnMonster();
		static void GiveUp();

		static void MonsterCountDecrease() { curMonsterCount -= 1; }


	private:
		static bool isActivate;

		static bool StartCall;
		static bool inWave;
		static bool isClear;

		static unsigned int waveCount;
		static unsigned int WaveMonsterCount;
		static unsigned int curMonsterCount;
		static unsigned int prevMonsterCount;

		static std::vector<std::wstring> monsters;
		static std::vector<std::wstring> rewards;

		static WaveButton* StartButton;
		static WaveButton* GiveUpButton;
	};
}
