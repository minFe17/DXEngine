#pragma once
#include "DXEngineComponent.h"
#include "DXEngineAnimation.h"

namespace DXEngine
{
	class Animator : public Component
	{
	public:
		Animator();
		~Animator();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void CreateAnimation(const std::wstring& name, Graphcis::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration);
		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);

	private:
		std::map<std::wstring, Animation*> animations;
		Animation* activeAnimation;
		bool isLoop;
	};
}