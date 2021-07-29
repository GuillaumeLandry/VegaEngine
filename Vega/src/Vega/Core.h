#pragma once

#ifdef VG_PLATFORM_WINDOWS
	#ifdef VG_BUILD_DLL
		#define VEGA_API _declspec(dllexport)
	#else
		#define	VEGA_API __declspec(dllimport)
	#endif
#else
	#error Vega only supports Windows !
#endif

