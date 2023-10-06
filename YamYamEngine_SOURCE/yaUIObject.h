#pragma once
#include "yaGameObject.h"

namespace ya
{
	class UIObject : public GameObject
	{
	public:
		UIObject();
		~UIObject() override;

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
