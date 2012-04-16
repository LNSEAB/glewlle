//
// glewlle
// Copyright (C) 2012 LNSEAB
//

/*
** Copyright (c) 2007-2012 The Khronos Group Inc.
** 
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
** 
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
** 
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/

#ifndef GLEWLLE_HPP_
#define GLEWLLE_HPP_

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

namespace glewlle {

#if defined( GLEWLLE_WINDOWS )
	typedef decltype( wglGetProcAddress( std::declval<char const*>() ) ) proc_address_type;
#elif defined( GLEWLLE_LINUX )
	typedef decltype( glXGetProcAddress( std::declval<GLubyte const*>() ) ) proc_address_type;
#endif

	inline proc_address_type get_proc_address(char const* name)
	{
#if defined( GLEWLLE_WINDOWS )
		return wglGetProcAddress( name );
#elif defined( GLEWLLE_LINUX )
		return glXGetProcAddress( reinterpret_cast<GLubyte const*>( name ) );
#endif
	}

} // namespace glewlle

inline void glBlendColor(GLfloat red,  GLfloat green,  GLfloat blue,  GLfloat alpha)
{
	typedef void (*proc_type)(GLfloat red,  GLfloat green,  GLfloat blue,  GLfloat alpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendColor" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendColor" ); }
	(*func_ptr)( red, green, blue, alpha );
}

inline void glBlendEquation(GLenum mode)
{
	typedef void (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquation" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquation" ); }
	(*func_ptr)( mode );
}

inline void glDrawRangeElements(GLenum mode,  GLuint start,  GLuint end,  GLsizei count,  GLenum type,  const GLvoid *indices)
{
	typedef void (*proc_type)(GLenum mode,  GLuint start,  GLuint end,  GLsizei count,  GLenum type,  const GLvoid *indices);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawRangeElements" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawRangeElements" ); }
	(*func_ptr)( mode, start, end, count, type, indices );
}

inline void glTexImage3D(GLenum target,  GLint level,  GLint internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLint internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexImage3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexImage3D" ); }
	(*func_ptr)( target, level, internalformat, width, height, depth, border, format, type, pixels );
}

inline void glTexSubImage3D(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexSubImage3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexSubImage3D" ); }
	(*func_ptr)( target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels );
}

inline void glCopyTexSubImage3D(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLint x,  GLint y,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLint x,  GLint y,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTexSubImage3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTexSubImage3D" ); }
	(*func_ptr)( target, level, xoffset, yoffset, zoffset, x, y, width, height );
}

inline void glColorTable(GLenum target,  GLenum internalformat,  GLsizei width,  GLenum format,  GLenum type,  const GLvoid *table)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLsizei width,  GLenum format,  GLenum type,  const GLvoid *table);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorTable" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorTable" ); }
	(*func_ptr)( target, internalformat, width, format, type, table );
}

inline void glColorTableParameterfv(GLenum target,  GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorTableParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorTableParameterfv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glColorTableParameteriv(GLenum target,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorTableParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorTableParameteriv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glCopyColorTable(GLenum target,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyColorTable" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyColorTable" ); }
	(*func_ptr)( target, internalformat, x, y, width );
}

inline void glGetColorTable(GLenum target,  GLenum format,  GLenum type,  GLvoid *table)
{
	typedef void (*proc_type)(GLenum target,  GLenum format,  GLenum type,  GLvoid *table);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTable" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTable" ); }
	(*func_ptr)( target, format, type, table );
}

inline void glGetColorTableParameterfv(GLenum target,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTableParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTableParameterfv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetColorTableParameteriv(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTableParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTableParameteriv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glColorSubTable(GLenum target,  GLsizei start,  GLsizei count,  GLenum format,  GLenum type,  const GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLsizei start,  GLsizei count,  GLenum format,  GLenum type,  const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorSubTable" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorSubTable" ); }
	(*func_ptr)( target, start, count, format, type, data );
}

inline void glCopyColorSubTable(GLenum target,  GLsizei start,  GLint x,  GLint y,  GLsizei width)
{
	typedef void (*proc_type)(GLenum target,  GLsizei start,  GLint x,  GLint y,  GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyColorSubTable" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyColorSubTable" ); }
	(*func_ptr)( target, start, x, y, width );
}

inline void glConvolutionFilter1D(GLenum target,  GLenum internalformat,  GLsizei width,  GLenum format,  GLenum type,  const GLvoid *image)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLsizei width,  GLenum format,  GLenum type,  const GLvoid *image);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionFilter1D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionFilter1D" ); }
	(*func_ptr)( target, internalformat, width, format, type, image );
}

inline void glConvolutionFilter2D(GLenum target,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  const GLvoid *image)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  const GLvoid *image);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionFilter2D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionFilter2D" ); }
	(*func_ptr)( target, internalformat, width, height, format, type, image );
}

inline void glConvolutionParameterf(GLenum target,  GLenum pname,  GLfloat params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLfloat params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionParameterf" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionParameterf" ); }
	(*func_ptr)( target, pname, params );
}

inline void glConvolutionParameterfv(GLenum target,  GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionParameterfv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glConvolutionParameteri(GLenum target,  GLenum pname,  GLint params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionParameteri" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionParameteri" ); }
	(*func_ptr)( target, pname, params );
}

inline void glConvolutionParameteriv(GLenum target,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionParameteriv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glCopyConvolutionFilter1D(GLenum target,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyConvolutionFilter1D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyConvolutionFilter1D" ); }
	(*func_ptr)( target, internalformat, x, y, width );
}

inline void glCopyConvolutionFilter2D(GLenum target,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyConvolutionFilter2D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyConvolutionFilter2D" ); }
	(*func_ptr)( target, internalformat, x, y, width, height );
}

inline void glGetConvolutionFilter(GLenum target,  GLenum format,  GLenum type,  GLvoid *image)
{
	typedef void (*proc_type)(GLenum target,  GLenum format,  GLenum type,  GLvoid *image);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetConvolutionFilter" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetConvolutionFilter" ); }
	(*func_ptr)( target, format, type, image );
}

inline void glGetConvolutionParameterfv(GLenum target,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetConvolutionParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetConvolutionParameterfv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetConvolutionParameteriv(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetConvolutionParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetConvolutionParameteriv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetSeparableFilter(GLenum target,  GLenum format,  GLenum type,  GLvoid *row,  GLvoid *column,  GLvoid *span)
{
	typedef void (*proc_type)(GLenum target,  GLenum format,  GLenum type,  GLvoid *row,  GLvoid *column,  GLvoid *span);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSeparableFilter" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSeparableFilter" ); }
	(*func_ptr)( target, format, type, row, column, span );
}

inline void glSeparableFilter2D(GLenum target,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  const GLvoid *row,  const GLvoid *column)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  const GLvoid *row,  const GLvoid *column);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSeparableFilter2D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSeparableFilter2D" ); }
	(*func_ptr)( target, internalformat, width, height, format, type, row, column );
}

inline void glGetHistogram(GLenum target,  GLboolean reset,  GLenum format,  GLenum type,  GLvoid *values)
{
	typedef void (*proc_type)(GLenum target,  GLboolean reset,  GLenum format,  GLenum type,  GLvoid *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetHistogram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetHistogram" ); }
	(*func_ptr)( target, reset, format, type, values );
}

inline void glGetHistogramParameterfv(GLenum target,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetHistogramParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetHistogramParameterfv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetHistogramParameteriv(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetHistogramParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetHistogramParameteriv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetMinmax(GLenum target,  GLboolean reset,  GLenum format,  GLenum type,  GLvoid *values)
{
	typedef void (*proc_type)(GLenum target,  GLboolean reset,  GLenum format,  GLenum type,  GLvoid *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMinmax" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMinmax" ); }
	(*func_ptr)( target, reset, format, type, values );
}

inline void glGetMinmaxParameterfv(GLenum target,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMinmaxParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMinmaxParameterfv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetMinmaxParameteriv(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMinmaxParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMinmaxParameteriv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glHistogram(GLenum target,  GLsizei width,  GLenum internalformat,  GLboolean sink)
{
	typedef void (*proc_type)(GLenum target,  GLsizei width,  GLenum internalformat,  GLboolean sink);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glHistogram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glHistogram" ); }
	(*func_ptr)( target, width, internalformat, sink );
}

inline void glMinmax(GLenum target,  GLenum internalformat,  GLboolean sink)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLboolean sink);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMinmax" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMinmax" ); }
	(*func_ptr)( target, internalformat, sink );
}

inline void glResetHistogram(GLenum target)
{
	typedef void (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glResetHistogram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glResetHistogram" ); }
	(*func_ptr)( target );
}

inline void glResetMinmax(GLenum target)
{
	typedef void (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glResetMinmax" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glResetMinmax" ); }
	(*func_ptr)( target );
}

inline void glActiveTexture(GLenum texture)
{
	typedef void (*proc_type)(GLenum texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glActiveTexture" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glActiveTexture" ); }
	(*func_ptr)( texture );
}

inline void glSampleCoverage(GLfloat value,  GLboolean invert)
{
	typedef void (*proc_type)(GLfloat value,  GLboolean invert);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSampleCoverage" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSampleCoverage" ); }
	(*func_ptr)( value, invert );
}

inline void glCompressedTexImage3D(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLint border,  GLsizei imageSize,  const GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLint border,  GLsizei imageSize,  const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexImage3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexImage3D" ); }
	(*func_ptr)( target, level, internalformat, width, height, depth, border, imageSize, data );
}

inline void glCompressedTexImage2D(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLint border,  GLsizei imageSize,  const GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLint border,  GLsizei imageSize,  const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexImage2D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexImage2D" ); }
	(*func_ptr)( target, level, internalformat, width, height, border, imageSize, data );
}

inline void glCompressedTexImage1D(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLint border,  GLsizei imageSize,  const GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLint border,  GLsizei imageSize,  const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexImage1D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexImage1D" ); }
	(*func_ptr)( target, level, internalformat, width, border, imageSize, data );
}

inline void glCompressedTexSubImage3D(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLenum format,  GLsizei imageSize,  const GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLenum format,  GLsizei imageSize,  const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexSubImage3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexSubImage3D" ); }
	(*func_ptr)( target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data );
}

inline void glCompressedTexSubImage2D(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLsizei width,  GLsizei height,  GLenum format,  GLsizei imageSize,  const GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLsizei width,  GLsizei height,  GLenum format,  GLsizei imageSize,  const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexSubImage2D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexSubImage2D" ); }
	(*func_ptr)( target, level, xoffset, yoffset, width, height, format, imageSize, data );
}

inline void glCompressedTexSubImage1D(GLenum target,  GLint level,  GLint xoffset,  GLsizei width,  GLenum format,  GLsizei imageSize,  const GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLint xoffset,  GLsizei width,  GLenum format,  GLsizei imageSize,  const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexSubImage1D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexSubImage1D" ); }
	(*func_ptr)( target, level, xoffset, width, format, imageSize, data );
}

inline void glGetCompressedTexImage(GLenum target,  GLint level,  GLvoid *img)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLvoid *img);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCompressedTexImage" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCompressedTexImage" ); }
	(*func_ptr)( target, level, img );
}

inline void glClientActiveTexture(GLenum texture)
{
	typedef void (*proc_type)(GLenum texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClientActiveTexture" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClientActiveTexture" ); }
	(*func_ptr)( texture );
}

inline void glMultiTexCoord1d(GLenum target,  GLdouble s)
{
	typedef void (*proc_type)(GLenum target,  GLdouble s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1d" ); }
	(*func_ptr)( target, s );
}

inline void glMultiTexCoord1dv(GLenum target,  const GLdouble *v)
{
	typedef void (*proc_type)(GLenum target,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1dv" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord1f(GLenum target,  GLfloat s)
{
	typedef void (*proc_type)(GLenum target,  GLfloat s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1f" ); }
	(*func_ptr)( target, s );
}

inline void glMultiTexCoord1fv(GLenum target,  const GLfloat *v)
{
	typedef void (*proc_type)(GLenum target,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1fv" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord1i(GLenum target,  GLint s)
{
	typedef void (*proc_type)(GLenum target,  GLint s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1i" ); }
	(*func_ptr)( target, s );
}

inline void glMultiTexCoord1iv(GLenum target,  const GLint *v)
{
	typedef void (*proc_type)(GLenum target,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1iv" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord1s(GLenum target,  GLshort s)
{
	typedef void (*proc_type)(GLenum target,  GLshort s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1s" ); }
	(*func_ptr)( target, s );
}

inline void glMultiTexCoord1sv(GLenum target,  const GLshort *v)
{
	typedef void (*proc_type)(GLenum target,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1sv" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord2d(GLenum target,  GLdouble s,  GLdouble t)
{
	typedef void (*proc_type)(GLenum target,  GLdouble s,  GLdouble t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2d" ); }
	(*func_ptr)( target, s, t );
}

inline void glMultiTexCoord2dv(GLenum target,  const GLdouble *v)
{
	typedef void (*proc_type)(GLenum target,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2dv" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord2f(GLenum target,  GLfloat s,  GLfloat t)
{
	typedef void (*proc_type)(GLenum target,  GLfloat s,  GLfloat t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2f" ); }
	(*func_ptr)( target, s, t );
}

inline void glMultiTexCoord2fv(GLenum target,  const GLfloat *v)
{
	typedef void (*proc_type)(GLenum target,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2fv" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord2i(GLenum target,  GLint s,  GLint t)
{
	typedef void (*proc_type)(GLenum target,  GLint s,  GLint t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2i" ); }
	(*func_ptr)( target, s, t );
}

inline void glMultiTexCoord2iv(GLenum target,  const GLint *v)
{
	typedef void (*proc_type)(GLenum target,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2iv" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord2s(GLenum target,  GLshort s,  GLshort t)
{
	typedef void (*proc_type)(GLenum target,  GLshort s,  GLshort t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2s" ); }
	(*func_ptr)( target, s, t );
}

inline void glMultiTexCoord2sv(GLenum target,  const GLshort *v)
{
	typedef void (*proc_type)(GLenum target,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2sv" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord3d(GLenum target,  GLdouble s,  GLdouble t,  GLdouble r)
{
	typedef void (*proc_type)(GLenum target,  GLdouble s,  GLdouble t,  GLdouble r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3d" ); }
	(*func_ptr)( target, s, t, r );
}

inline void glMultiTexCoord3dv(GLenum target,  const GLdouble *v)
{
	typedef void (*proc_type)(GLenum target,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3dv" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord3f(GLenum target,  GLfloat s,  GLfloat t,  GLfloat r)
{
	typedef void (*proc_type)(GLenum target,  GLfloat s,  GLfloat t,  GLfloat r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3f" ); }
	(*func_ptr)( target, s, t, r );
}

inline void glMultiTexCoord3fv(GLenum target,  const GLfloat *v)
{
	typedef void (*proc_type)(GLenum target,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3fv" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord3i(GLenum target,  GLint s,  GLint t,  GLint r)
{
	typedef void (*proc_type)(GLenum target,  GLint s,  GLint t,  GLint r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3i" ); }
	(*func_ptr)( target, s, t, r );
}

inline void glMultiTexCoord3iv(GLenum target,  const GLint *v)
{
	typedef void (*proc_type)(GLenum target,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3iv" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord3s(GLenum target,  GLshort s,  GLshort t,  GLshort r)
{
	typedef void (*proc_type)(GLenum target,  GLshort s,  GLshort t,  GLshort r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3s" ); }
	(*func_ptr)( target, s, t, r );
}

inline void glMultiTexCoord3sv(GLenum target,  const GLshort *v)
{
	typedef void (*proc_type)(GLenum target,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3sv" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord4d(GLenum target,  GLdouble s,  GLdouble t,  GLdouble r,  GLdouble q)
{
	typedef void (*proc_type)(GLenum target,  GLdouble s,  GLdouble t,  GLdouble r,  GLdouble q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4d" ); }
	(*func_ptr)( target, s, t, r, q );
}

inline void glMultiTexCoord4dv(GLenum target,  const GLdouble *v)
{
	typedef void (*proc_type)(GLenum target,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4dv" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord4f(GLenum target,  GLfloat s,  GLfloat t,  GLfloat r,  GLfloat q)
{
	typedef void (*proc_type)(GLenum target,  GLfloat s,  GLfloat t,  GLfloat r,  GLfloat q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4f" ); }
	(*func_ptr)( target, s, t, r, q );
}

inline void glMultiTexCoord4fv(GLenum target,  const GLfloat *v)
{
	typedef void (*proc_type)(GLenum target,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4fv" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord4i(GLenum target,  GLint s,  GLint t,  GLint r,  GLint q)
{
	typedef void (*proc_type)(GLenum target,  GLint s,  GLint t,  GLint r,  GLint q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4i" ); }
	(*func_ptr)( target, s, t, r, q );
}

inline void glMultiTexCoord4iv(GLenum target,  const GLint *v)
{
	typedef void (*proc_type)(GLenum target,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4iv" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord4s(GLenum target,  GLshort s,  GLshort t,  GLshort r,  GLshort q)
{
	typedef void (*proc_type)(GLenum target,  GLshort s,  GLshort t,  GLshort r,  GLshort q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4s" ); }
	(*func_ptr)( target, s, t, r, q );
}

inline void glMultiTexCoord4sv(GLenum target,  const GLshort *v)
{
	typedef void (*proc_type)(GLenum target,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4sv" ); }
	(*func_ptr)( target, v );
}

inline void glLoadTransposeMatrixf(const GLfloat *m)
{
	typedef void (*proc_type)(const GLfloat *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLoadTransposeMatrixf" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLoadTransposeMatrixf" ); }
	(*func_ptr)( m );
}

inline void glLoadTransposeMatrixd(const GLdouble *m)
{
	typedef void (*proc_type)(const GLdouble *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLoadTransposeMatrixd" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLoadTransposeMatrixd" ); }
	(*func_ptr)( m );
}

inline void glMultTransposeMatrixf(const GLfloat *m)
{
	typedef void (*proc_type)(const GLfloat *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultTransposeMatrixf" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultTransposeMatrixf" ); }
	(*func_ptr)( m );
}

inline void glMultTransposeMatrixd(const GLdouble *m)
{
	typedef void (*proc_type)(const GLdouble *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultTransposeMatrixd" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultTransposeMatrixd" ); }
	(*func_ptr)( m );
}

inline void glBlendFuncSeparate(GLenum sfactorRGB,  GLenum dfactorRGB,  GLenum sfactorAlpha,  GLenum dfactorAlpha)
{
	typedef void (*proc_type)(GLenum sfactorRGB,  GLenum dfactorRGB,  GLenum sfactorAlpha,  GLenum dfactorAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFuncSeparate" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFuncSeparate" ); }
	(*func_ptr)( sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha );
}

inline void glMultiDrawArrays(GLenum mode,  const GLint *first,  const GLsizei *count,  GLsizei primcount)
{
	typedef void (*proc_type)(GLenum mode,  const GLint *first,  const GLsizei *count,  GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawArrays" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawArrays" ); }
	(*func_ptr)( mode, first, count, primcount );
}

inline void glMultiDrawElements(GLenum mode,  const GLsizei *count,  GLenum type,  const GLvoid* *indices,  GLsizei primcount)
{
	typedef void (*proc_type)(GLenum mode,  const GLsizei *count,  GLenum type,  const GLvoid* *indices,  GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawElements" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawElements" ); }
	(*func_ptr)( mode, count, type, indices, primcount );
}

inline void glPointParameterf(GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterf" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterf" ); }
	(*func_ptr)( pname, param );
}

inline void glPointParameterfv(GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterfv" ); }
	(*func_ptr)( pname, params );
}

inline void glPointParameteri(GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameteri" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameteri" ); }
	(*func_ptr)( pname, param );
}

inline void glPointParameteriv(GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameteriv" ); }
	(*func_ptr)( pname, params );
}

inline void glFogCoordf(GLfloat coord)
{
	typedef void (*proc_type)(GLfloat coord);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordf" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordf" ); }
	(*func_ptr)( coord );
}

inline void glFogCoordfv(const GLfloat *coord)
{
	typedef void (*proc_type)(const GLfloat *coord);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordfv" ); }
	(*func_ptr)( coord );
}

inline void glFogCoordd(GLdouble coord)
{
	typedef void (*proc_type)(GLdouble coord);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordd" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordd" ); }
	(*func_ptr)( coord );
}

inline void glFogCoorddv(const GLdouble *coord)
{
	typedef void (*proc_type)(const GLdouble *coord);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoorddv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoorddv" ); }
	(*func_ptr)( coord );
}

inline void glFogCoordPointer(GLenum type,  GLsizei stride,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLenum type,  GLsizei stride,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordPointer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordPointer" ); }
	(*func_ptr)( type, stride, pointer );
}

inline void glSecondaryColor3b(GLbyte red,  GLbyte green,  GLbyte blue)
{
	typedef void (*proc_type)(GLbyte red,  GLbyte green,  GLbyte blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3b" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3b" ); }
	(*func_ptr)( red, green, blue );
}

inline void glSecondaryColor3bv(const GLbyte *v)
{
	typedef void (*proc_type)(const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3bv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3bv" ); }
	(*func_ptr)( v );
}

inline void glSecondaryColor3d(GLdouble red,  GLdouble green,  GLdouble blue)
{
	typedef void (*proc_type)(GLdouble red,  GLdouble green,  GLdouble blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3d" ); }
	(*func_ptr)( red, green, blue );
}

inline void glSecondaryColor3dv(const GLdouble *v)
{
	typedef void (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3dv" ); }
	(*func_ptr)( v );
}

inline void glSecondaryColor3f(GLfloat red,  GLfloat green,  GLfloat blue)
{
	typedef void (*proc_type)(GLfloat red,  GLfloat green,  GLfloat blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3f" ); }
	(*func_ptr)( red, green, blue );
}

inline void glSecondaryColor3fv(const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3fv" ); }
	(*func_ptr)( v );
}

inline void glSecondaryColor3i(GLint red,  GLint green,  GLint blue)
{
	typedef void (*proc_type)(GLint red,  GLint green,  GLint blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3i" ); }
	(*func_ptr)( red, green, blue );
}

inline void glSecondaryColor3iv(const GLint *v)
{
	typedef void (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3iv" ); }
	(*func_ptr)( v );
}

inline void glSecondaryColor3s(GLshort red,  GLshort green,  GLshort blue)
{
	typedef void (*proc_type)(GLshort red,  GLshort green,  GLshort blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3s" ); }
	(*func_ptr)( red, green, blue );
}

inline void glSecondaryColor3sv(const GLshort *v)
{
	typedef void (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3sv" ); }
	(*func_ptr)( v );
}

inline void glSecondaryColor3ub(GLubyte red,  GLubyte green,  GLubyte blue)
{
	typedef void (*proc_type)(GLubyte red,  GLubyte green,  GLubyte blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3ub" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3ub" ); }
	(*func_ptr)( red, green, blue );
}

inline void glSecondaryColor3ubv(const GLubyte *v)
{
	typedef void (*proc_type)(const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3ubv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3ubv" ); }
	(*func_ptr)( v );
}

inline void glSecondaryColor3ui(GLuint red,  GLuint green,  GLuint blue)
{
	typedef void (*proc_type)(GLuint red,  GLuint green,  GLuint blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3ui" ); }
	(*func_ptr)( red, green, blue );
}

inline void glSecondaryColor3uiv(const GLuint *v)
{
	typedef void (*proc_type)(const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3uiv" ); }
	(*func_ptr)( v );
}

inline void glSecondaryColor3us(GLushort red,  GLushort green,  GLushort blue)
{
	typedef void (*proc_type)(GLushort red,  GLushort green,  GLushort blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3us" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3us" ); }
	(*func_ptr)( red, green, blue );
}

inline void glSecondaryColor3usv(const GLushort *v)
{
	typedef void (*proc_type)(const GLushort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3usv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3usv" ); }
	(*func_ptr)( v );
}

inline void glSecondaryColorPointer(GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColorPointer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColorPointer" ); }
	(*func_ptr)( size, type, stride, pointer );
}

inline void glWindowPos2d(GLdouble x,  GLdouble y)
{
	typedef void (*proc_type)(GLdouble x,  GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2d" ); }
	(*func_ptr)( x, y );
}

inline void glWindowPos2dv(const GLdouble *v)
{
	typedef void (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2dv" ); }
	(*func_ptr)( v );
}

inline void glWindowPos2f(GLfloat x,  GLfloat y)
{
	typedef void (*proc_type)(GLfloat x,  GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2f" ); }
	(*func_ptr)( x, y );
}

inline void glWindowPos2fv(const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2fv" ); }
	(*func_ptr)( v );
}

inline void glWindowPos2i(GLint x,  GLint y)
{
	typedef void (*proc_type)(GLint x,  GLint y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2i" ); }
	(*func_ptr)( x, y );
}

inline void glWindowPos2iv(const GLint *v)
{
	typedef void (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2iv" ); }
	(*func_ptr)( v );
}

inline void glWindowPos2s(GLshort x,  GLshort y)
{
	typedef void (*proc_type)(GLshort x,  GLshort y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2s" ); }
	(*func_ptr)( x, y );
}

inline void glWindowPos2sv(const GLshort *v)
{
	typedef void (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2sv" ); }
	(*func_ptr)( v );
}

inline void glWindowPos3d(GLdouble x,  GLdouble y,  GLdouble z)
{
	typedef void (*proc_type)(GLdouble x,  GLdouble y,  GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3d" ); }
	(*func_ptr)( x, y, z );
}

inline void glWindowPos3dv(const GLdouble *v)
{
	typedef void (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3dv" ); }
	(*func_ptr)( v );
}

inline void glWindowPos3f(GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3f" ); }
	(*func_ptr)( x, y, z );
}

inline void glWindowPos3fv(const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3fv" ); }
	(*func_ptr)( v );
}

inline void glWindowPos3i(GLint x,  GLint y,  GLint z)
{
	typedef void (*proc_type)(GLint x,  GLint y,  GLint z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3i" ); }
	(*func_ptr)( x, y, z );
}

inline void glWindowPos3iv(const GLint *v)
{
	typedef void (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3iv" ); }
	(*func_ptr)( v );
}

inline void glWindowPos3s(GLshort x,  GLshort y,  GLshort z)
{
	typedef void (*proc_type)(GLshort x,  GLshort y,  GLshort z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3s" ); }
	(*func_ptr)( x, y, z );
}

inline void glWindowPos3sv(const GLshort *v)
{
	typedef void (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3sv" ); }
	(*func_ptr)( v );
}

inline void glGenQueries(GLsizei n,  GLuint *ids)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenQueries" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenQueries" ); }
	(*func_ptr)( n, ids );
}

inline void glDeleteQueries(GLsizei n,  const GLuint *ids)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteQueries" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteQueries" ); }
	(*func_ptr)( n, ids );
}

inline GLboolean glIsQuery(GLuint id)
{
	typedef GLboolean (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsQuery" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsQuery" ); }
	return (*func_ptr)( id );
}

inline void glBeginQuery(GLenum target,  GLuint id)
{
	typedef void (*proc_type)(GLenum target,  GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginQuery" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginQuery" ); }
	(*func_ptr)( target, id );
}

inline void glEndQuery(GLenum target)
{
	typedef void (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndQuery" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndQuery" ); }
	(*func_ptr)( target );
}

inline void glGetQueryiv(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryiv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetQueryObjectiv(GLuint id,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint id,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryObjectiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryObjectiv" ); }
	(*func_ptr)( id, pname, params );
}

inline void glGetQueryObjectuiv(GLuint id,  GLenum pname,  GLuint *params)
{
	typedef void (*proc_type)(GLuint id,  GLenum pname,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryObjectuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryObjectuiv" ); }
	(*func_ptr)( id, pname, params );
}

inline void glBindBuffer(GLenum target,  GLuint buffer)
{
	typedef void (*proc_type)(GLenum target,  GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBuffer" ); }
	(*func_ptr)( target, buffer );
}

inline void glDeleteBuffers(GLsizei n,  const GLuint *buffers)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *buffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteBuffers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteBuffers" ); }
	(*func_ptr)( n, buffers );
}

inline void glGenBuffers(GLsizei n,  GLuint *buffers)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *buffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenBuffers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenBuffers" ); }
	(*func_ptr)( n, buffers );
}

inline GLboolean glIsBuffer(GLuint buffer)
{
	typedef GLboolean (*proc_type)(GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsBuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsBuffer" ); }
	return (*func_ptr)( buffer );
}

inline void glBufferData(GLenum target,  GLsizeiptr size,  const GLvoid *data,  GLenum usage)
{
	typedef void (*proc_type)(GLenum target,  GLsizeiptr size,  const GLvoid *data,  GLenum usage);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBufferData" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBufferData" ); }
	(*func_ptr)( target, size, data, usage );
}

inline void glBufferSubData(GLenum target,  GLintptr offset,  GLsizeiptr size,  const GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLintptr offset,  GLsizeiptr size,  const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBufferSubData" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBufferSubData" ); }
	(*func_ptr)( target, offset, size, data );
}

inline void glGetBufferSubData(GLenum target,  GLintptr offset,  GLsizeiptr size,  GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLintptr offset,  GLsizeiptr size,  GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBufferSubData" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBufferSubData" ); }
	(*func_ptr)( target, offset, size, data );
}

inline GLboolean glUnmapBuffer(GLenum target)
{
	typedef GLboolean (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUnmapBuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUnmapBuffer" ); }
	return (*func_ptr)( target );
}

inline void glGetBufferParameteriv(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBufferParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBufferParameteriv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetBufferPointerv(GLenum target,  GLenum pname,  GLvoid* *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLvoid* *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBufferPointerv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBufferPointerv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glBlendEquationSeparate(GLenum modeRGB,  GLenum modeAlpha)
{
	typedef void (*proc_type)(GLenum modeRGB,  GLenum modeAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationSeparate" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationSeparate" ); }
	(*func_ptr)( modeRGB, modeAlpha );
}

inline void glDrawBuffers(GLsizei n,  const GLenum *bufs)
{
	typedef void (*proc_type)(GLsizei n,  const GLenum *bufs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawBuffers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawBuffers" ); }
	(*func_ptr)( n, bufs );
}

inline void glStencilOpSeparate(GLenum face,  GLenum sfail,  GLenum dpfail,  GLenum dppass)
{
	typedef void (*proc_type)(GLenum face,  GLenum sfail,  GLenum dpfail,  GLenum dppass);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilOpSeparate" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilOpSeparate" ); }
	(*func_ptr)( face, sfail, dpfail, dppass );
}

inline void glStencilFuncSeparate(GLenum face,  GLenum func,  GLint ref,  GLuint mask)
{
	typedef void (*proc_type)(GLenum face,  GLenum func,  GLint ref,  GLuint mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilFuncSeparate" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilFuncSeparate" ); }
	(*func_ptr)( face, func, ref, mask );
}

inline void glStencilMaskSeparate(GLenum face,  GLuint mask)
{
	typedef void (*proc_type)(GLenum face,  GLuint mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilMaskSeparate" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilMaskSeparate" ); }
	(*func_ptr)( face, mask );
}

inline void glAttachShader(GLuint program,  GLuint shader)
{
	typedef void (*proc_type)(GLuint program,  GLuint shader);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glAttachShader" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glAttachShader" ); }
	(*func_ptr)( program, shader );
}

inline void glBindAttribLocation(GLuint program,  GLuint index,  const GLchar *name)
{
	typedef void (*proc_type)(GLuint program,  GLuint index,  const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindAttribLocation" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindAttribLocation" ); }
	(*func_ptr)( program, index, name );
}

inline void glCompileShader(GLuint shader)
{
	typedef void (*proc_type)(GLuint shader);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompileShader" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompileShader" ); }
	(*func_ptr)( shader );
}

inline GLuint glCreateProgram(void)
{
	typedef GLuint (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCreateProgram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCreateProgram" ); }
	return (*func_ptr)(  );
}

inline GLuint glCreateShader(GLenum type)
{
	typedef GLuint (*proc_type)(GLenum type);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCreateShader" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCreateShader" ); }
	return (*func_ptr)( type );
}

inline void glDeleteProgram(GLuint program)
{
	typedef void (*proc_type)(GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteProgram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteProgram" ); }
	(*func_ptr)( program );
}

inline void glDeleteShader(GLuint shader)
{
	typedef void (*proc_type)(GLuint shader);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteShader" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteShader" ); }
	(*func_ptr)( shader );
}

inline void glDetachShader(GLuint program,  GLuint shader)
{
	typedef void (*proc_type)(GLuint program,  GLuint shader);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDetachShader" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDetachShader" ); }
	(*func_ptr)( program, shader );
}

inline void glDisableVertexAttribArray(GLuint index)
{
	typedef void (*proc_type)(GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDisableVertexAttribArray" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDisableVertexAttribArray" ); }
	(*func_ptr)( index );
}

inline void glEnableVertexAttribArray(GLuint index)
{
	typedef void (*proc_type)(GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEnableVertexAttribArray" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEnableVertexAttribArray" ); }
	(*func_ptr)( index );
}

inline void glGetActiveAttrib(GLuint program,  GLuint index,  GLsizei bufSize,  GLsizei *length,  GLint *size,  GLenum *type,  GLchar *name)
{
	typedef void (*proc_type)(GLuint program,  GLuint index,  GLsizei bufSize,  GLsizei *length,  GLint *size,  GLenum *type,  GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveAttrib" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveAttrib" ); }
	(*func_ptr)( program, index, bufSize, length, size, type, name );
}

inline void glGetActiveUniform(GLuint program,  GLuint index,  GLsizei bufSize,  GLsizei *length,  GLint *size,  GLenum *type,  GLchar *name)
{
	typedef void (*proc_type)(GLuint program,  GLuint index,  GLsizei bufSize,  GLsizei *length,  GLint *size,  GLenum *type,  GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveUniform" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveUniform" ); }
	(*func_ptr)( program, index, bufSize, length, size, type, name );
}

inline void glGetAttachedShaders(GLuint program,  GLsizei maxCount,  GLsizei *count,  GLuint *obj)
{
	typedef void (*proc_type)(GLuint program,  GLsizei maxCount,  GLsizei *count,  GLuint *obj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetAttachedShaders" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetAttachedShaders" ); }
	(*func_ptr)( program, maxCount, count, obj );
}

inline GLint glGetAttribLocation(GLuint program,  const GLchar *name)
{
	typedef GLint (*proc_type)(GLuint program,  const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetAttribLocation" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetAttribLocation" ); }
	return (*func_ptr)( program, name );
}

inline void glGetProgramiv(GLuint program,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint program,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramiv" ); }
	(*func_ptr)( program, pname, params );
}

inline void glGetProgramInfoLog(GLuint program,  GLsizei bufSize,  GLsizei *length,  GLchar *infoLog)
{
	typedef void (*proc_type)(GLuint program,  GLsizei bufSize,  GLsizei *length,  GLchar *infoLog);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramInfoLog" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramInfoLog" ); }
	(*func_ptr)( program, bufSize, length, infoLog );
}

inline void glGetShaderiv(GLuint shader,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint shader,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetShaderiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetShaderiv" ); }
	(*func_ptr)( shader, pname, params );
}

inline void glGetShaderInfoLog(GLuint shader,  GLsizei bufSize,  GLsizei *length,  GLchar *infoLog)
{
	typedef void (*proc_type)(GLuint shader,  GLsizei bufSize,  GLsizei *length,  GLchar *infoLog);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetShaderInfoLog" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetShaderInfoLog" ); }
	(*func_ptr)( shader, bufSize, length, infoLog );
}

inline void glGetShaderSource(GLuint shader,  GLsizei bufSize,  GLsizei *length,  GLchar *source)
{
	typedef void (*proc_type)(GLuint shader,  GLsizei bufSize,  GLsizei *length,  GLchar *source);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetShaderSource" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetShaderSource" ); }
	(*func_ptr)( shader, bufSize, length, source );
}

inline GLint glGetUniformLocation(GLuint program,  const GLchar *name)
{
	typedef GLint (*proc_type)(GLuint program,  const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformLocation" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformLocation" ); }
	return (*func_ptr)( program, name );
}

inline void glGetUniformfv(GLuint program,  GLint location,  GLfloat *params)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformfv" ); }
	(*func_ptr)( program, location, params );
}

inline void glGetUniformiv(GLuint program,  GLint location,  GLint *params)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformiv" ); }
	(*func_ptr)( program, location, params );
}

inline void glGetVertexAttribdv(GLuint index,  GLenum pname,  GLdouble *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribdv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribdv" ); }
	(*func_ptr)( index, pname, params );
}

inline void glGetVertexAttribfv(GLuint index,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribfv" ); }
	(*func_ptr)( index, pname, params );
}

inline void glGetVertexAttribiv(GLuint index,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribiv" ); }
	(*func_ptr)( index, pname, params );
}

inline void glGetVertexAttribPointerv(GLuint index,  GLenum pname,  GLvoid* *pointer)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLvoid* *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribPointerv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribPointerv" ); }
	(*func_ptr)( index, pname, pointer );
}

inline GLboolean glIsProgram(GLuint program)
{
	typedef GLboolean (*proc_type)(GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsProgram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsProgram" ); }
	return (*func_ptr)( program );
}

inline GLboolean glIsShader(GLuint shader)
{
	typedef GLboolean (*proc_type)(GLuint shader);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsShader" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsShader" ); }
	return (*func_ptr)( shader );
}

inline void glLinkProgram(GLuint program)
{
	typedef void (*proc_type)(GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLinkProgram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLinkProgram" ); }
	(*func_ptr)( program );
}

inline void glShaderSource(GLuint shader,  GLsizei count,  const GLchar* *string,  const GLint *length)
{
	typedef void (*proc_type)(GLuint shader,  GLsizei count,  const GLchar* *string,  const GLint *length);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glShaderSource" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glShaderSource" ); }
	(*func_ptr)( shader, count, string, length );
}

inline void glUseProgram(GLuint program)
{
	typedef void (*proc_type)(GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUseProgram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUseProgram" ); }
	(*func_ptr)( program );
}

inline void glUniform1f(GLint location,  GLfloat v0)
{
	typedef void (*proc_type)(GLint location,  GLfloat v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1f" ); }
	(*func_ptr)( location, v0 );
}

inline void glUniform2f(GLint location,  GLfloat v0,  GLfloat v1)
{
	typedef void (*proc_type)(GLint location,  GLfloat v0,  GLfloat v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2f" ); }
	(*func_ptr)( location, v0, v1 );
}

inline void glUniform3f(GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2)
{
	typedef void (*proc_type)(GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3f" ); }
	(*func_ptr)( location, v0, v1, v2 );
}

inline void glUniform4f(GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2,  GLfloat v3)
{
	typedef void (*proc_type)(GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2,  GLfloat v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4f" ); }
	(*func_ptr)( location, v0, v1, v2, v3 );
}

inline void glUniform1i(GLint location,  GLint v0)
{
	typedef void (*proc_type)(GLint location,  GLint v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1i" ); }
	(*func_ptr)( location, v0 );
}

inline void glUniform2i(GLint location,  GLint v0,  GLint v1)
{
	typedef void (*proc_type)(GLint location,  GLint v0,  GLint v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2i" ); }
	(*func_ptr)( location, v0, v1 );
}

inline void glUniform3i(GLint location,  GLint v0,  GLint v1,  GLint v2)
{
	typedef void (*proc_type)(GLint location,  GLint v0,  GLint v1,  GLint v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3i" ); }
	(*func_ptr)( location, v0, v1, v2 );
}

inline void glUniform4i(GLint location,  GLint v0,  GLint v1,  GLint v2,  GLint v3)
{
	typedef void (*proc_type)(GLint location,  GLint v0,  GLint v1,  GLint v2,  GLint v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4i" ); }
	(*func_ptr)( location, v0, v1, v2, v3 );
}

inline void glUniform1fv(GLint location,  GLsizei count,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1fv" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform2fv(GLint location,  GLsizei count,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2fv" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform3fv(GLint location,  GLsizei count,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3fv" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform4fv(GLint location,  GLsizei count,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4fv" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform1iv(GLint location,  GLsizei count,  const GLint *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1iv" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform2iv(GLint location,  GLsizei count,  const GLint *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2iv" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform3iv(GLint location,  GLsizei count,  const GLint *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3iv" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform4iv(GLint location,  GLsizei count,  const GLint *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4iv" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniformMatrix2fv(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix2fv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glUniformMatrix3fv(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix3fv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glUniformMatrix4fv(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix4fv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glValidateProgram(GLuint program)
{
	typedef void (*proc_type)(GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glValidateProgram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glValidateProgram" ); }
	(*func_ptr)( program );
}

inline void glVertexAttrib1d(GLuint index,  GLdouble x)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1d" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttrib1dv(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1dv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib1f(GLuint index,  GLfloat x)
{
	typedef void (*proc_type)(GLuint index,  GLfloat x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1f" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttrib1fv(GLuint index,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint index,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1fv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib1s(GLuint index,  GLshort x)
{
	typedef void (*proc_type)(GLuint index,  GLshort x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1s" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttrib1sv(GLuint index,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1sv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib2d(GLuint index,  GLdouble x,  GLdouble y)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x,  GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2d" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttrib2dv(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2dv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib2f(GLuint index,  GLfloat x,  GLfloat y)
{
	typedef void (*proc_type)(GLuint index,  GLfloat x,  GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2f" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttrib2fv(GLuint index,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint index,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2fv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib2s(GLuint index,  GLshort x,  GLshort y)
{
	typedef void (*proc_type)(GLuint index,  GLshort x,  GLshort y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2s" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttrib2sv(GLuint index,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2sv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib3d(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3d" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttrib3dv(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3dv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib3f(GLuint index,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLuint index,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3f" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttrib3fv(GLuint index,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint index,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3fv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib3s(GLuint index,  GLshort x,  GLshort y,  GLshort z)
{
	typedef void (*proc_type)(GLuint index,  GLshort x,  GLshort y,  GLshort z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3s" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttrib3sv(GLuint index,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3sv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4Nbv(GLuint index,  const GLbyte *v)
{
	typedef void (*proc_type)(GLuint index,  const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4Nbv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4Nbv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4Niv(GLuint index,  const GLint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4Niv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4Niv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4Nsv(GLuint index,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4Nsv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4Nsv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4Nub(GLuint index,  GLubyte x,  GLubyte y,  GLubyte z,  GLubyte w)
{
	typedef void (*proc_type)(GLuint index,  GLubyte x,  GLubyte y,  GLubyte z,  GLubyte w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4Nub" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4Nub" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttrib4Nubv(GLuint index,  const GLubyte *v)
{
	typedef void (*proc_type)(GLuint index,  const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4Nubv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4Nubv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4Nuiv(GLuint index,  const GLuint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4Nuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4Nuiv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4Nusv(GLuint index,  const GLushort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLushort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4Nusv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4Nusv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4bv(GLuint index,  const GLbyte *v)
{
	typedef void (*proc_type)(GLuint index,  const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4bv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4bv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4d(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4d" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttrib4dv(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4dv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4f(GLuint index,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w)
{
	typedef void (*proc_type)(GLuint index,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4f" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttrib4fv(GLuint index,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint index,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4fv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4iv(GLuint index,  const GLint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4iv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4s(GLuint index,  GLshort x,  GLshort y,  GLshort z,  GLshort w)
{
	typedef void (*proc_type)(GLuint index,  GLshort x,  GLshort y,  GLshort z,  GLshort w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4s" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttrib4sv(GLuint index,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4sv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4ubv(GLuint index,  const GLubyte *v)
{
	typedef void (*proc_type)(GLuint index,  const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4ubv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4ubv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4uiv(GLuint index,  const GLuint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4uiv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4usv(GLuint index,  const GLushort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLushort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4usv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4usv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribPointer(GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribPointer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribPointer" ); }
	(*func_ptr)( index, size, type, normalized, stride, pointer );
}

inline void glUniformMatrix2x3fv(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix2x3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix2x3fv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glUniformMatrix3x2fv(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix3x2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix3x2fv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glUniformMatrix2x4fv(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix2x4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix2x4fv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glUniformMatrix4x2fv(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix4x2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix4x2fv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glUniformMatrix3x4fv(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix3x4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix3x4fv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glUniformMatrix4x3fv(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix4x3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix4x3fv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glColorMaski(GLuint index,  GLboolean r,  GLboolean g,  GLboolean b,  GLboolean a)
{
	typedef void (*proc_type)(GLuint index,  GLboolean r,  GLboolean g,  GLboolean b,  GLboolean a);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorMaski" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorMaski" ); }
	(*func_ptr)( index, r, g, b, a );
}

inline void glGetBooleani_v(GLenum target,  GLuint index,  GLboolean *data)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLboolean *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBooleani_v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBooleani_v" ); }
	(*func_ptr)( target, index, data );
}

inline void glGetIntegeri_v(GLenum target,  GLuint index,  GLint *data)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLint *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetIntegeri_v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetIntegeri_v" ); }
	(*func_ptr)( target, index, data );
}

inline void glEnablei(GLenum target,  GLuint index)
{
	typedef void (*proc_type)(GLenum target,  GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEnablei" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEnablei" ); }
	(*func_ptr)( target, index );
}

inline void glDisablei(GLenum target,  GLuint index)
{
	typedef void (*proc_type)(GLenum target,  GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDisablei" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDisablei" ); }
	(*func_ptr)( target, index );
}

inline GLboolean glIsEnabledi(GLenum target,  GLuint index)
{
	typedef GLboolean (*proc_type)(GLenum target,  GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsEnabledi" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsEnabledi" ); }
	return (*func_ptr)( target, index );
}

inline void glBeginTransformFeedback(GLenum primitiveMode)
{
	typedef void (*proc_type)(GLenum primitiveMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginTransformFeedback" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginTransformFeedback" ); }
	(*func_ptr)( primitiveMode );
}

inline void glEndTransformFeedback(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndTransformFeedback" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndTransformFeedback" ); }
	(*func_ptr)(  );
}

inline void glBindBufferRange(GLenum target,  GLuint index,  GLuint buffer,  GLintptr offset,  GLsizeiptr size)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLuint buffer,  GLintptr offset,  GLsizeiptr size);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferRange" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferRange" ); }
	(*func_ptr)( target, index, buffer, offset, size );
}

inline void glBindBufferBase(GLenum target,  GLuint index,  GLuint buffer)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferBase" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferBase" ); }
	(*func_ptr)( target, index, buffer );
}

inline void glTransformFeedbackVaryings(GLuint program,  GLsizei count,  const GLchar* *varyings,  GLenum bufferMode)
{
	typedef void (*proc_type)(GLuint program,  GLsizei count,  const GLchar* *varyings,  GLenum bufferMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTransformFeedbackVaryings" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTransformFeedbackVaryings" ); }
	(*func_ptr)( program, count, varyings, bufferMode );
}

inline void glGetTransformFeedbackVarying(GLuint program,  GLuint index,  GLsizei bufSize,  GLsizei *length,  GLsizei *size,  GLenum *type,  GLchar *name)
{
	typedef void (*proc_type)(GLuint program,  GLuint index,  GLsizei bufSize,  GLsizei *length,  GLsizei *size,  GLenum *type,  GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTransformFeedbackVarying" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTransformFeedbackVarying" ); }
	(*func_ptr)( program, index, bufSize, length, size, type, name );
}

inline void glClampColor(GLenum target,  GLenum clamp)
{
	typedef void (*proc_type)(GLenum target,  GLenum clamp);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClampColor" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClampColor" ); }
	(*func_ptr)( target, clamp );
}

inline void glBeginConditionalRender(GLuint id,  GLenum mode)
{
	typedef void (*proc_type)(GLuint id,  GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginConditionalRender" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginConditionalRender" ); }
	(*func_ptr)( id, mode );
}

inline void glEndConditionalRender(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndConditionalRender" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndConditionalRender" ); }
	(*func_ptr)(  );
}

inline void glVertexAttribIPointer(GLuint index,  GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLuint index,  GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribIPointer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribIPointer" ); }
	(*func_ptr)( index, size, type, stride, pointer );
}

inline void glGetVertexAttribIiv(GLuint index,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribIiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribIiv" ); }
	(*func_ptr)( index, pname, params );
}

inline void glGetVertexAttribIuiv(GLuint index,  GLenum pname,  GLuint *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribIuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribIuiv" ); }
	(*func_ptr)( index, pname, params );
}

inline void glVertexAttribI1i(GLuint index,  GLint x)
{
	typedef void (*proc_type)(GLuint index,  GLint x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI1i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI1i" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttribI2i(GLuint index,  GLint x,  GLint y)
{
	typedef void (*proc_type)(GLuint index,  GLint x,  GLint y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI2i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI2i" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttribI3i(GLuint index,  GLint x,  GLint y,  GLint z)
{
	typedef void (*proc_type)(GLuint index,  GLint x,  GLint y,  GLint z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI3i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI3i" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttribI4i(GLuint index,  GLint x,  GLint y,  GLint z,  GLint w)
{
	typedef void (*proc_type)(GLuint index,  GLint x,  GLint y,  GLint z,  GLint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4i" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttribI1ui(GLuint index,  GLuint x)
{
	typedef void (*proc_type)(GLuint index,  GLuint x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI1ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI1ui" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttribI2ui(GLuint index,  GLuint x,  GLuint y)
{
	typedef void (*proc_type)(GLuint index,  GLuint x,  GLuint y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI2ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI2ui" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttribI3ui(GLuint index,  GLuint x,  GLuint y,  GLuint z)
{
	typedef void (*proc_type)(GLuint index,  GLuint x,  GLuint y,  GLuint z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI3ui" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttribI4ui(GLuint index,  GLuint x,  GLuint y,  GLuint z,  GLuint w)
{
	typedef void (*proc_type)(GLuint index,  GLuint x,  GLuint y,  GLuint z,  GLuint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4ui" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttribI1iv(GLuint index,  const GLint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI1iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI1iv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI2iv(GLuint index,  const GLint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI2iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI2iv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI3iv(GLuint index,  const GLint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI3iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI3iv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI4iv(GLuint index,  const GLint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4iv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI1uiv(GLuint index,  const GLuint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI1uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI1uiv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI2uiv(GLuint index,  const GLuint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI2uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI2uiv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI3uiv(GLuint index,  const GLuint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI3uiv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI4uiv(GLuint index,  const GLuint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4uiv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI4bv(GLuint index,  const GLbyte *v)
{
	typedef void (*proc_type)(GLuint index,  const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4bv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4bv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI4sv(GLuint index,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4sv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI4ubv(GLuint index,  const GLubyte *v)
{
	typedef void (*proc_type)(GLuint index,  const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4ubv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4ubv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI4usv(GLuint index,  const GLushort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLushort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4usv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4usv" ); }
	(*func_ptr)( index, v );
}

inline void glGetUniformuiv(GLuint program,  GLint location,  GLuint *params)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformuiv" ); }
	(*func_ptr)( program, location, params );
}

inline void glBindFragDataLocation(GLuint program,  GLuint color,  const GLchar *name)
{
	typedef void (*proc_type)(GLuint program,  GLuint color,  const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindFragDataLocation" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindFragDataLocation" ); }
	(*func_ptr)( program, color, name );
}

inline GLint glGetFragDataLocation(GLuint program,  const GLchar *name)
{
	typedef GLint (*proc_type)(GLuint program,  const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFragDataLocation" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFragDataLocation" ); }
	return (*func_ptr)( program, name );
}

inline void glUniform1ui(GLint location,  GLuint v0)
{
	typedef void (*proc_type)(GLint location,  GLuint v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1ui" ); }
	(*func_ptr)( location, v0 );
}

inline void glUniform2ui(GLint location,  GLuint v0,  GLuint v1)
{
	typedef void (*proc_type)(GLint location,  GLuint v0,  GLuint v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2ui" ); }
	(*func_ptr)( location, v0, v1 );
}

inline void glUniform3ui(GLint location,  GLuint v0,  GLuint v1,  GLuint v2)
{
	typedef void (*proc_type)(GLint location,  GLuint v0,  GLuint v1,  GLuint v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3ui" ); }
	(*func_ptr)( location, v0, v1, v2 );
}

inline void glUniform4ui(GLint location,  GLuint v0,  GLuint v1,  GLuint v2,  GLuint v3)
{
	typedef void (*proc_type)(GLint location,  GLuint v0,  GLuint v1,  GLuint v2,  GLuint v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4ui" ); }
	(*func_ptr)( location, v0, v1, v2, v3 );
}

inline void glUniform1uiv(GLint location,  GLsizei count,  const GLuint *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1uiv" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform2uiv(GLint location,  GLsizei count,  const GLuint *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2uiv" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform3uiv(GLint location,  GLsizei count,  const GLuint *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3uiv" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform4uiv(GLint location,  GLsizei count,  const GLuint *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4uiv" ); }
	(*func_ptr)( location, count, value );
}

inline void glTexParameterIiv(GLenum target,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexParameterIiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexParameterIiv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glTexParameterIuiv(GLenum target,  GLenum pname,  const GLuint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexParameterIuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexParameterIuiv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetTexParameterIiv(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTexParameterIiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTexParameterIiv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetTexParameterIuiv(GLenum target,  GLenum pname,  GLuint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTexParameterIuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTexParameterIuiv" ); }
	(*func_ptr)( target, pname, params );
}

inline void glClearBufferiv(GLenum buffer,  GLint drawbuffer,  const GLint *value)
{
	typedef void (*proc_type)(GLenum buffer,  GLint drawbuffer,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClearBufferiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClearBufferiv" ); }
	(*func_ptr)( buffer, drawbuffer, value );
}

inline void glClearBufferuiv(GLenum buffer,  GLint drawbuffer,  const GLuint *value)
{
	typedef void (*proc_type)(GLenum buffer,  GLint drawbuffer,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClearBufferuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClearBufferuiv" ); }
	(*func_ptr)( buffer, drawbuffer, value );
}

inline void glClearBufferfv(GLenum buffer,  GLint drawbuffer,  const GLfloat *value)
{
	typedef void (*proc_type)(GLenum buffer,  GLint drawbuffer,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClearBufferfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClearBufferfv" ); }
	(*func_ptr)( buffer, drawbuffer, value );
}

inline void glClearBufferfi(GLenum buffer,  GLint drawbuffer,  GLfloat depth,  GLint stencil)
{
	typedef void (*proc_type)(GLenum buffer,  GLint drawbuffer,  GLfloat depth,  GLint stencil);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClearBufferfi" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClearBufferfi" ); }
	(*func_ptr)( buffer, drawbuffer, depth, stencil );
}

inline void glDrawArraysInstanced(GLenum mode,  GLint first,  GLsizei count,  GLsizei primcount)
{
	typedef void (*proc_type)(GLenum mode,  GLint first,  GLsizei count,  GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawArraysInstanced" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawArraysInstanced" ); }
	(*func_ptr)( mode, first, count, primcount );
}

inline void glDrawElementsInstanced(GLenum mode,  GLsizei count,  GLenum type,  const GLvoid *indices,  GLsizei primcount)
{
	typedef void (*proc_type)(GLenum mode,  GLsizei count,  GLenum type,  const GLvoid *indices,  GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementsInstanced" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementsInstanced" ); }
	(*func_ptr)( mode, count, type, indices, primcount );
}

inline void glTexBuffer(GLenum target,  GLenum internalformat,  GLuint buffer)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexBuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexBuffer" ); }
	(*func_ptr)( target, internalformat, buffer );
}

inline void glPrimitiveRestartIndex(GLuint index)
{
	typedef void (*proc_type)(GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPrimitiveRestartIndex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPrimitiveRestartIndex" ); }
	(*func_ptr)( index );
}

inline void glGetInteger64i_v(GLenum target,  GLuint index,  GLint64 *data)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLint64 *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetInteger64i_v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetInteger64i_v" ); }
	(*func_ptr)( target, index, data );
}

inline void glGetBufferParameteri64v(GLenum target,  GLenum pname,  GLint64 *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint64 *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBufferParameteri64v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBufferParameteri64v" ); }
	(*func_ptr)( target, pname, params );
}

inline void glFramebufferTexture(GLenum target,  GLenum attachment,  GLuint texture,  GLint level)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLuint texture,  GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTexture" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTexture" ); }
	(*func_ptr)( target, attachment, texture, level );
}

inline void glVertexAttribDivisor(GLuint index,  GLuint divisor)
{
	typedef void (*proc_type)(GLuint index,  GLuint divisor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribDivisor" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribDivisor" ); }
	(*func_ptr)( index, divisor );
}

inline void glMinSampleShading(GLfloat value)
{
	typedef void (*proc_type)(GLfloat value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMinSampleShading" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMinSampleShading" ); }
	(*func_ptr)( value );
}

inline void glBlendEquationi(GLuint buf,  GLenum mode)
{
	typedef void (*proc_type)(GLuint buf,  GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationi" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationi" ); }
	(*func_ptr)( buf, mode );
}

inline void glBlendEquationSeparatei(GLuint buf,  GLenum modeRGB,  GLenum modeAlpha)
{
	typedef void (*proc_type)(GLuint buf,  GLenum modeRGB,  GLenum modeAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationSeparatei" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationSeparatei" ); }
	(*func_ptr)( buf, modeRGB, modeAlpha );
}

inline void glBlendFunci(GLuint buf,  GLenum src,  GLenum dst)
{
	typedef void (*proc_type)(GLuint buf,  GLenum src,  GLenum dst);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFunci" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFunci" ); }
	(*func_ptr)( buf, src, dst );
}

inline void glBlendFuncSeparatei(GLuint buf,  GLenum srcRGB,  GLenum dstRGB,  GLenum srcAlpha,  GLenum dstAlpha)
{
	typedef void (*proc_type)(GLuint buf,  GLenum srcRGB,  GLenum dstRGB,  GLenum srcAlpha,  GLenum dstAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFuncSeparatei" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFuncSeparatei" ); }
	(*func_ptr)( buf, srcRGB, dstRGB, srcAlpha, dstAlpha );
}

inline void glActiveTextureARB(GLenum texture)
{
	typedef void (*proc_type)(GLenum texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glActiveTextureARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glActiveTextureARB" ); }
	(*func_ptr)( texture );
}

inline void glClientActiveTextureARB(GLenum texture)
{
	typedef void (*proc_type)(GLenum texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClientActiveTextureARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClientActiveTextureARB" ); }
	(*func_ptr)( texture );
}

inline void glMultiTexCoord1dARB(GLenum target,  GLdouble s)
{
	typedef void (*proc_type)(GLenum target,  GLdouble s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1dARB" ); }
	(*func_ptr)( target, s );
}

inline void glMultiTexCoord1dvARB(GLenum target,  const GLdouble *v)
{
	typedef void (*proc_type)(GLenum target,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1dvARB" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord1fARB(GLenum target,  GLfloat s)
{
	typedef void (*proc_type)(GLenum target,  GLfloat s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1fARB" ); }
	(*func_ptr)( target, s );
}

inline void glMultiTexCoord1fvARB(GLenum target,  const GLfloat *v)
{
	typedef void (*proc_type)(GLenum target,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1fvARB" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord1iARB(GLenum target,  GLint s)
{
	typedef void (*proc_type)(GLenum target,  GLint s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1iARB" ); }
	(*func_ptr)( target, s );
}

inline void glMultiTexCoord1ivARB(GLenum target,  const GLint *v)
{
	typedef void (*proc_type)(GLenum target,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1ivARB" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord1sARB(GLenum target,  GLshort s)
{
	typedef void (*proc_type)(GLenum target,  GLshort s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1sARB" ); }
	(*func_ptr)( target, s );
}

inline void glMultiTexCoord1svARB(GLenum target,  const GLshort *v)
{
	typedef void (*proc_type)(GLenum target,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1svARB" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord2dARB(GLenum target,  GLdouble s,  GLdouble t)
{
	typedef void (*proc_type)(GLenum target,  GLdouble s,  GLdouble t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2dARB" ); }
	(*func_ptr)( target, s, t );
}

inline void glMultiTexCoord2dvARB(GLenum target,  const GLdouble *v)
{
	typedef void (*proc_type)(GLenum target,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2dvARB" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord2fARB(GLenum target,  GLfloat s,  GLfloat t)
{
	typedef void (*proc_type)(GLenum target,  GLfloat s,  GLfloat t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2fARB" ); }
	(*func_ptr)( target, s, t );
}

inline void glMultiTexCoord2fvARB(GLenum target,  const GLfloat *v)
{
	typedef void (*proc_type)(GLenum target,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2fvARB" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord2iARB(GLenum target,  GLint s,  GLint t)
{
	typedef void (*proc_type)(GLenum target,  GLint s,  GLint t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2iARB" ); }
	(*func_ptr)( target, s, t );
}

inline void glMultiTexCoord2ivARB(GLenum target,  const GLint *v)
{
	typedef void (*proc_type)(GLenum target,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2ivARB" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord2sARB(GLenum target,  GLshort s,  GLshort t)
{
	typedef void (*proc_type)(GLenum target,  GLshort s,  GLshort t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2sARB" ); }
	(*func_ptr)( target, s, t );
}

inline void glMultiTexCoord2svARB(GLenum target,  const GLshort *v)
{
	typedef void (*proc_type)(GLenum target,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2svARB" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord3dARB(GLenum target,  GLdouble s,  GLdouble t,  GLdouble r)
{
	typedef void (*proc_type)(GLenum target,  GLdouble s,  GLdouble t,  GLdouble r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3dARB" ); }
	(*func_ptr)( target, s, t, r );
}

inline void glMultiTexCoord3dvARB(GLenum target,  const GLdouble *v)
{
	typedef void (*proc_type)(GLenum target,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3dvARB" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord3fARB(GLenum target,  GLfloat s,  GLfloat t,  GLfloat r)
{
	typedef void (*proc_type)(GLenum target,  GLfloat s,  GLfloat t,  GLfloat r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3fARB" ); }
	(*func_ptr)( target, s, t, r );
}

inline void glMultiTexCoord3fvARB(GLenum target,  const GLfloat *v)
{
	typedef void (*proc_type)(GLenum target,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3fvARB" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord3iARB(GLenum target,  GLint s,  GLint t,  GLint r)
{
	typedef void (*proc_type)(GLenum target,  GLint s,  GLint t,  GLint r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3iARB" ); }
	(*func_ptr)( target, s, t, r );
}

inline void glMultiTexCoord3ivARB(GLenum target,  const GLint *v)
{
	typedef void (*proc_type)(GLenum target,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3ivARB" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord3sARB(GLenum target,  GLshort s,  GLshort t,  GLshort r)
{
	typedef void (*proc_type)(GLenum target,  GLshort s,  GLshort t,  GLshort r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3sARB" ); }
	(*func_ptr)( target, s, t, r );
}

inline void glMultiTexCoord3svARB(GLenum target,  const GLshort *v)
{
	typedef void (*proc_type)(GLenum target,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3svARB" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord4dARB(GLenum target,  GLdouble s,  GLdouble t,  GLdouble r,  GLdouble q)
{
	typedef void (*proc_type)(GLenum target,  GLdouble s,  GLdouble t,  GLdouble r,  GLdouble q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4dARB" ); }
	(*func_ptr)( target, s, t, r, q );
}

inline void glMultiTexCoord4dvARB(GLenum target,  const GLdouble *v)
{
	typedef void (*proc_type)(GLenum target,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4dvARB" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord4fARB(GLenum target,  GLfloat s,  GLfloat t,  GLfloat r,  GLfloat q)
{
	typedef void (*proc_type)(GLenum target,  GLfloat s,  GLfloat t,  GLfloat r,  GLfloat q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4fARB" ); }
	(*func_ptr)( target, s, t, r, q );
}

inline void glMultiTexCoord4fvARB(GLenum target,  const GLfloat *v)
{
	typedef void (*proc_type)(GLenum target,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4fvARB" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord4iARB(GLenum target,  GLint s,  GLint t,  GLint r,  GLint q)
{
	typedef void (*proc_type)(GLenum target,  GLint s,  GLint t,  GLint r,  GLint q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4iARB" ); }
	(*func_ptr)( target, s, t, r, q );
}

inline void glMultiTexCoord4ivARB(GLenum target,  const GLint *v)
{
	typedef void (*proc_type)(GLenum target,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4ivARB" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord4sARB(GLenum target,  GLshort s,  GLshort t,  GLshort r,  GLshort q)
{
	typedef void (*proc_type)(GLenum target,  GLshort s,  GLshort t,  GLshort r,  GLshort q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4sARB" ); }
	(*func_ptr)( target, s, t, r, q );
}

inline void glMultiTexCoord4svARB(GLenum target,  const GLshort *v)
{
	typedef void (*proc_type)(GLenum target,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4svARB" ); }
	(*func_ptr)( target, v );
}

inline void glLoadTransposeMatrixfARB(const GLfloat *m)
{
	typedef void (*proc_type)(const GLfloat *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLoadTransposeMatrixfARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLoadTransposeMatrixfARB" ); }
	(*func_ptr)( m );
}

inline void glLoadTransposeMatrixdARB(const GLdouble *m)
{
	typedef void (*proc_type)(const GLdouble *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLoadTransposeMatrixdARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLoadTransposeMatrixdARB" ); }
	(*func_ptr)( m );
}

inline void glMultTransposeMatrixfARB(const GLfloat *m)
{
	typedef void (*proc_type)(const GLfloat *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultTransposeMatrixfARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultTransposeMatrixfARB" ); }
	(*func_ptr)( m );
}

inline void glMultTransposeMatrixdARB(const GLdouble *m)
{
	typedef void (*proc_type)(const GLdouble *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultTransposeMatrixdARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultTransposeMatrixdARB" ); }
	(*func_ptr)( m );
}

inline void glSampleCoverageARB(GLfloat value,  GLboolean invert)
{
	typedef void (*proc_type)(GLfloat value,  GLboolean invert);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSampleCoverageARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSampleCoverageARB" ); }
	(*func_ptr)( value, invert );
}

inline void glCompressedTexImage3DARB(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLint border,  GLsizei imageSize,  const GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLint border,  GLsizei imageSize,  const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexImage3DARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexImage3DARB" ); }
	(*func_ptr)( target, level, internalformat, width, height, depth, border, imageSize, data );
}

inline void glCompressedTexImage2DARB(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLint border,  GLsizei imageSize,  const GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLint border,  GLsizei imageSize,  const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexImage2DARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexImage2DARB" ); }
	(*func_ptr)( target, level, internalformat, width, height, border, imageSize, data );
}

inline void glCompressedTexImage1DARB(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLint border,  GLsizei imageSize,  const GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLint border,  GLsizei imageSize,  const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexImage1DARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexImage1DARB" ); }
	(*func_ptr)( target, level, internalformat, width, border, imageSize, data );
}

inline void glCompressedTexSubImage3DARB(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLenum format,  GLsizei imageSize,  const GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLenum format,  GLsizei imageSize,  const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexSubImage3DARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexSubImage3DARB" ); }
	(*func_ptr)( target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data );
}

inline void glCompressedTexSubImage2DARB(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLsizei width,  GLsizei height,  GLenum format,  GLsizei imageSize,  const GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLsizei width,  GLsizei height,  GLenum format,  GLsizei imageSize,  const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexSubImage2DARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexSubImage2DARB" ); }
	(*func_ptr)( target, level, xoffset, yoffset, width, height, format, imageSize, data );
}

inline void glCompressedTexSubImage1DARB(GLenum target,  GLint level,  GLint xoffset,  GLsizei width,  GLenum format,  GLsizei imageSize,  const GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLint xoffset,  GLsizei width,  GLenum format,  GLsizei imageSize,  const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexSubImage1DARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexSubImage1DARB" ); }
	(*func_ptr)( target, level, xoffset, width, format, imageSize, data );
}

inline void glGetCompressedTexImageARB(GLenum target,  GLint level,  GLvoid *img)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLvoid *img);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCompressedTexImageARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCompressedTexImageARB" ); }
	(*func_ptr)( target, level, img );
}

inline void glPointParameterfARB(GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterfARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterfARB" ); }
	(*func_ptr)( pname, param );
}

inline void glPointParameterfvARB(GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterfvARB" ); }
	(*func_ptr)( pname, params );
}

inline void glWeightbvARB(GLint size,  const GLbyte *weights)
{
	typedef void (*proc_type)(GLint size,  const GLbyte *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightbvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightbvARB" ); }
	(*func_ptr)( size, weights );
}

inline void glWeightsvARB(GLint size,  const GLshort *weights)
{
	typedef void (*proc_type)(GLint size,  const GLshort *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightsvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightsvARB" ); }
	(*func_ptr)( size, weights );
}

inline void glWeightivARB(GLint size,  const GLint *weights)
{
	typedef void (*proc_type)(GLint size,  const GLint *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightivARB" ); }
	(*func_ptr)( size, weights );
}

inline void glWeightfvARB(GLint size,  const GLfloat *weights)
{
	typedef void (*proc_type)(GLint size,  const GLfloat *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightfvARB" ); }
	(*func_ptr)( size, weights );
}

inline void glWeightdvARB(GLint size,  const GLdouble *weights)
{
	typedef void (*proc_type)(GLint size,  const GLdouble *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightdvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightdvARB" ); }
	(*func_ptr)( size, weights );
}

inline void glWeightubvARB(GLint size,  const GLubyte *weights)
{
	typedef void (*proc_type)(GLint size,  const GLubyte *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightubvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightubvARB" ); }
	(*func_ptr)( size, weights );
}

inline void glWeightusvARB(GLint size,  const GLushort *weights)
{
	typedef void (*proc_type)(GLint size,  const GLushort *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightusvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightusvARB" ); }
	(*func_ptr)( size, weights );
}

inline void glWeightuivARB(GLint size,  const GLuint *weights)
{
	typedef void (*proc_type)(GLint size,  const GLuint *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightuivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightuivARB" ); }
	(*func_ptr)( size, weights );
}

inline void glWeightPointerARB(GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightPointerARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightPointerARB" ); }
	(*func_ptr)( size, type, stride, pointer );
}

inline void glVertexBlendARB(GLint count)
{
	typedef void (*proc_type)(GLint count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexBlendARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexBlendARB" ); }
	(*func_ptr)( count );
}

inline void glCurrentPaletteMatrixARB(GLint index)
{
	typedef void (*proc_type)(GLint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCurrentPaletteMatrixARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCurrentPaletteMatrixARB" ); }
	(*func_ptr)( index );
}

inline void glMatrixIndexubvARB(GLint size,  const GLubyte *indices)
{
	typedef void (*proc_type)(GLint size,  const GLubyte *indices);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixIndexubvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixIndexubvARB" ); }
	(*func_ptr)( size, indices );
}

inline void glMatrixIndexusvARB(GLint size,  const GLushort *indices)
{
	typedef void (*proc_type)(GLint size,  const GLushort *indices);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixIndexusvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixIndexusvARB" ); }
	(*func_ptr)( size, indices );
}

inline void glMatrixIndexuivARB(GLint size,  const GLuint *indices)
{
	typedef void (*proc_type)(GLint size,  const GLuint *indices);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixIndexuivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixIndexuivARB" ); }
	(*func_ptr)( size, indices );
}

inline void glMatrixIndexPointerARB(GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixIndexPointerARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixIndexPointerARB" ); }
	(*func_ptr)( size, type, stride, pointer );
}

inline void glWindowPos2dARB(GLdouble x,  GLdouble y)
{
	typedef void (*proc_type)(GLdouble x,  GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2dARB" ); }
	(*func_ptr)( x, y );
}

inline void glWindowPos2dvARB(const GLdouble *v)
{
	typedef void (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2dvARB" ); }
	(*func_ptr)( v );
}

inline void glWindowPos2fARB(GLfloat x,  GLfloat y)
{
	typedef void (*proc_type)(GLfloat x,  GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2fARB" ); }
	(*func_ptr)( x, y );
}

inline void glWindowPos2fvARB(const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2fvARB" ); }
	(*func_ptr)( v );
}

inline void glWindowPos2iARB(GLint x,  GLint y)
{
	typedef void (*proc_type)(GLint x,  GLint y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2iARB" ); }
	(*func_ptr)( x, y );
}

inline void glWindowPos2ivARB(const GLint *v)
{
	typedef void (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2ivARB" ); }
	(*func_ptr)( v );
}

inline void glWindowPos2sARB(GLshort x,  GLshort y)
{
	typedef void (*proc_type)(GLshort x,  GLshort y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2sARB" ); }
	(*func_ptr)( x, y );
}

inline void glWindowPos2svARB(const GLshort *v)
{
	typedef void (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2svARB" ); }
	(*func_ptr)( v );
}

inline void glWindowPos3dARB(GLdouble x,  GLdouble y,  GLdouble z)
{
	typedef void (*proc_type)(GLdouble x,  GLdouble y,  GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3dARB" ); }
	(*func_ptr)( x, y, z );
}

inline void glWindowPos3dvARB(const GLdouble *v)
{
	typedef void (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3dvARB" ); }
	(*func_ptr)( v );
}

inline void glWindowPos3fARB(GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3fARB" ); }
	(*func_ptr)( x, y, z );
}

inline void glWindowPos3fvARB(const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3fvARB" ); }
	(*func_ptr)( v );
}

inline void glWindowPos3iARB(GLint x,  GLint y,  GLint z)
{
	typedef void (*proc_type)(GLint x,  GLint y,  GLint z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3iARB" ); }
	(*func_ptr)( x, y, z );
}

inline void glWindowPos3ivARB(const GLint *v)
{
	typedef void (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3ivARB" ); }
	(*func_ptr)( v );
}

inline void glWindowPos3sARB(GLshort x,  GLshort y,  GLshort z)
{
	typedef void (*proc_type)(GLshort x,  GLshort y,  GLshort z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3sARB" ); }
	(*func_ptr)( x, y, z );
}

inline void glWindowPos3svARB(const GLshort *v)
{
	typedef void (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3svARB" ); }
	(*func_ptr)( v );
}

inline void glVertexAttrib1dARB(GLuint index,  GLdouble x)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1dARB" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttrib1dvARB(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1dvARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib1fARB(GLuint index,  GLfloat x)
{
	typedef void (*proc_type)(GLuint index,  GLfloat x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1fARB" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttrib1fvARB(GLuint index,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint index,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1fvARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib1sARB(GLuint index,  GLshort x)
{
	typedef void (*proc_type)(GLuint index,  GLshort x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1sARB" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttrib1svARB(GLuint index,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1svARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib2dARB(GLuint index,  GLdouble x,  GLdouble y)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x,  GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2dARB" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttrib2dvARB(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2dvARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib2fARB(GLuint index,  GLfloat x,  GLfloat y)
{
	typedef void (*proc_type)(GLuint index,  GLfloat x,  GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2fARB" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttrib2fvARB(GLuint index,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint index,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2fvARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib2sARB(GLuint index,  GLshort x,  GLshort y)
{
	typedef void (*proc_type)(GLuint index,  GLshort x,  GLshort y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2sARB" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttrib2svARB(GLuint index,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2svARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib3dARB(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3dARB" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttrib3dvARB(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3dvARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib3fARB(GLuint index,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLuint index,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3fARB" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttrib3fvARB(GLuint index,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint index,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3fvARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib3sARB(GLuint index,  GLshort x,  GLshort y,  GLshort z)
{
	typedef void (*proc_type)(GLuint index,  GLshort x,  GLshort y,  GLshort z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3sARB" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttrib3svARB(GLuint index,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3svARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4NbvARB(GLuint index,  const GLbyte *v)
{
	typedef void (*proc_type)(GLuint index,  const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4NbvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4NbvARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4NivARB(GLuint index,  const GLint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4NivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4NivARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4NsvARB(GLuint index,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4NsvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4NsvARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4NubARB(GLuint index,  GLubyte x,  GLubyte y,  GLubyte z,  GLubyte w)
{
	typedef void (*proc_type)(GLuint index,  GLubyte x,  GLubyte y,  GLubyte z,  GLubyte w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4NubARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4NubARB" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttrib4NubvARB(GLuint index,  const GLubyte *v)
{
	typedef void (*proc_type)(GLuint index,  const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4NubvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4NubvARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4NuivARB(GLuint index,  const GLuint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4NuivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4NuivARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4NusvARB(GLuint index,  const GLushort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLushort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4NusvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4NusvARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4bvARB(GLuint index,  const GLbyte *v)
{
	typedef void (*proc_type)(GLuint index,  const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4bvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4bvARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4dARB(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4dARB" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttrib4dvARB(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4dvARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4fARB(GLuint index,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w)
{
	typedef void (*proc_type)(GLuint index,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4fARB" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttrib4fvARB(GLuint index,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint index,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4fvARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4ivARB(GLuint index,  const GLint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4ivARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4sARB(GLuint index,  GLshort x,  GLshort y,  GLshort z,  GLshort w)
{
	typedef void (*proc_type)(GLuint index,  GLshort x,  GLshort y,  GLshort z,  GLshort w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4sARB" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttrib4svARB(GLuint index,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4svARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4ubvARB(GLuint index,  const GLubyte *v)
{
	typedef void (*proc_type)(GLuint index,  const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4ubvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4ubvARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4uivARB(GLuint index,  const GLuint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4uivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4uivARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4usvARB(GLuint index,  const GLushort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLushort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4usvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4usvARB" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribPointerARB(GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribPointerARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribPointerARB" ); }
	(*func_ptr)( index, size, type, normalized, stride, pointer );
}

inline void glEnableVertexAttribArrayARB(GLuint index)
{
	typedef void (*proc_type)(GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEnableVertexAttribArrayARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEnableVertexAttribArrayARB" ); }
	(*func_ptr)( index );
}

inline void glDisableVertexAttribArrayARB(GLuint index)
{
	typedef void (*proc_type)(GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDisableVertexAttribArrayARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDisableVertexAttribArrayARB" ); }
	(*func_ptr)( index );
}

inline void glProgramStringARB(GLenum target,  GLenum format,  GLsizei len,  const GLvoid *string)
{
	typedef void (*proc_type)(GLenum target,  GLenum format,  GLsizei len,  const GLvoid *string);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramStringARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramStringARB" ); }
	(*func_ptr)( target, format, len, string );
}

inline void glBindProgramARB(GLenum target,  GLuint program)
{
	typedef void (*proc_type)(GLenum target,  GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindProgramARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindProgramARB" ); }
	(*func_ptr)( target, program );
}

inline void glDeleteProgramsARB(GLsizei n,  const GLuint *programs)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *programs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteProgramsARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteProgramsARB" ); }
	(*func_ptr)( n, programs );
}

inline void glGenProgramsARB(GLsizei n,  GLuint *programs)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *programs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenProgramsARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenProgramsARB" ); }
	(*func_ptr)( n, programs );
}

inline void glProgramEnvParameter4dARB(GLenum target,  GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameter4dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameter4dARB" ); }
	(*func_ptr)( target, index, x, y, z, w );
}

inline void glProgramEnvParameter4dvARB(GLenum target,  GLuint index,  const GLdouble *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  const GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameter4dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameter4dvARB" ); }
	(*func_ptr)( target, index, params );
}

inline void glProgramEnvParameter4fARB(GLenum target,  GLuint index,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameter4fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameter4fARB" ); }
	(*func_ptr)( target, index, x, y, z, w );
}

inline void glProgramEnvParameter4fvARB(GLenum target,  GLuint index,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameter4fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameter4fvARB" ); }
	(*func_ptr)( target, index, params );
}

inline void glProgramLocalParameter4dARB(GLenum target,  GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameter4dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameter4dARB" ); }
	(*func_ptr)( target, index, x, y, z, w );
}

inline void glProgramLocalParameter4dvARB(GLenum target,  GLuint index,  const GLdouble *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  const GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameter4dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameter4dvARB" ); }
	(*func_ptr)( target, index, params );
}

inline void glProgramLocalParameter4fARB(GLenum target,  GLuint index,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameter4fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameter4fARB" ); }
	(*func_ptr)( target, index, x, y, z, w );
}

inline void glProgramLocalParameter4fvARB(GLenum target,  GLuint index,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameter4fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameter4fvARB" ); }
	(*func_ptr)( target, index, params );
}

inline void glGetProgramEnvParameterdvARB(GLenum target,  GLuint index,  GLdouble *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramEnvParameterdvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramEnvParameterdvARB" ); }
	(*func_ptr)( target, index, params );
}

inline void glGetProgramEnvParameterfvARB(GLenum target,  GLuint index,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramEnvParameterfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramEnvParameterfvARB" ); }
	(*func_ptr)( target, index, params );
}

inline void glGetProgramLocalParameterdvARB(GLenum target,  GLuint index,  GLdouble *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramLocalParameterdvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramLocalParameterdvARB" ); }
	(*func_ptr)( target, index, params );
}

inline void glGetProgramLocalParameterfvARB(GLenum target,  GLuint index,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramLocalParameterfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramLocalParameterfvARB" ); }
	(*func_ptr)( target, index, params );
}

inline void glGetProgramivARB(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramivARB" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetProgramStringARB(GLenum target,  GLenum pname,  GLvoid *string)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLvoid *string);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramStringARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramStringARB" ); }
	(*func_ptr)( target, pname, string );
}

inline void glGetVertexAttribdvARB(GLuint index,  GLenum pname,  GLdouble *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribdvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribdvARB" ); }
	(*func_ptr)( index, pname, params );
}

inline void glGetVertexAttribfvARB(GLuint index,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribfvARB" ); }
	(*func_ptr)( index, pname, params );
}

inline void glGetVertexAttribivARB(GLuint index,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribivARB" ); }
	(*func_ptr)( index, pname, params );
}

inline void glGetVertexAttribPointervARB(GLuint index,  GLenum pname,  GLvoid* *pointer)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLvoid* *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribPointervARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribPointervARB" ); }
	(*func_ptr)( index, pname, pointer );
}

inline GLboolean glIsProgramARB(GLuint program)
{
	typedef GLboolean (*proc_type)(GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsProgramARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsProgramARB" ); }
	return (*func_ptr)( program );
}

inline void glBindBufferARB(GLenum target,  GLuint buffer)
{
	typedef void (*proc_type)(GLenum target,  GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferARB" ); }
	(*func_ptr)( target, buffer );
}

inline void glDeleteBuffersARB(GLsizei n,  const GLuint *buffers)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *buffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteBuffersARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteBuffersARB" ); }
	(*func_ptr)( n, buffers );
}

inline void glGenBuffersARB(GLsizei n,  GLuint *buffers)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *buffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenBuffersARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenBuffersARB" ); }
	(*func_ptr)( n, buffers );
}

inline GLboolean glIsBufferARB(GLuint buffer)
{
	typedef GLboolean (*proc_type)(GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsBufferARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsBufferARB" ); }
	return (*func_ptr)( buffer );
}

inline void glBufferDataARB(GLenum target,  GLsizeiptrARB size,  const GLvoid *data,  GLenum usage)
{
	typedef void (*proc_type)(GLenum target,  GLsizeiptrARB size,  const GLvoid *data,  GLenum usage);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBufferDataARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBufferDataARB" ); }
	(*func_ptr)( target, size, data, usage );
}

inline void glBufferSubDataARB(GLenum target,  GLintptrARB offset,  GLsizeiptrARB size,  const GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLintptrARB offset,  GLsizeiptrARB size,  const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBufferSubDataARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBufferSubDataARB" ); }
	(*func_ptr)( target, offset, size, data );
}

inline void glGetBufferSubDataARB(GLenum target,  GLintptrARB offset,  GLsizeiptrARB size,  GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLintptrARB offset,  GLsizeiptrARB size,  GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBufferSubDataARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBufferSubDataARB" ); }
	(*func_ptr)( target, offset, size, data );
}

inline GLboolean glUnmapBufferARB(GLenum target)
{
	typedef GLboolean (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUnmapBufferARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUnmapBufferARB" ); }
	return (*func_ptr)( target );
}

inline void glGetBufferParameterivARB(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBufferParameterivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBufferParameterivARB" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetBufferPointervARB(GLenum target,  GLenum pname,  GLvoid* *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLvoid* *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBufferPointervARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBufferPointervARB" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGenQueriesARB(GLsizei n,  GLuint *ids)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenQueriesARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenQueriesARB" ); }
	(*func_ptr)( n, ids );
}

inline void glDeleteQueriesARB(GLsizei n,  const GLuint *ids)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteQueriesARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteQueriesARB" ); }
	(*func_ptr)( n, ids );
}

inline GLboolean glIsQueryARB(GLuint id)
{
	typedef GLboolean (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsQueryARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsQueryARB" ); }
	return (*func_ptr)( id );
}

inline void glBeginQueryARB(GLenum target,  GLuint id)
{
	typedef void (*proc_type)(GLenum target,  GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginQueryARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginQueryARB" ); }
	(*func_ptr)( target, id );
}

inline void glEndQueryARB(GLenum target)
{
	typedef void (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndQueryARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndQueryARB" ); }
	(*func_ptr)( target );
}

inline void glGetQueryivARB(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryivARB" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetQueryObjectivARB(GLuint id,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint id,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryObjectivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryObjectivARB" ); }
	(*func_ptr)( id, pname, params );
}

inline void glGetQueryObjectuivARB(GLuint id,  GLenum pname,  GLuint *params)
{
	typedef void (*proc_type)(GLuint id,  GLenum pname,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryObjectuivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryObjectuivARB" ); }
	(*func_ptr)( id, pname, params );
}

inline void glDeleteObjectARB(GLhandleARB obj)
{
	typedef void (*proc_type)(GLhandleARB obj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteObjectARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteObjectARB" ); }
	(*func_ptr)( obj );
}

inline GLhandleARB glGetHandleARB(GLenum pname)
{
	typedef GLhandleARB (*proc_type)(GLenum pname);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetHandleARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetHandleARB" ); }
	return (*func_ptr)( pname );
}

inline void glDetachObjectARB(GLhandleARB containerObj,  GLhandleARB attachedObj)
{
	typedef void (*proc_type)(GLhandleARB containerObj,  GLhandleARB attachedObj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDetachObjectARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDetachObjectARB" ); }
	(*func_ptr)( containerObj, attachedObj );
}

inline GLhandleARB glCreateShaderObjectARB(GLenum shaderType)
{
	typedef GLhandleARB (*proc_type)(GLenum shaderType);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCreateShaderObjectARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCreateShaderObjectARB" ); }
	return (*func_ptr)( shaderType );
}

inline void glShaderSourceARB(GLhandleARB shaderObj,  GLsizei count,  const GLcharARB* *string,  const GLint *length)
{
	typedef void (*proc_type)(GLhandleARB shaderObj,  GLsizei count,  const GLcharARB* *string,  const GLint *length);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glShaderSourceARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glShaderSourceARB" ); }
	(*func_ptr)( shaderObj, count, string, length );
}

inline void glCompileShaderARB(GLhandleARB shaderObj)
{
	typedef void (*proc_type)(GLhandleARB shaderObj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompileShaderARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompileShaderARB" ); }
	(*func_ptr)( shaderObj );
}

inline GLhandleARB glCreateProgramObjectARB(void)
{
	typedef GLhandleARB (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCreateProgramObjectARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCreateProgramObjectARB" ); }
	return (*func_ptr)(  );
}

inline void glAttachObjectARB(GLhandleARB containerObj,  GLhandleARB obj)
{
	typedef void (*proc_type)(GLhandleARB containerObj,  GLhandleARB obj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glAttachObjectARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glAttachObjectARB" ); }
	(*func_ptr)( containerObj, obj );
}

inline void glLinkProgramARB(GLhandleARB programObj)
{
	typedef void (*proc_type)(GLhandleARB programObj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLinkProgramARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLinkProgramARB" ); }
	(*func_ptr)( programObj );
}

inline void glUseProgramObjectARB(GLhandleARB programObj)
{
	typedef void (*proc_type)(GLhandleARB programObj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUseProgramObjectARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUseProgramObjectARB" ); }
	(*func_ptr)( programObj );
}

inline void glValidateProgramARB(GLhandleARB programObj)
{
	typedef void (*proc_type)(GLhandleARB programObj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glValidateProgramARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glValidateProgramARB" ); }
	(*func_ptr)( programObj );
}

inline void glUniform1fARB(GLint location,  GLfloat v0)
{
	typedef void (*proc_type)(GLint location,  GLfloat v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1fARB" ); }
	(*func_ptr)( location, v0 );
}

inline void glUniform2fARB(GLint location,  GLfloat v0,  GLfloat v1)
{
	typedef void (*proc_type)(GLint location,  GLfloat v0,  GLfloat v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2fARB" ); }
	(*func_ptr)( location, v0, v1 );
}

inline void glUniform3fARB(GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2)
{
	typedef void (*proc_type)(GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3fARB" ); }
	(*func_ptr)( location, v0, v1, v2 );
}

inline void glUniform4fARB(GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2,  GLfloat v3)
{
	typedef void (*proc_type)(GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2,  GLfloat v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4fARB" ); }
	(*func_ptr)( location, v0, v1, v2, v3 );
}

inline void glUniform1iARB(GLint location,  GLint v0)
{
	typedef void (*proc_type)(GLint location,  GLint v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1iARB" ); }
	(*func_ptr)( location, v0 );
}

inline void glUniform2iARB(GLint location,  GLint v0,  GLint v1)
{
	typedef void (*proc_type)(GLint location,  GLint v0,  GLint v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2iARB" ); }
	(*func_ptr)( location, v0, v1 );
}

inline void glUniform3iARB(GLint location,  GLint v0,  GLint v1,  GLint v2)
{
	typedef void (*proc_type)(GLint location,  GLint v0,  GLint v1,  GLint v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3iARB" ); }
	(*func_ptr)( location, v0, v1, v2 );
}

inline void glUniform4iARB(GLint location,  GLint v0,  GLint v1,  GLint v2,  GLint v3)
{
	typedef void (*proc_type)(GLint location,  GLint v0,  GLint v1,  GLint v2,  GLint v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4iARB" ); }
	(*func_ptr)( location, v0, v1, v2, v3 );
}

inline void glUniform1fvARB(GLint location,  GLsizei count,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1fvARB" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform2fvARB(GLint location,  GLsizei count,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2fvARB" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform3fvARB(GLint location,  GLsizei count,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3fvARB" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform4fvARB(GLint location,  GLsizei count,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4fvARB" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform1ivARB(GLint location,  GLsizei count,  const GLint *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1ivARB" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform2ivARB(GLint location,  GLsizei count,  const GLint *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2ivARB" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform3ivARB(GLint location,  GLsizei count,  const GLint *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3ivARB" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform4ivARB(GLint location,  GLsizei count,  const GLint *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4ivARB" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniformMatrix2fvARB(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix2fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix2fvARB" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glUniformMatrix3fvARB(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix3fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix3fvARB" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glUniformMatrix4fvARB(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix4fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix4fvARB" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glGetObjectParameterfvARB(GLhandleARB obj,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLhandleARB obj,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetObjectParameterfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetObjectParameterfvARB" ); }
	(*func_ptr)( obj, pname, params );
}

inline void glGetObjectParameterivARB(GLhandleARB obj,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLhandleARB obj,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetObjectParameterivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetObjectParameterivARB" ); }
	(*func_ptr)( obj, pname, params );
}

inline void glGetInfoLogARB(GLhandleARB obj,  GLsizei maxLength,  GLsizei *length,  GLcharARB *infoLog)
{
	typedef void (*proc_type)(GLhandleARB obj,  GLsizei maxLength,  GLsizei *length,  GLcharARB *infoLog);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetInfoLogARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetInfoLogARB" ); }
	(*func_ptr)( obj, maxLength, length, infoLog );
}

inline void glGetAttachedObjectsARB(GLhandleARB containerObj,  GLsizei maxCount,  GLsizei *count,  GLhandleARB *obj)
{
	typedef void (*proc_type)(GLhandleARB containerObj,  GLsizei maxCount,  GLsizei *count,  GLhandleARB *obj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetAttachedObjectsARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetAttachedObjectsARB" ); }
	(*func_ptr)( containerObj, maxCount, count, obj );
}

inline GLint glGetUniformLocationARB(GLhandleARB programObj,  const GLcharARB *name)
{
	typedef GLint (*proc_type)(GLhandleARB programObj,  const GLcharARB *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformLocationARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformLocationARB" ); }
	return (*func_ptr)( programObj, name );
}

inline void glGetActiveUniformARB(GLhandleARB programObj,  GLuint index,  GLsizei maxLength,  GLsizei *length,  GLint *size,  GLenum *type,  GLcharARB *name)
{
	typedef void (*proc_type)(GLhandleARB programObj,  GLuint index,  GLsizei maxLength,  GLsizei *length,  GLint *size,  GLenum *type,  GLcharARB *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveUniformARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveUniformARB" ); }
	(*func_ptr)( programObj, index, maxLength, length, size, type, name );
}

inline void glGetUniformfvARB(GLhandleARB programObj,  GLint location,  GLfloat *params)
{
	typedef void (*proc_type)(GLhandleARB programObj,  GLint location,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformfvARB" ); }
	(*func_ptr)( programObj, location, params );
}

inline void glGetUniformivARB(GLhandleARB programObj,  GLint location,  GLint *params)
{
	typedef void (*proc_type)(GLhandleARB programObj,  GLint location,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformivARB" ); }
	(*func_ptr)( programObj, location, params );
}

inline void glGetShaderSourceARB(GLhandleARB obj,  GLsizei maxLength,  GLsizei *length,  GLcharARB *source)
{
	typedef void (*proc_type)(GLhandleARB obj,  GLsizei maxLength,  GLsizei *length,  GLcharARB *source);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetShaderSourceARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetShaderSourceARB" ); }
	(*func_ptr)( obj, maxLength, length, source );
}

inline void glBindAttribLocationARB(GLhandleARB programObj,  GLuint index,  const GLcharARB *name)
{
	typedef void (*proc_type)(GLhandleARB programObj,  GLuint index,  const GLcharARB *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindAttribLocationARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindAttribLocationARB" ); }
	(*func_ptr)( programObj, index, name );
}

inline void glGetActiveAttribARB(GLhandleARB programObj,  GLuint index,  GLsizei maxLength,  GLsizei *length,  GLint *size,  GLenum *type,  GLcharARB *name)
{
	typedef void (*proc_type)(GLhandleARB programObj,  GLuint index,  GLsizei maxLength,  GLsizei *length,  GLint *size,  GLenum *type,  GLcharARB *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveAttribARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveAttribARB" ); }
	(*func_ptr)( programObj, index, maxLength, length, size, type, name );
}

inline GLint glGetAttribLocationARB(GLhandleARB programObj,  const GLcharARB *name)
{
	typedef GLint (*proc_type)(GLhandleARB programObj,  const GLcharARB *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetAttribLocationARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetAttribLocationARB" ); }
	return (*func_ptr)( programObj, name );
}

inline void glDrawBuffersARB(GLsizei n,  const GLenum *bufs)
{
	typedef void (*proc_type)(GLsizei n,  const GLenum *bufs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawBuffersARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawBuffersARB" ); }
	(*func_ptr)( n, bufs );
}

inline void glClampColorARB(GLenum target,  GLenum clamp)
{
	typedef void (*proc_type)(GLenum target,  GLenum clamp);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClampColorARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClampColorARB" ); }
	(*func_ptr)( target, clamp );
}

inline void glDrawArraysInstancedARB(GLenum mode,  GLint first,  GLsizei count,  GLsizei primcount)
{
	typedef void (*proc_type)(GLenum mode,  GLint first,  GLsizei count,  GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawArraysInstancedARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawArraysInstancedARB" ); }
	(*func_ptr)( mode, first, count, primcount );
}

inline void glDrawElementsInstancedARB(GLenum mode,  GLsizei count,  GLenum type,  const GLvoid *indices,  GLsizei primcount)
{
	typedef void (*proc_type)(GLenum mode,  GLsizei count,  GLenum type,  const GLvoid *indices,  GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementsInstancedARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementsInstancedARB" ); }
	(*func_ptr)( mode, count, type, indices, primcount );
}

inline GLboolean glIsRenderbuffer(GLuint renderbuffer)
{
	typedef GLboolean (*proc_type)(GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsRenderbuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsRenderbuffer" ); }
	return (*func_ptr)( renderbuffer );
}

inline void glBindRenderbuffer(GLenum target,  GLuint renderbuffer)
{
	typedef void (*proc_type)(GLenum target,  GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindRenderbuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindRenderbuffer" ); }
	(*func_ptr)( target, renderbuffer );
}

inline void glDeleteRenderbuffers(GLsizei n,  const GLuint *renderbuffers)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *renderbuffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteRenderbuffers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteRenderbuffers" ); }
	(*func_ptr)( n, renderbuffers );
}

inline void glGenRenderbuffers(GLsizei n,  GLuint *renderbuffers)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *renderbuffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenRenderbuffers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenRenderbuffers" ); }
	(*func_ptr)( n, renderbuffers );
}

inline void glRenderbufferStorage(GLenum target,  GLenum internalformat,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glRenderbufferStorage" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glRenderbufferStorage" ); }
	(*func_ptr)( target, internalformat, width, height );
}

inline void glGetRenderbufferParameteriv(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetRenderbufferParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetRenderbufferParameteriv" ); }
	(*func_ptr)( target, pname, params );
}

inline GLboolean glIsFramebuffer(GLuint framebuffer)
{
	typedef GLboolean (*proc_type)(GLuint framebuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsFramebuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsFramebuffer" ); }
	return (*func_ptr)( framebuffer );
}

inline void glBindFramebuffer(GLenum target,  GLuint framebuffer)
{
	typedef void (*proc_type)(GLenum target,  GLuint framebuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindFramebuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindFramebuffer" ); }
	(*func_ptr)( target, framebuffer );
}

inline void glDeleteFramebuffers(GLsizei n,  const GLuint *framebuffers)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *framebuffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteFramebuffers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteFramebuffers" ); }
	(*func_ptr)( n, framebuffers );
}

inline void glGenFramebuffers(GLsizei n,  GLuint *framebuffers)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *framebuffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenFramebuffers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenFramebuffers" ); }
	(*func_ptr)( n, framebuffers );
}

inline GLenum glCheckFramebufferStatus(GLenum target)
{
	typedef GLenum (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCheckFramebufferStatus" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCheckFramebufferStatus" ); }
	return (*func_ptr)( target );
}

inline void glFramebufferTexture1D(GLenum target,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTexture1D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTexture1D" ); }
	(*func_ptr)( target, attachment, textarget, texture, level );
}

inline void glFramebufferTexture2D(GLenum target,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTexture2D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTexture2D" ); }
	(*func_ptr)( target, attachment, textarget, texture, level );
}

inline void glFramebufferTexture3D(GLenum target,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level,  GLint zoffset)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level,  GLint zoffset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTexture3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTexture3D" ); }
	(*func_ptr)( target, attachment, textarget, texture, level, zoffset );
}

inline void glFramebufferRenderbuffer(GLenum target,  GLenum attachment,  GLenum renderbuffertarget,  GLuint renderbuffer)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLenum renderbuffertarget,  GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferRenderbuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferRenderbuffer" ); }
	(*func_ptr)( target, attachment, renderbuffertarget, renderbuffer );
}

inline void glGetFramebufferAttachmentParameteriv(GLenum target,  GLenum attachment,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFramebufferAttachmentParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFramebufferAttachmentParameteriv" ); }
	(*func_ptr)( target, attachment, pname, params );
}

inline void glGenerateMipmap(GLenum target)
{
	typedef void (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenerateMipmap" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenerateMipmap" ); }
	(*func_ptr)( target );
}

inline void glBlitFramebuffer(GLint srcX0,  GLint srcY0,  GLint srcX1,  GLint srcY1,  GLint dstX0,  GLint dstY0,  GLint dstX1,  GLint dstY1,  GLbitfield mask,  GLenum filter)
{
	typedef void (*proc_type)(GLint srcX0,  GLint srcY0,  GLint srcX1,  GLint srcY1,  GLint dstX0,  GLint dstY0,  GLint dstX1,  GLint dstY1,  GLbitfield mask,  GLenum filter);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlitFramebuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlitFramebuffer" ); }
	(*func_ptr)( srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter );
}

inline void glRenderbufferStorageMultisample(GLenum target,  GLsizei samples,  GLenum internalformat,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLenum target,  GLsizei samples,  GLenum internalformat,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glRenderbufferStorageMultisample" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glRenderbufferStorageMultisample" ); }
	(*func_ptr)( target, samples, internalformat, width, height );
}

inline void glFramebufferTextureLayer(GLenum target,  GLenum attachment,  GLuint texture,  GLint level,  GLint layer)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLuint texture,  GLint level,  GLint layer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTextureLayer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTextureLayer" ); }
	(*func_ptr)( target, attachment, texture, level, layer );
}

inline void glProgramParameteriARB(GLuint program,  GLenum pname,  GLint value)
{
	typedef void (*proc_type)(GLuint program,  GLenum pname,  GLint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameteriARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameteriARB" ); }
	(*func_ptr)( program, pname, value );
}

inline void glFramebufferTextureARB(GLenum target,  GLenum attachment,  GLuint texture,  GLint level)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLuint texture,  GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTextureARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTextureARB" ); }
	(*func_ptr)( target, attachment, texture, level );
}

inline void glFramebufferTextureLayerARB(GLenum target,  GLenum attachment,  GLuint texture,  GLint level,  GLint layer)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLuint texture,  GLint level,  GLint layer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTextureLayerARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTextureLayerARB" ); }
	(*func_ptr)( target, attachment, texture, level, layer );
}

inline void glFramebufferTextureFaceARB(GLenum target,  GLenum attachment,  GLuint texture,  GLint level,  GLenum face)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLuint texture,  GLint level,  GLenum face);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTextureFaceARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTextureFaceARB" ); }
	(*func_ptr)( target, attachment, texture, level, face );
}

inline void glVertexAttribDivisorARB(GLuint index,  GLuint divisor)
{
	typedef void (*proc_type)(GLuint index,  GLuint divisor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribDivisorARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribDivisorARB" ); }
	(*func_ptr)( index, divisor );
}

inline void glFlushMappedBufferRange(GLenum target,  GLintptr offset,  GLsizeiptr length)
{
	typedef void (*proc_type)(GLenum target,  GLintptr offset,  GLsizeiptr length);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFlushMappedBufferRange" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFlushMappedBufferRange" ); }
	(*func_ptr)( target, offset, length );
}

inline void glTexBufferARB(GLenum target,  GLenum internalformat,  GLuint buffer)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexBufferARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexBufferARB" ); }
	(*func_ptr)( target, internalformat, buffer );
}

inline void glBindVertexArray(GLuint array)
{
	typedef void (*proc_type)(GLuint array);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindVertexArray" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindVertexArray" ); }
	(*func_ptr)( array );
}

inline void glDeleteVertexArrays(GLsizei n,  const GLuint *arrays)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *arrays);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteVertexArrays" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteVertexArrays" ); }
	(*func_ptr)( n, arrays );
}

inline void glGenVertexArrays(GLsizei n,  GLuint *arrays)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *arrays);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenVertexArrays" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenVertexArrays" ); }
	(*func_ptr)( n, arrays );
}

inline GLboolean glIsVertexArray(GLuint array)
{
	typedef GLboolean (*proc_type)(GLuint array);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsVertexArray" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsVertexArray" ); }
	return (*func_ptr)( array );
}

inline void glGetUniformIndices(GLuint program,  GLsizei uniformCount,  const GLchar* *uniformNames,  GLuint *uniformIndices)
{
	typedef void (*proc_type)(GLuint program,  GLsizei uniformCount,  const GLchar* *uniformNames,  GLuint *uniformIndices);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformIndices" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformIndices" ); }
	(*func_ptr)( program, uniformCount, uniformNames, uniformIndices );
}

inline void glGetActiveUniformsiv(GLuint program,  GLsizei uniformCount,  const GLuint *uniformIndices,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint program,  GLsizei uniformCount,  const GLuint *uniformIndices,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveUniformsiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveUniformsiv" ); }
	(*func_ptr)( program, uniformCount, uniformIndices, pname, params );
}

inline void glGetActiveUniformName(GLuint program,  GLuint uniformIndex,  GLsizei bufSize,  GLsizei *length,  GLchar *uniformName)
{
	typedef void (*proc_type)(GLuint program,  GLuint uniformIndex,  GLsizei bufSize,  GLsizei *length,  GLchar *uniformName);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveUniformName" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveUniformName" ); }
	(*func_ptr)( program, uniformIndex, bufSize, length, uniformName );
}

inline GLuint glGetUniformBlockIndex(GLuint program,  const GLchar *uniformBlockName)
{
	typedef GLuint (*proc_type)(GLuint program,  const GLchar *uniformBlockName);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformBlockIndex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformBlockIndex" ); }
	return (*func_ptr)( program, uniformBlockName );
}

inline void glGetActiveUniformBlockiv(GLuint program,  GLuint uniformBlockIndex,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint program,  GLuint uniformBlockIndex,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveUniformBlockiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveUniformBlockiv" ); }
	(*func_ptr)( program, uniformBlockIndex, pname, params );
}

inline void glGetActiveUniformBlockName(GLuint program,  GLuint uniformBlockIndex,  GLsizei bufSize,  GLsizei *length,  GLchar *uniformBlockName)
{
	typedef void (*proc_type)(GLuint program,  GLuint uniformBlockIndex,  GLsizei bufSize,  GLsizei *length,  GLchar *uniformBlockName);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveUniformBlockName" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveUniformBlockName" ); }
	(*func_ptr)( program, uniformBlockIndex, bufSize, length, uniformBlockName );
}

inline void glUniformBlockBinding(GLuint program,  GLuint uniformBlockIndex,  GLuint uniformBlockBinding)
{
	typedef void (*proc_type)(GLuint program,  GLuint uniformBlockIndex,  GLuint uniformBlockBinding);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformBlockBinding" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformBlockBinding" ); }
	(*func_ptr)( program, uniformBlockIndex, uniformBlockBinding );
}

inline void glCopyBufferSubData(GLenum readTarget,  GLenum writeTarget,  GLintptr readOffset,  GLintptr writeOffset,  GLsizeiptr size)
{
	typedef void (*proc_type)(GLenum readTarget,  GLenum writeTarget,  GLintptr readOffset,  GLintptr writeOffset,  GLsizeiptr size);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyBufferSubData" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyBufferSubData" ); }
	(*func_ptr)( readTarget, writeTarget, readOffset, writeOffset, size );
}

inline void glDrawElementsBaseVertex(GLenum mode,  GLsizei count,  GLenum type,  const GLvoid *indices,  GLint basevertex)
{
	typedef void (*proc_type)(GLenum mode,  GLsizei count,  GLenum type,  const GLvoid *indices,  GLint basevertex);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementsBaseVertex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementsBaseVertex" ); }
	(*func_ptr)( mode, count, type, indices, basevertex );
}

inline void glDrawRangeElementsBaseVertex(GLenum mode,  GLuint start,  GLuint end,  GLsizei count,  GLenum type,  const GLvoid *indices,  GLint basevertex)
{
	typedef void (*proc_type)(GLenum mode,  GLuint start,  GLuint end,  GLsizei count,  GLenum type,  const GLvoid *indices,  GLint basevertex);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawRangeElementsBaseVertex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawRangeElementsBaseVertex" ); }
	(*func_ptr)( mode, start, end, count, type, indices, basevertex );
}

inline void glDrawElementsInstancedBaseVertex(GLenum mode,  GLsizei count,  GLenum type,  const GLvoid *indices,  GLsizei primcount,  GLint basevertex)
{
	typedef void (*proc_type)(GLenum mode,  GLsizei count,  GLenum type,  const GLvoid *indices,  GLsizei primcount,  GLint basevertex);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementsInstancedBaseVertex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementsInstancedBaseVertex" ); }
	(*func_ptr)( mode, count, type, indices, primcount, basevertex );
}

inline void glMultiDrawElementsBaseVertex(GLenum mode,  const GLsizei *count,  GLenum type,  const GLvoid* *indices,  GLsizei primcount,  const GLint *basevertex)
{
	typedef void (*proc_type)(GLenum mode,  const GLsizei *count,  GLenum type,  const GLvoid* *indices,  GLsizei primcount,  const GLint *basevertex);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawElementsBaseVertex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawElementsBaseVertex" ); }
	(*func_ptr)( mode, count, type, indices, primcount, basevertex );
}

inline void glProvokingVertex(GLenum mode)
{
	typedef void (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProvokingVertex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProvokingVertex" ); }
	(*func_ptr)( mode );
}

inline GLsync glFenceSync(GLenum condition,  GLbitfield flags)
{
	typedef GLsync (*proc_type)(GLenum condition,  GLbitfield flags);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFenceSync" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFenceSync" ); }
	return (*func_ptr)( condition, flags );
}

inline GLboolean glIsSync(GLsync sync)
{
	typedef GLboolean (*proc_type)(GLsync sync);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsSync" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsSync" ); }
	return (*func_ptr)( sync );
}

inline void glDeleteSync(GLsync sync)
{
	typedef void (*proc_type)(GLsync sync);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteSync" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteSync" ); }
	(*func_ptr)( sync );
}

inline GLenum glClientWaitSync(GLsync sync,  GLbitfield flags,  GLuint64 timeout)
{
	typedef GLenum (*proc_type)(GLsync sync,  GLbitfield flags,  GLuint64 timeout);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClientWaitSync" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClientWaitSync" ); }
	return (*func_ptr)( sync, flags, timeout );
}

inline void glWaitSync(GLsync sync,  GLbitfield flags,  GLuint64 timeout)
{
	typedef void (*proc_type)(GLsync sync,  GLbitfield flags,  GLuint64 timeout);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWaitSync" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWaitSync" ); }
	(*func_ptr)( sync, flags, timeout );
}

inline void glGetInteger64v(GLenum pname,  GLint64 *params)
{
	typedef void (*proc_type)(GLenum pname,  GLint64 *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetInteger64v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetInteger64v" ); }
	(*func_ptr)( pname, params );
}

inline void glGetSynciv(GLsync sync,  GLenum pname,  GLsizei bufSize,  GLsizei *length,  GLint *values)
{
	typedef void (*proc_type)(GLsync sync,  GLenum pname,  GLsizei bufSize,  GLsizei *length,  GLint *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSynciv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSynciv" ); }
	(*func_ptr)( sync, pname, bufSize, length, values );
}

inline void glTexImage2DMultisample(GLenum target,  GLsizei samples,  GLint internalformat,  GLsizei width,  GLsizei height,  GLboolean fixedsamplelocations)
{
	typedef void (*proc_type)(GLenum target,  GLsizei samples,  GLint internalformat,  GLsizei width,  GLsizei height,  GLboolean fixedsamplelocations);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexImage2DMultisample" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexImage2DMultisample" ); }
	(*func_ptr)( target, samples, internalformat, width, height, fixedsamplelocations );
}

inline void glTexImage3DMultisample(GLenum target,  GLsizei samples,  GLint internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLboolean fixedsamplelocations)
{
	typedef void (*proc_type)(GLenum target,  GLsizei samples,  GLint internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLboolean fixedsamplelocations);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexImage3DMultisample" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexImage3DMultisample" ); }
	(*func_ptr)( target, samples, internalformat, width, height, depth, fixedsamplelocations );
}

inline void glGetMultisamplefv(GLenum pname,  GLuint index,  GLfloat *val)
{
	typedef void (*proc_type)(GLenum pname,  GLuint index,  GLfloat *val);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultisamplefv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultisamplefv" ); }
	(*func_ptr)( pname, index, val );
}

inline void glSampleMaski(GLuint index,  GLbitfield mask)
{
	typedef void (*proc_type)(GLuint index,  GLbitfield mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSampleMaski" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSampleMaski" ); }
	(*func_ptr)( index, mask );
}

inline void glBlendEquationiARB(GLuint buf,  GLenum mode)
{
	typedef void (*proc_type)(GLuint buf,  GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationiARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationiARB" ); }
	(*func_ptr)( buf, mode );
}

inline void glBlendEquationSeparateiARB(GLuint buf,  GLenum modeRGB,  GLenum modeAlpha)
{
	typedef void (*proc_type)(GLuint buf,  GLenum modeRGB,  GLenum modeAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationSeparateiARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationSeparateiARB" ); }
	(*func_ptr)( buf, modeRGB, modeAlpha );
}

inline void glBlendFunciARB(GLuint buf,  GLenum src,  GLenum dst)
{
	typedef void (*proc_type)(GLuint buf,  GLenum src,  GLenum dst);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFunciARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFunciARB" ); }
	(*func_ptr)( buf, src, dst );
}

inline void glBlendFuncSeparateiARB(GLuint buf,  GLenum srcRGB,  GLenum dstRGB,  GLenum srcAlpha,  GLenum dstAlpha)
{
	typedef void (*proc_type)(GLuint buf,  GLenum srcRGB,  GLenum dstRGB,  GLenum srcAlpha,  GLenum dstAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFuncSeparateiARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFuncSeparateiARB" ); }
	(*func_ptr)( buf, srcRGB, dstRGB, srcAlpha, dstAlpha );
}

inline void glMinSampleShadingARB(GLfloat value)
{
	typedef void (*proc_type)(GLfloat value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMinSampleShadingARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMinSampleShadingARB" ); }
	(*func_ptr)( value );
}

inline void glNamedStringARB(GLenum type,  GLint namelen,  const GLchar *name,  GLint stringlen,  const GLchar *string)
{
	typedef void (*proc_type)(GLenum type,  GLint namelen,  const GLchar *name,  GLint stringlen,  const GLchar *string);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedStringARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedStringARB" ); }
	(*func_ptr)( type, namelen, name, stringlen, string );
}

inline void glDeleteNamedStringARB(GLint namelen,  const GLchar *name)
{
	typedef void (*proc_type)(GLint namelen,  const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteNamedStringARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteNamedStringARB" ); }
	(*func_ptr)( namelen, name );
}

inline void glCompileShaderIncludeARB(GLuint shader,  GLsizei count,  const GLchar* *path,  const GLint *length)
{
	typedef void (*proc_type)(GLuint shader,  GLsizei count,  const GLchar* *path,  const GLint *length);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompileShaderIncludeARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompileShaderIncludeARB" ); }
	(*func_ptr)( shader, count, path, length );
}

inline GLboolean glIsNamedStringARB(GLint namelen,  const GLchar *name)
{
	typedef GLboolean (*proc_type)(GLint namelen,  const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsNamedStringARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsNamedStringARB" ); }
	return (*func_ptr)( namelen, name );
}

inline void glGetNamedStringARB(GLint namelen,  const GLchar *name,  GLsizei bufSize,  GLint *stringlen,  GLchar *string)
{
	typedef void (*proc_type)(GLint namelen,  const GLchar *name,  GLsizei bufSize,  GLint *stringlen,  GLchar *string);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedStringARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedStringARB" ); }
	(*func_ptr)( namelen, name, bufSize, stringlen, string );
}

inline void glGetNamedStringivARB(GLint namelen,  const GLchar *name,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLint namelen,  const GLchar *name,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedStringivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedStringivARB" ); }
	(*func_ptr)( namelen, name, pname, params );
}

inline void glBindFragDataLocationIndexed(GLuint program,  GLuint colorNumber,  GLuint index,  const GLchar *name)
{
	typedef void (*proc_type)(GLuint program,  GLuint colorNumber,  GLuint index,  const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindFragDataLocationIndexed" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindFragDataLocationIndexed" ); }
	(*func_ptr)( program, colorNumber, index, name );
}

inline GLint glGetFragDataIndex(GLuint program,  const GLchar *name)
{
	typedef GLint (*proc_type)(GLuint program,  const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFragDataIndex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFragDataIndex" ); }
	return (*func_ptr)( program, name );
}

inline void glGenSamplers(GLsizei count,  GLuint *samplers)
{
	typedef void (*proc_type)(GLsizei count,  GLuint *samplers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenSamplers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenSamplers" ); }
	(*func_ptr)( count, samplers );
}

inline void glDeleteSamplers(GLsizei count,  const GLuint *samplers)
{
	typedef void (*proc_type)(GLsizei count,  const GLuint *samplers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteSamplers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteSamplers" ); }
	(*func_ptr)( count, samplers );
}

inline GLboolean glIsSampler(GLuint sampler)
{
	typedef GLboolean (*proc_type)(GLuint sampler);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsSampler" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsSampler" ); }
	return (*func_ptr)( sampler );
}

inline void glBindSampler(GLuint unit,  GLuint sampler)
{
	typedef void (*proc_type)(GLuint unit,  GLuint sampler);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindSampler" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindSampler" ); }
	(*func_ptr)( unit, sampler );
}

inline void glSamplerParameteri(GLuint sampler,  GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLuint sampler,  GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSamplerParameteri" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSamplerParameteri" ); }
	(*func_ptr)( sampler, pname, param );
}

inline void glSamplerParameteriv(GLuint sampler,  GLenum pname,  const GLint *param)
{
	typedef void (*proc_type)(GLuint sampler,  GLenum pname,  const GLint *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSamplerParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSamplerParameteriv" ); }
	(*func_ptr)( sampler, pname, param );
}

inline void glSamplerParameterf(GLuint sampler,  GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLuint sampler,  GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSamplerParameterf" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSamplerParameterf" ); }
	(*func_ptr)( sampler, pname, param );
}

inline void glSamplerParameterfv(GLuint sampler,  GLenum pname,  const GLfloat *param)
{
	typedef void (*proc_type)(GLuint sampler,  GLenum pname,  const GLfloat *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSamplerParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSamplerParameterfv" ); }
	(*func_ptr)( sampler, pname, param );
}

inline void glSamplerParameterIiv(GLuint sampler,  GLenum pname,  const GLint *param)
{
	typedef void (*proc_type)(GLuint sampler,  GLenum pname,  const GLint *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSamplerParameterIiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSamplerParameterIiv" ); }
	(*func_ptr)( sampler, pname, param );
}

inline void glSamplerParameterIuiv(GLuint sampler,  GLenum pname,  const GLuint *param)
{
	typedef void (*proc_type)(GLuint sampler,  GLenum pname,  const GLuint *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSamplerParameterIuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSamplerParameterIuiv" ); }
	(*func_ptr)( sampler, pname, param );
}

inline void glGetSamplerParameteriv(GLuint sampler,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint sampler,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSamplerParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSamplerParameteriv" ); }
	(*func_ptr)( sampler, pname, params );
}

inline void glGetSamplerParameterIiv(GLuint sampler,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint sampler,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSamplerParameterIiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSamplerParameterIiv" ); }
	(*func_ptr)( sampler, pname, params );
}

inline void glGetSamplerParameterfv(GLuint sampler,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLuint sampler,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSamplerParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSamplerParameterfv" ); }
	(*func_ptr)( sampler, pname, params );
}

inline void glGetSamplerParameterIuiv(GLuint sampler,  GLenum pname,  GLuint *params)
{
	typedef void (*proc_type)(GLuint sampler,  GLenum pname,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSamplerParameterIuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSamplerParameterIuiv" ); }
	(*func_ptr)( sampler, pname, params );
}

inline void glQueryCounter(GLuint id,  GLenum target)
{
	typedef void (*proc_type)(GLuint id,  GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glQueryCounter" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glQueryCounter" ); }
	(*func_ptr)( id, target );
}

inline void glGetQueryObjecti64v(GLuint id,  GLenum pname,  GLint64 *params)
{
	typedef void (*proc_type)(GLuint id,  GLenum pname,  GLint64 *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryObjecti64v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryObjecti64v" ); }
	(*func_ptr)( id, pname, params );
}

inline void glGetQueryObjectui64v(GLuint id,  GLenum pname,  GLuint64 *params)
{
	typedef void (*proc_type)(GLuint id,  GLenum pname,  GLuint64 *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryObjectui64v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryObjectui64v" ); }
	(*func_ptr)( id, pname, params );
}

inline void glVertexP2ui(GLenum type,  GLuint value)
{
	typedef void (*proc_type)(GLenum type,  GLuint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexP2ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexP2ui" ); }
	(*func_ptr)( type, value );
}

inline void glVertexP2uiv(GLenum type,  const GLuint *value)
{
	typedef void (*proc_type)(GLenum type,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexP2uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexP2uiv" ); }
	(*func_ptr)( type, value );
}

inline void glVertexP3ui(GLenum type,  GLuint value)
{
	typedef void (*proc_type)(GLenum type,  GLuint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexP3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexP3ui" ); }
	(*func_ptr)( type, value );
}

inline void glVertexP3uiv(GLenum type,  const GLuint *value)
{
	typedef void (*proc_type)(GLenum type,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexP3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexP3uiv" ); }
	(*func_ptr)( type, value );
}

inline void glVertexP4ui(GLenum type,  GLuint value)
{
	typedef void (*proc_type)(GLenum type,  GLuint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexP4ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexP4ui" ); }
	(*func_ptr)( type, value );
}

inline void glVertexP4uiv(GLenum type,  const GLuint *value)
{
	typedef void (*proc_type)(GLenum type,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexP4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexP4uiv" ); }
	(*func_ptr)( type, value );
}

inline void glTexCoordP1ui(GLenum type,  GLuint coords)
{
	typedef void (*proc_type)(GLenum type,  GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordP1ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordP1ui" ); }
	(*func_ptr)( type, coords );
}

inline void glTexCoordP1uiv(GLenum type,  const GLuint *coords)
{
	typedef void (*proc_type)(GLenum type,  const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordP1uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordP1uiv" ); }
	(*func_ptr)( type, coords );
}

inline void glTexCoordP2ui(GLenum type,  GLuint coords)
{
	typedef void (*proc_type)(GLenum type,  GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordP2ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordP2ui" ); }
	(*func_ptr)( type, coords );
}

inline void glTexCoordP2uiv(GLenum type,  const GLuint *coords)
{
	typedef void (*proc_type)(GLenum type,  const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordP2uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordP2uiv" ); }
	(*func_ptr)( type, coords );
}

inline void glTexCoordP3ui(GLenum type,  GLuint coords)
{
	typedef void (*proc_type)(GLenum type,  GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordP3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordP3ui" ); }
	(*func_ptr)( type, coords );
}

inline void glTexCoordP3uiv(GLenum type,  const GLuint *coords)
{
	typedef void (*proc_type)(GLenum type,  const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordP3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordP3uiv" ); }
	(*func_ptr)( type, coords );
}

inline void glTexCoordP4ui(GLenum type,  GLuint coords)
{
	typedef void (*proc_type)(GLenum type,  GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordP4ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordP4ui" ); }
	(*func_ptr)( type, coords );
}

inline void glTexCoordP4uiv(GLenum type,  const GLuint *coords)
{
	typedef void (*proc_type)(GLenum type,  const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordP4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordP4uiv" ); }
	(*func_ptr)( type, coords );
}

inline void glMultiTexCoordP1ui(GLenum texture,  GLenum type,  GLuint coords)
{
	typedef void (*proc_type)(GLenum texture,  GLenum type,  GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordP1ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordP1ui" ); }
	(*func_ptr)( texture, type, coords );
}

inline void glMultiTexCoordP1uiv(GLenum texture,  GLenum type,  const GLuint *coords)
{
	typedef void (*proc_type)(GLenum texture,  GLenum type,  const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordP1uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordP1uiv" ); }
	(*func_ptr)( texture, type, coords );
}

inline void glMultiTexCoordP2ui(GLenum texture,  GLenum type,  GLuint coords)
{
	typedef void (*proc_type)(GLenum texture,  GLenum type,  GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordP2ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordP2ui" ); }
	(*func_ptr)( texture, type, coords );
}

inline void glMultiTexCoordP2uiv(GLenum texture,  GLenum type,  const GLuint *coords)
{
	typedef void (*proc_type)(GLenum texture,  GLenum type,  const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordP2uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordP2uiv" ); }
	(*func_ptr)( texture, type, coords );
}

inline void glMultiTexCoordP3ui(GLenum texture,  GLenum type,  GLuint coords)
{
	typedef void (*proc_type)(GLenum texture,  GLenum type,  GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordP3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordP3ui" ); }
	(*func_ptr)( texture, type, coords );
}

inline void glMultiTexCoordP3uiv(GLenum texture,  GLenum type,  const GLuint *coords)
{
	typedef void (*proc_type)(GLenum texture,  GLenum type,  const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordP3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordP3uiv" ); }
	(*func_ptr)( texture, type, coords );
}

inline void glMultiTexCoordP4ui(GLenum texture,  GLenum type,  GLuint coords)
{
	typedef void (*proc_type)(GLenum texture,  GLenum type,  GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordP4ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordP4ui" ); }
	(*func_ptr)( texture, type, coords );
}

inline void glMultiTexCoordP4uiv(GLenum texture,  GLenum type,  const GLuint *coords)
{
	typedef void (*proc_type)(GLenum texture,  GLenum type,  const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordP4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordP4uiv" ); }
	(*func_ptr)( texture, type, coords );
}

inline void glNormalP3ui(GLenum type,  GLuint coords)
{
	typedef void (*proc_type)(GLenum type,  GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalP3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalP3ui" ); }
	(*func_ptr)( type, coords );
}

inline void glNormalP3uiv(GLenum type,  const GLuint *coords)
{
	typedef void (*proc_type)(GLenum type,  const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalP3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalP3uiv" ); }
	(*func_ptr)( type, coords );
}

inline void glColorP3ui(GLenum type,  GLuint color)
{
	typedef void (*proc_type)(GLenum type,  GLuint color);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorP3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorP3ui" ); }
	(*func_ptr)( type, color );
}

inline void glColorP3uiv(GLenum type,  const GLuint *color)
{
	typedef void (*proc_type)(GLenum type,  const GLuint *color);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorP3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorP3uiv" ); }
	(*func_ptr)( type, color );
}

inline void glColorP4ui(GLenum type,  GLuint color)
{
	typedef void (*proc_type)(GLenum type,  GLuint color);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorP4ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorP4ui" ); }
	(*func_ptr)( type, color );
}

inline void glColorP4uiv(GLenum type,  const GLuint *color)
{
	typedef void (*proc_type)(GLenum type,  const GLuint *color);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorP4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorP4uiv" ); }
	(*func_ptr)( type, color );
}

inline void glSecondaryColorP3ui(GLenum type,  GLuint color)
{
	typedef void (*proc_type)(GLenum type,  GLuint color);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColorP3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColorP3ui" ); }
	(*func_ptr)( type, color );
}

inline void glSecondaryColorP3uiv(GLenum type,  const GLuint *color)
{
	typedef void (*proc_type)(GLenum type,  const GLuint *color);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColorP3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColorP3uiv" ); }
	(*func_ptr)( type, color );
}

inline void glVertexAttribP1ui(GLuint index,  GLenum type,  GLboolean normalized,  GLuint value)
{
	typedef void (*proc_type)(GLuint index,  GLenum type,  GLboolean normalized,  GLuint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribP1ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribP1ui" ); }
	(*func_ptr)( index, type, normalized, value );
}

inline void glVertexAttribP1uiv(GLuint index,  GLenum type,  GLboolean normalized,  const GLuint *value)
{
	typedef void (*proc_type)(GLuint index,  GLenum type,  GLboolean normalized,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribP1uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribP1uiv" ); }
	(*func_ptr)( index, type, normalized, value );
}

inline void glVertexAttribP2ui(GLuint index,  GLenum type,  GLboolean normalized,  GLuint value)
{
	typedef void (*proc_type)(GLuint index,  GLenum type,  GLboolean normalized,  GLuint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribP2ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribP2ui" ); }
	(*func_ptr)( index, type, normalized, value );
}

inline void glVertexAttribP2uiv(GLuint index,  GLenum type,  GLboolean normalized,  const GLuint *value)
{
	typedef void (*proc_type)(GLuint index,  GLenum type,  GLboolean normalized,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribP2uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribP2uiv" ); }
	(*func_ptr)( index, type, normalized, value );
}

inline void glVertexAttribP3ui(GLuint index,  GLenum type,  GLboolean normalized,  GLuint value)
{
	typedef void (*proc_type)(GLuint index,  GLenum type,  GLboolean normalized,  GLuint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribP3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribP3ui" ); }
	(*func_ptr)( index, type, normalized, value );
}

inline void glVertexAttribP3uiv(GLuint index,  GLenum type,  GLboolean normalized,  const GLuint *value)
{
	typedef void (*proc_type)(GLuint index,  GLenum type,  GLboolean normalized,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribP3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribP3uiv" ); }
	(*func_ptr)( index, type, normalized, value );
}

inline void glVertexAttribP4ui(GLuint index,  GLenum type,  GLboolean normalized,  GLuint value)
{
	typedef void (*proc_type)(GLuint index,  GLenum type,  GLboolean normalized,  GLuint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribP4ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribP4ui" ); }
	(*func_ptr)( index, type, normalized, value );
}

inline void glVertexAttribP4uiv(GLuint index,  GLenum type,  GLboolean normalized,  const GLuint *value)
{
	typedef void (*proc_type)(GLuint index,  GLenum type,  GLboolean normalized,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribP4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribP4uiv" ); }
	(*func_ptr)( index, type, normalized, value );
}

inline void glDrawArraysIndirect(GLenum mode,  const GLvoid *indirect)
{
	typedef void (*proc_type)(GLenum mode,  const GLvoid *indirect);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawArraysIndirect" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawArraysIndirect" ); }
	(*func_ptr)( mode, indirect );
}

inline void glDrawElementsIndirect(GLenum mode,  GLenum type,  const GLvoid *indirect)
{
	typedef void (*proc_type)(GLenum mode,  GLenum type,  const GLvoid *indirect);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementsIndirect" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementsIndirect" ); }
	(*func_ptr)( mode, type, indirect );
}

inline void glUniform1d(GLint location,  GLdouble x)
{
	typedef void (*proc_type)(GLint location,  GLdouble x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1d" ); }
	(*func_ptr)( location, x );
}

inline void glUniform2d(GLint location,  GLdouble x,  GLdouble y)
{
	typedef void (*proc_type)(GLint location,  GLdouble x,  GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2d" ); }
	(*func_ptr)( location, x, y );
}

inline void glUniform3d(GLint location,  GLdouble x,  GLdouble y,  GLdouble z)
{
	typedef void (*proc_type)(GLint location,  GLdouble x,  GLdouble y,  GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3d" ); }
	(*func_ptr)( location, x, y, z );
}

inline void glUniform4d(GLint location,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w)
{
	typedef void (*proc_type)(GLint location,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4d" ); }
	(*func_ptr)( location, x, y, z, w );
}

inline void glUniform1dv(GLint location,  GLsizei count,  const GLdouble *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1dv" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform2dv(GLint location,  GLsizei count,  const GLdouble *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2dv" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform3dv(GLint location,  GLsizei count,  const GLdouble *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3dv" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform4dv(GLint location,  GLsizei count,  const GLdouble *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4dv" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniformMatrix2dv(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix2dv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glUniformMatrix3dv(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix3dv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glUniformMatrix4dv(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix4dv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glUniformMatrix2x3dv(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix2x3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix2x3dv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glUniformMatrix2x4dv(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix2x4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix2x4dv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glUniformMatrix3x2dv(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix3x2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix3x2dv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glUniformMatrix3x4dv(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix3x4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix3x4dv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glUniformMatrix4x2dv(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix4x2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix4x2dv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glUniformMatrix4x3dv(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix4x3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix4x3dv" ); }
	(*func_ptr)( location, count, transpose, value );
}

inline void glGetUniformdv(GLuint program,  GLint location,  GLdouble *params)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformdv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformdv" ); }
	(*func_ptr)( program, location, params );
}

inline GLint glGetSubroutineUniformLocation(GLuint program,  GLenum shadertype,  const GLchar *name)
{
	typedef GLint (*proc_type)(GLuint program,  GLenum shadertype,  const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSubroutineUniformLocation" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSubroutineUniformLocation" ); }
	return (*func_ptr)( program, shadertype, name );
}

inline GLuint glGetSubroutineIndex(GLuint program,  GLenum shadertype,  const GLchar *name)
{
	typedef GLuint (*proc_type)(GLuint program,  GLenum shadertype,  const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSubroutineIndex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSubroutineIndex" ); }
	return (*func_ptr)( program, shadertype, name );
}

inline void glGetActiveSubroutineUniformiv(GLuint program,  GLenum shadertype,  GLuint index,  GLenum pname,  GLint *values)
{
	typedef void (*proc_type)(GLuint program,  GLenum shadertype,  GLuint index,  GLenum pname,  GLint *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveSubroutineUniformiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveSubroutineUniformiv" ); }
	(*func_ptr)( program, shadertype, index, pname, values );
}

inline void glGetActiveSubroutineUniformName(GLuint program,  GLenum shadertype,  GLuint index,  GLsizei bufsize,  GLsizei *length,  GLchar *name)
{
	typedef void (*proc_type)(GLuint program,  GLenum shadertype,  GLuint index,  GLsizei bufsize,  GLsizei *length,  GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveSubroutineUniformName" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveSubroutineUniformName" ); }
	(*func_ptr)( program, shadertype, index, bufsize, length, name );
}

inline void glGetActiveSubroutineName(GLuint program,  GLenum shadertype,  GLuint index,  GLsizei bufsize,  GLsizei *length,  GLchar *name)
{
	typedef void (*proc_type)(GLuint program,  GLenum shadertype,  GLuint index,  GLsizei bufsize,  GLsizei *length,  GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveSubroutineName" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveSubroutineName" ); }
	(*func_ptr)( program, shadertype, index, bufsize, length, name );
}

inline void glUniformSubroutinesuiv(GLenum shadertype,  GLsizei count,  const GLuint *indices)
{
	typedef void (*proc_type)(GLenum shadertype,  GLsizei count,  const GLuint *indices);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformSubroutinesuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformSubroutinesuiv" ); }
	(*func_ptr)( shadertype, count, indices );
}

inline void glGetUniformSubroutineuiv(GLenum shadertype,  GLint location,  GLuint *params)
{
	typedef void (*proc_type)(GLenum shadertype,  GLint location,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformSubroutineuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformSubroutineuiv" ); }
	(*func_ptr)( shadertype, location, params );
}

inline void glGetProgramStageiv(GLuint program,  GLenum shadertype,  GLenum pname,  GLint *values)
{
	typedef void (*proc_type)(GLuint program,  GLenum shadertype,  GLenum pname,  GLint *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramStageiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramStageiv" ); }
	(*func_ptr)( program, shadertype, pname, values );
}

inline void glPatchParameteri(GLenum pname,  GLint value)
{
	typedef void (*proc_type)(GLenum pname,  GLint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPatchParameteri" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPatchParameteri" ); }
	(*func_ptr)( pname, value );
}

inline void glPatchParameterfv(GLenum pname,  const GLfloat *values)
{
	typedef void (*proc_type)(GLenum pname,  const GLfloat *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPatchParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPatchParameterfv" ); }
	(*func_ptr)( pname, values );
}

inline void glBindTransformFeedback(GLenum target,  GLuint id)
{
	typedef void (*proc_type)(GLenum target,  GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindTransformFeedback" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindTransformFeedback" ); }
	(*func_ptr)( target, id );
}

inline void glDeleteTransformFeedbacks(GLsizei n,  const GLuint *ids)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteTransformFeedbacks" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteTransformFeedbacks" ); }
	(*func_ptr)( n, ids );
}

inline void glGenTransformFeedbacks(GLsizei n,  GLuint *ids)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenTransformFeedbacks" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenTransformFeedbacks" ); }
	(*func_ptr)( n, ids );
}

inline GLboolean glIsTransformFeedback(GLuint id)
{
	typedef GLboolean (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsTransformFeedback" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsTransformFeedback" ); }
	return (*func_ptr)( id );
}

inline void glPauseTransformFeedback(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPauseTransformFeedback" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPauseTransformFeedback" ); }
	(*func_ptr)(  );
}

inline void glResumeTransformFeedback(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glResumeTransformFeedback" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glResumeTransformFeedback" ); }
	(*func_ptr)(  );
}

inline void glDrawTransformFeedback(GLenum mode,  GLuint id)
{
	typedef void (*proc_type)(GLenum mode,  GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawTransformFeedback" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawTransformFeedback" ); }
	(*func_ptr)( mode, id );
}

inline void glDrawTransformFeedbackStream(GLenum mode,  GLuint id,  GLuint stream)
{
	typedef void (*proc_type)(GLenum mode,  GLuint id,  GLuint stream);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawTransformFeedbackStream" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawTransformFeedbackStream" ); }
	(*func_ptr)( mode, id, stream );
}

inline void glBeginQueryIndexed(GLenum target,  GLuint index,  GLuint id)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginQueryIndexed" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginQueryIndexed" ); }
	(*func_ptr)( target, index, id );
}

inline void glEndQueryIndexed(GLenum target,  GLuint index)
{
	typedef void (*proc_type)(GLenum target,  GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndQueryIndexed" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndQueryIndexed" ); }
	(*func_ptr)( target, index );
}

inline void glGetQueryIndexediv(GLenum target,  GLuint index,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryIndexediv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryIndexediv" ); }
	(*func_ptr)( target, index, pname, params );
}

inline void glReleaseShaderCompiler(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReleaseShaderCompiler" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReleaseShaderCompiler" ); }
	(*func_ptr)(  );
}

inline void glShaderBinary(GLsizei count,  const GLuint *shaders,  GLenum binaryformat,  const GLvoid *binary,  GLsizei length)
{
	typedef void (*proc_type)(GLsizei count,  const GLuint *shaders,  GLenum binaryformat,  const GLvoid *binary,  GLsizei length);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glShaderBinary" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glShaderBinary" ); }
	(*func_ptr)( count, shaders, binaryformat, binary, length );
}

inline void glGetShaderPrecisionFormat(GLenum shadertype,  GLenum precisiontype,  GLint *range,  GLint *precision)
{
	typedef void (*proc_type)(GLenum shadertype,  GLenum precisiontype,  GLint *range,  GLint *precision);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetShaderPrecisionFormat" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetShaderPrecisionFormat" ); }
	(*func_ptr)( shadertype, precisiontype, range, precision );
}

inline void glDepthRangef(GLfloat n,  GLfloat f)
{
	typedef void (*proc_type)(GLfloat n,  GLfloat f);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDepthRangef" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDepthRangef" ); }
	(*func_ptr)( n, f );
}

inline void glClearDepthf(GLfloat d)
{
	typedef void (*proc_type)(GLfloat d);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClearDepthf" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClearDepthf" ); }
	(*func_ptr)( d );
}

inline void glGetProgramBinary(GLuint program,  GLsizei bufSize,  GLsizei *length,  GLenum *binaryFormat,  GLvoid *binary)
{
	typedef void (*proc_type)(GLuint program,  GLsizei bufSize,  GLsizei *length,  GLenum *binaryFormat,  GLvoid *binary);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramBinary" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramBinary" ); }
	(*func_ptr)( program, bufSize, length, binaryFormat, binary );
}

inline void glProgramBinary(GLuint program,  GLenum binaryFormat,  const GLvoid *binary,  GLsizei length)
{
	typedef void (*proc_type)(GLuint program,  GLenum binaryFormat,  const GLvoid *binary,  GLsizei length);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramBinary" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramBinary" ); }
	(*func_ptr)( program, binaryFormat, binary, length );
}

inline void glProgramParameteri(GLuint program,  GLenum pname,  GLint value)
{
	typedef void (*proc_type)(GLuint program,  GLenum pname,  GLint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameteri" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameteri" ); }
	(*func_ptr)( program, pname, value );
}

inline void glUseProgramStages(GLuint pipeline,  GLbitfield stages,  GLuint program)
{
	typedef void (*proc_type)(GLuint pipeline,  GLbitfield stages,  GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUseProgramStages" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUseProgramStages" ); }
	(*func_ptr)( pipeline, stages, program );
}

inline void glActiveShaderProgram(GLuint pipeline,  GLuint program)
{
	typedef void (*proc_type)(GLuint pipeline,  GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glActiveShaderProgram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glActiveShaderProgram" ); }
	(*func_ptr)( pipeline, program );
}

inline GLuint glCreateShaderProgramv(GLenum type,  GLsizei count,  const GLchar* *strings)
{
	typedef GLuint (*proc_type)(GLenum type,  GLsizei count,  const GLchar* *strings);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCreateShaderProgramv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCreateShaderProgramv" ); }
	return (*func_ptr)( type, count, strings );
}

inline void glBindProgramPipeline(GLuint pipeline)
{
	typedef void (*proc_type)(GLuint pipeline);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindProgramPipeline" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindProgramPipeline" ); }
	(*func_ptr)( pipeline );
}

inline void glDeleteProgramPipelines(GLsizei n,  const GLuint *pipelines)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *pipelines);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteProgramPipelines" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteProgramPipelines" ); }
	(*func_ptr)( n, pipelines );
}

inline void glGenProgramPipelines(GLsizei n,  GLuint *pipelines)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *pipelines);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenProgramPipelines" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenProgramPipelines" ); }
	(*func_ptr)( n, pipelines );
}

inline GLboolean glIsProgramPipeline(GLuint pipeline)
{
	typedef GLboolean (*proc_type)(GLuint pipeline);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsProgramPipeline" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsProgramPipeline" ); }
	return (*func_ptr)( pipeline );
}

inline void glGetProgramPipelineiv(GLuint pipeline,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint pipeline,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramPipelineiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramPipelineiv" ); }
	(*func_ptr)( pipeline, pname, params );
}

inline void glProgramUniform1i(GLuint program,  GLint location,  GLint v0)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLint v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1i" ); }
	(*func_ptr)( program, location, v0 );
}

inline void glProgramUniform1iv(GLuint program,  GLint location,  GLsizei count,  const GLint *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1iv" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform1f(GLuint program,  GLint location,  GLfloat v0)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLfloat v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1f" ); }
	(*func_ptr)( program, location, v0 );
}

inline void glProgramUniform1fv(GLuint program,  GLint location,  GLsizei count,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1fv" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform1d(GLuint program,  GLint location,  GLdouble v0)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLdouble v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1d" ); }
	(*func_ptr)( program, location, v0 );
}

inline void glProgramUniform1dv(GLuint program,  GLint location,  GLsizei count,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1dv" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform1ui(GLuint program,  GLint location,  GLuint v0)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1ui" ); }
	(*func_ptr)( program, location, v0 );
}

inline void glProgramUniform1uiv(GLuint program,  GLint location,  GLsizei count,  const GLuint *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1uiv" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform2i(GLuint program,  GLint location,  GLint v0,  GLint v1)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLint v0,  GLint v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2i" ); }
	(*func_ptr)( program, location, v0, v1 );
}

inline void glProgramUniform2iv(GLuint program,  GLint location,  GLsizei count,  const GLint *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2iv" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform2f(GLuint program,  GLint location,  GLfloat v0,  GLfloat v1)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLfloat v0,  GLfloat v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2f" ); }
	(*func_ptr)( program, location, v0, v1 );
}

inline void glProgramUniform2fv(GLuint program,  GLint location,  GLsizei count,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2fv" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform2d(GLuint program,  GLint location,  GLdouble v0,  GLdouble v1)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLdouble v0,  GLdouble v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2d" ); }
	(*func_ptr)( program, location, v0, v1 );
}

inline void glProgramUniform2dv(GLuint program,  GLint location,  GLsizei count,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2dv" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform2ui(GLuint program,  GLint location,  GLuint v0,  GLuint v1)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint v0,  GLuint v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2ui" ); }
	(*func_ptr)( program, location, v0, v1 );
}

inline void glProgramUniform2uiv(GLuint program,  GLint location,  GLsizei count,  const GLuint *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2uiv" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform3i(GLuint program,  GLint location,  GLint v0,  GLint v1,  GLint v2)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLint v0,  GLint v1,  GLint v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3i" ); }
	(*func_ptr)( program, location, v0, v1, v2 );
}

inline void glProgramUniform3iv(GLuint program,  GLint location,  GLsizei count,  const GLint *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3iv" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform3f(GLuint program,  GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3f" ); }
	(*func_ptr)( program, location, v0, v1, v2 );
}

inline void glProgramUniform3fv(GLuint program,  GLint location,  GLsizei count,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3fv" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform3d(GLuint program,  GLint location,  GLdouble v0,  GLdouble v1,  GLdouble v2)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLdouble v0,  GLdouble v1,  GLdouble v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3d" ); }
	(*func_ptr)( program, location, v0, v1, v2 );
}

inline void glProgramUniform3dv(GLuint program,  GLint location,  GLsizei count,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3dv" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform3ui(GLuint program,  GLint location,  GLuint v0,  GLuint v1,  GLuint v2)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint v0,  GLuint v1,  GLuint v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3ui" ); }
	(*func_ptr)( program, location, v0, v1, v2 );
}

inline void glProgramUniform3uiv(GLuint program,  GLint location,  GLsizei count,  const GLuint *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3uiv" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform4i(GLuint program,  GLint location,  GLint v0,  GLint v1,  GLint v2,  GLint v3)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLint v0,  GLint v1,  GLint v2,  GLint v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4i" ); }
	(*func_ptr)( program, location, v0, v1, v2, v3 );
}

inline void glProgramUniform4iv(GLuint program,  GLint location,  GLsizei count,  const GLint *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4iv" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform4f(GLuint program,  GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2,  GLfloat v3)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2,  GLfloat v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4f" ); }
	(*func_ptr)( program, location, v0, v1, v2, v3 );
}

inline void glProgramUniform4fv(GLuint program,  GLint location,  GLsizei count,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4fv" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform4d(GLuint program,  GLint location,  GLdouble v0,  GLdouble v1,  GLdouble v2,  GLdouble v3)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLdouble v0,  GLdouble v1,  GLdouble v2,  GLdouble v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4d" ); }
	(*func_ptr)( program, location, v0, v1, v2, v3 );
}

inline void glProgramUniform4dv(GLuint program,  GLint location,  GLsizei count,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4dv" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform4ui(GLuint program,  GLint location,  GLuint v0,  GLuint v1,  GLuint v2,  GLuint v3)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint v0,  GLuint v1,  GLuint v2,  GLuint v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4ui" ); }
	(*func_ptr)( program, location, v0, v1, v2, v3 );
}

inline void glProgramUniform4uiv(GLuint program,  GLint location,  GLsizei count,  const GLuint *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4uiv" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniformMatrix2fv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2fv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix3fv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3fv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix4fv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4fv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix2dv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2dv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix3dv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3dv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix4dv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4dv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix2x3fv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2x3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2x3fv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix3x2fv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3x2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3x2fv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix2x4fv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2x4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2x4fv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix4x2fv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4x2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4x2fv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix3x4fv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3x4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3x4fv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix4x3fv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4x3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4x3fv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix2x3dv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2x3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2x3dv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix3x2dv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3x2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3x2dv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix2x4dv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2x4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2x4dv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix4x2dv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4x2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4x2dv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix3x4dv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3x4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3x4dv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix4x3dv(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4x3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4x3dv" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glValidateProgramPipeline(GLuint pipeline)
{
	typedef void (*proc_type)(GLuint pipeline);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glValidateProgramPipeline" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glValidateProgramPipeline" ); }
	(*func_ptr)( pipeline );
}

inline void glGetProgramPipelineInfoLog(GLuint pipeline,  GLsizei bufSize,  GLsizei *length,  GLchar *infoLog)
{
	typedef void (*proc_type)(GLuint pipeline,  GLsizei bufSize,  GLsizei *length,  GLchar *infoLog);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramPipelineInfoLog" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramPipelineInfoLog" ); }
	(*func_ptr)( pipeline, bufSize, length, infoLog );
}

inline void glVertexAttribL1d(GLuint index,  GLdouble x)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL1d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL1d" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttribL2d(GLuint index,  GLdouble x,  GLdouble y)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x,  GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL2d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL2d" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttribL3d(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL3d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL3d" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttribL4d(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL4d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL4d" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttribL1dv(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL1dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL1dv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribL2dv(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL2dv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribL3dv(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL3dv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribL4dv(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL4dv" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribLPointer(GLuint index,  GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLuint index,  GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribLPointer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribLPointer" ); }
	(*func_ptr)( index, size, type, stride, pointer );
}

inline void glGetVertexAttribLdv(GLuint index,  GLenum pname,  GLdouble *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribLdv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribLdv" ); }
	(*func_ptr)( index, pname, params );
}

inline void glViewportArrayv(GLuint first,  GLsizei count,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint first,  GLsizei count,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glViewportArrayv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glViewportArrayv" ); }
	(*func_ptr)( first, count, v );
}

inline void glViewportIndexedf(GLuint index,  GLfloat x,  GLfloat y,  GLfloat w,  GLfloat h)
{
	typedef void (*proc_type)(GLuint index,  GLfloat x,  GLfloat y,  GLfloat w,  GLfloat h);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glViewportIndexedf" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glViewportIndexedf" ); }
	(*func_ptr)( index, x, y, w, h );
}

inline void glViewportIndexedfv(GLuint index,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint index,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glViewportIndexedfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glViewportIndexedfv" ); }
	(*func_ptr)( index, v );
}

inline void glScissorArrayv(GLuint first,  GLsizei count,  const GLint *v)
{
	typedef void (*proc_type)(GLuint first,  GLsizei count,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glScissorArrayv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glScissorArrayv" ); }
	(*func_ptr)( first, count, v );
}

inline void glScissorIndexed(GLuint index,  GLint left,  GLint bottom,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLuint index,  GLint left,  GLint bottom,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glScissorIndexed" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glScissorIndexed" ); }
	(*func_ptr)( index, left, bottom, width, height );
}

inline void glScissorIndexedv(GLuint index,  const GLint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glScissorIndexedv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glScissorIndexedv" ); }
	(*func_ptr)( index, v );
}

inline void glDepthRangeArrayv(GLuint first,  GLsizei count,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint first,  GLsizei count,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDepthRangeArrayv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDepthRangeArrayv" ); }
	(*func_ptr)( first, count, v );
}

inline void glDepthRangeIndexed(GLuint index,  GLdouble n,  GLdouble f)
{
	typedef void (*proc_type)(GLuint index,  GLdouble n,  GLdouble f);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDepthRangeIndexed" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDepthRangeIndexed" ); }
	(*func_ptr)( index, n, f );
}

inline void glGetFloati_v(GLenum target,  GLuint index,  GLfloat *data)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLfloat *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFloati_v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFloati_v" ); }
	(*func_ptr)( target, index, data );
}

inline void glGetDoublei_v(GLenum target,  GLuint index,  GLdouble *data)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLdouble *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetDoublei_v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetDoublei_v" ); }
	(*func_ptr)( target, index, data );
}

inline GLsync glCreateSyncFromCLeventARB(struct _cl_context * context,  struct _cl_event * event,  GLbitfield flags)
{
	typedef GLsync (*proc_type)(struct _cl_context * context,  struct _cl_event * event,  GLbitfield flags);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCreateSyncFromCLeventARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCreateSyncFromCLeventARB" ); }
	return (*func_ptr)( context, event, flags );
}

inline void glDebugMessageControlARB(GLenum source,  GLenum type,  GLenum severity,  GLsizei count,  const GLuint *ids,  GLboolean enabled)
{
	typedef void (*proc_type)(GLenum source,  GLenum type,  GLenum severity,  GLsizei count,  const GLuint *ids,  GLboolean enabled);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDebugMessageControlARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDebugMessageControlARB" ); }
	(*func_ptr)( source, type, severity, count, ids, enabled );
}

inline void glDebugMessageInsertARB(GLenum source,  GLenum type,  GLuint id,  GLenum severity,  GLsizei length,  const GLchar *buf)
{
	typedef void (*proc_type)(GLenum source,  GLenum type,  GLuint id,  GLenum severity,  GLsizei length,  const GLchar *buf);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDebugMessageInsertARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDebugMessageInsertARB" ); }
	(*func_ptr)( source, type, id, severity, length, buf );
}

inline void glDebugMessageCallbackARB(GLDEBUGPROCARB callback,  const GLvoid *userParam)
{
	typedef void (*proc_type)(GLDEBUGPROCARB callback,  const GLvoid *userParam);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDebugMessageCallbackARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDebugMessageCallbackARB" ); }
	(*func_ptr)( callback, userParam );
}

inline GLuint glGetDebugMessageLogARB(GLuint count,  GLsizei bufsize,  GLenum *sources,  GLenum *types,  GLuint *ids,  GLenum *severities,  GLsizei *lengths,  GLchar *messageLog)
{
	typedef GLuint (*proc_type)(GLuint count,  GLsizei bufsize,  GLenum *sources,  GLenum *types,  GLuint *ids,  GLenum *severities,  GLsizei *lengths,  GLchar *messageLog);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetDebugMessageLogARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetDebugMessageLogARB" ); }
	return (*func_ptr)( count, bufsize, sources, types, ids, severities, lengths, messageLog );
}

inline GLenum glGetGraphicsResetStatusARB(void)
{
	typedef GLenum (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetGraphicsResetStatusARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetGraphicsResetStatusARB" ); }
	return (*func_ptr)(  );
}

inline void glGetnMapdvARB(GLenum target,  GLenum query,  GLsizei bufSize,  GLdouble *v)
{
	typedef void (*proc_type)(GLenum target,  GLenum query,  GLsizei bufSize,  GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnMapdvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnMapdvARB" ); }
	(*func_ptr)( target, query, bufSize, v );
}

inline void glGetnMapfvARB(GLenum target,  GLenum query,  GLsizei bufSize,  GLfloat *v)
{
	typedef void (*proc_type)(GLenum target,  GLenum query,  GLsizei bufSize,  GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnMapfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnMapfvARB" ); }
	(*func_ptr)( target, query, bufSize, v );
}

inline void glGetnMapivARB(GLenum target,  GLenum query,  GLsizei bufSize,  GLint *v)
{
	typedef void (*proc_type)(GLenum target,  GLenum query,  GLsizei bufSize,  GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnMapivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnMapivARB" ); }
	(*func_ptr)( target, query, bufSize, v );
}

inline void glGetnPixelMapfvARB(GLenum map,  GLsizei bufSize,  GLfloat *values)
{
	typedef void (*proc_type)(GLenum map,  GLsizei bufSize,  GLfloat *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnPixelMapfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnPixelMapfvARB" ); }
	(*func_ptr)( map, bufSize, values );
}

inline void glGetnPixelMapuivARB(GLenum map,  GLsizei bufSize,  GLuint *values)
{
	typedef void (*proc_type)(GLenum map,  GLsizei bufSize,  GLuint *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnPixelMapuivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnPixelMapuivARB" ); }
	(*func_ptr)( map, bufSize, values );
}

inline void glGetnPixelMapusvARB(GLenum map,  GLsizei bufSize,  GLushort *values)
{
	typedef void (*proc_type)(GLenum map,  GLsizei bufSize,  GLushort *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnPixelMapusvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnPixelMapusvARB" ); }
	(*func_ptr)( map, bufSize, values );
}

inline void glGetnPolygonStippleARB(GLsizei bufSize,  GLubyte *pattern)
{
	typedef void (*proc_type)(GLsizei bufSize,  GLubyte *pattern);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnPolygonStippleARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnPolygonStippleARB" ); }
	(*func_ptr)( bufSize, pattern );
}

inline void glGetnColorTableARB(GLenum target,  GLenum format,  GLenum type,  GLsizei bufSize,  GLvoid *table)
{
	typedef void (*proc_type)(GLenum target,  GLenum format,  GLenum type,  GLsizei bufSize,  GLvoid *table);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnColorTableARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnColorTableARB" ); }
	(*func_ptr)( target, format, type, bufSize, table );
}

inline void glGetnConvolutionFilterARB(GLenum target,  GLenum format,  GLenum type,  GLsizei bufSize,  GLvoid *image)
{
	typedef void (*proc_type)(GLenum target,  GLenum format,  GLenum type,  GLsizei bufSize,  GLvoid *image);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnConvolutionFilterARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnConvolutionFilterARB" ); }
	(*func_ptr)( target, format, type, bufSize, image );
}

inline void glGetnSeparableFilterARB(GLenum target,  GLenum format,  GLenum type,  GLsizei rowBufSize,  GLvoid *row,  GLsizei columnBufSize,  GLvoid *column,  GLvoid *span)
{
	typedef void (*proc_type)(GLenum target,  GLenum format,  GLenum type,  GLsizei rowBufSize,  GLvoid *row,  GLsizei columnBufSize,  GLvoid *column,  GLvoid *span);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnSeparableFilterARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnSeparableFilterARB" ); }
	(*func_ptr)( target, format, type, rowBufSize, row, columnBufSize, column, span );
}

inline void glGetnHistogramARB(GLenum target,  GLboolean reset,  GLenum format,  GLenum type,  GLsizei bufSize,  GLvoid *values)
{
	typedef void (*proc_type)(GLenum target,  GLboolean reset,  GLenum format,  GLenum type,  GLsizei bufSize,  GLvoid *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnHistogramARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnHistogramARB" ); }
	(*func_ptr)( target, reset, format, type, bufSize, values );
}

inline void glGetnMinmaxARB(GLenum target,  GLboolean reset,  GLenum format,  GLenum type,  GLsizei bufSize,  GLvoid *values)
{
	typedef void (*proc_type)(GLenum target,  GLboolean reset,  GLenum format,  GLenum type,  GLsizei bufSize,  GLvoid *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnMinmaxARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnMinmaxARB" ); }
	(*func_ptr)( target, reset, format, type, bufSize, values );
}

inline void glGetnTexImageARB(GLenum target,  GLint level,  GLenum format,  GLenum type,  GLsizei bufSize,  GLvoid *img)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLenum format,  GLenum type,  GLsizei bufSize,  GLvoid *img);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnTexImageARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnTexImageARB" ); }
	(*func_ptr)( target, level, format, type, bufSize, img );
}

inline void glReadnPixelsARB(GLint x,  GLint y,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  GLsizei bufSize,  GLvoid *data)
{
	typedef void (*proc_type)(GLint x,  GLint y,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  GLsizei bufSize,  GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReadnPixelsARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReadnPixelsARB" ); }
	(*func_ptr)( x, y, width, height, format, type, bufSize, data );
}

inline void glGetnCompressedTexImageARB(GLenum target,  GLint lod,  GLsizei bufSize,  GLvoid *img)
{
	typedef void (*proc_type)(GLenum target,  GLint lod,  GLsizei bufSize,  GLvoid *img);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnCompressedTexImageARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnCompressedTexImageARB" ); }
	(*func_ptr)( target, lod, bufSize, img );
}

inline void glGetnUniformfvARB(GLuint program,  GLint location,  GLsizei bufSize,  GLfloat *params)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei bufSize,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnUniformfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnUniformfvARB" ); }
	(*func_ptr)( program, location, bufSize, params );
}

inline void glGetnUniformivARB(GLuint program,  GLint location,  GLsizei bufSize,  GLint *params)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei bufSize,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnUniformivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnUniformivARB" ); }
	(*func_ptr)( program, location, bufSize, params );
}

inline void glGetnUniformuivARB(GLuint program,  GLint location,  GLsizei bufSize,  GLuint *params)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei bufSize,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnUniformuivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnUniformuivARB" ); }
	(*func_ptr)( program, location, bufSize, params );
}

inline void glGetnUniformdvARB(GLuint program,  GLint location,  GLsizei bufSize,  GLdouble *params)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei bufSize,  GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnUniformdvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnUniformdvARB" ); }
	(*func_ptr)( program, location, bufSize, params );
}

inline void glDrawArraysInstancedBaseInstance(GLenum mode,  GLint first,  GLsizei count,  GLsizei primcount,  GLuint baseinstance)
{
	typedef void (*proc_type)(GLenum mode,  GLint first,  GLsizei count,  GLsizei primcount,  GLuint baseinstance);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawArraysInstancedBaseInstance" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawArraysInstancedBaseInstance" ); }
	(*func_ptr)( mode, first, count, primcount, baseinstance );
}

inline void glDrawElementsInstancedBaseInstance(GLenum mode,  GLsizei count,  GLenum type,  const void *indices,  GLsizei primcount,  GLuint baseinstance)
{
	typedef void (*proc_type)(GLenum mode,  GLsizei count,  GLenum type,  const void *indices,  GLsizei primcount,  GLuint baseinstance);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementsInstancedBaseInstance" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementsInstancedBaseInstance" ); }
	(*func_ptr)( mode, count, type, indices, primcount, baseinstance );
}

inline void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode,  GLsizei count,  GLenum type,  const void *indices,  GLsizei primcount,  GLint basevertex,  GLuint baseinstance)
{
	typedef void (*proc_type)(GLenum mode,  GLsizei count,  GLenum type,  const void *indices,  GLsizei primcount,  GLint basevertex,  GLuint baseinstance);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementsInstancedBaseVertexBaseInstance" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementsInstancedBaseVertexBaseInstance" ); }
	(*func_ptr)( mode, count, type, indices, primcount, basevertex, baseinstance );
}

inline void glDrawTransformFeedbackInstanced(GLenum mode,  GLuint id,  GLsizei primcount)
{
	typedef void (*proc_type)(GLenum mode,  GLuint id,  GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawTransformFeedbackInstanced" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawTransformFeedbackInstanced" ); }
	(*func_ptr)( mode, id, primcount );
}

inline void glDrawTransformFeedbackStreamInstanced(GLenum mode,  GLuint id,  GLuint stream,  GLsizei primcount)
{
	typedef void (*proc_type)(GLenum mode,  GLuint id,  GLuint stream,  GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawTransformFeedbackStreamInstanced" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawTransformFeedbackStreamInstanced" ); }
	(*func_ptr)( mode, id, stream, primcount );
}

inline void glGetInternalformativ(GLenum target,  GLenum internalformat,  GLenum pname,  GLsizei bufSize,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLenum pname,  GLsizei bufSize,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetInternalformativ" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetInternalformativ" ); }
	(*func_ptr)( target, internalformat, pname, bufSize, params );
}

inline void glGetActiveAtomicCounterBufferiv(GLuint program,  GLuint bufferIndex,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint program,  GLuint bufferIndex,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveAtomicCounterBufferiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveAtomicCounterBufferiv" ); }
	(*func_ptr)( program, bufferIndex, pname, params );
}

inline void glBindImageTexture(GLuint unit,  GLuint texture,  GLint level,  GLboolean layered,  GLint layer,  GLenum access,  GLenum format)
{
	typedef void (*proc_type)(GLuint unit,  GLuint texture,  GLint level,  GLboolean layered,  GLint layer,  GLenum access,  GLenum format);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindImageTexture" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindImageTexture" ); }
	(*func_ptr)( unit, texture, level, layered, layer, access, format );
}

inline void glMemoryBarrier(GLbitfield barriers)
{
	typedef void (*proc_type)(GLbitfield barriers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMemoryBarrier" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMemoryBarrier" ); }
	(*func_ptr)( barriers );
}

inline void glTexStorage1D(GLenum target,  GLsizei levels,  GLenum internalformat,  GLsizei width)
{
	typedef void (*proc_type)(GLenum target,  GLsizei levels,  GLenum internalformat,  GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexStorage1D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexStorage1D" ); }
	(*func_ptr)( target, levels, internalformat, width );
}

inline void glTexStorage2D(GLenum target,  GLsizei levels,  GLenum internalformat,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLenum target,  GLsizei levels,  GLenum internalformat,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexStorage2D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexStorage2D" ); }
	(*func_ptr)( target, levels, internalformat, width, height );
}

inline void glTexStorage3D(GLenum target,  GLsizei levels,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth)
{
	typedef void (*proc_type)(GLenum target,  GLsizei levels,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexStorage3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexStorage3D" ); }
	(*func_ptr)( target, levels, internalformat, width, height, depth );
}

inline void glTextureStorage1DEXT(GLuint texture,  GLenum target,  GLsizei levels,  GLenum internalformat,  GLsizei width)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLsizei levels,  GLenum internalformat,  GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureStorage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureStorage1DEXT" ); }
	(*func_ptr)( texture, target, levels, internalformat, width );
}

inline void glTextureStorage2DEXT(GLuint texture,  GLenum target,  GLsizei levels,  GLenum internalformat,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLsizei levels,  GLenum internalformat,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureStorage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureStorage2DEXT" ); }
	(*func_ptr)( texture, target, levels, internalformat, width, height );
}

inline void glTextureStorage3DEXT(GLuint texture,  GLenum target,  GLsizei levels,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLsizei levels,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureStorage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureStorage3DEXT" ); }
	(*func_ptr)( texture, target, levels, internalformat, width, height, depth );
}

inline void glBlendColorEXT(GLfloat red,  GLfloat green,  GLfloat blue,  GLfloat alpha)
{
	typedef void (*proc_type)(GLfloat red,  GLfloat green,  GLfloat blue,  GLfloat alpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendColorEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendColorEXT" ); }
	(*func_ptr)( red, green, blue, alpha );
}

inline void glPolygonOffsetEXT(GLfloat factor,  GLfloat bias)
{
	typedef void (*proc_type)(GLfloat factor,  GLfloat bias);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPolygonOffsetEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPolygonOffsetEXT" ); }
	(*func_ptr)( factor, bias );
}

inline void glTexImage3DEXT(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexImage3DEXT" ); }
	(*func_ptr)( target, level, internalformat, width, height, depth, border, format, type, pixels );
}

inline void glTexSubImage3DEXT(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexSubImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexSubImage3DEXT" ); }
	(*func_ptr)( target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels );
}

inline void glGetTexFilterFuncSGIS(GLenum target,  GLenum filter,  GLfloat *weights)
{
	typedef void (*proc_type)(GLenum target,  GLenum filter,  GLfloat *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTexFilterFuncSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTexFilterFuncSGIS" ); }
	(*func_ptr)( target, filter, weights );
}

inline void glTexFilterFuncSGIS(GLenum target,  GLenum filter,  GLsizei n,  const GLfloat *weights)
{
	typedef void (*proc_type)(GLenum target,  GLenum filter,  GLsizei n,  const GLfloat *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexFilterFuncSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexFilterFuncSGIS" ); }
	(*func_ptr)( target, filter, n, weights );
}

inline void glTexSubImage1DEXT(GLenum target,  GLint level,  GLint xoffset,  GLsizei width,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLint xoffset,  GLsizei width,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexSubImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexSubImage1DEXT" ); }
	(*func_ptr)( target, level, xoffset, width, format, type, pixels );
}

inline void glTexSubImage2DEXT(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexSubImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexSubImage2DEXT" ); }
	(*func_ptr)( target, level, xoffset, yoffset, width, height, format, type, pixels );
}

inline void glCopyTexImage1DEXT(GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLint border)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLint border);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTexImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTexImage1DEXT" ); }
	(*func_ptr)( target, level, internalformat, x, y, width, border );
}

inline void glCopyTexImage2DEXT(GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLsizei height,  GLint border)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLsizei height,  GLint border);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTexImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTexImage2DEXT" ); }
	(*func_ptr)( target, level, internalformat, x, y, width, height, border );
}

inline void glCopyTexSubImage1DEXT(GLenum target,  GLint level,  GLint xoffset,  GLint x,  GLint y,  GLsizei width)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLint xoffset,  GLint x,  GLint y,  GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTexSubImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTexSubImage1DEXT" ); }
	(*func_ptr)( target, level, xoffset, x, y, width );
}

inline void glCopyTexSubImage2DEXT(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint x,  GLint y,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint x,  GLint y,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTexSubImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTexSubImage2DEXT" ); }
	(*func_ptr)( target, level, xoffset, yoffset, x, y, width, height );
}

inline void glCopyTexSubImage3DEXT(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLint x,  GLint y,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLint x,  GLint y,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTexSubImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTexSubImage3DEXT" ); }
	(*func_ptr)( target, level, xoffset, yoffset, zoffset, x, y, width, height );
}

inline void glGetHistogramEXT(GLenum target,  GLboolean reset,  GLenum format,  GLenum type,  GLvoid *values)
{
	typedef void (*proc_type)(GLenum target,  GLboolean reset,  GLenum format,  GLenum type,  GLvoid *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetHistogramEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetHistogramEXT" ); }
	(*func_ptr)( target, reset, format, type, values );
}

inline void glGetHistogramParameterfvEXT(GLenum target,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetHistogramParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetHistogramParameterfvEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetHistogramParameterivEXT(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetHistogramParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetHistogramParameterivEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetMinmaxEXT(GLenum target,  GLboolean reset,  GLenum format,  GLenum type,  GLvoid *values)
{
	typedef void (*proc_type)(GLenum target,  GLboolean reset,  GLenum format,  GLenum type,  GLvoid *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMinmaxEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMinmaxEXT" ); }
	(*func_ptr)( target, reset, format, type, values );
}

inline void glGetMinmaxParameterfvEXT(GLenum target,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMinmaxParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMinmaxParameterfvEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetMinmaxParameterivEXT(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMinmaxParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMinmaxParameterivEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glHistogramEXT(GLenum target,  GLsizei width,  GLenum internalformat,  GLboolean sink)
{
	typedef void (*proc_type)(GLenum target,  GLsizei width,  GLenum internalformat,  GLboolean sink);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glHistogramEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glHistogramEXT" ); }
	(*func_ptr)( target, width, internalformat, sink );
}

inline void glMinmaxEXT(GLenum target,  GLenum internalformat,  GLboolean sink)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLboolean sink);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMinmaxEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMinmaxEXT" ); }
	(*func_ptr)( target, internalformat, sink );
}

inline void glResetHistogramEXT(GLenum target)
{
	typedef void (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glResetHistogramEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glResetHistogramEXT" ); }
	(*func_ptr)( target );
}

inline void glResetMinmaxEXT(GLenum target)
{
	typedef void (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glResetMinmaxEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glResetMinmaxEXT" ); }
	(*func_ptr)( target );
}

inline void glConvolutionFilter1DEXT(GLenum target,  GLenum internalformat,  GLsizei width,  GLenum format,  GLenum type,  const GLvoid *image)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLsizei width,  GLenum format,  GLenum type,  const GLvoid *image);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionFilter1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionFilter1DEXT" ); }
	(*func_ptr)( target, internalformat, width, format, type, image );
}

inline void glConvolutionFilter2DEXT(GLenum target,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  const GLvoid *image)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  const GLvoid *image);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionFilter2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionFilter2DEXT" ); }
	(*func_ptr)( target, internalformat, width, height, format, type, image );
}

inline void glConvolutionParameterfEXT(GLenum target,  GLenum pname,  GLfloat params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLfloat params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionParameterfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionParameterfEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glConvolutionParameterfvEXT(GLenum target,  GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionParameterfvEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glConvolutionParameteriEXT(GLenum target,  GLenum pname,  GLint params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionParameteriEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionParameteriEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glConvolutionParameterivEXT(GLenum target,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionParameterivEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glCopyConvolutionFilter1DEXT(GLenum target,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyConvolutionFilter1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyConvolutionFilter1DEXT" ); }
	(*func_ptr)( target, internalformat, x, y, width );
}

inline void glCopyConvolutionFilter2DEXT(GLenum target,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyConvolutionFilter2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyConvolutionFilter2DEXT" ); }
	(*func_ptr)( target, internalformat, x, y, width, height );
}

inline void glGetConvolutionFilterEXT(GLenum target,  GLenum format,  GLenum type,  GLvoid *image)
{
	typedef void (*proc_type)(GLenum target,  GLenum format,  GLenum type,  GLvoid *image);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetConvolutionFilterEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetConvolutionFilterEXT" ); }
	(*func_ptr)( target, format, type, image );
}

inline void glGetConvolutionParameterfvEXT(GLenum target,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetConvolutionParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetConvolutionParameterfvEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetConvolutionParameterivEXT(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetConvolutionParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetConvolutionParameterivEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetSeparableFilterEXT(GLenum target,  GLenum format,  GLenum type,  GLvoid *row,  GLvoid *column,  GLvoid *span)
{
	typedef void (*proc_type)(GLenum target,  GLenum format,  GLenum type,  GLvoid *row,  GLvoid *column,  GLvoid *span);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSeparableFilterEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSeparableFilterEXT" ); }
	(*func_ptr)( target, format, type, row, column, span );
}

inline void glSeparableFilter2DEXT(GLenum target,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  const GLvoid *row,  const GLvoid *column)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  const GLvoid *row,  const GLvoid *column);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSeparableFilter2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSeparableFilter2DEXT" ); }
	(*func_ptr)( target, internalformat, width, height, format, type, row, column );
}

inline void glColorTableSGI(GLenum target,  GLenum internalformat,  GLsizei width,  GLenum format,  GLenum type,  const GLvoid *table)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLsizei width,  GLenum format,  GLenum type,  const GLvoid *table);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorTableSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorTableSGI" ); }
	(*func_ptr)( target, internalformat, width, format, type, table );
}

inline void glColorTableParameterfvSGI(GLenum target,  GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorTableParameterfvSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorTableParameterfvSGI" ); }
	(*func_ptr)( target, pname, params );
}

inline void glColorTableParameterivSGI(GLenum target,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorTableParameterivSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorTableParameterivSGI" ); }
	(*func_ptr)( target, pname, params );
}

inline void glCopyColorTableSGI(GLenum target,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyColorTableSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyColorTableSGI" ); }
	(*func_ptr)( target, internalformat, x, y, width );
}

inline void glGetColorTableSGI(GLenum target,  GLenum format,  GLenum type,  GLvoid *table)
{
	typedef void (*proc_type)(GLenum target,  GLenum format,  GLenum type,  GLvoid *table);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTableSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTableSGI" ); }
	(*func_ptr)( target, format, type, table );
}

inline void glGetColorTableParameterfvSGI(GLenum target,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTableParameterfvSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTableParameterfvSGI" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetColorTableParameterivSGI(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTableParameterivSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTableParameterivSGI" ); }
	(*func_ptr)( target, pname, params );
}

inline void glPixelTexGenSGIX(GLenum mode)
{
	typedef void (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTexGenSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTexGenSGIX" ); }
	(*func_ptr)( mode );
}

inline void glPixelTexGenParameteriSGIS(GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTexGenParameteriSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTexGenParameteriSGIS" ); }
	(*func_ptr)( pname, param );
}

inline void glPixelTexGenParameterivSGIS(GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTexGenParameterivSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTexGenParameterivSGIS" ); }
	(*func_ptr)( pname, params );
}

inline void glPixelTexGenParameterfSGIS(GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTexGenParameterfSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTexGenParameterfSGIS" ); }
	(*func_ptr)( pname, param );
}

inline void glPixelTexGenParameterfvSGIS(GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTexGenParameterfvSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTexGenParameterfvSGIS" ); }
	(*func_ptr)( pname, params );
}

inline void glGetPixelTexGenParameterivSGIS(GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPixelTexGenParameterivSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPixelTexGenParameterivSGIS" ); }
	(*func_ptr)( pname, params );
}

inline void glGetPixelTexGenParameterfvSGIS(GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPixelTexGenParameterfvSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPixelTexGenParameterfvSGIS" ); }
	(*func_ptr)( pname, params );
}

inline void glTexImage4DSGIS(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLsizei size4d,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLsizei size4d,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexImage4DSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexImage4DSGIS" ); }
	(*func_ptr)( target, level, internalformat, width, height, depth, size4d, border, format, type, pixels );
}

inline void glTexSubImage4DSGIS(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLint woffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLsizei size4d,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLint woffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLsizei size4d,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexSubImage4DSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexSubImage4DSGIS" ); }
	(*func_ptr)( target, level, xoffset, yoffset, zoffset, woffset, width, height, depth, size4d, format, type, pixels );
}

inline GLboolean glAreTexturesResidentEXT(GLsizei n,  const GLuint *textures,  GLboolean *residences)
{
	typedef GLboolean (*proc_type)(GLsizei n,  const GLuint *textures,  GLboolean *residences);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glAreTexturesResidentEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glAreTexturesResidentEXT" ); }
	return (*func_ptr)( n, textures, residences );
}

inline void glBindTextureEXT(GLenum target,  GLuint texture)
{
	typedef void (*proc_type)(GLenum target,  GLuint texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindTextureEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindTextureEXT" ); }
	(*func_ptr)( target, texture );
}

inline void glDeleteTexturesEXT(GLsizei n,  const GLuint *textures)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *textures);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteTexturesEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteTexturesEXT" ); }
	(*func_ptr)( n, textures );
}

inline void glGenTexturesEXT(GLsizei n,  GLuint *textures)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *textures);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenTexturesEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenTexturesEXT" ); }
	(*func_ptr)( n, textures );
}

inline GLboolean glIsTextureEXT(GLuint texture)
{
	typedef GLboolean (*proc_type)(GLuint texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsTextureEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsTextureEXT" ); }
	return (*func_ptr)( texture );
}

inline void glPrioritizeTexturesEXT(GLsizei n,  const GLuint *textures,  const GLclampf *priorities)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *textures,  const GLclampf *priorities);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPrioritizeTexturesEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPrioritizeTexturesEXT" ); }
	(*func_ptr)( n, textures, priorities );
}

inline void glDetailTexFuncSGIS(GLenum target,  GLsizei n,  const GLfloat *points)
{
	typedef void (*proc_type)(GLenum target,  GLsizei n,  const GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDetailTexFuncSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDetailTexFuncSGIS" ); }
	(*func_ptr)( target, n, points );
}

inline void glGetDetailTexFuncSGIS(GLenum target,  GLfloat *points)
{
	typedef void (*proc_type)(GLenum target,  GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetDetailTexFuncSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetDetailTexFuncSGIS" ); }
	(*func_ptr)( target, points );
}

inline void glSharpenTexFuncSGIS(GLenum target,  GLsizei n,  const GLfloat *points)
{
	typedef void (*proc_type)(GLenum target,  GLsizei n,  const GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSharpenTexFuncSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSharpenTexFuncSGIS" ); }
	(*func_ptr)( target, n, points );
}

inline void glGetSharpenTexFuncSGIS(GLenum target,  GLfloat *points)
{
	typedef void (*proc_type)(GLenum target,  GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSharpenTexFuncSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSharpenTexFuncSGIS" ); }
	(*func_ptr)( target, points );
}

inline void glSampleMaskSGIS(GLclampf value,  GLboolean invert)
{
	typedef void (*proc_type)(GLclampf value,  GLboolean invert);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSampleMaskSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSampleMaskSGIS" ); }
	(*func_ptr)( value, invert );
}

inline void glSamplePatternSGIS(GLenum pattern)
{
	typedef void (*proc_type)(GLenum pattern);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSamplePatternSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSamplePatternSGIS" ); }
	(*func_ptr)( pattern );
}

inline void glArrayElementEXT(GLint i)
{
	typedef void (*proc_type)(GLint i);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glArrayElementEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glArrayElementEXT" ); }
	(*func_ptr)( i );
}

inline void glColorPointerEXT(GLint size,  GLenum type,  GLsizei stride,  GLsizei count,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  GLsizei stride,  GLsizei count,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorPointerEXT" ); }
	(*func_ptr)( size, type, stride, count, pointer );
}

inline void glDrawArraysEXT(GLenum mode,  GLint first,  GLsizei count)
{
	typedef void (*proc_type)(GLenum mode,  GLint first,  GLsizei count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawArraysEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawArraysEXT" ); }
	(*func_ptr)( mode, first, count );
}

inline void glEdgeFlagPointerEXT(GLsizei stride,  GLsizei count,  const GLboolean *pointer)
{
	typedef void (*proc_type)(GLsizei stride,  GLsizei count,  const GLboolean *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEdgeFlagPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEdgeFlagPointerEXT" ); }
	(*func_ptr)( stride, count, pointer );
}

inline void glGetPointervEXT(GLenum pname,  GLvoid* *params)
{
	typedef void (*proc_type)(GLenum pname,  GLvoid* *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPointervEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPointervEXT" ); }
	(*func_ptr)( pname, params );
}

inline void glIndexPointerEXT(GLenum type,  GLsizei stride,  GLsizei count,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLenum type,  GLsizei stride,  GLsizei count,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIndexPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIndexPointerEXT" ); }
	(*func_ptr)( type, stride, count, pointer );
}

inline void glNormalPointerEXT(GLenum type,  GLsizei stride,  GLsizei count,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLenum type,  GLsizei stride,  GLsizei count,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalPointerEXT" ); }
	(*func_ptr)( type, stride, count, pointer );
}

inline void glTexCoordPointerEXT(GLint size,  GLenum type,  GLsizei stride,  GLsizei count,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  GLsizei stride,  GLsizei count,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordPointerEXT" ); }
	(*func_ptr)( size, type, stride, count, pointer );
}

inline void glVertexPointerEXT(GLint size,  GLenum type,  GLsizei stride,  GLsizei count,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  GLsizei stride,  GLsizei count,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexPointerEXT" ); }
	(*func_ptr)( size, type, stride, count, pointer );
}

inline void glBlendEquationEXT(GLenum mode)
{
	typedef void (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationEXT" ); }
	(*func_ptr)( mode );
}

inline void glSpriteParameterfSGIX(GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSpriteParameterfSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSpriteParameterfSGIX" ); }
	(*func_ptr)( pname, param );
}

inline void glSpriteParameterfvSGIX(GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSpriteParameterfvSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSpriteParameterfvSGIX" ); }
	(*func_ptr)( pname, params );
}

inline void glSpriteParameteriSGIX(GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSpriteParameteriSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSpriteParameteriSGIX" ); }
	(*func_ptr)( pname, param );
}

inline void glSpriteParameterivSGIX(GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSpriteParameterivSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSpriteParameterivSGIX" ); }
	(*func_ptr)( pname, params );
}

inline void glPointParameterfEXT(GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterfEXT" ); }
	(*func_ptr)( pname, param );
}

inline void glPointParameterfvEXT(GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterfvEXT" ); }
	(*func_ptr)( pname, params );
}

inline void glPointParameterfSGIS(GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterfSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterfSGIS" ); }
	(*func_ptr)( pname, param );
}

inline void glPointParameterfvSGIS(GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterfvSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterfvSGIS" ); }
	(*func_ptr)( pname, params );
}

inline GLint glGetInstrumentsSGIX(void)
{
	typedef GLint (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetInstrumentsSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetInstrumentsSGIX" ); }
	return (*func_ptr)(  );
}

inline void glInstrumentsBufferSGIX(GLsizei size,  GLint *buffer)
{
	typedef void (*proc_type)(GLsizei size,  GLint *buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glInstrumentsBufferSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glInstrumentsBufferSGIX" ); }
	(*func_ptr)( size, buffer );
}

inline GLint glPollInstrumentsSGIX(GLint *marker_p)
{
	typedef GLint (*proc_type)(GLint *marker_p);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPollInstrumentsSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPollInstrumentsSGIX" ); }
	return (*func_ptr)( marker_p );
}

inline void glReadInstrumentsSGIX(GLint marker)
{
	typedef void (*proc_type)(GLint marker);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReadInstrumentsSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReadInstrumentsSGIX" ); }
	(*func_ptr)( marker );
}

inline void glStartInstrumentsSGIX(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStartInstrumentsSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStartInstrumentsSGIX" ); }
	(*func_ptr)(  );
}

inline void glStopInstrumentsSGIX(GLint marker)
{
	typedef void (*proc_type)(GLint marker);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStopInstrumentsSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStopInstrumentsSGIX" ); }
	(*func_ptr)( marker );
}

inline void glFrameZoomSGIX(GLint factor)
{
	typedef void (*proc_type)(GLint factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFrameZoomSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFrameZoomSGIX" ); }
	(*func_ptr)( factor );
}

inline void glTagSampleBufferSGIX(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTagSampleBufferSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTagSampleBufferSGIX" ); }
	(*func_ptr)(  );
}

inline void glDeformationMap3dSGIX(GLenum target,  GLdouble u1,  GLdouble u2,  GLint ustride,  GLint uorder,  GLdouble v1,  GLdouble v2,  GLint vstride,  GLint vorder,  GLdouble w1,  GLdouble w2,  GLint wstride,  GLint worder,  const GLdouble *points)
{
	typedef void (*proc_type)(GLenum target,  GLdouble u1,  GLdouble u2,  GLint ustride,  GLint uorder,  GLdouble v1,  GLdouble v2,  GLint vstride,  GLint vorder,  GLdouble w1,  GLdouble w2,  GLint wstride,  GLint worder,  const GLdouble *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeformationMap3dSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeformationMap3dSGIX" ); }
	(*func_ptr)( target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points );
}

inline void glDeformationMap3fSGIX(GLenum target,  GLfloat u1,  GLfloat u2,  GLint ustride,  GLint uorder,  GLfloat v1,  GLfloat v2,  GLint vstride,  GLint vorder,  GLfloat w1,  GLfloat w2,  GLint wstride,  GLint worder,  const GLfloat *points)
{
	typedef void (*proc_type)(GLenum target,  GLfloat u1,  GLfloat u2,  GLint ustride,  GLint uorder,  GLfloat v1,  GLfloat v2,  GLint vstride,  GLint vorder,  GLfloat w1,  GLfloat w2,  GLint wstride,  GLint worder,  const GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeformationMap3fSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeformationMap3fSGIX" ); }
	(*func_ptr)( target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points );
}

inline void glDeformSGIX(GLbitfield mask)
{
	typedef void (*proc_type)(GLbitfield mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeformSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeformSGIX" ); }
	(*func_ptr)( mask );
}

inline void glLoadIdentityDeformationMapSGIX(GLbitfield mask)
{
	typedef void (*proc_type)(GLbitfield mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLoadIdentityDeformationMapSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLoadIdentityDeformationMapSGIX" ); }
	(*func_ptr)( mask );
}

inline void glReferencePlaneSGIX(const GLdouble *equation)
{
	typedef void (*proc_type)(const GLdouble *equation);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReferencePlaneSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReferencePlaneSGIX" ); }
	(*func_ptr)( equation );
}

inline void glFlushRasterSGIX(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFlushRasterSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFlushRasterSGIX" ); }
	(*func_ptr)(  );
}

inline void glFogFuncSGIS(GLsizei n,  const GLfloat *points)
{
	typedef void (*proc_type)(GLsizei n,  const GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogFuncSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogFuncSGIS" ); }
	(*func_ptr)( n, points );
}

inline void glGetFogFuncSGIS(GLfloat *points)
{
	typedef void (*proc_type)(GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFogFuncSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFogFuncSGIS" ); }
	(*func_ptr)( points );
}

inline void glImageTransformParameteriHP(GLenum target,  GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glImageTransformParameteriHP" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glImageTransformParameteriHP" ); }
	(*func_ptr)( target, pname, param );
}

inline void glImageTransformParameterfHP(GLenum target,  GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glImageTransformParameterfHP" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glImageTransformParameterfHP" ); }
	(*func_ptr)( target, pname, param );
}

inline void glImageTransformParameterivHP(GLenum target,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glImageTransformParameterivHP" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glImageTransformParameterivHP" ); }
	(*func_ptr)( target, pname, params );
}

inline void glImageTransformParameterfvHP(GLenum target,  GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glImageTransformParameterfvHP" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glImageTransformParameterfvHP" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetImageTransformParameterivHP(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetImageTransformParameterivHP" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetImageTransformParameterivHP" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetImageTransformParameterfvHP(GLenum target,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetImageTransformParameterfvHP" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetImageTransformParameterfvHP" ); }
	(*func_ptr)( target, pname, params );
}

inline void glColorSubTableEXT(GLenum target,  GLsizei start,  GLsizei count,  GLenum format,  GLenum type,  const GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLsizei start,  GLsizei count,  GLenum format,  GLenum type,  const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorSubTableEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorSubTableEXT" ); }
	(*func_ptr)( target, start, count, format, type, data );
}

inline void glCopyColorSubTableEXT(GLenum target,  GLsizei start,  GLint x,  GLint y,  GLsizei width)
{
	typedef void (*proc_type)(GLenum target,  GLsizei start,  GLint x,  GLint y,  GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyColorSubTableEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyColorSubTableEXT" ); }
	(*func_ptr)( target, start, x, y, width );
}

inline void glHintPGI(GLenum target,  GLint mode)
{
	typedef void (*proc_type)(GLenum target,  GLint mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glHintPGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glHintPGI" ); }
	(*func_ptr)( target, mode );
}

inline void glColorTableEXT(GLenum target,  GLenum internalFormat,  GLsizei width,  GLenum format,  GLenum type,  const GLvoid *table)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalFormat,  GLsizei width,  GLenum format,  GLenum type,  const GLvoid *table);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorTableEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorTableEXT" ); }
	(*func_ptr)( target, internalFormat, width, format, type, table );
}

inline void glGetColorTableEXT(GLenum target,  GLenum format,  GLenum type,  GLvoid *data)
{
	typedef void (*proc_type)(GLenum target,  GLenum format,  GLenum type,  GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTableEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTableEXT" ); }
	(*func_ptr)( target, format, type, data );
}

inline void glGetColorTableParameterivEXT(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTableParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTableParameterivEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetColorTableParameterfvEXT(GLenum target,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTableParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTableParameterfvEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetListParameterfvSGIX(GLuint list,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLuint list,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetListParameterfvSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetListParameterfvSGIX" ); }
	(*func_ptr)( list, pname, params );
}

inline void glGetListParameterivSGIX(GLuint list,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint list,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetListParameterivSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetListParameterivSGIX" ); }
	(*func_ptr)( list, pname, params );
}

inline void glListParameterfSGIX(GLuint list,  GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLuint list,  GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glListParameterfSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glListParameterfSGIX" ); }
	(*func_ptr)( list, pname, param );
}

inline void glListParameterfvSGIX(GLuint list,  GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLuint list,  GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glListParameterfvSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glListParameterfvSGIX" ); }
	(*func_ptr)( list, pname, params );
}

inline void glListParameteriSGIX(GLuint list,  GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLuint list,  GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glListParameteriSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glListParameteriSGIX" ); }
	(*func_ptr)( list, pname, param );
}

inline void glListParameterivSGIX(GLuint list,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLuint list,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glListParameterivSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glListParameterivSGIX" ); }
	(*func_ptr)( list, pname, params );
}

inline void glIndexMaterialEXT(GLenum face,  GLenum mode)
{
	typedef void (*proc_type)(GLenum face,  GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIndexMaterialEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIndexMaterialEXT" ); }
	(*func_ptr)( face, mode );
}

inline void glIndexFuncEXT(GLenum func,  GLclampf ref)
{
	typedef void (*proc_type)(GLenum func,  GLclampf ref);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIndexFuncEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIndexFuncEXT" ); }
	(*func_ptr)( func, ref );
}

inline void glLockArraysEXT(GLint first,  GLsizei count)
{
	typedef void (*proc_type)(GLint first,  GLsizei count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLockArraysEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLockArraysEXT" ); }
	(*func_ptr)( first, count );
}

inline void glUnlockArraysEXT(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUnlockArraysEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUnlockArraysEXT" ); }
	(*func_ptr)(  );
}

inline void glCullParameterdvEXT(GLenum pname,  GLdouble *params)
{
	typedef void (*proc_type)(GLenum pname,  GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCullParameterdvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCullParameterdvEXT" ); }
	(*func_ptr)( pname, params );
}

inline void glCullParameterfvEXT(GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCullParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCullParameterfvEXT" ); }
	(*func_ptr)( pname, params );
}

inline void glFragmentColorMaterialSGIX(GLenum face,  GLenum mode)
{
	typedef void (*proc_type)(GLenum face,  GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentColorMaterialSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentColorMaterialSGIX" ); }
	(*func_ptr)( face, mode );
}

inline void glFragmentLightfSGIX(GLenum light,  GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLenum light,  GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentLightfSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentLightfSGIX" ); }
	(*func_ptr)( light, pname, param );
}

inline void glFragmentLightfvSGIX(GLenum light,  GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum light,  GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentLightfvSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentLightfvSGIX" ); }
	(*func_ptr)( light, pname, params );
}

inline void glFragmentLightiSGIX(GLenum light,  GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum light,  GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentLightiSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentLightiSGIX" ); }
	(*func_ptr)( light, pname, param );
}

inline void glFragmentLightivSGIX(GLenum light,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum light,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentLightivSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentLightivSGIX" ); }
	(*func_ptr)( light, pname, params );
}

inline void glFragmentLightModelfSGIX(GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentLightModelfSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentLightModelfSGIX" ); }
	(*func_ptr)( pname, param );
}

inline void glFragmentLightModelfvSGIX(GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentLightModelfvSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentLightModelfvSGIX" ); }
	(*func_ptr)( pname, params );
}

inline void glFragmentLightModeliSGIX(GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentLightModeliSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentLightModeliSGIX" ); }
	(*func_ptr)( pname, param );
}

inline void glFragmentLightModelivSGIX(GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentLightModelivSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentLightModelivSGIX" ); }
	(*func_ptr)( pname, params );
}

inline void glFragmentMaterialfSGIX(GLenum face,  GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLenum face,  GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentMaterialfSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentMaterialfSGIX" ); }
	(*func_ptr)( face, pname, param );
}

inline void glFragmentMaterialfvSGIX(GLenum face,  GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum face,  GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentMaterialfvSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentMaterialfvSGIX" ); }
	(*func_ptr)( face, pname, params );
}

inline void glFragmentMaterialiSGIX(GLenum face,  GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum face,  GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentMaterialiSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentMaterialiSGIX" ); }
	(*func_ptr)( face, pname, param );
}

inline void glFragmentMaterialivSGIX(GLenum face,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum face,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentMaterialivSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentMaterialivSGIX" ); }
	(*func_ptr)( face, pname, params );
}

inline void glGetFragmentLightfvSGIX(GLenum light,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum light,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFragmentLightfvSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFragmentLightfvSGIX" ); }
	(*func_ptr)( light, pname, params );
}

inline void glGetFragmentLightivSGIX(GLenum light,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum light,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFragmentLightivSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFragmentLightivSGIX" ); }
	(*func_ptr)( light, pname, params );
}

inline void glGetFragmentMaterialfvSGIX(GLenum face,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum face,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFragmentMaterialfvSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFragmentMaterialfvSGIX" ); }
	(*func_ptr)( face, pname, params );
}

inline void glGetFragmentMaterialivSGIX(GLenum face,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum face,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFragmentMaterialivSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFragmentMaterialivSGIX" ); }
	(*func_ptr)( face, pname, params );
}

inline void glLightEnviSGIX(GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLightEnviSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLightEnviSGIX" ); }
	(*func_ptr)( pname, param );
}

inline void glDrawRangeElementsEXT(GLenum mode,  GLuint start,  GLuint end,  GLsizei count,  GLenum type,  const GLvoid *indices)
{
	typedef void (*proc_type)(GLenum mode,  GLuint start,  GLuint end,  GLsizei count,  GLenum type,  const GLvoid *indices);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawRangeElementsEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawRangeElementsEXT" ); }
	(*func_ptr)( mode, start, end, count, type, indices );
}

inline void glApplyTextureEXT(GLenum mode)
{
	typedef void (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glApplyTextureEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glApplyTextureEXT" ); }
	(*func_ptr)( mode );
}

inline void glTextureLightEXT(GLenum pname)
{
	typedef void (*proc_type)(GLenum pname);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureLightEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureLightEXT" ); }
	(*func_ptr)( pname );
}

inline void glTextureMaterialEXT(GLenum face,  GLenum mode)
{
	typedef void (*proc_type)(GLenum face,  GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureMaterialEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureMaterialEXT" ); }
	(*func_ptr)( face, mode );
}

inline void glAsyncMarkerSGIX(GLuint marker)
{
	typedef void (*proc_type)(GLuint marker);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glAsyncMarkerSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glAsyncMarkerSGIX" ); }
	(*func_ptr)( marker );
}

inline GLint glFinishAsyncSGIX(GLuint *markerp)
{
	typedef GLint (*proc_type)(GLuint *markerp);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFinishAsyncSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFinishAsyncSGIX" ); }
	return (*func_ptr)( markerp );
}

inline GLint glPollAsyncSGIX(GLuint *markerp)
{
	typedef GLint (*proc_type)(GLuint *markerp);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPollAsyncSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPollAsyncSGIX" ); }
	return (*func_ptr)( markerp );
}

inline GLuint glGenAsyncMarkersSGIX(GLsizei range)
{
	typedef GLuint (*proc_type)(GLsizei range);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenAsyncMarkersSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenAsyncMarkersSGIX" ); }
	return (*func_ptr)( range );
}

inline void glDeleteAsyncMarkersSGIX(GLuint marker,  GLsizei range)
{
	typedef void (*proc_type)(GLuint marker,  GLsizei range);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteAsyncMarkersSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteAsyncMarkersSGIX" ); }
	(*func_ptr)( marker, range );
}

inline GLboolean glIsAsyncMarkerSGIX(GLuint marker)
{
	typedef GLboolean (*proc_type)(GLuint marker);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsAsyncMarkerSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsAsyncMarkerSGIX" ); }
	return (*func_ptr)( marker );
}

inline void glVertexPointervINTEL(GLint size,  GLenum type,  const GLvoid* *pointer)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  const GLvoid* *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexPointervINTEL" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexPointervINTEL" ); }
	(*func_ptr)( size, type, pointer );
}

inline void glNormalPointervINTEL(GLenum type,  const GLvoid* *pointer)
{
	typedef void (*proc_type)(GLenum type,  const GLvoid* *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalPointervINTEL" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalPointervINTEL" ); }
	(*func_ptr)( type, pointer );
}

inline void glColorPointervINTEL(GLint size,  GLenum type,  const GLvoid* *pointer)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  const GLvoid* *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorPointervINTEL" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorPointervINTEL" ); }
	(*func_ptr)( size, type, pointer );
}

inline void glTexCoordPointervINTEL(GLint size,  GLenum type,  const GLvoid* *pointer)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  const GLvoid* *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordPointervINTEL" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordPointervINTEL" ); }
	(*func_ptr)( size, type, pointer );
}

inline void glPixelTransformParameteriEXT(GLenum target,  GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTransformParameteriEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTransformParameteriEXT" ); }
	(*func_ptr)( target, pname, param );
}

inline void glPixelTransformParameterfEXT(GLenum target,  GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTransformParameterfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTransformParameterfEXT" ); }
	(*func_ptr)( target, pname, param );
}

inline void glPixelTransformParameterivEXT(GLenum target,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTransformParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTransformParameterivEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glPixelTransformParameterfvEXT(GLenum target,  GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTransformParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTransformParameterfvEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glSecondaryColor3bEXT(GLbyte red,  GLbyte green,  GLbyte blue)
{
	typedef void (*proc_type)(GLbyte red,  GLbyte green,  GLbyte blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3bEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3bEXT" ); }
	(*func_ptr)( red, green, blue );
}

inline void glSecondaryColor3bvEXT(const GLbyte *v)
{
	typedef void (*proc_type)(const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3bvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3bvEXT" ); }
	(*func_ptr)( v );
}

inline void glSecondaryColor3dEXT(GLdouble red,  GLdouble green,  GLdouble blue)
{
	typedef void (*proc_type)(GLdouble red,  GLdouble green,  GLdouble blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3dEXT" ); }
	(*func_ptr)( red, green, blue );
}

inline void glSecondaryColor3dvEXT(const GLdouble *v)
{
	typedef void (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3dvEXT" ); }
	(*func_ptr)( v );
}

inline void glSecondaryColor3fEXT(GLfloat red,  GLfloat green,  GLfloat blue)
{
	typedef void (*proc_type)(GLfloat red,  GLfloat green,  GLfloat blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3fEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3fEXT" ); }
	(*func_ptr)( red, green, blue );
}

inline void glSecondaryColor3fvEXT(const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3fvEXT" ); }
	(*func_ptr)( v );
}

inline void glSecondaryColor3iEXT(GLint red,  GLint green,  GLint blue)
{
	typedef void (*proc_type)(GLint red,  GLint green,  GLint blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3iEXT" ); }
	(*func_ptr)( red, green, blue );
}

inline void glSecondaryColor3ivEXT(const GLint *v)
{
	typedef void (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3ivEXT" ); }
	(*func_ptr)( v );
}

inline void glSecondaryColor3sEXT(GLshort red,  GLshort green,  GLshort blue)
{
	typedef void (*proc_type)(GLshort red,  GLshort green,  GLshort blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3sEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3sEXT" ); }
	(*func_ptr)( red, green, blue );
}

inline void glSecondaryColor3svEXT(const GLshort *v)
{
	typedef void (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3svEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3svEXT" ); }
	(*func_ptr)( v );
}

inline void glSecondaryColor3ubEXT(GLubyte red,  GLubyte green,  GLubyte blue)
{
	typedef void (*proc_type)(GLubyte red,  GLubyte green,  GLubyte blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3ubEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3ubEXT" ); }
	(*func_ptr)( red, green, blue );
}

inline void glSecondaryColor3ubvEXT(const GLubyte *v)
{
	typedef void (*proc_type)(const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3ubvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3ubvEXT" ); }
	(*func_ptr)( v );
}

inline void glSecondaryColor3uiEXT(GLuint red,  GLuint green,  GLuint blue)
{
	typedef void (*proc_type)(GLuint red,  GLuint green,  GLuint blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3uiEXT" ); }
	(*func_ptr)( red, green, blue );
}

inline void glSecondaryColor3uivEXT(const GLuint *v)
{
	typedef void (*proc_type)(const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3uivEXT" ); }
	(*func_ptr)( v );
}

inline void glSecondaryColor3usEXT(GLushort red,  GLushort green,  GLushort blue)
{
	typedef void (*proc_type)(GLushort red,  GLushort green,  GLushort blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3usEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3usEXT" ); }
	(*func_ptr)( red, green, blue );
}

inline void glSecondaryColor3usvEXT(const GLushort *v)
{
	typedef void (*proc_type)(const GLushort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3usvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3usvEXT" ); }
	(*func_ptr)( v );
}

inline void glSecondaryColorPointerEXT(GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColorPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColorPointerEXT" ); }
	(*func_ptr)( size, type, stride, pointer );
}

inline void glTextureNormalEXT(GLenum mode)
{
	typedef void (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureNormalEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureNormalEXT" ); }
	(*func_ptr)( mode );
}

inline void glMultiDrawArraysEXT(GLenum mode,  const GLint *first,  const GLsizei *count,  GLsizei primcount)
{
	typedef void (*proc_type)(GLenum mode,  const GLint *first,  const GLsizei *count,  GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawArraysEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawArraysEXT" ); }
	(*func_ptr)( mode, first, count, primcount );
}

inline void glMultiDrawElementsEXT(GLenum mode,  const GLsizei *count,  GLenum type,  const GLvoid* *indices,  GLsizei primcount)
{
	typedef void (*proc_type)(GLenum mode,  const GLsizei *count,  GLenum type,  const GLvoid* *indices,  GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawElementsEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawElementsEXT" ); }
	(*func_ptr)( mode, count, type, indices, primcount );
}

inline void glFogCoordfEXT(GLfloat coord)
{
	typedef void (*proc_type)(GLfloat coord);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordfEXT" ); }
	(*func_ptr)( coord );
}

inline void glFogCoordfvEXT(const GLfloat *coord)
{
	typedef void (*proc_type)(const GLfloat *coord);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordfvEXT" ); }
	(*func_ptr)( coord );
}

inline void glFogCoorddEXT(GLdouble coord)
{
	typedef void (*proc_type)(GLdouble coord);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoorddEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoorddEXT" ); }
	(*func_ptr)( coord );
}

inline void glFogCoorddvEXT(const GLdouble *coord)
{
	typedef void (*proc_type)(const GLdouble *coord);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoorddvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoorddvEXT" ); }
	(*func_ptr)( coord );
}

inline void glFogCoordPointerEXT(GLenum type,  GLsizei stride,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLenum type,  GLsizei stride,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordPointerEXT" ); }
	(*func_ptr)( type, stride, pointer );
}

inline void glTangent3bEXT(GLbyte tx,  GLbyte ty,  GLbyte tz)
{
	typedef void (*proc_type)(GLbyte tx,  GLbyte ty,  GLbyte tz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3bEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3bEXT" ); }
	(*func_ptr)( tx, ty, tz );
}

inline void glTangent3bvEXT(const GLbyte *v)
{
	typedef void (*proc_type)(const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3bvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3bvEXT" ); }
	(*func_ptr)( v );
}

inline void glTangent3dEXT(GLdouble tx,  GLdouble ty,  GLdouble tz)
{
	typedef void (*proc_type)(GLdouble tx,  GLdouble ty,  GLdouble tz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3dEXT" ); }
	(*func_ptr)( tx, ty, tz );
}

inline void glTangent3dvEXT(const GLdouble *v)
{
	typedef void (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3dvEXT" ); }
	(*func_ptr)( v );
}

inline void glTangent3fEXT(GLfloat tx,  GLfloat ty,  GLfloat tz)
{
	typedef void (*proc_type)(GLfloat tx,  GLfloat ty,  GLfloat tz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3fEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3fEXT" ); }
	(*func_ptr)( tx, ty, tz );
}

inline void glTangent3fvEXT(const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3fvEXT" ); }
	(*func_ptr)( v );
}

inline void glTangent3iEXT(GLint tx,  GLint ty,  GLint tz)
{
	typedef void (*proc_type)(GLint tx,  GLint ty,  GLint tz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3iEXT" ); }
	(*func_ptr)( tx, ty, tz );
}

inline void glTangent3ivEXT(const GLint *v)
{
	typedef void (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3ivEXT" ); }
	(*func_ptr)( v );
}

inline void glTangent3sEXT(GLshort tx,  GLshort ty,  GLshort tz)
{
	typedef void (*proc_type)(GLshort tx,  GLshort ty,  GLshort tz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3sEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3sEXT" ); }
	(*func_ptr)( tx, ty, tz );
}

inline void glTangent3svEXT(const GLshort *v)
{
	typedef void (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3svEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3svEXT" ); }
	(*func_ptr)( v );
}

inline void glBinormal3bEXT(GLbyte bx,  GLbyte by,  GLbyte bz)
{
	typedef void (*proc_type)(GLbyte bx,  GLbyte by,  GLbyte bz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3bEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3bEXT" ); }
	(*func_ptr)( bx, by, bz );
}

inline void glBinormal3bvEXT(const GLbyte *v)
{
	typedef void (*proc_type)(const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3bvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3bvEXT" ); }
	(*func_ptr)( v );
}

inline void glBinormal3dEXT(GLdouble bx,  GLdouble by,  GLdouble bz)
{
	typedef void (*proc_type)(GLdouble bx,  GLdouble by,  GLdouble bz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3dEXT" ); }
	(*func_ptr)( bx, by, bz );
}

inline void glBinormal3dvEXT(const GLdouble *v)
{
	typedef void (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3dvEXT" ); }
	(*func_ptr)( v );
}

inline void glBinormal3fEXT(GLfloat bx,  GLfloat by,  GLfloat bz)
{
	typedef void (*proc_type)(GLfloat bx,  GLfloat by,  GLfloat bz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3fEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3fEXT" ); }
	(*func_ptr)( bx, by, bz );
}

inline void glBinormal3fvEXT(const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3fvEXT" ); }
	(*func_ptr)( v );
}

inline void glBinormal3iEXT(GLint bx,  GLint by,  GLint bz)
{
	typedef void (*proc_type)(GLint bx,  GLint by,  GLint bz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3iEXT" ); }
	(*func_ptr)( bx, by, bz );
}

inline void glBinormal3ivEXT(const GLint *v)
{
	typedef void (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3ivEXT" ); }
	(*func_ptr)( v );
}

inline void glBinormal3sEXT(GLshort bx,  GLshort by,  GLshort bz)
{
	typedef void (*proc_type)(GLshort bx,  GLshort by,  GLshort bz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3sEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3sEXT" ); }
	(*func_ptr)( bx, by, bz );
}

inline void glBinormal3svEXT(const GLshort *v)
{
	typedef void (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3svEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3svEXT" ); }
	(*func_ptr)( v );
}

inline void glTangentPointerEXT(GLenum type,  GLsizei stride,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLenum type,  GLsizei stride,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangentPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangentPointerEXT" ); }
	(*func_ptr)( type, stride, pointer );
}

inline void glBinormalPointerEXT(GLenum type,  GLsizei stride,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLenum type,  GLsizei stride,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormalPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormalPointerEXT" ); }
	(*func_ptr)( type, stride, pointer );
}

inline void glFinishTextureSUNX(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFinishTextureSUNX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFinishTextureSUNX" ); }
	(*func_ptr)(  );
}

inline void glGlobalAlphaFactorbSUN(GLbyte factor)
{
	typedef void (*proc_type)(GLbyte factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGlobalAlphaFactorbSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGlobalAlphaFactorbSUN" ); }
	(*func_ptr)( factor );
}

inline void glGlobalAlphaFactorsSUN(GLshort factor)
{
	typedef void (*proc_type)(GLshort factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGlobalAlphaFactorsSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGlobalAlphaFactorsSUN" ); }
	(*func_ptr)( factor );
}

inline void glGlobalAlphaFactoriSUN(GLint factor)
{
	typedef void (*proc_type)(GLint factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGlobalAlphaFactoriSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGlobalAlphaFactoriSUN" ); }
	(*func_ptr)( factor );
}

inline void glGlobalAlphaFactorfSUN(GLfloat factor)
{
	typedef void (*proc_type)(GLfloat factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGlobalAlphaFactorfSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGlobalAlphaFactorfSUN" ); }
	(*func_ptr)( factor );
}

inline void glGlobalAlphaFactordSUN(GLdouble factor)
{
	typedef void (*proc_type)(GLdouble factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGlobalAlphaFactordSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGlobalAlphaFactordSUN" ); }
	(*func_ptr)( factor );
}

inline void glGlobalAlphaFactorubSUN(GLubyte factor)
{
	typedef void (*proc_type)(GLubyte factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGlobalAlphaFactorubSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGlobalAlphaFactorubSUN" ); }
	(*func_ptr)( factor );
}

inline void glGlobalAlphaFactorusSUN(GLushort factor)
{
	typedef void (*proc_type)(GLushort factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGlobalAlphaFactorusSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGlobalAlphaFactorusSUN" ); }
	(*func_ptr)( factor );
}

inline void glGlobalAlphaFactoruiSUN(GLuint factor)
{
	typedef void (*proc_type)(GLuint factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGlobalAlphaFactoruiSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGlobalAlphaFactoruiSUN" ); }
	(*func_ptr)( factor );
}

inline void glReplacementCodeuiSUN(GLuint code)
{
	typedef void (*proc_type)(GLuint code);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiSUN" ); }
	(*func_ptr)( code );
}

inline void glReplacementCodeusSUN(GLushort code)
{
	typedef void (*proc_type)(GLushort code);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeusSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeusSUN" ); }
	(*func_ptr)( code );
}

inline void glReplacementCodeubSUN(GLubyte code)
{
	typedef void (*proc_type)(GLubyte code);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeubSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeubSUN" ); }
	(*func_ptr)( code );
}

inline void glReplacementCodeuivSUN(const GLuint *code)
{
	typedef void (*proc_type)(const GLuint *code);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuivSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuivSUN" ); }
	(*func_ptr)( code );
}

inline void glReplacementCodeusvSUN(const GLushort *code)
{
	typedef void (*proc_type)(const GLushort *code);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeusvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeusvSUN" ); }
	(*func_ptr)( code );
}

inline void glReplacementCodeubvSUN(const GLubyte *code)
{
	typedef void (*proc_type)(const GLubyte *code);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeubvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeubvSUN" ); }
	(*func_ptr)( code );
}

inline void glReplacementCodePointerSUN(GLenum type,  GLsizei stride,  const GLvoid* *pointer)
{
	typedef void (*proc_type)(GLenum type,  GLsizei stride,  const GLvoid* *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodePointerSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodePointerSUN" ); }
	(*func_ptr)( type, stride, pointer );
}

inline void glColor4ubVertex2fSUN(GLubyte r,  GLubyte g,  GLubyte b,  GLubyte a,  GLfloat x,  GLfloat y)
{
	typedef void (*proc_type)(GLubyte r,  GLubyte g,  GLubyte b,  GLubyte a,  GLfloat x,  GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor4ubVertex2fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor4ubVertex2fSUN" ); }
	(*func_ptr)( r, g, b, a, x, y );
}

inline void glColor4ubVertex2fvSUN(const GLubyte *c,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLubyte *c,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor4ubVertex2fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor4ubVertex2fvSUN" ); }
	(*func_ptr)( c, v );
}

inline void glColor4ubVertex3fSUN(GLubyte r,  GLubyte g,  GLubyte b,  GLubyte a,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLubyte r,  GLubyte g,  GLubyte b,  GLubyte a,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor4ubVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor4ubVertex3fSUN" ); }
	(*func_ptr)( r, g, b, a, x, y, z );
}

inline void glColor4ubVertex3fvSUN(const GLubyte *c,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLubyte *c,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor4ubVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor4ubVertex3fvSUN" ); }
	(*func_ptr)( c, v );
}

inline void glColor3fVertex3fSUN(GLfloat r,  GLfloat g,  GLfloat b,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLfloat r,  GLfloat g,  GLfloat b,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor3fVertex3fSUN" ); }
	(*func_ptr)( r, g, b, x, y, z );
}

inline void glColor3fVertex3fvSUN(const GLfloat *c,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *c,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor3fVertex3fvSUN" ); }
	(*func_ptr)( c, v );
}

inline void glNormal3fVertex3fSUN(GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormal3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormal3fVertex3fSUN" ); }
	(*func_ptr)( nx, ny, nz, x, y, z );
}

inline void glNormal3fVertex3fvSUN(const GLfloat *n,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *n,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormal3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormal3fVertex3fvSUN" ); }
	(*func_ptr)( n, v );
}

inline void glColor4fNormal3fVertex3fSUN(GLfloat r,  GLfloat g,  GLfloat b,  GLfloat a,  GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLfloat r,  GLfloat g,  GLfloat b,  GLfloat a,  GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor4fNormal3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor4fNormal3fVertex3fSUN" ); }
	(*func_ptr)( r, g, b, a, nx, ny, nz, x, y, z );
}

inline void glColor4fNormal3fVertex3fvSUN(const GLfloat *c,  const GLfloat *n,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *c,  const GLfloat *n,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor4fNormal3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor4fNormal3fVertex3fvSUN" ); }
	(*func_ptr)( c, n, v );
}

inline void glTexCoord2fVertex3fSUN(GLfloat s,  GLfloat t,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLfloat s,  GLfloat t,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fVertex3fSUN" ); }
	(*func_ptr)( s, t, x, y, z );
}

inline void glTexCoord2fVertex3fvSUN(const GLfloat *tc,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *tc,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fVertex3fvSUN" ); }
	(*func_ptr)( tc, v );
}

inline void glTexCoord4fVertex4fSUN(GLfloat s,  GLfloat t,  GLfloat p,  GLfloat q,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w)
{
	typedef void (*proc_type)(GLfloat s,  GLfloat t,  GLfloat p,  GLfloat q,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord4fVertex4fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord4fVertex4fSUN" ); }
	(*func_ptr)( s, t, p, q, x, y, z, w );
}

inline void glTexCoord4fVertex4fvSUN(const GLfloat *tc,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *tc,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord4fVertex4fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord4fVertex4fvSUN" ); }
	(*func_ptr)( tc, v );
}

inline void glTexCoord2fColor4ubVertex3fSUN(GLfloat s,  GLfloat t,  GLubyte r,  GLubyte g,  GLubyte b,  GLubyte a,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLfloat s,  GLfloat t,  GLubyte r,  GLubyte g,  GLubyte b,  GLubyte a,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fColor4ubVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fColor4ubVertex3fSUN" ); }
	(*func_ptr)( s, t, r, g, b, a, x, y, z );
}

inline void glTexCoord2fColor4ubVertex3fvSUN(const GLfloat *tc,  const GLubyte *c,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *tc,  const GLubyte *c,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fColor4ubVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fColor4ubVertex3fvSUN" ); }
	(*func_ptr)( tc, c, v );
}

inline void glTexCoord2fColor3fVertex3fSUN(GLfloat s,  GLfloat t,  GLfloat r,  GLfloat g,  GLfloat b,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLfloat s,  GLfloat t,  GLfloat r,  GLfloat g,  GLfloat b,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fColor3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fColor3fVertex3fSUN" ); }
	(*func_ptr)( s, t, r, g, b, x, y, z );
}

inline void glTexCoord2fColor3fVertex3fvSUN(const GLfloat *tc,  const GLfloat *c,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *tc,  const GLfloat *c,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fColor3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fColor3fVertex3fvSUN" ); }
	(*func_ptr)( tc, c, v );
}

inline void glTexCoord2fNormal3fVertex3fSUN(GLfloat s,  GLfloat t,  GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLfloat s,  GLfloat t,  GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fNormal3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fNormal3fVertex3fSUN" ); }
	(*func_ptr)( s, t, nx, ny, nz, x, y, z );
}

inline void glTexCoord2fNormal3fVertex3fvSUN(const GLfloat *tc,  const GLfloat *n,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *tc,  const GLfloat *n,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fNormal3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fNormal3fVertex3fvSUN" ); }
	(*func_ptr)( tc, n, v );
}

inline void glTexCoord2fColor4fNormal3fVertex3fSUN(GLfloat s,  GLfloat t,  GLfloat r,  GLfloat g,  GLfloat b,  GLfloat a,  GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLfloat s,  GLfloat t,  GLfloat r,  GLfloat g,  GLfloat b,  GLfloat a,  GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fColor4fNormal3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fColor4fNormal3fVertex3fSUN" ); }
	(*func_ptr)( s, t, r, g, b, a, nx, ny, nz, x, y, z );
}

inline void glTexCoord2fColor4fNormal3fVertex3fvSUN(const GLfloat *tc,  const GLfloat *c,  const GLfloat *n,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *tc,  const GLfloat *c,  const GLfloat *n,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fColor4fNormal3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fColor4fNormal3fVertex3fvSUN" ); }
	(*func_ptr)( tc, c, n, v );
}

inline void glTexCoord4fColor4fNormal3fVertex4fSUN(GLfloat s,  GLfloat t,  GLfloat p,  GLfloat q,  GLfloat r,  GLfloat g,  GLfloat b,  GLfloat a,  GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w)
{
	typedef void (*proc_type)(GLfloat s,  GLfloat t,  GLfloat p,  GLfloat q,  GLfloat r,  GLfloat g,  GLfloat b,  GLfloat a,  GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord4fColor4fNormal3fVertex4fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord4fColor4fNormal3fVertex4fSUN" ); }
	(*func_ptr)( s, t, p, q, r, g, b, a, nx, ny, nz, x, y, z, w );
}

inline void glTexCoord4fColor4fNormal3fVertex4fvSUN(const GLfloat *tc,  const GLfloat *c,  const GLfloat *n,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *tc,  const GLfloat *c,  const GLfloat *n,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord4fColor4fNormal3fVertex4fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord4fColor4fNormal3fVertex4fvSUN" ); }
	(*func_ptr)( tc, c, n, v );
}

inline void glReplacementCodeuiVertex3fSUN(GLuint rc,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLuint rc,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiVertex3fSUN" ); }
	(*func_ptr)( rc, x, y, z );
}

inline void glReplacementCodeuiVertex3fvSUN(const GLuint *rc,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLuint *rc,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiVertex3fvSUN" ); }
	(*func_ptr)( rc, v );
}

inline void glReplacementCodeuiColor4ubVertex3fSUN(GLuint rc,  GLubyte r,  GLubyte g,  GLubyte b,  GLubyte a,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLuint rc,  GLubyte r,  GLubyte g,  GLubyte b,  GLubyte a,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiColor4ubVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiColor4ubVertex3fSUN" ); }
	(*func_ptr)( rc, r, g, b, a, x, y, z );
}

inline void glReplacementCodeuiColor4ubVertex3fvSUN(const GLuint *rc,  const GLubyte *c,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLuint *rc,  const GLubyte *c,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiColor4ubVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiColor4ubVertex3fvSUN" ); }
	(*func_ptr)( rc, c, v );
}

inline void glReplacementCodeuiColor3fVertex3fSUN(GLuint rc,  GLfloat r,  GLfloat g,  GLfloat b,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLuint rc,  GLfloat r,  GLfloat g,  GLfloat b,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiColor3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiColor3fVertex3fSUN" ); }
	(*func_ptr)( rc, r, g, b, x, y, z );
}

inline void glReplacementCodeuiColor3fVertex3fvSUN(const GLuint *rc,  const GLfloat *c,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLuint *rc,  const GLfloat *c,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiColor3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiColor3fVertex3fvSUN" ); }
	(*func_ptr)( rc, c, v );
}

inline void glReplacementCodeuiNormal3fVertex3fSUN(GLuint rc,  GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLuint rc,  GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiNormal3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiNormal3fVertex3fSUN" ); }
	(*func_ptr)( rc, nx, ny, nz, x, y, z );
}

inline void glReplacementCodeuiNormal3fVertex3fvSUN(const GLuint *rc,  const GLfloat *n,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLuint *rc,  const GLfloat *n,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiNormal3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiNormal3fVertex3fvSUN" ); }
	(*func_ptr)( rc, n, v );
}

inline void glReplacementCodeuiColor4fNormal3fVertex3fSUN(GLuint rc,  GLfloat r,  GLfloat g,  GLfloat b,  GLfloat a,  GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLuint rc,  GLfloat r,  GLfloat g,  GLfloat b,  GLfloat a,  GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiColor4fNormal3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiColor4fNormal3fVertex3fSUN" ); }
	(*func_ptr)( rc, r, g, b, a, nx, ny, nz, x, y, z );
}

inline void glReplacementCodeuiColor4fNormal3fVertex3fvSUN(const GLuint *rc,  const GLfloat *c,  const GLfloat *n,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLuint *rc,  const GLfloat *c,  const GLfloat *n,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiColor4fNormal3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiColor4fNormal3fVertex3fvSUN" ); }
	(*func_ptr)( rc, c, n, v );
}

inline void glReplacementCodeuiTexCoord2fVertex3fSUN(GLuint rc,  GLfloat s,  GLfloat t,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLuint rc,  GLfloat s,  GLfloat t,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiTexCoord2fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiTexCoord2fVertex3fSUN" ); }
	(*func_ptr)( rc, s, t, x, y, z );
}

inline void glReplacementCodeuiTexCoord2fVertex3fvSUN(const GLuint *rc,  const GLfloat *tc,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLuint *rc,  const GLfloat *tc,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiTexCoord2fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiTexCoord2fVertex3fvSUN" ); }
	(*func_ptr)( rc, tc, v );
}

inline void glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(GLuint rc,  GLfloat s,  GLfloat t,  GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLuint rc,  GLfloat s,  GLfloat t,  GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN" ); }
	(*func_ptr)( rc, s, t, nx, ny, nz, x, y, z );
}

inline void glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(const GLuint *rc,  const GLfloat *tc,  const GLfloat *n,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLuint *rc,  const GLfloat *tc,  const GLfloat *n,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN" ); }
	(*func_ptr)( rc, tc, n, v );
}

inline void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(GLuint rc,  GLfloat s,  GLfloat t,  GLfloat r,  GLfloat g,  GLfloat b,  GLfloat a,  GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLuint rc,  GLfloat s,  GLfloat t,  GLfloat r,  GLfloat g,  GLfloat b,  GLfloat a,  GLfloat nx,  GLfloat ny,  GLfloat nz,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN" ); }
	(*func_ptr)( rc, s, t, r, g, b, a, nx, ny, nz, x, y, z );
}

inline void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(const GLuint *rc,  const GLfloat *tc,  const GLfloat *c,  const GLfloat *n,  const GLfloat *v)
{
	typedef void (*proc_type)(const GLuint *rc,  const GLfloat *tc,  const GLfloat *c,  const GLfloat *n,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN" ); }
	(*func_ptr)( rc, tc, c, n, v );
}

inline void glBlendFuncSeparateEXT(GLenum sfactorRGB,  GLenum dfactorRGB,  GLenum sfactorAlpha,  GLenum dfactorAlpha)
{
	typedef void (*proc_type)(GLenum sfactorRGB,  GLenum dfactorRGB,  GLenum sfactorAlpha,  GLenum dfactorAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFuncSeparateEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFuncSeparateEXT" ); }
	(*func_ptr)( sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha );
}

inline void glBlendFuncSeparateINGR(GLenum sfactorRGB,  GLenum dfactorRGB,  GLenum sfactorAlpha,  GLenum dfactorAlpha)
{
	typedef void (*proc_type)(GLenum sfactorRGB,  GLenum dfactorRGB,  GLenum sfactorAlpha,  GLenum dfactorAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFuncSeparateINGR" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFuncSeparateINGR" ); }
	(*func_ptr)( sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha );
}

inline void glVertexWeightfEXT(GLfloat weight)
{
	typedef void (*proc_type)(GLfloat weight);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexWeightfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexWeightfEXT" ); }
	(*func_ptr)( weight );
}

inline void glVertexWeightfvEXT(const GLfloat *weight)
{
	typedef void (*proc_type)(const GLfloat *weight);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexWeightfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexWeightfvEXT" ); }
	(*func_ptr)( weight );
}

inline void glVertexWeightPointerEXT(GLsizei size,  GLenum type,  GLsizei stride,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLsizei size,  GLenum type,  GLsizei stride,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexWeightPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexWeightPointerEXT" ); }
	(*func_ptr)( size, type, stride, pointer );
}

inline void glFlushVertexArrayRangeNV(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFlushVertexArrayRangeNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFlushVertexArrayRangeNV" ); }
	(*func_ptr)(  );
}

inline void glVertexArrayRangeNV(GLsizei length,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLsizei length,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexArrayRangeNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexArrayRangeNV" ); }
	(*func_ptr)( length, pointer );
}

inline void glCombinerParameterfvNV(GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCombinerParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCombinerParameterfvNV" ); }
	(*func_ptr)( pname, params );
}

inline void glCombinerParameterfNV(GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCombinerParameterfNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCombinerParameterfNV" ); }
	(*func_ptr)( pname, param );
}

inline void glCombinerParameterivNV(GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCombinerParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCombinerParameterivNV" ); }
	(*func_ptr)( pname, params );
}

inline void glCombinerParameteriNV(GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCombinerParameteriNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCombinerParameteriNV" ); }
	(*func_ptr)( pname, param );
}

inline void glCombinerInputNV(GLenum stage,  GLenum portion,  GLenum variable,  GLenum input,  GLenum mapping,  GLenum componentUsage)
{
	typedef void (*proc_type)(GLenum stage,  GLenum portion,  GLenum variable,  GLenum input,  GLenum mapping,  GLenum componentUsage);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCombinerInputNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCombinerInputNV" ); }
	(*func_ptr)( stage, portion, variable, input, mapping, componentUsage );
}

inline void glCombinerOutputNV(GLenum stage,  GLenum portion,  GLenum abOutput,  GLenum cdOutput,  GLenum sumOutput,  GLenum scale,  GLenum bias,  GLboolean abDotProduct,  GLboolean cdDotProduct,  GLboolean muxSum)
{
	typedef void (*proc_type)(GLenum stage,  GLenum portion,  GLenum abOutput,  GLenum cdOutput,  GLenum sumOutput,  GLenum scale,  GLenum bias,  GLboolean abDotProduct,  GLboolean cdDotProduct,  GLboolean muxSum);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCombinerOutputNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCombinerOutputNV" ); }
	(*func_ptr)( stage, portion, abOutput, cdOutput, sumOutput, scale, bias, abDotProduct, cdDotProduct, muxSum );
}

inline void glFinalCombinerInputNV(GLenum variable,  GLenum input,  GLenum mapping,  GLenum componentUsage)
{
	typedef void (*proc_type)(GLenum variable,  GLenum input,  GLenum mapping,  GLenum componentUsage);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFinalCombinerInputNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFinalCombinerInputNV" ); }
	(*func_ptr)( variable, input, mapping, componentUsage );
}

inline void glGetCombinerInputParameterfvNV(GLenum stage,  GLenum portion,  GLenum variable,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum stage,  GLenum portion,  GLenum variable,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCombinerInputParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCombinerInputParameterfvNV" ); }
	(*func_ptr)( stage, portion, variable, pname, params );
}

inline void glGetCombinerInputParameterivNV(GLenum stage,  GLenum portion,  GLenum variable,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum stage,  GLenum portion,  GLenum variable,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCombinerInputParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCombinerInputParameterivNV" ); }
	(*func_ptr)( stage, portion, variable, pname, params );
}

inline void glGetCombinerOutputParameterfvNV(GLenum stage,  GLenum portion,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum stage,  GLenum portion,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCombinerOutputParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCombinerOutputParameterfvNV" ); }
	(*func_ptr)( stage, portion, pname, params );
}

inline void glGetCombinerOutputParameterivNV(GLenum stage,  GLenum portion,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum stage,  GLenum portion,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCombinerOutputParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCombinerOutputParameterivNV" ); }
	(*func_ptr)( stage, portion, pname, params );
}

inline void glGetFinalCombinerInputParameterfvNV(GLenum variable,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum variable,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFinalCombinerInputParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFinalCombinerInputParameterfvNV" ); }
	(*func_ptr)( variable, pname, params );
}

inline void glGetFinalCombinerInputParameterivNV(GLenum variable,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum variable,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFinalCombinerInputParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFinalCombinerInputParameterivNV" ); }
	(*func_ptr)( variable, pname, params );
}

inline void glResizeBuffersMESA(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glResizeBuffersMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glResizeBuffersMESA" ); }
	(*func_ptr)(  );
}

inline void glWindowPos2dMESA(GLdouble x,  GLdouble y)
{
	typedef void (*proc_type)(GLdouble x,  GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2dMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2dMESA" ); }
	(*func_ptr)( x, y );
}

inline void glWindowPos2dvMESA(const GLdouble *v)
{
	typedef void (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2dvMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2dvMESA" ); }
	(*func_ptr)( v );
}

inline void glWindowPos2fMESA(GLfloat x,  GLfloat y)
{
	typedef void (*proc_type)(GLfloat x,  GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2fMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2fMESA" ); }
	(*func_ptr)( x, y );
}

inline void glWindowPos2fvMESA(const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2fvMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2fvMESA" ); }
	(*func_ptr)( v );
}

inline void glWindowPos2iMESA(GLint x,  GLint y)
{
	typedef void (*proc_type)(GLint x,  GLint y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2iMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2iMESA" ); }
	(*func_ptr)( x, y );
}

inline void glWindowPos2ivMESA(const GLint *v)
{
	typedef void (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2ivMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2ivMESA" ); }
	(*func_ptr)( v );
}

inline void glWindowPos2sMESA(GLshort x,  GLshort y)
{
	typedef void (*proc_type)(GLshort x,  GLshort y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2sMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2sMESA" ); }
	(*func_ptr)( x, y );
}

inline void glWindowPos2svMESA(const GLshort *v)
{
	typedef void (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2svMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2svMESA" ); }
	(*func_ptr)( v );
}

inline void glWindowPos3dMESA(GLdouble x,  GLdouble y,  GLdouble z)
{
	typedef void (*proc_type)(GLdouble x,  GLdouble y,  GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3dMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3dMESA" ); }
	(*func_ptr)( x, y, z );
}

inline void glWindowPos3dvMESA(const GLdouble *v)
{
	typedef void (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3dvMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3dvMESA" ); }
	(*func_ptr)( v );
}

inline void glWindowPos3fMESA(GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3fMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3fMESA" ); }
	(*func_ptr)( x, y, z );
}

inline void glWindowPos3fvMESA(const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3fvMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3fvMESA" ); }
	(*func_ptr)( v );
}

inline void glWindowPos3iMESA(GLint x,  GLint y,  GLint z)
{
	typedef void (*proc_type)(GLint x,  GLint y,  GLint z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3iMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3iMESA" ); }
	(*func_ptr)( x, y, z );
}

inline void glWindowPos3ivMESA(const GLint *v)
{
	typedef void (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3ivMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3ivMESA" ); }
	(*func_ptr)( v );
}

inline void glWindowPos3sMESA(GLshort x,  GLshort y,  GLshort z)
{
	typedef void (*proc_type)(GLshort x,  GLshort y,  GLshort z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3sMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3sMESA" ); }
	(*func_ptr)( x, y, z );
}

inline void glWindowPos3svMESA(const GLshort *v)
{
	typedef void (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3svMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3svMESA" ); }
	(*func_ptr)( v );
}

inline void glWindowPos4dMESA(GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w)
{
	typedef void (*proc_type)(GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos4dMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos4dMESA" ); }
	(*func_ptr)( x, y, z, w );
}

inline void glWindowPos4dvMESA(const GLdouble *v)
{
	typedef void (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos4dvMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos4dvMESA" ); }
	(*func_ptr)( v );
}

inline void glWindowPos4fMESA(GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w)
{
	typedef void (*proc_type)(GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos4fMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos4fMESA" ); }
	(*func_ptr)( x, y, z, w );
}

inline void glWindowPos4fvMESA(const GLfloat *v)
{
	typedef void (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos4fvMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos4fvMESA" ); }
	(*func_ptr)( v );
}

inline void glWindowPos4iMESA(GLint x,  GLint y,  GLint z,  GLint w)
{
	typedef void (*proc_type)(GLint x,  GLint y,  GLint z,  GLint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos4iMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos4iMESA" ); }
	(*func_ptr)( x, y, z, w );
}

inline void glWindowPos4ivMESA(const GLint *v)
{
	typedef void (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos4ivMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos4ivMESA" ); }
	(*func_ptr)( v );
}

inline void glWindowPos4sMESA(GLshort x,  GLshort y,  GLshort z,  GLshort w)
{
	typedef void (*proc_type)(GLshort x,  GLshort y,  GLshort z,  GLshort w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos4sMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos4sMESA" ); }
	(*func_ptr)( x, y, z, w );
}

inline void glWindowPos4svMESA(const GLshort *v)
{
	typedef void (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos4svMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos4svMESA" ); }
	(*func_ptr)( v );
}

inline void glMultiModeDrawArraysIBM(const GLenum *mode,  const GLint *first,  const GLsizei *count,  GLsizei primcount,  GLint modestride)
{
	typedef void (*proc_type)(const GLenum *mode,  const GLint *first,  const GLsizei *count,  GLsizei primcount,  GLint modestride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiModeDrawArraysIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiModeDrawArraysIBM" ); }
	(*func_ptr)( mode, first, count, primcount, modestride );
}

inline void glMultiModeDrawElementsIBM(const GLenum *mode,  const GLsizei *count,  GLenum type,  const GLvoid* const *indices,  GLsizei primcount,  GLint modestride)
{
	typedef void (*proc_type)(const GLenum *mode,  const GLsizei *count,  GLenum type,  const GLvoid* const *indices,  GLsizei primcount,  GLint modestride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiModeDrawElementsIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiModeDrawElementsIBM" ); }
	(*func_ptr)( mode, count, type, indices, primcount, modestride );
}

inline void glColorPointerListIBM(GLint size,  GLenum type,  GLint stride,  const GLvoid* *pointer,  GLint ptrstride)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  GLint stride,  const GLvoid* *pointer,  GLint ptrstride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorPointerListIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorPointerListIBM" ); }
	(*func_ptr)( size, type, stride, pointer, ptrstride );
}

inline void glSecondaryColorPointerListIBM(GLint size,  GLenum type,  GLint stride,  const GLvoid* *pointer,  GLint ptrstride)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  GLint stride,  const GLvoid* *pointer,  GLint ptrstride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColorPointerListIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColorPointerListIBM" ); }
	(*func_ptr)( size, type, stride, pointer, ptrstride );
}

inline void glEdgeFlagPointerListIBM(GLint stride,  const GLboolean* *pointer,  GLint ptrstride)
{
	typedef void (*proc_type)(GLint stride,  const GLboolean* *pointer,  GLint ptrstride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEdgeFlagPointerListIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEdgeFlagPointerListIBM" ); }
	(*func_ptr)( stride, pointer, ptrstride );
}

inline void glFogCoordPointerListIBM(GLenum type,  GLint stride,  const GLvoid* *pointer,  GLint ptrstride)
{
	typedef void (*proc_type)(GLenum type,  GLint stride,  const GLvoid* *pointer,  GLint ptrstride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordPointerListIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordPointerListIBM" ); }
	(*func_ptr)( type, stride, pointer, ptrstride );
}

inline void glIndexPointerListIBM(GLenum type,  GLint stride,  const GLvoid* *pointer,  GLint ptrstride)
{
	typedef void (*proc_type)(GLenum type,  GLint stride,  const GLvoid* *pointer,  GLint ptrstride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIndexPointerListIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIndexPointerListIBM" ); }
	(*func_ptr)( type, stride, pointer, ptrstride );
}

inline void glNormalPointerListIBM(GLenum type,  GLint stride,  const GLvoid* *pointer,  GLint ptrstride)
{
	typedef void (*proc_type)(GLenum type,  GLint stride,  const GLvoid* *pointer,  GLint ptrstride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalPointerListIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalPointerListIBM" ); }
	(*func_ptr)( type, stride, pointer, ptrstride );
}

inline void glTexCoordPointerListIBM(GLint size,  GLenum type,  GLint stride,  const GLvoid* *pointer,  GLint ptrstride)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  GLint stride,  const GLvoid* *pointer,  GLint ptrstride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordPointerListIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordPointerListIBM" ); }
	(*func_ptr)( size, type, stride, pointer, ptrstride );
}

inline void glVertexPointerListIBM(GLint size,  GLenum type,  GLint stride,  const GLvoid* *pointer,  GLint ptrstride)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  GLint stride,  const GLvoid* *pointer,  GLint ptrstride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexPointerListIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexPointerListIBM" ); }
	(*func_ptr)( size, type, stride, pointer, ptrstride );
}

inline void glTbufferMask3DFX(GLuint mask)
{
	typedef void (*proc_type)(GLuint mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTbufferMask3DFX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTbufferMask3DFX" ); }
	(*func_ptr)( mask );
}

inline void glSampleMaskEXT(GLclampf value,  GLboolean invert)
{
	typedef void (*proc_type)(GLclampf value,  GLboolean invert);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSampleMaskEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSampleMaskEXT" ); }
	(*func_ptr)( value, invert );
}

inline void glSamplePatternEXT(GLenum pattern)
{
	typedef void (*proc_type)(GLenum pattern);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSamplePatternEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSamplePatternEXT" ); }
	(*func_ptr)( pattern );
}

inline void glTextureColorMaskSGIS(GLboolean red,  GLboolean green,  GLboolean blue,  GLboolean alpha)
{
	typedef void (*proc_type)(GLboolean red,  GLboolean green,  GLboolean blue,  GLboolean alpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureColorMaskSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureColorMaskSGIS" ); }
	(*func_ptr)( red, green, blue, alpha );
}

inline void glIglooInterfaceSGIX(GLenum pname,  const GLvoid *params)
{
	typedef void (*proc_type)(GLenum pname,  const GLvoid *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIglooInterfaceSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIglooInterfaceSGIX" ); }
	(*func_ptr)( pname, params );
}

inline void glDeleteFencesNV(GLsizei n,  const GLuint *fences)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *fences);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteFencesNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteFencesNV" ); }
	(*func_ptr)( n, fences );
}

inline void glGenFencesNV(GLsizei n,  GLuint *fences)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *fences);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenFencesNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenFencesNV" ); }
	(*func_ptr)( n, fences );
}

inline GLboolean glIsFenceNV(GLuint fence)
{
	typedef GLboolean (*proc_type)(GLuint fence);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsFenceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsFenceNV" ); }
	return (*func_ptr)( fence );
}

inline GLboolean glTestFenceNV(GLuint fence)
{
	typedef GLboolean (*proc_type)(GLuint fence);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTestFenceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTestFenceNV" ); }
	return (*func_ptr)( fence );
}

inline void glGetFenceivNV(GLuint fence,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint fence,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFenceivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFenceivNV" ); }
	(*func_ptr)( fence, pname, params );
}

inline void glFinishFenceNV(GLuint fence)
{
	typedef void (*proc_type)(GLuint fence);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFinishFenceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFinishFenceNV" ); }
	(*func_ptr)( fence );
}

inline void glSetFenceNV(GLuint fence,  GLenum condition)
{
	typedef void (*proc_type)(GLuint fence,  GLenum condition);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSetFenceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSetFenceNV" ); }
	(*func_ptr)( fence, condition );
}

inline void glMapControlPointsNV(GLenum target,  GLuint index,  GLenum type,  GLsizei ustride,  GLsizei vstride,  GLint uorder,  GLint vorder,  GLboolean packed,  const GLvoid *points)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLenum type,  GLsizei ustride,  GLsizei vstride,  GLint uorder,  GLint vorder,  GLboolean packed,  const GLvoid *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapControlPointsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapControlPointsNV" ); }
	(*func_ptr)( target, index, type, ustride, vstride, uorder, vorder, packed, points );
}

inline void glMapParameterivNV(GLenum target,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapParameterivNV" ); }
	(*func_ptr)( target, pname, params );
}

inline void glMapParameterfvNV(GLenum target,  GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapParameterfvNV" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetMapControlPointsNV(GLenum target,  GLuint index,  GLenum type,  GLsizei ustride,  GLsizei vstride,  GLboolean packed,  GLvoid *points)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLenum type,  GLsizei ustride,  GLsizei vstride,  GLboolean packed,  GLvoid *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMapControlPointsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMapControlPointsNV" ); }
	(*func_ptr)( target, index, type, ustride, vstride, packed, points );
}

inline void glGetMapParameterivNV(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMapParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMapParameterivNV" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetMapParameterfvNV(GLenum target,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMapParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMapParameterfvNV" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetMapAttribParameterivNV(GLenum target,  GLuint index,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMapAttribParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMapAttribParameterivNV" ); }
	(*func_ptr)( target, index, pname, params );
}

inline void glGetMapAttribParameterfvNV(GLenum target,  GLuint index,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMapAttribParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMapAttribParameterfvNV" ); }
	(*func_ptr)( target, index, pname, params );
}

inline void glEvalMapsNV(GLenum target,  GLenum mode)
{
	typedef void (*proc_type)(GLenum target,  GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEvalMapsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEvalMapsNV" ); }
	(*func_ptr)( target, mode );
}

inline void glCombinerStageParameterfvNV(GLenum stage,  GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum stage,  GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCombinerStageParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCombinerStageParameterfvNV" ); }
	(*func_ptr)( stage, pname, params );
}

inline void glGetCombinerStageParameterfvNV(GLenum stage,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum stage,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCombinerStageParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCombinerStageParameterfvNV" ); }
	(*func_ptr)( stage, pname, params );
}

inline GLboolean glAreProgramsResidentNV(GLsizei n,  const GLuint *programs,  GLboolean *residences)
{
	typedef GLboolean (*proc_type)(GLsizei n,  const GLuint *programs,  GLboolean *residences);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glAreProgramsResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glAreProgramsResidentNV" ); }
	return (*func_ptr)( n, programs, residences );
}

inline void glBindProgramNV(GLenum target,  GLuint id)
{
	typedef void (*proc_type)(GLenum target,  GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindProgramNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindProgramNV" ); }
	(*func_ptr)( target, id );
}

inline void glDeleteProgramsNV(GLsizei n,  const GLuint *programs)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *programs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteProgramsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteProgramsNV" ); }
	(*func_ptr)( n, programs );
}

inline void glExecuteProgramNV(GLenum target,  GLuint id,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint id,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glExecuteProgramNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glExecuteProgramNV" ); }
	(*func_ptr)( target, id, params );
}

inline void glGenProgramsNV(GLsizei n,  GLuint *programs)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *programs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenProgramsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenProgramsNV" ); }
	(*func_ptr)( n, programs );
}

inline void glGetProgramParameterdvNV(GLenum target,  GLuint index,  GLenum pname,  GLdouble *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLenum pname,  GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramParameterdvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramParameterdvNV" ); }
	(*func_ptr)( target, index, pname, params );
}

inline void glGetProgramParameterfvNV(GLenum target,  GLuint index,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramParameterfvNV" ); }
	(*func_ptr)( target, index, pname, params );
}

inline void glGetProgramivNV(GLuint id,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint id,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramivNV" ); }
	(*func_ptr)( id, pname, params );
}

inline void glGetProgramStringNV(GLuint id,  GLenum pname,  GLubyte *program)
{
	typedef void (*proc_type)(GLuint id,  GLenum pname,  GLubyte *program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramStringNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramStringNV" ); }
	(*func_ptr)( id, pname, program );
}

inline void glGetTrackMatrixivNV(GLenum target,  GLuint address,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint address,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTrackMatrixivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTrackMatrixivNV" ); }
	(*func_ptr)( target, address, pname, params );
}

inline void glGetVertexAttribdvNV(GLuint index,  GLenum pname,  GLdouble *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribdvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribdvNV" ); }
	(*func_ptr)( index, pname, params );
}

inline void glGetVertexAttribfvNV(GLuint index,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribfvNV" ); }
	(*func_ptr)( index, pname, params );
}

inline void glGetVertexAttribivNV(GLuint index,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribivNV" ); }
	(*func_ptr)( index, pname, params );
}

inline void glGetVertexAttribPointervNV(GLuint index,  GLenum pname,  GLvoid* *pointer)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLvoid* *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribPointervNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribPointervNV" ); }
	(*func_ptr)( index, pname, pointer );
}

inline GLboolean glIsProgramNV(GLuint id)
{
	typedef GLboolean (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsProgramNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsProgramNV" ); }
	return (*func_ptr)( id );
}

inline void glLoadProgramNV(GLenum target,  GLuint id,  GLsizei len,  const GLubyte *program)
{
	typedef void (*proc_type)(GLenum target,  GLuint id,  GLsizei len,  const GLubyte *program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLoadProgramNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLoadProgramNV" ); }
	(*func_ptr)( target, id, len, program );
}

inline void glProgramParameter4dNV(GLenum target,  GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameter4dNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameter4dNV" ); }
	(*func_ptr)( target, index, x, y, z, w );
}

inline void glProgramParameter4dvNV(GLenum target,  GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameter4dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameter4dvNV" ); }
	(*func_ptr)( target, index, v );
}

inline void glProgramParameter4fNV(GLenum target,  GLuint index,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameter4fNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameter4fNV" ); }
	(*func_ptr)( target, index, x, y, z, w );
}

inline void glProgramParameter4fvNV(GLenum target,  GLuint index,  const GLfloat *v)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameter4fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameter4fvNV" ); }
	(*func_ptr)( target, index, v );
}

inline void glProgramParameters4dvNV(GLenum target,  GLuint index,  GLsizei count,  const GLdouble *v)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLsizei count,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameters4dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameters4dvNV" ); }
	(*func_ptr)( target, index, count, v );
}

inline void glProgramParameters4fvNV(GLenum target,  GLuint index,  GLsizei count,  const GLfloat *v)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLsizei count,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameters4fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameters4fvNV" ); }
	(*func_ptr)( target, index, count, v );
}

inline void glRequestResidentProgramsNV(GLsizei n,  const GLuint *programs)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *programs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glRequestResidentProgramsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glRequestResidentProgramsNV" ); }
	(*func_ptr)( n, programs );
}

inline void glTrackMatrixNV(GLenum target,  GLuint address,  GLenum matrix,  GLenum transform)
{
	typedef void (*proc_type)(GLenum target,  GLuint address,  GLenum matrix,  GLenum transform);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTrackMatrixNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTrackMatrixNV" ); }
	(*func_ptr)( target, address, matrix, transform );
}

inline void glVertexAttribPointerNV(GLuint index,  GLint fsize,  GLenum type,  GLsizei stride,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLuint index,  GLint fsize,  GLenum type,  GLsizei stride,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribPointerNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribPointerNV" ); }
	(*func_ptr)( index, fsize, type, stride, pointer );
}

inline void glVertexAttrib1dNV(GLuint index,  GLdouble x)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1dNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1dNV" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttrib1dvNV(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1dvNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib1fNV(GLuint index,  GLfloat x)
{
	typedef void (*proc_type)(GLuint index,  GLfloat x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1fNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1fNV" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttrib1fvNV(GLuint index,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint index,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1fvNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib1sNV(GLuint index,  GLshort x)
{
	typedef void (*proc_type)(GLuint index,  GLshort x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1sNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1sNV" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttrib1svNV(GLuint index,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1svNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1svNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib2dNV(GLuint index,  GLdouble x,  GLdouble y)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x,  GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2dNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2dNV" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttrib2dvNV(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2dvNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib2fNV(GLuint index,  GLfloat x,  GLfloat y)
{
	typedef void (*proc_type)(GLuint index,  GLfloat x,  GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2fNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2fNV" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttrib2fvNV(GLuint index,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint index,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2fvNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib2sNV(GLuint index,  GLshort x,  GLshort y)
{
	typedef void (*proc_type)(GLuint index,  GLshort x,  GLshort y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2sNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2sNV" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttrib2svNV(GLuint index,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2svNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2svNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib3dNV(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3dNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3dNV" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttrib3dvNV(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3dvNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib3fNV(GLuint index,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLuint index,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3fNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3fNV" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttrib3fvNV(GLuint index,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint index,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3fvNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib3sNV(GLuint index,  GLshort x,  GLshort y,  GLshort z)
{
	typedef void (*proc_type)(GLuint index,  GLshort x,  GLshort y,  GLshort z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3sNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3sNV" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttrib3svNV(GLuint index,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3svNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3svNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4dNV(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4dNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4dNV" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttrib4dvNV(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4dvNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4fNV(GLuint index,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w)
{
	typedef void (*proc_type)(GLuint index,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4fNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4fNV" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttrib4fvNV(GLuint index,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint index,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4fvNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4sNV(GLuint index,  GLshort x,  GLshort y,  GLshort z,  GLshort w)
{
	typedef void (*proc_type)(GLuint index,  GLshort x,  GLshort y,  GLshort z,  GLshort w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4sNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4sNV" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttrib4svNV(GLuint index,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4svNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4svNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4ubNV(GLuint index,  GLubyte x,  GLubyte y,  GLubyte z,  GLubyte w)
{
	typedef void (*proc_type)(GLuint index,  GLubyte x,  GLubyte y,  GLubyte z,  GLubyte w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4ubNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4ubNV" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttrib4ubvNV(GLuint index,  const GLubyte *v)
{
	typedef void (*proc_type)(GLuint index,  const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4ubvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4ubvNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribs1dvNV(GLuint index,  GLsizei count,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  GLsizei count,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs1dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs1dvNV" ); }
	(*func_ptr)( index, count, v );
}

inline void glVertexAttribs1fvNV(GLuint index,  GLsizei count,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint index,  GLsizei count,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs1fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs1fvNV" ); }
	(*func_ptr)( index, count, v );
}

inline void glVertexAttribs1svNV(GLuint index,  GLsizei count,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  GLsizei count,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs1svNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs1svNV" ); }
	(*func_ptr)( index, count, v );
}

inline void glVertexAttribs2dvNV(GLuint index,  GLsizei count,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  GLsizei count,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs2dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs2dvNV" ); }
	(*func_ptr)( index, count, v );
}

inline void glVertexAttribs2fvNV(GLuint index,  GLsizei count,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint index,  GLsizei count,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs2fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs2fvNV" ); }
	(*func_ptr)( index, count, v );
}

inline void glVertexAttribs2svNV(GLuint index,  GLsizei count,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  GLsizei count,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs2svNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs2svNV" ); }
	(*func_ptr)( index, count, v );
}

inline void glVertexAttribs3dvNV(GLuint index,  GLsizei count,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  GLsizei count,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs3dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs3dvNV" ); }
	(*func_ptr)( index, count, v );
}

inline void glVertexAttribs3fvNV(GLuint index,  GLsizei count,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint index,  GLsizei count,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs3fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs3fvNV" ); }
	(*func_ptr)( index, count, v );
}

inline void glVertexAttribs3svNV(GLuint index,  GLsizei count,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  GLsizei count,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs3svNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs3svNV" ); }
	(*func_ptr)( index, count, v );
}

inline void glVertexAttribs4dvNV(GLuint index,  GLsizei count,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  GLsizei count,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs4dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs4dvNV" ); }
	(*func_ptr)( index, count, v );
}

inline void glVertexAttribs4fvNV(GLuint index,  GLsizei count,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint index,  GLsizei count,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs4fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs4fvNV" ); }
	(*func_ptr)( index, count, v );
}

inline void glVertexAttribs4svNV(GLuint index,  GLsizei count,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  GLsizei count,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs4svNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs4svNV" ); }
	(*func_ptr)( index, count, v );
}

inline void glVertexAttribs4ubvNV(GLuint index,  GLsizei count,  const GLubyte *v)
{
	typedef void (*proc_type)(GLuint index,  GLsizei count,  const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs4ubvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs4ubvNV" ); }
	(*func_ptr)( index, count, v );
}

inline void glTexBumpParameterivATI(GLenum pname,  const GLint *param)
{
	typedef void (*proc_type)(GLenum pname,  const GLint *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexBumpParameterivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexBumpParameterivATI" ); }
	(*func_ptr)( pname, param );
}

inline void glTexBumpParameterfvATI(GLenum pname,  const GLfloat *param)
{
	typedef void (*proc_type)(GLenum pname,  const GLfloat *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexBumpParameterfvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexBumpParameterfvATI" ); }
	(*func_ptr)( pname, param );
}

inline void glGetTexBumpParameterivATI(GLenum pname,  GLint *param)
{
	typedef void (*proc_type)(GLenum pname,  GLint *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTexBumpParameterivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTexBumpParameterivATI" ); }
	(*func_ptr)( pname, param );
}

inline void glGetTexBumpParameterfvATI(GLenum pname,  GLfloat *param)
{
	typedef void (*proc_type)(GLenum pname,  GLfloat *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTexBumpParameterfvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTexBumpParameterfvATI" ); }
	(*func_ptr)( pname, param );
}

inline GLuint glGenFragmentShadersATI(GLuint range)
{
	typedef GLuint (*proc_type)(GLuint range);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenFragmentShadersATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenFragmentShadersATI" ); }
	return (*func_ptr)( range );
}

inline void glBindFragmentShaderATI(GLuint id)
{
	typedef void (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindFragmentShaderATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindFragmentShaderATI" ); }
	(*func_ptr)( id );
}

inline void glDeleteFragmentShaderATI(GLuint id)
{
	typedef void (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteFragmentShaderATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteFragmentShaderATI" ); }
	(*func_ptr)( id );
}

inline void glBeginFragmentShaderATI(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginFragmentShaderATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginFragmentShaderATI" ); }
	(*func_ptr)(  );
}

inline void glEndFragmentShaderATI(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndFragmentShaderATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndFragmentShaderATI" ); }
	(*func_ptr)(  );
}

inline void glPassTexCoordATI(GLuint dst,  GLuint coord,  GLenum swizzle)
{
	typedef void (*proc_type)(GLuint dst,  GLuint coord,  GLenum swizzle);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPassTexCoordATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPassTexCoordATI" ); }
	(*func_ptr)( dst, coord, swizzle );
}

inline void glSampleMapATI(GLuint dst,  GLuint interp,  GLenum swizzle)
{
	typedef void (*proc_type)(GLuint dst,  GLuint interp,  GLenum swizzle);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSampleMapATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSampleMapATI" ); }
	(*func_ptr)( dst, interp, swizzle );
}

inline void glColorFragmentOp1ATI(GLenum op,  GLuint dst,  GLuint dstMask,  GLuint dstMod,  GLuint arg1,  GLuint arg1Rep,  GLuint arg1Mod)
{
	typedef void (*proc_type)(GLenum op,  GLuint dst,  GLuint dstMask,  GLuint dstMod,  GLuint arg1,  GLuint arg1Rep,  GLuint arg1Mod);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorFragmentOp1ATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorFragmentOp1ATI" ); }
	(*func_ptr)( op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod );
}

inline void glColorFragmentOp2ATI(GLenum op,  GLuint dst,  GLuint dstMask,  GLuint dstMod,  GLuint arg1,  GLuint arg1Rep,  GLuint arg1Mod,  GLuint arg2,  GLuint arg2Rep,  GLuint arg2Mod)
{
	typedef void (*proc_type)(GLenum op,  GLuint dst,  GLuint dstMask,  GLuint dstMod,  GLuint arg1,  GLuint arg1Rep,  GLuint arg1Mod,  GLuint arg2,  GLuint arg2Rep,  GLuint arg2Mod);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorFragmentOp2ATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorFragmentOp2ATI" ); }
	(*func_ptr)( op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod );
}

inline void glColorFragmentOp3ATI(GLenum op,  GLuint dst,  GLuint dstMask,  GLuint dstMod,  GLuint arg1,  GLuint arg1Rep,  GLuint arg1Mod,  GLuint arg2,  GLuint arg2Rep,  GLuint arg2Mod,  GLuint arg3,  GLuint arg3Rep,  GLuint arg3Mod)
{
	typedef void (*proc_type)(GLenum op,  GLuint dst,  GLuint dstMask,  GLuint dstMod,  GLuint arg1,  GLuint arg1Rep,  GLuint arg1Mod,  GLuint arg2,  GLuint arg2Rep,  GLuint arg2Mod,  GLuint arg3,  GLuint arg3Rep,  GLuint arg3Mod);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorFragmentOp3ATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorFragmentOp3ATI" ); }
	(*func_ptr)( op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod );
}

inline void glAlphaFragmentOp1ATI(GLenum op,  GLuint dst,  GLuint dstMod,  GLuint arg1,  GLuint arg1Rep,  GLuint arg1Mod)
{
	typedef void (*proc_type)(GLenum op,  GLuint dst,  GLuint dstMod,  GLuint arg1,  GLuint arg1Rep,  GLuint arg1Mod);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glAlphaFragmentOp1ATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glAlphaFragmentOp1ATI" ); }
	(*func_ptr)( op, dst, dstMod, arg1, arg1Rep, arg1Mod );
}

inline void glAlphaFragmentOp2ATI(GLenum op,  GLuint dst,  GLuint dstMod,  GLuint arg1,  GLuint arg1Rep,  GLuint arg1Mod,  GLuint arg2,  GLuint arg2Rep,  GLuint arg2Mod)
{
	typedef void (*proc_type)(GLenum op,  GLuint dst,  GLuint dstMod,  GLuint arg1,  GLuint arg1Rep,  GLuint arg1Mod,  GLuint arg2,  GLuint arg2Rep,  GLuint arg2Mod);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glAlphaFragmentOp2ATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glAlphaFragmentOp2ATI" ); }
	(*func_ptr)( op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod );
}

inline void glAlphaFragmentOp3ATI(GLenum op,  GLuint dst,  GLuint dstMod,  GLuint arg1,  GLuint arg1Rep,  GLuint arg1Mod,  GLuint arg2,  GLuint arg2Rep,  GLuint arg2Mod,  GLuint arg3,  GLuint arg3Rep,  GLuint arg3Mod)
{
	typedef void (*proc_type)(GLenum op,  GLuint dst,  GLuint dstMod,  GLuint arg1,  GLuint arg1Rep,  GLuint arg1Mod,  GLuint arg2,  GLuint arg2Rep,  GLuint arg2Mod,  GLuint arg3,  GLuint arg3Rep,  GLuint arg3Mod);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glAlphaFragmentOp3ATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glAlphaFragmentOp3ATI" ); }
	(*func_ptr)( op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod );
}

inline void glSetFragmentShaderConstantATI(GLuint dst,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint dst,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSetFragmentShaderConstantATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSetFragmentShaderConstantATI" ); }
	(*func_ptr)( dst, value );
}

inline void glPNTrianglesiATI(GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPNTrianglesiATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPNTrianglesiATI" ); }
	(*func_ptr)( pname, param );
}

inline void glPNTrianglesfATI(GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPNTrianglesfATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPNTrianglesfATI" ); }
	(*func_ptr)( pname, param );
}

inline GLuint glNewObjectBufferATI(GLsizei size,  const GLvoid *pointer,  GLenum usage)
{
	typedef GLuint (*proc_type)(GLsizei size,  const GLvoid *pointer,  GLenum usage);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNewObjectBufferATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNewObjectBufferATI" ); }
	return (*func_ptr)( size, pointer, usage );
}

inline GLboolean glIsObjectBufferATI(GLuint buffer)
{
	typedef GLboolean (*proc_type)(GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsObjectBufferATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsObjectBufferATI" ); }
	return (*func_ptr)( buffer );
}

inline void glUpdateObjectBufferATI(GLuint buffer,  GLuint offset,  GLsizei size,  const GLvoid *pointer,  GLenum preserve)
{
	typedef void (*proc_type)(GLuint buffer,  GLuint offset,  GLsizei size,  const GLvoid *pointer,  GLenum preserve);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUpdateObjectBufferATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUpdateObjectBufferATI" ); }
	(*func_ptr)( buffer, offset, size, pointer, preserve );
}

inline void glGetObjectBufferfvATI(GLuint buffer,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLuint buffer,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetObjectBufferfvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetObjectBufferfvATI" ); }
	(*func_ptr)( buffer, pname, params );
}

inline void glGetObjectBufferivATI(GLuint buffer,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint buffer,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetObjectBufferivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetObjectBufferivATI" ); }
	(*func_ptr)( buffer, pname, params );
}

inline void glFreeObjectBufferATI(GLuint buffer)
{
	typedef void (*proc_type)(GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFreeObjectBufferATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFreeObjectBufferATI" ); }
	(*func_ptr)( buffer );
}

inline void glArrayObjectATI(GLenum array,  GLint size,  GLenum type,  GLsizei stride,  GLuint buffer,  GLuint offset)
{
	typedef void (*proc_type)(GLenum array,  GLint size,  GLenum type,  GLsizei stride,  GLuint buffer,  GLuint offset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glArrayObjectATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glArrayObjectATI" ); }
	(*func_ptr)( array, size, type, stride, buffer, offset );
}

inline void glGetArrayObjectfvATI(GLenum array,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum array,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetArrayObjectfvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetArrayObjectfvATI" ); }
	(*func_ptr)( array, pname, params );
}

inline void glGetArrayObjectivATI(GLenum array,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum array,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetArrayObjectivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetArrayObjectivATI" ); }
	(*func_ptr)( array, pname, params );
}

inline void glVariantArrayObjectATI(GLuint id,  GLenum type,  GLsizei stride,  GLuint buffer,  GLuint offset)
{
	typedef void (*proc_type)(GLuint id,  GLenum type,  GLsizei stride,  GLuint buffer,  GLuint offset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantArrayObjectATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantArrayObjectATI" ); }
	(*func_ptr)( id, type, stride, buffer, offset );
}

inline void glGetVariantArrayObjectfvATI(GLuint id,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLuint id,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVariantArrayObjectfvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVariantArrayObjectfvATI" ); }
	(*func_ptr)( id, pname, params );
}

inline void glGetVariantArrayObjectivATI(GLuint id,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint id,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVariantArrayObjectivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVariantArrayObjectivATI" ); }
	(*func_ptr)( id, pname, params );
}

inline void glBeginVertexShaderEXT(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginVertexShaderEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginVertexShaderEXT" ); }
	(*func_ptr)(  );
}

inline void glEndVertexShaderEXT(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndVertexShaderEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndVertexShaderEXT" ); }
	(*func_ptr)(  );
}

inline void glBindVertexShaderEXT(GLuint id)
{
	typedef void (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindVertexShaderEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindVertexShaderEXT" ); }
	(*func_ptr)( id );
}

inline GLuint glGenVertexShadersEXT(GLuint range)
{
	typedef GLuint (*proc_type)(GLuint range);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenVertexShadersEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenVertexShadersEXT" ); }
	return (*func_ptr)( range );
}

inline void glDeleteVertexShaderEXT(GLuint id)
{
	typedef void (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteVertexShaderEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteVertexShaderEXT" ); }
	(*func_ptr)( id );
}

inline void glShaderOp1EXT(GLenum op,  GLuint res,  GLuint arg1)
{
	typedef void (*proc_type)(GLenum op,  GLuint res,  GLuint arg1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glShaderOp1EXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glShaderOp1EXT" ); }
	(*func_ptr)( op, res, arg1 );
}

inline void glShaderOp2EXT(GLenum op,  GLuint res,  GLuint arg1,  GLuint arg2)
{
	typedef void (*proc_type)(GLenum op,  GLuint res,  GLuint arg1,  GLuint arg2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glShaderOp2EXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glShaderOp2EXT" ); }
	(*func_ptr)( op, res, arg1, arg2 );
}

inline void glShaderOp3EXT(GLenum op,  GLuint res,  GLuint arg1,  GLuint arg2,  GLuint arg3)
{
	typedef void (*proc_type)(GLenum op,  GLuint res,  GLuint arg1,  GLuint arg2,  GLuint arg3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glShaderOp3EXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glShaderOp3EXT" ); }
	(*func_ptr)( op, res, arg1, arg2, arg3 );
}

inline void glSwizzleEXT(GLuint res,  GLuint in,  GLenum outX,  GLenum outY,  GLenum outZ,  GLenum outW)
{
	typedef void (*proc_type)(GLuint res,  GLuint in,  GLenum outX,  GLenum outY,  GLenum outZ,  GLenum outW);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSwizzleEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSwizzleEXT" ); }
	(*func_ptr)( res, in, outX, outY, outZ, outW );
}

inline void glWriteMaskEXT(GLuint res,  GLuint in,  GLenum outX,  GLenum outY,  GLenum outZ,  GLenum outW)
{
	typedef void (*proc_type)(GLuint res,  GLuint in,  GLenum outX,  GLenum outY,  GLenum outZ,  GLenum outW);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWriteMaskEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWriteMaskEXT" ); }
	(*func_ptr)( res, in, outX, outY, outZ, outW );
}

inline void glInsertComponentEXT(GLuint res,  GLuint src,  GLuint num)
{
	typedef void (*proc_type)(GLuint res,  GLuint src,  GLuint num);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glInsertComponentEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glInsertComponentEXT" ); }
	(*func_ptr)( res, src, num );
}

inline void glExtractComponentEXT(GLuint res,  GLuint src,  GLuint num)
{
	typedef void (*proc_type)(GLuint res,  GLuint src,  GLuint num);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glExtractComponentEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glExtractComponentEXT" ); }
	(*func_ptr)( res, src, num );
}

inline GLuint glGenSymbolsEXT(GLenum datatype,  GLenum storagetype,  GLenum range,  GLuint components)
{
	typedef GLuint (*proc_type)(GLenum datatype,  GLenum storagetype,  GLenum range,  GLuint components);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenSymbolsEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenSymbolsEXT" ); }
	return (*func_ptr)( datatype, storagetype, range, components );
}

inline void glSetInvariantEXT(GLuint id,  GLenum type,  const GLvoid *addr)
{
	typedef void (*proc_type)(GLuint id,  GLenum type,  const GLvoid *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSetInvariantEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSetInvariantEXT" ); }
	(*func_ptr)( id, type, addr );
}

inline void glSetLocalConstantEXT(GLuint id,  GLenum type,  const GLvoid *addr)
{
	typedef void (*proc_type)(GLuint id,  GLenum type,  const GLvoid *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSetLocalConstantEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSetLocalConstantEXT" ); }
	(*func_ptr)( id, type, addr );
}

inline void glVariantbvEXT(GLuint id,  const GLbyte *addr)
{
	typedef void (*proc_type)(GLuint id,  const GLbyte *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantbvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantbvEXT" ); }
	(*func_ptr)( id, addr );
}

inline void glVariantsvEXT(GLuint id,  const GLshort *addr)
{
	typedef void (*proc_type)(GLuint id,  const GLshort *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantsvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantsvEXT" ); }
	(*func_ptr)( id, addr );
}

inline void glVariantivEXT(GLuint id,  const GLint *addr)
{
	typedef void (*proc_type)(GLuint id,  const GLint *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantivEXT" ); }
	(*func_ptr)( id, addr );
}

inline void glVariantfvEXT(GLuint id,  const GLfloat *addr)
{
	typedef void (*proc_type)(GLuint id,  const GLfloat *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantfvEXT" ); }
	(*func_ptr)( id, addr );
}

inline void glVariantdvEXT(GLuint id,  const GLdouble *addr)
{
	typedef void (*proc_type)(GLuint id,  const GLdouble *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantdvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantdvEXT" ); }
	(*func_ptr)( id, addr );
}

inline void glVariantubvEXT(GLuint id,  const GLubyte *addr)
{
	typedef void (*proc_type)(GLuint id,  const GLubyte *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantubvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantubvEXT" ); }
	(*func_ptr)( id, addr );
}

inline void glVariantusvEXT(GLuint id,  const GLushort *addr)
{
	typedef void (*proc_type)(GLuint id,  const GLushort *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantusvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantusvEXT" ); }
	(*func_ptr)( id, addr );
}

inline void glVariantuivEXT(GLuint id,  const GLuint *addr)
{
	typedef void (*proc_type)(GLuint id,  const GLuint *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantuivEXT" ); }
	(*func_ptr)( id, addr );
}

inline void glVariantPointerEXT(GLuint id,  GLenum type,  GLuint stride,  const GLvoid *addr)
{
	typedef void (*proc_type)(GLuint id,  GLenum type,  GLuint stride,  const GLvoid *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantPointerEXT" ); }
	(*func_ptr)( id, type, stride, addr );
}

inline void glEnableVariantClientStateEXT(GLuint id)
{
	typedef void (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEnableVariantClientStateEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEnableVariantClientStateEXT" ); }
	(*func_ptr)( id );
}

inline void glDisableVariantClientStateEXT(GLuint id)
{
	typedef void (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDisableVariantClientStateEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDisableVariantClientStateEXT" ); }
	(*func_ptr)( id );
}

inline GLuint glBindLightParameterEXT(GLenum light,  GLenum value)
{
	typedef GLuint (*proc_type)(GLenum light,  GLenum value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindLightParameterEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindLightParameterEXT" ); }
	return (*func_ptr)( light, value );
}

inline GLuint glBindMaterialParameterEXT(GLenum face,  GLenum value)
{
	typedef GLuint (*proc_type)(GLenum face,  GLenum value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindMaterialParameterEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindMaterialParameterEXT" ); }
	return (*func_ptr)( face, value );
}

inline GLuint glBindTexGenParameterEXT(GLenum unit,  GLenum coord,  GLenum value)
{
	typedef GLuint (*proc_type)(GLenum unit,  GLenum coord,  GLenum value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindTexGenParameterEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindTexGenParameterEXT" ); }
	return (*func_ptr)( unit, coord, value );
}

inline GLuint glBindTextureUnitParameterEXT(GLenum unit,  GLenum value)
{
	typedef GLuint (*proc_type)(GLenum unit,  GLenum value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindTextureUnitParameterEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindTextureUnitParameterEXT" ); }
	return (*func_ptr)( unit, value );
}

inline GLuint glBindParameterEXT(GLenum value)
{
	typedef GLuint (*proc_type)(GLenum value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindParameterEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindParameterEXT" ); }
	return (*func_ptr)( value );
}

inline GLboolean glIsVariantEnabledEXT(GLuint id,  GLenum cap)
{
	typedef GLboolean (*proc_type)(GLuint id,  GLenum cap);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsVariantEnabledEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsVariantEnabledEXT" ); }
	return (*func_ptr)( id, cap );
}

inline void glGetVariantBooleanvEXT(GLuint id,  GLenum value,  GLboolean *data)
{
	typedef void (*proc_type)(GLuint id,  GLenum value,  GLboolean *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVariantBooleanvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVariantBooleanvEXT" ); }
	(*func_ptr)( id, value, data );
}

inline void glGetVariantIntegervEXT(GLuint id,  GLenum value,  GLint *data)
{
	typedef void (*proc_type)(GLuint id,  GLenum value,  GLint *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVariantIntegervEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVariantIntegervEXT" ); }
	(*func_ptr)( id, value, data );
}

inline void glGetVariantFloatvEXT(GLuint id,  GLenum value,  GLfloat *data)
{
	typedef void (*proc_type)(GLuint id,  GLenum value,  GLfloat *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVariantFloatvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVariantFloatvEXT" ); }
	(*func_ptr)( id, value, data );
}

inline void glGetVariantPointervEXT(GLuint id,  GLenum value,  GLvoid* *data)
{
	typedef void (*proc_type)(GLuint id,  GLenum value,  GLvoid* *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVariantPointervEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVariantPointervEXT" ); }
	(*func_ptr)( id, value, data );
}

inline void glGetInvariantBooleanvEXT(GLuint id,  GLenum value,  GLboolean *data)
{
	typedef void (*proc_type)(GLuint id,  GLenum value,  GLboolean *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetInvariantBooleanvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetInvariantBooleanvEXT" ); }
	(*func_ptr)( id, value, data );
}

inline void glGetInvariantIntegervEXT(GLuint id,  GLenum value,  GLint *data)
{
	typedef void (*proc_type)(GLuint id,  GLenum value,  GLint *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetInvariantIntegervEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetInvariantIntegervEXT" ); }
	(*func_ptr)( id, value, data );
}

inline void glGetInvariantFloatvEXT(GLuint id,  GLenum value,  GLfloat *data)
{
	typedef void (*proc_type)(GLuint id,  GLenum value,  GLfloat *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetInvariantFloatvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetInvariantFloatvEXT" ); }
	(*func_ptr)( id, value, data );
}

inline void glGetLocalConstantBooleanvEXT(GLuint id,  GLenum value,  GLboolean *data)
{
	typedef void (*proc_type)(GLuint id,  GLenum value,  GLboolean *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetLocalConstantBooleanvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetLocalConstantBooleanvEXT" ); }
	(*func_ptr)( id, value, data );
}

inline void glGetLocalConstantIntegervEXT(GLuint id,  GLenum value,  GLint *data)
{
	typedef void (*proc_type)(GLuint id,  GLenum value,  GLint *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetLocalConstantIntegervEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetLocalConstantIntegervEXT" ); }
	(*func_ptr)( id, value, data );
}

inline void glGetLocalConstantFloatvEXT(GLuint id,  GLenum value,  GLfloat *data)
{
	typedef void (*proc_type)(GLuint id,  GLenum value,  GLfloat *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetLocalConstantFloatvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetLocalConstantFloatvEXT" ); }
	(*func_ptr)( id, value, data );
}

inline void glVertexStream1sATI(GLenum stream,  GLshort x)
{
	typedef void (*proc_type)(GLenum stream,  GLshort x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream1sATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream1sATI" ); }
	(*func_ptr)( stream, x );
}

inline void glVertexStream1svATI(GLenum stream,  const GLshort *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLshort *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream1svATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream1svATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glVertexStream1iATI(GLenum stream,  GLint x)
{
	typedef void (*proc_type)(GLenum stream,  GLint x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream1iATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream1iATI" ); }
	(*func_ptr)( stream, x );
}

inline void glVertexStream1ivATI(GLenum stream,  const GLint *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream1ivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream1ivATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glVertexStream1fATI(GLenum stream,  GLfloat x)
{
	typedef void (*proc_type)(GLenum stream,  GLfloat x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream1fATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream1fATI" ); }
	(*func_ptr)( stream, x );
}

inline void glVertexStream1fvATI(GLenum stream,  const GLfloat *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLfloat *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream1fvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream1fvATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glVertexStream1dATI(GLenum stream,  GLdouble x)
{
	typedef void (*proc_type)(GLenum stream,  GLdouble x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream1dATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream1dATI" ); }
	(*func_ptr)( stream, x );
}

inline void glVertexStream1dvATI(GLenum stream,  const GLdouble *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLdouble *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream1dvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream1dvATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glVertexStream2sATI(GLenum stream,  GLshort x,  GLshort y)
{
	typedef void (*proc_type)(GLenum stream,  GLshort x,  GLshort y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream2sATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream2sATI" ); }
	(*func_ptr)( stream, x, y );
}

inline void glVertexStream2svATI(GLenum stream,  const GLshort *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLshort *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream2svATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream2svATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glVertexStream2iATI(GLenum stream,  GLint x,  GLint y)
{
	typedef void (*proc_type)(GLenum stream,  GLint x,  GLint y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream2iATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream2iATI" ); }
	(*func_ptr)( stream, x, y );
}

inline void glVertexStream2ivATI(GLenum stream,  const GLint *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream2ivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream2ivATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glVertexStream2fATI(GLenum stream,  GLfloat x,  GLfloat y)
{
	typedef void (*proc_type)(GLenum stream,  GLfloat x,  GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream2fATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream2fATI" ); }
	(*func_ptr)( stream, x, y );
}

inline void glVertexStream2fvATI(GLenum stream,  const GLfloat *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLfloat *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream2fvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream2fvATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glVertexStream2dATI(GLenum stream,  GLdouble x,  GLdouble y)
{
	typedef void (*proc_type)(GLenum stream,  GLdouble x,  GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream2dATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream2dATI" ); }
	(*func_ptr)( stream, x, y );
}

inline void glVertexStream2dvATI(GLenum stream,  const GLdouble *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLdouble *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream2dvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream2dvATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glVertexStream3sATI(GLenum stream,  GLshort x,  GLshort y,  GLshort z)
{
	typedef void (*proc_type)(GLenum stream,  GLshort x,  GLshort y,  GLshort z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream3sATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream3sATI" ); }
	(*func_ptr)( stream, x, y, z );
}

inline void glVertexStream3svATI(GLenum stream,  const GLshort *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLshort *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream3svATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream3svATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glVertexStream3iATI(GLenum stream,  GLint x,  GLint y,  GLint z)
{
	typedef void (*proc_type)(GLenum stream,  GLint x,  GLint y,  GLint z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream3iATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream3iATI" ); }
	(*func_ptr)( stream, x, y, z );
}

inline void glVertexStream3ivATI(GLenum stream,  const GLint *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream3ivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream3ivATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glVertexStream3fATI(GLenum stream,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLenum stream,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream3fATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream3fATI" ); }
	(*func_ptr)( stream, x, y, z );
}

inline void glVertexStream3fvATI(GLenum stream,  const GLfloat *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLfloat *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream3fvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream3fvATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glVertexStream3dATI(GLenum stream,  GLdouble x,  GLdouble y,  GLdouble z)
{
	typedef void (*proc_type)(GLenum stream,  GLdouble x,  GLdouble y,  GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream3dATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream3dATI" ); }
	(*func_ptr)( stream, x, y, z );
}

inline void glVertexStream3dvATI(GLenum stream,  const GLdouble *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLdouble *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream3dvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream3dvATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glVertexStream4sATI(GLenum stream,  GLshort x,  GLshort y,  GLshort z,  GLshort w)
{
	typedef void (*proc_type)(GLenum stream,  GLshort x,  GLshort y,  GLshort z,  GLshort w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream4sATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream4sATI" ); }
	(*func_ptr)( stream, x, y, z, w );
}

inline void glVertexStream4svATI(GLenum stream,  const GLshort *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLshort *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream4svATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream4svATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glVertexStream4iATI(GLenum stream,  GLint x,  GLint y,  GLint z,  GLint w)
{
	typedef void (*proc_type)(GLenum stream,  GLint x,  GLint y,  GLint z,  GLint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream4iATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream4iATI" ); }
	(*func_ptr)( stream, x, y, z, w );
}

inline void glVertexStream4ivATI(GLenum stream,  const GLint *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream4ivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream4ivATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glVertexStream4fATI(GLenum stream,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w)
{
	typedef void (*proc_type)(GLenum stream,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream4fATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream4fATI" ); }
	(*func_ptr)( stream, x, y, z, w );
}

inline void glVertexStream4fvATI(GLenum stream,  const GLfloat *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLfloat *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream4fvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream4fvATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glVertexStream4dATI(GLenum stream,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w)
{
	typedef void (*proc_type)(GLenum stream,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream4dATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream4dATI" ); }
	(*func_ptr)( stream, x, y, z, w );
}

inline void glVertexStream4dvATI(GLenum stream,  const GLdouble *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLdouble *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream4dvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream4dvATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glNormalStream3bATI(GLenum stream,  GLbyte nx,  GLbyte ny,  GLbyte nz)
{
	typedef void (*proc_type)(GLenum stream,  GLbyte nx,  GLbyte ny,  GLbyte nz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3bATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3bATI" ); }
	(*func_ptr)( stream, nx, ny, nz );
}

inline void glNormalStream3bvATI(GLenum stream,  const GLbyte *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLbyte *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3bvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3bvATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glNormalStream3sATI(GLenum stream,  GLshort nx,  GLshort ny,  GLshort nz)
{
	typedef void (*proc_type)(GLenum stream,  GLshort nx,  GLshort ny,  GLshort nz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3sATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3sATI" ); }
	(*func_ptr)( stream, nx, ny, nz );
}

inline void glNormalStream3svATI(GLenum stream,  const GLshort *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLshort *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3svATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3svATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glNormalStream3iATI(GLenum stream,  GLint nx,  GLint ny,  GLint nz)
{
	typedef void (*proc_type)(GLenum stream,  GLint nx,  GLint ny,  GLint nz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3iATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3iATI" ); }
	(*func_ptr)( stream, nx, ny, nz );
}

inline void glNormalStream3ivATI(GLenum stream,  const GLint *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3ivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3ivATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glNormalStream3fATI(GLenum stream,  GLfloat nx,  GLfloat ny,  GLfloat nz)
{
	typedef void (*proc_type)(GLenum stream,  GLfloat nx,  GLfloat ny,  GLfloat nz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3fATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3fATI" ); }
	(*func_ptr)( stream, nx, ny, nz );
}

inline void glNormalStream3fvATI(GLenum stream,  const GLfloat *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLfloat *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3fvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3fvATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glNormalStream3dATI(GLenum stream,  GLdouble nx,  GLdouble ny,  GLdouble nz)
{
	typedef void (*proc_type)(GLenum stream,  GLdouble nx,  GLdouble ny,  GLdouble nz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3dATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3dATI" ); }
	(*func_ptr)( stream, nx, ny, nz );
}

inline void glNormalStream3dvATI(GLenum stream,  const GLdouble *coords)
{
	typedef void (*proc_type)(GLenum stream,  const GLdouble *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3dvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3dvATI" ); }
	(*func_ptr)( stream, coords );
}

inline void glClientActiveVertexStreamATI(GLenum stream)
{
	typedef void (*proc_type)(GLenum stream);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClientActiveVertexStreamATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClientActiveVertexStreamATI" ); }
	(*func_ptr)( stream );
}

inline void glVertexBlendEnviATI(GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexBlendEnviATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexBlendEnviATI" ); }
	(*func_ptr)( pname, param );
}

inline void glVertexBlendEnvfATI(GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexBlendEnvfATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexBlendEnvfATI" ); }
	(*func_ptr)( pname, param );
}

inline void glElementPointerATI(GLenum type,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLenum type,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glElementPointerATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glElementPointerATI" ); }
	(*func_ptr)( type, pointer );
}

inline void glDrawElementArrayATI(GLenum mode,  GLsizei count)
{
	typedef void (*proc_type)(GLenum mode,  GLsizei count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementArrayATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementArrayATI" ); }
	(*func_ptr)( mode, count );
}

inline void glDrawRangeElementArrayATI(GLenum mode,  GLuint start,  GLuint end,  GLsizei count)
{
	typedef void (*proc_type)(GLenum mode,  GLuint start,  GLuint end,  GLsizei count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawRangeElementArrayATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawRangeElementArrayATI" ); }
	(*func_ptr)( mode, start, end, count );
}

inline void glDrawMeshArraysSUN(GLenum mode,  GLint first,  GLsizei count,  GLsizei width)
{
	typedef void (*proc_type)(GLenum mode,  GLint first,  GLsizei count,  GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawMeshArraysSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawMeshArraysSUN" ); }
	(*func_ptr)( mode, first, count, width );
}

inline void glGenOcclusionQueriesNV(GLsizei n,  GLuint *ids)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenOcclusionQueriesNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenOcclusionQueriesNV" ); }
	(*func_ptr)( n, ids );
}

inline void glDeleteOcclusionQueriesNV(GLsizei n,  const GLuint *ids)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteOcclusionQueriesNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteOcclusionQueriesNV" ); }
	(*func_ptr)( n, ids );
}

inline GLboolean glIsOcclusionQueryNV(GLuint id)
{
	typedef GLboolean (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsOcclusionQueryNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsOcclusionQueryNV" ); }
	return (*func_ptr)( id );
}

inline void glBeginOcclusionQueryNV(GLuint id)
{
	typedef void (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginOcclusionQueryNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginOcclusionQueryNV" ); }
	(*func_ptr)( id );
}

inline void glEndOcclusionQueryNV(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndOcclusionQueryNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndOcclusionQueryNV" ); }
	(*func_ptr)(  );
}

inline void glGetOcclusionQueryivNV(GLuint id,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint id,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetOcclusionQueryivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetOcclusionQueryivNV" ); }
	(*func_ptr)( id, pname, params );
}

inline void glGetOcclusionQueryuivNV(GLuint id,  GLenum pname,  GLuint *params)
{
	typedef void (*proc_type)(GLuint id,  GLenum pname,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetOcclusionQueryuivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetOcclusionQueryuivNV" ); }
	(*func_ptr)( id, pname, params );
}

inline void glPointParameteriNV(GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameteriNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameteriNV" ); }
	(*func_ptr)( pname, param );
}

inline void glPointParameterivNV(GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterivNV" ); }
	(*func_ptr)( pname, params );
}

inline void glActiveStencilFaceEXT(GLenum face)
{
	typedef void (*proc_type)(GLenum face);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glActiveStencilFaceEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glActiveStencilFaceEXT" ); }
	(*func_ptr)( face );
}

inline void glElementPointerAPPLE(GLenum type,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLenum type,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glElementPointerAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glElementPointerAPPLE" ); }
	(*func_ptr)( type, pointer );
}

inline void glDrawElementArrayAPPLE(GLenum mode,  GLint first,  GLsizei count)
{
	typedef void (*proc_type)(GLenum mode,  GLint first,  GLsizei count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementArrayAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementArrayAPPLE" ); }
	(*func_ptr)( mode, first, count );
}

inline void glDrawRangeElementArrayAPPLE(GLenum mode,  GLuint start,  GLuint end,  GLint first,  GLsizei count)
{
	typedef void (*proc_type)(GLenum mode,  GLuint start,  GLuint end,  GLint first,  GLsizei count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawRangeElementArrayAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawRangeElementArrayAPPLE" ); }
	(*func_ptr)( mode, start, end, first, count );
}

inline void glMultiDrawElementArrayAPPLE(GLenum mode,  const GLint *first,  const GLsizei *count,  GLsizei primcount)
{
	typedef void (*proc_type)(GLenum mode,  const GLint *first,  const GLsizei *count,  GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawElementArrayAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawElementArrayAPPLE" ); }
	(*func_ptr)( mode, first, count, primcount );
}

inline void glMultiDrawRangeElementArrayAPPLE(GLenum mode,  GLuint start,  GLuint end,  const GLint *first,  const GLsizei *count,  GLsizei primcount)
{
	typedef void (*proc_type)(GLenum mode,  GLuint start,  GLuint end,  const GLint *first,  const GLsizei *count,  GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawRangeElementArrayAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawRangeElementArrayAPPLE" ); }
	(*func_ptr)( mode, start, end, first, count, primcount );
}

inline void glGenFencesAPPLE(GLsizei n,  GLuint *fences)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *fences);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenFencesAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenFencesAPPLE" ); }
	(*func_ptr)( n, fences );
}

inline void glDeleteFencesAPPLE(GLsizei n,  const GLuint *fences)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *fences);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteFencesAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteFencesAPPLE" ); }
	(*func_ptr)( n, fences );
}

inline void glSetFenceAPPLE(GLuint fence)
{
	typedef void (*proc_type)(GLuint fence);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSetFenceAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSetFenceAPPLE" ); }
	(*func_ptr)( fence );
}

inline GLboolean glIsFenceAPPLE(GLuint fence)
{
	typedef GLboolean (*proc_type)(GLuint fence);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsFenceAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsFenceAPPLE" ); }
	return (*func_ptr)( fence );
}

inline GLboolean glTestFenceAPPLE(GLuint fence)
{
	typedef GLboolean (*proc_type)(GLuint fence);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTestFenceAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTestFenceAPPLE" ); }
	return (*func_ptr)( fence );
}

inline void glFinishFenceAPPLE(GLuint fence)
{
	typedef void (*proc_type)(GLuint fence);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFinishFenceAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFinishFenceAPPLE" ); }
	(*func_ptr)( fence );
}

inline GLboolean glTestObjectAPPLE(GLenum object,  GLuint name)
{
	typedef GLboolean (*proc_type)(GLenum object,  GLuint name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTestObjectAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTestObjectAPPLE" ); }
	return (*func_ptr)( object, name );
}

inline void glFinishObjectAPPLE(GLenum object,  GLint name)
{
	typedef void (*proc_type)(GLenum object,  GLint name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFinishObjectAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFinishObjectAPPLE" ); }
	(*func_ptr)( object, name );
}

inline void glBindVertexArrayAPPLE(GLuint array)
{
	typedef void (*proc_type)(GLuint array);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindVertexArrayAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindVertexArrayAPPLE" ); }
	(*func_ptr)( array );
}

inline void glDeleteVertexArraysAPPLE(GLsizei n,  const GLuint *arrays)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *arrays);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteVertexArraysAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteVertexArraysAPPLE" ); }
	(*func_ptr)( n, arrays );
}

inline void glGenVertexArraysAPPLE(GLsizei n,  GLuint *arrays)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *arrays);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenVertexArraysAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenVertexArraysAPPLE" ); }
	(*func_ptr)( n, arrays );
}

inline GLboolean glIsVertexArrayAPPLE(GLuint array)
{
	typedef GLboolean (*proc_type)(GLuint array);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsVertexArrayAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsVertexArrayAPPLE" ); }
	return (*func_ptr)( array );
}

inline void glVertexArrayRangeAPPLE(GLsizei length,  GLvoid *pointer)
{
	typedef void (*proc_type)(GLsizei length,  GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexArrayRangeAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexArrayRangeAPPLE" ); }
	(*func_ptr)( length, pointer );
}

inline void glFlushVertexArrayRangeAPPLE(GLsizei length,  GLvoid *pointer)
{
	typedef void (*proc_type)(GLsizei length,  GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFlushVertexArrayRangeAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFlushVertexArrayRangeAPPLE" ); }
	(*func_ptr)( length, pointer );
}

inline void glVertexArrayParameteriAPPLE(GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexArrayParameteriAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexArrayParameteriAPPLE" ); }
	(*func_ptr)( pname, param );
}

inline void glDrawBuffersATI(GLsizei n,  const GLenum *bufs)
{
	typedef void (*proc_type)(GLsizei n,  const GLenum *bufs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawBuffersATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawBuffersATI" ); }
	(*func_ptr)( n, bufs );
}

inline void glProgramNamedParameter4fNV(GLuint id,  GLsizei len,  const GLubyte *name,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w)
{
	typedef void (*proc_type)(GLuint id,  GLsizei len,  const GLubyte *name,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramNamedParameter4fNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramNamedParameter4fNV" ); }
	(*func_ptr)( id, len, name, x, y, z, w );
}

inline void glProgramNamedParameter4dNV(GLuint id,  GLsizei len,  const GLubyte *name,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w)
{
	typedef void (*proc_type)(GLuint id,  GLsizei len,  const GLubyte *name,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramNamedParameter4dNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramNamedParameter4dNV" ); }
	(*func_ptr)( id, len, name, x, y, z, w );
}

inline void glProgramNamedParameter4fvNV(GLuint id,  GLsizei len,  const GLubyte *name,  const GLfloat *v)
{
	typedef void (*proc_type)(GLuint id,  GLsizei len,  const GLubyte *name,  const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramNamedParameter4fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramNamedParameter4fvNV" ); }
	(*func_ptr)( id, len, name, v );
}

inline void glProgramNamedParameter4dvNV(GLuint id,  GLsizei len,  const GLubyte *name,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint id,  GLsizei len,  const GLubyte *name,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramNamedParameter4dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramNamedParameter4dvNV" ); }
	(*func_ptr)( id, len, name, v );
}

inline void glGetProgramNamedParameterfvNV(GLuint id,  GLsizei len,  const GLubyte *name,  GLfloat *params)
{
	typedef void (*proc_type)(GLuint id,  GLsizei len,  const GLubyte *name,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramNamedParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramNamedParameterfvNV" ); }
	(*func_ptr)( id, len, name, params );
}

inline void glGetProgramNamedParameterdvNV(GLuint id,  GLsizei len,  const GLubyte *name,  GLdouble *params)
{
	typedef void (*proc_type)(GLuint id,  GLsizei len,  const GLubyte *name,  GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramNamedParameterdvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramNamedParameterdvNV" ); }
	(*func_ptr)( id, len, name, params );
}

inline void glVertex2hNV(GLhalfNV x,  GLhalfNV y)
{
	typedef void (*proc_type)(GLhalfNV x,  GLhalfNV y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertex2hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertex2hNV" ); }
	(*func_ptr)( x, y );
}

inline void glVertex2hvNV(const GLhalfNV *v)
{
	typedef void (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertex2hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertex2hvNV" ); }
	(*func_ptr)( v );
}

inline void glVertex3hNV(GLhalfNV x,  GLhalfNV y,  GLhalfNV z)
{
	typedef void (*proc_type)(GLhalfNV x,  GLhalfNV y,  GLhalfNV z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertex3hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertex3hNV" ); }
	(*func_ptr)( x, y, z );
}

inline void glVertex3hvNV(const GLhalfNV *v)
{
	typedef void (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertex3hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertex3hvNV" ); }
	(*func_ptr)( v );
}

inline void glVertex4hNV(GLhalfNV x,  GLhalfNV y,  GLhalfNV z,  GLhalfNV w)
{
	typedef void (*proc_type)(GLhalfNV x,  GLhalfNV y,  GLhalfNV z,  GLhalfNV w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertex4hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertex4hNV" ); }
	(*func_ptr)( x, y, z, w );
}

inline void glVertex4hvNV(const GLhalfNV *v)
{
	typedef void (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertex4hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertex4hvNV" ); }
	(*func_ptr)( v );
}

inline void glNormal3hNV(GLhalfNV nx,  GLhalfNV ny,  GLhalfNV nz)
{
	typedef void (*proc_type)(GLhalfNV nx,  GLhalfNV ny,  GLhalfNV nz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormal3hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormal3hNV" ); }
	(*func_ptr)( nx, ny, nz );
}

inline void glNormal3hvNV(const GLhalfNV *v)
{
	typedef void (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormal3hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormal3hvNV" ); }
	(*func_ptr)( v );
}

inline void glColor3hNV(GLhalfNV red,  GLhalfNV green,  GLhalfNV blue)
{
	typedef void (*proc_type)(GLhalfNV red,  GLhalfNV green,  GLhalfNV blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor3hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor3hNV" ); }
	(*func_ptr)( red, green, blue );
}

inline void glColor3hvNV(const GLhalfNV *v)
{
	typedef void (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor3hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor3hvNV" ); }
	(*func_ptr)( v );
}

inline void glColor4hNV(GLhalfNV red,  GLhalfNV green,  GLhalfNV blue,  GLhalfNV alpha)
{
	typedef void (*proc_type)(GLhalfNV red,  GLhalfNV green,  GLhalfNV blue,  GLhalfNV alpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor4hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor4hNV" ); }
	(*func_ptr)( red, green, blue, alpha );
}

inline void glColor4hvNV(const GLhalfNV *v)
{
	typedef void (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor4hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor4hvNV" ); }
	(*func_ptr)( v );
}

inline void glTexCoord1hNV(GLhalfNV s)
{
	typedef void (*proc_type)(GLhalfNV s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord1hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord1hNV" ); }
	(*func_ptr)( s );
}

inline void glTexCoord1hvNV(const GLhalfNV *v)
{
	typedef void (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord1hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord1hvNV" ); }
	(*func_ptr)( v );
}

inline void glTexCoord2hNV(GLhalfNV s,  GLhalfNV t)
{
	typedef void (*proc_type)(GLhalfNV s,  GLhalfNV t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2hNV" ); }
	(*func_ptr)( s, t );
}

inline void glTexCoord2hvNV(const GLhalfNV *v)
{
	typedef void (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2hvNV" ); }
	(*func_ptr)( v );
}

inline void glTexCoord3hNV(GLhalfNV s,  GLhalfNV t,  GLhalfNV r)
{
	typedef void (*proc_type)(GLhalfNV s,  GLhalfNV t,  GLhalfNV r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord3hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord3hNV" ); }
	(*func_ptr)( s, t, r );
}

inline void glTexCoord3hvNV(const GLhalfNV *v)
{
	typedef void (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord3hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord3hvNV" ); }
	(*func_ptr)( v );
}

inline void glTexCoord4hNV(GLhalfNV s,  GLhalfNV t,  GLhalfNV r,  GLhalfNV q)
{
	typedef void (*proc_type)(GLhalfNV s,  GLhalfNV t,  GLhalfNV r,  GLhalfNV q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord4hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord4hNV" ); }
	(*func_ptr)( s, t, r, q );
}

inline void glTexCoord4hvNV(const GLhalfNV *v)
{
	typedef void (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord4hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord4hvNV" ); }
	(*func_ptr)( v );
}

inline void glMultiTexCoord1hNV(GLenum target,  GLhalfNV s)
{
	typedef void (*proc_type)(GLenum target,  GLhalfNV s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1hNV" ); }
	(*func_ptr)( target, s );
}

inline void glMultiTexCoord1hvNV(GLenum target,  const GLhalfNV *v)
{
	typedef void (*proc_type)(GLenum target,  const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1hvNV" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord2hNV(GLenum target,  GLhalfNV s,  GLhalfNV t)
{
	typedef void (*proc_type)(GLenum target,  GLhalfNV s,  GLhalfNV t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2hNV" ); }
	(*func_ptr)( target, s, t );
}

inline void glMultiTexCoord2hvNV(GLenum target,  const GLhalfNV *v)
{
	typedef void (*proc_type)(GLenum target,  const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2hvNV" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord3hNV(GLenum target,  GLhalfNV s,  GLhalfNV t,  GLhalfNV r)
{
	typedef void (*proc_type)(GLenum target,  GLhalfNV s,  GLhalfNV t,  GLhalfNV r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3hNV" ); }
	(*func_ptr)( target, s, t, r );
}

inline void glMultiTexCoord3hvNV(GLenum target,  const GLhalfNV *v)
{
	typedef void (*proc_type)(GLenum target,  const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3hvNV" ); }
	(*func_ptr)( target, v );
}

inline void glMultiTexCoord4hNV(GLenum target,  GLhalfNV s,  GLhalfNV t,  GLhalfNV r,  GLhalfNV q)
{
	typedef void (*proc_type)(GLenum target,  GLhalfNV s,  GLhalfNV t,  GLhalfNV r,  GLhalfNV q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4hNV" ); }
	(*func_ptr)( target, s, t, r, q );
}

inline void glMultiTexCoord4hvNV(GLenum target,  const GLhalfNV *v)
{
	typedef void (*proc_type)(GLenum target,  const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4hvNV" ); }
	(*func_ptr)( target, v );
}

inline void glFogCoordhNV(GLhalfNV fog)
{
	typedef void (*proc_type)(GLhalfNV fog);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordhNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordhNV" ); }
	(*func_ptr)( fog );
}

inline void glFogCoordhvNV(const GLhalfNV *fog)
{
	typedef void (*proc_type)(const GLhalfNV *fog);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordhvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordhvNV" ); }
	(*func_ptr)( fog );
}

inline void glSecondaryColor3hNV(GLhalfNV red,  GLhalfNV green,  GLhalfNV blue)
{
	typedef void (*proc_type)(GLhalfNV red,  GLhalfNV green,  GLhalfNV blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3hNV" ); }
	(*func_ptr)( red, green, blue );
}

inline void glSecondaryColor3hvNV(const GLhalfNV *v)
{
	typedef void (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3hvNV" ); }
	(*func_ptr)( v );
}

inline void glVertexWeighthNV(GLhalfNV weight)
{
	typedef void (*proc_type)(GLhalfNV weight);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexWeighthNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexWeighthNV" ); }
	(*func_ptr)( weight );
}

inline void glVertexWeighthvNV(const GLhalfNV *weight)
{
	typedef void (*proc_type)(const GLhalfNV *weight);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexWeighthvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexWeighthvNV" ); }
	(*func_ptr)( weight );
}

inline void glVertexAttrib1hNV(GLuint index,  GLhalfNV x)
{
	typedef void (*proc_type)(GLuint index,  GLhalfNV x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1hNV" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttrib1hvNV(GLuint index,  const GLhalfNV *v)
{
	typedef void (*proc_type)(GLuint index,  const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1hvNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib2hNV(GLuint index,  GLhalfNV x,  GLhalfNV y)
{
	typedef void (*proc_type)(GLuint index,  GLhalfNV x,  GLhalfNV y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2hNV" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttrib2hvNV(GLuint index,  const GLhalfNV *v)
{
	typedef void (*proc_type)(GLuint index,  const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2hvNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib3hNV(GLuint index,  GLhalfNV x,  GLhalfNV y,  GLhalfNV z)
{
	typedef void (*proc_type)(GLuint index,  GLhalfNV x,  GLhalfNV y,  GLhalfNV z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3hNV" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttrib3hvNV(GLuint index,  const GLhalfNV *v)
{
	typedef void (*proc_type)(GLuint index,  const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3hvNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttrib4hNV(GLuint index,  GLhalfNV x,  GLhalfNV y,  GLhalfNV z,  GLhalfNV w)
{
	typedef void (*proc_type)(GLuint index,  GLhalfNV x,  GLhalfNV y,  GLhalfNV z,  GLhalfNV w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4hNV" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttrib4hvNV(GLuint index,  const GLhalfNV *v)
{
	typedef void (*proc_type)(GLuint index,  const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4hvNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribs1hvNV(GLuint index,  GLsizei n,  const GLhalfNV *v)
{
	typedef void (*proc_type)(GLuint index,  GLsizei n,  const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs1hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs1hvNV" ); }
	(*func_ptr)( index, n, v );
}

inline void glVertexAttribs2hvNV(GLuint index,  GLsizei n,  const GLhalfNV *v)
{
	typedef void (*proc_type)(GLuint index,  GLsizei n,  const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs2hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs2hvNV" ); }
	(*func_ptr)( index, n, v );
}

inline void glVertexAttribs3hvNV(GLuint index,  GLsizei n,  const GLhalfNV *v)
{
	typedef void (*proc_type)(GLuint index,  GLsizei n,  const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs3hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs3hvNV" ); }
	(*func_ptr)( index, n, v );
}

inline void glVertexAttribs4hvNV(GLuint index,  GLsizei n,  const GLhalfNV *v)
{
	typedef void (*proc_type)(GLuint index,  GLsizei n,  const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs4hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs4hvNV" ); }
	(*func_ptr)( index, n, v );
}

inline void glPixelDataRangeNV(GLenum target,  GLsizei length,  GLvoid *pointer)
{
	typedef void (*proc_type)(GLenum target,  GLsizei length,  GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelDataRangeNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelDataRangeNV" ); }
	(*func_ptr)( target, length, pointer );
}

inline void glFlushPixelDataRangeNV(GLenum target)
{
	typedef void (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFlushPixelDataRangeNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFlushPixelDataRangeNV" ); }
	(*func_ptr)( target );
}

inline void glPrimitiveRestartNV(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPrimitiveRestartNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPrimitiveRestartNV" ); }
	(*func_ptr)(  );
}

inline void glPrimitiveRestartIndexNV(GLuint index)
{
	typedef void (*proc_type)(GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPrimitiveRestartIndexNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPrimitiveRestartIndexNV" ); }
	(*func_ptr)( index );
}

inline void glUnmapObjectBufferATI(GLuint buffer)
{
	typedef void (*proc_type)(GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUnmapObjectBufferATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUnmapObjectBufferATI" ); }
	(*func_ptr)( buffer );
}

inline void glStencilOpSeparateATI(GLenum face,  GLenum sfail,  GLenum dpfail,  GLenum dppass)
{
	typedef void (*proc_type)(GLenum face,  GLenum sfail,  GLenum dpfail,  GLenum dppass);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilOpSeparateATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilOpSeparateATI" ); }
	(*func_ptr)( face, sfail, dpfail, dppass );
}

inline void glStencilFuncSeparateATI(GLenum frontfunc,  GLenum backfunc,  GLint ref,  GLuint mask)
{
	typedef void (*proc_type)(GLenum frontfunc,  GLenum backfunc,  GLint ref,  GLuint mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilFuncSeparateATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilFuncSeparateATI" ); }
	(*func_ptr)( frontfunc, backfunc, ref, mask );
}

inline void glVertexAttribArrayObjectATI(GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  GLuint buffer,  GLuint offset)
{
	typedef void (*proc_type)(GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  GLuint buffer,  GLuint offset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribArrayObjectATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribArrayObjectATI" ); }
	(*func_ptr)( index, size, type, normalized, stride, buffer, offset );
}

inline void glGetVertexAttribArrayObjectfvATI(GLuint index,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribArrayObjectfvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribArrayObjectfvATI" ); }
	(*func_ptr)( index, pname, params );
}

inline void glGetVertexAttribArrayObjectivATI(GLuint index,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribArrayObjectivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribArrayObjectivATI" ); }
	(*func_ptr)( index, pname, params );
}

inline void glDepthBoundsEXT(GLclampd zmin,  GLclampd zmax)
{
	typedef void (*proc_type)(GLclampd zmin,  GLclampd zmax);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDepthBoundsEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDepthBoundsEXT" ); }
	(*func_ptr)( zmin, zmax );
}

inline void glBlendEquationSeparateEXT(GLenum modeRGB,  GLenum modeAlpha)
{
	typedef void (*proc_type)(GLenum modeRGB,  GLenum modeAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationSeparateEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationSeparateEXT" ); }
	(*func_ptr)( modeRGB, modeAlpha );
}

inline GLboolean glIsRenderbufferEXT(GLuint renderbuffer)
{
	typedef GLboolean (*proc_type)(GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsRenderbufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsRenderbufferEXT" ); }
	return (*func_ptr)( renderbuffer );
}

inline void glBindRenderbufferEXT(GLenum target,  GLuint renderbuffer)
{
	typedef void (*proc_type)(GLenum target,  GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindRenderbufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindRenderbufferEXT" ); }
	(*func_ptr)( target, renderbuffer );
}

inline void glDeleteRenderbuffersEXT(GLsizei n,  const GLuint *renderbuffers)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *renderbuffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteRenderbuffersEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteRenderbuffersEXT" ); }
	(*func_ptr)( n, renderbuffers );
}

inline void glGenRenderbuffersEXT(GLsizei n,  GLuint *renderbuffers)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *renderbuffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenRenderbuffersEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenRenderbuffersEXT" ); }
	(*func_ptr)( n, renderbuffers );
}

inline void glRenderbufferStorageEXT(GLenum target,  GLenum internalformat,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glRenderbufferStorageEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glRenderbufferStorageEXT" ); }
	(*func_ptr)( target, internalformat, width, height );
}

inline void glGetRenderbufferParameterivEXT(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetRenderbufferParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetRenderbufferParameterivEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline GLboolean glIsFramebufferEXT(GLuint framebuffer)
{
	typedef GLboolean (*proc_type)(GLuint framebuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsFramebufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsFramebufferEXT" ); }
	return (*func_ptr)( framebuffer );
}

inline void glBindFramebufferEXT(GLenum target,  GLuint framebuffer)
{
	typedef void (*proc_type)(GLenum target,  GLuint framebuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindFramebufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindFramebufferEXT" ); }
	(*func_ptr)( target, framebuffer );
}

inline void glDeleteFramebuffersEXT(GLsizei n,  const GLuint *framebuffers)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *framebuffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteFramebuffersEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteFramebuffersEXT" ); }
	(*func_ptr)( n, framebuffers );
}

inline void glGenFramebuffersEXT(GLsizei n,  GLuint *framebuffers)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *framebuffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenFramebuffersEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenFramebuffersEXT" ); }
	(*func_ptr)( n, framebuffers );
}

inline GLenum glCheckFramebufferStatusEXT(GLenum target)
{
	typedef GLenum (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCheckFramebufferStatusEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCheckFramebufferStatusEXT" ); }
	return (*func_ptr)( target );
}

inline void glFramebufferTexture1DEXT(GLenum target,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTexture1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTexture1DEXT" ); }
	(*func_ptr)( target, attachment, textarget, texture, level );
}

inline void glFramebufferTexture2DEXT(GLenum target,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTexture2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTexture2DEXT" ); }
	(*func_ptr)( target, attachment, textarget, texture, level );
}

inline void glFramebufferTexture3DEXT(GLenum target,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level,  GLint zoffset)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level,  GLint zoffset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTexture3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTexture3DEXT" ); }
	(*func_ptr)( target, attachment, textarget, texture, level, zoffset );
}

inline void glFramebufferRenderbufferEXT(GLenum target,  GLenum attachment,  GLenum renderbuffertarget,  GLuint renderbuffer)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLenum renderbuffertarget,  GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferRenderbufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferRenderbufferEXT" ); }
	(*func_ptr)( target, attachment, renderbuffertarget, renderbuffer );
}

inline void glGetFramebufferAttachmentParameterivEXT(GLenum target,  GLenum attachment,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFramebufferAttachmentParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFramebufferAttachmentParameterivEXT" ); }
	(*func_ptr)( target, attachment, pname, params );
}

inline void glGenerateMipmapEXT(GLenum target)
{
	typedef void (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenerateMipmapEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenerateMipmapEXT" ); }
	(*func_ptr)( target );
}

inline void glStringMarkerGREMEDY(GLsizei len,  const GLvoid *string)
{
	typedef void (*proc_type)(GLsizei len,  const GLvoid *string);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStringMarkerGREMEDY" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStringMarkerGREMEDY" ); }
	(*func_ptr)( len, string );
}

inline void glStencilClearTagEXT(GLsizei stencilTagBits,  GLuint stencilClearTag)
{
	typedef void (*proc_type)(GLsizei stencilTagBits,  GLuint stencilClearTag);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilClearTagEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilClearTagEXT" ); }
	(*func_ptr)( stencilTagBits, stencilClearTag );
}

inline void glBlitFramebufferEXT(GLint srcX0,  GLint srcY0,  GLint srcX1,  GLint srcY1,  GLint dstX0,  GLint dstY0,  GLint dstX1,  GLint dstY1,  GLbitfield mask,  GLenum filter)
{
	typedef void (*proc_type)(GLint srcX0,  GLint srcY0,  GLint srcX1,  GLint srcY1,  GLint dstX0,  GLint dstY0,  GLint dstX1,  GLint dstY1,  GLbitfield mask,  GLenum filter);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlitFramebufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlitFramebufferEXT" ); }
	(*func_ptr)( srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter );
}

inline void glRenderbufferStorageMultisampleEXT(GLenum target,  GLsizei samples,  GLenum internalformat,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLenum target,  GLsizei samples,  GLenum internalformat,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glRenderbufferStorageMultisampleEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glRenderbufferStorageMultisampleEXT" ); }
	(*func_ptr)( target, samples, internalformat, width, height );
}

inline void glGetQueryObjecti64vEXT(GLuint id,  GLenum pname,  GLint64EXT *params)
{
	typedef void (*proc_type)(GLuint id,  GLenum pname,  GLint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryObjecti64vEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryObjecti64vEXT" ); }
	(*func_ptr)( id, pname, params );
}

inline void glGetQueryObjectui64vEXT(GLuint id,  GLenum pname,  GLuint64EXT *params)
{
	typedef void (*proc_type)(GLuint id,  GLenum pname,  GLuint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryObjectui64vEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryObjectui64vEXT" ); }
	(*func_ptr)( id, pname, params );
}

inline void glProgramEnvParameters4fvEXT(GLenum target,  GLuint index,  GLsizei count,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLsizei count,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameters4fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameters4fvEXT" ); }
	(*func_ptr)( target, index, count, params );
}

inline void glProgramLocalParameters4fvEXT(GLenum target,  GLuint index,  GLsizei count,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLsizei count,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameters4fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameters4fvEXT" ); }
	(*func_ptr)( target, index, count, params );
}

inline void glBufferParameteriAPPLE(GLenum target,  GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBufferParameteriAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBufferParameteriAPPLE" ); }
	(*func_ptr)( target, pname, param );
}

inline void glFlushMappedBufferRangeAPPLE(GLenum target,  GLintptr offset,  GLsizeiptr size)
{
	typedef void (*proc_type)(GLenum target,  GLintptr offset,  GLsizeiptr size);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFlushMappedBufferRangeAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFlushMappedBufferRangeAPPLE" ); }
	(*func_ptr)( target, offset, size );
}

inline void glProgramLocalParameterI4iNV(GLenum target,  GLuint index,  GLint x,  GLint y,  GLint z,  GLint w)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLint x,  GLint y,  GLint z,  GLint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameterI4iNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameterI4iNV" ); }
	(*func_ptr)( target, index, x, y, z, w );
}

inline void glProgramLocalParameterI4ivNV(GLenum target,  GLuint index,  const GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameterI4ivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameterI4ivNV" ); }
	(*func_ptr)( target, index, params );
}

inline void glProgramLocalParametersI4ivNV(GLenum target,  GLuint index,  GLsizei count,  const GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLsizei count,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParametersI4ivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParametersI4ivNV" ); }
	(*func_ptr)( target, index, count, params );
}

inline void glProgramLocalParameterI4uiNV(GLenum target,  GLuint index,  GLuint x,  GLuint y,  GLuint z,  GLuint w)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLuint x,  GLuint y,  GLuint z,  GLuint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameterI4uiNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameterI4uiNV" ); }
	(*func_ptr)( target, index, x, y, z, w );
}

inline void glProgramLocalParameterI4uivNV(GLenum target,  GLuint index,  const GLuint *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameterI4uivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameterI4uivNV" ); }
	(*func_ptr)( target, index, params );
}

inline void glProgramLocalParametersI4uivNV(GLenum target,  GLuint index,  GLsizei count,  const GLuint *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLsizei count,  const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParametersI4uivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParametersI4uivNV" ); }
	(*func_ptr)( target, index, count, params );
}

inline void glProgramEnvParameterI4iNV(GLenum target,  GLuint index,  GLint x,  GLint y,  GLint z,  GLint w)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLint x,  GLint y,  GLint z,  GLint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameterI4iNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameterI4iNV" ); }
	(*func_ptr)( target, index, x, y, z, w );
}

inline void glProgramEnvParameterI4ivNV(GLenum target,  GLuint index,  const GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameterI4ivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameterI4ivNV" ); }
	(*func_ptr)( target, index, params );
}

inline void glProgramEnvParametersI4ivNV(GLenum target,  GLuint index,  GLsizei count,  const GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLsizei count,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParametersI4ivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParametersI4ivNV" ); }
	(*func_ptr)( target, index, count, params );
}

inline void glProgramEnvParameterI4uiNV(GLenum target,  GLuint index,  GLuint x,  GLuint y,  GLuint z,  GLuint w)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLuint x,  GLuint y,  GLuint z,  GLuint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameterI4uiNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameterI4uiNV" ); }
	(*func_ptr)( target, index, x, y, z, w );
}

inline void glProgramEnvParameterI4uivNV(GLenum target,  GLuint index,  const GLuint *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameterI4uivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameterI4uivNV" ); }
	(*func_ptr)( target, index, params );
}

inline void glProgramEnvParametersI4uivNV(GLenum target,  GLuint index,  GLsizei count,  const GLuint *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLsizei count,  const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParametersI4uivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParametersI4uivNV" ); }
	(*func_ptr)( target, index, count, params );
}

inline void glGetProgramLocalParameterIivNV(GLenum target,  GLuint index,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramLocalParameterIivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramLocalParameterIivNV" ); }
	(*func_ptr)( target, index, params );
}

inline void glGetProgramLocalParameterIuivNV(GLenum target,  GLuint index,  GLuint *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramLocalParameterIuivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramLocalParameterIuivNV" ); }
	(*func_ptr)( target, index, params );
}

inline void glGetProgramEnvParameterIivNV(GLenum target,  GLuint index,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramEnvParameterIivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramEnvParameterIivNV" ); }
	(*func_ptr)( target, index, params );
}

inline void glGetProgramEnvParameterIuivNV(GLenum target,  GLuint index,  GLuint *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramEnvParameterIuivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramEnvParameterIuivNV" ); }
	(*func_ptr)( target, index, params );
}

inline void glProgramVertexLimitNV(GLenum target,  GLint limit)
{
	typedef void (*proc_type)(GLenum target,  GLint limit);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramVertexLimitNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramVertexLimitNV" ); }
	(*func_ptr)( target, limit );
}

inline void glFramebufferTextureEXT(GLenum target,  GLenum attachment,  GLuint texture,  GLint level)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLuint texture,  GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTextureEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTextureEXT" ); }
	(*func_ptr)( target, attachment, texture, level );
}

inline void glFramebufferTextureLayerEXT(GLenum target,  GLenum attachment,  GLuint texture,  GLint level,  GLint layer)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLuint texture,  GLint level,  GLint layer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTextureLayerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTextureLayerEXT" ); }
	(*func_ptr)( target, attachment, texture, level, layer );
}

inline void glFramebufferTextureFaceEXT(GLenum target,  GLenum attachment,  GLuint texture,  GLint level,  GLenum face)
{
	typedef void (*proc_type)(GLenum target,  GLenum attachment,  GLuint texture,  GLint level,  GLenum face);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTextureFaceEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTextureFaceEXT" ); }
	(*func_ptr)( target, attachment, texture, level, face );
}

inline void glProgramParameteriEXT(GLuint program,  GLenum pname,  GLint value)
{
	typedef void (*proc_type)(GLuint program,  GLenum pname,  GLint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameteriEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameteriEXT" ); }
	(*func_ptr)( program, pname, value );
}

inline void glVertexAttribI1iEXT(GLuint index,  GLint x)
{
	typedef void (*proc_type)(GLuint index,  GLint x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI1iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI1iEXT" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttribI2iEXT(GLuint index,  GLint x,  GLint y)
{
	typedef void (*proc_type)(GLuint index,  GLint x,  GLint y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI2iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI2iEXT" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttribI3iEXT(GLuint index,  GLint x,  GLint y,  GLint z)
{
	typedef void (*proc_type)(GLuint index,  GLint x,  GLint y,  GLint z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI3iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI3iEXT" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttribI4iEXT(GLuint index,  GLint x,  GLint y,  GLint z,  GLint w)
{
	typedef void (*proc_type)(GLuint index,  GLint x,  GLint y,  GLint z,  GLint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4iEXT" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttribI1uiEXT(GLuint index,  GLuint x)
{
	typedef void (*proc_type)(GLuint index,  GLuint x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI1uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI1uiEXT" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttribI2uiEXT(GLuint index,  GLuint x,  GLuint y)
{
	typedef void (*proc_type)(GLuint index,  GLuint x,  GLuint y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI2uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI2uiEXT" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttribI3uiEXT(GLuint index,  GLuint x,  GLuint y,  GLuint z)
{
	typedef void (*proc_type)(GLuint index,  GLuint x,  GLuint y,  GLuint z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI3uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI3uiEXT" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttribI4uiEXT(GLuint index,  GLuint x,  GLuint y,  GLuint z,  GLuint w)
{
	typedef void (*proc_type)(GLuint index,  GLuint x,  GLuint y,  GLuint z,  GLuint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4uiEXT" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttribI1ivEXT(GLuint index,  const GLint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI1ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI1ivEXT" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI2ivEXT(GLuint index,  const GLint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI2ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI2ivEXT" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI3ivEXT(GLuint index,  const GLint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI3ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI3ivEXT" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI4ivEXT(GLuint index,  const GLint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4ivEXT" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI1uivEXT(GLuint index,  const GLuint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI1uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI1uivEXT" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI2uivEXT(GLuint index,  const GLuint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI2uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI2uivEXT" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI3uivEXT(GLuint index,  const GLuint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI3uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI3uivEXT" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI4uivEXT(GLuint index,  const GLuint *v)
{
	typedef void (*proc_type)(GLuint index,  const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4uivEXT" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI4bvEXT(GLuint index,  const GLbyte *v)
{
	typedef void (*proc_type)(GLuint index,  const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4bvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4bvEXT" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI4svEXT(GLuint index,  const GLshort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4svEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4svEXT" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI4ubvEXT(GLuint index,  const GLubyte *v)
{
	typedef void (*proc_type)(GLuint index,  const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4ubvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4ubvEXT" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribI4usvEXT(GLuint index,  const GLushort *v)
{
	typedef void (*proc_type)(GLuint index,  const GLushort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4usvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4usvEXT" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribIPointerEXT(GLuint index,  GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLuint index,  GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribIPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribIPointerEXT" ); }
	(*func_ptr)( index, size, type, stride, pointer );
}

inline void glGetVertexAttribIivEXT(GLuint index,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribIivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribIivEXT" ); }
	(*func_ptr)( index, pname, params );
}

inline void glGetVertexAttribIuivEXT(GLuint index,  GLenum pname,  GLuint *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribIuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribIuivEXT" ); }
	(*func_ptr)( index, pname, params );
}

inline void glGetUniformuivEXT(GLuint program,  GLint location,  GLuint *params)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformuivEXT" ); }
	(*func_ptr)( program, location, params );
}

inline void glBindFragDataLocationEXT(GLuint program,  GLuint color,  const GLchar *name)
{
	typedef void (*proc_type)(GLuint program,  GLuint color,  const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindFragDataLocationEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindFragDataLocationEXT" ); }
	(*func_ptr)( program, color, name );
}

inline GLint glGetFragDataLocationEXT(GLuint program,  const GLchar *name)
{
	typedef GLint (*proc_type)(GLuint program,  const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFragDataLocationEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFragDataLocationEXT" ); }
	return (*func_ptr)( program, name );
}

inline void glUniform1uiEXT(GLint location,  GLuint v0)
{
	typedef void (*proc_type)(GLint location,  GLuint v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1uiEXT" ); }
	(*func_ptr)( location, v0 );
}

inline void glUniform2uiEXT(GLint location,  GLuint v0,  GLuint v1)
{
	typedef void (*proc_type)(GLint location,  GLuint v0,  GLuint v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2uiEXT" ); }
	(*func_ptr)( location, v0, v1 );
}

inline void glUniform3uiEXT(GLint location,  GLuint v0,  GLuint v1,  GLuint v2)
{
	typedef void (*proc_type)(GLint location,  GLuint v0,  GLuint v1,  GLuint v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3uiEXT" ); }
	(*func_ptr)( location, v0, v1, v2 );
}

inline void glUniform4uiEXT(GLint location,  GLuint v0,  GLuint v1,  GLuint v2,  GLuint v3)
{
	typedef void (*proc_type)(GLint location,  GLuint v0,  GLuint v1,  GLuint v2,  GLuint v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4uiEXT" ); }
	(*func_ptr)( location, v0, v1, v2, v3 );
}

inline void glUniform1uivEXT(GLint location,  GLsizei count,  const GLuint *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1uivEXT" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform2uivEXT(GLint location,  GLsizei count,  const GLuint *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2uivEXT" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform3uivEXT(GLint location,  GLsizei count,  const GLuint *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3uivEXT" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform4uivEXT(GLint location,  GLsizei count,  const GLuint *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4uivEXT" ); }
	(*func_ptr)( location, count, value );
}

inline void glDrawArraysInstancedEXT(GLenum mode,  GLint start,  GLsizei count,  GLsizei primcount)
{
	typedef void (*proc_type)(GLenum mode,  GLint start,  GLsizei count,  GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawArraysInstancedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawArraysInstancedEXT" ); }
	(*func_ptr)( mode, start, count, primcount );
}

inline void glDrawElementsInstancedEXT(GLenum mode,  GLsizei count,  GLenum type,  const GLvoid *indices,  GLsizei primcount)
{
	typedef void (*proc_type)(GLenum mode,  GLsizei count,  GLenum type,  const GLvoid *indices,  GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementsInstancedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementsInstancedEXT" ); }
	(*func_ptr)( mode, count, type, indices, primcount );
}

inline void glTexBufferEXT(GLenum target,  GLenum internalformat,  GLuint buffer)
{
	typedef void (*proc_type)(GLenum target,  GLenum internalformat,  GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexBufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexBufferEXT" ); }
	(*func_ptr)( target, internalformat, buffer );
}

inline void glDepthRangedNV(GLdouble zNear,  GLdouble zFar)
{
	typedef void (*proc_type)(GLdouble zNear,  GLdouble zFar);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDepthRangedNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDepthRangedNV" ); }
	(*func_ptr)( zNear, zFar );
}

inline void glClearDepthdNV(GLdouble depth)
{
	typedef void (*proc_type)(GLdouble depth);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClearDepthdNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClearDepthdNV" ); }
	(*func_ptr)( depth );
}

inline void glDepthBoundsdNV(GLdouble zmin,  GLdouble zmax)
{
	typedef void (*proc_type)(GLdouble zmin,  GLdouble zmax);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDepthBoundsdNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDepthBoundsdNV" ); }
	(*func_ptr)( zmin, zmax );
}

inline void glRenderbufferStorageMultisampleCoverageNV(GLenum target,  GLsizei coverageSamples,  GLsizei colorSamples,  GLenum internalformat,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLenum target,  GLsizei coverageSamples,  GLsizei colorSamples,  GLenum internalformat,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glRenderbufferStorageMultisampleCoverageNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glRenderbufferStorageMultisampleCoverageNV" ); }
	(*func_ptr)( target, coverageSamples, colorSamples, internalformat, width, height );
}

inline void glProgramBufferParametersfvNV(GLenum target,  GLuint buffer,  GLuint index,  GLsizei count,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint buffer,  GLuint index,  GLsizei count,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramBufferParametersfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramBufferParametersfvNV" ); }
	(*func_ptr)( target, buffer, index, count, params );
}

inline void glProgramBufferParametersIivNV(GLenum target,  GLuint buffer,  GLuint index,  GLsizei count,  const GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint buffer,  GLuint index,  GLsizei count,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramBufferParametersIivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramBufferParametersIivNV" ); }
	(*func_ptr)( target, buffer, index, count, params );
}

inline void glProgramBufferParametersIuivNV(GLenum target,  GLuint buffer,  GLuint index,  GLsizei count,  const GLuint *params)
{
	typedef void (*proc_type)(GLenum target,  GLuint buffer,  GLuint index,  GLsizei count,  const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramBufferParametersIuivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramBufferParametersIuivNV" ); }
	(*func_ptr)( target, buffer, index, count, params );
}

inline void glColorMaskIndexedEXT(GLuint index,  GLboolean r,  GLboolean g,  GLboolean b,  GLboolean a)
{
	typedef void (*proc_type)(GLuint index,  GLboolean r,  GLboolean g,  GLboolean b,  GLboolean a);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorMaskIndexedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorMaskIndexedEXT" ); }
	(*func_ptr)( index, r, g, b, a );
}

inline void glGetBooleanIndexedvEXT(GLenum target,  GLuint index,  GLboolean *data)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLboolean *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBooleanIndexedvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBooleanIndexedvEXT" ); }
	(*func_ptr)( target, index, data );
}

inline void glGetIntegerIndexedvEXT(GLenum target,  GLuint index,  GLint *data)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLint *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetIntegerIndexedvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetIntegerIndexedvEXT" ); }
	(*func_ptr)( target, index, data );
}

inline void glEnableIndexedEXT(GLenum target,  GLuint index)
{
	typedef void (*proc_type)(GLenum target,  GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEnableIndexedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEnableIndexedEXT" ); }
	(*func_ptr)( target, index );
}

inline void glDisableIndexedEXT(GLenum target,  GLuint index)
{
	typedef void (*proc_type)(GLenum target,  GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDisableIndexedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDisableIndexedEXT" ); }
	(*func_ptr)( target, index );
}

inline GLboolean glIsEnabledIndexedEXT(GLenum target,  GLuint index)
{
	typedef GLboolean (*proc_type)(GLenum target,  GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsEnabledIndexedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsEnabledIndexedEXT" ); }
	return (*func_ptr)( target, index );
}

inline void glBeginTransformFeedbackNV(GLenum primitiveMode)
{
	typedef void (*proc_type)(GLenum primitiveMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginTransformFeedbackNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginTransformFeedbackNV" ); }
	(*func_ptr)( primitiveMode );
}

inline void glEndTransformFeedbackNV(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndTransformFeedbackNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndTransformFeedbackNV" ); }
	(*func_ptr)(  );
}

inline void glTransformFeedbackAttribsNV(GLuint count,  const GLint *attribs,  GLenum bufferMode)
{
	typedef void (*proc_type)(GLuint count,  const GLint *attribs,  GLenum bufferMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTransformFeedbackAttribsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTransformFeedbackAttribsNV" ); }
	(*func_ptr)( count, attribs, bufferMode );
}

inline void glBindBufferRangeNV(GLenum target,  GLuint index,  GLuint buffer,  GLintptr offset,  GLsizeiptr size)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLuint buffer,  GLintptr offset,  GLsizeiptr size);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferRangeNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferRangeNV" ); }
	(*func_ptr)( target, index, buffer, offset, size );
}

inline void glBindBufferOffsetNV(GLenum target,  GLuint index,  GLuint buffer,  GLintptr offset)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLuint buffer,  GLintptr offset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferOffsetNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferOffsetNV" ); }
	(*func_ptr)( target, index, buffer, offset );
}

inline void glBindBufferBaseNV(GLenum target,  GLuint index,  GLuint buffer)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferBaseNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferBaseNV" ); }
	(*func_ptr)( target, index, buffer );
}

inline void glTransformFeedbackVaryingsNV(GLuint program,  GLsizei count,  const GLint *locations,  GLenum bufferMode)
{
	typedef void (*proc_type)(GLuint program,  GLsizei count,  const GLint *locations,  GLenum bufferMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTransformFeedbackVaryingsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTransformFeedbackVaryingsNV" ); }
	(*func_ptr)( program, count, locations, bufferMode );
}

inline void glActiveVaryingNV(GLuint program,  const GLchar *name)
{
	typedef void (*proc_type)(GLuint program,  const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glActiveVaryingNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glActiveVaryingNV" ); }
	(*func_ptr)( program, name );
}

inline GLint glGetVaryingLocationNV(GLuint program,  const GLchar *name)
{
	typedef GLint (*proc_type)(GLuint program,  const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVaryingLocationNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVaryingLocationNV" ); }
	return (*func_ptr)( program, name );
}

inline void glGetActiveVaryingNV(GLuint program,  GLuint index,  GLsizei bufSize,  GLsizei *length,  GLsizei *size,  GLenum *type,  GLchar *name)
{
	typedef void (*proc_type)(GLuint program,  GLuint index,  GLsizei bufSize,  GLsizei *length,  GLsizei *size,  GLenum *type,  GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveVaryingNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveVaryingNV" ); }
	(*func_ptr)( program, index, bufSize, length, size, type, name );
}

inline void glGetTransformFeedbackVaryingNV(GLuint program,  GLuint index,  GLint *location)
{
	typedef void (*proc_type)(GLuint program,  GLuint index,  GLint *location);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTransformFeedbackVaryingNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTransformFeedbackVaryingNV" ); }
	(*func_ptr)( program, index, location );
}

inline void glTransformFeedbackStreamAttribsNV(GLsizei count,  const GLint *attribs,  GLsizei nbuffers,  const GLint *bufstreams,  GLenum bufferMode)
{
	typedef void (*proc_type)(GLsizei count,  const GLint *attribs,  GLsizei nbuffers,  const GLint *bufstreams,  GLenum bufferMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTransformFeedbackStreamAttribsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTransformFeedbackStreamAttribsNV" ); }
	(*func_ptr)( count, attribs, nbuffers, bufstreams, bufferMode );
}

inline void glUniformBufferEXT(GLuint program,  GLint location,  GLuint buffer)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformBufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformBufferEXT" ); }
	(*func_ptr)( program, location, buffer );
}

inline GLint glGetUniformBufferSizeEXT(GLuint program,  GLint location)
{
	typedef GLint (*proc_type)(GLuint program,  GLint location);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformBufferSizeEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformBufferSizeEXT" ); }
	return (*func_ptr)( program, location );
}

inline GLintptr glGetUniformOffsetEXT(GLuint program,  GLint location)
{
	typedef GLintptr (*proc_type)(GLuint program,  GLint location);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformOffsetEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformOffsetEXT" ); }
	return (*func_ptr)( program, location );
}

inline void glTexParameterIivEXT(GLenum target,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexParameterIivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexParameterIivEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glTexParameterIuivEXT(GLenum target,  GLenum pname,  const GLuint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexParameterIuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexParameterIuivEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetTexParameterIivEXT(GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTexParameterIivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTexParameterIivEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetTexParameterIuivEXT(GLenum target,  GLenum pname,  GLuint *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTexParameterIuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTexParameterIuivEXT" ); }
	(*func_ptr)( target, pname, params );
}

inline void glClearColorIiEXT(GLint red,  GLint green,  GLint blue,  GLint alpha)
{
	typedef void (*proc_type)(GLint red,  GLint green,  GLint blue,  GLint alpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClearColorIiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClearColorIiEXT" ); }
	(*func_ptr)( red, green, blue, alpha );
}

inline void glClearColorIuiEXT(GLuint red,  GLuint green,  GLuint blue,  GLuint alpha)
{
	typedef void (*proc_type)(GLuint red,  GLuint green,  GLuint blue,  GLuint alpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClearColorIuiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClearColorIuiEXT" ); }
	(*func_ptr)( red, green, blue, alpha );
}

inline void glFrameTerminatorGREMEDY(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFrameTerminatorGREMEDY" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFrameTerminatorGREMEDY" ); }
	(*func_ptr)(  );
}

inline void glBeginConditionalRenderNV(GLuint id,  GLenum mode)
{
	typedef void (*proc_type)(GLuint id,  GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginConditionalRenderNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginConditionalRenderNV" ); }
	(*func_ptr)( id, mode );
}

inline void glEndConditionalRenderNV(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndConditionalRenderNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndConditionalRenderNV" ); }
	(*func_ptr)(  );
}

inline void glPresentFrameKeyedNV(GLuint video_slot,  GLuint64EXT minPresentTime,  GLuint beginPresentTimeId,  GLuint presentDurationId,  GLenum type,  GLenum target0,  GLuint fill0,  GLuint key0,  GLenum target1,  GLuint fill1,  GLuint key1)
{
	typedef void (*proc_type)(GLuint video_slot,  GLuint64EXT minPresentTime,  GLuint beginPresentTimeId,  GLuint presentDurationId,  GLenum type,  GLenum target0,  GLuint fill0,  GLuint key0,  GLenum target1,  GLuint fill1,  GLuint key1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPresentFrameKeyedNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPresentFrameKeyedNV" ); }
	(*func_ptr)( video_slot, minPresentTime, beginPresentTimeId, presentDurationId, type, target0, fill0, key0, target1, fill1, key1 );
}

inline void glPresentFrameDualFillNV(GLuint video_slot,  GLuint64EXT minPresentTime,  GLuint beginPresentTimeId,  GLuint presentDurationId,  GLenum type,  GLenum target0,  GLuint fill0,  GLenum target1,  GLuint fill1,  GLenum target2,  GLuint fill2,  GLenum target3,  GLuint fill3)
{
	typedef void (*proc_type)(GLuint video_slot,  GLuint64EXT minPresentTime,  GLuint beginPresentTimeId,  GLuint presentDurationId,  GLenum type,  GLenum target0,  GLuint fill0,  GLenum target1,  GLuint fill1,  GLenum target2,  GLuint fill2,  GLenum target3,  GLuint fill3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPresentFrameDualFillNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPresentFrameDualFillNV" ); }
	(*func_ptr)( video_slot, minPresentTime, beginPresentTimeId, presentDurationId, type, target0, fill0, target1, fill1, target2, fill2, target3, fill3 );
}

inline void glGetVideoivNV(GLuint video_slot,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint video_slot,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVideoivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVideoivNV" ); }
	(*func_ptr)( video_slot, pname, params );
}

inline void glGetVideouivNV(GLuint video_slot,  GLenum pname,  GLuint *params)
{
	typedef void (*proc_type)(GLuint video_slot,  GLenum pname,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVideouivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVideouivNV" ); }
	(*func_ptr)( video_slot, pname, params );
}

inline void glGetVideoi64vNV(GLuint video_slot,  GLenum pname,  GLint64EXT *params)
{
	typedef void (*proc_type)(GLuint video_slot,  GLenum pname,  GLint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVideoi64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVideoi64vNV" ); }
	(*func_ptr)( video_slot, pname, params );
}

inline void glGetVideoui64vNV(GLuint video_slot,  GLenum pname,  GLuint64EXT *params)
{
	typedef void (*proc_type)(GLuint video_slot,  GLenum pname,  GLuint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVideoui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVideoui64vNV" ); }
	(*func_ptr)( video_slot, pname, params );
}

inline void glBeginTransformFeedbackEXT(GLenum primitiveMode)
{
	typedef void (*proc_type)(GLenum primitiveMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginTransformFeedbackEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginTransformFeedbackEXT" ); }
	(*func_ptr)( primitiveMode );
}

inline void glEndTransformFeedbackEXT(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndTransformFeedbackEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndTransformFeedbackEXT" ); }
	(*func_ptr)(  );
}

inline void glBindBufferRangeEXT(GLenum target,  GLuint index,  GLuint buffer,  GLintptr offset,  GLsizeiptr size)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLuint buffer,  GLintptr offset,  GLsizeiptr size);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferRangeEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferRangeEXT" ); }
	(*func_ptr)( target, index, buffer, offset, size );
}

inline void glBindBufferOffsetEXT(GLenum target,  GLuint index,  GLuint buffer,  GLintptr offset)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLuint buffer,  GLintptr offset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferOffsetEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferOffsetEXT" ); }
	(*func_ptr)( target, index, buffer, offset );
}

inline void glBindBufferBaseEXT(GLenum target,  GLuint index,  GLuint buffer)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferBaseEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferBaseEXT" ); }
	(*func_ptr)( target, index, buffer );
}

inline void glTransformFeedbackVaryingsEXT(GLuint program,  GLsizei count,  const GLchar* *varyings,  GLenum bufferMode)
{
	typedef void (*proc_type)(GLuint program,  GLsizei count,  const GLchar* *varyings,  GLenum bufferMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTransformFeedbackVaryingsEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTransformFeedbackVaryingsEXT" ); }
	(*func_ptr)( program, count, varyings, bufferMode );
}

inline void glGetTransformFeedbackVaryingEXT(GLuint program,  GLuint index,  GLsizei bufSize,  GLsizei *length,  GLsizei *size,  GLenum *type,  GLchar *name)
{
	typedef void (*proc_type)(GLuint program,  GLuint index,  GLsizei bufSize,  GLsizei *length,  GLsizei *size,  GLenum *type,  GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTransformFeedbackVaryingEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTransformFeedbackVaryingEXT" ); }
	(*func_ptr)( program, index, bufSize, length, size, type, name );
}

inline void glClientAttribDefaultEXT(GLbitfield mask)
{
	typedef void (*proc_type)(GLbitfield mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClientAttribDefaultEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClientAttribDefaultEXT" ); }
	(*func_ptr)( mask );
}

inline void glPushClientAttribDefaultEXT(GLbitfield mask)
{
	typedef void (*proc_type)(GLbitfield mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPushClientAttribDefaultEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPushClientAttribDefaultEXT" ); }
	(*func_ptr)( mask );
}

inline void glMatrixLoadfEXT(GLenum mode,  const GLfloat *m)
{
	typedef void (*proc_type)(GLenum mode,  const GLfloat *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixLoadfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixLoadfEXT" ); }
	(*func_ptr)( mode, m );
}

inline void glMatrixLoaddEXT(GLenum mode,  const GLdouble *m)
{
	typedef void (*proc_type)(GLenum mode,  const GLdouble *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixLoaddEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixLoaddEXT" ); }
	(*func_ptr)( mode, m );
}

inline void glMatrixMultfEXT(GLenum mode,  const GLfloat *m)
{
	typedef void (*proc_type)(GLenum mode,  const GLfloat *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixMultfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixMultfEXT" ); }
	(*func_ptr)( mode, m );
}

inline void glMatrixMultdEXT(GLenum mode,  const GLdouble *m)
{
	typedef void (*proc_type)(GLenum mode,  const GLdouble *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixMultdEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixMultdEXT" ); }
	(*func_ptr)( mode, m );
}

inline void glMatrixLoadIdentityEXT(GLenum mode)
{
	typedef void (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixLoadIdentityEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixLoadIdentityEXT" ); }
	(*func_ptr)( mode );
}

inline void glMatrixRotatefEXT(GLenum mode,  GLfloat angle,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLenum mode,  GLfloat angle,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixRotatefEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixRotatefEXT" ); }
	(*func_ptr)( mode, angle, x, y, z );
}

inline void glMatrixRotatedEXT(GLenum mode,  GLdouble angle,  GLdouble x,  GLdouble y,  GLdouble z)
{
	typedef void (*proc_type)(GLenum mode,  GLdouble angle,  GLdouble x,  GLdouble y,  GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixRotatedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixRotatedEXT" ); }
	(*func_ptr)( mode, angle, x, y, z );
}

inline void glMatrixScalefEXT(GLenum mode,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLenum mode,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixScalefEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixScalefEXT" ); }
	(*func_ptr)( mode, x, y, z );
}

inline void glMatrixScaledEXT(GLenum mode,  GLdouble x,  GLdouble y,  GLdouble z)
{
	typedef void (*proc_type)(GLenum mode,  GLdouble x,  GLdouble y,  GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixScaledEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixScaledEXT" ); }
	(*func_ptr)( mode, x, y, z );
}

inline void glMatrixTranslatefEXT(GLenum mode,  GLfloat x,  GLfloat y,  GLfloat z)
{
	typedef void (*proc_type)(GLenum mode,  GLfloat x,  GLfloat y,  GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixTranslatefEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixTranslatefEXT" ); }
	(*func_ptr)( mode, x, y, z );
}

inline void glMatrixTranslatedEXT(GLenum mode,  GLdouble x,  GLdouble y,  GLdouble z)
{
	typedef void (*proc_type)(GLenum mode,  GLdouble x,  GLdouble y,  GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixTranslatedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixTranslatedEXT" ); }
	(*func_ptr)( mode, x, y, z );
}

inline void glMatrixFrustumEXT(GLenum mode,  GLdouble left,  GLdouble right,  GLdouble bottom,  GLdouble top,  GLdouble zNear,  GLdouble zFar)
{
	typedef void (*proc_type)(GLenum mode,  GLdouble left,  GLdouble right,  GLdouble bottom,  GLdouble top,  GLdouble zNear,  GLdouble zFar);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixFrustumEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixFrustumEXT" ); }
	(*func_ptr)( mode, left, right, bottom, top, zNear, zFar );
}

inline void glMatrixOrthoEXT(GLenum mode,  GLdouble left,  GLdouble right,  GLdouble bottom,  GLdouble top,  GLdouble zNear,  GLdouble zFar)
{
	typedef void (*proc_type)(GLenum mode,  GLdouble left,  GLdouble right,  GLdouble bottom,  GLdouble top,  GLdouble zNear,  GLdouble zFar);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixOrthoEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixOrthoEXT" ); }
	(*func_ptr)( mode, left, right, bottom, top, zNear, zFar );
}

inline void glMatrixPopEXT(GLenum mode)
{
	typedef void (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixPopEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixPopEXT" ); }
	(*func_ptr)( mode );
}

inline void glMatrixPushEXT(GLenum mode)
{
	typedef void (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixPushEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixPushEXT" ); }
	(*func_ptr)( mode );
}

inline void glMatrixLoadTransposefEXT(GLenum mode,  const GLfloat *m)
{
	typedef void (*proc_type)(GLenum mode,  const GLfloat *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixLoadTransposefEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixLoadTransposefEXT" ); }
	(*func_ptr)( mode, m );
}

inline void glMatrixLoadTransposedEXT(GLenum mode,  const GLdouble *m)
{
	typedef void (*proc_type)(GLenum mode,  const GLdouble *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixLoadTransposedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixLoadTransposedEXT" ); }
	(*func_ptr)( mode, m );
}

inline void glMatrixMultTransposefEXT(GLenum mode,  const GLfloat *m)
{
	typedef void (*proc_type)(GLenum mode,  const GLfloat *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixMultTransposefEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixMultTransposefEXT" ); }
	(*func_ptr)( mode, m );
}

inline void glMatrixMultTransposedEXT(GLenum mode,  const GLdouble *m)
{
	typedef void (*proc_type)(GLenum mode,  const GLdouble *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixMultTransposedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixMultTransposedEXT" ); }
	(*func_ptr)( mode, m );
}

inline void glTextureParameterfEXT(GLuint texture,  GLenum target,  GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureParameterfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureParameterfEXT" ); }
	(*func_ptr)( texture, target, pname, param );
}

inline void glTextureParameterfvEXT(GLuint texture,  GLenum target,  GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureParameterfvEXT" ); }
	(*func_ptr)( texture, target, pname, params );
}

inline void glTextureParameteriEXT(GLuint texture,  GLenum target,  GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureParameteriEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureParameteriEXT" ); }
	(*func_ptr)( texture, target, pname, param );
}

inline void glTextureParameterivEXT(GLuint texture,  GLenum target,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureParameterivEXT" ); }
	(*func_ptr)( texture, target, pname, params );
}

inline void glTextureImage1DEXT(GLuint texture,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureImage1DEXT" ); }
	(*func_ptr)( texture, target, level, internalformat, width, border, format, type, pixels );
}

inline void glTextureImage2DEXT(GLuint texture,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureImage2DEXT" ); }
	(*func_ptr)( texture, target, level, internalformat, width, height, border, format, type, pixels );
}

inline void glTextureSubImage1DEXT(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLsizei width,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLsizei width,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureSubImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureSubImage1DEXT" ); }
	(*func_ptr)( texture, target, level, xoffset, width, format, type, pixels );
}

inline void glTextureSubImage2DEXT(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureSubImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureSubImage2DEXT" ); }
	(*func_ptr)( texture, target, level, xoffset, yoffset, width, height, format, type, pixels );
}

inline void glCopyTextureImage1DEXT(GLuint texture,  GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLint border)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLint border);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTextureImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTextureImage1DEXT" ); }
	(*func_ptr)( texture, target, level, internalformat, x, y, width, border );
}

inline void glCopyTextureImage2DEXT(GLuint texture,  GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLsizei height,  GLint border)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLsizei height,  GLint border);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTextureImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTextureImage2DEXT" ); }
	(*func_ptr)( texture, target, level, internalformat, x, y, width, height, border );
}

inline void glCopyTextureSubImage1DEXT(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLint x,  GLint y,  GLsizei width)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLint x,  GLint y,  GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTextureSubImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTextureSubImage1DEXT" ); }
	(*func_ptr)( texture, target, level, xoffset, x, y, width );
}

inline void glCopyTextureSubImage2DEXT(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint x,  GLint y,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint x,  GLint y,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTextureSubImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTextureSubImage2DEXT" ); }
	(*func_ptr)( texture, target, level, xoffset, yoffset, x, y, width, height );
}

inline void glGetTextureImageEXT(GLuint texture,  GLenum target,  GLint level,  GLenum format,  GLenum type,  GLvoid *pixels)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLenum format,  GLenum type,  GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureImageEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureImageEXT" ); }
	(*func_ptr)( texture, target, level, format, type, pixels );
}

inline void glGetTextureParameterfvEXT(GLuint texture,  GLenum target,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureParameterfvEXT" ); }
	(*func_ptr)( texture, target, pname, params );
}

inline void glGetTextureParameterivEXT(GLuint texture,  GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureParameterivEXT" ); }
	(*func_ptr)( texture, target, pname, params );
}

inline void glGetTextureLevelParameterfvEXT(GLuint texture,  GLenum target,  GLint level,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureLevelParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureLevelParameterfvEXT" ); }
	(*func_ptr)( texture, target, level, pname, params );
}

inline void glGetTextureLevelParameterivEXT(GLuint texture,  GLenum target,  GLint level,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureLevelParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureLevelParameterivEXT" ); }
	(*func_ptr)( texture, target, level, pname, params );
}

inline void glTextureImage3DEXT(GLuint texture,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureImage3DEXT" ); }
	(*func_ptr)( texture, target, level, internalformat, width, height, depth, border, format, type, pixels );
}

inline void glTextureSubImage3DEXT(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureSubImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureSubImage3DEXT" ); }
	(*func_ptr)( texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels );
}

inline void glCopyTextureSubImage3DEXT(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLint x,  GLint y,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLint x,  GLint y,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTextureSubImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTextureSubImage3DEXT" ); }
	(*func_ptr)( texture, target, level, xoffset, yoffset, zoffset, x, y, width, height );
}

inline void glMultiTexParameterfEXT(GLenum texunit,  GLenum target,  GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexParameterfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexParameterfEXT" ); }
	(*func_ptr)( texunit, target, pname, param );
}

inline void glMultiTexParameterfvEXT(GLenum texunit,  GLenum target,  GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexParameterfvEXT" ); }
	(*func_ptr)( texunit, target, pname, params );
}

inline void glMultiTexParameteriEXT(GLenum texunit,  GLenum target,  GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexParameteriEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexParameteriEXT" ); }
	(*func_ptr)( texunit, target, pname, param );
}

inline void glMultiTexParameterivEXT(GLenum texunit,  GLenum target,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexParameterivEXT" ); }
	(*func_ptr)( texunit, target, pname, params );
}

inline void glMultiTexImage1DEXT(GLenum texunit,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexImage1DEXT" ); }
	(*func_ptr)( texunit, target, level, internalformat, width, border, format, type, pixels );
}

inline void glMultiTexImage2DEXT(GLenum texunit,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexImage2DEXT" ); }
	(*func_ptr)( texunit, target, level, internalformat, width, height, border, format, type, pixels );
}

inline void glMultiTexSubImage1DEXT(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLsizei width,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLsizei width,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexSubImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexSubImage1DEXT" ); }
	(*func_ptr)( texunit, target, level, xoffset, width, format, type, pixels );
}

inline void glMultiTexSubImage2DEXT(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLsizei width,  GLsizei height,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexSubImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexSubImage2DEXT" ); }
	(*func_ptr)( texunit, target, level, xoffset, yoffset, width, height, format, type, pixels );
}

inline void glCopyMultiTexImage1DEXT(GLenum texunit,  GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLint border)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLint border);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyMultiTexImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyMultiTexImage1DEXT" ); }
	(*func_ptr)( texunit, target, level, internalformat, x, y, width, border );
}

inline void glCopyMultiTexImage2DEXT(GLenum texunit,  GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLsizei height,  GLint border)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  GLsizei width,  GLsizei height,  GLint border);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyMultiTexImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyMultiTexImage2DEXT" ); }
	(*func_ptr)( texunit, target, level, internalformat, x, y, width, height, border );
}

inline void glCopyMultiTexSubImage1DEXT(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLint x,  GLint y,  GLsizei width)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLint x,  GLint y,  GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyMultiTexSubImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyMultiTexSubImage1DEXT" ); }
	(*func_ptr)( texunit, target, level, xoffset, x, y, width );
}

inline void glCopyMultiTexSubImage2DEXT(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint x,  GLint y,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint x,  GLint y,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyMultiTexSubImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyMultiTexSubImage2DEXT" ); }
	(*func_ptr)( texunit, target, level, xoffset, yoffset, x, y, width, height );
}

inline void glGetMultiTexImageEXT(GLenum texunit,  GLenum target,  GLint level,  GLenum format,  GLenum type,  GLvoid *pixels)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLenum format,  GLenum type,  GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexImageEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexImageEXT" ); }
	(*func_ptr)( texunit, target, level, format, type, pixels );
}

inline void glGetMultiTexParameterfvEXT(GLenum texunit,  GLenum target,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexParameterfvEXT" ); }
	(*func_ptr)( texunit, target, pname, params );
}

inline void glGetMultiTexParameterivEXT(GLenum texunit,  GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexParameterivEXT" ); }
	(*func_ptr)( texunit, target, pname, params );
}

inline void glGetMultiTexLevelParameterfvEXT(GLenum texunit,  GLenum target,  GLint level,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexLevelParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexLevelParameterfvEXT" ); }
	(*func_ptr)( texunit, target, level, pname, params );
}

inline void glGetMultiTexLevelParameterivEXT(GLenum texunit,  GLenum target,  GLint level,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexLevelParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexLevelParameterivEXT" ); }
	(*func_ptr)( texunit, target, level, pname, params );
}

inline void glMultiTexImage3DEXT(GLenum texunit,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLint border,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexImage3DEXT" ); }
	(*func_ptr)( texunit, target, level, internalformat, width, height, depth, border, format, type, pixels );
}

inline void glMultiTexSubImage3DEXT(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLenum format,  GLenum type,  const GLvoid *pixels)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLenum format,  GLenum type,  const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexSubImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexSubImage3DEXT" ); }
	(*func_ptr)( texunit, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels );
}

inline void glCopyMultiTexSubImage3DEXT(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLint x,  GLint y,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLint x,  GLint y,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyMultiTexSubImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyMultiTexSubImage3DEXT" ); }
	(*func_ptr)( texunit, target, level, xoffset, yoffset, zoffset, x, y, width, height );
}

inline void glBindMultiTextureEXT(GLenum texunit,  GLenum target,  GLuint texture)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLuint texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindMultiTextureEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindMultiTextureEXT" ); }
	(*func_ptr)( texunit, target, texture );
}

inline void glEnableClientStateIndexedEXT(GLenum array,  GLuint index)
{
	typedef void (*proc_type)(GLenum array,  GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEnableClientStateIndexedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEnableClientStateIndexedEXT" ); }
	(*func_ptr)( array, index );
}

inline void glDisableClientStateIndexedEXT(GLenum array,  GLuint index)
{
	typedef void (*proc_type)(GLenum array,  GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDisableClientStateIndexedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDisableClientStateIndexedEXT" ); }
	(*func_ptr)( array, index );
}

inline void glMultiTexCoordPointerEXT(GLenum texunit,  GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLenum texunit,  GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordPointerEXT" ); }
	(*func_ptr)( texunit, size, type, stride, pointer );
}

inline void glMultiTexEnvfEXT(GLenum texunit,  GLenum target,  GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexEnvfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexEnvfEXT" ); }
	(*func_ptr)( texunit, target, pname, param );
}

inline void glMultiTexEnvfvEXT(GLenum texunit,  GLenum target,  GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexEnvfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexEnvfvEXT" ); }
	(*func_ptr)( texunit, target, pname, params );
}

inline void glMultiTexEnviEXT(GLenum texunit,  GLenum target,  GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexEnviEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexEnviEXT" ); }
	(*func_ptr)( texunit, target, pname, param );
}

inline void glMultiTexEnvivEXT(GLenum texunit,  GLenum target,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexEnvivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexEnvivEXT" ); }
	(*func_ptr)( texunit, target, pname, params );
}

inline void glMultiTexGendEXT(GLenum texunit,  GLenum coord,  GLenum pname,  GLdouble param)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum coord,  GLenum pname,  GLdouble param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexGendEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexGendEXT" ); }
	(*func_ptr)( texunit, coord, pname, param );
}

inline void glMultiTexGendvEXT(GLenum texunit,  GLenum coord,  GLenum pname,  const GLdouble *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum coord,  GLenum pname,  const GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexGendvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexGendvEXT" ); }
	(*func_ptr)( texunit, coord, pname, params );
}

inline void glMultiTexGenfEXT(GLenum texunit,  GLenum coord,  GLenum pname,  GLfloat param)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum coord,  GLenum pname,  GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexGenfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexGenfEXT" ); }
	(*func_ptr)( texunit, coord, pname, param );
}

inline void glMultiTexGenfvEXT(GLenum texunit,  GLenum coord,  GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum coord,  GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexGenfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexGenfvEXT" ); }
	(*func_ptr)( texunit, coord, pname, params );
}

inline void glMultiTexGeniEXT(GLenum texunit,  GLenum coord,  GLenum pname,  GLint param)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum coord,  GLenum pname,  GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexGeniEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexGeniEXT" ); }
	(*func_ptr)( texunit, coord, pname, param );
}

inline void glMultiTexGenivEXT(GLenum texunit,  GLenum coord,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum coord,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexGenivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexGenivEXT" ); }
	(*func_ptr)( texunit, coord, pname, params );
}

inline void glGetMultiTexEnvfvEXT(GLenum texunit,  GLenum target,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexEnvfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexEnvfvEXT" ); }
	(*func_ptr)( texunit, target, pname, params );
}

inline void glGetMultiTexEnvivEXT(GLenum texunit,  GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexEnvivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexEnvivEXT" ); }
	(*func_ptr)( texunit, target, pname, params );
}

inline void glGetMultiTexGendvEXT(GLenum texunit,  GLenum coord,  GLenum pname,  GLdouble *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum coord,  GLenum pname,  GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexGendvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexGendvEXT" ); }
	(*func_ptr)( texunit, coord, pname, params );
}

inline void glGetMultiTexGenfvEXT(GLenum texunit,  GLenum coord,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum coord,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexGenfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexGenfvEXT" ); }
	(*func_ptr)( texunit, coord, pname, params );
}

inline void glGetMultiTexGenivEXT(GLenum texunit,  GLenum coord,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum coord,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexGenivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexGenivEXT" ); }
	(*func_ptr)( texunit, coord, pname, params );
}

inline void glGetFloatIndexedvEXT(GLenum target,  GLuint index,  GLfloat *data)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLfloat *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFloatIndexedvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFloatIndexedvEXT" ); }
	(*func_ptr)( target, index, data );
}

inline void glGetDoubleIndexedvEXT(GLenum target,  GLuint index,  GLdouble *data)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLdouble *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetDoubleIndexedvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetDoubleIndexedvEXT" ); }
	(*func_ptr)( target, index, data );
}

inline void glGetPointerIndexedvEXT(GLenum target,  GLuint index,  GLvoid* *data)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLvoid* *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPointerIndexedvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPointerIndexedvEXT" ); }
	(*func_ptr)( target, index, data );
}

inline void glCompressedTextureImage3DEXT(GLuint texture,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLint border,  GLsizei imageSize,  const GLvoid *bits)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLint border,  GLsizei imageSize,  const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTextureImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTextureImage3DEXT" ); }
	(*func_ptr)( texture, target, level, internalformat, width, height, depth, border, imageSize, bits );
}

inline void glCompressedTextureImage2DEXT(GLuint texture,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLint border,  GLsizei imageSize,  const GLvoid *bits)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLint border,  GLsizei imageSize,  const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTextureImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTextureImage2DEXT" ); }
	(*func_ptr)( texture, target, level, internalformat, width, height, border, imageSize, bits );
}

inline void glCompressedTextureImage1DEXT(GLuint texture,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLint border,  GLsizei imageSize,  const GLvoid *bits)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLint border,  GLsizei imageSize,  const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTextureImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTextureImage1DEXT" ); }
	(*func_ptr)( texture, target, level, internalformat, width, border, imageSize, bits );
}

inline void glCompressedTextureSubImage3DEXT(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLenum format,  GLsizei imageSize,  const GLvoid *bits)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLenum format,  GLsizei imageSize,  const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTextureSubImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTextureSubImage3DEXT" ); }
	(*func_ptr)( texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits );
}

inline void glCompressedTextureSubImage2DEXT(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLsizei width,  GLsizei height,  GLenum format,  GLsizei imageSize,  const GLvoid *bits)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLsizei width,  GLsizei height,  GLenum format,  GLsizei imageSize,  const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTextureSubImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTextureSubImage2DEXT" ); }
	(*func_ptr)( texture, target, level, xoffset, yoffset, width, height, format, imageSize, bits );
}

inline void glCompressedTextureSubImage1DEXT(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLsizei width,  GLenum format,  GLsizei imageSize,  const GLvoid *bits)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint level,  GLint xoffset,  GLsizei width,  GLenum format,  GLsizei imageSize,  const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTextureSubImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTextureSubImage1DEXT" ); }
	(*func_ptr)( texture, target, level, xoffset, width, format, imageSize, bits );
}

inline void glGetCompressedTextureImageEXT(GLuint texture,  GLenum target,  GLint lod,  GLvoid *img)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLint lod,  GLvoid *img);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCompressedTextureImageEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCompressedTextureImageEXT" ); }
	(*func_ptr)( texture, target, lod, img );
}

inline void glCompressedMultiTexImage3DEXT(GLenum texunit,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLint border,  GLsizei imageSize,  const GLvoid *bits)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLint border,  GLsizei imageSize,  const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedMultiTexImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedMultiTexImage3DEXT" ); }
	(*func_ptr)( texunit, target, level, internalformat, width, height, depth, border, imageSize, bits );
}

inline void glCompressedMultiTexImage2DEXT(GLenum texunit,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLint border,  GLsizei imageSize,  const GLvoid *bits)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLsizei height,  GLint border,  GLsizei imageSize,  const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedMultiTexImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedMultiTexImage2DEXT" ); }
	(*func_ptr)( texunit, target, level, internalformat, width, height, border, imageSize, bits );
}

inline void glCompressedMultiTexImage1DEXT(GLenum texunit,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLint border,  GLsizei imageSize,  const GLvoid *bits)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLenum internalformat,  GLsizei width,  GLint border,  GLsizei imageSize,  const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedMultiTexImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedMultiTexImage1DEXT" ); }
	(*func_ptr)( texunit, target, level, internalformat, width, border, imageSize, bits );
}

inline void glCompressedMultiTexSubImage3DEXT(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLenum format,  GLsizei imageSize,  const GLvoid *bits)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLint zoffset,  GLsizei width,  GLsizei height,  GLsizei depth,  GLenum format,  GLsizei imageSize,  const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedMultiTexSubImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedMultiTexSubImage3DEXT" ); }
	(*func_ptr)( texunit, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits );
}

inline void glCompressedMultiTexSubImage2DEXT(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLsizei width,  GLsizei height,  GLenum format,  GLsizei imageSize,  const GLvoid *bits)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLint yoffset,  GLsizei width,  GLsizei height,  GLenum format,  GLsizei imageSize,  const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedMultiTexSubImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedMultiTexSubImage2DEXT" ); }
	(*func_ptr)( texunit, target, level, xoffset, yoffset, width, height, format, imageSize, bits );
}

inline void glCompressedMultiTexSubImage1DEXT(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLsizei width,  GLenum format,  GLsizei imageSize,  const GLvoid *bits)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint level,  GLint xoffset,  GLsizei width,  GLenum format,  GLsizei imageSize,  const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedMultiTexSubImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedMultiTexSubImage1DEXT" ); }
	(*func_ptr)( texunit, target, level, xoffset, width, format, imageSize, bits );
}

inline void glGetCompressedMultiTexImageEXT(GLenum texunit,  GLenum target,  GLint lod,  GLvoid *img)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLint lod,  GLvoid *img);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCompressedMultiTexImageEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCompressedMultiTexImageEXT" ); }
	(*func_ptr)( texunit, target, lod, img );
}

inline void glNamedProgramStringEXT(GLuint program,  GLenum target,  GLenum format,  GLsizei len,  const GLvoid *string)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLenum format,  GLsizei len,  const GLvoid *string);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramStringEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramStringEXT" ); }
	(*func_ptr)( program, target, format, len, string );
}

inline void glNamedProgramLocalParameter4dEXT(GLuint program,  GLenum target,  GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameter4dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameter4dEXT" ); }
	(*func_ptr)( program, target, index, x, y, z, w );
}

inline void glNamedProgramLocalParameter4dvEXT(GLuint program,  GLenum target,  GLuint index,  const GLdouble *params)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLuint index,  const GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameter4dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameter4dvEXT" ); }
	(*func_ptr)( program, target, index, params );
}

inline void glNamedProgramLocalParameter4fEXT(GLuint program,  GLenum target,  GLuint index,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLuint index,  GLfloat x,  GLfloat y,  GLfloat z,  GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameter4fEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameter4fEXT" ); }
	(*func_ptr)( program, target, index, x, y, z, w );
}

inline void glNamedProgramLocalParameter4fvEXT(GLuint program,  GLenum target,  GLuint index,  const GLfloat *params)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLuint index,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameter4fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameter4fvEXT" ); }
	(*func_ptr)( program, target, index, params );
}

inline void glGetNamedProgramLocalParameterdvEXT(GLuint program,  GLenum target,  GLuint index,  GLdouble *params)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLuint index,  GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedProgramLocalParameterdvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedProgramLocalParameterdvEXT" ); }
	(*func_ptr)( program, target, index, params );
}

inline void glGetNamedProgramLocalParameterfvEXT(GLuint program,  GLenum target,  GLuint index,  GLfloat *params)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLuint index,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedProgramLocalParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedProgramLocalParameterfvEXT" ); }
	(*func_ptr)( program, target, index, params );
}

inline void glGetNamedProgramivEXT(GLuint program,  GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedProgramivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedProgramivEXT" ); }
	(*func_ptr)( program, target, pname, params );
}

inline void glGetNamedProgramStringEXT(GLuint program,  GLenum target,  GLenum pname,  GLvoid *string)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLenum pname,  GLvoid *string);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedProgramStringEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedProgramStringEXT" ); }
	(*func_ptr)( program, target, pname, string );
}

inline void glNamedProgramLocalParameters4fvEXT(GLuint program,  GLenum target,  GLuint index,  GLsizei count,  const GLfloat *params)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLuint index,  GLsizei count,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameters4fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameters4fvEXT" ); }
	(*func_ptr)( program, target, index, count, params );
}

inline void glNamedProgramLocalParameterI4iEXT(GLuint program,  GLenum target,  GLuint index,  GLint x,  GLint y,  GLint z,  GLint w)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLuint index,  GLint x,  GLint y,  GLint z,  GLint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameterI4iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameterI4iEXT" ); }
	(*func_ptr)( program, target, index, x, y, z, w );
}

inline void glNamedProgramLocalParameterI4ivEXT(GLuint program,  GLenum target,  GLuint index,  const GLint *params)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLuint index,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameterI4ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameterI4ivEXT" ); }
	(*func_ptr)( program, target, index, params );
}

inline void glNamedProgramLocalParametersI4ivEXT(GLuint program,  GLenum target,  GLuint index,  GLsizei count,  const GLint *params)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLuint index,  GLsizei count,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParametersI4ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParametersI4ivEXT" ); }
	(*func_ptr)( program, target, index, count, params );
}

inline void glNamedProgramLocalParameterI4uiEXT(GLuint program,  GLenum target,  GLuint index,  GLuint x,  GLuint y,  GLuint z,  GLuint w)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLuint index,  GLuint x,  GLuint y,  GLuint z,  GLuint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameterI4uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameterI4uiEXT" ); }
	(*func_ptr)( program, target, index, x, y, z, w );
}

inline void glNamedProgramLocalParameterI4uivEXT(GLuint program,  GLenum target,  GLuint index,  const GLuint *params)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLuint index,  const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameterI4uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameterI4uivEXT" ); }
	(*func_ptr)( program, target, index, params );
}

inline void glNamedProgramLocalParametersI4uivEXT(GLuint program,  GLenum target,  GLuint index,  GLsizei count,  const GLuint *params)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLuint index,  GLsizei count,  const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParametersI4uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParametersI4uivEXT" ); }
	(*func_ptr)( program, target, index, count, params );
}

inline void glGetNamedProgramLocalParameterIivEXT(GLuint program,  GLenum target,  GLuint index,  GLint *params)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLuint index,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedProgramLocalParameterIivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedProgramLocalParameterIivEXT" ); }
	(*func_ptr)( program, target, index, params );
}

inline void glGetNamedProgramLocalParameterIuivEXT(GLuint program,  GLenum target,  GLuint index,  GLuint *params)
{
	typedef void (*proc_type)(GLuint program,  GLenum target,  GLuint index,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedProgramLocalParameterIuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedProgramLocalParameterIuivEXT" ); }
	(*func_ptr)( program, target, index, params );
}

inline void glTextureParameterIivEXT(GLuint texture,  GLenum target,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureParameterIivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureParameterIivEXT" ); }
	(*func_ptr)( texture, target, pname, params );
}

inline void glTextureParameterIuivEXT(GLuint texture,  GLenum target,  GLenum pname,  const GLuint *params)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLenum pname,  const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureParameterIuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureParameterIuivEXT" ); }
	(*func_ptr)( texture, target, pname, params );
}

inline void glGetTextureParameterIivEXT(GLuint texture,  GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureParameterIivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureParameterIivEXT" ); }
	(*func_ptr)( texture, target, pname, params );
}

inline void glGetTextureParameterIuivEXT(GLuint texture,  GLenum target,  GLenum pname,  GLuint *params)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLenum pname,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureParameterIuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureParameterIuivEXT" ); }
	(*func_ptr)( texture, target, pname, params );
}

inline void glMultiTexParameterIivEXT(GLenum texunit,  GLenum target,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexParameterIivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexParameterIivEXT" ); }
	(*func_ptr)( texunit, target, pname, params );
}

inline void glMultiTexParameterIuivEXT(GLenum texunit,  GLenum target,  GLenum pname,  const GLuint *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLenum pname,  const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexParameterIuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexParameterIuivEXT" ); }
	(*func_ptr)( texunit, target, pname, params );
}

inline void glGetMultiTexParameterIivEXT(GLenum texunit,  GLenum target,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexParameterIivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexParameterIivEXT" ); }
	(*func_ptr)( texunit, target, pname, params );
}

inline void glGetMultiTexParameterIuivEXT(GLenum texunit,  GLenum target,  GLenum pname,  GLuint *params)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLenum pname,  GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexParameterIuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexParameterIuivEXT" ); }
	(*func_ptr)( texunit, target, pname, params );
}

inline void glProgramUniform1fEXT(GLuint program,  GLint location,  GLfloat v0)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLfloat v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1fEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1fEXT" ); }
	(*func_ptr)( program, location, v0 );
}

inline void glProgramUniform2fEXT(GLuint program,  GLint location,  GLfloat v0,  GLfloat v1)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLfloat v0,  GLfloat v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2fEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2fEXT" ); }
	(*func_ptr)( program, location, v0, v1 );
}

inline void glProgramUniform3fEXT(GLuint program,  GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3fEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3fEXT" ); }
	(*func_ptr)( program, location, v0, v1, v2 );
}

inline void glProgramUniform4fEXT(GLuint program,  GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2,  GLfloat v3)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLfloat v0,  GLfloat v1,  GLfloat v2,  GLfloat v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4fEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4fEXT" ); }
	(*func_ptr)( program, location, v0, v1, v2, v3 );
}

inline void glProgramUniform1iEXT(GLuint program,  GLint location,  GLint v0)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLint v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1iEXT" ); }
	(*func_ptr)( program, location, v0 );
}

inline void glProgramUniform2iEXT(GLuint program,  GLint location,  GLint v0,  GLint v1)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLint v0,  GLint v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2iEXT" ); }
	(*func_ptr)( program, location, v0, v1 );
}

inline void glProgramUniform3iEXT(GLuint program,  GLint location,  GLint v0,  GLint v1,  GLint v2)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLint v0,  GLint v1,  GLint v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3iEXT" ); }
	(*func_ptr)( program, location, v0, v1, v2 );
}

inline void glProgramUniform4iEXT(GLuint program,  GLint location,  GLint v0,  GLint v1,  GLint v2,  GLint v3)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLint v0,  GLint v1,  GLint v2,  GLint v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4iEXT" ); }
	(*func_ptr)( program, location, v0, v1, v2, v3 );
}

inline void glProgramUniform1fvEXT(GLuint program,  GLint location,  GLsizei count,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1fvEXT" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform2fvEXT(GLuint program,  GLint location,  GLsizei count,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2fvEXT" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform3fvEXT(GLuint program,  GLint location,  GLsizei count,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3fvEXT" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform4fvEXT(GLuint program,  GLint location,  GLsizei count,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4fvEXT" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform1ivEXT(GLuint program,  GLint location,  GLsizei count,  const GLint *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1ivEXT" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform2ivEXT(GLuint program,  GLint location,  GLsizei count,  const GLint *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2ivEXT" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform3ivEXT(GLuint program,  GLint location,  GLsizei count,  const GLint *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3ivEXT" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform4ivEXT(GLuint program,  GLint location,  GLsizei count,  const GLint *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4ivEXT" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniformMatrix2fvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2fvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix3fvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3fvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix4fvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4fvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix2x3fvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2x3fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2x3fvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix3x2fvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3x2fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3x2fvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix2x4fvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2x4fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2x4fvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix4x2fvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4x2fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4x2fvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix3x4fvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3x4fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3x4fvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix4x3fvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4x3fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4x3fvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniform1uiEXT(GLuint program,  GLint location,  GLuint v0)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1uiEXT" ); }
	(*func_ptr)( program, location, v0 );
}

inline void glProgramUniform2uiEXT(GLuint program,  GLint location,  GLuint v0,  GLuint v1)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint v0,  GLuint v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2uiEXT" ); }
	(*func_ptr)( program, location, v0, v1 );
}

inline void glProgramUniform3uiEXT(GLuint program,  GLint location,  GLuint v0,  GLuint v1,  GLuint v2)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint v0,  GLuint v1,  GLuint v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3uiEXT" ); }
	(*func_ptr)( program, location, v0, v1, v2 );
}

inline void glProgramUniform4uiEXT(GLuint program,  GLint location,  GLuint v0,  GLuint v1,  GLuint v2,  GLuint v3)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint v0,  GLuint v1,  GLuint v2,  GLuint v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4uiEXT" ); }
	(*func_ptr)( program, location, v0, v1, v2, v3 );
}

inline void glProgramUniform1uivEXT(GLuint program,  GLint location,  GLsizei count,  const GLuint *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1uivEXT" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform2uivEXT(GLuint program,  GLint location,  GLsizei count,  const GLuint *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2uivEXT" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform3uivEXT(GLuint program,  GLint location,  GLsizei count,  const GLuint *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3uivEXT" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform4uivEXT(GLuint program,  GLint location,  GLsizei count,  const GLuint *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4uivEXT" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glNamedBufferDataEXT(GLuint buffer,  GLsizeiptr size,  const GLvoid *data,  GLenum usage)
{
	typedef void (*proc_type)(GLuint buffer,  GLsizeiptr size,  const GLvoid *data,  GLenum usage);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedBufferDataEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedBufferDataEXT" ); }
	(*func_ptr)( buffer, size, data, usage );
}

inline void glNamedBufferSubDataEXT(GLuint buffer,  GLintptr offset,  GLsizeiptr size,  const GLvoid *data)
{
	typedef void (*proc_type)(GLuint buffer,  GLintptr offset,  GLsizeiptr size,  const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedBufferSubDataEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedBufferSubDataEXT" ); }
	(*func_ptr)( buffer, offset, size, data );
}

inline GLboolean glUnmapNamedBufferEXT(GLuint buffer)
{
	typedef GLboolean (*proc_type)(GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUnmapNamedBufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUnmapNamedBufferEXT" ); }
	return (*func_ptr)( buffer );
}

inline void glFlushMappedNamedBufferRangeEXT(GLuint buffer,  GLintptr offset,  GLsizeiptr length)
{
	typedef void (*proc_type)(GLuint buffer,  GLintptr offset,  GLsizeiptr length);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFlushMappedNamedBufferRangeEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFlushMappedNamedBufferRangeEXT" ); }
	(*func_ptr)( buffer, offset, length );
}

inline void glNamedCopyBufferSubDataEXT(GLuint readBuffer,  GLuint writeBuffer,  GLintptr readOffset,  GLintptr writeOffset,  GLsizeiptr size)
{
	typedef void (*proc_type)(GLuint readBuffer,  GLuint writeBuffer,  GLintptr readOffset,  GLintptr writeOffset,  GLsizeiptr size);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedCopyBufferSubDataEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedCopyBufferSubDataEXT" ); }
	(*func_ptr)( readBuffer, writeBuffer, readOffset, writeOffset, size );
}

inline void glGetNamedBufferParameterivEXT(GLuint buffer,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint buffer,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedBufferParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedBufferParameterivEXT" ); }
	(*func_ptr)( buffer, pname, params );
}

inline void glGetNamedBufferPointervEXT(GLuint buffer,  GLenum pname,  GLvoid* *params)
{
	typedef void (*proc_type)(GLuint buffer,  GLenum pname,  GLvoid* *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedBufferPointervEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedBufferPointervEXT" ); }
	(*func_ptr)( buffer, pname, params );
}

inline void glGetNamedBufferSubDataEXT(GLuint buffer,  GLintptr offset,  GLsizeiptr size,  GLvoid *data)
{
	typedef void (*proc_type)(GLuint buffer,  GLintptr offset,  GLsizeiptr size,  GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedBufferSubDataEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedBufferSubDataEXT" ); }
	(*func_ptr)( buffer, offset, size, data );
}

inline void glTextureBufferEXT(GLuint texture,  GLenum target,  GLenum internalformat,  GLuint buffer)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLenum internalformat,  GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureBufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureBufferEXT" ); }
	(*func_ptr)( texture, target, internalformat, buffer );
}

inline void glMultiTexBufferEXT(GLenum texunit,  GLenum target,  GLenum internalformat,  GLuint buffer)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLenum internalformat,  GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexBufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexBufferEXT" ); }
	(*func_ptr)( texunit, target, internalformat, buffer );
}

inline void glNamedRenderbufferStorageEXT(GLuint renderbuffer,  GLenum internalformat,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLuint renderbuffer,  GLenum internalformat,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedRenderbufferStorageEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedRenderbufferStorageEXT" ); }
	(*func_ptr)( renderbuffer, internalformat, width, height );
}

inline void glGetNamedRenderbufferParameterivEXT(GLuint renderbuffer,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint renderbuffer,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedRenderbufferParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedRenderbufferParameterivEXT" ); }
	(*func_ptr)( renderbuffer, pname, params );
}

inline GLenum glCheckNamedFramebufferStatusEXT(GLuint framebuffer,  GLenum target)
{
	typedef GLenum (*proc_type)(GLuint framebuffer,  GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCheckNamedFramebufferStatusEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCheckNamedFramebufferStatusEXT" ); }
	return (*func_ptr)( framebuffer, target );
}

inline void glNamedFramebufferTexture1DEXT(GLuint framebuffer,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level)
{
	typedef void (*proc_type)(GLuint framebuffer,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedFramebufferTexture1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedFramebufferTexture1DEXT" ); }
	(*func_ptr)( framebuffer, attachment, textarget, texture, level );
}

inline void glNamedFramebufferTexture2DEXT(GLuint framebuffer,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level)
{
	typedef void (*proc_type)(GLuint framebuffer,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedFramebufferTexture2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedFramebufferTexture2DEXT" ); }
	(*func_ptr)( framebuffer, attachment, textarget, texture, level );
}

inline void glNamedFramebufferTexture3DEXT(GLuint framebuffer,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level,  GLint zoffset)
{
	typedef void (*proc_type)(GLuint framebuffer,  GLenum attachment,  GLenum textarget,  GLuint texture,  GLint level,  GLint zoffset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedFramebufferTexture3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedFramebufferTexture3DEXT" ); }
	(*func_ptr)( framebuffer, attachment, textarget, texture, level, zoffset );
}

inline void glNamedFramebufferRenderbufferEXT(GLuint framebuffer,  GLenum attachment,  GLenum renderbuffertarget,  GLuint renderbuffer)
{
	typedef void (*proc_type)(GLuint framebuffer,  GLenum attachment,  GLenum renderbuffertarget,  GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedFramebufferRenderbufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedFramebufferRenderbufferEXT" ); }
	(*func_ptr)( framebuffer, attachment, renderbuffertarget, renderbuffer );
}

inline void glGetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer,  GLenum attachment,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint framebuffer,  GLenum attachment,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedFramebufferAttachmentParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedFramebufferAttachmentParameterivEXT" ); }
	(*func_ptr)( framebuffer, attachment, pname, params );
}

inline void glGenerateTextureMipmapEXT(GLuint texture,  GLenum target)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenerateTextureMipmapEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenerateTextureMipmapEXT" ); }
	(*func_ptr)( texture, target );
}

inline void glGenerateMultiTexMipmapEXT(GLenum texunit,  GLenum target)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenerateMultiTexMipmapEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenerateMultiTexMipmapEXT" ); }
	(*func_ptr)( texunit, target );
}

inline void glFramebufferDrawBufferEXT(GLuint framebuffer,  GLenum mode)
{
	typedef void (*proc_type)(GLuint framebuffer,  GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferDrawBufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferDrawBufferEXT" ); }
	(*func_ptr)( framebuffer, mode );
}

inline void glFramebufferDrawBuffersEXT(GLuint framebuffer,  GLsizei n,  const GLenum *bufs)
{
	typedef void (*proc_type)(GLuint framebuffer,  GLsizei n,  const GLenum *bufs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferDrawBuffersEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferDrawBuffersEXT" ); }
	(*func_ptr)( framebuffer, n, bufs );
}

inline void glFramebufferReadBufferEXT(GLuint framebuffer,  GLenum mode)
{
	typedef void (*proc_type)(GLuint framebuffer,  GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferReadBufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferReadBufferEXT" ); }
	(*func_ptr)( framebuffer, mode );
}

inline void glGetFramebufferParameterivEXT(GLuint framebuffer,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint framebuffer,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFramebufferParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFramebufferParameterivEXT" ); }
	(*func_ptr)( framebuffer, pname, params );
}

inline void glNamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer,  GLsizei samples,  GLenum internalformat,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLuint renderbuffer,  GLsizei samples,  GLenum internalformat,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedRenderbufferStorageMultisampleEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedRenderbufferStorageMultisampleEXT" ); }
	(*func_ptr)( renderbuffer, samples, internalformat, width, height );
}

inline void glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer,  GLsizei coverageSamples,  GLsizei colorSamples,  GLenum internalformat,  GLsizei width,  GLsizei height)
{
	typedef void (*proc_type)(GLuint renderbuffer,  GLsizei coverageSamples,  GLsizei colorSamples,  GLenum internalformat,  GLsizei width,  GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedRenderbufferStorageMultisampleCoverageEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedRenderbufferStorageMultisampleCoverageEXT" ); }
	(*func_ptr)( renderbuffer, coverageSamples, colorSamples, internalformat, width, height );
}

inline void glNamedFramebufferTextureEXT(GLuint framebuffer,  GLenum attachment,  GLuint texture,  GLint level)
{
	typedef void (*proc_type)(GLuint framebuffer,  GLenum attachment,  GLuint texture,  GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedFramebufferTextureEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedFramebufferTextureEXT" ); }
	(*func_ptr)( framebuffer, attachment, texture, level );
}

inline void glNamedFramebufferTextureLayerEXT(GLuint framebuffer,  GLenum attachment,  GLuint texture,  GLint level,  GLint layer)
{
	typedef void (*proc_type)(GLuint framebuffer,  GLenum attachment,  GLuint texture,  GLint level,  GLint layer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedFramebufferTextureLayerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedFramebufferTextureLayerEXT" ); }
	(*func_ptr)( framebuffer, attachment, texture, level, layer );
}

inline void glNamedFramebufferTextureFaceEXT(GLuint framebuffer,  GLenum attachment,  GLuint texture,  GLint level,  GLenum face)
{
	typedef void (*proc_type)(GLuint framebuffer,  GLenum attachment,  GLuint texture,  GLint level,  GLenum face);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedFramebufferTextureFaceEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedFramebufferTextureFaceEXT" ); }
	(*func_ptr)( framebuffer, attachment, texture, level, face );
}

inline void glTextureRenderbufferEXT(GLuint texture,  GLenum target,  GLuint renderbuffer)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureRenderbufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureRenderbufferEXT" ); }
	(*func_ptr)( texture, target, renderbuffer );
}

inline void glMultiTexRenderbufferEXT(GLenum texunit,  GLenum target,  GLuint renderbuffer)
{
	typedef void (*proc_type)(GLenum texunit,  GLenum target,  GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexRenderbufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexRenderbufferEXT" ); }
	(*func_ptr)( texunit, target, renderbuffer );
}

inline void glProgramUniform1dEXT(GLuint program,  GLint location,  GLdouble x)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLdouble x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1dEXT" ); }
	(*func_ptr)( program, location, x );
}

inline void glProgramUniform2dEXT(GLuint program,  GLint location,  GLdouble x,  GLdouble y)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLdouble x,  GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2dEXT" ); }
	(*func_ptr)( program, location, x, y );
}

inline void glProgramUniform3dEXT(GLuint program,  GLint location,  GLdouble x,  GLdouble y,  GLdouble z)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLdouble x,  GLdouble y,  GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3dEXT" ); }
	(*func_ptr)( program, location, x, y, z );
}

inline void glProgramUniform4dEXT(GLuint program,  GLint location,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4dEXT" ); }
	(*func_ptr)( program, location, x, y, z, w );
}

inline void glProgramUniform1dvEXT(GLuint program,  GLint location,  GLsizei count,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1dvEXT" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform2dvEXT(GLuint program,  GLint location,  GLsizei count,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2dvEXT" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform3dvEXT(GLuint program,  GLint location,  GLsizei count,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3dvEXT" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform4dvEXT(GLuint program,  GLint location,  GLsizei count,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4dvEXT" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniformMatrix2dvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2dvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix3dvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3dvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix4dvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4dvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix2x3dvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2x3dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2x3dvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix2x4dvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2x4dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2x4dvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix3x2dvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3x2dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3x2dvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix3x4dvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3x4dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3x4dvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix4x2dvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4x2dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4x2dvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glProgramUniformMatrix4x3dvEXT(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  GLboolean transpose,  const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4x3dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4x3dvEXT" ); }
	(*func_ptr)( program, location, count, transpose, value );
}

inline void glGetMultisamplefvNV(GLenum pname,  GLuint index,  GLfloat *val)
{
	typedef void (*proc_type)(GLenum pname,  GLuint index,  GLfloat *val);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultisamplefvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultisamplefvNV" ); }
	(*func_ptr)( pname, index, val );
}

inline void glSampleMaskIndexedNV(GLuint index,  GLbitfield mask)
{
	typedef void (*proc_type)(GLuint index,  GLbitfield mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSampleMaskIndexedNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSampleMaskIndexedNV" ); }
	(*func_ptr)( index, mask );
}

inline void glTexRenderbufferNV(GLenum target,  GLuint renderbuffer)
{
	typedef void (*proc_type)(GLenum target,  GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexRenderbufferNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexRenderbufferNV" ); }
	(*func_ptr)( target, renderbuffer );
}

inline void glBindTransformFeedbackNV(GLenum target,  GLuint id)
{
	typedef void (*proc_type)(GLenum target,  GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindTransformFeedbackNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindTransformFeedbackNV" ); }
	(*func_ptr)( target, id );
}

inline void glDeleteTransformFeedbacksNV(GLsizei n,  const GLuint *ids)
{
	typedef void (*proc_type)(GLsizei n,  const GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteTransformFeedbacksNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteTransformFeedbacksNV" ); }
	(*func_ptr)( n, ids );
}

inline void glGenTransformFeedbacksNV(GLsizei n,  GLuint *ids)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenTransformFeedbacksNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenTransformFeedbacksNV" ); }
	(*func_ptr)( n, ids );
}

inline GLboolean glIsTransformFeedbackNV(GLuint id)
{
	typedef GLboolean (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsTransformFeedbackNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsTransformFeedbackNV" ); }
	return (*func_ptr)( id );
}

inline void glPauseTransformFeedbackNV(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPauseTransformFeedbackNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPauseTransformFeedbackNV" ); }
	(*func_ptr)(  );
}

inline void glResumeTransformFeedbackNV(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glResumeTransformFeedbackNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glResumeTransformFeedbackNV" ); }
	(*func_ptr)(  );
}

inline void glDrawTransformFeedbackNV(GLenum mode,  GLuint id)
{
	typedef void (*proc_type)(GLenum mode,  GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawTransformFeedbackNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawTransformFeedbackNV" ); }
	(*func_ptr)( mode, id );
}

inline void glGetPerfMonitorGroupsAMD(GLint *numGroups,  GLsizei groupsSize,  GLuint *groups)
{
	typedef void (*proc_type)(GLint *numGroups,  GLsizei groupsSize,  GLuint *groups);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPerfMonitorGroupsAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPerfMonitorGroupsAMD" ); }
	(*func_ptr)( numGroups, groupsSize, groups );
}

inline void glGetPerfMonitorCountersAMD(GLuint group,  GLint *numCounters,  GLint *maxActiveCounters,  GLsizei counterSize,  GLuint *counters)
{
	typedef void (*proc_type)(GLuint group,  GLint *numCounters,  GLint *maxActiveCounters,  GLsizei counterSize,  GLuint *counters);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPerfMonitorCountersAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPerfMonitorCountersAMD" ); }
	(*func_ptr)( group, numCounters, maxActiveCounters, counterSize, counters );
}

inline void glGetPerfMonitorGroupStringAMD(GLuint group,  GLsizei bufSize,  GLsizei *length,  GLchar *groupString)
{
	typedef void (*proc_type)(GLuint group,  GLsizei bufSize,  GLsizei *length,  GLchar *groupString);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPerfMonitorGroupStringAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPerfMonitorGroupStringAMD" ); }
	(*func_ptr)( group, bufSize, length, groupString );
}

inline void glGetPerfMonitorCounterStringAMD(GLuint group,  GLuint counter,  GLsizei bufSize,  GLsizei *length,  GLchar *counterString)
{
	typedef void (*proc_type)(GLuint group,  GLuint counter,  GLsizei bufSize,  GLsizei *length,  GLchar *counterString);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPerfMonitorCounterStringAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPerfMonitorCounterStringAMD" ); }
	(*func_ptr)( group, counter, bufSize, length, counterString );
}

inline void glGetPerfMonitorCounterInfoAMD(GLuint group,  GLuint counter,  GLenum pname,  GLvoid *data)
{
	typedef void (*proc_type)(GLuint group,  GLuint counter,  GLenum pname,  GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPerfMonitorCounterInfoAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPerfMonitorCounterInfoAMD" ); }
	(*func_ptr)( group, counter, pname, data );
}

inline void glGenPerfMonitorsAMD(GLsizei n,  GLuint *monitors)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *monitors);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenPerfMonitorsAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenPerfMonitorsAMD" ); }
	(*func_ptr)( n, monitors );
}

inline void glDeletePerfMonitorsAMD(GLsizei n,  GLuint *monitors)
{
	typedef void (*proc_type)(GLsizei n,  GLuint *monitors);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeletePerfMonitorsAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeletePerfMonitorsAMD" ); }
	(*func_ptr)( n, monitors );
}

inline void glSelectPerfMonitorCountersAMD(GLuint monitor,  GLboolean enable,  GLuint group,  GLint numCounters,  GLuint *counterList)
{
	typedef void (*proc_type)(GLuint monitor,  GLboolean enable,  GLuint group,  GLint numCounters,  GLuint *counterList);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSelectPerfMonitorCountersAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSelectPerfMonitorCountersAMD" ); }
	(*func_ptr)( monitor, enable, group, numCounters, counterList );
}

inline void glBeginPerfMonitorAMD(GLuint monitor)
{
	typedef void (*proc_type)(GLuint monitor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginPerfMonitorAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginPerfMonitorAMD" ); }
	(*func_ptr)( monitor );
}

inline void glEndPerfMonitorAMD(GLuint monitor)
{
	typedef void (*proc_type)(GLuint monitor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndPerfMonitorAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndPerfMonitorAMD" ); }
	(*func_ptr)( monitor );
}

inline void glGetPerfMonitorCounterDataAMD(GLuint monitor,  GLenum pname,  GLsizei dataSize,  GLuint *data,  GLint *bytesWritten)
{
	typedef void (*proc_type)(GLuint monitor,  GLenum pname,  GLsizei dataSize,  GLuint *data,  GLint *bytesWritten);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPerfMonitorCounterDataAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPerfMonitorCounterDataAMD" ); }
	(*func_ptr)( monitor, pname, dataSize, data, bytesWritten );
}

inline void glTessellationFactorAMD(GLfloat factor)
{
	typedef void (*proc_type)(GLfloat factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTessellationFactorAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTessellationFactorAMD" ); }
	(*func_ptr)( factor );
}

inline void glTessellationModeAMD(GLenum mode)
{
	typedef void (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTessellationModeAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTessellationModeAMD" ); }
	(*func_ptr)( mode );
}

inline void glProvokingVertexEXT(GLenum mode)
{
	typedef void (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProvokingVertexEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProvokingVertexEXT" ); }
	(*func_ptr)( mode );
}

inline void glBlendFuncIndexedAMD(GLuint buf,  GLenum src,  GLenum dst)
{
	typedef void (*proc_type)(GLuint buf,  GLenum src,  GLenum dst);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFuncIndexedAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFuncIndexedAMD" ); }
	(*func_ptr)( buf, src, dst );
}

inline void glBlendFuncSeparateIndexedAMD(GLuint buf,  GLenum srcRGB,  GLenum dstRGB,  GLenum srcAlpha,  GLenum dstAlpha)
{
	typedef void (*proc_type)(GLuint buf,  GLenum srcRGB,  GLenum dstRGB,  GLenum srcAlpha,  GLenum dstAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFuncSeparateIndexedAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFuncSeparateIndexedAMD" ); }
	(*func_ptr)( buf, srcRGB, dstRGB, srcAlpha, dstAlpha );
}

inline void glBlendEquationIndexedAMD(GLuint buf,  GLenum mode)
{
	typedef void (*proc_type)(GLuint buf,  GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationIndexedAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationIndexedAMD" ); }
	(*func_ptr)( buf, mode );
}

inline void glBlendEquationSeparateIndexedAMD(GLuint buf,  GLenum modeRGB,  GLenum modeAlpha)
{
	typedef void (*proc_type)(GLuint buf,  GLenum modeRGB,  GLenum modeAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationSeparateIndexedAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationSeparateIndexedAMD" ); }
	(*func_ptr)( buf, modeRGB, modeAlpha );
}

inline void glTextureRangeAPPLE(GLenum target,  GLsizei length,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLenum target,  GLsizei length,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureRangeAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureRangeAPPLE" ); }
	(*func_ptr)( target, length, pointer );
}

inline void glGetTexParameterPointervAPPLE(GLenum target,  GLenum pname,  GLvoid* *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLvoid* *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTexParameterPointervAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTexParameterPointervAPPLE" ); }
	(*func_ptr)( target, pname, params );
}

inline void glEnableVertexAttribAPPLE(GLuint index,  GLenum pname)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEnableVertexAttribAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEnableVertexAttribAPPLE" ); }
	(*func_ptr)( index, pname );
}

inline void glDisableVertexAttribAPPLE(GLuint index,  GLenum pname)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDisableVertexAttribAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDisableVertexAttribAPPLE" ); }
	(*func_ptr)( index, pname );
}

inline GLboolean glIsVertexAttribEnabledAPPLE(GLuint index,  GLenum pname)
{
	typedef GLboolean (*proc_type)(GLuint index,  GLenum pname);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsVertexAttribEnabledAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsVertexAttribEnabledAPPLE" ); }
	return (*func_ptr)( index, pname );
}

inline void glMapVertexAttrib1dAPPLE(GLuint index,  GLuint size,  GLdouble u1,  GLdouble u2,  GLint stride,  GLint order,  const GLdouble *points)
{
	typedef void (*proc_type)(GLuint index,  GLuint size,  GLdouble u1,  GLdouble u2,  GLint stride,  GLint order,  const GLdouble *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapVertexAttrib1dAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapVertexAttrib1dAPPLE" ); }
	(*func_ptr)( index, size, u1, u2, stride, order, points );
}

inline void glMapVertexAttrib1fAPPLE(GLuint index,  GLuint size,  GLfloat u1,  GLfloat u2,  GLint stride,  GLint order,  const GLfloat *points)
{
	typedef void (*proc_type)(GLuint index,  GLuint size,  GLfloat u1,  GLfloat u2,  GLint stride,  GLint order,  const GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapVertexAttrib1fAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapVertexAttrib1fAPPLE" ); }
	(*func_ptr)( index, size, u1, u2, stride, order, points );
}

inline void glMapVertexAttrib2dAPPLE(GLuint index,  GLuint size,  GLdouble u1,  GLdouble u2,  GLint ustride,  GLint uorder,  GLdouble v1,  GLdouble v2,  GLint vstride,  GLint vorder,  const GLdouble *points)
{
	typedef void (*proc_type)(GLuint index,  GLuint size,  GLdouble u1,  GLdouble u2,  GLint ustride,  GLint uorder,  GLdouble v1,  GLdouble v2,  GLint vstride,  GLint vorder,  const GLdouble *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapVertexAttrib2dAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapVertexAttrib2dAPPLE" ); }
	(*func_ptr)( index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points );
}

inline void glMapVertexAttrib2fAPPLE(GLuint index,  GLuint size,  GLfloat u1,  GLfloat u2,  GLint ustride,  GLint uorder,  GLfloat v1,  GLfloat v2,  GLint vstride,  GLint vorder,  const GLfloat *points)
{
	typedef void (*proc_type)(GLuint index,  GLuint size,  GLfloat u1,  GLfloat u2,  GLint ustride,  GLint uorder,  GLfloat v1,  GLfloat v2,  GLint vstride,  GLint vorder,  const GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapVertexAttrib2fAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapVertexAttrib2fAPPLE" ); }
	(*func_ptr)( index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points );
}

inline GLenum glObjectPurgeableAPPLE(GLenum objectType,  GLuint name,  GLenum option)
{
	typedef GLenum (*proc_type)(GLenum objectType,  GLuint name,  GLenum option);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glObjectPurgeableAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glObjectPurgeableAPPLE" ); }
	return (*func_ptr)( objectType, name, option );
}

inline GLenum glObjectUnpurgeableAPPLE(GLenum objectType,  GLuint name,  GLenum option)
{
	typedef GLenum (*proc_type)(GLenum objectType,  GLuint name,  GLenum option);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glObjectUnpurgeableAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glObjectUnpurgeableAPPLE" ); }
	return (*func_ptr)( objectType, name, option );
}

inline void glGetObjectParameterivAPPLE(GLenum objectType,  GLuint name,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLenum objectType,  GLuint name,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetObjectParameterivAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetObjectParameterivAPPLE" ); }
	(*func_ptr)( objectType, name, pname, params );
}

inline void glBeginVideoCaptureNV(GLuint video_capture_slot)
{
	typedef void (*proc_type)(GLuint video_capture_slot);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginVideoCaptureNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginVideoCaptureNV" ); }
	(*func_ptr)( video_capture_slot );
}

inline void glBindVideoCaptureStreamBufferNV(GLuint video_capture_slot,  GLuint stream,  GLenum frame_region,  GLintptrARB offset)
{
	typedef void (*proc_type)(GLuint video_capture_slot,  GLuint stream,  GLenum frame_region,  GLintptrARB offset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindVideoCaptureStreamBufferNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindVideoCaptureStreamBufferNV" ); }
	(*func_ptr)( video_capture_slot, stream, frame_region, offset );
}

inline void glBindVideoCaptureStreamTextureNV(GLuint video_capture_slot,  GLuint stream,  GLenum frame_region,  GLenum target,  GLuint texture)
{
	typedef void (*proc_type)(GLuint video_capture_slot,  GLuint stream,  GLenum frame_region,  GLenum target,  GLuint texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindVideoCaptureStreamTextureNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindVideoCaptureStreamTextureNV" ); }
	(*func_ptr)( video_capture_slot, stream, frame_region, target, texture );
}

inline void glEndVideoCaptureNV(GLuint video_capture_slot)
{
	typedef void (*proc_type)(GLuint video_capture_slot);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndVideoCaptureNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndVideoCaptureNV" ); }
	(*func_ptr)( video_capture_slot );
}

inline void glGetVideoCaptureivNV(GLuint video_capture_slot,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint video_capture_slot,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVideoCaptureivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVideoCaptureivNV" ); }
	(*func_ptr)( video_capture_slot, pname, params );
}

inline void glGetVideoCaptureStreamivNV(GLuint video_capture_slot,  GLuint stream,  GLenum pname,  GLint *params)
{
	typedef void (*proc_type)(GLuint video_capture_slot,  GLuint stream,  GLenum pname,  GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVideoCaptureStreamivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVideoCaptureStreamivNV" ); }
	(*func_ptr)( video_capture_slot, stream, pname, params );
}

inline void glGetVideoCaptureStreamfvNV(GLuint video_capture_slot,  GLuint stream,  GLenum pname,  GLfloat *params)
{
	typedef void (*proc_type)(GLuint video_capture_slot,  GLuint stream,  GLenum pname,  GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVideoCaptureStreamfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVideoCaptureStreamfvNV" ); }
	(*func_ptr)( video_capture_slot, stream, pname, params );
}

inline void glGetVideoCaptureStreamdvNV(GLuint video_capture_slot,  GLuint stream,  GLenum pname,  GLdouble *params)
{
	typedef void (*proc_type)(GLuint video_capture_slot,  GLuint stream,  GLenum pname,  GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVideoCaptureStreamdvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVideoCaptureStreamdvNV" ); }
	(*func_ptr)( video_capture_slot, stream, pname, params );
}

inline GLenum glVideoCaptureNV(GLuint video_capture_slot,  GLuint *sequence_num,  GLuint64EXT *capture_time)
{
	typedef GLenum (*proc_type)(GLuint video_capture_slot,  GLuint *sequence_num,  GLuint64EXT *capture_time);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVideoCaptureNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVideoCaptureNV" ); }
	return (*func_ptr)( video_capture_slot, sequence_num, capture_time );
}

inline void glVideoCaptureStreamParameterivNV(GLuint video_capture_slot,  GLuint stream,  GLenum pname,  const GLint *params)
{
	typedef void (*proc_type)(GLuint video_capture_slot,  GLuint stream,  GLenum pname,  const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVideoCaptureStreamParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVideoCaptureStreamParameterivNV" ); }
	(*func_ptr)( video_capture_slot, stream, pname, params );
}

inline void glVideoCaptureStreamParameterfvNV(GLuint video_capture_slot,  GLuint stream,  GLenum pname,  const GLfloat *params)
{
	typedef void (*proc_type)(GLuint video_capture_slot,  GLuint stream,  GLenum pname,  const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVideoCaptureStreamParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVideoCaptureStreamParameterfvNV" ); }
	(*func_ptr)( video_capture_slot, stream, pname, params );
}

inline void glVideoCaptureStreamParameterdvNV(GLuint video_capture_slot,  GLuint stream,  GLenum pname,  const GLdouble *params)
{
	typedef void (*proc_type)(GLuint video_capture_slot,  GLuint stream,  GLenum pname,  const GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVideoCaptureStreamParameterdvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVideoCaptureStreamParameterdvNV" ); }
	(*func_ptr)( video_capture_slot, stream, pname, params );
}

inline void glCopyImageSubDataNV(GLuint srcName,  GLenum srcTarget,  GLint srcLevel,  GLint srcX,  GLint srcY,  GLint srcZ,  GLuint dstName,  GLenum dstTarget,  GLint dstLevel,  GLint dstX,  GLint dstY,  GLint dstZ,  GLsizei width,  GLsizei height,  GLsizei depth)
{
	typedef void (*proc_type)(GLuint srcName,  GLenum srcTarget,  GLint srcLevel,  GLint srcX,  GLint srcY,  GLint srcZ,  GLuint dstName,  GLenum dstTarget,  GLint dstLevel,  GLint dstX,  GLint dstY,  GLint dstZ,  GLsizei width,  GLsizei height,  GLsizei depth);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyImageSubDataNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyImageSubDataNV" ); }
	(*func_ptr)( srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth );
}

inline void glUseShaderProgramEXT(GLenum type,  GLuint program)
{
	typedef void (*proc_type)(GLenum type,  GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUseShaderProgramEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUseShaderProgramEXT" ); }
	(*func_ptr)( type, program );
}

inline void glActiveProgramEXT(GLuint program)
{
	typedef void (*proc_type)(GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glActiveProgramEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glActiveProgramEXT" ); }
	(*func_ptr)( program );
}

inline GLuint glCreateShaderProgramEXT(GLenum type,  const GLchar *string)
{
	typedef GLuint (*proc_type)(GLenum type,  const GLchar *string);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCreateShaderProgramEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCreateShaderProgramEXT" ); }
	return (*func_ptr)( type, string );
}

inline void glMakeBufferResidentNV(GLenum target,  GLenum access)
{
	typedef void (*proc_type)(GLenum target,  GLenum access);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMakeBufferResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMakeBufferResidentNV" ); }
	(*func_ptr)( target, access );
}

inline void glMakeBufferNonResidentNV(GLenum target)
{
	typedef void (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMakeBufferNonResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMakeBufferNonResidentNV" ); }
	(*func_ptr)( target );
}

inline GLboolean glIsBufferResidentNV(GLenum target)
{
	typedef GLboolean (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsBufferResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsBufferResidentNV" ); }
	return (*func_ptr)( target );
}

inline void glMakeNamedBufferResidentNV(GLuint buffer,  GLenum access)
{
	typedef void (*proc_type)(GLuint buffer,  GLenum access);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMakeNamedBufferResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMakeNamedBufferResidentNV" ); }
	(*func_ptr)( buffer, access );
}

inline void glMakeNamedBufferNonResidentNV(GLuint buffer)
{
	typedef void (*proc_type)(GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMakeNamedBufferNonResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMakeNamedBufferNonResidentNV" ); }
	(*func_ptr)( buffer );
}

inline GLboolean glIsNamedBufferResidentNV(GLuint buffer)
{
	typedef GLboolean (*proc_type)(GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsNamedBufferResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsNamedBufferResidentNV" ); }
	return (*func_ptr)( buffer );
}

inline void glGetBufferParameterui64vNV(GLenum target,  GLenum pname,  GLuint64EXT *params)
{
	typedef void (*proc_type)(GLenum target,  GLenum pname,  GLuint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBufferParameterui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBufferParameterui64vNV" ); }
	(*func_ptr)( target, pname, params );
}

inline void glGetNamedBufferParameterui64vNV(GLuint buffer,  GLenum pname,  GLuint64EXT *params)
{
	typedef void (*proc_type)(GLuint buffer,  GLenum pname,  GLuint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedBufferParameterui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedBufferParameterui64vNV" ); }
	(*func_ptr)( buffer, pname, params );
}

inline void glGetIntegerui64vNV(GLenum value,  GLuint64EXT *result)
{
	typedef void (*proc_type)(GLenum value,  GLuint64EXT *result);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetIntegerui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetIntegerui64vNV" ); }
	(*func_ptr)( value, result );
}

inline void glUniformui64NV(GLint location,  GLuint64EXT value)
{
	typedef void (*proc_type)(GLint location,  GLuint64EXT value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformui64NV" ); }
	(*func_ptr)( location, value );
}

inline void glUniformui64vNV(GLint location,  GLsizei count,  const GLuint64EXT *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformui64vNV" ); }
	(*func_ptr)( location, count, value );
}

inline void glGetUniformui64vNV(GLuint program,  GLint location,  GLuint64EXT *params)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformui64vNV" ); }
	(*func_ptr)( program, location, params );
}

inline void glProgramUniformui64NV(GLuint program,  GLint location,  GLuint64EXT value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint64EXT value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformui64NV" ); }
	(*func_ptr)( program, location, value );
}

inline void glProgramUniformui64vNV(GLuint program,  GLint location,  GLsizei count,  const GLuint64EXT *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformui64vNV" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glBufferAddressRangeNV(GLenum pname,  GLuint index,  GLuint64EXT address,  GLsizeiptr length)
{
	typedef void (*proc_type)(GLenum pname,  GLuint index,  GLuint64EXT address,  GLsizeiptr length);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBufferAddressRangeNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBufferAddressRangeNV" ); }
	(*func_ptr)( pname, index, address, length );
}

inline void glVertexFormatNV(GLint size,  GLenum type,  GLsizei stride)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexFormatNV" ); }
	(*func_ptr)( size, type, stride );
}

inline void glNormalFormatNV(GLenum type,  GLsizei stride)
{
	typedef void (*proc_type)(GLenum type,  GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalFormatNV" ); }
	(*func_ptr)( type, stride );
}

inline void glColorFormatNV(GLint size,  GLenum type,  GLsizei stride)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorFormatNV" ); }
	(*func_ptr)( size, type, stride );
}

inline void glIndexFormatNV(GLenum type,  GLsizei stride)
{
	typedef void (*proc_type)(GLenum type,  GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIndexFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIndexFormatNV" ); }
	(*func_ptr)( type, stride );
}

inline void glTexCoordFormatNV(GLint size,  GLenum type,  GLsizei stride)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordFormatNV" ); }
	(*func_ptr)( size, type, stride );
}

inline void glEdgeFlagFormatNV(GLsizei stride)
{
	typedef void (*proc_type)(GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEdgeFlagFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEdgeFlagFormatNV" ); }
	(*func_ptr)( stride );
}

inline void glSecondaryColorFormatNV(GLint size,  GLenum type,  GLsizei stride)
{
	typedef void (*proc_type)(GLint size,  GLenum type,  GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColorFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColorFormatNV" ); }
	(*func_ptr)( size, type, stride );
}

inline void glFogCoordFormatNV(GLenum type,  GLsizei stride)
{
	typedef void (*proc_type)(GLenum type,  GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordFormatNV" ); }
	(*func_ptr)( type, stride );
}

inline void glVertexAttribFormatNV(GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride)
{
	typedef void (*proc_type)(GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribFormatNV" ); }
	(*func_ptr)( index, size, type, normalized, stride );
}

inline void glVertexAttribIFormatNV(GLuint index,  GLint size,  GLenum type,  GLsizei stride)
{
	typedef void (*proc_type)(GLuint index,  GLint size,  GLenum type,  GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribIFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribIFormatNV" ); }
	(*func_ptr)( index, size, type, stride );
}

inline void glGetIntegerui64i_vNV(GLenum value,  GLuint index,  GLuint64EXT *result)
{
	typedef void (*proc_type)(GLenum value,  GLuint index,  GLuint64EXT *result);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetIntegerui64i_vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetIntegerui64i_vNV" ); }
	(*func_ptr)( value, index, result );
}

inline void glTextureBarrierNV(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureBarrierNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureBarrierNV" ); }
	(*func_ptr)(  );
}

inline void glBindImageTextureEXT(GLuint index,  GLuint texture,  GLint level,  GLboolean layered,  GLint layer,  GLenum access,  GLint format)
{
	typedef void (*proc_type)(GLuint index,  GLuint texture,  GLint level,  GLboolean layered,  GLint layer,  GLenum access,  GLint format);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindImageTextureEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindImageTextureEXT" ); }
	(*func_ptr)( index, texture, level, layered, layer, access, format );
}

inline void glMemoryBarrierEXT(GLbitfield barriers)
{
	typedef void (*proc_type)(GLbitfield barriers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMemoryBarrierEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMemoryBarrierEXT" ); }
	(*func_ptr)( barriers );
}

inline void glVertexAttribL1dEXT(GLuint index,  GLdouble x)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL1dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL1dEXT" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttribL2dEXT(GLuint index,  GLdouble x,  GLdouble y)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x,  GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL2dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL2dEXT" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttribL3dEXT(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL3dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL3dEXT" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttribL4dEXT(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w)
{
	typedef void (*proc_type)(GLuint index,  GLdouble x,  GLdouble y,  GLdouble z,  GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL4dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL4dEXT" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttribL1dvEXT(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL1dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL1dvEXT" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribL2dvEXT(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL2dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL2dvEXT" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribL3dvEXT(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL3dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL3dvEXT" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribL4dvEXT(GLuint index,  const GLdouble *v)
{
	typedef void (*proc_type)(GLuint index,  const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL4dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL4dvEXT" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribLPointerEXT(GLuint index,  GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer)
{
	typedef void (*proc_type)(GLuint index,  GLint size,  GLenum type,  GLsizei stride,  const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribLPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribLPointerEXT" ); }
	(*func_ptr)( index, size, type, stride, pointer );
}

inline void glGetVertexAttribLdvEXT(GLuint index,  GLenum pname,  GLdouble *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribLdvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribLdvEXT" ); }
	(*func_ptr)( index, pname, params );
}

inline void glVertexArrayVertexAttribLOffsetEXT(GLuint vaobj,  GLuint buffer,  GLuint index,  GLint size,  GLenum type,  GLsizei stride,  GLintptr offset)
{
	typedef void (*proc_type)(GLuint vaobj,  GLuint buffer,  GLuint index,  GLint size,  GLenum type,  GLsizei stride,  GLintptr offset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexArrayVertexAttribLOffsetEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexArrayVertexAttribLOffsetEXT" ); }
	(*func_ptr)( vaobj, buffer, index, size, type, stride, offset );
}

inline void glProgramSubroutineParametersuivNV(GLenum target,  GLsizei count,  const GLuint *params)
{
	typedef void (*proc_type)(GLenum target,  GLsizei count,  const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramSubroutineParametersuivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramSubroutineParametersuivNV" ); }
	(*func_ptr)( target, count, params );
}

inline void glGetProgramSubroutineParameteruivNV(GLenum target,  GLuint index,  GLuint *param)
{
	typedef void (*proc_type)(GLenum target,  GLuint index,  GLuint *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramSubroutineParameteruivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramSubroutineParameteruivNV" ); }
	(*func_ptr)( target, index, param );
}

inline void glUniform1i64NV(GLint location,  GLint64EXT x)
{
	typedef void (*proc_type)(GLint location,  GLint64EXT x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1i64NV" ); }
	(*func_ptr)( location, x );
}

inline void glUniform2i64NV(GLint location,  GLint64EXT x,  GLint64EXT y)
{
	typedef void (*proc_type)(GLint location,  GLint64EXT x,  GLint64EXT y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2i64NV" ); }
	(*func_ptr)( location, x, y );
}

inline void glUniform3i64NV(GLint location,  GLint64EXT x,  GLint64EXT y,  GLint64EXT z)
{
	typedef void (*proc_type)(GLint location,  GLint64EXT x,  GLint64EXT y,  GLint64EXT z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3i64NV" ); }
	(*func_ptr)( location, x, y, z );
}

inline void glUniform4i64NV(GLint location,  GLint64EXT x,  GLint64EXT y,  GLint64EXT z,  GLint64EXT w)
{
	typedef void (*proc_type)(GLint location,  GLint64EXT x,  GLint64EXT y,  GLint64EXT z,  GLint64EXT w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4i64NV" ); }
	(*func_ptr)( location, x, y, z, w );
}

inline void glUniform1i64vNV(GLint location,  GLsizei count,  const GLint64EXT *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1i64vNV" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform2i64vNV(GLint location,  GLsizei count,  const GLint64EXT *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2i64vNV" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform3i64vNV(GLint location,  GLsizei count,  const GLint64EXT *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3i64vNV" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform4i64vNV(GLint location,  GLsizei count,  const GLint64EXT *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4i64vNV" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform1ui64NV(GLint location,  GLuint64EXT x)
{
	typedef void (*proc_type)(GLint location,  GLuint64EXT x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1ui64NV" ); }
	(*func_ptr)( location, x );
}

inline void glUniform2ui64NV(GLint location,  GLuint64EXT x,  GLuint64EXT y)
{
	typedef void (*proc_type)(GLint location,  GLuint64EXT x,  GLuint64EXT y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2ui64NV" ); }
	(*func_ptr)( location, x, y );
}

inline void glUniform3ui64NV(GLint location,  GLuint64EXT x,  GLuint64EXT y,  GLuint64EXT z)
{
	typedef void (*proc_type)(GLint location,  GLuint64EXT x,  GLuint64EXT y,  GLuint64EXT z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3ui64NV" ); }
	(*func_ptr)( location, x, y, z );
}

inline void glUniform4ui64NV(GLint location,  GLuint64EXT x,  GLuint64EXT y,  GLuint64EXT z,  GLuint64EXT w)
{
	typedef void (*proc_type)(GLint location,  GLuint64EXT x,  GLuint64EXT y,  GLuint64EXT z,  GLuint64EXT w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4ui64NV" ); }
	(*func_ptr)( location, x, y, z, w );
}

inline void glUniform1ui64vNV(GLint location,  GLsizei count,  const GLuint64EXT *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1ui64vNV" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform2ui64vNV(GLint location,  GLsizei count,  const GLuint64EXT *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2ui64vNV" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform3ui64vNV(GLint location,  GLsizei count,  const GLuint64EXT *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3ui64vNV" ); }
	(*func_ptr)( location, count, value );
}

inline void glUniform4ui64vNV(GLint location,  GLsizei count,  const GLuint64EXT *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4ui64vNV" ); }
	(*func_ptr)( location, count, value );
}

inline void glGetUniformi64vNV(GLuint program,  GLint location,  GLint64EXT *params)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformi64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformi64vNV" ); }
	(*func_ptr)( program, location, params );
}

inline void glProgramUniform1i64NV(GLuint program,  GLint location,  GLint64EXT x)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLint64EXT x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1i64NV" ); }
	(*func_ptr)( program, location, x );
}

inline void glProgramUniform2i64NV(GLuint program,  GLint location,  GLint64EXT x,  GLint64EXT y)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLint64EXT x,  GLint64EXT y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2i64NV" ); }
	(*func_ptr)( program, location, x, y );
}

inline void glProgramUniform3i64NV(GLuint program,  GLint location,  GLint64EXT x,  GLint64EXT y,  GLint64EXT z)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLint64EXT x,  GLint64EXT y,  GLint64EXT z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3i64NV" ); }
	(*func_ptr)( program, location, x, y, z );
}

inline void glProgramUniform4i64NV(GLuint program,  GLint location,  GLint64EXT x,  GLint64EXT y,  GLint64EXT z,  GLint64EXT w)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLint64EXT x,  GLint64EXT y,  GLint64EXT z,  GLint64EXT w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4i64NV" ); }
	(*func_ptr)( program, location, x, y, z, w );
}

inline void glProgramUniform1i64vNV(GLuint program,  GLint location,  GLsizei count,  const GLint64EXT *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1i64vNV" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform2i64vNV(GLuint program,  GLint location,  GLsizei count,  const GLint64EXT *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2i64vNV" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform3i64vNV(GLuint program,  GLint location,  GLsizei count,  const GLint64EXT *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3i64vNV" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform4i64vNV(GLuint program,  GLint location,  GLsizei count,  const GLint64EXT *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4i64vNV" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform1ui64NV(GLuint program,  GLint location,  GLuint64EXT x)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint64EXT x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1ui64NV" ); }
	(*func_ptr)( program, location, x );
}

inline void glProgramUniform2ui64NV(GLuint program,  GLint location,  GLuint64EXT x,  GLuint64EXT y)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint64EXT x,  GLuint64EXT y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2ui64NV" ); }
	(*func_ptr)( program, location, x, y );
}

inline void glProgramUniform3ui64NV(GLuint program,  GLint location,  GLuint64EXT x,  GLuint64EXT y,  GLuint64EXT z)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint64EXT x,  GLuint64EXT y,  GLuint64EXT z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3ui64NV" ); }
	(*func_ptr)( program, location, x, y, z );
}

inline void glProgramUniform4ui64NV(GLuint program,  GLint location,  GLuint64EXT x,  GLuint64EXT y,  GLuint64EXT z,  GLuint64EXT w)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint64EXT x,  GLuint64EXT y,  GLuint64EXT z,  GLuint64EXT w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4ui64NV" ); }
	(*func_ptr)( program, location, x, y, z, w );
}

inline void glProgramUniform1ui64vNV(GLuint program,  GLint location,  GLsizei count,  const GLuint64EXT *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1ui64vNV" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform2ui64vNV(GLuint program,  GLint location,  GLsizei count,  const GLuint64EXT *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2ui64vNV" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform3ui64vNV(GLuint program,  GLint location,  GLsizei count,  const GLuint64EXT *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3ui64vNV" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glProgramUniform4ui64vNV(GLuint program,  GLint location,  GLsizei count,  const GLuint64EXT *value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4ui64vNV" ); }
	(*func_ptr)( program, location, count, value );
}

inline void glVertexAttribL1i64NV(GLuint index,  GLint64EXT x)
{
	typedef void (*proc_type)(GLuint index,  GLint64EXT x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL1i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL1i64NV" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttribL2i64NV(GLuint index,  GLint64EXT x,  GLint64EXT y)
{
	typedef void (*proc_type)(GLuint index,  GLint64EXT x,  GLint64EXT y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL2i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL2i64NV" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttribL3i64NV(GLuint index,  GLint64EXT x,  GLint64EXT y,  GLint64EXT z)
{
	typedef void (*proc_type)(GLuint index,  GLint64EXT x,  GLint64EXT y,  GLint64EXT z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL3i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL3i64NV" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttribL4i64NV(GLuint index,  GLint64EXT x,  GLint64EXT y,  GLint64EXT z,  GLint64EXT w)
{
	typedef void (*proc_type)(GLuint index,  GLint64EXT x,  GLint64EXT y,  GLint64EXT z,  GLint64EXT w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL4i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL4i64NV" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttribL1i64vNV(GLuint index,  const GLint64EXT *v)
{
	typedef void (*proc_type)(GLuint index,  const GLint64EXT *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL1i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL1i64vNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribL2i64vNV(GLuint index,  const GLint64EXT *v)
{
	typedef void (*proc_type)(GLuint index,  const GLint64EXT *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL2i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL2i64vNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribL3i64vNV(GLuint index,  const GLint64EXT *v)
{
	typedef void (*proc_type)(GLuint index,  const GLint64EXT *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL3i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL3i64vNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribL4i64vNV(GLuint index,  const GLint64EXT *v)
{
	typedef void (*proc_type)(GLuint index,  const GLint64EXT *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL4i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL4i64vNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribL1ui64NV(GLuint index,  GLuint64EXT x)
{
	typedef void (*proc_type)(GLuint index,  GLuint64EXT x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL1ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL1ui64NV" ); }
	(*func_ptr)( index, x );
}

inline void glVertexAttribL2ui64NV(GLuint index,  GLuint64EXT x,  GLuint64EXT y)
{
	typedef void (*proc_type)(GLuint index,  GLuint64EXT x,  GLuint64EXT y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL2ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL2ui64NV" ); }
	(*func_ptr)( index, x, y );
}

inline void glVertexAttribL3ui64NV(GLuint index,  GLuint64EXT x,  GLuint64EXT y,  GLuint64EXT z)
{
	typedef void (*proc_type)(GLuint index,  GLuint64EXT x,  GLuint64EXT y,  GLuint64EXT z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL3ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL3ui64NV" ); }
	(*func_ptr)( index, x, y, z );
}

inline void glVertexAttribL4ui64NV(GLuint index,  GLuint64EXT x,  GLuint64EXT y,  GLuint64EXT z,  GLuint64EXT w)
{
	typedef void (*proc_type)(GLuint index,  GLuint64EXT x,  GLuint64EXT y,  GLuint64EXT z,  GLuint64EXT w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL4ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL4ui64NV" ); }
	(*func_ptr)( index, x, y, z, w );
}

inline void glVertexAttribL1ui64vNV(GLuint index,  const GLuint64EXT *v)
{
	typedef void (*proc_type)(GLuint index,  const GLuint64EXT *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL1ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL1ui64vNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribL2ui64vNV(GLuint index,  const GLuint64EXT *v)
{
	typedef void (*proc_type)(GLuint index,  const GLuint64EXT *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL2ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL2ui64vNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribL3ui64vNV(GLuint index,  const GLuint64EXT *v)
{
	typedef void (*proc_type)(GLuint index,  const GLuint64EXT *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL3ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL3ui64vNV" ); }
	(*func_ptr)( index, v );
}

inline void glVertexAttribL4ui64vNV(GLuint index,  const GLuint64EXT *v)
{
	typedef void (*proc_type)(GLuint index,  const GLuint64EXT *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL4ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL4ui64vNV" ); }
	(*func_ptr)( index, v );
}

inline void glGetVertexAttribLi64vNV(GLuint index,  GLenum pname,  GLint64EXT *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribLi64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribLi64vNV" ); }
	(*func_ptr)( index, pname, params );
}

inline void glGetVertexAttribLui64vNV(GLuint index,  GLenum pname,  GLuint64EXT *params)
{
	typedef void (*proc_type)(GLuint index,  GLenum pname,  GLuint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribLui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribLui64vNV" ); }
	(*func_ptr)( index, pname, params );
}

inline void glVertexAttribLFormatNV(GLuint index,  GLint size,  GLenum type,  GLsizei stride)
{
	typedef void (*proc_type)(GLuint index,  GLint size,  GLenum type,  GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribLFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribLFormatNV" ); }
	(*func_ptr)( index, size, type, stride );
}

inline void glGenNamesAMD(GLenum identifier,  GLuint num,  GLuint *names)
{
	typedef void (*proc_type)(GLenum identifier,  GLuint num,  GLuint *names);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenNamesAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenNamesAMD" ); }
	(*func_ptr)( identifier, num, names );
}

inline void glDeleteNamesAMD(GLenum identifier,  GLuint num,  const GLuint *names)
{
	typedef void (*proc_type)(GLenum identifier,  GLuint num,  const GLuint *names);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteNamesAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteNamesAMD" ); }
	(*func_ptr)( identifier, num, names );
}

inline GLboolean glIsNameAMD(GLenum identifier,  GLuint name)
{
	typedef GLboolean (*proc_type)(GLenum identifier,  GLuint name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsNameAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsNameAMD" ); }
	return (*func_ptr)( identifier, name );
}

inline void glDebugMessageEnableAMD(GLenum category,  GLenum severity,  GLsizei count,  const GLuint *ids,  GLboolean enabled)
{
	typedef void (*proc_type)(GLenum category,  GLenum severity,  GLsizei count,  const GLuint *ids,  GLboolean enabled);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDebugMessageEnableAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDebugMessageEnableAMD" ); }
	(*func_ptr)( category, severity, count, ids, enabled );
}

inline void glDebugMessageInsertAMD(GLenum category,  GLenum severity,  GLuint id,  GLsizei length,  const GLchar *buf)
{
	typedef void (*proc_type)(GLenum category,  GLenum severity,  GLuint id,  GLsizei length,  const GLchar *buf);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDebugMessageInsertAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDebugMessageInsertAMD" ); }
	(*func_ptr)( category, severity, id, length, buf );
}

inline void glDebugMessageCallbackAMD(GLDEBUGPROCAMD callback,  GLvoid *userParam)
{
	typedef void (*proc_type)(GLDEBUGPROCAMD callback,  GLvoid *userParam);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDebugMessageCallbackAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDebugMessageCallbackAMD" ); }
	(*func_ptr)( callback, userParam );
}

inline GLuint glGetDebugMessageLogAMD(GLuint count,  GLsizei bufsize,  GLenum *categories,  GLuint *severities,  GLuint *ids,  GLsizei *lengths,  GLchar *message)
{
	typedef GLuint (*proc_type)(GLuint count,  GLsizei bufsize,  GLenum *categories,  GLuint *severities,  GLuint *ids,  GLsizei *lengths,  GLchar *message);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetDebugMessageLogAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetDebugMessageLogAMD" ); }
	return (*func_ptr)( count, bufsize, categories, severities, ids, lengths, message );
}

inline void glVDPAUInitNV(const GLvoid *vdpDevice,  const GLvoid *getProcAddress)
{
	typedef void (*proc_type)(const GLvoid *vdpDevice,  const GLvoid *getProcAddress);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAUInitNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAUInitNV" ); }
	(*func_ptr)( vdpDevice, getProcAddress );
}

inline void glVDPAUFiniNV(void)
{
	typedef void (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAUFiniNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAUFiniNV" ); }
	(*func_ptr)(  );
}

inline GLvdpauSurfaceNV glVDPAURegisterVideoSurfaceNV(GLvoid *vdpSurface,  GLenum target,  GLsizei numTextureNames,  const GLuint *textureNames)
{
	typedef GLvdpauSurfaceNV (*proc_type)(GLvoid *vdpSurface,  GLenum target,  GLsizei numTextureNames,  const GLuint *textureNames);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAURegisterVideoSurfaceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAURegisterVideoSurfaceNV" ); }
	return (*func_ptr)( vdpSurface, target, numTextureNames, textureNames );
}

inline GLvdpauSurfaceNV glVDPAURegisterOutputSurfaceNV(GLvoid *vdpSurface,  GLenum target,  GLsizei numTextureNames,  const GLuint *textureNames)
{
	typedef GLvdpauSurfaceNV (*proc_type)(GLvoid *vdpSurface,  GLenum target,  GLsizei numTextureNames,  const GLuint *textureNames);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAURegisterOutputSurfaceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAURegisterOutputSurfaceNV" ); }
	return (*func_ptr)( vdpSurface, target, numTextureNames, textureNames );
}

inline void glVDPAUIsSurfaceNV(GLvdpauSurfaceNV surface)
{
	typedef void (*proc_type)(GLvdpauSurfaceNV surface);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAUIsSurfaceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAUIsSurfaceNV" ); }
	(*func_ptr)( surface );
}

inline void glVDPAUUnregisterSurfaceNV(GLvdpauSurfaceNV surface)
{
	typedef void (*proc_type)(GLvdpauSurfaceNV surface);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAUUnregisterSurfaceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAUUnregisterSurfaceNV" ); }
	(*func_ptr)( surface );
}

inline void glVDPAUGetSurfaceivNV(GLvdpauSurfaceNV surface,  GLenum pname,  GLsizei bufSize,  GLsizei *length,  GLint *values)
{
	typedef void (*proc_type)(GLvdpauSurfaceNV surface,  GLenum pname,  GLsizei bufSize,  GLsizei *length,  GLint *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAUGetSurfaceivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAUGetSurfaceivNV" ); }
	(*func_ptr)( surface, pname, bufSize, length, values );
}

inline void glVDPAUSurfaceAccessNV(GLvdpauSurfaceNV surface,  GLenum access)
{
	typedef void (*proc_type)(GLvdpauSurfaceNV surface,  GLenum access);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAUSurfaceAccessNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAUSurfaceAccessNV" ); }
	(*func_ptr)( surface, access );
}

inline void glVDPAUMapSurfacesNV(GLsizei numSurfaces,  const GLvdpauSurfaceNV *surfaces)
{
	typedef void (*proc_type)(GLsizei numSurfaces,  const GLvdpauSurfaceNV *surfaces);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAUMapSurfacesNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAUMapSurfacesNV" ); }
	(*func_ptr)( numSurfaces, surfaces );
}

inline void glVDPAUUnmapSurfacesNV(GLsizei numSurface,  const GLvdpauSurfaceNV *surfaces)
{
	typedef void (*proc_type)(GLsizei numSurface,  const GLvdpauSurfaceNV *surfaces);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAUUnmapSurfacesNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAUUnmapSurfacesNV" ); }
	(*func_ptr)( numSurface, surfaces );
}

inline void glTexImage2DMultisampleCoverageNV(GLenum target,  GLsizei coverageSamples,  GLsizei colorSamples,  GLint internalFormat,  GLsizei width,  GLsizei height,  GLboolean fixedSampleLocations)
{
	typedef void (*proc_type)(GLenum target,  GLsizei coverageSamples,  GLsizei colorSamples,  GLint internalFormat,  GLsizei width,  GLsizei height,  GLboolean fixedSampleLocations);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexImage2DMultisampleCoverageNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexImage2DMultisampleCoverageNV" ); }
	(*func_ptr)( target, coverageSamples, colorSamples, internalFormat, width, height, fixedSampleLocations );
}

inline void glTexImage3DMultisampleCoverageNV(GLenum target,  GLsizei coverageSamples,  GLsizei colorSamples,  GLint internalFormat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLboolean fixedSampleLocations)
{
	typedef void (*proc_type)(GLenum target,  GLsizei coverageSamples,  GLsizei colorSamples,  GLint internalFormat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLboolean fixedSampleLocations);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexImage3DMultisampleCoverageNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexImage3DMultisampleCoverageNV" ); }
	(*func_ptr)( target, coverageSamples, colorSamples, internalFormat, width, height, depth, fixedSampleLocations );
}

inline void glTextureImage2DMultisampleNV(GLuint texture,  GLenum target,  GLsizei samples,  GLint internalFormat,  GLsizei width,  GLsizei height,  GLboolean fixedSampleLocations)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLsizei samples,  GLint internalFormat,  GLsizei width,  GLsizei height,  GLboolean fixedSampleLocations);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureImage2DMultisampleNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureImage2DMultisampleNV" ); }
	(*func_ptr)( texture, target, samples, internalFormat, width, height, fixedSampleLocations );
}

inline void glTextureImage3DMultisampleNV(GLuint texture,  GLenum target,  GLsizei samples,  GLint internalFormat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLboolean fixedSampleLocations)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLsizei samples,  GLint internalFormat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLboolean fixedSampleLocations);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureImage3DMultisampleNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureImage3DMultisampleNV" ); }
	(*func_ptr)( texture, target, samples, internalFormat, width, height, depth, fixedSampleLocations );
}

inline void glTextureImage2DMultisampleCoverageNV(GLuint texture,  GLenum target,  GLsizei coverageSamples,  GLsizei colorSamples,  GLint internalFormat,  GLsizei width,  GLsizei height,  GLboolean fixedSampleLocations)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLsizei coverageSamples,  GLsizei colorSamples,  GLint internalFormat,  GLsizei width,  GLsizei height,  GLboolean fixedSampleLocations);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureImage2DMultisampleCoverageNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureImage2DMultisampleCoverageNV" ); }
	(*func_ptr)( texture, target, coverageSamples, colorSamples, internalFormat, width, height, fixedSampleLocations );
}

inline void glTextureImage3DMultisampleCoverageNV(GLuint texture,  GLenum target,  GLsizei coverageSamples,  GLsizei colorSamples,  GLint internalFormat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLboolean fixedSampleLocations)
{
	typedef void (*proc_type)(GLuint texture,  GLenum target,  GLsizei coverageSamples,  GLsizei colorSamples,  GLint internalFormat,  GLsizei width,  GLsizei height,  GLsizei depth,  GLboolean fixedSampleLocations);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureImage3DMultisampleCoverageNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureImage3DMultisampleCoverageNV" ); }
	(*func_ptr)( texture, target, coverageSamples, colorSamples, internalFormat, width, height, depth, fixedSampleLocations );
}

inline void glSetMultisamplefvAMD(GLenum pname,  GLuint index,  const GLfloat *val)
{
	typedef void (*proc_type)(GLenum pname,  GLuint index,  const GLfloat *val);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSetMultisamplefvAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSetMultisamplefvAMD" ); }
	(*func_ptr)( pname, index, val );
}

inline GLsync glImportSyncEXT(GLenum external_sync_type,  GLintptr external_sync,  GLbitfield flags)
{
	typedef GLsync (*proc_type)(GLenum external_sync_type,  GLintptr external_sync,  GLbitfield flags);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glImportSyncEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glImportSyncEXT" ); }
	return (*func_ptr)( external_sync_type, external_sync, flags );
}

inline void glMultiDrawArraysIndirectAMD(GLenum mode,  const GLvoid *indirect,  GLsizei primcount,  GLsizei stride)
{
	typedef void (*proc_type)(GLenum mode,  const GLvoid *indirect,  GLsizei primcount,  GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawArraysIndirectAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawArraysIndirectAMD" ); }
	(*func_ptr)( mode, indirect, primcount, stride );
}

inline void glMultiDrawElementsIndirectAMD(GLenum mode,  GLenum type,  const GLvoid *indirect,  GLsizei primcount,  GLsizei stride)
{
	typedef void (*proc_type)(GLenum mode,  GLenum type,  const GLvoid *indirect,  GLsizei primcount,  GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawElementsIndirectAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawElementsIndirectAMD" ); }
	(*func_ptr)( mode, type, indirect, primcount, stride );
}

inline GLuint glGenPathsNV(GLsizei range)
{
	typedef GLuint (*proc_type)(GLsizei range);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenPathsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenPathsNV" ); }
	return (*func_ptr)( range );
}

inline void glDeletePathsNV(GLuint path,  GLsizei range)
{
	typedef void (*proc_type)(GLuint path,  GLsizei range);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeletePathsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeletePathsNV" ); }
	(*func_ptr)( path, range );
}

inline GLboolean glIsPathNV(GLuint path)
{
	typedef GLboolean (*proc_type)(GLuint path);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsPathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsPathNV" ); }
	return (*func_ptr)( path );
}

inline void glPathCommandsNV(GLuint path,  GLsizei numCommands,  const GLubyte *commands,  GLsizei numCoords,  GLenum coordType,  const GLvoid *coords)
{
	typedef void (*proc_type)(GLuint path,  GLsizei numCommands,  const GLubyte *commands,  GLsizei numCoords,  GLenum coordType,  const GLvoid *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathCommandsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathCommandsNV" ); }
	(*func_ptr)( path, numCommands, commands, numCoords, coordType, coords );
}

inline void glPathCoordsNV(GLuint path,  GLsizei numCoords,  GLenum coordType,  const GLvoid *coords)
{
	typedef void (*proc_type)(GLuint path,  GLsizei numCoords,  GLenum coordType,  const GLvoid *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathCoordsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathCoordsNV" ); }
	(*func_ptr)( path, numCoords, coordType, coords );
}

inline void glPathSubCommandsNV(GLuint path,  GLsizei commandStart,  GLsizei commandsToDelete,  GLsizei numCommands,  const GLubyte *commands,  GLsizei numCoords,  GLenum coordType,  const GLvoid *coords)
{
	typedef void (*proc_type)(GLuint path,  GLsizei commandStart,  GLsizei commandsToDelete,  GLsizei numCommands,  const GLubyte *commands,  GLsizei numCoords,  GLenum coordType,  const GLvoid *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathSubCommandsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathSubCommandsNV" ); }
	(*func_ptr)( path, commandStart, commandsToDelete, numCommands, commands, numCoords, coordType, coords );
}

inline void glPathSubCoordsNV(GLuint path,  GLsizei coordStart,  GLsizei numCoords,  GLenum coordType,  const GLvoid *coords)
{
	typedef void (*proc_type)(GLuint path,  GLsizei coordStart,  GLsizei numCoords,  GLenum coordType,  const GLvoid *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathSubCoordsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathSubCoordsNV" ); }
	(*func_ptr)( path, coordStart, numCoords, coordType, coords );
}

inline void glPathStringNV(GLuint path,  GLenum format,  GLsizei length,  const GLvoid *pathString)
{
	typedef void (*proc_type)(GLuint path,  GLenum format,  GLsizei length,  const GLvoid *pathString);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathStringNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathStringNV" ); }
	(*func_ptr)( path, format, length, pathString );
}

inline void glPathGlyphsNV(GLuint firstPathName,  GLenum fontTarget,  const GLvoid *fontName,  GLbitfield fontStyle,  GLsizei numGlyphs,  GLenum type,  const GLvoid *charcodes,  GLenum handleMissingGlyphs,  GLuint pathParameterTemplate,  GLfloat emScale)
{
	typedef void (*proc_type)(GLuint firstPathName,  GLenum fontTarget,  const GLvoid *fontName,  GLbitfield fontStyle,  GLsizei numGlyphs,  GLenum type,  const GLvoid *charcodes,  GLenum handleMissingGlyphs,  GLuint pathParameterTemplate,  GLfloat emScale);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathGlyphsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathGlyphsNV" ); }
	(*func_ptr)( firstPathName, fontTarget, fontName, fontStyle, numGlyphs, type, charcodes, handleMissingGlyphs, pathParameterTemplate, emScale );
}

inline void glPathGlyphRangeNV(GLuint firstPathName,  GLenum fontTarget,  const GLvoid *fontName,  GLbitfield fontStyle,  GLuint firstGlyph,  GLsizei numGlyphs,  GLenum handleMissingGlyphs,  GLuint pathParameterTemplate,  GLfloat emScale)
{
	typedef void (*proc_type)(GLuint firstPathName,  GLenum fontTarget,  const GLvoid *fontName,  GLbitfield fontStyle,  GLuint firstGlyph,  GLsizei numGlyphs,  GLenum handleMissingGlyphs,  GLuint pathParameterTemplate,  GLfloat emScale);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathGlyphRangeNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathGlyphRangeNV" ); }
	(*func_ptr)( firstPathName, fontTarget, fontName, fontStyle, firstGlyph, numGlyphs, handleMissingGlyphs, pathParameterTemplate, emScale );
}

inline void glWeightPathsNV(GLuint resultPath,  GLsizei numPaths,  const GLuint *paths,  const GLfloat *weights)
{
	typedef void (*proc_type)(GLuint resultPath,  GLsizei numPaths,  const GLuint *paths,  const GLfloat *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightPathsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightPathsNV" ); }
	(*func_ptr)( resultPath, numPaths, paths, weights );
}

inline void glCopyPathNV(GLuint resultPath,  GLuint srcPath)
{
	typedef void (*proc_type)(GLuint resultPath,  GLuint srcPath);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyPathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyPathNV" ); }
	(*func_ptr)( resultPath, srcPath );
}

inline void glInterpolatePathsNV(GLuint resultPath,  GLuint pathA,  GLuint pathB,  GLfloat weight)
{
	typedef void (*proc_type)(GLuint resultPath,  GLuint pathA,  GLuint pathB,  GLfloat weight);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glInterpolatePathsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glInterpolatePathsNV" ); }
	(*func_ptr)( resultPath, pathA, pathB, weight );
}

inline void glTransformPathNV(GLuint resultPath,  GLuint srcPath,  GLenum transformType,  const GLfloat *transformValues)
{
	typedef void (*proc_type)(GLuint resultPath,  GLuint srcPath,  GLenum transformType,  const GLfloat *transformValues);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTransformPathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTransformPathNV" ); }
	(*func_ptr)( resultPath, srcPath, transformType, transformValues );
}

inline void glPathParameterivNV(GLuint path,  GLenum pname,  const GLint *value)
{
	typedef void (*proc_type)(GLuint path,  GLenum pname,  const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathParameterivNV" ); }
	(*func_ptr)( path, pname, value );
}

inline void glPathParameteriNV(GLuint path,  GLenum pname,  GLint value)
{
	typedef void (*proc_type)(GLuint path,  GLenum pname,  GLint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathParameteriNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathParameteriNV" ); }
	(*func_ptr)( path, pname, value );
}

inline void glPathParameterfvNV(GLuint path,  GLenum pname,  const GLfloat *value)
{
	typedef void (*proc_type)(GLuint path,  GLenum pname,  const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathParameterfvNV" ); }
	(*func_ptr)( path, pname, value );
}

inline void glPathParameterfNV(GLuint path,  GLenum pname,  GLfloat value)
{
	typedef void (*proc_type)(GLuint path,  GLenum pname,  GLfloat value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathParameterfNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathParameterfNV" ); }
	(*func_ptr)( path, pname, value );
}

inline void glPathDashArrayNV(GLuint path,  GLsizei dashCount,  const GLfloat *dashArray)
{
	typedef void (*proc_type)(GLuint path,  GLsizei dashCount,  const GLfloat *dashArray);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathDashArrayNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathDashArrayNV" ); }
	(*func_ptr)( path, dashCount, dashArray );
}

inline void glPathStencilFuncNV(GLenum func,  GLint ref,  GLuint mask)
{
	typedef void (*proc_type)(GLenum func,  GLint ref,  GLuint mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathStencilFuncNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathStencilFuncNV" ); }
	(*func_ptr)( func, ref, mask );
}

inline void glPathStencilDepthOffsetNV(GLfloat factor,  GLfloat units)
{
	typedef void (*proc_type)(GLfloat factor,  GLfloat units);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathStencilDepthOffsetNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathStencilDepthOffsetNV" ); }
	(*func_ptr)( factor, units );
}

inline void glStencilFillPathNV(GLuint path,  GLenum fillMode,  GLuint mask)
{
	typedef void (*proc_type)(GLuint path,  GLenum fillMode,  GLuint mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilFillPathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilFillPathNV" ); }
	(*func_ptr)( path, fillMode, mask );
}

inline void glStencilStrokePathNV(GLuint path,  GLint reference,  GLuint mask)
{
	typedef void (*proc_type)(GLuint path,  GLint reference,  GLuint mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilStrokePathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilStrokePathNV" ); }
	(*func_ptr)( path, reference, mask );
}

inline void glStencilFillPathInstancedNV(GLsizei numPaths,  GLenum pathNameType,  const GLvoid *paths,  GLuint pathBase,  GLenum fillMode,  GLuint mask,  GLenum transformType,  const GLfloat *transformValues)
{
	typedef void (*proc_type)(GLsizei numPaths,  GLenum pathNameType,  const GLvoid *paths,  GLuint pathBase,  GLenum fillMode,  GLuint mask,  GLenum transformType,  const GLfloat *transformValues);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilFillPathInstancedNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilFillPathInstancedNV" ); }
	(*func_ptr)( numPaths, pathNameType, paths, pathBase, fillMode, mask, transformType, transformValues );
}

inline void glStencilStrokePathInstancedNV(GLsizei numPaths,  GLenum pathNameType,  const GLvoid *paths,  GLuint pathBase,  GLint reference,  GLuint mask,  GLenum transformType,  const GLfloat *transformValues)
{
	typedef void (*proc_type)(GLsizei numPaths,  GLenum pathNameType,  const GLvoid *paths,  GLuint pathBase,  GLint reference,  GLuint mask,  GLenum transformType,  const GLfloat *transformValues);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilStrokePathInstancedNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilStrokePathInstancedNV" ); }
	(*func_ptr)( numPaths, pathNameType, paths, pathBase, reference, mask, transformType, transformValues );
}

inline void glPathCoverDepthFuncNV(GLenum func)
{
	typedef void (*proc_type)(GLenum func);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathCoverDepthFuncNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathCoverDepthFuncNV" ); }
	(*func_ptr)( func );
}

inline void glPathColorGenNV(GLenum color,  GLenum genMode,  GLenum colorFormat,  const GLfloat *coeffs)
{
	typedef void (*proc_type)(GLenum color,  GLenum genMode,  GLenum colorFormat,  const GLfloat *coeffs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathColorGenNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathColorGenNV" ); }
	(*func_ptr)( color, genMode, colorFormat, coeffs );
}

inline void glPathTexGenNV(GLenum texCoordSet,  GLenum genMode,  GLint components,  const GLfloat *coeffs)
{
	typedef void (*proc_type)(GLenum texCoordSet,  GLenum genMode,  GLint components,  const GLfloat *coeffs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathTexGenNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathTexGenNV" ); }
	(*func_ptr)( texCoordSet, genMode, components, coeffs );
}

inline void glPathFogGenNV(GLenum genMode)
{
	typedef void (*proc_type)(GLenum genMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathFogGenNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathFogGenNV" ); }
	(*func_ptr)( genMode );
}

inline void glCoverFillPathNV(GLuint path,  GLenum coverMode)
{
	typedef void (*proc_type)(GLuint path,  GLenum coverMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCoverFillPathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCoverFillPathNV" ); }
	(*func_ptr)( path, coverMode );
}

inline void glCoverStrokePathNV(GLuint path,  GLenum coverMode)
{
	typedef void (*proc_type)(GLuint path,  GLenum coverMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCoverStrokePathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCoverStrokePathNV" ); }
	(*func_ptr)( path, coverMode );
}

inline void glCoverFillPathInstancedNV(GLsizei numPaths,  GLenum pathNameType,  const GLvoid *paths,  GLuint pathBase,  GLenum coverMode,  GLenum transformType,  const GLfloat *transformValues)
{
	typedef void (*proc_type)(GLsizei numPaths,  GLenum pathNameType,  const GLvoid *paths,  GLuint pathBase,  GLenum coverMode,  GLenum transformType,  const GLfloat *transformValues);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCoverFillPathInstancedNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCoverFillPathInstancedNV" ); }
	(*func_ptr)( numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues );
}

inline void glCoverStrokePathInstancedNV(GLsizei numPaths,  GLenum pathNameType,  const GLvoid *paths,  GLuint pathBase,  GLenum coverMode,  GLenum transformType,  const GLfloat *transformValues)
{
	typedef void (*proc_type)(GLsizei numPaths,  GLenum pathNameType,  const GLvoid *paths,  GLuint pathBase,  GLenum coverMode,  GLenum transformType,  const GLfloat *transformValues);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCoverStrokePathInstancedNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCoverStrokePathInstancedNV" ); }
	(*func_ptr)( numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues );
}

inline void glGetPathParameterivNV(GLuint path,  GLenum pname,  GLint *value)
{
	typedef void (*proc_type)(GLuint path,  GLenum pname,  GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathParameterivNV" ); }
	(*func_ptr)( path, pname, value );
}

inline void glGetPathParameterfvNV(GLuint path,  GLenum pname,  GLfloat *value)
{
	typedef void (*proc_type)(GLuint path,  GLenum pname,  GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathParameterfvNV" ); }
	(*func_ptr)( path, pname, value );
}

inline void glGetPathCommandsNV(GLuint path,  GLubyte *commands)
{
	typedef void (*proc_type)(GLuint path,  GLubyte *commands);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathCommandsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathCommandsNV" ); }
	(*func_ptr)( path, commands );
}

inline void glGetPathCoordsNV(GLuint path,  GLfloat *coords)
{
	typedef void (*proc_type)(GLuint path,  GLfloat *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathCoordsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathCoordsNV" ); }
	(*func_ptr)( path, coords );
}

inline void glGetPathDashArrayNV(GLuint path,  GLfloat *dashArray)
{
	typedef void (*proc_type)(GLuint path,  GLfloat *dashArray);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathDashArrayNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathDashArrayNV" ); }
	(*func_ptr)( path, dashArray );
}

inline void glGetPathMetricsNV(GLbitfield metricQueryMask,  GLsizei numPaths,  GLenum pathNameType,  const GLvoid *paths,  GLuint pathBase,  GLsizei stride,  GLfloat *metrics)
{
	typedef void (*proc_type)(GLbitfield metricQueryMask,  GLsizei numPaths,  GLenum pathNameType,  const GLvoid *paths,  GLuint pathBase,  GLsizei stride,  GLfloat *metrics);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathMetricsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathMetricsNV" ); }
	(*func_ptr)( metricQueryMask, numPaths, pathNameType, paths, pathBase, stride, metrics );
}

inline void glGetPathMetricRangeNV(GLbitfield metricQueryMask,  GLuint firstPathName,  GLsizei numPaths,  GLsizei stride,  GLfloat *metrics)
{
	typedef void (*proc_type)(GLbitfield metricQueryMask,  GLuint firstPathName,  GLsizei numPaths,  GLsizei stride,  GLfloat *metrics);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathMetricRangeNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathMetricRangeNV" ); }
	(*func_ptr)( metricQueryMask, firstPathName, numPaths, stride, metrics );
}

inline void glGetPathSpacingNV(GLenum pathListMode,  GLsizei numPaths,  GLenum pathNameType,  const GLvoid *paths,  GLuint pathBase,  GLfloat advanceScale,  GLfloat kerningScale,  GLenum transformType,  GLfloat *returnedSpacing)
{
	typedef void (*proc_type)(GLenum pathListMode,  GLsizei numPaths,  GLenum pathNameType,  const GLvoid *paths,  GLuint pathBase,  GLfloat advanceScale,  GLfloat kerningScale,  GLenum transformType,  GLfloat *returnedSpacing);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathSpacingNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathSpacingNV" ); }
	(*func_ptr)( pathListMode, numPaths, pathNameType, paths, pathBase, advanceScale, kerningScale, transformType, returnedSpacing );
}

inline void glGetPathColorGenivNV(GLenum color,  GLenum pname,  GLint *value)
{
	typedef void (*proc_type)(GLenum color,  GLenum pname,  GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathColorGenivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathColorGenivNV" ); }
	(*func_ptr)( color, pname, value );
}

inline void glGetPathColorGenfvNV(GLenum color,  GLenum pname,  GLfloat *value)
{
	typedef void (*proc_type)(GLenum color,  GLenum pname,  GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathColorGenfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathColorGenfvNV" ); }
	(*func_ptr)( color, pname, value );
}

inline void glGetPathTexGenivNV(GLenum texCoordSet,  GLenum pname,  GLint *value)
{
	typedef void (*proc_type)(GLenum texCoordSet,  GLenum pname,  GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathTexGenivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathTexGenivNV" ); }
	(*func_ptr)( texCoordSet, pname, value );
}

inline void glGetPathTexGenfvNV(GLenum texCoordSet,  GLenum pname,  GLfloat *value)
{
	typedef void (*proc_type)(GLenum texCoordSet,  GLenum pname,  GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathTexGenfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathTexGenfvNV" ); }
	(*func_ptr)( texCoordSet, pname, value );
}

inline GLboolean glIsPointInFillPathNV(GLuint path,  GLuint mask,  GLfloat x,  GLfloat y)
{
	typedef GLboolean (*proc_type)(GLuint path,  GLuint mask,  GLfloat x,  GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsPointInFillPathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsPointInFillPathNV" ); }
	return (*func_ptr)( path, mask, x, y );
}

inline GLboolean glIsPointInStrokePathNV(GLuint path,  GLfloat x,  GLfloat y)
{
	typedef GLboolean (*proc_type)(GLuint path,  GLfloat x,  GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsPointInStrokePathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsPointInStrokePathNV" ); }
	return (*func_ptr)( path, x, y );
}

inline GLfloat glGetPathLengthNV(GLuint path,  GLsizei startSegment,  GLsizei numSegments)
{
	typedef GLfloat (*proc_type)(GLuint path,  GLsizei startSegment,  GLsizei numSegments);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathLengthNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathLengthNV" ); }
	return (*func_ptr)( path, startSegment, numSegments );
}

inline GLboolean glPointAlongPathNV(GLuint path,  GLsizei startSegment,  GLsizei numSegments,  GLfloat distance,  GLfloat *x,  GLfloat *y,  GLfloat *tangentX,  GLfloat *tangentY)
{
	typedef GLboolean (*proc_type)(GLuint path,  GLsizei startSegment,  GLsizei numSegments,  GLfloat distance,  GLfloat *x,  GLfloat *y,  GLfloat *tangentX,  GLfloat *tangentY);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointAlongPathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointAlongPathNV" ); }
	return (*func_ptr)( path, startSegment, numSegments, distance, x, y, tangentX, tangentY );
}

inline void glStencilOpValueAMD(GLenum face,  GLuint value)
{
	typedef void (*proc_type)(GLenum face,  GLuint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilOpValueAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilOpValueAMD" ); }
	(*func_ptr)( face, value );
}

inline GLuint64 glGetTextureHandleNV(GLuint texture)
{
	typedef GLuint64 (*proc_type)(GLuint texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureHandleNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureHandleNV" ); }
	return (*func_ptr)( texture );
}

inline GLuint64 glGetTextureSamplerHandleNV(GLuint texture,  GLuint sampler)
{
	typedef GLuint64 (*proc_type)(GLuint texture,  GLuint sampler);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureSamplerHandleNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureSamplerHandleNV" ); }
	return (*func_ptr)( texture, sampler );
}

inline void glMakeTextureHandleResidentNV(GLuint64 handle)
{
	typedef void (*proc_type)(GLuint64 handle);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMakeTextureHandleResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMakeTextureHandleResidentNV" ); }
	(*func_ptr)( handle );
}

inline void glMakeTextureHandleNonResidentNV(GLuint64 handle)
{
	typedef void (*proc_type)(GLuint64 handle);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMakeTextureHandleNonResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMakeTextureHandleNonResidentNV" ); }
	(*func_ptr)( handle );
}

inline GLuint64 glGetImageHandleNV(GLuint texture,  GLint level,  GLboolean layered,  GLint layer,  GLenum format)
{
	typedef GLuint64 (*proc_type)(GLuint texture,  GLint level,  GLboolean layered,  GLint layer,  GLenum format);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetImageHandleNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetImageHandleNV" ); }
	return (*func_ptr)( texture, level, layered, layer, format );
}

inline void glMakeImageHandleResidentNV(GLuint64 handle,  GLenum access)
{
	typedef void (*proc_type)(GLuint64 handle,  GLenum access);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMakeImageHandleResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMakeImageHandleResidentNV" ); }
	(*func_ptr)( handle, access );
}

inline void glMakeImageHandleNonResidentNV(GLuint64 handle)
{
	typedef void (*proc_type)(GLuint64 handle);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMakeImageHandleNonResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMakeImageHandleNonResidentNV" ); }
	(*func_ptr)( handle );
}

inline void glUniformHandleui64NV(GLint location,  GLuint64 value)
{
	typedef void (*proc_type)(GLint location,  GLuint64 value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformHandleui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformHandleui64NV" ); }
	(*func_ptr)( location, value );
}

inline void glUniformHandleui64vNV(GLint location,  GLsizei count,  const GLuint64 *value)
{
	typedef void (*proc_type)(GLint location,  GLsizei count,  const GLuint64 *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformHandleui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformHandleui64vNV" ); }
	(*func_ptr)( location, count, value );
}

inline void glProgramUniformHandleui64NV(GLuint program,  GLint location,  GLuint64 value)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLuint64 value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformHandleui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformHandleui64NV" ); }
	(*func_ptr)( program, location, value );
}

inline void glProgramUniformHandleui64vNV(GLuint program,  GLint location,  GLsizei count,  const GLuint64 *values)
{
	typedef void (*proc_type)(GLuint program,  GLint location,  GLsizei count,  const GLuint64 *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformHandleui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformHandleui64vNV" ); }
	(*func_ptr)( program, location, count, values );
}

inline GLboolean glIsTextureHandleResidentNV(GLuint64 handle)
{
	typedef GLboolean (*proc_type)(GLuint64 handle);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsTextureHandleResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsTextureHandleResidentNV" ); }
	return (*func_ptr)( handle );
}

inline GLboolean glIsImageHandleResidentNV(GLuint64 handle)
{
	typedef GLboolean (*proc_type)(GLuint64 handle);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsImageHandleResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsImageHandleResidentNV" ); }
	return (*func_ptr)( handle );
}


#endif // GLEWLLE_HPP_
