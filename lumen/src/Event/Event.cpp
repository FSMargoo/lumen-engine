/**
 * Event.cpp:
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/11/2025
 */

#include <Events/Event.h>

namespace Lumen {
std::string Event::ToString() const {
	return GetName();
}
EventDispatcher::EventDispatcher(Event &E) : _event(E) {

}
}