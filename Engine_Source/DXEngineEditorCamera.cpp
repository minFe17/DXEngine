#include "DXEngineEditorCamera.h"

namespace DXEngine
{
	EditorCamera::EditorCamera() : Camera(), renderTarget(nullptr)
	{

	}
	EditorCamera::~EditorCamera()
	{

	}

	void EditorCamera::Init()
	{
		Camera::Init();
	}

	void EditorCamera::Update()
	{
		Camera::Update();
	}

	void EditorCamera::LateUpdate()
	{
		Camera::LateUpdate();
	}

	void EditorCamera::Render(const Matrix& view, const Matrix& projection)
	{
		Camera::Render(view, projection);
	}

	void EditorCamera::OnEvent(Event& e)
	{

	}
}