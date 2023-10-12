#include "yaFireRateUpBox.h"
#include "yaplayer.h"
#include "yaMeshRenderer.h"

namespace ya
{
	FireRateUpBox::FireRateUpBox()
	{
	}
	FireRateUpBox::~FireRateUpBox()
	{
	}
	void FireRateUpBox::Initialize()
	{
		RewardBox::Initialize();

		MeshRenderer* mr = GetComponent<MeshRenderer>();
		mr->SetColor(Vector3(255, 0, 0));
	}
	void FireRateUpBox::Update()
	{
		RewardBox::Update();
	}
	void FireRateUpBox::LateUpdate()
	{
		RewardBox::LateUpdate();
	}
	void FireRateUpBox::Render()
	{
		RewardBox::Render();
	}
	void FireRateUpBox::OnCollisionEnter(Collider* other)
	{
		RewardBox::OnCollisionEnter(other);
	}
	void FireRateUpBox::OnCollisionStay(Collider* other)
	{
		RewardBox::OnCollisionStay(other);
	}
	void FireRateUpBox::OnCollisionExit(Collider* other)
	{
		RewardBox::OnCollisionExit(other);
	}

	void FireRateUpBox::ReturnReward(player* target)
	{
		target->SetFireRate(target->GetFireRate() + 0.1f);
	}
}