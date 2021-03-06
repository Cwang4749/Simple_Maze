#pragma once

#include "PrecompH.h"

#ifdef YAM_WINDOWS
	#ifdef YAM_LIB
		#define YAM_API __declspec(dllexport)
	#else
		#define YAM_API __declspec(dllimport)
	#endif
#else
	#define YAM_API
#endif

#ifdef YAM_DEBUG
	#define YAM_LOG(x) std::cout<<x<<std::endl;
#else
	#define YAM_LOG(x)
#endif