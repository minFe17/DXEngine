#pragma once
#include "guiEditor.h"
#include "guiEditorWindow.h"

#include "..\\Engine_Source\\DXEngineEvent.h"

namespace Gui
{
	class ImguiEditor : public EditorWindow
	{
	public:
		ImguiEditor();
		~ImguiEditor();

		void Init() override;
		void Update() override;
		void OnGUI() override;
		void Run() override;
		void OnEnable() override;
		void OnDisable() override;
		void OnDestroy() override;
		void OnEvent(DXEngine::Event& e) override;

		void Begin();
		void End();
		void Release();
		void SetDarkThemeColors();

		void BlockEvent(bool block) { blockEvent = block; }

	private:
		bool blockEvent;
	};
}