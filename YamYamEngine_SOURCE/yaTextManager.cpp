#include "yaTextManager.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include <directxtk/SpriteBatch.h>
#include <directxtk/SpriteFont.h>

namespace ya
{
	std::vector<Text*> TextManager::mTexts = {};
	std::unique_ptr<DirectX::SpriteBatch> TextManager::spriteBatch;
	std::unique_ptr<DirectX::SpriteFont> TextManager::spriteFont;

	void TextManager::Initialize(Microsoft::WRL::ComPtr<ID3D11Device> device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> context)
	{							 
		spriteBatch = std::make_unique<DirectX::SpriteBatch>(context.Get());
		spriteFont = std::make_unique<DirectX::SpriteFont>(device.Get(), L"..\\Data\\comic_sans_ms_16.spritefont");
	}
	void TextManager::Release()
	{
	}
	void TextManager::Render()
	{
		spriteBatch->Begin();

		for (Text* text : mTexts)
		{
			if (text->CanRender())
			{
				spriteFont->DrawString(spriteBatch.get(), text->GetText().c_str(), (DirectX::XMFLOAT2)text->GetPosition(), text->GetColor(), 0.0f, DirectX::XMFLOAT2(0.0f, 0.0f), (DirectX::XMFLOAT2)text->GetScale());
				text->SetRender(false);
			}
		}

		spriteBatch->End();
	}
}