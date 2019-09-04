#pragma once

#ifdef JN_PLATFORM_WINDOWS
#ifdef JN_BUILD_DLL
#define JANUS_API __declspec(dllexport)
#else
#define JANUS_API __declspec(dllimport)
#endif
#else
#error Janus only supports Windows!
#endif

#ifdef JN_ENABLE_ASSERTS
	#define JN_ASSERT(x, ...) { if(!(x)) {JN_ERROR{"Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define JN_CORE_ASSERT(x, ...) { if(!(x)) {JN_CORE_ERROR{"Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define JN_ASSERT(x, ...)
	#define JN_CORE_ASSERT(x, ...)
#endif

// Macro used to create bit codes for bit flagging systems
#define BIT(x) (1 << x)

// Function bind macro to improve readability when defining callbck functions
#define JN_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
