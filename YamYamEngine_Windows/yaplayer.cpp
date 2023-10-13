#include "yaplayer.h"
#include "yaResources.h"
#include "yaShotScript.h"
#include "yaControllerScript.h"
#include "yaPlayerColorChangeScript.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaMeshRenderer.h"
#include "yaText.h"
#include "yaMonsterBullet.h"

namespace ya
{
	player::player()
		: HP(3)
		, FireRate(0.3f)
		, MoveSpeed(3.f)
		, PlayerColor(Vector3(0.f,255.f,0.f))
		, ShootType(ShootType::basic)
		, Additional_Fire_Rate(0.f)
		, Projectile_Level(0)
		, Additional_Damage(0.f)
		, is_dead(false)
	{
		SetTag(enums::TAG::Player);
	}
	player::~player()
	{
	}
	void player::Initialize()
	{
		AddComponent<Transform>();
		Collider* col = AddComponent<Collider>();
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetColor(PlayerColor);
		AddComponent<ShotScript>();
		AddComponent<ControllerScript>();
		AddComponent<PlayerColorChangeScript>();
		text = AddComponent<Text>();
		text->SetText(L"current : " + std::to_wstring(score));

		col->SetSize(Vector2(1.f, 1.f));

		GameObject::Initialize();
	}
	void player::Update()
	{
		text->SetText(L"current : " + std::to_wstring(score));
		if (HP <= 0 && !is_dead)
		{
			is_dead = true;
			SaveScore();
		}
		GameObject::Update();
	}
	void player::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void player::Render()
	{
		GameObject::Render();
	}
	void player::OnCollisionEnter(Collider* other)
	{
		GameObject::OnCollisionEnter(other);
	}
	void player::OnCollisionStay(Collider* other)
	{
		GameObject::OnCollisionStay(other);
	}
	void player::OnCollisionExit(Collider* other)
	{
		GameObject::OnCollisionExit(other);
	}


	void player::SaveScore()
	{
		//최고 점수 읽기
		int prev_max_score = 0;
		std::ifstream ifs;
		ifs.open("score.txt", std::ios::in);
		if (!ifs)
		{
			std::cout << "Error!" << std::endl;
		}
		std::string line;
		int i = 0;
		while (i <= 1)
		{
			getline(ifs, line);
			if (i == 1)
				prev_max_score = stoi(line);
			i++;
		}

		ifs.close();

		//현재 점수 기록 및 최고점수 갱신
		std::ofstream ofs("score.txt", std::ios::out | std::ios::trunc);
		if (ofs.fail())
		{
			std::cout << "Error!" << std::endl;
		}
		ofs << score;
		ofs << "\n";

		if (score > prev_max_score)
		{
			ofs << score;
			ofs << "\n";
		}
		else
		{
			ofs << prev_max_score;
			ofs << "\n";
		}

		ofs.close();
			
	}
}