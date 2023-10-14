#pragma once
#include "yaUIObject.h"

namespace ya
{
    class ScoreUI : public UIObject
    {
    public:
		ScoreUI();
		~ScoreUI() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

    private:

    };
}
