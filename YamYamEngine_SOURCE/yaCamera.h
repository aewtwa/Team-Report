#pragma once
#include "yaGameObject.h"

namespace ya
{
	using namespace math;
	class Camera
	{
	public:
		static void Initialize();
		static void Update();
		static void Clear();

		static Vector3 CalculatePosition(Vector3 pos) { return pos - mDistance; }

		static GameObject* GetTarget() { return mTarget; }
		static void SetTarget(GameObject* target) { mTarget = target; }

	private:
		static Vector3 mResolution;
		static Vector3 mLookPosition;
		static Vector3 mDistance;
		static GameObject* mTarget;
	};
}
