#include "DXEngineUIManager.h"

namespace DXEngine
{
	std::unordered_map<EUIType, UIBase*> UIManager::uis = {};
	std::stack<UIBase*> UIManager::uiBases = {};
	std::queue<EUIType> UIManager::requestUIQueue = {};
	UIBase* UIManager::activeUI = nullptr;

	void UIManager::Init()
	{
	}

	void UIManager::OnLoad(EUIType type)
	{
		std::unordered_map<EUIType, UIBase*>::iterator iter = uis.find(type);

		if (iter == uis.end())
		{
			OnFail();
			return;
		}
		OnComplete(iter->second);
	}

	void UIManager::Update()
	{
		std::stack<UIBase*> uiStack = uiBases;
		while (!uiStack.empty())
		{
			UIBase* uiBase = uiStack.top();
			if (uiBase)
			{
				uiBase->Update();
				uiStack.pop();
			}
		}

		if (requestUIQueue.size() > 0)
		{
			EUIType requestUI = requestUIQueue.front();
			requestUIQueue.pop();
			OnLoad(requestUI);
		}
	}

	void UIManager::LateUpdate()
	{
		std::stack<UIBase*> uiStack = uiBases;
		while (!uiStack.empty())
		{
			UIBase* uiBase = uiStack.top();
			if (uiBase)
			{
				uiBase->LateUpdate();
				uiStack.pop();
			}
		}
	}

	void UIManager::Render()
	{
		std::stack<UIBase*> uiStack = uiBases;
		while (!uiStack.empty())
		{
			UIBase* uiBase = uiStack.top();
			if (uiBase)
			{
				uiBase->Render();
				uiStack.pop();
			}
		}
	}

	void UIManager::OnComplete(UIBase* addUI)
	{
		if (addUI == nullptr)
			return;

		addUI->Init();
		addUI->Active();
		addUI->Update();

		if (addUI->GetIsFullScreen())
		{
			std::stack<UIBase*> uiStack = uiBases;
			while (!uiStack.empty())
			{
				UIBase* uiBase = uiStack.top();
				uiStack.pop();

				if (uiBase)
					uiBase->InActive();
			}
		}

		uiBases.push(addUI);
		activeUI = addUI;
	}

	void UIManager::OnFail()
	{
		activeUI = nullptr;
	}

	void UIManager::Release()
	{
		for (auto iter : uis)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	void UIManager::Push(EUIType type)
	{
		requestUIQueue.push(type);
	}

	void UIManager::Pop(EUIType type)
	{
		if (uiBases.size() <= 0)
			return;

		std::stack<UIBase*> tempStack;

		UIBase* ui = nullptr;
		while (uiBases.size() > 0)
		{
			ui = uiBases.top(); 
			uiBases.pop();

			if (ui->GetUIType() != type)
			{
				tempStack.push(ui);
				continue;
			}

			if (ui->GetIsFullScreen())
			{
				std::stack<UIBase*> uiStack = uiBases;
				while (!uiStack.empty())
				{
					UIBase* uiBase = uiStack.top();
					uiStack.pop();
					if(uiBase)
					{
						uiBase->Active();
						break;
					}
				}
			}

			ui->UIClear();
		}

		while (tempStack.size() > 0)
		{
			ui = tempStack.top();
			tempStack.pop();
			uiBases.push(ui);
		}
	}
}