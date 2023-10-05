#pragma once
#include "yaScript.h"

namespace ya
{

	class TurretScript : public Script
	{
	public:
		TurretScript();
		virtual ~TurretScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:
		float directions[12];
	};

}
