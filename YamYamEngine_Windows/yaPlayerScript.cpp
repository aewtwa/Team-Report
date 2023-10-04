#include "yaPlayerScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaobject.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaBullet.h"
#include "yaMonster.h"

namespace ya
{

	PlayerScript::PlayerScript()
		: canShoot(true)
		, FireRate(0.15f)
		, prevShootTime(0)
	{
	}

	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
	}

	void PlayerScript::Update()
	{
		GameObject* obj = GetOwner();
		Transform* tr = obj->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		if (Input::GetKey(KEY_CODE::LBTN) && canShoot)
		{
			GameObject* objecti = object::Instantiate<ya::Bullet>(LAYER::Bullet, GetOwner()->GetComponent<Transform>()->GetPosition());
			Vector2 MPos = Input::GetMouseWorldPosition();
			MPos.y *= -1;

			Vector2 dir = MPos - pos;
			dir.normalize();

			dynamic_cast<ya::Bullet*>(objecti)->SetDir(dir);

			canShoot = false;
			prevShootTime = Time::GetTime();
		}
		else if (!canShoot)
		{
			if (prevShootTime + FireRate < Time::GetTime())
				canShoot = true;
		}

		if (Input::GetKeyDown(KEY_CODE::RBTN))
		{
			object::Instantiate<ya::Monster>(LAYER::Monster, /*GetOwner()->GetComponent<Transform>()->GetPosition() +*/ Vector3(10, 0, 0));
		}

		tr->SetPosition(pos);
	}

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render()
	{
	}

}
