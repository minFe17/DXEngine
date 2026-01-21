#include "DXEngineComponent.h"

namespace DXEngine
{
	Component::Component(Enum::EComponentType type)
	{
		this->type = type;
	}

	Component::~Component()
	{
	}
	void Component::Init()
	{

	}

	void Component::Update()
	{

	}

	void Component::LateUpdate()
	{

	}

	void Component::Render(HDC hdc)
	{

	}
}