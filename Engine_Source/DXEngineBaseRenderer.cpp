#include "DXEngineBaseRenderer.h"
#include "DXEngineTransform.h"
#include "DXEngineGameObject.h"

namespace DXEngine
{
	BaseRenderer::BaseRenderer(Enum::EComponentType type) : Component(type), material(nullptr)
	{
	}

	BaseRenderer::~BaseRenderer()
	{
	}

	void BaseRenderer::Init()
	{
	}

	void BaseRenderer::Update()
	{
	}

	void BaseRenderer::LateUpdate()
	{

	}

	void BaseRenderer::Render(const Matrix& view, const Matrix& projection)
	{
		Transform* transform = GetOwner()->GetComponent<Transform>();
		if (transform)
			transform->Bind();

		if (mesh)
			mesh->Bind();

		if (material)
			material->BindShader();
	}

	void BaseRenderer::Draw()
	{
		if (mesh)
			Graphics::GetDevice()->DrawIndexed(mesh->GetIndexCount(), 0, 0);
	}
}