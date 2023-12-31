#pragma once
#include "yaComponent.h"



namespace ya
{
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetConstantBuffer(bool AffectCamera = true);

		void SetPosition(Vector3 position) { mPosition = position; }
		void SetRotation(Vector3 rotation) { mRotation = rotation; }
		void SetScale(Vector3 scale) { mScale = scale; }

		void SetPositionVec2(Vector2 position) { mPosition = Vector3(position.x, position.y, mPosition.z); }
		void SetPosition(float x, float y, float z) { mPosition = Vector3(x,y,z); }
		void SetRotation(float x, float y, float z) { mRotation = Vector3(x, y, z); }
		void SetScale(float x, float y, float z) { mScale = Vector3(x, y, z); }

		Vector3 GetPosition() { return mPosition; }
		Vector2 GetPositionVec2() { return Vector2(mPosition.x, mPosition.y); }
		Vector3 GetRotation() { return mRotation; }
		Vector3 GetScale() { return mScale; }

	private:
		Vector3 mPosition;
		Vector3 mRotation;
		Vector3 mScale;

		bool mbAffectCamera;
	};
}
