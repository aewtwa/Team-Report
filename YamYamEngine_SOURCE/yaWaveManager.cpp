#include "yaWaveManager.h"
#include <cmath>
#include <cstdlib>
#include "yaobject.h"
#include "yaTime.h"
#include "yaSceneManager.h"

#include "..\YamYamEngine_Windows\yaZombie.h"
#include "..\YamYamEngine_Windows\yaTurret.h"
#include "..\YamYamEngine_Windows\yaBomber.h"

namespace ya
{
	bool WaveManager::isActivate = false;

	bool WaveManager::StartCall = false;
	bool WaveManager::inWave = false;
	bool WaveManager::isClear = false;
	bool WaveManager::isGetReward = false;

	unsigned int WaveManager::waveCount = 0;
	unsigned int WaveManager::WaveMonsterCount = 0;
	unsigned int WaveManager::curMonsterCount = 0;
	unsigned int WaveManager::prevMonsterCount = 0;

	std::vector<std::wstring> WaveManager::monsters = {};

	WaveButton* WaveManager::StartButton = nullptr;
	WaveButton* WaveManager::GiveUpButton = nullptr;

	void WaveManager::Setting()
	{
		//button spawn
		StartButton = object::Instantiate<WaveButton>(enums::LAYER::Wall, Vector3(10, 5, 0));
		GiveUpButton = object::Instantiate<WaveButton>(enums::LAYER::Wall, Vector3(10, 10, 0));

		GiveUpButton->SetType(WaveButton::WaveButtonType::giveup);
		StartButton->SetType(WaveButton::WaveButtonType::start);

		//monster types initialize
		monsters.push_back(L"zombie");
		monsters.push_back(L"turret");
		monsters.push_back(L"bomber");
		monsters.push_back(L"soldier");
	}
	void WaveManager::Update()
	{
		if (isActivate)
		{
			if (StartCall)
			{
				waveCount++;
				prevMonsterCount = WaveMonsterCount;
				WaveMonsterCount = (prevMonsterCount + 3) /** ceil(waveCount % 10)*/;
				isClear = false;
				inWave = true;

				SpawnMonster();

				StartCall = false;
			}

			if (curMonsterCount == 0 && inWave)
			{
				isClear = true;
				inWave = false;

				GiveUpButton->Activate();
			}

			if (isClear)
			{
				WaveClear();
				isClear = false;
			}

			if (!isClear && !inWave && isGetReward)
			{
				StartButton->Activate();
			}
		}
	}
	void WaveManager::LateUpdate()
	{
	}

	void WaveManager::WaveStart()
	{
		StartCall = true;
		StartButton->Pause();
		GiveUpButton->Pause();
	}
	void WaveManager::SpawnMonster()
	{
		Vector3 startPos = Vector3(-3, 8, 0);

		for (int i = 0; i < WaveMonsterCount; i++)
		{
			Vector3 curPos = startPos;

			srand(Time::GetTime() / Time::DeltaTime() * i * waveCount / curMonsterCount * WaveMonsterCount / prevMonsterCount);
			int r = rand();
			r %= 3;

			curPos.x += (i - ((i / 5) * 5)) * 2;
			curPos.y += i / 5;

			if (monsters[r] == L"zombie")
				ya::object::Instantiate<Zombie>(enums::LAYER::Monster, curPos);
			else if (monsters[r] == L"turret")
				ya::object::Instantiate<Turret>(enums::LAYER::Monster, curPos);
			else if (monsters[r] == L"bomber")
				ya::object::Instantiate<Bomber>(enums::LAYER::Monster, curPos);

			curMonsterCount++;
		}
	}
	void WaveManager::WaveClear()
	{
		//상자 스폰
	}
	void WaveManager::GiveUp()
	{
		SceneManager::LoadScene(L"TitleScene");
		// 여기서 점수관련 작업
	}
}