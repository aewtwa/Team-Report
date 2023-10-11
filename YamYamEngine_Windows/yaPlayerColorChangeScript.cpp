#include "yaPlayerColorChangeScript.h"
#include "yaInput.h"
#include "yaGameObject.h"
#include "yaMeshRenderer.h"
#include "yaplayer.h"

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
		GameObject* obj = GetOwner();
		player* cur_player = dynamic_cast<player*>(obj);


		if (Input::GetKeyDown(KEY_CODE::N_1))
		{
			mr->SetColor(Vector3(0, 255, 0));	// 초록
			cur_player->SetPlayerColor(Vector3(0, 255, 0));
			cur_player->SetShootType(player::ShootType::basic); //슛타입에 따라 플레이어 스크립트 LBTN 클릭 부분에서 처리가 달라짐
		}

		if (Input::GetKeyDown(KEY_CODE::N_2))
		{
			mr->SetColor(Vector3(255, 165, 0));	// 주황
			cur_player->SetPlayerColor(Vector3(255, 165, 0));
			cur_player->SetShootType(player::ShootType::shotgun);
		}

		if (Input::GetKeyDown(KEY_CODE::N_3))
		{
			mr->SetColor(Vector3(0xff, 0, 0xff));		// 마젠타
			cur_player->SetPlayerColor(Vector3(0xff, 0, 0xff));
			cur_player->SetShootType(player::ShootType::rpg);
		}
	}
	void PlayerColorChangeScript::LateUpdate()
	{
	}
	void PlayerColorChangeScript::Render()
	{
	}
}