#include "GuiInspectorWindow.h"

namespace Gui
{
	InspectorWindow::InspectorWindow()
	{
		SetName("Inspector");
		SetSize(ImVec2(300, 600));
	}

	InspectorWindow::~InspectorWindow()
	{
	}

	void InspectorWindow::Init()
	{
	}

	void InspectorWindow::Update()
	{
		for (Editor* editor : editors)
		{
			editor->Update();
		}
	}

	void InspectorWindow::OnGUI()
	{

		for (Editor* editor : editors)
		{
			editor->OnGUI();
		}
	}

	void InspectorWindow::Run()
	{
		bool Active = (bool)GetState();
		ImGui::Begin(GetName().c_str(), &Active, GetFlag());

		Update();
		OnGUI();

		ImGui::End();
	}

	void InspectorWindow::OnEnable()
	{
	}

	void InspectorWindow::OnDisable()
	{
	}

	void InspectorWindow::OnDestroy()
	{
	}
}