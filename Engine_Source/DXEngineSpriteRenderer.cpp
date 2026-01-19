#include "DXEngineSpriteRenderer.h"
#include "DXEngineGameObject.h"
#include "DXEngineTransform.h"

namespace DXEngine
{
	SpriteRenderer::SpriteRenderer()
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
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Transform* transform = GetOwner()->GetComponent<Transform>();
		int x = transform->GetPositionX();
		int y = transform->GetPositionY();
		Rectangle(hdc, 100 + x, 100 + y, 200 + x, 200 + y);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
	}
}