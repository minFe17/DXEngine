#include "DXEngineSpriteRenderer.h"
#include "DXEngineGameObject.h"
#include "DXEngineTransform.h"
#include "DXEngineTexture.h"
#include "DXEngineRenderer.h"

namespace DXEngine
{
	SpriteRenderer::SpriteRenderer() : Component(Enum::EComponentType::SpriteRenderer), texture(nullptr), size(Vector2::One)
	{

	}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Init()
	{
	}

	void SpriteRenderer::Update()
	{
	}

	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		if (texture == nullptr)
			assert(false);

		Transform* transform = GetOwner()->GetComponent<Transform>();
		Vector2 position = transform->GetPosition();
		float rotation = transform->GetRotation();
		Vector2 scale = transform->GetScale();

		position = Renderer::mainCamera->CalculatePosition(position);

		if (texture->GetTextureType() == Graphcis::Texture::ETextureType::Bmp)
		{
			TransparentBlt(hdc, position.x, position.y, texture->GetWidth() * size.x * scale.x, texture->GetHeight() * scale.y * scale.y, texture->GetHdc(), 0, 0, texture->GetWidth(), texture->GetHeight(), RGB(255, 0, 255));
		}
		else if (texture->GetTextureType() == Graphcis::Texture::ETextureType::Png)
		{
			Gdiplus::ImageAttributes imageAttribute = {};
			imageAttribute.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));
			Gdiplus::Graphics graphics(hdc);
			graphics.TranslateTransform(position.x, position.y);
			graphics.RotateTransform(rotation);
			graphics.TranslateTransform(-position.x, -position.y);

			graphics.DrawImage(texture->GetImage(), Gdiplus::Rect(position.x, position.y, texture->GetWidth() * size.x * scale.x, texture->GetHeight() * size.x * scale.y), 0, 0, texture->GetWidth(), texture->GetHeight(), Gdiplus::UnitPixel, nullptr);
		}
	}	
}