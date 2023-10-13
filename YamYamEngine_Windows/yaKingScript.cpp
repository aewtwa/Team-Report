#include "yaKingScript.h"
#include "yaTransform.h"
#include "yaSceneManager.h"
#include "yaScene.h"
#include "yaTime.h"
#include "yaMonsterBullet.h"
#include "yaobject.h"


namespace ya
{
	KingScript::KingScript() :
		mTarget(nullptr)
		, shot_time(KING_SHOT_TIME)
		, move_time(KING_MOVE_TIME)
		, speed(KING_SPEED)
		, cur_state(KingState::Following)
		, origin_pos(Vector3::Zero)
		, Color_Palette{}
		, cur_color_index(0)
		, cur_degree(0)
		, is_left(false)
		, first_attack_time(FIRST_ATTACK_TIME)
		, first_bullet_index(0)
		, second_attack_count(SECOND_ATTACK_COUNT)
		, second_attack_time(SECOND_ATTACK_TIME)
		, second_iter_time(SECOND_ITER_TIME)
	{
		Color_Palette[0] = Vector3(0, 255, 0);
		Color_Palette[1] = Vector3(255, 165, 0);
		Color_Palette[2] = Vector3(255, 0, 255);

	}
	KingScript::~KingScript()
	{
	}
	void KingScript::Initialize()
	{
	}
	void KingScript::Update()
	{
		if (mTarget == nullptr)
			FindTarget();

		switch (cur_state)
		{
		case ya::KingState::Following:
			MoveToTarget();
			break;
		case ya::KingState::RoundMoving:
			RoundMoving();
			RoundShoot();
			break;
		case ya::KingState::FirstAttack:
			FirstAttack();
			break;
		case ya::KingState::SecondAttack:
			SecondAttack();
			break;
		case ya::KingState::Freeze:
			break;
		}

	}
	void KingScript::LateUpdate()
	{
	}
	void KingScript::Render()
	{
	}
	void KingScript::FindTarget()
	{
		GameObject* player = SceneManager::GetActiveScene()->GetPlayer();
		if (player != nullptr)
		{
			mTarget = player;
			return;
		}
	}
	void KingScript::MoveToTarget()
	{
		Vector2 pPos = (Vector2)mTarget->GetComponent<Transform>()->GetPosition(); //player Position
		Vector2 mPos = (Vector2)GetOwner()->GetComponent<Transform>()->GetPosition(); //monster Position

		Vector2 dir = pPos - mPos;
		dir.normalize();

		mPos += dir * speed * Time::DeltaTime();
		GetOwner()->GetComponent<Transform>()->SetPosition((Vector3)mPos);
		origin_pos = GetOwner()->GetComponent<Transform>()->GetPosition();

		move_time -= Time::DeltaTime();

		if (move_time <= 0.f)
		{
			move_time = KING_MOVE_TIME;
			cur_state = KingState::RoundMoving;
			cur_degree = XMConvertToDegrees(atan2(dir.y, dir.x));
		}


	}

	void KingScript::Shoot()
	{
		Vector2 pPos = (Vector2)mTarget->GetComponent<Transform>()->GetPosition(); //player Position
		Vector3 mPos = GetOwner()->GetComponent<Transform>()->GetPosition(); //monster Position

		Vector2 dir = pPos - (Vector2)mPos;
		dir.normalize(); // 플레이어를 바라보는 방향 벡터

		MonsterBullet* monsterBullet = object::Instantiate<MonsterBullet>(LAYER::Bullet, mPos);
		monsterBullet->SetDir(dir);

	}

	void KingScript::ManualShoot(Vector2 dir, Vector3 color)
	{
		Vector3 mPos = GetOwner()->GetComponent<Transform>()->GetPosition();
		MonsterBullet* monsterBullet = object::Instantiate<MonsterBullet>(LAYER::Bullet, mPos);
		monsterBullet->SetDir(dir);
		monsterBullet->SetColor(color);
	}



	void KingScript::RoundShoot()
	{
		Vector2 pPos = (Vector2)mTarget->GetComponent<Transform>()->GetPosition(); //player Position
		Vector3 mPos = GetOwner()->GetComponent<Transform>()->GetPosition(); //monster Position

		Vector2 dir = pPos - (Vector2)mPos;
		dir.normalize(); // 플레이어를 바라보는 방향 벡터

		MonsterBullet* monsterBullet = object::Instantiate<MonsterBullet>(LAYER::Bullet, mPos);
		monsterBullet->SetDir(dir);
		is_left ? monsterBullet->SetColor(Color_Palette[2]) : monsterBullet->SetColor(Color_Palette[1]);
	}

