#pragma once
#include "yaButton.h"

namespace ya
{
    class NameInputButton : public Button
    {
    public:
        NameInputButton();
        ~NameInputButton() override;

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render() override;

        void OnCollisionEnter(Collider* other) override;
        void OnCollisionStay(Collider* other) override;
        void OnCollisionExit(Collider* other) override;
        void OnClick() override;

        void SaveName();

    private:
        bool is_clicked;
        int start_index;
        wchar_t input_char;
        std::wstring init_text;
        int max_name_count;
        class Text* text;
    };
}
