#include "DXEngineSpriteRenderer.h"
#include "DXEngineGameObject.h"
#include "DXEngineTransform.h"

namespace DXEngine
{
	SpriteRenderer::SpriteRenderer() : image(nullptr), width(0), height(0)
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

	void SpriteRenderer::Render(HDC hdc)
	{
		Transform* transform = GetOwner()->GetComponent<Transform>();

		Vector2 pos = transform->GetPosition();

		Gdiplus::Graphics graphcis(hdc);
		graphcis.DrawImage(image, Gdiplus::Rect(pos.x, pos.y, width, height));
	}

	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		image = Gdiplus::Image::FromFile(path.c_str());
		width = image->GetWidth();
		height = image->GetHeight();
	}
}