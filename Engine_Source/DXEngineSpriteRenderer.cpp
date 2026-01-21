#include "DXEngineSpriteRenderer.h"
#include "DXEngineGameObject.h"
#include "DXEngineTransform.h"
#include "DXEngineTexture.h"
#include "DXEngineRenderer.h"

namespace DXEngine
{
	SpriteRenderer::SpriteRenderer() : Component(Enum::EComponentType::SpriteRenderer), texture(nullptr), scale(Vector2::One)
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
		Vector2 pos = transform->GetPosition();
		pos = Renderer::mainCamera->CalculatePosition(pos);

		if (texture->GetTextureType() == Graphcis::Texture::ETextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y, texture->GetWidth() * scale.x, texture->GetHeight() * scale.y, texture->GetHdc(), 0, 0, texture->GetWidth(), texture->GetHeight(), RGB(255, 0, 255));
		}
		else if (texture->GetTextureType() == Graphcis::Texture::ETextureType::Png)
		{
			Gdiplus::Graphics graphcis(hdc);
			graphcis.DrawImage(texture->GetImage(), Gdiplus::Rect(pos.x, pos.y, texture->GetWidth() * scale.x, texture->GetHeight() * scale.y));
		}
	}	
}