#include "yaNameInputButton.h"
#include "yaApplication.h"
#include "yaTransform.h"
#include "yaCollider.h"
#include "yaText.h"
#include "yaInput.h"

extern ya::Application application;

namespace ya
{
	NameInputButton::NameInputButton() :
		  is_clicked(false)
		, start_index(7)
		, input_char(0)
		, init_text(L"Name : ")
		, text(nullptr)
		, max_name_count(10)
	{
	}
	NameInputButton::~NameInputButton()
	{
	}
	void NameInputButton::Initialize()
	{
		Button::Initialize();

		GetComponent<Collider>()->SetSize(Vector2(3, 1));
		text = GetComponent<Text>();
		text->SetText(init_text);
		text->SetStatic();
	}
	void NameInputButton::Update()
	{
		if (is_clicked && max_name_count >= 0)
		{
			for (int i = 0; i < 26; i++)
			{
				if (Input::GetKeyDown((KEY_CODE)i))
				{
					input_char = (wchar_t)Input::GetASCII((KEY_CODE)i);
				}
	
			}
			if (input_char != 0)
			{
				init_text += input_char;
				max_name_count--;
				input_char = 0;
			}
		}
		text->SetText(init_text);
		SaveName();
		Button::Update();
	}
	void NameInputButton::LateUpdate()
	{
		Button::LateUpdate();
	}
	void NameInputButton::Render()
	{
		Button::Render();
	}
	void NameInputButton::OnCollisionEnter(Collider* other)
	{
		Button::OnCollisionEnter(other);
	}
	void NameInputButton::OnCollisionStay(Collider* other)
	{
		Button::OnCollisionEnter(other);
	}
	void NameInputButton::OnCollisionExit(Collider* other)
	{
		Button::OnCollisionEnter(other);
	}
	void NameInputButton::OnClick()
	{
		Button::OnClick();
		is_clicked = true;
	}

	void NameInputButton::SaveName()
	{
		std::string cur_name;
		for (int i = 7; i < init_text.size(); i++)
		{
			cur_name += init_text[i];
		}

		std::ofstream ofs("name.txt", std::ios::out | std::ios::trunc);
		if (ofs.fail())
		{
			std::cout << "Error!" << std::endl;
		}
		ofs << cur_name;
		ofs << "\n";

		ofs.close();
	}

}