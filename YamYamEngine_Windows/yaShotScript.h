#pragma once
#include "yaScript.h"
#include "yaShieldScript.h"

namespace ya
{
	class ShotScript : public Script
	{
	public:
		ShotScript();
		virtual ~ShotScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:
		bool	canShoot;
		float	prevShootTime;

		//ShieldScript* shield;
	};

}
