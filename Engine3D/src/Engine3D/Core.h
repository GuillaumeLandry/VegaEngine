#pragma once

#ifdef E3_PLATFORM_WINDOWS
	#ifdef E3_BUILD_DLL
		#define Engine3D_API _declspec(dllexport)
	#else
		#define	Engine3D_API __declspec(dllimport)
	#endif
#else
	#error Engine3D only supports Windows !
#endif


