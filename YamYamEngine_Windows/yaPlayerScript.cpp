#include "yaPlayerScript.h"
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

namespace ya
{

	PlayerScript::PlayerScript()
		: canShoot(true)
		, FireRate(0.3f)
		, prevShootTime(0)
		//, shield(nullptr)
	{
	}

	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
		//shield = object::Instantiate<Shield>(enums::LAYER::Player)->GetScript<ShieldScript>();
		//shield->SetShieldTarget(GetOwner());
	}

	void PlayerScript::Update()
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

			switch (cur_player->GetShootType())
			{
			case 0:
				objecti = object::Instantiate<ya::Bullet>(LAYER::Bullet, GetOwner()->GetComponent<Transform>()->GetPosition());
				dir.normalize();

				dynamic_cast<ya::Bullet*>(objecti)->SetDir(dir);

				canShoot = false;
				prevShootTime = Time::GetTime();
				break;
			case 1:
				MPos = Input::GetMouseWorldPosition();
				MPos.y *= -1;
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
					cur_bullet->SetPlayerPos(obj->GetComponent<Transform>()->GetPositionVec2());
					cur_radian += 0.26;
				}

				canShoot = false;
				prevShootTime = Time::GetTime();
				break;
			case 2:
				break;
			default:
				break;
			}
		
		}
		else if (!canShoot)
		{
			if (prevShootTime + FireRate < Time::GetTime())
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

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render()
	{
	}

}
