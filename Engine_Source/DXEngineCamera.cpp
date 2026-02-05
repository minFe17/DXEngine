#include "DXEngineCamera.h"
#include "DXEngineGameObject.h"
#include "DXEngineTransform.h"
#include "DXEngineApplication.h"

extern DXEngine::Application application;

namespace DXEngine
{
	Camera::Camera() : Component(Enum::EComponentType::Camera), target(nullptr), distance(Vector2::Zero), resolution(Vector2(1600, 900)), lookPosition(Vector2::Zero)
	{

	}

	Camera::~Camera()
	{

	}

	void Camera::Init()
	{
		resolution.x = (float)application.GetWidth();
		resolution.y = (float)application.GetHeight();
	}

	void Camera::Update()
	{
		if (target)
		{
			Transform* transform = target->GetComponent<Transform>();
			lookPosition = transform->GetPosition();
		}
		else
		{
			Transform* transform = GetOwner()->GetComponent<Transform>();
			lookPosition = transform->GetPosition();
		}
		
		distance = lookPosition - (resolution / 2.0f);
	}

	void Camera::LateUpdate()
	{
		
	}

	void Camera::Render()
	{

	}
}