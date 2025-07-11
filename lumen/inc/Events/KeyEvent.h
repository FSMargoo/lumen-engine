/**
 * KeyEvent.h:
 *      @Descripiton    :   The events for keyboard
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/11/2025
 */

#ifndef KEYEVENT_H
#define KEYEVENT_H

#include <Events/Event.h>

namespace Lumen {
/**
 * The basic event class for key events
 */
class KeyEvent : public Event {
public:
	/**
	 * Getting the key code
	 * @return Getting the key code of the event
	 */
	[[nodiscard]] int GetKeyCode() const;

public:
	EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)

protected:
	explicit KeyEvent(int KeyCode);

	int _keyCode;
};

/**
 * The key pressed event
 */
class KeyPressedEvent : public KeyEvent {
public:
	KeyPressedEvent(int KeyCode, int RepeatCount);

public:
	[[nodiscard]] std::string ToString() const override;

public:
	EVENT_CLASS_TYPE(EventType::KeyPressed)

private:
	int _repeatCount;
};

/**
 * The key released event
 */
class KeyReleasedEvent : public KeyEvent {
public:
 	explicit KeyReleasedEvent(int KeyCode);

public:
	[[nodiscard]] std::string ToString() const override;

public:
	EVENT_CLASS_TYPE(EventType::KeyReleased)
};
}

#endif //KEYEVENT_H
