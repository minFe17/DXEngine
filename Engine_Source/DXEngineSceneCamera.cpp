#include "DXEngineSceneCamera.h"

namespace DXEngine
{
	SceneCamera::SceneCamera() : Camera()
	{

	}

	SceneCamera::~SceneCamera()
	{

	}

	void SceneCamera::Init()
	{
		Camera::Init();
	}

	void SceneCamera::Update()
	{
		Camera::Update();
	}

	void SceneCamera::LateUpdate()
	{
		Camera::LateUpdate();
	}

	void SceneCamera::Render(const Matrix& view, const Matrix& projection)
	{
		Camera::Render(view, projection);
	}

	void SceneCamera::OnEvent(Event& e)
	{

	}
}