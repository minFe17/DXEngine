#include "DXEngineSpriteRenderer.h"
#include "DXEngineGameObject.h"
#include "DXEngineTransform.h"
#include "DXEngineTexture.h"
#include "DXEngineRenderer.h"

namespace DXEngine
{
	SpriteRenderer::SpriteRenderer() : Component(Enum::EComponentType::SpriteRenderer), texture(nullptr), size(Vector2::One)
	{

	}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Init()
	{
	}

	void SpriteRenderer::Update()
	{
	}

	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render()
	{
		if (texture == nullptr)
			assert(false);
	}	
}