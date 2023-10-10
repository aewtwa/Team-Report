#include "yaZombie.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaZombieScript.h"

namespace ya
{
	Zombie::Zombie()
	{
		SetTag(enums::TAG::Monster);
	}

	Zombie::~Zombie()
	{
	}

	void Zombie::Initialize()
	{
		AddComponent<Transform>();
		AddComponent<Collider>();
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetColor(Vector4(255.f, 0.f, 0.f, 0.f));

		AddComponent<ZombieScript>();
		GameObject::Initialize();
	}

	void Zombie::Update()
	{
		GameObject::Update();
	}

	void Zombie::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Zombie::Render()
	{
		GameObject::Render();
	}

	void Zombie::OnCollisionEnter(Collider* other)
	{
		if (other->GetOwner()->GetTag() == TAG::PlayerBullet)
		{
			Destroy(this);
		}
	}

	void Zombie::OnCollisionStay(Collider* other)
	{
	}

	void Zombie::OnCollisionExit(Collider* other)
	{
	}

}