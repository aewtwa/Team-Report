#pragma once
#include "yaEntity.h"

namespace ya
{
	class Text : Entity
	{
	public:
		Text();
		virtual ~Text() override;

		void Initialize();
		void Render();

		void SetString(std::wstring input) { text = input; }

	private:
		std::wstring text;

	};

}

