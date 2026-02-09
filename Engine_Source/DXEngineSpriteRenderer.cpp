#include "DXEngineSpriteRenderer.h"
#include "DXEngineGameObject.h"
#include "DXEngineTransform.h"
#include "DXEngineTexture.h"
#include "DXEngineRenderer.h"
#include "DXEngineResources.h"

namespace DXEngine
{
	SpriteRenderer::SpriteRenderer() : Component(Enum::EComponentType::SpriteRenderer), sprite(nullptr), material(nullptr), mesh(nullptr)
	{

	}

	SpriteRenderer::~SpriteRenderer()
	{

	}

	void SpriteRenderer::Init()
	{
		mesh = Resources::Find<Mesh>(L"RectMesh");
		material = Resources::Find<Material>(L"SpriteMaterial");
	}

	void SpriteRenderer::Update()
	{
	}

	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render()
	{
		if (mesh)
			mesh->Bind();
		if (material)
			material->Bind();
		if (sprite)
			sprite->Bind(EShaderStage::PS, (UINT)ETextureType::Sprite);
		if (mesh)
			Graphics::GetDevice()->DrawIndexed(mesh->GetIndexCount(), 0, 0);
	}
}