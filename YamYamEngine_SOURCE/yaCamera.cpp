#include "yaCamera.h"
#include "yaApplication.h"
#include "yaInput.h"
#include "yaTransform.h"
#include "yaTime.h"

extern ya::Application application;

namespace ya
{
	Vector2 Camera::mResolution = Vector2::Zero;
	Vector3 Camera::mLookPosition = Vector3::Zero;
	Vector3 Camera::mDistance = Vector3::Zero;
	Vector2 Camera::mDistanceApi = Vector2::Zero;
	GameObject* Camera::mTarget = nullptr;

	void Camera::Initialize()
	{
		Clear();
	}
	void Camera::Update()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();

		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
			mDistance = mLookPosition;
		}

		mDistanceApi = mLookPosition - (mResolution / 2);
	}
	void Camera::Clear()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = Vector3::Zero;
		mTarget = nullptr;
		mDistance = Vector3::Zero;
	}
}