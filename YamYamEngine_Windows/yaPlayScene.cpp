#include "yaPlayScene.h"
#include "yaResources.h"

#include "..\YamYamEngine_SOURCE\yaInput.h"

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
		{
			obj = new player();
			GameObject* object = obj;
			AddGameObject(object, LAYER::Player);
			Camera::SetTarget(object);
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
