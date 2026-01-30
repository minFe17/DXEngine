#pragma once
#include "CommonInclude.h"
#include "DXEngineUIBase.h"

namespace DXEngine
{
	using namespace Enum;
	class UIManager
	{
	public:
		static void Init();
		static void OnLoad(EUIType type);
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void OnComplete(UIBase* addUI);
		static void OnFail();
		static void Release();

		static void Push(EUIType type);
		static void Pop(EUIType type);

	private:
		static std::unordered_map<EUIType, UIBase*> uis;
		static std::stack<UIBase*> uiBases;
		static std::queue<EUIType> requestUIQueue;
		static UIBase* activeUI;
	};
}