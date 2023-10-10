#pragma once
#include "yaMonster.h"

namespace ya
{
	class Zombie : public Monster
	{
	public:
		Zombie();
		~Zombie() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

	private:
	};
}

