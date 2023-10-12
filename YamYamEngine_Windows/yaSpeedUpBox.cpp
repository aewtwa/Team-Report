#include "yaSpeedUpBox.h"
#include "yaplayer.h"
#include "yaMeshRenderer.h"

namespace ya
{
	SpeedUpBox::SpeedUpBox()
	{
	}
	SpeedUpBox::~SpeedUpBox()
	{
	}
	void SpeedUpBox::Initialize()
	{
		RewardBox::Initialize();

		MeshRenderer* mr = GetComponent<MeshRenderer>();
		mr->SetColor(Vector3(0, 0, 255));
	}
	void SpeedUpBox::Update()
	{
		RewardBox::Update();
	}
	void SpeedUpBox::LateUpdate()
	{
		RewardBox::LateUpdate();
	}
	void SpeedUpBox::Render()
	{
		RewardBox::Render();
	}
	void SpeedUpBox::OnCollisionEnter(Collider* other)
	{
		RewardBox::OnCollisionEnter(other);
	}
	void SpeedUpBox::OnCollisionStay(Collider* other)
	{
		RewardBox::OnCollisionStay(other);
	}
	void SpeedUpBox::OnCollisionExit(Collider* other)
	{
		RewardBox::OnCollisionExit(other);
	}

	void SpeedUpBox::ReturnReward(player* target)
	{
		target->SetMoveSpeed(target->GetMoveSpeed() + 1.2f);
	}
}