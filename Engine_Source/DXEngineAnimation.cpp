#include "DXEngineAnimation.h"
#include "DXEngineTime.h"
#include "DXEngineTransform.h"
#include "DXEngineGameObject.h"
#include "DXEngineAnimator.h"
#include "DXEngineRenderer.h"

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

		if (Renderer::mainCamera)
			position = Renderer::mainCamera->CalculatePosition(position);
		
		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255;

		Sprite sprite = animationSheet[index];
		HDC imageHdc = texture->GetHdc();
		AlphaBlend(hdc, position.x, position.y, sprite.size.x, sprite.size.y, imageHdc, sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y, func);
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