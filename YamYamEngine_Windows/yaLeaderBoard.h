#pragma once
#include "yaButton.h"

namespace ya
{
    class LeaderBoard : public Button
    {
    public:
        LeaderBoard();
        virtual ~LeaderBoard() override;

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render() override;

        void ReadAllScoreBoard();

        void OnCollisionEnter(Collider* other) override;
        void OnCollisionStay(Collider* other) override;
        void OnCollisionExit(Collider* other) override;

    private:
        std::vector<std::wstring> lines;
        std::vector<int> scores;
        std::vector<int> aligns;
        std::map<int, std::wstring> ranks;
        int cur_index;
        int capacity;
        class GameObject* text_list[10];
    };
}
