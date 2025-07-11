/**
 * MouseEvent.cpp:
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/11/2025
 */

#include <Events/MouseEvent.h>

namespace Lumen {
MouseMovedEvent::MouseMovedEvent(const float &X, const float &Y)
	: _mouseX(X), _mouseY(Y) {

}

float MouseMovedEvent::GetX() const {
	return _mouseX;
}

float MouseMovedEvent::GetY() const {
	return _mouseY;
}

std::string MouseMovedEvent::ToString() const {
	return std::format("MouseMovedEvent(X={}, Y={})", _mouseX, _mouseY);
}

MouseScrollEvent::MouseScrollEvent(const float &XOffset, const float &YOffset)
	: _mouseXOffset(XOffset), _mouseYOffset(YOffset) {

}

float MouseScrollEvent::GetXOffset() const {
	return _mouseXOffset;
}

float MouseScrollEvent::GetYOffset() const {
	return _mouseYOffset;
}

std::string MouseScrollEvent::ToString() const {
	return std::format("MouseScrollEvent(X={}, Y={})", _mouseXOffset, _mouseYOffset);
}

MouseButtonEvent::MouseButtonEvent(const int &Button)
	: _button(Button) {

}

int MouseButtonEvent::GetMouseButton() const {
	return _button;
}

MouseButtonPressedEvent::MouseButtonPressedEvent(const int &Button) : MouseButtonEvent(Button) {

}

std::string MouseButtonPressedEvent::ToString() const {
	return std::format("MouseButtonPressedEvent(Button={})", _button);
}

MouseButtonReleasedEvent::MouseButtonReleasedEvent(const int &Button) : MouseButtonEvent(Button) {

}

std::string MouseButtonReleasedEvent::ToString() const {
	return std::format("MouseButtonReleasedEvent(Button={})", _button);
}
}
