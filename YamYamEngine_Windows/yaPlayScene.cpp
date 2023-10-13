#include "yaPlayScene.h"

#include "yaResources.h"
#include "yaInput.h"
#include "yaWaveManager.h"
#include "yaobject.h"
#include "yaCamera.h"
#include "yaColliderManager.h"

#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaControllerScript.h"

#include "yaplayer.h"
#include "yaWall.h"

#include "yaHPBar.h"
#include "yaSpeedUI.h"
#include "yaFireRateUI.h"
#include "yaExtraDamageUI.h"
#include "yaScoreUI.h"

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

		// 敲饭捞绢 积己
		{
			player* play = object::Instantiate<ya::player>(LAYER::Player, Vector3(0, 0, 0));
			Camera::SetTarget(play);
			obj = play;
		}

		// 寒 积己
		{
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

		// UI 积己
		{
			HPBar* hb = new HPBar;
			AddGameObject(hb, (UINT)LAYER::UI);
			hb->GetComponent<Transform>()->SetPosition(Vector3(-12, -8, 1));
			hb->SetTarget(dynamic_cast<player*>(obj));

			SpeedUI* speedui = new SpeedUI;
			AddGameObject(speedui, (UINT)LAYER::UI);
			speedui->SetTarget(dynamic_cast<player*>(obj));

			FireRateUI* frui = new FireRateUI;
			AddGameObject(frui, (UINT)LAYER::UI);
			frui->SetTarget(dynamic_cast<player*>(obj));

			ExtraDamageUI* edui = new ExtraDamageUI;
			AddGameObject(edui, (UINT)LAYER::UI);
			edui->SetTarget(dynamic_cast<player*>(obj));

			ScoreUI* scoreui = new ScoreUI();
			AddGameObject(scoreui, (UINT)LAYER::UI);
			scoreui->SetTarget(dynamic_cast<player*>(obj));
		}

		ColliderManager::CollisionLayerCheck(LAYER::Player, LAYER::Wall, true);
		ColliderManager::CollisionLayerCheck(LAYER::Bullet, LAYER::Wall, true);
		ColliderManager::CollisionLayerCheck(LAYER::Bullet, LAYER::Monster, true);
		ColliderManager::CollisionLayerCheck(LAYER::Bullet, LAYER::Player, true);
	}

	void PlayScene::Setting()
	{
		dynamic_cast<player*>(obj)->Reset();
		Camera::SetTarget(obj);
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
