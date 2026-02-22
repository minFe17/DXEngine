#include "DXEngineCamera.h"
#include "DXEngineGameObject.h"
#include "DXEngineTransform.h"
#include "DXEngineApplication.h"

extern DXEngine::Application application;

namespace DXEngine
{
	Matrix Camera::ViewMatrix = Matrix::Identity;
	Matrix Camera::ProjectionMatrix = Matrix::Identity;

	Camera::Camera() : Component(Enum::EComponentType::Camera), projectionType(EProjectionType::Perspective), viewMatrix(Matrix::Identity), projectionMatrix(Matrix::Identity), aspectRatio(0.0f), nearValue(1.0f), farValue(1000.0f), size(1.0f)
	{

	}

	Camera::~Camera()
	{

	}

	void Camera::Init()
	{
		
	}

	void Camera::Update()
	{

	}

	void Camera::LateUpdate()
	{
		CreateViewMatrix();
		CreateProjectionMatrix(projectionType);

		ViewMatrix = viewMatrix;
		ProjectionMatrix = projectionMatrix;
	}

	void Camera::Render()
	{

	}

	void Camera::CreateViewMatrix()
	{
		Transform* transform = GetOwner()->GetComponent<Transform>();

		const Vector3 pos = transform->GetPosition();
		const Vector3 up = transform->Up();
		const Vector3 forward = transform->Foward();

		viewMatrix = Matrix::CreateLookToLH(pos, forward, up);
	}

	void Camera::CreateProjectionMatrix(EProjectionType type)
	{
		RECT winRect;
		GetClientRect(application.GetWindow().GetHwnd(), &winRect);
		float width = (winRect.right - winRect.left);
		float height = (winRect.bottom - winRect.top);
		aspectRatio = width / height;

		switch (type)
		{
		case EProjectionType::Perspective:
			projectionMatrix = Matrix::CreatePerspectiveFieldOfViewLH(XM_2PI / 6.0f, aspectRatio, nearValue, farValue);
			break;
		case EProjectionType::Orthographic:
			projectionMatrix = Matrix::CreateOrthographicLH(width / size, height / size, nearValue, farValue);
			break;
		}
	}
}