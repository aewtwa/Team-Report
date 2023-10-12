#include "yaHealBox.h"
#include "yaplayer.h"
#include "yaMeshRenderer.h"

namespace ya
{
	HealBox::HealBox()
	{
	}
	HealBox::~HealBox()
	{
	}
	void HealBox::Initialize()
	{
		RewardBox::Initialize();

		MeshRenderer* mr = GetComponent<MeshRenderer>();
		mr->SetColor(Vector3(255, 0, 0));
	}
	void HealBox::Update()
	{
		RewardBox::Update();
	}
	void HealBox::LateUpdate()
	{
		RewardBox::LateUpdate();
	}
	void HealBox::Render()
	{
		RewardBox::Render();
	}

	void HealBox::OnCollisionEnter(Collider* other)
	{
		RewardBox::OnCollisionEnter(other);
	}
	void HealBox::OnCollisionStay(Collider* other)
	{
		RewardBox::OnCollisionStay(other);
	}
	void HealBox::OnCollisionExit(Collider* other)
	{
		RewardBox::OnCollisionExit(other);
	}

	void HealBox::ReturnReward(player* target)
	{
		target->Heal();
	}
}