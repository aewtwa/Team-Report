#include "WaveManager.h"
#include <cmath>
#include <cstdlib>
#include "yaobject.h"
#include "yaTime.h"

#include "..\YamYamEngine_Windows\yaZombie.h"
#include "..\YamYamEngine_Windows\yaTurret.h"
#include "..\YamYamEngine_Windows\yaBomber.h"

namespace ya
{
	bool WaveManager::StartCall = false;
	bool WaveManager::inWave = false;
	bool WaveManager::isClear = false;

	unsigned int WaveManager::waveCount = 0;
	unsigned int WaveManager::WaveMonsterCount = 0;
	unsigned int WaveManager::curMonsterCount = 0;
	unsigned int WaveManager::prevMonsterCount = 0;

	std::vector<std::wstring> WaveManager::monsters = {};

	void WaveManager::Initialize()
	{
		monsters.push_back(L"zombie");
		monsters.push_back(L"turret");
		monsters.push_back(L"bomber");
	}
	void WaveManager::Update()
	{
		if (StartCall)
		{
			waveCount++;
			prevMonsterCount = WaveMonsterCount;
			WaveMonsterCount = (prevMonsterCount + 3) * ceil(waveCount % 10);
			isClear = false;
			inWave = true;

			SpawnMonster();

			StartCall = false;
		}

		if (curMonsterCount == 0 && inWave)
		{
			isClear = true;
			inWave = false;
		}
	}
	void WaveManager::LateUpdate()
	{
	}

	void WaveManager::WaveStart()
	{
		StartCall = true;
	}
	void WaveManager::SpawnMonster()
	{
		Vector3 startPos = Vector3(9, 8, 0);

		int line = WaveMonsterCount / 5;

		if (WaveMonsterCount % 5 != 0)
		{
			line++;
		}

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
	void WaveManager::GiveUp()
	{

	}
}