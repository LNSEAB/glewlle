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
#
#	define GLEWLLE_WINDOWS
#	include <windows.h>
#endif

#if defined( __linux ) || defined( __linux__ ) || defined( linux )
#	define GLEWLLE_LINUX
#	include <GL/glx.h>
#endif

#include <GL/gl.h>
#include "glext.h"
