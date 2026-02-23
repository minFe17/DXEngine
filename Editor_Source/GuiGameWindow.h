#pragma once

#include "GuiEditorWindow.h"
#include "GuiEditor.h"

namespace Gui
{
	class GameWindow : public EditorWindow
	{
	public:
		GameWindow();
		~GameWindow();

		void Init() override;
		void Update() override;
		void OnGUI() override;
		void Run() override;
		void OnEnable() override;
		void OnDisable() override;
		void OnDestroy() override;

	private:
		std::vector<Editor*> editors;
	};
}