#include "DXEngineSpriteRenderer.h"
#include "DXEngineGameObject.h"
#include "DXEngineTexture.h"
#include "DXEngineRenderer.h"
#include "DXEngineResources.h"

namespace DXEngine
{
	SpriteRenderer::SpriteRenderer() : BaseRenderer(Enum::EComponentType::SpriteRenderer)
	{

	}

	SpriteRenderer::~SpriteRenderer()
	{

	}

	void SpriteRenderer::Init()
	{
		BaseRenderer::Init();

		Mesh* mesh = Resources::Find<Mesh>(L"RectMesh");
		Material* material = Resources::Find<Material>(L"SpriteMaterial");

		SetMesh(mesh);
		SetMaterial(material);
	}

	void SpriteRenderer::Update()
	{
		BaseRenderer::Update();
	}

	void SpriteRenderer::LateUpdate()
	{
		BaseRenderer::LateUpdate();
	}

	void SpriteRenderer::Render(const Matrix& view, const Matrix& projection)
	{
		BaseRenderer::Render(view, projection);

		if (sprite)
			sprite->Bind(EShaderStage::PS, (UINT)ETextureType::Sprite);

		BaseRenderer::Draw();
	}
}