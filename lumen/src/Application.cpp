/**
 * Application.cpp:
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/10/2025
 */

#include <Application.h>

namespace Lumen {
bool Application::OnWindowClose(WindowCloseEvent &E) {
	_running = false;

	return true;
}
}