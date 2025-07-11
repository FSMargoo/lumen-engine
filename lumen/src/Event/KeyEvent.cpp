/**
 * KeyEvent.cpp:
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/11/2025
 */

#include <Events/KeyEvent.h>

namespace Lumen {
KeyEvent::KeyEvent(int KeyCode)
	: _keyCode(KeyCode) {

}

int KeyEvent::GetKeyCode() const {
	return _keyCode;
}

KeyPressedEvent::KeyPressedEvent(const int KeyCode, const int RepeatCount)
	: KeyEvent(KeyCode), _repeatCount(RepeatCount) {

}

std::string KeyPressedEvent::ToString() const {
	return std::format("KeyPressedEvent(KeyCode={}, RepeatCount={})", _keyCode, _repeatCount);
}

KeyReleasedEvent::KeyReleasedEvent(int KeyCode) : KeyEvent(KeyCode) {

}

std::string KeyReleasedEvent::ToString() const {
	return std::format("KeyReleasedEvent(KeyCode={})", _keyCode);
}

}
