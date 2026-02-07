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

	HRESULT Animation::Save(const std::wstring& path)
	{
		return E_NOTIMPL;
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

	void Animation::Render()
	{
		if (texture == nullptr)
			return;
	}

	void Animation::CreateAnimation(const std::wstring& name, Graphics::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
		SetName(name);
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