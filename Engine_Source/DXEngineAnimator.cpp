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

		Events* event = new Events();
		events.insert(std::make_pair(name, event));
	}

	void Animator::CreateAnimationByFolder(const std::wstring& name, const std::wstring& path, Vector2 offset, float duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);

		if (animation != nullptr)
			return;

		int fileCount = 0;

		std::filesystem::path animationPath(path);
		std::vector<Graphcis::Texture*> images = {};
		for (auto& entry : std::filesystem::recursive_directory_iterator(animationPath))
		{
			std::wstring fileName = entry.path().filename();
			std::wstring fullName = entry.path();

			Graphcis::Texture* texture = Resources::Load<Graphcis::Texture>(fileName, fullName);
			images.push_back(texture);
			fileCount++;
		}

		UINT sheetWidth = images[0]->GetWidth() * fileCount;
		UINT sheetHeight = images[0]->GetHeight();
		Graphcis::Texture* spriteSheet = Graphcis::Texture::Create(name, sheetWidth, sheetHeight);

		UINT imageWidth = images[0]->GetWidth();
		UINT imageHeight = images[0]->GetHeight();
		for (size_t i = 0; i < images.size(); i++)
			BitBlt(spriteSheet->GetHdc(), i * imageWidth, 0, imageWidth, imageHeight, images[i]->GetHdc(), 0, 0, SRCCOPY);
		CreateAnimation(name, spriteSheet, Vector2::One, Vector2(imageWidth, imageHeight), offset, fileCount, duration);
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