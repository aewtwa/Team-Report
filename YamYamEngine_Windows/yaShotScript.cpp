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
		//, shield(nullptr)
	{
	}

	ShotScript::~ShotScript()
	{
	}

	void ShotScript::Initialize()
	{
		//shield = object::Instantiate<Shield>(enums::LAYER::Player)->GetScript<ShieldScript>();
		//shield->SetShieldTarget(GetOwner());
	}

	void ShotScript::Update()
	{
		GameObject* obj = GetOwner();
		Transform* tr = obj->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		GameObject* objecti = nullptr;

		player* cur_player = dynamic_cast<player*>(obj);

		if (Input::GetKey(KEY_CODE::LBTN) && canShoot && !Input::GetKey(KEY_CODE::RBTN))
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

				canShoot = false;
				prevShootTime = Time::GetTime();
				break;
			case 1:
				dir = MPos - Camera::CalculatePosition(pos);
				dir.normalize();

				cur_radian = atan2(dir.y, dir.x);

				cur_radian -= 0.26;

				for (int i = 0; i < 3; i++)
				{
					Vector2 cur_dir = Vector2(cos(cur_radian), sin(cur_radian));
					GameObject* shotgun_bullet = object::Instantiate<ya::ShotgunBullet>(LAYER::Bullet, GetOwner()->GetComponent<Transform>()->GetPosition());
					ShotgunBullet* cur_bullet = dynamic_cast<ya::ShotgunBullet*>(shotgun_bullet);
					cur_bullet->SetDir(cur_dir);
					cur_bullet->SetStartPos(obj->GetComponent<Transform>()->GetPositionVec2());
					cur_radian += 0.26;
				}

				canShoot = false;
				prevShootTime = Time::GetTime();
				break;
			case 2:
				objecti = object::Instantiate<ya::RpgBullet>(LAYER::Bullet, GetOwner()->GetComponent<Transform>()->GetPosition());
				dir = MPos - Camera::CalculatePosition(pos);
				dir.normalize();

				dynamic_cast<ya::RpgBullet*>(objecti)->SetDir(dir);
				dynamic_cast<ya::RpgBullet*>(objecti)->SetMaxDistance(Vector2(5.f,5.f));
				dynamic_cast<ya::RpgBullet*>(objecti)->SetStartPos(Vector2(pos));
				
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

		//if (Input::GetKey(KEY_CODE::RBTN))
		//{
		//	//object::Instantiate<ya::Monster>(LAYER::Monster, Vector3(10, 0, 0)); // spawn monster

		//	shield->SetActive(true);
		//}
		//else if (!Input::GetKey(KEY_CODE::RBTN))
		//{
		//	shield->SetActive(false);
		//}

		tr->SetPosition(pos);
	}

	void ShotScript::LateUpdate()
	{
	}

	void ShotScript::Render()
	{
	}

}
