#include "yaShotScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaTime.h"
#include "yaCamera.h"
#include "yaInput.h"
#include "yaobject.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaBullet.h"
#include "yaMonster.h"
#include "yaplayer.h"
#include "yaShotgunBullet.h"
#include "yaShield.h"
#include "yaRpgBullet.h"

namespace ya
{

	ShotScript::ShotScript()
		: canShoot(true)
		, prevShootTime(0)
	{
	}

	ShotScript::~ShotScript()
	{
	}

	void ShotScript::Initialize()
	{

	}

	void ShotScript::Update()
	{
		GameObject* obj = GetOwner();
		Transform* tr = obj->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		GameObject* objecti = nullptr;

		player* cur_player = dynamic_cast<player*>(obj);
		float additional_damage = cur_player->GetAdditionalDamage();
		int proj_level = cur_player->GetProjectile_Level();

		if (Input::GetKey(KEY_CODE::LBTN) && canShoot)
		{
			Vector2 MPos = Input::GetMouseWorldPosition();
			MPos.y *= -1;
			Vector2 dir = MPos - Camera::CalculatePosition(pos);
			float cur_radian = 0.f;

			switch ((int)cur_player->GetShootType())
			{
			case 0:
				objecti = object::Instantiate<ya::Bullet>(LAYER::Bullet, GetOwner()->GetComponent<Transform>()->GetPosition());
				dir.normalize();

				dynamic_cast<ya::Bullet*>(objecti)->SetDir(dir);
				dynamic_cast<ya::Bullet*>(objecti)->SetDamage(dynamic_cast<ya::Bullet*>(objecti)->GetDamage() + additional_damage);
				canShoot = false;
				prevShootTime = Time::GetTime();
				break;
			case 1:
				dir = MPos - Camera::CalculatePosition(pos);
				dir.normalize();

				cur_radian = atan2(dir.y, dir.x);

				cur_radian -= 0.26;

				for (int i = 0; i < 3 + proj_level; i++)
				{
					Vector2 cur_dir = Vector2(cos(cur_radian), sin(cur_radian));
					GameObject* shotgun_bullet = object::Instantiate<ya::ShotgunBullet>(LAYER::Bullet, GetOwner()->GetComponent<Transform>()->GetPosition());
					ShotgunBullet* cur_bullet = dynamic_cast<ya::ShotgunBullet*>(shotgun_bullet);
					cur_bullet->SetDir(cur_dir);
					cur_bullet->SetStartPos(obj->GetComponent<Transform>()->GetPositionVec2());
					cur_bullet->SetDamage(cur_bullet->GetDamage() + additional_damage);
					cur_radian += 0.16;
				}

				canShoot = false;
				prevShootTime = Time::GetTime();
				break;
			case 2:
				objecti = object::Instantiate<ya::RpgBullet>(LAYER::Bullet, GetOwner()->GetComponent<Transform>()->GetPosition());
				dir = MPos - Camera::CalculatePosition(pos);
				dir.normalize();

				dynamic_cast<ya::RpgBullet*>(objecti)->SetDir(dir);
				dynamic_cast<ya::RpgBullet*>(objecti)->SetMaxDistance(Vector2(5.f + proj_level,5.f + proj_level));
				dynamic_cast<ya::RpgBullet*>(objecti)->SetStartPos(Vector2(pos));
				dynamic_cast<ya::RpgBullet*>(objecti)->SetDamage(dynamic_cast<ya::RpgBullet*>(objecti)->GetDamage() + additional_damage);
				
				canShoot = false;
				prevShootTime = Time::GetTime();
				break;
			default:
				break;
			}
		
		}
		else if (!canShoot)
		{
			if (prevShootTime + dynamic_cast<player*>(GetOwner())->GetFireRate() < Time::GetTime())
				canShoot = true;
		}

		tr->SetPosition(pos);
	}

	void ShotScript::LateUpdate()
	{
	}

	void ShotScript::Render()
	{
	}

}
