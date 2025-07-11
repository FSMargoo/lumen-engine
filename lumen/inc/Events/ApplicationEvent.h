/**
 * Application.h:
 *      @Descripiton    :   The events of the application
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/11/2025
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include <Events/Event.h>

namespace Lumen {
/**
 * When the window was resized, this event will be generated
 */
class WindowResizeEvent : public Event {
public:
	WindowResizeEvent(const int &Width, const int &Height);

public:
	[[nodiscard]] int GetWidth() const;

	[[nodiscard]] int GetHeight() const;

	[[nodiscard]] std::string ToString() const override;

public:
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
	EVENT_CLASS_TYPE(WindowResize)

private:
	int _width;
	int _height;
};

/**
 * When the window was closed, this event will be generated
 */
class WindowCloseEvent : public Event {
public:
	WindowCloseEvent() = default;

public:
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
	EVENT_CLASS_TYPE(WindowClose)
};

/**
 * When the window was focused, this event will be generated
 */
class WindowFocusEvent : public Event {
public:
	WindowFocusEvent() = default;

public:
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
	EVENT_CLASS_TYPE(WindowFocus)
};

/**
 * When the window was lost focused, this event will be generated
 */
class WindowLostFocusEvent : public Event {
public:
	WindowLostFocusEvent() = default;

public:
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
	EVENT_CLASS_TYPE(WindowLostFocus)
};

/**
 * When the window was lost focused, this event will be generated
 */
class WindowMovedEvent : public Event {
public:
	WindowMovedEvent() = default;

public:
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
	EVENT_CLASS_TYPE(WindowMoved)
};

class AppTickEvent : public Event {
public:
	AppTickEvent() = default;

public:
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
	EVENT_CLASS_TYPE(AppTick)
};

class AppRenderEvent : public Event {
public:
	AppRenderEvent() = default;

public:
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
	EVENT_CLASS_TYPE(AppRender)
};

class AppUpdateEvent : public Event {
public:
	AppUpdateEvent() = default;

public:
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
	EVENT_CLASS_TYPE(AppUpdate)
};
}

#endif //APPLICATION_H
