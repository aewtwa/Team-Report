﻿#include "yaRigidbody.h"
#include "yaTime.h"
#include "yaGameObject.h"
#include "yaTransform.h"

namespace ya
{

	Rigidbody::Rigidbody() :
		Component(COMPONENTTYPE::RIGIDBODY)
		, mMass(1.0f)
		, mFriction(0.0f)
		, mbGround(false)
	{
		mLimitedVelocity.x = 10.0f;
		mLimitedVelocity.y = 10.0f;
		mGravity = Vector2(0.0f, 8.0f);

	}


	Rigidbody::~Rigidbody()
	{
	}


	void Rigidbody::Initialize()
	{
	}


	void Rigidbody::Update()
	{
		// f(힘) = m (질량) a (가속도)
		mAcceleration = mForce / mMass;

		//속도에 가속도를 더해줘야 총 속도가 나온다
		mVelocity += mAcceleration * Time::DeltaTime();

		if (mbGround)
		{
			// 땅위에 있을때
			Vector2 gravity = mGravity;
			gravity.normalize();
			float dot = ya::math::Vector2::Dot(mVelocity, gravity);
			mVelocity += gravity * dot;
		}
		else
		{
			// 공중에 있을때
			mVelocity -= mGravity * Time::DeltaTime();
		}

		// 최대 속도 제한
		Vector2 gravity = mGravity;
		gravity.normalize();
		float dot = ya::math::Vector2::Dot(mVelocity, gravity);
		gravity = gravity * dot;

		Vector2 sideVelocity = mVelocity - gravity;
		if (mLimitedVelocity.y < gravity.length())
		{
			gravity.normalize();
			gravity *= mLimitedVelocity.y;
		}

		if (mLimitedVelocity.x < sideVelocity.length())
		{
			sideVelocity.normalize();
			sideVelocity *= mLimitedVelocity.x;
		}
		mVelocity = gravity + sideVelocity;


		//마찰력 조건 ( 적용된 힘이 없고, 속도가 0 이 아닐 )
		if (!(mVelocity == Vector2::Zero))
		{
			// 속도에 반대 방향으로 마찰력을 적용
			Vector2 friction = -mVelocity;
			friction = friction.normalize() * mFriction * mMass * Time::DeltaTime();

			// 마찰력으로 인한 속도 감소량이 현재 속도보다 더 큰 경우
			if (mVelocity.length() < friction.length())
			{
				// 속도를 0 로 만든다.
				mVelocity = Vector2(0.f, 0.f);
			}
			else
			{
				// 속도에서 마찰력으로 인한 반대방향으로 속도를 차감한다.
				mVelocity += friction;
			}
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		pos = pos + mVelocity * Time::DeltaTime();
		tr->SetPosition(pos);
		mForce.clear();
	}

	void Rigidbody::LateUpdate()
	{
	}

	void Rigidbody::Render()
	{

	}

}