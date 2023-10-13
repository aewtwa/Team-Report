#pragma once
#include "yaComponent.h"

namespace ya
{
	class Text : public Component
	{
	public:
		Text();
		~Text() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		Vector2 GetPosition() { return mPosition; }

		void SetScale(Vector2 scale) { mScale = scale; }
		Vector2 GetScale() { return mScale; }

		void SetOffset(Vector2 offset) { mOffset = offset; }
		Vector2 GetOffset() { return mOffset; }

		void SetColor(std::wstring name);
		DirectX::XMVECTORF32 GetColor() { return mColor; }

		std::wstring GetText() { return text; }
		void SetText(std::wstring tex) { text = tex; }

		bool CanRender() { return render; }
		void SetRender(bool value) { render = value; }

	private:
		std::wstring text;
		Vector2 mPosition;
		Vector2 mScale;
		Vector2 mOffset;

		DirectX::XMVECTORF32 mColor;
		bool render;
	};
}
