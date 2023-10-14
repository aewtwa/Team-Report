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

    private:
        bool is_clicked;
    };
}
