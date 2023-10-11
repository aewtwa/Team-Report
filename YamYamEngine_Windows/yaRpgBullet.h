#pragma once
#include "yaBullet.h"

namespace ya
{
	class RpgBullet : public Bullet
	{
	public:
		RpgBullet();
		~RpgBullet() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:
		Vector2 explode_directions[30];
	};
}
