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

	}
	void OnEvent(Lumen::Event& e) override {

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
		PushLayer(new Lumen::ImGUILayer());
	}

	~Sandbox() override = default;

public:
	void OnEvent(Lumen::Event &E) override {
		Application::OnEvent(E);
	}

	int Run() override {
		while (_running) {
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			Application::OnUpdate();

			_window->OnUpdate();
		}

		return 0;
	}

public:
	Lumen::Window* GetWindow() override {
		return _window.get();
	}

private:
	std::unique_ptr<Lumen::Window> _window;
};

Lumen::Application *Lumen::CreateApplication() {
	auto app = new Sandbox();

	return app;
}
