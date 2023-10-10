#pragma once
#include "yaScript.h"

namespace ya
{
	class BomberScript : public Script
	{
	public:
		BomberScript();
		~BomberScript() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void FindTarget();
		void MoveToTarget();
		void Explode();

	private:
		GameObject* ownObj;
		GameObject* mTarget;
		float speed;
		float explode_time;
		Vector2 directions[30];
	};
}
