#include "yaShieldScript.h"
#include "yaInput.h"
#include "yaCamera.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"

namespace ya
{
	ShieldScript::ShieldScript()
		:isActive(false)
	{
	}
	ShieldScript::~ShieldScript()
	{
	}
	void ShieldScript::Initialize()
	{
	}
	void ShieldScript::Update()
	{
		if (isActive)
		{
			Vector3 pos = ShieldTarget->GetComponent<Transform>()->GetPosition();
			Vector2 MPos = Input::GetMouseWorldPosition();
			Vector2 dir = MPos - Camera::CalculatePosition(pos);
			dir.y *= -1;
			dir.normalize();

			GetOwner()->GetComponent<Transform>()->SetPositionVec2(pos + (dir * 2));
		}
	}
	void ShieldScript::LateUpdate()
	{
	}
	void ShieldScript::Render()
	{
	}
	void ShieldScript::OnCollisionEnter(Collider* other)
	{
	}
	void ShieldScript::OnCollisionStay(Collider* other)
	{
	}
	void ShieldScript::OnCollisionExit(Collider* other)
	{
	}
	void ShieldScript::SetActive(bool value)
	{
		isActive = value;
		if (!value)
		{
			GetOwner()->GetComponent<Transform>()->SetActivate(false);
			GetOwner()->GetComponent<Collider>()->SetActivate(false);
			GetOwner()->GetComponent<MeshRenderer>()->SetActivate(false);
		}
		else
		{
			GetOwner()->GetComponent<Transform>()->SetActivate(true);
			GetOwner()->GetComponent<Collider>()->SetActivate(true);
			GetOwner()->GetComponent<MeshRenderer>()->SetActivate(true);
		}
	}
}