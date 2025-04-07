#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace MiniHalo {

	class HALO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger> GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core Log macros
#define HA_CORE_TRACE(...)		::MiniHalo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HA_CORE_INFO(...)		::MiniHalo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HA_CORE_WARN(...)		::MiniHalo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HA_CORE_ERROR(...)		::MiniHalo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HA_CORE_FATAL(...)		::MiniHalo::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros
#define HA_TRACE(...)			::MiniHalo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HA_INFO(...)			::MiniHalo::Log::GetClientLogger()->info(__VA_ARGS__)
#define HA_WARN(...)			::MiniHalo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HA_ERROR(...)			::MiniHalo::Log::GetClientLogger()->error(__VA_ARGS__)
#define HA_FATAL(...)			::MiniHalo::Log::GetClientLogger()->fatal(__VA_ARGS__)