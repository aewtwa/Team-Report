#pragma once
#include "yaScene.h"
#include "yaTextBox.h"

namespace ya
{
    class GameOverScene : public Scene
    {
    public:
        GameOverScene();
        ~GameOverScene() override;

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render() override;

    private:
        TextBox* curScore;
        TextBox* highScore;

    };
}
