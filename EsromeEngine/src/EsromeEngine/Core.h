#pragma once

#ifdef EE_PLATFORM_WINDOWS
	#ifdef EE_BUILD_DLL
		#define ESROME_API __declspec(dllexport)
	#else
		#define ESROME_API __declspec(dllimport)
	#endif
#else
	#error Windows is the only platform currently supported!
#endif