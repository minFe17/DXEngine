#pragma once
#include "GuiEditor.h"
#include "GuiEditorWindow.h"

namespace Gui
{
	/// <summary>
	/// EditorApplication 클래스는 에디터에서 사용되는 메인 클래스
	/// 에디터의 메인 루프를 실행하고 에디터의 초기화 및 종료를 담당
	/// </summary>
	class EditorApplication
	{
	public:
		enum class EStateType
		{
			Disable,
			Active,
			Destroy,
			Max
		};

		template <typename T>
		T* GetWindow(const std::wstring& name)
		{
			auto iter = editorWindows.find(name);
			if (iter == editorWindows.end())
				return nullptr;

			return dynamic_cast<T*>(iter->second);
		}

		static bool Init();
		static void Update();
		static void OnGUI();
		static void Run();

		static void Release();

	private:
		static bool ImGuiInit();
		static void ImGuiRender();
		static void DockSpaceUpdate();
		static void DockSpaceOnGui();

		static ImGuiWindowFlags flag;
		static ImGuiDockNodeFlags dockspaceFlags;
		static EStateType state;
		static bool fullScreen;
		static bool padding;

		static std::map<std::wstring, EditorWindow*> editorWindows;
	};
}