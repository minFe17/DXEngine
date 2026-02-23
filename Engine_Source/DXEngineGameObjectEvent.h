#pragma once
#include "DXEngineEvent.h"
#include "DXEngineGameObject.h"
#include "DXEngineScene.h"

namespace DXEngine
{
	class GameObjectEvent : public Event
	{
	public:
		GameObject::EStateType GetState() const { return stateType; }
		EVENT_CLASS_CATEGORY(EventCategoryGameObject | EventCategoryGame)

	protected:
		GameObjectEvent(const GameObject::EStateType state) : stateType(state) {}

		GameObject::EStateType stateType;
	};

	class GameObjectCreatedEvent : public GameObjectEvent
	{
	public:
		GameObjectCreatedEvent(GameObject* object, Scene* targetScene) : GameObjectEvent(GameObject::EStateType::Created), gameObject(object), scene(targetScene) { }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GameObjectCreatedEvent";
			return ss.str();
		}

		GameObject* GetGameObject() const { return gameObject; }
		Scene* GetScene() const { return scene; }

		EVENT_CLASS_TYPE(GameObjectCreated)

	private:
		GameObject* gameObject;
		Scene* scene;
	};

	class GameObjectDestroyedEvent : public GameObjectEvent
	{
	public:
		GameObjectDestroyedEvent(GameObject* object, Scene* targetScene) : GameObjectEvent(GameObject::EStateType::Destroyed), gameObject(object), scene(targetScene) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GameObjectDestroyedEvent";
			return ss.str();
		}

		GameObject* GetGameObject() const { return gameObject; }
		Scene* GetScene() const { return scene; }

		EVENT_CLASS_TYPE(GameObjectDestroyed)

	private:
		GameObject* gameObject;
		Scene* scene;
	};
}