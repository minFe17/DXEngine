#include "DXEngineAnimation.h"
#include "DXEngineAnimator.h"
#include "DXEngineGameObject.h"
#include "DXEngineRenderer.h"
#include "DXEngineTime.h"
#include "DXEngineTransform.h"

namespace DXEngine
{
	Animation::Animation() : Resource(Enum::EResourceType::Animation), animator(nullptr), texture(nullptr), animationSheet{}, index(-1), time(0), isComplete(false)
	{

	}

	Animation::~Animation()
	{

	}

	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void Animation::Update()
	{
		if (isComplete)
			return;
		time += Time::DeltaTime();

		if (animationSheet[index].duration < time)
		{
			time = 0;
			if (index < animationSheet.size() - 1)
				index++;
			else
				isComplete = true;
		}
	}

	void Animation::Render(HDC hdc)
	{
		if (texture == nullptr)
			return;

		GameObject* gameObject = animator->GetOwner();
		Transform* transform = gameObject->GetComponent<Transform>();
		Vector2 position = transform->GetPosition();
		float rotation = transform->GetRotation();
		Vector2 scale = transform->GetScale();

		if (Renderer::mainCamera)
			position = Renderer::mainCamera->CalculatePosition(position);
		Sprite sprite = animationSheet[index];

		Graphcis::Texture::ETextureType textureType = texture->GetTextureType();
		if (textureType == Graphcis::Texture::ETextureType::Bmp)
		{
			HDC imageHdc = texture->GetHdc();

			if (texture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255;

				AlphaBlend(hdc, position.x - (sprite.size.x / 2) + sprite.offset.x, position.y - (sprite.size.y / 2) + sprite.offset.y,
											  sprite.size.x * scale.x, sprite.size.y * scale.y, 
					                          imageHdc, sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y, func);
			}
			else
			{
				GdiTransparentBlt(hdc, position.x - (sprite.size.x / 2) + sprite.offset.x, position.y - (sprite.size.y / 2) + sprite.offset.y, 
									   sprite.size.x * scale.x, sprite.size.y * scale.y, 
					                   imageHdc, sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y, RGB(255, 0, 255));
			}
		}
		else if (textureType == Graphcis::Texture::ETextureType::Png)
		{
			Gdiplus::ImageAttributes imageAttribute = {};
			imageAttribute.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));
			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(position.x, position.y);
			graphics.RotateTransform(rotation);
			graphics.TranslateTransform(-position.x, -position.y);
			graphics.DrawImage(texture->GetImage(), Gdiplus::Rect(position.x - (sprite.size.x / 2), position.y - (sprite.size.y / 2), sprite.size.x * scale.x, sprite.size.y * scale.y), sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y, Gdiplus::UnitPixel, nullptr);
		}
	}

	void Animation::CreateAnimation(const std::wstring& name, Graphcis::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
		texture = spriteSheet;
		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			animationSheet.push_back(sprite);
		}
	}

	void Animation::Reset()
	{
		time = 0;
		index = 0;
		isComplete = false;
	}
}