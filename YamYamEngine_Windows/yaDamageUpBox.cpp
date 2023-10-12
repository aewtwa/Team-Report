#include "yaDamageUpBox.h"
#include "yaplayer.h"
#include "yaMeshRenderer.h"

namespace ya
{
	DamageUpBox::DamageUpBox()
	{
	}
	DamageUpBox::~DamageUpBox()
	{
	}
	void DamageUpBox::Initialize()
	{
		RewardBox::Initialize();

		MeshRenderer* mr = GetComponent<MeshRenderer>();
		mr->SetColor(Vector3(255, 0, 0));
	}
	void DamageUpBox::Update()
	{
		RewardBox::Update();
	}
	void DamageUpBox::LateUpdate()
	{
		RewardBox::LateUpdate();
	}
	void DamageUpBox::Render()
	{
		RewardBox::Render();
	}
	void DamageUpBox::OnCollisionEnter(Collider* other)
	{
		RewardBox::OnCollisionEnter(other);
	}
	void DamageUpBox::OnCollisionStay(Collider* other)
	{
		RewardBox::OnCollisionStay(other);
	}
	void DamageUpBox::OnCollisionExit(Collider* other)
	{
		RewardBox::OnCollisionExit(other);
	}

	void DamageUpBox::ReturnReward(player* target)
	{

	}
}