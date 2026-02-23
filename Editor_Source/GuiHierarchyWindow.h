#pragma once

#include "GuiEditorWindow.h"
#include "GuiEditor.h"

namespace Gui
{
	class HierarchyWindow : public EditorWindow
	{
	public:
		HierarchyWindow();
		~HierarchyWindow();

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