#pragma once
#include "yaScript.h"

namespace ya
{
	class ShieldScript : public Script
	{
	public:
		ShieldScript(); 
		~ShieldScript() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

		void SetActive(bool value) { isActive = value; }

	private:
		bool isActive;

	};
}
