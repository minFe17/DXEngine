#include "GuiConsoleWindow.h"

namespace Gui
{
	ConsoleWindow::ConsoleWindow()
	{
		SetName("Console");
		SetSize(ImVec2(300, 600));
	}

	ConsoleWindow::~ConsoleWindow()
	{
	}

	void ConsoleWindow::Init()
	{
	}

	void ConsoleWindow::Update()
	{
		for (Editor* editor : editors)
			editor->Update();
	}

	void ConsoleWindow::OnGUI()
	{

		for (Editor* editor : editors)
			editor->OnGUI();
	}

	void ConsoleWindow::Run()
	{
		bool Active = (bool)GetState();
		ImGui::Begin(GetName().c_str(), &Active, GetFlag());

		Update();
		OnGUI();

		ImGui::End();
	}

	void ConsoleWindow::OnEnable()
	{
	}

	void ConsoleWindow::OnDisable()
	{
	}

	void ConsoleWindow::OnDestroy()
	{
	}
}