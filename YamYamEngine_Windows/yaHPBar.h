#pragma once
#include "yaGameObject.h"
#include "yaplayer.h"

namespace ya
{
	class HPBar : public GameObject
	{
	public:
		HPBar();
		~HPBar() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void SetTarget(player* p) { target = p; }

	private:
		player* target;

	};
}
