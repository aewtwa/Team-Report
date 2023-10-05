#include "yaPlayerColorChangeScript.h"
#include "yaInput.h"
#include "yaGameObject.h"
#include "yaMeshRenderer.h"

namespace ya
{
	PlayerColorChangeScript::PlayerColorChangeScript()
	{
	}
	PlayerColorChangeScript::~PlayerColorChangeScript()
	{
	}
	void PlayerColorChangeScript::Initialize()
	{
	}
	void PlayerColorChangeScript::Update()
	{
		MeshRenderer* mr = GetOwner()->GetComponent<MeshRenderer>();

		if (Input::GetKeyDown(KEY_CODE::N_1))
		{
			mr->SetColor(Vector3(0, 255, 0));	// 초록
		}

		if (Input::GetKeyDown(KEY_CODE::N_2))
		{
			mr->SetColor(Vector3(255, 165, 0));	// 주황
		}

		if (Input::GetKeyDown(KEY_CODE::N_3))
		{
			mr->SetColor(Vector3(0, 0, 0));		// 검정
		}
	}
	void PlayerColorChangeScript::LateUpdate()
	{
	}
	void PlayerColorChangeScript::Render()
	{
	}
}