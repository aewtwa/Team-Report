#include "yaGameOverScene.h"
#include "yaTextBox.h"

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

		tb1 = new TextBox();
		AddGameObject(tb1, (UINT)LAYER::UI);
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
				}
				break;

			case 1:
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