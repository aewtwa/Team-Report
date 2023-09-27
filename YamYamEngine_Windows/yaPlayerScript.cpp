#include "yaPlayerScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaobject.h"
#include "yaMeshRenderer.h"
#include "yaResources.h"

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
			GameObject* objecti = object::Instantiate<GameObject>(Bullet);
			Transform* tr = objecti->AddComponent<Transform>();
			Vector2 Pos = Input::GetMousPosition();
			Vector3 vPos = {};
			Pos.x /= 1600;
			Pos.y /= 900;
			vPos.x = Pos.x;
			vPos.y = Pos.y;
			vPos.z = 0.0f;
			tr->SetPosition(vPos);

			MeshRenderer* meshRenderer = objecti->AddComponent<MeshRenderer>();
			meshRenderer->SetMesh(Resources::Find<Mesh>(L"TriangleMesh"));
			meshRenderer->SetShader(Resources::Find<Shader>(L"TriangleShader"));

			objecti->AddComponent<Collider>();
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
