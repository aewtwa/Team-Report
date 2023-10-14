#include "yaWaveManager.h"
#include <iostream>
#include <cmath>
#include "yaobject.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaColliderManager.h"

#include "..\YamYamEngine_Windows\yaZombie.h"
#include "..\YamYamEngine_Windows\yaTurret.h"
#include "..\YamYamEngine_Windows\yaBomber.h"

#include "..\YamYamEngine_Windows\yaHealBox.h"
#include "..\YamYamEngine_Windows\yaSpeedUpBox.h"
#include "..\YamYamEngine_Windows\yaFireRateUpBox.h"
#include "..\YamYamEngine_Windows\yaDamageUpBox.h"
#include "..\YamYamEngine_Windows\yaIncreaseProjectileBox.h"

namespace ya
{
	bool WaveManager::isActivate = false;

	int WaveManager::Score = 0;

	bool WaveManager::StartCall = false;
	bool WaveManager::inWave = false;
	bool WaveManager::isClear = false;
	bool WaveManager::isGetReward = false;

	unsigned int WaveManager::waveCount = 0;
	unsigned int WaveManager::WaveMonsterCount = 0;
	unsigned int WaveManager::curMonsterCount = 0;
	unsigned int WaveManager::prevMonsterCount = 0;

	std::random_device WaveManager::rd;

	std::vector<std::wstring> WaveManager::monsters = {};
	std::vector<std::wstring> WaveManager::bosses = {};
	std::vector<std::wstring> WaveManager::rewards = {};
	std::vector<Vector3> WaveManager::rewardSpawnPos = {};

	WaveButton* WaveManager::StartButton = nullptr;
	WaveButton* WaveManager::GiveUpButton = nullptr;

	void WaveManager::Release()
	{

	}

	void WaveManager::Setting()
	{
		ColliderManager::CollisionLayerCheck(LAYER::Player, LAYER::Reward, true);

		Score = 0;

		StartCall = false;
		inWave = false;
		isClear = false;
		isGetReward = false;

		waveCount = 0;
		WaveMonsterCount = 0;
		curMonsterCount = 0;
		prevMonsterCount = 0;

		if (StartButton == nullptr && GiveUpButton == nullptr)
		{
			//button spawn
			StartButton = object::Instantiate<WaveButton>(enums::LAYER::Wall, Vector3(10, 5, 0));
			GiveUpButton = object::Instantiate<WaveButton>(enums::LAYER::Wall, Vector3(10, 10, 0));

			GiveUpButton->SetType(WaveButton::WaveButtonType::giveup);
			StartButton->SetType(WaveButton::WaveButtonType::start);
		}

		GiveUpButton->Activate();
		StartButton->Activate();

		//reward
		rewardSpawnPos.resize(3);
		rewardSpawnPos[0] = Vector3(-5, 5, 0);
		rewardSpawnPos[1] = Vector3(0, 5, 0);
		rewardSpawnPos[2] = Vector3(5, 5, 0);

		rewards.push_back(L"heal");
		rewards.push_back(L"dmg");
		rewards.push_back(L"firerate");
		rewards.push_back(L"speed");
		rewards.push_back(L"projectile");

		//monster types initialize
		monsters.push_back(L"zombie");
		monsters.push_back(L"turret");
		monsters.push_back(L"bomber");

		bosses.push_back(L"soldier");
		bosses.push_back(L"king");
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
				isGetReward = false;
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
				SpawnReward();
				isClear = false;
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
		if (waveCount % 10 == 0)
		{
			
		}
		else
		{
			Vector3 startPos = Vector3(-3, 8, 0);

			for (int i = 0; i < WaveMonsterCount; i++)
			{			
				std::mt19937 gen(rd());  // to seed mersenne twister.
										 // replace the call to rd() with a
										 // constant value to get repeatable
										 // results.

				Vector3 curPos = startPos;

				unsigned int r = gen();
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
	}
	void WaveManager::SpawnReward()
	{
		//상자 스폰
		std::mt19937 gen(rd());  // to seed mersenne twister.
								 // replace the call to rd() with a
								 // constant value to get repeatable
								 // results.

		int spawned[3] = {};

		for (int i = 0; i < 3; i++)
		{
			unsigned int r = gen(); 
			r %= 5; 

			if (i == 2)
			{
				while (true)
				{
					r = gen();
					r %= 5;

					if (r != spawned[0] && r != spawned[1])
						break;
				}
			}
			else if (i == 1)
			{
				while (r == spawned[0])
				{
					r = gen();
					r %= 5;
				}
			}

			if (rewards[r] == L"heal")
				ya::object::Instantiate<HealBox>(enums::LAYER::Reward, rewardSpawnPos[i]);
			else if (rewards[r] == L"dmg")
				ya::object::Instantiate<DamageUpBox>(enums::LAYER::Reward, rewardSpawnPos[i]);
			else if (rewards[r] == L"firerate")
				ya::object::Instantiate<FireRateUpBox>(enums::LAYER::Reward, rewardSpawnPos[i]);
			else if (rewards[r] == L"speed")
				ya::object::Instantiate<SpeedUpBox>(enums::LAYER::Reward, rewardSpawnPos[i]);
			else if (rewards[r] == L"projectile")
				ya::object::Instantiate<IncreaseProjectileBox>(enums::LAYER::Reward, rewardSpawnPos[i]);

			spawned[i] = r;
		}
	}
	void WaveManager::GiveUp()
	{
		SaveScore();
		SceneManager::LoadScene(L"GameOverScene");
		// 여기서 점수관련 작업
	}
	void WaveManager::SaveScore()
	{
		//최고 점수 읽기
		int prev_max_score = 0;
		std::ifstream ifs;
		ifs.open("score.txt", std::ios::in);
		if (!ifs)
		{
			std::cout << "Error!" << std::endl;
		}
		std::string line;
		int i = 0;
		while (i <= 1)
		{
			getline(ifs, line);
			if (i == 1)
				prev_max_score = stoi(line);
			i++;
		}

		ifs.close();

		//현재 점수 기록 및 최고점수 갱신
		std::ofstream ofs("score.txt", std::ios::out | std::ios::trunc);
		if (ofs.fail())
		{
			std::cout << "Error!" << std::endl;
		}
		ofs << Score;
		ofs << "\n";

		if (Score > prev_max_score)
		{
			ofs << Score;
			ofs << "\n";
		}
		else
		{
			ofs << prev_max_score;
			ofs << "\n";
		}

		ofs.close();
	}
}