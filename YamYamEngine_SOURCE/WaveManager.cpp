#include "WaveManager.h"
#include <cmath>
#include "yaobject.h"


namespace ya
{
	bool WaveManager::StartCall = false;
	bool WaveManager::inWave = false;
	bool WaveManager::isClear = false;

	unsigned int WaveManager::waveCount = 0;
	unsigned int WaveManager::WaveMonsterCount = 0;
	unsigned int WaveManager::curMonsterCount = 0;
	unsigned int WaveManager::prevMonsterCount = 0;

	void WaveManager::Initialize()
	{
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

		if (curMonsterCount == 0)
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
		for (int i = 0; i < WaveMonsterCount; i++)
		{
			//ya::object::Instantiate<>(enums::LAYER::Monster, );
			curMonsterCount++;
		}
	}
	void WaveManager::GiveUp()
	{

	}
}