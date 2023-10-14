#include "yaplayer.h"
#include "yaResources.h"
#include "yaWaveManager.h"
#include "yaShotScript.h"
#include "yaControllerScript.h"
#include "yaPlayerColorChangeScript.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaMeshRenderer.h"
#include "yaText.h"
#include "yaMonsterBullet.h"
#include "yaTime.h"

namespace ya
{
	player::player()
		: HP(3)
		, FireRate(0.3f)
		, MoveSpeed(3.f)
		, PlayerColor(Vector3(0.f,255.f,0.f))
		, mShootType(ShootType::basic)
		, Additional_Fire_Rate(0.f)
		, Projectile_Level(0)
		, Additional_Damage(0.f)
		, is_dead(false)
		, is_invincible(false)
		, invincible_time(1.5f)
	{
		SetTag(enums::TAG::Player);
	}
	player::~player()
	{
	}
	void player::Reset()
	{
		HP = 3;
		is_dead = false;
		is_invincible = false;
		invincible_time = 1.5f;
		mShootType = ShootType::basic;

		FireRate = 0.3f;
		MoveSpeed = 3.f;
		Additional_Damage = 0.0f;
		Additional_Fire_Rate = 0.0f;
		Projectile_Level = 0;
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
		if (invincible_time > 0.f)
		{
			invincible_time -= Time::DeltaTime();
		}
		if (invincible_time > 0.f)
		{
			is_invincible = true;
		}
		else
		{
			invincible_time = 0.f;
			is_invincible = false;
		}
		if (HP <= 0 && !is_dead)
		{
			is_dead = true;
			WaveManager::SaveScore();
		}
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