	void KingScript::ShotgunShoot()
	{

		Vector2 pPos = (Vector2)mTarget->GetComponent<Transform>()->GetPosition(); //player Position
		Vector3 mPos = GetOwner()->GetComponent<Transform>()->GetPosition(); //monster Position

		Vector2 dir = pPos - (Vector2)mPos;
		dir.normalize(); // 플레이어를 바라보는 방향 벡터

		Vector2 left_dir = Vector2(dir.x - 0.16f, dir.y - 0.16f);
		Vector2 right_dir = Vector2(dir.x + 0.16f, dir.y + 0.16f);
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(0, 99);
		unsigned int color_index = 0;

		for (int i = 0; i < 3; i++)
		{
			MonsterBullet* monsterBullet = object::Instantiate<MonsterBullet>(LAYER::Bullet, mPos);
			switch (i)
			{
			case 0:
				color_index = dis(gen) % 3;
				monsterBullet->SetDir(left_dir);
				monsterBullet->SetColor(Color_Palette[color_index]);
				break;
			case 1:
				color_index = dis(gen) % 3;
				monsterBullet->SetDir(dir);
				monsterBullet->SetColor(Color_Palette[color_index]);
				break;
			case 2:
				color_index = dis(gen) % 3;
				monsterBullet->SetDir(right_dir);
				monsterBullet->SetColor(Color_Palette[color_index]);
				break;
			}

		}

	}


	void KingScript::FirstAttack()
	{
		first_attack_time -= Time::DeltaTime();
		cur_degree = 0;
		first_attacak_degree += Time::DeltaTime() * 100.f;

		if (is_left)
		{
			for (int i = 0; i < 4; i++)
			{
				Vector2 dir = Vector2(cos(XMConvertToRadians(cur_degree + i * 90 + first_attacak_degree)), sin(XMConvertToRadians(cur_degree + i * 90 + first_attacak_degree)));
				i > 2 ? ManualShoot(dir, Color_Palette[i - 1]) : ManualShoot(dir, Color_Palette[i]);
				cur_degree += i * 90;
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				Vector2 dir = Vector2(cos(XMConvertToRadians(cur_degree + i * 90 - first_attacak_degree)), sin(XMConvertToRadians(cur_degree + i * 90 - first_attacak_degree)));
				i > 2 ? ManualShoot(dir, Color_Palette[i - 1]) : ManualShoot(dir, Color_Palette[i]);
				cur_degree += i * 90;
			}
		}


		if (first_attack_time <= 0.f)
		{
			is_left = !is_left;
			first_attacak_degree = 0;
			first_attack_time = FIRST_ATTACK_TIME;
			cur_state = KingState::SecondAttack;
		}
	}

	void KingScript::SecondAttack()
	{
		second_attack_time -= Time::DeltaTime();

		if (second_attack_time <= 0.f)
		{
			second_attack_count = SECOND_ATTACK_COUNT;
			second_attack_time = SECOND_ATTACK_TIME;
			second_iter_time = SECOND_ITER_TIME;
			cur_state = KingState::Following;
			return;
		}

		else
		{
			second_iter_time -= Time::DeltaTime();
			if (second_iter_time <= 0.f)
			{
				ShotgunShoot();
				second_iter_time = SECOND_ITER_TIME;
			}
		}


	}

	void KingScript::RoundMoving()
	{
		Vector3 pPos = mTarget->GetComponent<Transform>()->GetPosition();
		Vector3 mPos = GetOwner()->GetComponent<Transform>()->GetPosition(); //monster Position

		/*round_distance = 3.f * Time::DeltaTime();*/
		round_distance = sqrt(pow(abs(pPos.x - mPos.x) , 2) + pow(abs(pPos.y - mPos.y),2));

		move_time -= Time::DeltaTime();


		mPos.x = pPos.x + cos(XMConvertToRadians(cur_degree)) * round_distance;
		mPos.y = pPos.y + sin(XMConvertToRadians(cur_degree)) * round_distance;


		if (cur_degree >= 360.f)
		{
			cur_degree = 0.f;
		}
		if (cur_degree <= 0.f)
		{
			cur_degree = 360.f;
		}

		GetOwner()->GetComponent<Transform>()->SetPosition(mPos);

		is_left ? cur_degree += 120.f * Time::DeltaTime() : cur_degree -= 120.f * Time::DeltaTime();

		if (move_time <= 0.f)
		{
			move_time = KING_MOVE_TIME;
			cur_state = KingState::FirstAttack;
			round_distance = 0.f;
			cur_degree = 0.f;
			is_left = !is_left;
		}
	}
}