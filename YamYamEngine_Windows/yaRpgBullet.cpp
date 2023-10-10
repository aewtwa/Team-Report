#include "yaRpgBullet.h"
#include "yaResources.h"
#include "yaTime.h"
#include "yaCamera.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaMeshRenderer.h"
#include "yaInput.h"
#include "yaBullet.h"
#include "yaobject.h"

namespace ya
{
	RpgBullet::RpgBullet()
	{
		startPos = Vector2::Zero;
		maxDistance = Vector2::Zero;
		for (int i = 0; i < 30; i++)
		{
			explode_directions[i] = Vector2(cos(XMConvertToRadians(12 * i)), sin(XMConvertToRadians(12 * i)));
		}
	}


	RpgBullet::~RpgBullet()
	{
	}


	void RpgBullet::Initialize()
	{
		Transform* tr = AddComponent<Transform>();
		tr->SetScale(Vector3(1.0f, 1.0f, 1.f));
		Collider* col = AddComponent<Collider>();
		col->SetSize(Vector2(1.0f, 1.0f));
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetColor(Vector4(0.f, 0.f, 255.f, 0.f));
		GameObject::Initialize();
	}


	void RpgBullet::Update()
	{
		GameObject::Update();
		Transform* tr = GetComponent<Transform>();
		Vector3 cur_pos = tr->GetPosition();
		math::Vector2 pos = (Vector2)tr->GetPosition();


		pos += mDirection * 10.f * Time::DeltaTime();

		tr->SetPosition((Vector3)pos);

		if (maxDistance != Vector2::Zero)
		{
			if (abs(startPos.x - pos.x) > maxDistance.x ||
				abs(startPos.y - pos.y) > maxDistance.y)
			{
				for (int i = 0; i < 20; i++)
				{
					//Bullet* bulletObj = object::Instantiate<Bullet>(LAYER::Bullet, cur_pos);
					//bulletObj->SetDir(explode_directions[i]);
					//bulletObj->SetStartPos((Vector2)cur_pos);
					//bulletObj->SetMaxDistance((Vector2)(3.f));
				}
				Destroy(this);
			}
		}
	}


	void RpgBullet::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void RpgBullet::Render()
	{
		GameObject::Render();
	}


	void RpgBullet::OnCollisionEnter(Collider* other)
	{
	}
	void RpgBullet::OnCollisionStay(Collider* other)
	{
	}
	void RpgBullet::OnCollisionExit(Collider* other)
	{
	}
}