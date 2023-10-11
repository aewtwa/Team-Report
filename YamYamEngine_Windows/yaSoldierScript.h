#pragma once
#include "yaScript.h"

namespace ya
{

	class SoldierScript : public Script
	{
	public:
		SoldierScript();
		virtual ~SoldierScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void FindTarget();
		void MoveToTarget();
		void Shoot();
		void MoveAround();

	private:
		GameObject* mTarget;
		float shot_time;
		float move_time;
		float speed;
		bool is_left;
		Vector3 origin_pos;
	};

}
