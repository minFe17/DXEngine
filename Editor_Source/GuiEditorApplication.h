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
		static bool Init();
		static void Update();
		static void OnGUI();
		static void Run();

		static void Release();

	private:
		static bool ImGuiInit();
		static void ImGuiRender();
	};
}