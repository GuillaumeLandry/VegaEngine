#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Vega {
	class VEGA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define VG_CORE_FATAL(...)	::Vega::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define VG_CORE_ERROR(...)	::Vega::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VG_CORE_WARN(...)	::Vega::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VG_CORE_INFO(...)	::Vega::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VG_CORE_TRACE(...)	::Vega::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define VG_FATAL(...)		::Vega::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define VG_ERROR(...)		::Vega::Log::GetClientLogger()->error(__VA_ARGS__)
#define VG_WARN(...)		::Vega::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VG_INFO(...)		::Vega::Log::GetClientLogger()->info(__VA_ARGS__)
#define VG_TRACE(...)		::Vega::Log::GetClientLogger()->trace(__VA_ARGS__)

