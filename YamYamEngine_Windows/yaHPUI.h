#pragma once
#include "yaUIObject.h"

namespace ya
{
	class HPUI : public UIObject
	{
	public:
		HPUI();
		~HPUI() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:

	};
}

