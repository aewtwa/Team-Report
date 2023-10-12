#include "yaIncreaseProjectileBox.h"
#include "yaplayer.h"
#include "yaMeshRenderer.h"

namespace ya
{
	IncreaseProjectileBox::IncreaseProjectileBox()
	{
	}
	IncreaseProjectileBox::~IncreaseProjectileBox()
	{
	}
	void IncreaseProjectileBox::Initialize()
	{
		RewardBox::Initialize();

		MeshRenderer* mr = GetComponent<MeshRenderer>();
		mr->SetColor(Vector3(0, 255, 0));
	}
	void IncreaseProjectileBox::Update()
	{
		RewardBox::Update();
	}
	void IncreaseProjectileBox::LateUpdate()
	{
		RewardBox::LateUpdate();
	}
	void IncreaseProjectileBox::Render()
	{
		RewardBox::Render();
	}
	void IncreaseProjectileBox::OnCollisionEnter(Collider* other)
	{
		RewardBox::OnCollisionEnter(other);
	}
	void IncreaseProjectileBox::OnCollisionStay(Collider* other)
	{
		RewardBox::OnCollisionStay(other);
	}
	void IncreaseProjectileBox::OnCollisionExit(Collider* other)
	{
		RewardBox::OnCollisionExit(other);
	}

	void IncreaseProjectileBox::ReturnReward(player* target)
	{
		target->SetProjectile_Level(target->GetProjectile_Level() + 1);
	}
}