#pragma once
#include "GuiEntity.h"

namespace Gui
{
	/// <summary>
	/// Editor는 특정 컴포넌트의 Inspector를 커스터마이징하는 데 사용
	/// Inspector 창에 표시되는 UI를 재정의하거나 확장
	/// </summary>
	class Editor : public Entity
	{
	public:
		enum class EStatetype
		{
			Paused,
			Active,
			Disabled,
			Destroyed,
			Max
		};

		Editor();
		virtual ~Editor();

		virtual void Initialize();
		virtual void Update();
		virtual void OnGUI();
		virtual void OnEnable();
		virtual void OnDisable();
		virtual void OnDestroy();

	private:
		EStatetype state;
	};
}