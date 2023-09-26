#pragma once
#include "..\\YamYamEngine_SOURCE\yaScript.h"

namespace ya
{
	class ControllerScript : public Script
	{
	public:
		ControllerScript();
		~ControllerScript() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;


	private:

	};
}
