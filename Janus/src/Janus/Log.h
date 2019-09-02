#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"


namespace Janus {
	class JANUS_API Log
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

#define JN_CORE_TRACE(...)    ::Janus::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define JN_CORE_INFO(...)     ::Janus::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JN_CORE_WARN(...)     ::Janus::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JN_CORE_ERROR(...)    ::Janus::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JN_CORE_FATAL(...)    ::Janus::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros

#define JN_TRACE(...)         ::Janus::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JN_INFO(...)          ::Janus::Log::GetClientLogger()->info(__VA_ARGS__)
#define JN_WARN(...)          ::Janus::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JN_ERROR(...)         ::Janus::Log::GetClientLogger()->error(__VA_ARGS__)
#define JN_FATAL(...)         ::Janus::Log::GetClientLogger()->fatal(__VA_ARGS__)



