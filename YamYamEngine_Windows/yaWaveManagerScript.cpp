#include "yaWaveManagerScript.h"
#include <cmath>
#include "yaobject.h"

namespace ya
{
	WaveManagerScript::WaveManagerScript()
		: StartCall(false)
		, inWave(false)
		, isClear(false)
		, waveCount(0)
		, curMonsterCount(0)
		, prevMonsterCount(0)
	{
	}
	WaveManagerScript::~WaveManagerScript()
	{
	}
	void WaveManagerScript::Initialize()
	{
	}
	void WaveManagerScript::Update()
	{
		if (StartCall)
		{
			WaveStart();
			StartCall = false;
		}
	}
	void WaveManagerScript::LateUpdate()
	{
	}
	void WaveManagerScript::Render()
	{
	}

	void WaveManagerScript::WaveStart()
	{
		waveCount++;
		prevMonsterCount = curMonsterCount;
		curMonsterCount = (prevMonsterCount + 3) * ceil(waveCount % 10);
		inWave = true;

		for (int i = 0; i < curMonsterCount; i++)
		{
			ya::object::Instantiate<>(enums::LAYER::Monster, );
		}
	}
	void WaveManagerScript::GiveUp()
	{

	}
}