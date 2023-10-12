#pragma once
#include "yaGameObject.h"

namespace ya
{
    class player;
    class RewardBox : public GameObject
    {
    public:
        RewardBox();
        virtual ~RewardBox() override;

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render() override;

        virtual void OnCollisionEnter(Collider* other) override;
        virtual void OnCollisionStay(Collider* other) override;
        virtual void OnCollisionExit(Collider* other) override;

        virtual void ReturnReward(player* target) = 0;

    private:

    };
}
