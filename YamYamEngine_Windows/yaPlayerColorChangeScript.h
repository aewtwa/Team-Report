#pragma once
#include "yaScript.h"

namespace ya
{
	class PlayerColorChangeScript : public Script
	{
	public:
		PlayerColorChangeScript();
		virtual ~PlayerColorChangeScript();

		 void Initialize() override;
		 void Update() override;
		 void LateUpdate() override;
		 void Render() override;

	private:

	};
}
