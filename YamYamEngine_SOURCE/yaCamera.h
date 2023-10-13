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
		static Vector2 CalculatePositionApi(Vector2 pos) { return pos - mDistanceApi; }

		static GameObject* GetTarget() { return mTarget; }
		static void SetTarget(GameObject* target) { mTarget = target; }

		static Vector2 GetResolution() { return mResolution; }

	private:
		static Vector2 mResolution;
		static Vector3 mLookPosition;
		static Vector3 mDistance;
		static Vector2 mDistanceApi;
		static GameObject* mTarget;
	};
}
