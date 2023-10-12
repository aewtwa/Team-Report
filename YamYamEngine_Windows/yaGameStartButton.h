#pragma once
#include "yaGameObject.h"

namespace ya
{
    class GameStartButton : public GameObject
    {
    public:
        GameStartButton();
        ~GameStartButton() override;

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render() override;

        void OnCollisionEnter(Collider* other) override;
        void OnCollisionStay(Collider* other) override;
        void OnCollisionExit(Collider* other) override;
        void OnClick() override;

    private:

    };
}
