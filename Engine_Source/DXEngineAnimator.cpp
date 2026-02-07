#include "DXEngineAnimator.h"
#include "DXEngineTexture.h"
#include "DXEngineLoadResources.h"

namespace DXEngine
{
	Animator::Animator() : Component(Enum::EComponentType::Aniimator)
	{
	}

	Animator::~Animator()
	{
		for (auto& iter : animations)
		{
			delete iter.second;
			iter.second = nullptr;
		}

		for (auto& iter : events)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	void Animator::Init()
	{
	}

	void Animator::Update()
	{
		if (activeAnimation)
		{
			activeAnimation->Update();
			Events* events = FindEvents(activeAnimation->GetName());

			if (activeAnimation->IsComplete())
			{
				if(events->completeEvent.event)
					events->completeEvent();

				if(isLoop == true)
					activeAnimation->Reset();
			}
		}
	}

	void Animator::LateUpdate()
	{
	}

	void Animator::Render()
	{
		
	}

	void Animator::CreateAnimation(const std::wstring& name, Graphics::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);

		if (animation != nullptr)
			return;

		animation = new Animation();
		animation->CreateAnimation(name, spriteSheet, leftTop, size, offset, spriteLength, duration);
		animation->SetAnimator(this);

		animations.insert(std::make_pair(name, animation));

		Events* event = new Events();
		events.insert(std::make_pair(name, event));
	}

	void Animator::CreateAnimationByFolder()
	{
		
	}

	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		std::map<std::wstring, Animation*>::iterator iter = animations.find(name);
		if (iter == animations.end())
			return nullptr;
		return iter->second;
	}

	Animator::Events* Animator::FindEvents(const std::wstring& name)
	{
		auto iter = events.find(name);
		if (iter == events.end())
			return nullptr;
		return iter->second;
	}

	void Animator::PlayAnimation(const std::wstring& name, bool loop)
	{
		Animation* animation = FindAnimation(name);
		if (animation == nullptr)
			return;

		Events* currentEvents = FindEvents(activeAnimation->GetName());
		if(currentEvents)
			currentEvents->endEvent();

		activeAnimation = animation;
		Events* nextEvents = FindEvents(activeAnimation->GetName());
		if(nextEvents)
			nextEvents->startEvent();

		activeAnimation->Reset();
		isLoop = loop;
	}

	std::function<void()>& Animator::GetStartEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->startEvent.event;
	}

	std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->completeEvent.event;
	}

	std::function<void()>& Animator::GetEndEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->endEvent.event;
	}
}