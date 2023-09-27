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

namespace ya
{

	PlayerScript::PlayerScript()
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

		if (Input::GetKeyDown(KEY_CODE::LBTN))
		{
			GameObject* objecti = object::Instantiate<ya::Bullet>(LAYER::Bullet, GetOwner()->GetComponent<Transform>()->GetPosition());
			//Transform* tr = objecti->GetComponent<Transform>();
			Vector2 Pos = Input::GetMousPosition();
			Vector3 vPos = GetOwner()->GetComponent<Transform>()->GetPosition();
			Pos.x -= 1600 / 2;
			Pos.y -= 900 / 2;

			Vector2 dir = Pos - vPos;
			dir.y *= -1;
			dir.normalize();

			dynamic_cast<ya::Bullet*>(objecti)->SetDir(dir);

			//tr->SetPosition(vPos);
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
