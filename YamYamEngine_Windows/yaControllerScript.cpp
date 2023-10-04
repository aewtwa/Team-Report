#include "yaControllerScript.h"
#include "..\\YamYamEngine_SOURCE\yaInput.h"
#include "..\\YamYamEngine_SOURCE\yaGameObject.h"
#include "..\\YamYamEngine_SOURCE\yaTransform.h"
#include "..\\YamYamEngine_SOURCE\yaTime.h"

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
		, DashDirection(Vector2::Zero)
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
		
		if (!Dashing)
		{
			if (Input::GetKey(KEY_CODE::W))
			{
				pos.y += 3.f * Time::DeltaTime();
				MoveDirection.y += 1;
			}

			if (Input::GetKey(KEY_CODE::A))
			{
				pos.x -= 3.f * Time::DeltaTime();
				MoveDirection.x -= 1;
			}

			if (Input::GetKey(KEY_CODE::S))
			{
				pos.y -= 3.f * Time::DeltaTime();
				MoveDirection.y -= 1;
			}

			if (Input::GetKey(KEY_CODE::D))
			{
				pos.x += 3.f * Time::DeltaTime();
				MoveDirection.x += 1;
			}

			DashDirection = MoveDirection;
			DashDirection.normalize();
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
			Vector2 length = pos - DashStartPos;
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
}