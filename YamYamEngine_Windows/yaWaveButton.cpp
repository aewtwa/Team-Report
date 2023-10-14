#include "yaWaveButton.h"
#include "yaWaveManager.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaMeshRenderer.h"

namespace ya
{
	WaveButton::WaveButton()
		: mType(WaveButtonType::none)
	{
		SetTag(TAG::Wall);
	}
	WaveButton::~WaveButton()
	{
	}
	void WaveButton::Initialize()
	{
		AddComponent<Transform>();
		AddComponent<Collider>();
		AddComponent<MeshRenderer>();

		GameObject::Initialize();
	}
	void WaveButton::Update()
	{
		GameObject::Update();
	}
	void WaveButton::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void WaveButton::Render()
	{
		GameObject::Render();
	}
	void WaveButton::OnCollisionEnter(Collider* other)
	{
		GameObject::OnCollisionEnter(other);

		if (other->GetOwner()->GetTag() == TAG::Player)
		{
			if(mType == WaveButtonType::start)
				WaveManager::WaveStart();
			else if (mType == WaveButtonType::giveup)
				WaveManager::GiveUp();
		}
	}
	void WaveButton::OnCollisionStay(Collider* other)
	{
		GameObject::OnCollisionStay(other);
	}
	void WaveButton::OnCollisionExit(Collider* other)
	{
		GameObject::OnCollisionExit(other);
	}
	void WaveButton::SetType(WaveButtonType type)
	{
		mType = type;

		if (mType == WaveButtonType::start)
			GetComponent<MeshRenderer>()->SetColor(Vector3(0, 255, 100));
		else if (mType == WaveButtonType::giveup)
			GetComponent<MeshRenderer>()->SetColor(Vector3(255, 0, 0));
	}
}