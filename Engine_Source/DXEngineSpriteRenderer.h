#pragma once
#include "DXEngineEntity.h"
#include "DXEngineComponent.h"
#include "DXEngineTexture.h"
namespace DXEngine
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void SetTexture(Graphcis::Texture* texture) { this->texture = texture; }
		void SetScale(Math::Vector2 value) { size = value; }

	private:
		Graphcis::Texture* texture;
		Math::Vector2 size;
	};
}