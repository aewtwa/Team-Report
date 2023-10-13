#pragma once
#include "CommonInclude.h"
#include <random>
#include "..\YamYamEngine_Windows\yaWaveButton.h"

namespace ya
{
	class WaveManager
	{
	public:
		static void SetActivate(bool value) { isActivate = value; Setting(); }
		static void Release();

		static void Setting();
		static void Update();
		static void LateUpdate();

		static void WaveStart();
		static void SpawnMonster();
		static void SpawnReward();
		static void GiveUp();

		static void MonsterCountDecrease() { curMonsterCount -= 1; }
		static void ChooseReward() { 
			isGetReward = true;
			StartButton->Activate();
		}
		static bool IsRewardSelected() { return isGetReward; }

	private:
		static bool isActivate;

		static bool StartCall;
		static bool inWave;
		static bool isClear;
		static bool isGetReward;

		static unsigned int waveCount;
		static unsigned int WaveMonsterCount;
		static unsigned int curMonsterCount;
		static unsigned int prevMonsterCount;

		static std::random_device rd;   // non-deterministic generator

		static std::vector<std::wstring> monsters;
		static std::vector<std::wstring> rewards;
		static std::vector<Vector3> rewardSpawnPos;

		static WaveButton* StartButton;
		static WaveButton* GiveUpButton;
	};
}
