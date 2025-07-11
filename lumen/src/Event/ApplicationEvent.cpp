/**
 * Application.cpp:
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/11/2025
 */

#include <Events/ApplicationEvent.h>

namespace Lumen {
WindowResizeEvent::WindowResizeEvent(const int &Width, const int &Height)
	: _width(Width), _height(Height) {

}

int WindowResizeEvent::GetHeight() const {
	return _height;
}

int WindowResizeEvent::GetWidth() const {
	return _width;
}

std::string WindowResizeEvent::ToString() const {
	return std::format("WindowResizeEvent(Width={}, Height={})", _width, _height);
}

}
