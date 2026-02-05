#pragma once
#include "DXEngineResource.h";
#include "DXEngineTexture.h";

namespace DXEngine
{
	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite() : leftTop(Vector2::Zero), size(Vector2::Zero), offset(Vector2::Zero), duration(0)
			{

			}
		};

		Animation();
		~Animation();

		HRESULT Load(const std::wstring& path) override;

		void Update();
		void Render();

		void CreateAnimation(const std::wstring& name, Graphcis::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration);
		void Reset();

		bool IsComplete() const { return isComplete; }
		void SetAnimator(class Animator* animator) { this->animator = animator; }

	private:
		class Animator* animator;
		Graphcis::Texture* texture;

		std::vector<Sprite> animationSheet;
		int index;
		float time;
		bool isComplete;
	};
}