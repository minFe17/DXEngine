#include "GuiProjectWindow.h"

namespace Gui
{
	ProjectWindow::ProjectWindow()
	{
		SetName("Project");
		SetSize(ImVec2(300, 600));
	}

	ProjectWindow::~ProjectWindow()
	{
	}

	void ProjectWindow::Init()
	{
	}

	void ProjectWindow::Update()
	{
		for (Editor* editor : editors)
		{
			editor->Update();
		}
	}

	void ProjectWindow::OnGUI()
	{

		for (Editor* editor : editors)
		{
			editor->OnGUI();
		}
	}

	void ProjectWindow::Run()
	{
		bool Active = (bool)GetState();
		ImGui::Begin(GetName().c_str(), &Active, GetFlag());

		Update();
		OnGUI();

		ImGui::End();
	}

	void ProjectWindow::OnEnable()
	{
	}

	void ProjectWindow::OnDisable()
	{
	}

	void ProjectWindow::OnDestroy()
	{
	}
}