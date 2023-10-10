#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Monster : public GameObject
	{
	public:
		Monster();
		virtual ~Monster() override;

		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void LateUpdate() = 0;
		virtual void Render() = 0;

	private:

	};
}