#pragma once
#include "GuiEditorWindow.h"
#include "GuiEditor.h"
namespace Gui
{
	class InspectorWindow : public EditorWindow
	{
	public:
		InspectorWindow();
		~InspectorWindow();

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