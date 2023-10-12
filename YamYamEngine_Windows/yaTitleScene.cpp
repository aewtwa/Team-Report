#include "yaTitleScene.h"
#include "yaColliderManager.h"
#include "yaobject.h"
#include "yaGameStartButton.h"

namespace ya
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Initialize()
	{
		GameStartButton* obj = new GameStartButton();
		AddGameObject(obj, (UINT)LAYER::UI);

		ColliderManager::MouseCollisionLayerCheck(LAYER::UI, true);
	}
	void TitleScene::Update()
	{
		Scene::Update();
	}
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void TitleScene::Render()
	{
		Scene::Render();
	}
}