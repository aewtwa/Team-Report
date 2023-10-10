#include "WaveManager.h"
#include <cmath>
#include "yaobject.h"


namespace ya
{
	bool WaveManager::StartCall = false;
	bool WaveManager::inWave = false;
	bool WaveManager::isClear = false;

	unsigned int WaveManager::waveCount = 0;
	unsigned int WaveManager::curMonsterCount = 0;
	unsigned int WaveManager::prevMonsterCount = 0;

	void WaveManager::Initialize()
	{
	}
	void WaveManager::Update()
	{
		if (StartCall)
		{
			WaveStart();
			SpawnMonster();
			StartCall = false;
		}
	}
	void WaveManager::LateUpdate()
	{
	}

	void WaveManager::WaveStart()
	{
		waveCount++;
		prevMonsterCount = curMonsterCount;
		curMonsterCount = (prevMonsterCount + 3) * ceil(waveCount % 10);
		inWave = true;
	}
	void WaveManager::SpawnMonster()
	{
		for (int i = 0; i < curMonsterCount; i++)
		{
			//ya::object::Instantiate<>(enums::LAYER::Monster, );
		}
	}
	void WaveManager::GiveUp()
	{

	}
}