#include "yaplayer.h"
#include "yaResources.h"
#include "yaShotScript.h"
#include "yaControllerScript.h"
#include "yaPlayerColorChangeScript.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaMeshRenderer.h"
#include "yaMonsterBullet.h"

namespace ya
{
	player::player()
		: HP(3)
		, FireRate(0.3f)
		, MoveSpeed(3.f)
		, PlayerColor(Vector3(0.f,255.f,0.f))
		, ShootType(ShootType::basic)
		, Additional_Fire_Rate(0.f)
		, Projectile_Level(0)
		, Additional_Damage(0.f)
	{
		SetTag(enums::TAG::Player);
	}
	player::~player()
	{
	}
	void player::Initialize()
	{
		AddComponent<Transform>();
		Collider* col = AddComponent<Collider>();
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetColor(PlayerColor);
		AddComponent<ShotScript>();
		AddComponent<ControllerScript>();
		AddComponent<PlayerColorChangeScript>();

		col->SetSize(Vector2(1.f, 1.f));

		GameObject::Initialize();
	}
	void player::Update()
	{
		GameObject::Update();
	}
	void player::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void player::Render()
	{
		GameObject::Render();
	}
	void player::OnCollisionEnter(Collider* other)
	{
		GameObject::OnCollisionEnter(other);
	}
	void player::OnCollisionStay(Collider* other)
	{
		GameObject::OnCollisionStay(other);
	}
	void player::OnCollisionExit(Collider* other)
	{
		GameObject::OnCollisionExit(other);
	}
}