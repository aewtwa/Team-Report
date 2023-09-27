#include "yaPlayScene.h"
#include "yaResources.h"

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
			GameObject* object = new player();
			AddGameObject(object, LAYER::Player);
			Camera::SetTarget(object);
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();
		Camera::Update();
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
