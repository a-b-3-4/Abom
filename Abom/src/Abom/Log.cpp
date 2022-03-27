#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Abom
{
	std::shared_ptr<spdlog::logger> Log::coreLogger;
	std::shared_ptr<spdlog::logger> Log::clientLogger;
	
	void Log::Initialize()
	{
		spdlog::set_pattern("[%T] %n: %v%$");

		coreLogger = spdlog::stdout_color_mt("abom");
		coreLogger->set_level(spdlog::level::trace);

		clientLogger = spdlog::stdout_color_mt("app");
		clientLogger->set_level(spdlog::level::trace);
	}
}