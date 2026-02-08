#pragma once
#include "DXEngineEntity.h"
#include "DXEngineComponent.h"
#include "DXEngineTexture.h"
#include "DXengineMaterial.h"
#include "DXEngineMesh.h"

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

		void SetSprite(Graphics::Texture* sprite) { this->sprite = sprite; }
		void SetMaterial(Material* material) { this->material = material; }

	private:
		Graphics::Texture* sprite;
		Material* material;
		Mesh* mesh;
	};
}