#include "GuiGameWindow.h"

namespace Gui
{
	GameWindow::GameWindow()
	{
		SetName("Game");
		SetSize(ImVec2(300, 600));
	}

	GameWindow::~GameWindow()
	{
	}

	void GameWindow::Init()
	{
	}

	void GameWindow::Update()
	{
		for (Editor* editor : editors)
			editor->Update();
	}

	void GameWindow::OnGUI()
	{

		for (Editor* editor : editors)
			editor->OnGUI();
	}

	void GameWindow::Run()
	{
		bool Active = (bool)GetState();
		ImGui::Begin(GetName().c_str(), &Active, GetFlag());

		Update();
		OnGUI();

		ImGui::End();
	}

	void GameWindow::OnEnable()
	{
	}

	void GameWindow::OnDisable()
	{
	}

	void GameWindow::OnDestroy()
	{
	}
}