#pragma once
#include "yaScene.h"

namespace ya
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene() override;

		void Initialize() override; 
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:

	};
}
