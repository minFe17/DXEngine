#include "DXEngineTransform.h"

namespace DXEngine
{
	DXEngine::Transform::Transform() : Component(Enum::EComponentType::Transform), rotation(0), scale(Vector2::One)
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
	}

	void Transform::Render(HDC hdc)
	{
	}
}