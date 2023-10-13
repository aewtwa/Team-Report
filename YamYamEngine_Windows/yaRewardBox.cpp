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
		Transform* tr = AddComponent<Transform>();
		tr->SetScale(Vector3(0.75f, 0.75f, 0.75f));
		Collider* col = AddComponent<Collider>();
		col->SetSize(Vector2(0.75f, 0.75f));
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

		if (other->GetOwner()->GetTag() == TAG::Player)
		{
			ReturnReward(dynamic_cast<player*>(other->GetOwner()));
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