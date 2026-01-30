#pragma once
#include "DXEngineEntity.h"

namespace DXEngine
{
	using namespace Enum;
	class UIBase : public Entity
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}
			void operator()()
			{
				if (mEvent)
					mEvent();
			}
			std::function<void()> mEvent;
		};

		UIBase(EUIType type);
		virtual ~UIBase();

		void Active();
		void InActive();

		void Init();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void UIClear();

		virtual void OnInit();
		virtual void OnActive();
		virtual void OnInActive();
		virtual void OnUpdate(); 
		virtual void OnLateUpdate();
		virtual void OnRender(HDC hdc);
		virtual void OnClear();

		EUIType GetUIType() { return uiType; }
		void SetType(EUIType type) { uiType = type; }
		void SetFullScreen(bool value) { isFullScreen = value; }
		bool GetIsFullScreen() { return isFullScreen; }
		Vector2 GetPos() { return position; }
		void SetPosition(Vector2 value) { position = value; }
		Vector2 GetSize() { return size; }
		void SetSize(Vector2 value) { size = value; }

	protected:
		Vector2 position;
		Vector2 size;
		bool isMouseOn;

	private:
		EUIType uiType;
		bool isFullScreen;
		bool isEnabled;
	};
}