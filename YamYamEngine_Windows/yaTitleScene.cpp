#include "yaTitleScene.h"
#include "yaColliderManager.h"
#include "yaobject.h"
#include "yaGameStartButton.h"
#include "yaExitButton.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaText.h"

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
		GameStartButton* sbtn = new GameStartButton();
		AddGameObject(sbtn, (UINT)LAYER::UI);

		ExitButton* ebtn = new ExitButton();
		AddGameObject(ebtn, (UINT)LAYER::UI);
		ebtn->GetComponent<Transform>()->SetPositionVec2(Vector2(0, -4));
		ebtn->AddComponent<MeshRenderer>();
		//ebtn->GetComponent<Text>()->SetOffset(Vector2(0, 50));

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