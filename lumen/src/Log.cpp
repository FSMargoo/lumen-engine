/**
 * Log.cpp:
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/10/2025
 */

#include <spdlog/sinks/stdout_color_sinks-inl.h>

#include <Log.h>

namespace Lumen {

std::shared_ptr<spdlog::logger> Log::_coreLogger;
std::shared_ptr<spdlog::logger> Log::_clientLogger;

void Log::Init() {
	spdlog::set_pattern("%^[%H:%M:%S] [%n] [%l] [thread %t] %v%$");

	_coreLogger = spdlog::stdout_color_mt("Lumen");
	_coreLogger->set_level(spdlog::level::trace);

	_clientLogger = spdlog::stdout_color_mt("App");
	_clientLogger->set_level(spdlog::level::trace);
}

}
