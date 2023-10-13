#pragma once
#include "yaGameObject.h"

namespace ya
{
    class Button : public GameObject
    {
    public:
        Button();
        virtual ~Button() override;

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render() override;

        virtual void OnCollisionEnter(Collider* other) override;
        virtual void OnCollisionStay(Collider* other) override;
        virtual void OnCollisionExit(Collider* other) override;
        virtual void OnClick() override;

    private:

    };
}
