#include "yaShotgunBullet.h"
#include "yaResources.h"
#include "yaTime.h"
#include "yaCamera.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaMeshRenderer.h"
#include "yaInput.h"


namespace ya
{
	ShotgunBullet::ShotgunBullet()
	{
	}
	ShotgunBullet::~ShotgunBullet()
	{
	}
	void ShotgunBullet::Initialize()
	{
		Transform* tr = AddComponent<Transform>();
		tr->SetScale(Vector3(0.5f, 0.5f, 1.f));
		Collider* col = AddComponent<Collider>();
		col->SetSize(Vector2(0.5f, 0.5f));
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetColor(Vector4(0.f, 0.f, 255.f, 0.f));

		GameObject::Initialize();
	}
	void ShotgunBullet::Update()
	{
		GameObject::Update();
		Transform* tr = GetComponent<Transform>();
		Vector2 cur_pos = tr->GetPositionVec2();
		if (abs(cur_pos.x - startPos.x) > 6.f || abs(cur_pos.y - startPos.y) > 6.f)
			Destroy(this);
		math::Vector2 pos = (Vector2)tr->GetPosition();

		pos += mDirection * 10.f * Time::DeltaTime();

		tr->SetPosition((Vector3)pos);
	}
	void ShotgunBullet::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void ShotgunBullet::Render()
	{
		GameObject::Render();
	}
}