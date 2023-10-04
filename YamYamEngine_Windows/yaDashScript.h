#pragma once
#include "yaScript.h"

namespace ya
{
	class DashScript : public Script
	{
	public:
		DashScript();
		~DashScript() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:

	};
}
