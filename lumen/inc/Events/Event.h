/**
 * Event.h:
 *      @Descripiton    :   The basic event defintion for the event system
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/11/2025
 */

#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <functional>

#include <Log.h>
#include <Core.h>

namespace Lumen {
/**
 * For now, the events in Lumen Engine are blocking.
 */

/**
 * The event types
 */
enum class EventType {
	None = 0,
	WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
	AppTick, AppUpdate, AppRender,
	KeyPressed, KeyReleased,
	MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

/**
 * The category for an event
 */
enum EventCategory {
	None                     = 0,
	EventCategoryApplication = BIT(0),
	EventCategoryInput       = BIT(1),
	EventCategoryKeyboard    = BIT(2),
	EventCategoryMouse       = BIT(3),
	EventCategoryMouseButton = BIT(4),
};

class Event {
public:
	Event() = default;

	virtual ~Event() = default;

public:
	/**
	 * Getting the type of the event
	 * @return The type of the event
	 */
	[[nodiscard]] virtual EventType GetEventType() const = 0;

	/**
	 * Getting the name of the event
	 * @return The name of the event
	 */
	[[nodiscard]] virtual const char *GetName() const = 0;

	/**
	 * Getting the category of the event
	 * @return The category of the event
	 */
	[[nodiscard]] virtual int GetCategory() const = 0;

	/**
	 * Getting the name of the event in string
	 * @return The string of the event's name
	 */
	[[nodiscard]] virtual std::string ToString() const;

	/**
	 * Judging whether the event in the category
	 * @param Category The category to be judged
	 * @return If the event in the category, returning true, nor false
	 */
	__forceinline bool IsInCategory(EventCategory Category) const {
		return GetCategory() & Category;
	}

	[[nodiscard]] bool IsHandled() const {
		return _handled;
	}

protected:
	bool _handled = false;

private:
	friend class EventDispatcher;
};

/**
 * The dispatcher for the events
 */
class EventDispatcher {
public:
	template <class T>
	using EventFunction = std::function<bool(T &)>;

public:
	explicit EventDispatcher(Event &E);

	/**
	 * Dispatching an event
	 * @tparam T The type for the event
	 * @param Function The dispatch function
	 * @return If the event was dispathced, returning true, nor false
	 */
	template <class T>
	bool Dispatch(EventFunction<T> Function) {
		if (_event.GetEventType() == T::GetStaticType()) {
			_event._handled = Function(*static_cast<T *>(&_event));

			return true;
		}

		return false;
	}

private:
	Event &_event;
};

#define EVENT_CLASS_TYPE(Type) static EventType GetStaticType() { return EventType::Type; } \
		virtual EventType GetEventType() const override { return GetStaticType(); } \
		virtual const char *GetName() const override { return #Type; }

#define EVENT_CLASS_CATEGORY(Category) virtual int GetCategory() const override { return Category; }

}

#endif //EVENT_H
