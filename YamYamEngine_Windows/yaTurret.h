#pragma once
#include "yaMonster.h"

namespace ya
{
	class Turret : public Monster
	{
	public:
		Turret();
		~Turret() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

	private:
		class Transform* tr;
		class MeshRenderer* mr;
		class Collider* col;
	};
}

