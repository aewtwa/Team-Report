#pragma once
#include "yaMonster.h"

namespace ya
{
	class Bomber : public Monster
	{
	public:
		Bomber();
		~Bomber() override;

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

