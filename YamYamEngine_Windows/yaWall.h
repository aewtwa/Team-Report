#pragma once
#include "..\YamYamEngine_SOURCE\yaGameObject.h"

namespace ya
{
	class Wall : public GameObject
	{
	public:
		Wall();
		~Wall() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

		void SetIsVertical(bool value) { isVertical = value; }

	private:
		bool isVertical;
		
	};
}