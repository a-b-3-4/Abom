#pragma once

#ifdef AB_PLATFORM_WINDOWS
	#ifdef AB_BUILD_DLL
		#define ABOM_API __declspec(dllexport)
	#else
		#define ABOM_API __declspec(dllimport)
	#endif
#else
	#error Abom only supports Windows!
#endif