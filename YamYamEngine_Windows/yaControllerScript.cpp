#include "yaControllerScript.h"
#include "..\\YamYamEngine_SOURCE\yaInput.h"
#include "..\\YamYamEngine_SOURCE\yaGameObject.h"
#include "..\\YamYamEngine_SOURCE\yaTransform.h"
#include "..\\YamYamEngine_SOURCE\yaTime.h"

namespace ya
{
	ControllerScript::ControllerScript()
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
		Transform* tr = GetOwner()->GetComponent<Transform>();
		math::Vector3 pos = tr->GetPosition();

		if (Input::GetKey(KEY_CODE::W))
		{
			pos.y += 3.f * Time::DeltaTime();
		}

		if (Input::GetKey(KEY_CODE::A))
		{
			pos.x -= 3.f * Time::DeltaTime();
		}

		if (Input::GetKey(KEY_CODE::S))
		{
			pos.y -= 3.f * Time::DeltaTime();
		}

		if (Input::GetKey(KEY_CODE::D))
		{
			pos.x += 3.f * Time::DeltaTime();
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