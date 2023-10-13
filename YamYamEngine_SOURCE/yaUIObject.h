#pragma once
#include "yaGameObject.h"

namespace ya
{
	class UIObject : public GameObject
	{
	public:
		UIObject();
		virtual ~UIObject() override;

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

	private:

	};
}
