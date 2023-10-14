#include "yaTitleScene.h"
#include "yaColliderManager.h"
#include "yaobject.h"
#include "yaGameStartButton.h"
#include "yaExitButton.h"
#include "yaNameInputButton.h"
#include "yaLeaderBoard.h"
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

		NameInputButton* nitn = new NameInputButton();
		AddGameObject(nitn, (UINT)LAYER::UI);
		nitn->GetComponent<Transform>()->SetPositionVec2(Vector2(4,-4));

		ExitButton* ebtn = new ExitButton();
		AddGameObject(ebtn, (UINT)LAYER::UI);
		ebtn->GetComponent<Transform>()->SetPositionVec2(Vector2(0, -4));

		LeaderBoard* leader = new LeaderBoard();
		AddGameObject(leader, (UINT)LAYER::UI);
		leader->GetComponent<Transform>()->SetPositionVec2(Vector2(-10, 5));

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