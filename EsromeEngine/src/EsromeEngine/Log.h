#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace EsromeEngine {
	class ESROME_API Log
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

//Core Log Macros
#define EE_CORE_TRACE(...)		::EsromeEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EE_CORE_INFO(...)		::EsromeEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EE_CORE_WARN(...)		::EsromeEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EE_CORE_ERROR(...)		::EsromeEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EE_CORE_CRITICAL(...)	::EsromeEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client Log Macros
#define EE_TRACE(...)			::EsromeEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EE_INFO(...)			::EsromeEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define EE_WARN(...)			::EsromeEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EE_ERROR(...)			::EsromeEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define EE_CRITICAL(...)		::EsromeEngine::Log::GetClientLogger()->critical(__VA_ARGS__)