#pragma once
#include "yaRewardBox.h"

namespace ya
{
    class HealBox : public RewardBox
    {
    public:
        HealBox();
        ~HealBox() override;

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render() override;

        void OnCollisionEnter(Collider* other) override;
        void OnCollisionStay(Collider* other) override;
        void OnCollisionExit(Collider* other) override;

        void ReturnReward(player* target) override;

    private:

    };
}
