#include "yaZombie.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaZombieScript.h"

namespace ya
{
	Zombie::Zombie() : Monster(3)
	{
	}

	Zombie::~Zombie()
	{
	}

	void Zombie::Initialize()
	{
		AddComponent<Transform>();
		AddComponent<Collider>();
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetColor(Vector4(96, 0x4b, 0x00, 0.f));

		AddComponent<ZombieScript>();
		GameObject::Initialize();
	}

	void Zombie::Update()
	{
		Monster::Update();
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
		Monster::OnCollisionEnter(other);
	}

	void Zombie::OnCollisionStay(Collider* other)
	{
	}

	void Zombie::OnCollisionExit(Collider* other)
	{
	}

}