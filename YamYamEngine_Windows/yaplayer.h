#pragma once
#include "yaGameObject.h"

namespace ya
{
	class player : public GameObject
	{
	public:
		player();
		~player() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

		int GetShootType() { return ShootType; }
		void SetShootType(int input) { ShootType = input; }

	private:
		
		int		ShootType;


	};
}

