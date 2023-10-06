#include "yaPlayScene.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaWall.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaRigidbody.h"
#include "yaPlayerScript.h"
#include "yaCamera.h"
#include "yaobject.h"
#include "yaControllerScript.h"
#include "yaplayer.h"
#include "yaColliderManager.h"
#include "yaDoor.h"
#include "yaTurret.h"
#include "yaHPBar.h"

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
		// 敲饭捞绢 积己
		{
			player* play = object::Instantiate<ya::player>(LAYER::Player, Vector3(0, 0, 0));
			Camera::SetTarget(play);
			obj = play;
		}

		// 寒 积己
		{
			for (int i = -32; i <= 32; i++)
			{
				object::Instantiate<ya::Wall>(LAYER::Wall, Vector3(i, 18, 0));
				object::Instantiate<ya::Wall>(LAYER::Wall, Vector3(i, -18, 0));
			}

			for (int i = -18; i <= 18; i++)
			{
				object::Instantiate<ya::Wall>(LAYER::Wall, Vector3(32, i, 0));
				object::Instantiate<ya::Wall>(LAYER::Wall, Vector3(-32, i, 0));
			}
		}

		{
			object::Instantiate<Door>(LAYER::Wall, Vector3(1, 1, 1));
		}

		//磐房 积己
		{
			object::Instantiate<Turret>(LAYER::Monster, Vector3(2, 2, 0));
		}

		{
			object::Instantiate<HPBar>(LAYER::UI, Vector3(-12, -8, 1));
		}

		ColliderManager::CollisionLayerCheck(LAYER::Player, LAYER::Wall, true);
		ColliderManager::CollisionLayerCheck(LAYER::Bullet, LAYER::Wall, true);
		ColliderManager::CollisionLayerCheck(LAYER::Bullet, LAYER::Monster, true);
	}

	void PlayScene::Update()
	{
		Scene::Update();
		Camera::Update();

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
