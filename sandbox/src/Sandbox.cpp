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

	}

	~Sandbox() {
	}

public:
	int Run() override {
		while (true) {
		}

		return 0;
	}
};

Lumen::Application* Lumen::CreateApplication() {
	auto app = new Sandbox();

	return app;
}