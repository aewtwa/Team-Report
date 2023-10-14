#include "yaText.h"
#include "yaTextManager.h"
#include "yaCamera.h"
#include "yaGameObject.h"
#include "yaTransform.h"


namespace ya
{
	Text::Text() : Component(TEXT)
		, text(L"")
		, mPosition(Vector2::Zero)
		, mScale(Vector2::One)
		, mOffset(Vector2::Zero)
		, mColor(DirectX::Colors::White)
		, mbRender(false)
		, mbIsStatic(true)
	{
		TextManager::AddText(this);
	}
	Text::~Text()
	{
	}
	void Text::Initialize()
	{
	}
	void Text::Update()
	{
		mPosition = GetOwner()->GetComponent<Transform>()->GetPosition() + mOffset;

		if (mbIsStatic) // mbIsStatic
		{
			mPosition.x -= mScale.x / 2;
			mPosition.y += mScale.y / 2;
			mPosition *= 50;
			mPosition.y *= -1;
		}
		else
		{
			XMMATRIX matTransform = XMMatrixAffineTransformation2D(
				XMVectorSet(mScale.x, mScale.y, 1.0f, 1.0f), // 스케일링
				XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f),   // 회전 중심 (여기서는 사용하지 않음)
				0.f,                         // 회전 각도
				XMVectorSet(0.f, 0.f, 1.f, 0.f) // 이동
			);

			// X 좌표를 반전 (DirectX 11 좌표에서 API 좌표로 변환)
			matTransform.r[3].m128_f32[0] *= -1;

			// Y 좌표를 반전 (DirectX 11 좌표에서 API 좌표로 변환)
			matTransform.r[3].m128_f32[1] *= -1;

			// DirectX 11 좌표를 2D 벡터로 표현
			XMFLOAT2 dx11Coordinate = XMFLOAT2(mPosition.x, mPosition.y);

			XMMATRIX matDx11ToAPI = XMMatrixIdentity(); // 기본값은 항등 행렬

			// 변환 행렬을 만든 후 적용
			matDx11ToAPI = XMMatrixMultiply(matTransform, matDx11ToAPI);

			// DirectX 11 좌표
			//float dx11X = 100.0f;
			//float dx11Y = 50.0f;

			// DirectX 11 좌표를 2D 벡터로 표현
			//XMFLOAT2 dx11Coordinate = XMFLOAT2(mPosition.x, mPosition.y); //dx11X, dx11Y

			// 변환 적용
			/*XMFLOAT2 apiCoordinate;
			XMVECTOR result = XMVector2Transform(XMLoadFloat2(&dx11Coordinate), matDx11ToAPI);
			XMStoreFloat2(&apiCoordinate, result);

			mPosition = apiCoordinate;*/

			XMFLOAT2 apiCoordinate;
			XMVECTOR result = XMVector3TransformCoord(XMLoadFloat2(&dx11Coordinate), matTransform);
			XMStoreFloat2(&apiCoordinate, result);

			mPosition = apiCoordinate;
		}

		mbRender = true;
	}
	void Text::LateUpdate()
	{
	}
	void Text::Render()
	{
	}
	void Text::SetColor(std::wstring name)
	{
		if (name == L"White")
			mColor = DirectX::Colors::White;
		else if (name == L"Black")
			mColor = DirectX::Colors::Black;
	}
}