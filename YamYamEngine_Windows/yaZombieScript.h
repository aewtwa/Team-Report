#pragma once
#include "yaScript.h"

namespace ya
{
	class ZombieScript : public Script
	{
	public:
		ZombieScript();
		~ZombieScript() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void FindTarget();
		void MoveToTarget();
		void Shoot();

	private:
		GameObject* mTarget;
		float speed;
		float shot_time;
	};
}
