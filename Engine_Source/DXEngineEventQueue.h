#pragma once
#include "DXEngineEvent.h"

namespace DXEngine
{
	class EventQueue
	{
	public:
		EventQueue();
		~EventQueue();

		//template <typename T>
		//void RegisterHandler(const EventCallbackFn& callback)
		//{
		//	mCallback = callback;
		//}

		// 특정 이벤트 타입에 대한 핸들러 등록
		template<typename T>
		void RegisterHandler(std::function<bool(T&)> handler)
		{
			handlers[T::GetStaticType()] = [handler](Event& e) -> bool
				{ return handler(static_cast<T&>(e)); };
		}

		void Push(Event* event)
		{
			queue.push(event);
		}

		void Process()
		{
			while (!queue.empty())
			{
				Event* event = queue.front();
				queue.pop();

				EventDispatcher dispatcher(*event);

				// 등록된 핸들러 실행
				auto handler = handlers.find(event->GetEventType());
				if (handler != handlers.end())
					event->Handled != handler->second(*event);

				// 기본 핸들러 실행 (처리되지 않은 경우)
				if (!event->Handled && callback)
					callback(*event);

				delete event;
				event = nullptr;
			}
		}

		void SetCallback(const EventCallbackFn& callback)
		{
			this->callback = callback;
		}

	private:
		std::queue<Event*> queue;
		EventCallbackFn callback;
		std::unordered_map<EEventType, HandlerCallbackFn> handlers;
	};
}