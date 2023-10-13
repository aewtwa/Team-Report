#include "yaRewardBox.h"
#include "yaWaveManager.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaMeshRenderer.h"
#include "yaSceneManager.h"
#include "yaplayer.h"

namespace ya
{
	RewardBox::RewardBox()
	{
	}
	RewardBox::~RewardBox()
	{
	}
	void RewardBox::Initialize()
	{
		AddComponent<Transform>();
		AddComponent<Collider>();
		AddComponent<MeshRenderer>();

		GameObject::Initialize();
	}
	void RewardBox::Update()
	{
		GameObject::Update();

		if (WaveManager::IsRewardSelected())
			Destroy(this);
	}
	void RewardBox::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void RewardBox::Render()
	{
		GameObject::Render();
	}
	void RewardBox::OnCollisionEnter(Collider* other)
	{
		GameObject::OnCollisionEnter(other);

		if (other->GetOwner()->GetTag() == TAG::PlayerBullet)
		{
			ReturnReward(dynamic_cast<player*>(SceneManager::GetActiveScene()->GetPlayer()));
			WaveManager::ChooseReward();
			Destroy(this);
		}
	}
	void RewardBox::OnCollisionStay(Collider* other)
	{
		GameObject::OnCollisionStay(other);
	}
	void RewardBox::OnCollisionExit(Collider* other)
	{
		GameObject::OnCollisionExit(other);
	}
}