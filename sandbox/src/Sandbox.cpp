/**
 * main.cpp:
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/10/2025
 */

#include <lumen/Lumen.h>

#include <memory>

class ExampleLayer : public Lumen::Layer {
public:
	ExampleLayer()
		: Layer("ExampleLayer") {
	}

public:
	void OnUpdate() override {
		Lumen::Log::Info("ExampleLayer::OnUpdate");
	}
	void OnEvent(Lumen::Event& e) override {
		Lumen::Log::Info("ExampleLayer::OnEvent, {}", e.ToString());
	}
};

class Sandbox : public Lumen::Application {
public:
	Sandbox() {
		_window = std::unique_ptr<Lumen::Window>(Lumen::Window::Create({}));
		_window->SetEventCallback([this]<typename T0>(T0 &&PH1) {
			OnEvent(std::forward<T0>(PH1));
		});

		PushLayer(new ExampleLayer());
	}

	~Sandbox() override = default;

public:
	void OnEvent(Lumen::Event &E) override {
		Application::OnEvent(E);

		Lumen::Log::Trace("{0}", E.ToString());
	}

	int Run() override {
		while (_running) {
			Application::OnUpdate();

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
