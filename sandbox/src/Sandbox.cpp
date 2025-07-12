/**
 * main.cpp:
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/10/2025
 */

#include <lumen/Lumen.h>

#include <memory>

class Sandbox : public Lumen::Application {
public:
	Sandbox() {
		_window = std::unique_ptr<Lumen::Window>(Lumen::Window::Create({}));
		_window->SetEventCallback([this]<typename T0>(T0 &&PH1) {
			OnEvent(std::forward<T0>(PH1));
		});
	}

	~Sandbox() override = default;

public:
	void OnEvent(Lumen::Event &E) {
		Lumen::EventDispatcher dispatcher(E);
		dispatcher.Dispatch<Lumen::WindowCloseEvent>(
			std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

		Lumen::Log::Trace("{0}", E.ToString());
	}

	int Run() override {
		while (_running) {
			_window->OnUpdate();
		}

		return 0;
	}

private:
	std::unique_ptr<Lumen::Window> _window;
};

Lumen::Application *Lumen::CreateApplication() {
	auto app = new Sandbox();

	return app;
}
