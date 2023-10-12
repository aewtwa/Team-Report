#include "yaTurretScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaTime.h"
#include "yaCamera.h"
#include "yaInput.h"
#include "yaobject.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"
#include "yaMonsterBullet.h"

namespace ya
{
	TurretScript::TurretScript() :
		directions(),
		cur_index(0),
		shoot_time(0.1f),
		change_time(2.f),
		color_palette{},
		palette_index(0)
	{
		color_palette[0] = Vector3(0, 255, 0);
		color_palette[1] = Vector3(255, 165, 0);
		color_palette[2] = Vector3(255, 0, 255);

		for (int i = 0; i < 12; i++)
		{
			directions[i] = Vector2(cos(XMConvertToRadians(30*i)),sin(XMConvertToRadians(30 * i)));
		}
	}
	TurretScript::~TurretScript()
	{
	}
	void TurretScript::Initialize()
	{
	}
	void TurretScript::Update()
	{
		shoot_time -= Time::DeltaTime();
		change_time -= Time::DeltaTime();
		GameObject* obj = GetOwner();
		Transform* turret_tr = obj->GetComponent<Transform>();
		if (shoot_time <= 0.0f)
		{
			shoot_time = 0.1f;
			MonsterBullet* monster_bullet = object::Instantiate<ya::MonsterBullet>(LAYER::Bullet, turret_tr->GetPosition());
			monster_bullet->SetDir(directions[cur_index]);
			monster_bullet->SetColor(color_palette[palette_index]);
			cur_index++;
			if (cur_index > 11)
				cur_index = 0;
		}

		if (change_time <= 0.f)
		{
			change_time = 2.f;
			palette_index++;
			palette_index > 2 ? palette_index = 0 : palette_index = palette_index;
		}

	}

	void TurretScript::LateUpdate()
	{
	}

	void TurretScript::Render()
	{
	}
}