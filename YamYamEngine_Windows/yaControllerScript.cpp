#include "yaControllerScript.h"
#include "yaInput.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaTime.h"
#include "yaplayer.h"

namespace ya
{
	ControllerScript::ControllerScript()
		: canDash(true)
		, Dashing(false)
		, DashCoolDown(1.f)
		, PrevDashTime(0.f)
		, DashDistance(3.f)
		, DashStartPos(Vector2::Zero)
		, MoveDirection(Vector2::Zero)
		, PrevMoveDirection(Vector2::Zero)
		, DashDirection(Vector2::One)
	{
	}
	ControllerScript::~ControllerScript()
	{
	}
	void ControllerScript::Initialize()
	{
	}
	void ControllerScript::Update()
	{
		MoveDirection = Vector2::Zero;
		Transform* tr = GetOwner()->GetComponent<Transform>();
		math::Vector3 pos = tr->GetPosition();
		
		float speed = dynamic_cast<player*>(GetOwner())->GetMoveSpeed();

		if (!Dashing)
		{
			if (Input::GetKey(KEY_CODE::W))
			{
				pos.y += speed * Time::DeltaTime();
				MoveDirection.y += 1;
			}

			if (Input::GetKey(KEY_CODE::A))
			{
				pos.x -= speed * Time::DeltaTime();
				MoveDirection.x -= 1;
			}

			if (Input::GetKey(KEY_CODE::S))
			{
				pos.y -= speed * Time::DeltaTime();
				MoveDirection.y -= 1;
			}

			if (Input::GetKey(KEY_CODE::D))
			{
				pos.x += speed * Time::DeltaTime();
				MoveDirection.x += 1;
			}

			if (PrevMoveDirection != MoveDirection && MoveDirection != Vector2::Zero)
			{
				DashDirection = MoveDirection;
				DashDirection.normalize();
			}
		}

		if (Input::GetKeyDown(KEY_CODE::SPACE) && canDash)
		{
			DashStartPos = (Vector2)GetOwner()->GetComponent<Transform>()->GetPosition();
			canDash = false;
			Dashing = true;
		}
		else if (!canDash && !Dashing)
		{
			if (PrevDashTime + DashCoolDown < Time::GetTime())
			{
				canDash = true;
			}
		}
		else if (Dashing)
		{
			Vector2 length = (pos - DashStartPos);
			if(abs(length.length()) < DashDistance)
				pos += (Vector3)DashDirection * 10.f * Time::DeltaTime();
			else
			{
				Dashing = false;
				PrevDashTime = Time::GetTime();
			}
		}

		tr->SetPosition(pos);
	}
	void ControllerScript::LateUpdate()
	{
	}
	void ControllerScript::Render()
	{
	}
	void ControllerScript::OnCollisionEnter(Collider* other)
	{
		if (other->GetOwner()->GetTag() == TAG::Wall && Dashing)
		{
			Dashing = false;
			PrevDashTime = Time::GetTime();
		}
	}
	void ControllerScript::OnCollisionStay(Collider* other)
	{
		if (other->GetOwner()->GetTag() == TAG::Wall && Dashing)
		{
			Dashing = false;
			PrevDashTime = Time::GetTime();
		}
	}
	void ControllerScript::OnCollisionExit(Collider* other)
	{
	}
}