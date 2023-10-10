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
			mr->SetColor(Vector3(0, 255, 0));	// �ʷ�
			cur_player->SetShootType(player::ShootType::basic); //��Ÿ�Կ� ���� �÷��̾� ��ũ��Ʈ LBTN Ŭ�� �κп��� ó���� �޶���
		}

		if (Input::GetKeyDown(KEY_CODE::N_2))
		{
			mr->SetColor(Vector3(255, 165, 0));	// ��Ȳ
			cur_player->SetShootType(player::ShootType::shotgun);
		}

		//if (Input::GetKeyDown(KEY_CODE::N_3))
		//{
		//	mr->SetColor(Vector3(0, 0, 0));		// ����
		//	cur_player->SetShootType(2);
		//}
	}
	void PlayerColorChangeScript::LateUpdate()
	{
	}
	void PlayerColorChangeScript::Render()
	{
	}
}