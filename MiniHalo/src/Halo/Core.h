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