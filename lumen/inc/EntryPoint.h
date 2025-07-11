/**
 * EntryPoint.h:
 *      @Descripiton    :   The entry point definitions
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/10/2025
 */
#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include <memory>

#include <Log.h>
#include <Application.h>

int main(int argc, char **argv) {
	Lumen::Log::Init();

	Lumen::Log::CoreInfo("Lumen Engine has started!");

	auto app = Lumen::CreateApplication();
	auto code = app->Run();

	delete app;

	return code;
}

#endif //ENTRYPOINT_H
