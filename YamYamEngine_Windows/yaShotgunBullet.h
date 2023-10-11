#pragma once
#include "yaBullet.h"

namespace ya
{
	class ShotgunBullet : public Bullet
	{
	public:
		ShotgunBullet();
		~ShotgunBullet() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:
	};
}
