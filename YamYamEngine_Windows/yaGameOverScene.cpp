#include "yaGameOverScene.h"
#include "yaTextBox.h"
#include "yaTransform.h"

namespace ya
{
	GameOverScene::GameOverScene()
	{
	}
	GameOverScene::~GameOverScene()
	{
	}
	void GameOverScene::Initialize()
	{
		Scene::Initialize();

		curScore = new TextBox();
		AddGameObject(curScore, (UINT)LAYER::UI);
		curScore->SetStatic();
		curScore->GetComponent<Transform>()->SetPositionVec2(Vector2(0, 1));

		highScore = new TextBox();
		AddGameObject(highScore, (UINT)LAYER::UI);
		highScore->SetStatic();
		highScore->GetComponent<Transform>()->SetPositionVec2(Vector2(0, 3));
	}
	void GameOverScene::Update()
	{
		Scene::Update();

		int prev_max_score = 0;
		std::ifstream ifs;
		ifs.open("score.txt", std::ios::in);
		if (!ifs)
		{
			std::cout << "Error!" << std::endl;
		}
		std::string line;
		int i = 0;
		while (i <= 1)
		{
			getline(ifs, line);
			
			switch (i)
			{
			case 0:
				{
					prev_max_score = stoi(line);
					curScore->SetText(L"Your Score : " + std::to_wstring(prev_max_score));
				}
				break;

			case 1:
				{
					prev_max_score = stoi(line);
					highScore->SetText(L"High Score : " + std::to_wstring(prev_max_score));
				}
				break;

			}
			i++; 
		}

		ifs.close();
	}
	void GameOverScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void GameOverScene::Render()
	{
		Scene::Render();
	}
}