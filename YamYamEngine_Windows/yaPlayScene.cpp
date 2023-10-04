#include "yaPlayScene.h"
#include "yaResources.h"
#include "..\YamYamEngine_SOURCE\yaInput.h"
#include "yaWall.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaRigidbody.h"
#include "yaPlayerScript.h"
#include "..\\YamYamEngine_SOURCE\\yaCamera.h"
#include "..\\YamYamEngine_SOURCE\yaobject.h"
#include "yaControllerScript.h"
#include "yaplayer.h"

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
