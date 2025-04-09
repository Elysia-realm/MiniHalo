#pragma once

#ifdef HALO_PLATFORM_WINDOWS
	#ifdef HALO_BUILD_DLL
		#define HALO_API __declspec(dllexport)
	#else
		#define HALO_API __declspec(dllimport)
	#endif 
#else
	#error MiniHalo Only support Windows!
#endif

#ifdef HA_ENABLE_ASSERTS
	#define HA_CORE_ASSERT(x, ...) { if(!(x)) { HA_CORE_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak(); } }
	#define HA_ASSERT(x, ...) { if(!(x)) { HA_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HA_COER_ASSERT(x, ...)
	#define HA_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)