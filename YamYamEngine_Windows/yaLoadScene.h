#pragma once
#include "yaSceneManager.h"
#include "yaPlayScene.h"
#include "yaTitleScene.h"
#include "yaGameOverScene.h"


//#ifdef  _DEBUG
//#pragma comment(lib, "..\\x64\\Debug\\YamYamEngine_Windows.lib")
//#else
//#pragma comment(lib, "..\\x64\\Release\\YamYamEngine_Windows.lib")
//#endif //  _DEBUG

namespace ya
{
	 void InitializeScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<GameOverScene>(L"GameOverScene");

		SceneManager::LoadScene(L"TitleScene");
	}
}