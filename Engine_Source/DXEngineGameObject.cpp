#include "DXEngineGameObject.h"
#include "DXEngineInput.h"
#include "DXEngineTime.h"
#include <DXEngineTransform.h>

namespace DXEngine
{
	GameObject::GameObject() : stateType(EStateType::Active), layerType(Enum::ELayerType::None)
	{
		components.resize((UINT)Enum::EComponentType::Max);
		InitTransform();
	}

	GameObject::~GameObject()
	{
		for (Component* component : components)
		{
			if (component == nullptr)
				continue;
			delete component;
			component = nullptr;
		}
	}

	void GameObject::Init()
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			if (components[i] == nullptr)
				continue;
			components[i]->Init();
		}
	}

	void GameObject::Update()
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			if (components[i] == nullptr)
				continue;
			components[i]->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			if (components[i] == nullptr)
				continue;
			components[i]->LateUpdate();
		}
	}

	void GameObject::Render()
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			if (components[i] == nullptr)
				continue;
			components[i]->Render();
		}
	}

	void GameObject::InitTransform()
	{
		AddComponent<Transform>();
	}
}