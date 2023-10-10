#pragma once
#include "yaGameObject.h"

namespace ya
{
	class WaveButton : public GameObject
	{
	public:
		enum class WaveButtonType
		{
			start,
			giveup,
			none,
		};

		WaveButton();
		~WaveButton() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

		void SetType(WaveButtonType type) { mType = type; }

	private:
		WaveButtonType mType;

	};
}
