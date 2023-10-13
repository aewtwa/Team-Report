#pragma once
#include "CommonInclude.h"
#include "yaGraphicsDevice_DX11.h"
#include <directxtk/SpriteBatch.h>
#include <directxtk/SpriteFont.h>
#include "yaText.h"

namespace ya
{
	class TextManager
	{
	public:
		static void Initialize(Microsoft::WRL::ComPtr<ID3D11Device> device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> context);
		static void Release();

		static void Render();

		static void AddText(Text* text) { mTexts.push_back(text); }

	private:
		static std::vector<Text*> mTexts;
		static std::unique_ptr<DirectX::SpriteBatch> spriteBatch;
		static std::unique_ptr<DirectX::SpriteFont> spriteFont;

	};
}
