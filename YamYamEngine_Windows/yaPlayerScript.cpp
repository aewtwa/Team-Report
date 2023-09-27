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

		if (Input::GetKeyDown(KEY_CODE::RBTN))
		{
			GameObject* objecti = object::Instantiate<ya::Bullet>(LAYER::Bullet, GetOwner()->GetComponent<Transform>()->GetPosition());
			//Transform* tr = objecti->GetComponent<Transform>();
			Vector2 MPos = Input::GetMouseWorldPosition();

			Vector2 dir = MPos - pos;
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
