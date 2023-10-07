#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Shield : public GameObject
	{
	public:
		Shield();
		~Shield() override;

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
