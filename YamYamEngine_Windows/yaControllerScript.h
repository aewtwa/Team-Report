#pragma once
#include "..\\YamYamEngine_SOURCE\yaScript.h"

namespace ya
{
	class ControllerScript : public Script
	{
	public:
		ControllerScript();
		~ControllerScript() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:
		Vector2 MoveDirection;
		Vector2 PrevMoveDirection;
		bool	canDash;
		bool	Dashing;
		float	DashCoolDown;
		float	PrevDashTime;
		float	DashDistance;
		Vector2	DashStartPos;
		Vector2 DashDirection;

	};
}
