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
		EditorWindow();
		virtual ~EditorWindow();

		virtual void Init();
		virtual void Update();
		virtual void OnGUI();
		virtual void OnEnable();
		virtual void OnDisable();
		virtual void OnDestroy();

	private:
	};
}