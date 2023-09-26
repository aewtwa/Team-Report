#include "yaCamera.h"
#include "yaApplication.h"
#include "yaInput.h"
#include "yaTransform.h"
#include "yaTime.h"

extern ya::Application application;

namespace ya
{
	Vector3 Camera::mResolution = Vector3::Zero;
	Vector3 Camera::mLookPosition = Vector3::Zero;
	Vector3 Camera::mDistance = Vector3::Zero;
	Vector3 Camera::mtestResoulution = Vector3::Zero;
	GameObject* Camera::mTarget = nullptr;

	void Camera::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = mResolution / 2.0f;
	}
	void Camera::Update()
	{
		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}

		mDistance = mLookPosition;
	}
	void Camera::Clear()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = mResolution / 2.0f;
	}
}