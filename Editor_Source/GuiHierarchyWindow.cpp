#include "GuiHierarchyWindow.h"

namespace Gui
{
	HierarchyWindow::HierarchyWindow()
	{
		SetName("Hierarchy");
		SetSize(ImVec2(300, 600));
	}

	HierarchyWindow::~HierarchyWindow()
	{
	}

	void HierarchyWindow::Init()
	{
	}

	void HierarchyWindow::Update()
	{
		for (Editor* editor : editors)
			editor->Update();
	}

	void HierarchyWindow::OnGUI()
	{

		for (Editor* editor : editors)
			editor->OnGUI();
	}

	void HierarchyWindow::Run()
	{
		bool Active = (bool)GetState();
		ImGui::Begin(GetName().c_str(), &Active, GetFlag());

		Update();
		OnGUI();

		ImGui::End();
	}

	void HierarchyWindow::OnEnable()
	{
	}

	void HierarchyWindow::OnDisable()
	{
	}

	void HierarchyWindow::OnDestroy()
	{
	}
}