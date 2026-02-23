#include "DXEngineTransform.h"
#include "DXEngineGraphics.h"
#include "DXEngineCamera.h"
#include "DXEngineConstantBuffer.h"
#include "DXEngineRenderer.h"

namespace DXEngine
{
	DXEngine::Transform::Transform() : Component(Enum::EComponentType::Transform), worldMatrix(Matrix::Identity), scale(Vector3::One), rotation(Vector3::Zero), position(Vector3::Zero)
	{
	}

	DXEngine::Transform::~Transform()
	{
	}

	void DXEngine::Transform::Init()
	{
	}

	void DXEngine::Transform::Update()
	{
	}

	void DXEngine::Transform::LateUpdate()
	{
		Matrix scaleMatrix = Matrix::CreateScale(scale.x, scale.y, scale.z);
		Matrix rotationMatrix = Matrix::CreateRotationX(Math::Radian(rotation.x));
		rotationMatrix *= Matrix::CreateRotationY(Math::Radian(rotation.y));
		rotationMatrix *= Matrix::CreateRotationZ(Math::Radian(rotation.z));
		Matrix translationMatrix = Matrix::CreateTranslation(position);

		worldMatrix = scaleMatrix * rotationMatrix * translationMatrix;

		forward = Vector3::TransformNormal(Vector3::Forward, rotationMatrix);
		right = Vector3::TransformNormal(Vector3::Right, rotationMatrix);
		up = Vector3::TransformNormal(Vector3::Up, rotationMatrix);
	}

	void Transform::Render(const Matrix& view, const Matrix& projection)
	{
	}

	void Transform::Bind()
	{
		Graphics::TransformCB cbData = {};
		cbData.world = GetWorldMatrix();
		cbData.view = Camera::GetGpuViewMatrix();
		cbData.projection = Camera::GetGpuProjectionMatrix();

		Graphics::ConstantBuffer* constantbuffer = Renderer::constantBuffers[CBSLOT_TRANSFORM];

		constantbuffer->SetData(&cbData);
		constantbuffer->Bind(EShaderStage::All);
	}
}