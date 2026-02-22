#pragma once
#include "GuiEntity.h"

namespace Gui
{
	/// <summary>
	/// EditorWindow는 독립적인 창을 생성하여 에디터에 새로운 도구나 워크플로우를 추가하는 데 사용
	/// 에디터에서 실행되는 완전히 새로운 사용자 인터페이스를 제공
	/// </summary>
	class EditorWindow :public Entity
	{
	public:
		enum class EStateType
		{
			Disable,
			Active,
			Destroy,
		};

		EditorWindow();
		virtual ~EditorWindow();

		virtual void Init();
		virtual void Update();
		virtual void OnGUI();
		virtual void Run();
		virtual void OnEnable();
		virtual void OnDisable();
		virtual void OnDestroy();
		virtual void OnEvent(DXEngine::Event& e) {}

		ImGuiWindowFlags GetFlag() const { return flag; }
		EStateType GetState() const { return state; }
		void SetState(EStateType type) { state = type; }
		ImVec2 GetSize() { return size; }
		void SetSize(ImVec2 value) { size = value; }

	private:
		ImGuiWindowFlags flag;
		EStateType state;
		ImVec2 size;
	};
}