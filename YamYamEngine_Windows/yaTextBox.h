#pragma once
#include "yaGameObject.h"
#include "yaText.h"

namespace ya
{
    class TextBox : public GameObject
    {
    public:
		TextBox();
		~TextBox() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void SetText(std::wstring text) { mText->SetText(text); }

	private:
		Text* mText;
    };
}
