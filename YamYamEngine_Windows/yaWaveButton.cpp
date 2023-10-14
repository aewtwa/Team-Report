#include "yaWaveButton.h"
#include "yaWaveManager.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaMeshRenderer.h"
#include "yaText.h"

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
		AddComponent<Text>()->SetDynamic();

		GameObject::Initialize();
	}
	void WaveButton::Update()
	{
		GameObject::Update();

		switch (mType)
		{
		case ya::WaveButton::WaveButtonType::start:
			GetComponent<Text>()->SetText(L"Wave Start");
			break;
		case ya::WaveButton::WaveButtonType::giveup:
			GetComponent<Text>()->SetText(L"Give Up");
			break;
		}
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
}