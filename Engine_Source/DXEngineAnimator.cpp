#include "DXEngineAnimator.h"
#include "DXEngineTexture.h"

namespace DXEngine
{
	Animator::Animator() : Component(Enum::EComponentType::Aniimator)
	{
	}

	Animator::~Animator()
	{
	}

	void Animator::Init()
	{
	}

	void Animator::Update()
	{
		if (activeAnimation)
		{
			activeAnimation->Update();
			if (activeAnimation->IsComplete() == true && isLoop == true)
				activeAnimation->Reset();
		}
	}

	void Animator::LateUpdate()
	{
	}

	void Animator::Render(HDC hdc)
	{
		if (activeAnimation)
			activeAnimation->Render(hdc);
	}

	void Animator::CreateAnimation(const std::wstring& name, Graphcis::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);

		if (animation != nullptr)
			return;
		animation = new Animation();
		animation->CreateAnimation(name, spriteSheet, leftTop, size, offset, spriteLength, duration);
		animation->SetAnimator(this);

		animations.insert(std::make_pair(name, animation));
	}

	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		std::map<std::wstring, Animation*>::iterator iter = animations.find(name);
		if (iter == animations.end())
			return nullptr;
		return iter->second;
	}

	void Animator::PlayAnimation(const std::wstring& name, bool loop)
	{
		Animation* animation = FindAnimation(name);
		if (animation == nullptr)
			return;

		activeAnimation = animation;
		activeAnimation->Reset();
		isLoop = loop;
	}
}