#include "yaLeaderBoard.h"
#include "yaApplication.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaText.h"

extern ya::Application application;


namespace ya
{
	LeaderBoard::LeaderBoard()
	{
		lines = {};
		scores = {};
		aligns = {};
		cur_index = 0;
		capacity = 0;
		ranks = {};
		for (int i = 0; i < 10; i++)
		{
			text_list[i] = nullptr;
		}
	}

	LeaderBoard::~LeaderBoard()
	{
	}
	void LeaderBoard::Initialize()
	{
		Button::Initialize();

		AddComponent<Transform>();

		Text* text = GetComponent<Text>();
		text->SetText(L" Leader board ");
		text->SetStatic();
		for (int i = 0; i < 10; i++)
		{
			text_list[i] = new GameObject;
			text_list[i]->AddComponent<Transform>();
			Text* text = text_list[i]->AddComponent<Text>();
			text->SetText(std::to_wstring(i + 1) + L".");
			text->SetOffset(Vector2(-12.f, 5.f - (i + 1)));
			text->SetStatic();
		}

		ReadAllScoreBoard();

	}
	void LeaderBoard::Update()
	{
		Button::Update();
		for (int i = 0; i < 10; i++)
		{
			text_list[i]->Update();
		}
	}
	void LeaderBoard::LateUpdate()
	{
		Button::LateUpdate();
		for (int i = 0; i < 10; i++)
		{
			text_list[i]->LateUpdate();
		}
	}
	void LeaderBoard::Render()
	{
		Button::Render();
		for (int i = 0; i < 10; i++)
		{
			text_list[i]->Render();
		}
	}
	void LeaderBoard::ReadAllScoreBoard()
	{
		std::ifstream ifs;
		int line_num = 0;
		ifs.open("records.txt", std::ios::in);
		if (!ifs)
		{
			std::cout << "Error!" << std::endl;
		}
		std::string line;
		while (getline(ifs, line))
		{
			lines.push_back(std::wstring().assign(line.begin(), line.end()));
			std::size_t pos = line.find(' ');
			int score = stoi(line.substr(0, pos));
			scores.push_back(score);
			std::string name = line.substr(pos + 1, line.size());
			std::wstring w_name = std::wstring().assign(name.begin(),name.end());
			
			ranks.insert(std::make_pair(score, w_name));

		}

		ifs.close();

		sort(scores.begin(), scores.end());
		reverse(scores.begin(), scores.end());
		
		auto iter = scores.begin();
		for (iter; iter != scores.end(); iter++)
		{
			if (capacity <= 9)
			{
				std::wstring name = ranks.find(*iter)->second;
				text_list[capacity]->GetComponent<Text>()->SetText(std::to_wstring(capacity + 1) + L"." + name);
				capacity++;
			}
		}

		int a = 0;

	}
	void LeaderBoard::OnCollisionEnter(Collider* other)
	{
	}
	void LeaderBoard::OnCollisionStay(Collider* other)
	{
	}
	void LeaderBoard::OnCollisionExit(Collider* other)
	{
	}
}