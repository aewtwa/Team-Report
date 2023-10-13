#pragma once
#include "yaUIObject.h"
#include "yaplayer.h"

namespace ya
{
    class FireRateUI : public UIObject
    {
    public:
		FireRateUI();
		~FireRateUI() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void SetTarget(player* p) { target = p; }

	private:
		player* target;

    };
}
