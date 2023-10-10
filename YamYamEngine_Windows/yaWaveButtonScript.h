#pragma once
#include "yaScript.h"

namespace ya
{
	class WaveButtonScript : public Script
	{
	public:
		WaveButtonScript();
		~WaveButtonScript() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

	private:
		bool isActivate;

	};
}