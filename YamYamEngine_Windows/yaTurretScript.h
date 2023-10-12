#pragma once
#include "yaScript.h"

namespace ya
{

	class TurretScript : public Script
	{
	public:
		TurretScript();
		virtual ~TurretScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:
		Vector2 directions[12];
		int cur_index;
		float shoot_time;
		float change_time;
		Vector3 color_palette[3];
		int palette_index;
	};

}
