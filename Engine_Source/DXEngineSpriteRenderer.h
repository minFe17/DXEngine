#pragma once
#include "DXEngineComponent.h"
#include "DXEngineTexture.h"
#include "DXengineMaterial.h"
#include "DXEngineMesh.h"
#include "DXEngineBaseRenderer.h"

namespace DXEngine
{
	class SpriteRenderer : public BaseRenderer
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(const Matrix& view, const Matrix& projection) override;

		void SetSprite(Graphics::Texture* sprite) { this->sprite = sprite; }

	private:
		Graphics::Texture* sprite;
	};
}