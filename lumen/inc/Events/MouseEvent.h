/**
 * MouseEvent.h:
 *      @Descripiton    :   The events of mouse action
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/11/2025
 */
#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include <Events/Event.h>

namespace Lumen {
/**
 * When the cursor moved, this event will be generated
 */
class MouseMovedEvent : public Event {
public:
	MouseMovedEvent(const float &X, const float &Y);

public:
	/**
	 * Getting the X position of the mouse
	 * @return The X position of the mouse
	 */
	[[nodiscard]] float GetX() const;

	/**
	 * Getting the Y position of the mouse
	 * @return The Y position of the mouse
	 */
	[[nodiscard]] float GetY() const;

	[[nodiscard]] std::string ToString() const override;

public:
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	EVENT_CLASS_TYPE(MouseMoved)

private:
	float _mouseX;
	float _mouseY;
};

/**
 * When the cursor scrolled, this event will be generated
 */
class MouseScrollEvent : public Event {
public:
	MouseScrollEvent(const float &XOffset, const float &YOffset);

public:
	/**
	 * Getting the X offset of the scroll
	 * @return The X offset of the scroll
	 */
	[[nodiscard]] float GetXOffset() const;

	/**
	 * Getting the Y offset of the scroll
	 * @return The Y offset of the scroll
	 */
	[[nodiscard]] float GetYOffset() const;

	[[nodiscard]] std::string ToString() const override;

public:
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	EVENT_CLASS_TYPE(MouseScrolled)

private:
	float _mouseXOffset;
	float _mouseYOffset;
};

/**
 * The base event class for the mouse button
 */
class MouseButtonEvent : public Event {
public:
	/**
	 * Getting the button that mouse has pressed
	 * @return The button that mouse pressed
	 */
	[[nodiscard]] int GetMouseButton() const;

public:
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

protected:
	explicit MouseButtonEvent(const int &Button);

protected:
	int _button;
};

class MouseButtonPressedEvent : public MouseButtonEvent {
public:
	explicit MouseButtonPressedEvent(const int &Button);

public:
	[[nodiscard]] std::string ToString() const override;

public:
	EVENT_CLASS_TYPE(MouseButtonPressed)
};

class MouseButtonReleasedEvent : public MouseButtonEvent {
public:
	explicit MouseButtonReleasedEvent(const int &Button);

public:
	[[nodiscard]] std::string ToString() const override;

public:
	EVENT_CLASS_TYPE(MouseButtonReleased)
};
}

#endif //MOUSEEVENT_H
