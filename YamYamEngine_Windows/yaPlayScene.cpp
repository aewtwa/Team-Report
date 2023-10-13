#include "yaPlayScene.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaWaveManager.h"
#include "yaWall.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaRigidbody.h"
#include "yaCamera.h"
#include "yaobject.h"
#include "yaControllerScript.h"
#include "yaplayer.h"
#include "yaColliderManager.h"
#include "yaTurret.h"
#include "yaHPBar.h"
#include "yaZombie.h"
#include "yaBomber.h"
#include "yaSoldier.h"
#include "yaDamageUpBox.h"
#include "yaFireRateUpBox.h"
#include "yaIncreaseProjectileBox.h"
#include "yaKing.h"

namespace ya
{
	PlayScene::PlayScene()
	{
	}


	PlayScene::~PlayScene()
	{

	}

	void PlayScene::Initialize()
	{
		//ColliderManager::SetRender(true);
		WaveManager::SetActivate(true);

		// �÷��̾� ����
		{
			player* play = object::Instantiate<ya::player>(LAYER::Player, Vector3(0, 0, 0));
			Camera::SetTarget(play);
			obj = play;
		}

		// �� ����
		{
			/*for (int i = -32; i <= 32; i++)
			{
				object::Instantiate<ya::Wall>(LAYER::Wall, Vector3(i, 18, 0));
				object::Instantiate<ya::Wall>(LAYER::Wall, Vector3(i, -18, 0));
			}

			for (int i = -18; i <= 18; i++)
			{
				object::Instantiate<ya::Wall>(LAYER::Wall, Vector3(32, i, 0));
				object::Instantiate<ya::Wall>(LAYER::Wall, Vector3(-32, i, 0));
			}*/

			Wall* w1 = object::Instantiate<Wall>(LAYER::Wall, Vector3(16, 0, 0));
			Wall* w2 = object::Instantiate<Wall>(LAYER::Wall, Vector3(0, 16, 0));
			Wall* w3 = object::Instantiate<Wall>(LAYER::Wall, Vector3(-16, 0, 0));
			Wall* w4 = object::Instantiate<Wall>(LAYER::Wall, Vector3(0, -16, 0));

			w1->SetIsVertical(true);
			w3->SetIsVertical(true);

			w1->GetComponent<Transform>()->SetScale(Vector3(1, 31, 1));
			w2->GetComponent<Transform>()->SetScale(Vector3(33, 1, 1));
			w3->GetComponent<Transform>()->SetScale(Vector3(1, 31, 1));
			w4->GetComponent<Transform>()->SetScale(Vector3(33, 1, 1));

			w1->GetComponent<Collider>()->SetSize(Vector2(1, 31));
			w2->GetComponent<Collider>()->SetSize(Vector2(33, 1));
			w3->GetComponent<Collider>()->SetSize(Vector2(1, 31));
			w4->GetComponent<Collider>()->SetSize(Vector2(33, 1));
		}

		//�ͷ� ����
		/*{
			object::Instantiate<Turret>(LAYER::Monster, Vector3(2, 2, 0));
		}*/

		//���� ����
		//{
		//	for (int i = 0; i < 5; i++)
		//	{
		//		//object::Instantiate<Zombie>(LAYER::Monster, Vector3(2, i * 3, 0));
		//	}	
		//}

		//������ ����
		//object::Instantiate<Bomber>(LAYER::Monster, Vector3(5, 5, 0));


		//���� ��ġ(�׽�Ʈ)
		//object::Instantiate<Soldier>(LAYER::Monster, Vector3(5, 5, 0));


		/*�׽�Ʈ�� ������*/
	/*	{
			for (int i = 0; i < 5; i++)
			{
				object::Instantiate<IncreaseProjectileBox>(LAYER::Monster, Vector3(5, i, 0));
			}

		
		}

		{
			object::Instantiate<King>(LAYER::Monster, Vector3(1, 1, 0));
		}


		{
			object::Instantiate<HPBar>(LAYER::UI, Vector3(-12, -8, 1));
		}*/



		ColliderManager::CollisionLayerCheck(LAYER::Player, LAYER::Wall, true);
		ColliderManager::CollisionLayerCheck(LAYER::Bullet, LAYER::Wall, true);
		ColliderManager::CollisionLayerCheck(LAYER::Bullet, LAYER::Monster, true);
		ColliderManager::CollisionLayerCheck(LAYER::Bullet, LAYER::Player, true);
	}

	void PlayScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(KEY_CODE::N))
		{
			if (Camera::GetTarget() == nullptr)
				Camera::SetTarget(obj);
			else
				Camera::SetTarget(nullptr);
		}
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render()
	{
		Scene::Render();
	}
}
