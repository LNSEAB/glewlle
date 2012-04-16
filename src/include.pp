#include <utility>
#include <stdexcept>

#if defined( WIN32 ) || defined( _WIN32 ) || defined( __WIN32__ ) || defined( WIN64 ) || defined( _WIN64 ) || defined( __WIN64__ )
#	if !defined( WIN32_LEAN_AND_MEAN )
#		define WIN32_LEAN_AND_MEAN
#	endif
#
#	if !defined( NOMINMAX )
#		define NOMINMAX
#	endif
#	include <windows.h>
#endif

#include "glext.h"
