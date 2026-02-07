#pragma once
#include "DXEngineComponent.h"
#include "DXEngineAnimation.h"

namespace DXEngine
{
	class Animator : public Component
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> function)
			{
				event = std::move(function);
			}

			void operator()()
			{
				if (event)
					event;
			}

			std::function<void()> event;
		};

		struct Events
		{
			Event startEvent;
			Event completeEvent;
			Event endEvent;
		};

		Animator();
		~Animator();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void CreateAnimation(const std::wstring& name, Graphics::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration);
		void CreateAnimationByFolder();
		Animation* FindAnimation(const std::wstring& name);

		Events* FindEvents(const std::wstring& name);

		void PlayAnimation(const std::wstring& name, bool loop = true);
		std::function<void()>& GetStartEvent(const std::wstring& name);
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		std::function<void()>& GetEndEvent(const std::wstring& name);

		bool IsCompleteAnimation() { return activeAnimation->IsComplete(); }

	private:
		std::map<std::wstring, Animation*> animations;
		Animation* activeAnimation;
		bool isLoop;

		std::map<std::wstring, Events*> events;
	};
}