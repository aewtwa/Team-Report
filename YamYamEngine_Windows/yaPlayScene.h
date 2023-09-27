#pragma once
#include "..\\YamYamEngine_SOURCE\\yaScene.h"

#include "..\\YamYamEngine_SOURCE\yaobject.h"

namespace ya
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		virtual ~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:
		GameObject* obj;

	};
}
