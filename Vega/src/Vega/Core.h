#pragma once

#ifdef E3_PLATFORM_WINDOWS
	#ifdef E3_BUILD_DLL
		#define VEGA_API _declspec(dllexport)
	#else
		#define	VEGA_API __declspec(dllimport)
	#endif
#else
	#error Vega only supports Windows !
#endif

