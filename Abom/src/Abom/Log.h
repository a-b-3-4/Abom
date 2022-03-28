#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Abom
{
	class ABOM_API Log
	{
	public:
		static void Initialize();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }
		static void Finalize();
	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}

//core log macros
#define AB_CORE_TRACE(...)  ::Abom::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AB_CORE_INFO(...)   ::Abom::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AB_CORE_WARN(...)   ::Abom::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AB_CORE_ERROR(...)  ::Abom::Log::GetCoreLogger()->error(__VA_ARGS__)

//client log macros
#define AB_TRACE(...)       ::Abom::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AB_INFO(...)        ::Abom::Log::GetClientLogger()->info(__VA_ARGS__)
#define AB_WARN(...)        ::Abom::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AB_ERROR(...)       ::Abom::Log::GetClientLogger()->error(__VA_ARGS__)