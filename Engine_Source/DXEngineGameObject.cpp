#include "DXEngineGameObject.h"
#include "DXEngineInput.h"
#include "DXEngineTime.h"
#include <DXEngineTransform.h>

namespace DXEngine
{
	GameObject::GameObject()
	{
		components.resize((UINT)Enum::EComponentType::Max);
		InitTransform();
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Init()
	{
		for (size_t i = 0; i < components.size(); i++)
			components[i]->Init();
	}

	void GameObject::Update()
	{
		for (size_t i = 0; i < components.size(); i++)
			components[i]->Update();
	}

	void GameObject::LateUpdate()
	{
		for (size_t i = 0; i < components.size(); i++)
			components[i]->LateUpdate();
	}

	void GameObject::Render(HDC hdc)
	{
		for (size_t i = 0; i < components.size(); i++)
			components[i]->Render(hdc);
	}

	void GameObject::InitTransform()
	{
		AddComponent<Transform>();
	}
}