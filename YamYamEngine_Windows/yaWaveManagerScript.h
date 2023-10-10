#pragma once
#include "yaScript.h"

namespace ya
{
	class WaveManagerScript : public Script
	{
	public:
		WaveManagerScript();
		~WaveManagerScript() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:

	};
}
