#pragma once
#include "..\\YamYamEngine_SOURCE\\yaScript.h"

namespace ya
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		virtual ~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:
		bool	canShoot;
		float	FireRate;
		float	prevShootTime;
	};

}
