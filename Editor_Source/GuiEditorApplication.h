#pragma once
#include "GuiEditor.h"
#include "GuiEditorWindow.h"
#include "GuiImguiEditor.h"

#include "..\\Engine_Source\\DXEngineRenderTarget.h"
#include "..\\Engine_Source\\DXEngineEvent.h"

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

		static void OnEvent(DXEngine::Event& e);

		static void OpenProject();
		static void NewScene();
		static void SaveScene();
		static void SaveSceneAs();
		static void OpenScene(const std::filesystem::path& path);

		static void OnImGuiRender();

		//Event
		static void SetCursorPos(double x, double y);

	private:
		static ImguiEditor* imguiEditor;

		static std::map<std::wstring, EditorWindow*> editorWindows;
		static ImGuiWindowFlags flag;
		static ImGuiDockNodeFlags dockspaceFlags;
		static EStateType state;
		static bool fullScreen;

		static DXEngine::Math::Vector2 viewportBounds[2];
		static DXEngine::Math::Vector2 viewportSize;
		static bool viewportFocused;
		static bool viewportHovered; 
		static int guizmoType;

		static DXEngine::Graphics::RenderTarget* frameBuffer;
		static DXEngine::EventCallbackFn eventCallback;
	};
}