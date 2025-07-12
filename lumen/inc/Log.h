/**
 * Log.h:
 *      @Descripiton    :   The log class for Lumen Engine
 *      @Author         :   Margoo(qiuzhengyu@acm.org)
 *      @Date           :   7/10/2025
 */

#ifndef LOG_H
#define LOG_H

#include <spdlog/spdlog.h>
#include <spdlog/fmt/fmt.h>

namespace Lumen {
/**
 * The log class for Lumen Engine
 */
class Log {
public:
	Log() = default;

	~Log() = default;

public:
	static void Init();

public:
	/**
	 * Get the core logger instance
	 * @return The core logger instance
	 */
	static std::shared_ptr<spdlog::logger> &GetCoreLogger() {
		return _coreLogger;
	}

	/**
	 * Get the client logger instance
	 * @return The client logger instance
	 */
	static std::shared_ptr<spdlog::logger> &GetClientLogger() {
		return _clientLogger;
	}

public:
	/**
	 * Output the trace level's log
	 * @param Arg The formats of the log
	 */
	template <typename... Args>
	static void CoreTrace(spdlog::format_string_t<Args...> fmt, Args &&...Arg) {
#ifndef LumenRelease
		_coreLogger->trace(fmt, std::forward<Args>(Arg)...);
#endif
	}
	/**
	 * Output the info level's log
	 * @param Arg The formats of the log
	 */
	template <typename... Args>
	static void CoreInfo(spdlog::format_string_t<Args...> fmt, Args &&...Arg) {
#ifndef LumenRelease
		_coreLogger->info(fmt, std::forward<Args>(Arg)...);
#endif
	}
	/**
	 * Output the warning level's log
	 * @param Arg The formats of the log
	 */
	template <typename... Args>
	static void CoreWarn(spdlog::format_string_t<Args...> fmt, Args &&...Arg) {
#ifndef LumenRelease
		_coreLogger->info(fmt, std::forward<Args>(Arg)...);
#endif
	}
	/**
	 * Output the error level's log
	 * @param Arg The formats of the log
	 */
	template <typename... Args>
	static void CoreErr(spdlog::format_string_t<Args...> fmt, Args &&...Arg) {
#ifndef LumenRelease
		_coreLogger->error(fmt, std::forward<Args>(Arg)...);
#endif
	}
	/**
	 * Output the fatal level's log
	 * @param Arg The formats of the log
	 */
	template <typename... Args>
	static void CoreFatal(spdlog::format_string_t<Args...> fmt, Args &&...Arg) {
#ifndef LumenRelease
		_coreLogger->critical(fmt, std::forward<Args>(Arg)...);
#endif
	}

	/**
	 * Output the trace level's log
	 * @param Arg The formats of the log
	 */
	template <typename... Args>
	static void Trace(spdlog::format_string_t<Args...> fmt, Args &&...Arg) {
#ifndef LumenRelease
		_clientLogger->trace(fmt, std::forward<Args>(Arg)...);
#endif
	}
	/**
	 * Output the info level's log
	 * @param Arg The formats of the log
	 */
	template <typename... Args>
	static void Info(spdlog::format_string_t<Args...> fmt, Args &&...Arg) {
#ifndef LumenRelease
		_clientLogger->info(fmt, std::forward<Args>(Arg)...);
#endif
	}
	/**
	 * Output the warning level's log
	 * @param Arg The formats of the log
	 */
	template <typename... Args>
	static void Warn(spdlog::format_string_t<Args...> fmt, Args &&...Arg) {
#ifndef LumenRelease
		_clientLogger->info(fmt, std::forward<Args>(Arg)...);
#endif
	}
	/**
	 * Output the error level's log
	 * @param Arg The formats of the log
	 */
	template <typename... Args>
	static void Err(spdlog::format_string_t<Args...> fmt, Args &&...Arg) {
#ifndef LumenRelease
		_clientLogger->error(fmt, std::forward<Args>(Arg)...);
#endif
	}
	/**
	 * Output the fatal level's log
	 * @param Arg The formats of the log
	 */
	template <typename... Args>
	static void Fatal(spdlog::format_string_t<Args...> fmt, Args &&...Arg) {
#ifndef LumenRelease
		_clientLogger->critical(fmt, std::forward<Args>(Arg)...);
#endif
	}

public:
	static std::shared_ptr<spdlog::logger> _coreLogger;
	static std::shared_ptr<spdlog::logger> _clientLogger;
};

#ifndef LUMEN_DEBUG
#	define LUMEN_ASSERT(x, ...)			{ if(!(x)) { Log::Fatal("Asertion Failed : {0}", __VA_ARGS__); __debugbreak(); } }
#	define LUMEN_CORE_ASSERT(x, ...)	{ if(!(x)) { Log::CoreFatal("Asertion Failed : {0}", __VA_ARGS__); __debugbreak(); } }
#else
#	define LUMEN_ASSERT(x, ...)
#	define LUMEN_CORE_ASSERT(x, ...)
#endif
}

#endif //LOG_H
