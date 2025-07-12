/**
 * Application.cpp:
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/10/2025
 */

#include <Application.h>

namespace Lumen {
void Application::OnEvent(Event &E) {
	EventDispatcher dispatcher(E);
	dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

	for (auto iterator = _layerStack.end(); iterator != _layerStack.begin(); ) {
		(*(--iterator))->OnEvent(E);
		if (E.IsHandled()) {
			break;
		}
	}
}

void Application::OnUpdate() {
	for (auto &layer : _layerStack) {
		layer->OnUpdate();
	}
}

void Application::PushLayer(Layer *Layer) {
	_layerStack.PushLayer(Layer);
}

void Application::PushOverlay(Layer *Overlay) {
	_layerStack.PushOverlay(Overlay);
}

bool Application::OnWindowClose(WindowCloseEvent &E) {
	_running = false;

	return true;
}
}
