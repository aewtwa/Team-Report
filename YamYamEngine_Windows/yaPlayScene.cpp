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
		// 플레이어 생성
		{
			obj = new player();
			GameObject* object = obj;
			AddGameObject(object, LAYER::Player);
			Camera::SetTarget(object);
		}

		// 벽 생성
		{			
			GameObject* object = new ya::Wall();
			AddGameObject(object, LAYER::Wall);
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
