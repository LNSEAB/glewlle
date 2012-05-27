// glewlle
// Copyright (C) 2012 LNSEAB

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

#include <glext.h>

inline void APIENTRY glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	typedef void APIENTRY (*proc_type)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendColor" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendColor" ); }
	return (*func_ptr)( red, green, blue, alpha );
}

inline void APIENTRY glBlendEquation(GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquation" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquation" ); }
	return (*func_ptr)( mode );
}

inline void APIENTRY glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawRangeElements" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawRangeElements" ); }
	return (*func_ptr)( mode, start, end, count, type, indices );
}

inline void APIENTRY glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexImage3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexImage3D" ); }
	return (*func_ptr)( target, level, internalformat, width, height, depth, border, format, type, pixels );
}

inline void APIENTRY glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexSubImage3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexSubImage3D" ); }
	return (*func_ptr)( target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels );
}

inline void APIENTRY glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTexSubImage3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTexSubImage3D" ); }
	return (*func_ptr)( target, level, xoffset, yoffset, zoffset, x, y, width, height );
}

inline void APIENTRY glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorTable" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorTable" ); }
	return (*func_ptr)( target, internalformat, width, format, type, table );
}

inline void APIENTRY glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorTableParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorTableParameterfv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glColorTableParameteriv(GLenum target, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorTableParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorTableParameteriv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyColorTable" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyColorTable" ); }
	return (*func_ptr)( target, internalformat, x, y, width );
}

inline void APIENTRY glGetColorTable(GLenum target, GLenum format, GLenum type, GLvoid *table)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum format, GLenum type, GLvoid *table);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTable" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTable" ); }
	return (*func_ptr)( target, format, type, table );
}

inline void APIENTRY glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTableParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTableParameterfv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetColorTableParameteriv(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTableParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTableParameteriv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorSubTable" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorSubTable" ); }
	return (*func_ptr)( target, start, count, format, type, data );
}

inline void APIENTRY glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyColorSubTable" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyColorSubTable" ); }
	return (*func_ptr)( target, start, x, y, width );
}

inline void APIENTRY glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionFilter1D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionFilter1D" ); }
	return (*func_ptr)( target, internalformat, width, format, type, image );
}

inline void APIENTRY glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionFilter2D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionFilter2D" ); }
	return (*func_ptr)( target, internalformat, width, height, format, type, image );
}

inline void APIENTRY glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLfloat params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionParameterf" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionParameterf" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionParameterfv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glConvolutionParameteri(GLenum target, GLenum pname, GLint params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionParameteri" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionParameteri" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glConvolutionParameteriv(GLenum target, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionParameteriv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyConvolutionFilter1D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyConvolutionFilter1D" ); }
	return (*func_ptr)( target, internalformat, x, y, width );
}

inline void APIENTRY glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyConvolutionFilter2D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyConvolutionFilter2D" ); }
	return (*func_ptr)( target, internalformat, x, y, width, height );
}

inline void APIENTRY glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid *image)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum format, GLenum type, GLvoid *image);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetConvolutionFilter" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetConvolutionFilter" ); }
	return (*func_ptr)( target, format, type, image );
}

inline void APIENTRY glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetConvolutionParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetConvolutionParameterfv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetConvolutionParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetConvolutionParameteriv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSeparableFilter" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSeparableFilter" ); }
	return (*func_ptr)( target, format, type, row, column, span );
}

inline void APIENTRY glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSeparableFilter2D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSeparableFilter2D" ); }
	return (*func_ptr)( target, internalformat, width, height, format, type, row, column );
}

inline void APIENTRY glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetHistogram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetHistogram" ); }
	return (*func_ptr)( target, reset, format, type, values );
}

inline void APIENTRY glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetHistogramParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetHistogramParameterfv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetHistogramParameteriv(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetHistogramParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetHistogramParameteriv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMinmax" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMinmax" ); }
	return (*func_ptr)( target, reset, format, type, values );
}

inline void APIENTRY glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMinmaxParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMinmaxParameterfv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMinmaxParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMinmaxParameteriv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glHistogram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glHistogram" ); }
	return (*func_ptr)( target, width, internalformat, sink );
}

inline void APIENTRY glMinmax(GLenum target, GLenum internalformat, GLboolean sink)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLboolean sink);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMinmax" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMinmax" ); }
	return (*func_ptr)( target, internalformat, sink );
}

inline void APIENTRY glResetHistogram(GLenum target)
{
	typedef void APIENTRY (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glResetHistogram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glResetHistogram" ); }
	return (*func_ptr)( target );
}

inline void APIENTRY glResetMinmax(GLenum target)
{
	typedef void APIENTRY (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glResetMinmax" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glResetMinmax" ); }
	return (*func_ptr)( target );
}

inline void APIENTRY glActiveTexture(GLenum texture)
{
	typedef void APIENTRY (*proc_type)(GLenum texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glActiveTexture" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glActiveTexture" ); }
	return (*func_ptr)( texture );
}

inline void APIENTRY glSampleCoverage(GLfloat value, GLboolean invert)
{
	typedef void APIENTRY (*proc_type)(GLfloat value, GLboolean invert);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSampleCoverage" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSampleCoverage" ); }
	return (*func_ptr)( value, invert );
}

inline void APIENTRY glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexImage3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexImage3D" ); }
	return (*func_ptr)( target, level, internalformat, width, height, depth, border, imageSize, data );
}

inline void APIENTRY glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexImage2D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexImage2D" ); }
	return (*func_ptr)( target, level, internalformat, width, height, border, imageSize, data );
}

inline void APIENTRY glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexImage1D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexImage1D" ); }
	return (*func_ptr)( target, level, internalformat, width, border, imageSize, data );
}

inline void APIENTRY glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexSubImage3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexSubImage3D" ); }
	return (*func_ptr)( target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data );
}

inline void APIENTRY glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexSubImage2D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexSubImage2D" ); }
	return (*func_ptr)( target, level, xoffset, yoffset, width, height, format, imageSize, data );
}

inline void APIENTRY glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexSubImage1D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexSubImage1D" ); }
	return (*func_ptr)( target, level, xoffset, width, format, imageSize, data );
}

inline void APIENTRY glGetCompressedTexImage(GLenum target, GLint level, GLvoid *img)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLvoid *img);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCompressedTexImage" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCompressedTexImage" ); }
	return (*func_ptr)( target, level, img );
}

inline void APIENTRY glClientActiveTexture(GLenum texture)
{
	typedef void APIENTRY (*proc_type)(GLenum texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClientActiveTexture" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClientActiveTexture" ); }
	return (*func_ptr)( texture );
}

inline void APIENTRY glMultiTexCoord1d(GLenum target, GLdouble s)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLdouble s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1d" ); }
	return (*func_ptr)( target, s );
}

inline void APIENTRY glMultiTexCoord1dv(GLenum target, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1dv" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord1f(GLenum target, GLfloat s)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLfloat s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1f" ); }
	return (*func_ptr)( target, s );
}

inline void APIENTRY glMultiTexCoord1fv(GLenum target, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1fv" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord1i(GLenum target, GLint s)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1i" ); }
	return (*func_ptr)( target, s );
}

inline void APIENTRY glMultiTexCoord1iv(GLenum target, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1iv" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord1s(GLenum target, GLshort s)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLshort s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1s" ); }
	return (*func_ptr)( target, s );
}

inline void APIENTRY glMultiTexCoord1sv(GLenum target, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1sv" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLdouble s, GLdouble t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2d" ); }
	return (*func_ptr)( target, s, t );
}

inline void APIENTRY glMultiTexCoord2dv(GLenum target, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2dv" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLfloat s, GLfloat t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2f" ); }
	return (*func_ptr)( target, s, t );
}

inline void APIENTRY glMultiTexCoord2fv(GLenum target, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2fv" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord2i(GLenum target, GLint s, GLint t)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint s, GLint t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2i" ); }
	return (*func_ptr)( target, s, t );
}

inline void APIENTRY glMultiTexCoord2iv(GLenum target, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2iv" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord2s(GLenum target, GLshort s, GLshort t)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLshort s, GLshort t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2s" ); }
	return (*func_ptr)( target, s, t );
}

inline void APIENTRY glMultiTexCoord2sv(GLenum target, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2sv" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3d" ); }
	return (*func_ptr)( target, s, t, r );
}

inline void APIENTRY glMultiTexCoord3dv(GLenum target, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3dv" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3f" ); }
	return (*func_ptr)( target, s, t, r );
}

inline void APIENTRY glMultiTexCoord3fv(GLenum target, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3fv" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint s, GLint t, GLint r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3i" ); }
	return (*func_ptr)( target, s, t, r );
}

inline void APIENTRY glMultiTexCoord3iv(GLenum target, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3iv" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLshort s, GLshort t, GLshort r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3s" ); }
	return (*func_ptr)( target, s, t, r );
}

inline void APIENTRY glMultiTexCoord3sv(GLenum target, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3sv" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4d" ); }
	return (*func_ptr)( target, s, t, r, q );
}

inline void APIENTRY glMultiTexCoord4dv(GLenum target, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4dv" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4f" ); }
	return (*func_ptr)( target, s, t, r, q );
}

inline void APIENTRY glMultiTexCoord4fv(GLenum target, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4fv" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint s, GLint t, GLint r, GLint q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4i" ); }
	return (*func_ptr)( target, s, t, r, q );
}

inline void APIENTRY glMultiTexCoord4iv(GLenum target, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4iv" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4s" ); }
	return (*func_ptr)( target, s, t, r, q );
}

inline void APIENTRY glMultiTexCoord4sv(GLenum target, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4sv" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glLoadTransposeMatrixf(const GLfloat *m)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLoadTransposeMatrixf" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLoadTransposeMatrixf" ); }
	return (*func_ptr)( m );
}

inline void APIENTRY glLoadTransposeMatrixd(const GLdouble *m)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLoadTransposeMatrixd" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLoadTransposeMatrixd" ); }
	return (*func_ptr)( m );
}

inline void APIENTRY glMultTransposeMatrixf(const GLfloat *m)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultTransposeMatrixf" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultTransposeMatrixf" ); }
	return (*func_ptr)( m );
}

inline void APIENTRY glMultTransposeMatrixd(const GLdouble *m)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultTransposeMatrixd" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultTransposeMatrixd" ); }
	return (*func_ptr)( m );
}

inline void APIENTRY glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
	typedef void APIENTRY (*proc_type)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFuncSeparate" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFuncSeparate" ); }
	return (*func_ptr)( sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha );
}

inline void APIENTRY glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawArrays" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawArrays" ); }
	return (*func_ptr)( mode, first, count, primcount );
}

inline void APIENTRY glMultiDrawElements(GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawElements" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawElements" ); }
	return (*func_ptr)( mode, count, type, indices, primcount );
}

inline void APIENTRY glPointParameterf(GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterf" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterf" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glPointParameterfv(GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterfv" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glPointParameteri(GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameteri" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameteri" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glPointParameteriv(GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameteriv" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glFogCoordf(GLfloat coord)
{
	typedef void APIENTRY (*proc_type)(GLfloat coord);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordf" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordf" ); }
	return (*func_ptr)( coord );
}

inline void APIENTRY glFogCoordfv(const GLfloat *coord)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *coord);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordfv" ); }
	return (*func_ptr)( coord );
}

inline void APIENTRY glFogCoordd(GLdouble coord)
{
	typedef void APIENTRY (*proc_type)(GLdouble coord);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordd" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordd" ); }
	return (*func_ptr)( coord );
}

inline void APIENTRY glFogCoorddv(const GLdouble *coord)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *coord);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoorddv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoorddv" ); }
	return (*func_ptr)( coord );
}

inline void APIENTRY glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLsizei stride, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordPointer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordPointer" ); }
	return (*func_ptr)( type, stride, pointer );
}

inline void APIENTRY glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue)
{
	typedef void APIENTRY (*proc_type)(GLbyte red, GLbyte green, GLbyte blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3b" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3b" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glSecondaryColor3bv(const GLbyte *v)
{
	typedef void APIENTRY (*proc_type)(const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3bv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3bv" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue)
{
	typedef void APIENTRY (*proc_type)(GLdouble red, GLdouble green, GLdouble blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3d" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glSecondaryColor3dv(const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3dv" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue)
{
	typedef void APIENTRY (*proc_type)(GLfloat red, GLfloat green, GLfloat blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3f" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glSecondaryColor3fv(const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3fv" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glSecondaryColor3i(GLint red, GLint green, GLint blue)
{
	typedef void APIENTRY (*proc_type)(GLint red, GLint green, GLint blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3i" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glSecondaryColor3iv(const GLint *v)
{
	typedef void APIENTRY (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3iv" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glSecondaryColor3s(GLshort red, GLshort green, GLshort blue)
{
	typedef void APIENTRY (*proc_type)(GLshort red, GLshort green, GLshort blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3s" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glSecondaryColor3sv(const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3sv" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue)
{
	typedef void APIENTRY (*proc_type)(GLubyte red, GLubyte green, GLubyte blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3ub" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3ub" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glSecondaryColor3ubv(const GLubyte *v)
{
	typedef void APIENTRY (*proc_type)(const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3ubv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3ubv" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue)
{
	typedef void APIENTRY (*proc_type)(GLuint red, GLuint green, GLuint blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3ui" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glSecondaryColor3uiv(const GLuint *v)
{
	typedef void APIENTRY (*proc_type)(const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3uiv" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glSecondaryColor3us(GLushort red, GLushort green, GLushort blue)
{
	typedef void APIENTRY (*proc_type)(GLushort red, GLushort green, GLushort blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3us" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3us" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glSecondaryColor3usv(const GLushort *v)
{
	typedef void APIENTRY (*proc_type)(const GLushort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3usv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3usv" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColorPointer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColorPointer" ); }
	return (*func_ptr)( size, type, stride, pointer );
}

inline void APIENTRY glWindowPos2d(GLdouble x, GLdouble y)
{
	typedef void APIENTRY (*proc_type)(GLdouble x, GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2d" ); }
	return (*func_ptr)( x, y );
}

inline void APIENTRY glWindowPos2dv(const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2dv" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos2f(GLfloat x, GLfloat y)
{
	typedef void APIENTRY (*proc_type)(GLfloat x, GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2f" ); }
	return (*func_ptr)( x, y );
}

inline void APIENTRY glWindowPos2fv(const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2fv" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos2i(GLint x, GLint y)
{
	typedef void APIENTRY (*proc_type)(GLint x, GLint y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2i" ); }
	return (*func_ptr)( x, y );
}

inline void APIENTRY glWindowPos2iv(const GLint *v)
{
	typedef void APIENTRY (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2iv" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos2s(GLshort x, GLshort y)
{
	typedef void APIENTRY (*proc_type)(GLshort x, GLshort y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2s" ); }
	return (*func_ptr)( x, y );
}

inline void APIENTRY glWindowPos2sv(const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2sv" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos3d(GLdouble x, GLdouble y, GLdouble z)
{
	typedef void APIENTRY (*proc_type)(GLdouble x, GLdouble y, GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3d" ); }
	return (*func_ptr)( x, y, z );
}

inline void APIENTRY glWindowPos3dv(const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3dv" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos3f(GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3f" ); }
	return (*func_ptr)( x, y, z );
}

inline void APIENTRY glWindowPos3fv(const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3fv" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos3i(GLint x, GLint y, GLint z)
{
	typedef void APIENTRY (*proc_type)(GLint x, GLint y, GLint z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3i" ); }
	return (*func_ptr)( x, y, z );
}

inline void APIENTRY glWindowPos3iv(const GLint *v)
{
	typedef void APIENTRY (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3iv" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos3s(GLshort x, GLshort y, GLshort z)
{
	typedef void APIENTRY (*proc_type)(GLshort x, GLshort y, GLshort z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3s" ); }
	return (*func_ptr)( x, y, z );
}

inline void APIENTRY glWindowPos3sv(const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3sv" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glGenQueries(GLsizei n, GLuint *ids)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenQueries" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenQueries" ); }
	return (*func_ptr)( n, ids );
}

inline void APIENTRY glDeleteQueries(GLsizei n, const GLuint *ids)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteQueries" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteQueries" ); }
	return (*func_ptr)( n, ids );
}

inline GLboolean APIENTRY glIsQuery(GLuint id)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsQuery" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsQuery" ); }
	return (*func_ptr)( id );
}

inline void APIENTRY glBeginQuery(GLenum target, GLuint id)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginQuery" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginQuery" ); }
	return (*func_ptr)( target, id );
}

inline void APIENTRY glEndQuery(GLenum target)
{
	typedef void APIENTRY (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndQuery" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndQuery" ); }
	return (*func_ptr)( target );
}

inline void APIENTRY glGetQueryiv(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryiv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetQueryObjectiv(GLuint id, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryObjectiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryObjectiv" ); }
	return (*func_ptr)( id, pname, params );
}

inline void APIENTRY glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum pname, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryObjectuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryObjectuiv" ); }
	return (*func_ptr)( id, pname, params );
}

inline void APIENTRY glBindBuffer(GLenum target, GLuint buffer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBuffer" ); }
	return (*func_ptr)( target, buffer );
}

inline void APIENTRY glDeleteBuffers(GLsizei n, const GLuint *buffers)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *buffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteBuffers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteBuffers" ); }
	return (*func_ptr)( n, buffers );
}

inline void APIENTRY glGenBuffers(GLsizei n, GLuint *buffers)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *buffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenBuffers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenBuffers" ); }
	return (*func_ptr)( n, buffers );
}

inline GLboolean APIENTRY glIsBuffer(GLuint buffer)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsBuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsBuffer" ); }
	return (*func_ptr)( buffer );
}

inline void APIENTRY glBufferData(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBufferData" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBufferData" ); }
	return (*func_ptr)( target, size, data, usage );
}

inline void APIENTRY glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBufferSubData" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBufferSubData" ); }
	return (*func_ptr)( target, offset, size, data );
}

inline void APIENTRY glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBufferSubData" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBufferSubData" ); }
	return (*func_ptr)( target, offset, size, data );
}

inline GLvoid* APIENTRY glMapBuffer(GLenum target, GLenum access)
{
	typedef GLvoid* APIENTRY (*proc_type)(GLenum target, GLenum access);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapBuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapBuffer" ); }
	return (*func_ptr)( target, access );
}

inline GLboolean APIENTRY glUnmapBuffer(GLenum target)
{
	typedef GLboolean APIENTRY (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUnmapBuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUnmapBuffer" ); }
	return (*func_ptr)( target );
}

inline void APIENTRY glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBufferParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBufferParameteriv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetBufferPointerv(GLenum target, GLenum pname, GLvoid* *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLvoid* *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBufferPointerv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBufferPointerv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
	typedef void APIENTRY (*proc_type)(GLenum modeRGB, GLenum modeAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationSeparate" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationSeparate" ); }
	return (*func_ptr)( modeRGB, modeAlpha );
}

inline void APIENTRY glDrawBuffers(GLsizei n, const GLenum *bufs)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLenum *bufs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawBuffers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawBuffers" ); }
	return (*func_ptr)( n, bufs );
}

inline void APIENTRY glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
{
	typedef void APIENTRY (*proc_type)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilOpSeparate" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilOpSeparate" ); }
	return (*func_ptr)( face, sfail, dpfail, dppass );
}

inline void APIENTRY glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
{
	typedef void APIENTRY (*proc_type)(GLenum face, GLenum func, GLint ref, GLuint mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilFuncSeparate" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilFuncSeparate" ); }
	return (*func_ptr)( face, func, ref, mask );
}

inline void APIENTRY glStencilMaskSeparate(GLenum face, GLuint mask)
{
	typedef void APIENTRY (*proc_type)(GLenum face, GLuint mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilMaskSeparate" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilMaskSeparate" ); }
	return (*func_ptr)( face, mask );
}

inline void APIENTRY glAttachShader(GLuint program, GLuint shader)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLuint shader);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glAttachShader" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glAttachShader" ); }
	return (*func_ptr)( program, shader );
}

inline void APIENTRY glBindAttribLocation(GLuint program, GLuint index, const GLchar *name)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLuint index, const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindAttribLocation" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindAttribLocation" ); }
	return (*func_ptr)( program, index, name );
}

inline void APIENTRY glCompileShader(GLuint shader)
{
	typedef void APIENTRY (*proc_type)(GLuint shader);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompileShader" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompileShader" ); }
	return (*func_ptr)( shader );
}

inline GLuint APIENTRY glCreateProgram(void)
{
	typedef GLuint APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCreateProgram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCreateProgram" ); }
	return (*func_ptr)(  );
}

inline GLuint APIENTRY glCreateShader(GLenum type)
{
	typedef GLuint APIENTRY (*proc_type)(GLenum type);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCreateShader" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCreateShader" ); }
	return (*func_ptr)( type );
}

inline void APIENTRY glDeleteProgram(GLuint program)
{
	typedef void APIENTRY (*proc_type)(GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteProgram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteProgram" ); }
	return (*func_ptr)( program );
}

inline void APIENTRY glDeleteShader(GLuint shader)
{
	typedef void APIENTRY (*proc_type)(GLuint shader);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteShader" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteShader" ); }
	return (*func_ptr)( shader );
}

inline void APIENTRY glDetachShader(GLuint program, GLuint shader)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLuint shader);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDetachShader" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDetachShader" ); }
	return (*func_ptr)( program, shader );
}

inline void APIENTRY glDisableVertexAttribArray(GLuint index)
{
	typedef void APIENTRY (*proc_type)(GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDisableVertexAttribArray" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDisableVertexAttribArray" ); }
	return (*func_ptr)( index );
}

inline void APIENTRY glEnableVertexAttribArray(GLuint index)
{
	typedef void APIENTRY (*proc_type)(GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEnableVertexAttribArray" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEnableVertexAttribArray" ); }
	return (*func_ptr)( index );
}

inline void APIENTRY glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveAttrib" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveAttrib" ); }
	return (*func_ptr)( program, index, bufSize, length, size, type, name );
}

inline void APIENTRY glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveUniform" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveUniform" ); }
	return (*func_ptr)( program, index, bufSize, length, size, type, name );
}

inline void APIENTRY glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *obj)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *obj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetAttachedShaders" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetAttachedShaders" ); }
	return (*func_ptr)( program, maxCount, count, obj );
}

inline GLint APIENTRY glGetAttribLocation(GLuint program, const GLchar *name)
{
	typedef GLint APIENTRY (*proc_type)(GLuint program, const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetAttribLocation" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetAttribLocation" ); }
	return (*func_ptr)( program, name );
}

inline void APIENTRY glGetProgramiv(GLuint program, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramiv" ); }
	return (*func_ptr)( program, pname, params );
}

inline void APIENTRY glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramInfoLog" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramInfoLog" ); }
	return (*func_ptr)( program, bufSize, length, infoLog );
}

inline void APIENTRY glGetShaderiv(GLuint shader, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint shader, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetShaderiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetShaderiv" ); }
	return (*func_ptr)( shader, pname, params );
}

inline void APIENTRY glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
	typedef void APIENTRY (*proc_type)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetShaderInfoLog" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetShaderInfoLog" ); }
	return (*func_ptr)( shader, bufSize, length, infoLog );
}

inline void APIENTRY glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source)
{
	typedef void APIENTRY (*proc_type)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetShaderSource" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetShaderSource" ); }
	return (*func_ptr)( shader, bufSize, length, source );
}

inline GLint APIENTRY glGetUniformLocation(GLuint program, const GLchar *name)
{
	typedef GLint APIENTRY (*proc_type)(GLuint program, const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformLocation" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformLocation" ); }
	return (*func_ptr)( program, name );
}

inline void APIENTRY glGetUniformfv(GLuint program, GLint location, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformfv" ); }
	return (*func_ptr)( program, location, params );
}

inline void APIENTRY glGetUniformiv(GLuint program, GLint location, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformiv" ); }
	return (*func_ptr)( program, location, params );
}

inline void APIENTRY glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribdv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribdv" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribfv" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribiv" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid* *pointer)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLvoid* *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribPointerv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribPointerv" ); }
	return (*func_ptr)( index, pname, pointer );
}

inline GLboolean APIENTRY glIsProgram(GLuint program)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsProgram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsProgram" ); }
	return (*func_ptr)( program );
}

inline GLboolean APIENTRY glIsShader(GLuint shader)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint shader);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsShader" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsShader" ); }
	return (*func_ptr)( shader );
}

inline void APIENTRY glLinkProgram(GLuint program)
{
	typedef void APIENTRY (*proc_type)(GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLinkProgram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLinkProgram" ); }
	return (*func_ptr)( program );
}

inline void APIENTRY glShaderSource(GLuint shader, GLsizei count, const GLchar* *string, const GLint *length)
{
	typedef void APIENTRY (*proc_type)(GLuint shader, GLsizei count, const GLchar* *string, const GLint *length);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glShaderSource" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glShaderSource" ); }
	return (*func_ptr)( shader, count, string, length );
}

inline void APIENTRY glUseProgram(GLuint program)
{
	typedef void APIENTRY (*proc_type)(GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUseProgram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUseProgram" ); }
	return (*func_ptr)( program );
}

inline void APIENTRY glUniform1f(GLint location, GLfloat v0)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLfloat v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1f" ); }
	return (*func_ptr)( location, v0 );
}

inline void APIENTRY glUniform2f(GLint location, GLfloat v0, GLfloat v1)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLfloat v0, GLfloat v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2f" ); }
	return (*func_ptr)( location, v0, v1 );
}

inline void APIENTRY glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3f" ); }
	return (*func_ptr)( location, v0, v1, v2 );
}

inline void APIENTRY glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4f" ); }
	return (*func_ptr)( location, v0, v1, v2, v3 );
}

inline void APIENTRY glUniform1i(GLint location, GLint v0)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLint v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1i" ); }
	return (*func_ptr)( location, v0 );
}

inline void APIENTRY glUniform2i(GLint location, GLint v0, GLint v1)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLint v0, GLint v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2i" ); }
	return (*func_ptr)( location, v0, v1 );
}

inline void APIENTRY glUniform3i(GLint location, GLint v0, GLint v1, GLint v2)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLint v0, GLint v1, GLint v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3i" ); }
	return (*func_ptr)( location, v0, v1, v2 );
}

inline void APIENTRY glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4i" ); }
	return (*func_ptr)( location, v0, v1, v2, v3 );
}

inline void APIENTRY glUniform1fv(GLint location, GLsizei count, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1fv" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform2fv(GLint location, GLsizei count, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2fv" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform3fv(GLint location, GLsizei count, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3fv" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform4fv(GLint location, GLsizei count, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4fv" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform1iv(GLint location, GLsizei count, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1iv" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform2iv(GLint location, GLsizei count, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2iv" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform3iv(GLint location, GLsizei count, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3iv" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform4iv(GLint location, GLsizei count, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4iv" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix2fv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix3fv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix4fv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glValidateProgram(GLuint program)
{
	typedef void APIENTRY (*proc_type)(GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glValidateProgram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glValidateProgram" ); }
	return (*func_ptr)( program );
}

inline void APIENTRY glVertexAttrib1d(GLuint index, GLdouble x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1d" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttrib1dv(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1dv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib1f(GLuint index, GLfloat x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLfloat x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1f" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttrib1fv(GLuint index, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1fv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib1s(GLuint index, GLshort x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLshort x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1s" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttrib1sv(GLuint index, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1sv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x, GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2d" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttrib2dv(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2dv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLfloat x, GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2f" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttrib2fv(GLuint index, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2fv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib2s(GLuint index, GLshort x, GLshort y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLshort x, GLshort y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2s" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttrib2sv(GLuint index, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2sv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3d" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttrib3dv(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3dv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3f" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttrib3fv(GLuint index, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3fv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLshort x, GLshort y, GLshort z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3s" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttrib3sv(GLuint index, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3sv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4Nbv(GLuint index, const GLbyte *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4Nbv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4Nbv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4Niv(GLuint index, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4Niv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4Niv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4Nsv(GLuint index, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4Nsv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4Nsv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4Nub" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4Nub" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttrib4Nubv(GLuint index, const GLubyte *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4Nubv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4Nubv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4Nuiv(GLuint index, const GLuint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4Nuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4Nuiv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4Nusv(GLuint index, const GLushort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLushort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4Nusv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4Nusv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4bv(GLuint index, const GLbyte *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4bv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4bv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4d" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttrib4dv(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4dv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4f" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttrib4fv(GLuint index, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4fv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4iv(GLuint index, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4iv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4s" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4s" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttrib4sv(GLuint index, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4sv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4ubv(GLuint index, const GLubyte *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4ubv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4ubv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4uiv(GLuint index, const GLuint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4uiv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4usv(GLuint index, const GLushort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLushort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4usv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4usv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribPointer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribPointer" ); }
	return (*func_ptr)( index, size, type, normalized, stride, pointer );
}

inline void APIENTRY glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix2x3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix2x3fv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix3x2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix3x2fv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix2x4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix2x4fv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix4x2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix4x2fv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix3x4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix3x4fv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix4x3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix4x3fv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorMaski" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorMaski" ); }
	return (*func_ptr)( index, r, g, b, a );
}

inline void APIENTRY glGetBooleani_v(GLenum target, GLuint index, GLboolean *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLboolean *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBooleani_v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBooleani_v" ); }
	return (*func_ptr)( target, index, data );
}

inline void APIENTRY glGetIntegeri_v(GLenum target, GLuint index, GLint *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLint *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetIntegeri_v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetIntegeri_v" ); }
	return (*func_ptr)( target, index, data );
}

inline void APIENTRY glEnablei(GLenum target, GLuint index)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEnablei" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEnablei" ); }
	return (*func_ptr)( target, index );
}

inline void APIENTRY glDisablei(GLenum target, GLuint index)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDisablei" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDisablei" ); }
	return (*func_ptr)( target, index );
}

inline GLboolean APIENTRY glIsEnabledi(GLenum target, GLuint index)
{
	typedef GLboolean APIENTRY (*proc_type)(GLenum target, GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsEnabledi" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsEnabledi" ); }
	return (*func_ptr)( target, index );
}

inline void APIENTRY glBeginTransformFeedback(GLenum primitiveMode)
{
	typedef void APIENTRY (*proc_type)(GLenum primitiveMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginTransformFeedback" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginTransformFeedback" ); }
	return (*func_ptr)( primitiveMode );
}

inline void APIENTRY glEndTransformFeedback(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndTransformFeedback" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndTransformFeedback" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferRange" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferRange" ); }
	return (*func_ptr)( target, index, buffer, offset, size );
}

inline void APIENTRY glBindBufferBase(GLenum target, GLuint index, GLuint buffer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferBase" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferBase" ); }
	return (*func_ptr)( target, index, buffer );
}

inline void APIENTRY glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar* *varyings, GLenum bufferMode)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLsizei count, const GLchar* *varyings, GLenum bufferMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTransformFeedbackVaryings" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTransformFeedbackVaryings" ); }
	return (*func_ptr)( program, count, varyings, bufferMode );
}

inline void APIENTRY glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTransformFeedbackVarying" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTransformFeedbackVarying" ); }
	return (*func_ptr)( program, index, bufSize, length, size, type, name );
}

inline void APIENTRY glClampColor(GLenum target, GLenum clamp)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum clamp);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClampColor" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClampColor" ); }
	return (*func_ptr)( target, clamp );
}

inline void APIENTRY glBeginConditionalRender(GLuint id, GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginConditionalRender" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginConditionalRender" ); }
	return (*func_ptr)( id, mode );
}

inline void APIENTRY glEndConditionalRender(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndConditionalRender" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndConditionalRender" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribIPointer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribIPointer" ); }
	return (*func_ptr)( index, size, type, stride, pointer );
}

inline void APIENTRY glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribIiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribIiv" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribIuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribIuiv" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glVertexAttribI1i(GLuint index, GLint x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI1i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI1i" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttribI2i(GLuint index, GLint x, GLint y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint x, GLint y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI2i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI2i" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint x, GLint y, GLint z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI3i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI3i" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint x, GLint y, GLint z, GLint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4i" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttribI1ui(GLuint index, GLuint x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI1ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI1ui" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttribI2ui(GLuint index, GLuint x, GLuint y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint x, GLuint y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI2ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI2ui" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint x, GLuint y, GLuint z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI3ui" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4ui" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttribI1iv(GLuint index, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI1iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI1iv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI2iv(GLuint index, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI2iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI2iv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI3iv(GLuint index, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI3iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI3iv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI4iv(GLuint index, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4iv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI1uiv(GLuint index, const GLuint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI1uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI1uiv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI2uiv(GLuint index, const GLuint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI2uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI2uiv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI3uiv(GLuint index, const GLuint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI3uiv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI4uiv(GLuint index, const GLuint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4uiv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI4bv(GLuint index, const GLbyte *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4bv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4bv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI4sv(GLuint index, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4sv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4sv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI4ubv(GLuint index, const GLubyte *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4ubv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4ubv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI4usv(GLuint index, const GLushort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLushort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4usv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4usv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glGetUniformuiv(GLuint program, GLint location, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformuiv" ); }
	return (*func_ptr)( program, location, params );
}

inline void APIENTRY glBindFragDataLocation(GLuint program, GLuint color, const GLchar *name)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLuint color, const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindFragDataLocation" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindFragDataLocation" ); }
	return (*func_ptr)( program, color, name );
}

inline GLint APIENTRY glGetFragDataLocation(GLuint program, const GLchar *name)
{
	typedef GLint APIENTRY (*proc_type)(GLuint program, const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFragDataLocation" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFragDataLocation" ); }
	return (*func_ptr)( program, name );
}

inline void APIENTRY glUniform1ui(GLint location, GLuint v0)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLuint v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1ui" ); }
	return (*func_ptr)( location, v0 );
}

inline void APIENTRY glUniform2ui(GLint location, GLuint v0, GLuint v1)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLuint v0, GLuint v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2ui" ); }
	return (*func_ptr)( location, v0, v1 );
}

inline void APIENTRY glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLuint v0, GLuint v1, GLuint v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3ui" ); }
	return (*func_ptr)( location, v0, v1, v2 );
}

inline void APIENTRY glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4ui" ); }
	return (*func_ptr)( location, v0, v1, v2, v3 );
}

inline void APIENTRY glUniform1uiv(GLint location, GLsizei count, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1uiv" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform2uiv(GLint location, GLsizei count, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2uiv" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform3uiv(GLint location, GLsizei count, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3uiv" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform4uiv(GLint location, GLsizei count, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4uiv" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glTexParameterIiv(GLenum target, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexParameterIiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexParameterIiv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glTexParameterIuiv(GLenum target, GLenum pname, const GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexParameterIuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexParameterIuiv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetTexParameterIiv(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTexParameterIiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTexParameterIiv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTexParameterIuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTexParameterIuiv" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLenum buffer, GLint drawbuffer, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClearBufferiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClearBufferiv" ); }
	return (*func_ptr)( buffer, drawbuffer, value );
}

inline void APIENTRY glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLenum buffer, GLint drawbuffer, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClearBufferuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClearBufferuiv" ); }
	return (*func_ptr)( buffer, drawbuffer, value );
}

inline void APIENTRY glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLenum buffer, GLint drawbuffer, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClearBufferfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClearBufferfv" ); }
	return (*func_ptr)( buffer, drawbuffer, value );
}

inline void APIENTRY glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
{
	typedef void APIENTRY (*proc_type)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClearBufferfi" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClearBufferfi" ); }
	return (*func_ptr)( buffer, drawbuffer, depth, stencil );
}

inline const GLubyte * APIENTRY glGetStringi(GLenum name, GLuint index)
{
	typedef const GLubyte * APIENTRY (*proc_type)(GLenum name, GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetStringi" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetStringi" ); }
	return (*func_ptr)( name, index );
}

inline void APIENTRY glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei primcount)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawArraysInstanced" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawArraysInstanced" ); }
	return (*func_ptr)( mode, first, count, primcount );
}

inline void APIENTRY glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementsInstanced" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementsInstanced" ); }
	return (*func_ptr)( mode, count, type, indices, primcount );
}

inline void APIENTRY glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexBuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexBuffer" ); }
	return (*func_ptr)( target, internalformat, buffer );
}

inline void APIENTRY glPrimitiveRestartIndex(GLuint index)
{
	typedef void APIENTRY (*proc_type)(GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPrimitiveRestartIndex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPrimitiveRestartIndex" ); }
	return (*func_ptr)( index );
}

inline void APIENTRY glGetInteger64i_v(GLenum target, GLuint index, GLint64 *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLint64 *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetInteger64i_v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetInteger64i_v" ); }
	return (*func_ptr)( target, index, data );
}

inline void APIENTRY glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint64 *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBufferParameteri64v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBufferParameteri64v" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLuint texture, GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTexture" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTexture" ); }
	return (*func_ptr)( target, attachment, texture, level );
}

inline void APIENTRY glVertexAttribDivisor(GLuint index, GLuint divisor)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint divisor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribDivisor" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribDivisor" ); }
	return (*func_ptr)( index, divisor );
}

inline void APIENTRY glMinSampleShading(GLfloat value)
{
	typedef void APIENTRY (*proc_type)(GLfloat value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMinSampleShading" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMinSampleShading" ); }
	return (*func_ptr)( value );
}

inline void APIENTRY glBlendEquationi(GLuint buf, GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLuint buf, GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationi" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationi" ); }
	return (*func_ptr)( buf, mode );
}

inline void APIENTRY glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
{
	typedef void APIENTRY (*proc_type)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationSeparatei" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationSeparatei" ); }
	return (*func_ptr)( buf, modeRGB, modeAlpha );
}

inline void APIENTRY glBlendFunci(GLuint buf, GLenum src, GLenum dst)
{
	typedef void APIENTRY (*proc_type)(GLuint buf, GLenum src, GLenum dst);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFunci" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFunci" ); }
	return (*func_ptr)( buf, src, dst );
}

inline void APIENTRY glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
	typedef void APIENTRY (*proc_type)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFuncSeparatei" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFuncSeparatei" ); }
	return (*func_ptr)( buf, srcRGB, dstRGB, srcAlpha, dstAlpha );
}

inline void APIENTRY glActiveTextureARB(GLenum texture)
{
	typedef void APIENTRY (*proc_type)(GLenum texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glActiveTextureARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glActiveTextureARB" ); }
	return (*func_ptr)( texture );
}

inline void APIENTRY glClientActiveTextureARB(GLenum texture)
{
	typedef void APIENTRY (*proc_type)(GLenum texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClientActiveTextureARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClientActiveTextureARB" ); }
	return (*func_ptr)( texture );
}

inline void APIENTRY glMultiTexCoord1dARB(GLenum target, GLdouble s)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLdouble s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1dARB" ); }
	return (*func_ptr)( target, s );
}

inline void APIENTRY glMultiTexCoord1dvARB(GLenum target, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1dvARB" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord1fARB(GLenum target, GLfloat s)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLfloat s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1fARB" ); }
	return (*func_ptr)( target, s );
}

inline void APIENTRY glMultiTexCoord1fvARB(GLenum target, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1fvARB" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord1iARB(GLenum target, GLint s)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1iARB" ); }
	return (*func_ptr)( target, s );
}

inline void APIENTRY glMultiTexCoord1ivARB(GLenum target, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1ivARB" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord1sARB(GLenum target, GLshort s)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLshort s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1sARB" ); }
	return (*func_ptr)( target, s );
}

inline void APIENTRY glMultiTexCoord1svARB(GLenum target, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1svARB" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLdouble s, GLdouble t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2dARB" ); }
	return (*func_ptr)( target, s, t );
}

inline void APIENTRY glMultiTexCoord2dvARB(GLenum target, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2dvARB" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLfloat s, GLfloat t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2fARB" ); }
	return (*func_ptr)( target, s, t );
}

inline void APIENTRY glMultiTexCoord2fvARB(GLenum target, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2fvARB" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord2iARB(GLenum target, GLint s, GLint t)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint s, GLint t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2iARB" ); }
	return (*func_ptr)( target, s, t );
}

inline void APIENTRY glMultiTexCoord2ivARB(GLenum target, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2ivARB" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLshort s, GLshort t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2sARB" ); }
	return (*func_ptr)( target, s, t );
}

inline void APIENTRY glMultiTexCoord2svARB(GLenum target, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2svARB" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3dARB" ); }
	return (*func_ptr)( target, s, t, r );
}

inline void APIENTRY glMultiTexCoord3dvARB(GLenum target, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3dvARB" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3fARB" ); }
	return (*func_ptr)( target, s, t, r );
}

inline void APIENTRY glMultiTexCoord3fvARB(GLenum target, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3fvARB" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint s, GLint t, GLint r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3iARB" ); }
	return (*func_ptr)( target, s, t, r );
}

inline void APIENTRY glMultiTexCoord3ivARB(GLenum target, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3ivARB" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLshort s, GLshort t, GLshort r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3sARB" ); }
	return (*func_ptr)( target, s, t, r );
}

inline void APIENTRY glMultiTexCoord3svARB(GLenum target, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3svARB" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4dARB" ); }
	return (*func_ptr)( target, s, t, r, q );
}

inline void APIENTRY glMultiTexCoord4dvARB(GLenum target, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4dvARB" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4fARB" ); }
	return (*func_ptr)( target, s, t, r, q );
}

inline void APIENTRY glMultiTexCoord4fvARB(GLenum target, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4fvARB" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint s, GLint t, GLint r, GLint q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4iARB" ); }
	return (*func_ptr)( target, s, t, r, q );
}

inline void APIENTRY glMultiTexCoord4ivARB(GLenum target, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4ivARB" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4sARB" ); }
	return (*func_ptr)( target, s, t, r, q );
}

inline void APIENTRY glMultiTexCoord4svARB(GLenum target, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4svARB" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glLoadTransposeMatrixfARB(const GLfloat *m)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLoadTransposeMatrixfARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLoadTransposeMatrixfARB" ); }
	return (*func_ptr)( m );
}

inline void APIENTRY glLoadTransposeMatrixdARB(const GLdouble *m)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLoadTransposeMatrixdARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLoadTransposeMatrixdARB" ); }
	return (*func_ptr)( m );
}

inline void APIENTRY glMultTransposeMatrixfARB(const GLfloat *m)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultTransposeMatrixfARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultTransposeMatrixfARB" ); }
	return (*func_ptr)( m );
}

inline void APIENTRY glMultTransposeMatrixdARB(const GLdouble *m)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultTransposeMatrixdARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultTransposeMatrixdARB" ); }
	return (*func_ptr)( m );
}

inline void APIENTRY glSampleCoverageARB(GLfloat value, GLboolean invert)
{
	typedef void APIENTRY (*proc_type)(GLfloat value, GLboolean invert);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSampleCoverageARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSampleCoverageARB" ); }
	return (*func_ptr)( value, invert );
}

inline void APIENTRY glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexImage3DARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexImage3DARB" ); }
	return (*func_ptr)( target, level, internalformat, width, height, depth, border, imageSize, data );
}

inline void APIENTRY glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexImage2DARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexImage2DARB" ); }
	return (*func_ptr)( target, level, internalformat, width, height, border, imageSize, data );
}

inline void APIENTRY glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexImage1DARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexImage1DARB" ); }
	return (*func_ptr)( target, level, internalformat, width, border, imageSize, data );
}

inline void APIENTRY glCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexSubImage3DARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexSubImage3DARB" ); }
	return (*func_ptr)( target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data );
}

inline void APIENTRY glCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexSubImage2DARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexSubImage2DARB" ); }
	return (*func_ptr)( target, level, xoffset, yoffset, width, height, format, imageSize, data );
}

inline void APIENTRY glCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTexSubImage1DARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTexSubImage1DARB" ); }
	return (*func_ptr)( target, level, xoffset, width, format, imageSize, data );
}

inline void APIENTRY glGetCompressedTexImageARB(GLenum target, GLint level, GLvoid *img)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLvoid *img);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCompressedTexImageARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCompressedTexImageARB" ); }
	return (*func_ptr)( target, level, img );
}

inline void APIENTRY glPointParameterfARB(GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterfARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterfARB" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glPointParameterfvARB(GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterfvARB" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glWeightbvARB(GLint size, const GLbyte *weights)
{
	typedef void APIENTRY (*proc_type)(GLint size, const GLbyte *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightbvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightbvARB" ); }
	return (*func_ptr)( size, weights );
}

inline void APIENTRY glWeightsvARB(GLint size, const GLshort *weights)
{
	typedef void APIENTRY (*proc_type)(GLint size, const GLshort *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightsvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightsvARB" ); }
	return (*func_ptr)( size, weights );
}

inline void APIENTRY glWeightivARB(GLint size, const GLint *weights)
{
	typedef void APIENTRY (*proc_type)(GLint size, const GLint *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightivARB" ); }
	return (*func_ptr)( size, weights );
}

inline void APIENTRY glWeightfvARB(GLint size, const GLfloat *weights)
{
	typedef void APIENTRY (*proc_type)(GLint size, const GLfloat *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightfvARB" ); }
	return (*func_ptr)( size, weights );
}

inline void APIENTRY glWeightdvARB(GLint size, const GLdouble *weights)
{
	typedef void APIENTRY (*proc_type)(GLint size, const GLdouble *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightdvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightdvARB" ); }
	return (*func_ptr)( size, weights );
}

inline void APIENTRY glWeightubvARB(GLint size, const GLubyte *weights)
{
	typedef void APIENTRY (*proc_type)(GLint size, const GLubyte *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightubvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightubvARB" ); }
	return (*func_ptr)( size, weights );
}

inline void APIENTRY glWeightusvARB(GLint size, const GLushort *weights)
{
	typedef void APIENTRY (*proc_type)(GLint size, const GLushort *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightusvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightusvARB" ); }
	return (*func_ptr)( size, weights );
}

inline void APIENTRY glWeightuivARB(GLint size, const GLuint *weights)
{
	typedef void APIENTRY (*proc_type)(GLint size, const GLuint *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightuivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightuivARB" ); }
	return (*func_ptr)( size, weights );
}

inline void APIENTRY glWeightPointerARB(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightPointerARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightPointerARB" ); }
	return (*func_ptr)( size, type, stride, pointer );
}

inline void APIENTRY glVertexBlendARB(GLint count)
{
	typedef void APIENTRY (*proc_type)(GLint count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexBlendARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexBlendARB" ); }
	return (*func_ptr)( count );
}

inline void APIENTRY glCurrentPaletteMatrixARB(GLint index)
{
	typedef void APIENTRY (*proc_type)(GLint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCurrentPaletteMatrixARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCurrentPaletteMatrixARB" ); }
	return (*func_ptr)( index );
}

inline void APIENTRY glMatrixIndexubvARB(GLint size, const GLubyte *indices)
{
	typedef void APIENTRY (*proc_type)(GLint size, const GLubyte *indices);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixIndexubvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixIndexubvARB" ); }
	return (*func_ptr)( size, indices );
}

inline void APIENTRY glMatrixIndexusvARB(GLint size, const GLushort *indices)
{
	typedef void APIENTRY (*proc_type)(GLint size, const GLushort *indices);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixIndexusvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixIndexusvARB" ); }
	return (*func_ptr)( size, indices );
}

inline void APIENTRY glMatrixIndexuivARB(GLint size, const GLuint *indices)
{
	typedef void APIENTRY (*proc_type)(GLint size, const GLuint *indices);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixIndexuivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixIndexuivARB" ); }
	return (*func_ptr)( size, indices );
}

inline void APIENTRY glMatrixIndexPointerARB(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixIndexPointerARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixIndexPointerARB" ); }
	return (*func_ptr)( size, type, stride, pointer );
}

inline void APIENTRY glWindowPos2dARB(GLdouble x, GLdouble y)
{
	typedef void APIENTRY (*proc_type)(GLdouble x, GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2dARB" ); }
	return (*func_ptr)( x, y );
}

inline void APIENTRY glWindowPos2dvARB(const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2dvARB" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos2fARB(GLfloat x, GLfloat y)
{
	typedef void APIENTRY (*proc_type)(GLfloat x, GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2fARB" ); }
	return (*func_ptr)( x, y );
}

inline void APIENTRY glWindowPos2fvARB(const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2fvARB" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos2iARB(GLint x, GLint y)
{
	typedef void APIENTRY (*proc_type)(GLint x, GLint y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2iARB" ); }
	return (*func_ptr)( x, y );
}

inline void APIENTRY glWindowPos2ivARB(const GLint *v)
{
	typedef void APIENTRY (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2ivARB" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos2sARB(GLshort x, GLshort y)
{
	typedef void APIENTRY (*proc_type)(GLshort x, GLshort y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2sARB" ); }
	return (*func_ptr)( x, y );
}

inline void APIENTRY glWindowPos2svARB(const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2svARB" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos3dARB(GLdouble x, GLdouble y, GLdouble z)
{
	typedef void APIENTRY (*proc_type)(GLdouble x, GLdouble y, GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3dARB" ); }
	return (*func_ptr)( x, y, z );
}

inline void APIENTRY glWindowPos3dvARB(const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3dvARB" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos3fARB(GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3fARB" ); }
	return (*func_ptr)( x, y, z );
}

inline void APIENTRY glWindowPos3fvARB(const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3fvARB" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos3iARB(GLint x, GLint y, GLint z)
{
	typedef void APIENTRY (*proc_type)(GLint x, GLint y, GLint z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3iARB" ); }
	return (*func_ptr)( x, y, z );
}

inline void APIENTRY glWindowPos3ivARB(const GLint *v)
{
	typedef void APIENTRY (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3ivARB" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos3sARB(GLshort x, GLshort y, GLshort z)
{
	typedef void APIENTRY (*proc_type)(GLshort x, GLshort y, GLshort z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3sARB" ); }
	return (*func_ptr)( x, y, z );
}

inline void APIENTRY glWindowPos3svARB(const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3svARB" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glVertexAttrib1dARB(GLuint index, GLdouble x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1dARB" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttrib1dvARB(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1dvARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib1fARB(GLuint index, GLfloat x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLfloat x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1fARB" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttrib1fvARB(GLuint index, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1fvARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib1sARB(GLuint index, GLshort x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLshort x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1sARB" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttrib1svARB(GLuint index, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1svARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x, GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2dARB" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttrib2dvARB(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2dvARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLfloat x, GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2fARB" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttrib2fvARB(GLuint index, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2fvARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib2sARB(GLuint index, GLshort x, GLshort y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLshort x, GLshort y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2sARB" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttrib2svARB(GLuint index, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2svARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3dARB" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttrib3dvARB(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3dvARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3fARB" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttrib3fvARB(GLuint index, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3fvARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLshort x, GLshort y, GLshort z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3sARB" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttrib3svARB(GLuint index, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3svARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4NbvARB(GLuint index, const GLbyte *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4NbvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4NbvARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4NivARB(GLuint index, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4NivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4NivARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4NsvARB(GLuint index, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4NsvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4NsvARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4NubARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4NubARB" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttrib4NubvARB(GLuint index, const GLubyte *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4NubvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4NubvARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4NuivARB(GLuint index, const GLuint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4NuivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4NuivARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4NusvARB(GLuint index, const GLushort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLushort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4NusvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4NusvARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4bvARB(GLuint index, const GLbyte *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4bvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4bvARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4dARB" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttrib4dvARB(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4dvARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4fARB" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttrib4fvARB(GLuint index, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4fvARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4ivARB(GLuint index, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4ivARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4sARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4sARB" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttrib4svARB(GLuint index, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4svARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4svARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4ubvARB(GLuint index, const GLubyte *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4ubvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4ubvARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4uivARB(GLuint index, const GLuint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4uivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4uivARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4usvARB(GLuint index, const GLushort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLushort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4usvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4usvARB" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribPointerARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribPointerARB" ); }
	return (*func_ptr)( index, size, type, normalized, stride, pointer );
}

inline void APIENTRY glEnableVertexAttribArrayARB(GLuint index)
{
	typedef void APIENTRY (*proc_type)(GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEnableVertexAttribArrayARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEnableVertexAttribArrayARB" ); }
	return (*func_ptr)( index );
}

inline void APIENTRY glDisableVertexAttribArrayARB(GLuint index)
{
	typedef void APIENTRY (*proc_type)(GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDisableVertexAttribArrayARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDisableVertexAttribArrayARB" ); }
	return (*func_ptr)( index );
}

inline void APIENTRY glProgramStringARB(GLenum target, GLenum format, GLsizei len, const GLvoid *string)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum format, GLsizei len, const GLvoid *string);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramStringARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramStringARB" ); }
	return (*func_ptr)( target, format, len, string );
}

inline void APIENTRY glBindProgramARB(GLenum target, GLuint program)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindProgramARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindProgramARB" ); }
	return (*func_ptr)( target, program );
}

inline void APIENTRY glDeleteProgramsARB(GLsizei n, const GLuint *programs)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *programs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteProgramsARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteProgramsARB" ); }
	return (*func_ptr)( n, programs );
}

inline void APIENTRY glGenProgramsARB(GLsizei n, GLuint *programs)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *programs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenProgramsARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenProgramsARB" ); }
	return (*func_ptr)( n, programs );
}

inline void APIENTRY glProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameter4dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameter4dARB" ); }
	return (*func_ptr)( target, index, x, y, z, w );
}

inline void APIENTRY glProgramEnvParameter4dvARB(GLenum target, GLuint index, const GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, const GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameter4dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameter4dvARB" ); }
	return (*func_ptr)( target, index, params );
}

inline void APIENTRY glProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameter4fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameter4fARB" ); }
	return (*func_ptr)( target, index, x, y, z, w );
}

inline void APIENTRY glProgramEnvParameter4fvARB(GLenum target, GLuint index, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameter4fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameter4fvARB" ); }
	return (*func_ptr)( target, index, params );
}

inline void APIENTRY glProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameter4dARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameter4dARB" ); }
	return (*func_ptr)( target, index, x, y, z, w );
}

inline void APIENTRY glProgramLocalParameter4dvARB(GLenum target, GLuint index, const GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, const GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameter4dvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameter4dvARB" ); }
	return (*func_ptr)( target, index, params );
}

inline void APIENTRY glProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameter4fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameter4fARB" ); }
	return (*func_ptr)( target, index, x, y, z, w );
}

inline void APIENTRY glProgramLocalParameter4fvARB(GLenum target, GLuint index, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameter4fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameter4fvARB" ); }
	return (*func_ptr)( target, index, params );
}

inline void APIENTRY glGetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramEnvParameterdvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramEnvParameterdvARB" ); }
	return (*func_ptr)( target, index, params );
}

inline void APIENTRY glGetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramEnvParameterfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramEnvParameterfvARB" ); }
	return (*func_ptr)( target, index, params );
}

inline void APIENTRY glGetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramLocalParameterdvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramLocalParameterdvARB" ); }
	return (*func_ptr)( target, index, params );
}

inline void APIENTRY glGetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramLocalParameterfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramLocalParameterfvARB" ); }
	return (*func_ptr)( target, index, params );
}

inline void APIENTRY glGetProgramivARB(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramivARB" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetProgramStringARB(GLenum target, GLenum pname, GLvoid *string)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLvoid *string);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramStringARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramStringARB" ); }
	return (*func_ptr)( target, pname, string );
}

inline void APIENTRY glGetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribdvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribdvARB" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glGetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribfvARB" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glGetVertexAttribivARB(GLuint index, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribivARB" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glGetVertexAttribPointervARB(GLuint index, GLenum pname, GLvoid* *pointer)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLvoid* *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribPointervARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribPointervARB" ); }
	return (*func_ptr)( index, pname, pointer );
}

inline GLboolean APIENTRY glIsProgramARB(GLuint program)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsProgramARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsProgramARB" ); }
	return (*func_ptr)( program );
}

inline void APIENTRY glBindBufferARB(GLenum target, GLuint buffer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferARB" ); }
	return (*func_ptr)( target, buffer );
}

inline void APIENTRY glDeleteBuffersARB(GLsizei n, const GLuint *buffers)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *buffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteBuffersARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteBuffersARB" ); }
	return (*func_ptr)( n, buffers );
}

inline void APIENTRY glGenBuffersARB(GLsizei n, GLuint *buffers)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *buffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenBuffersARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenBuffersARB" ); }
	return (*func_ptr)( n, buffers );
}

inline GLboolean APIENTRY glIsBufferARB(GLuint buffer)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsBufferARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsBufferARB" ); }
	return (*func_ptr)( buffer );
}

inline void APIENTRY glBufferDataARB(GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizeiptrARB size, const GLvoid *data, GLenum usage);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBufferDataARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBufferDataARB" ); }
	return (*func_ptr)( target, size, data, usage );
}

inline void APIENTRY glBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLintptrARB offset, GLsizeiptrARB size, const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBufferSubDataARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBufferSubDataARB" ); }
	return (*func_ptr)( target, offset, size, data );
}

inline void APIENTRY glGetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBufferSubDataARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBufferSubDataARB" ); }
	return (*func_ptr)( target, offset, size, data );
}

inline GLvoid* APIENTRY glMapBufferARB(GLenum target, GLenum access)
{
	typedef GLvoid* APIENTRY (*proc_type)(GLenum target, GLenum access);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapBufferARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapBufferARB" ); }
	return (*func_ptr)( target, access );
}

inline GLboolean APIENTRY glUnmapBufferARB(GLenum target)
{
	typedef GLboolean APIENTRY (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUnmapBufferARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUnmapBufferARB" ); }
	return (*func_ptr)( target );
}

inline void APIENTRY glGetBufferParameterivARB(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBufferParameterivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBufferParameterivARB" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetBufferPointervARB(GLenum target, GLenum pname, GLvoid* *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLvoid* *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBufferPointervARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBufferPointervARB" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGenQueriesARB(GLsizei n, GLuint *ids)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenQueriesARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenQueriesARB" ); }
	return (*func_ptr)( n, ids );
}

inline void APIENTRY glDeleteQueriesARB(GLsizei n, const GLuint *ids)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteQueriesARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteQueriesARB" ); }
	return (*func_ptr)( n, ids );
}

inline GLboolean APIENTRY glIsQueryARB(GLuint id)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsQueryARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsQueryARB" ); }
	return (*func_ptr)( id );
}

inline void APIENTRY glBeginQueryARB(GLenum target, GLuint id)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginQueryARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginQueryARB" ); }
	return (*func_ptr)( target, id );
}

inline void APIENTRY glEndQueryARB(GLenum target)
{
	typedef void APIENTRY (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndQueryARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndQueryARB" ); }
	return (*func_ptr)( target );
}

inline void APIENTRY glGetQueryivARB(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryivARB" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetQueryObjectivARB(GLuint id, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryObjectivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryObjectivARB" ); }
	return (*func_ptr)( id, pname, params );
}

inline void APIENTRY glGetQueryObjectuivARB(GLuint id, GLenum pname, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum pname, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryObjectuivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryObjectuivARB" ); }
	return (*func_ptr)( id, pname, params );
}

inline void APIENTRY glDeleteObjectARB(GLhandleARB obj)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB obj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteObjectARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteObjectARB" ); }
	return (*func_ptr)( obj );
}

inline GLhandleARB APIENTRY glGetHandleARB(GLenum pname)
{
	typedef GLhandleARB APIENTRY (*proc_type)(GLenum pname);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetHandleARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetHandleARB" ); }
	return (*func_ptr)( pname );
}

inline void APIENTRY glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB containerObj, GLhandleARB attachedObj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDetachObjectARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDetachObjectARB" ); }
	return (*func_ptr)( containerObj, attachedObj );
}

inline GLhandleARB APIENTRY glCreateShaderObjectARB(GLenum shaderType)
{
	typedef GLhandleARB APIENTRY (*proc_type)(GLenum shaderType);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCreateShaderObjectARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCreateShaderObjectARB" ); }
	return (*func_ptr)( shaderType );
}

inline void APIENTRY glShaderSourceARB(GLhandleARB shaderObj, GLsizei count, const GLcharARB* *string, const GLint *length)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB shaderObj, GLsizei count, const GLcharARB* *string, const GLint *length);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glShaderSourceARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glShaderSourceARB" ); }
	return (*func_ptr)( shaderObj, count, string, length );
}

inline void APIENTRY glCompileShaderARB(GLhandleARB shaderObj)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB shaderObj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompileShaderARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompileShaderARB" ); }
	return (*func_ptr)( shaderObj );
}

inline GLhandleARB APIENTRY glCreateProgramObjectARB(void)
{
	typedef GLhandleARB APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCreateProgramObjectARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCreateProgramObjectARB" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glAttachObjectARB(GLhandleARB containerObj, GLhandleARB obj)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB containerObj, GLhandleARB obj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glAttachObjectARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glAttachObjectARB" ); }
	return (*func_ptr)( containerObj, obj );
}

inline void APIENTRY glLinkProgramARB(GLhandleARB programObj)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB programObj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLinkProgramARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLinkProgramARB" ); }
	return (*func_ptr)( programObj );
}

inline void APIENTRY glUseProgramObjectARB(GLhandleARB programObj)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB programObj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUseProgramObjectARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUseProgramObjectARB" ); }
	return (*func_ptr)( programObj );
}

inline void APIENTRY glValidateProgramARB(GLhandleARB programObj)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB programObj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glValidateProgramARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glValidateProgramARB" ); }
	return (*func_ptr)( programObj );
}

inline void APIENTRY glUniform1fARB(GLint location, GLfloat v0)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLfloat v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1fARB" ); }
	return (*func_ptr)( location, v0 );
}

inline void APIENTRY glUniform2fARB(GLint location, GLfloat v0, GLfloat v1)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLfloat v0, GLfloat v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2fARB" ); }
	return (*func_ptr)( location, v0, v1 );
}

inline void APIENTRY glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3fARB" ); }
	return (*func_ptr)( location, v0, v1, v2 );
}

inline void APIENTRY glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4fARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4fARB" ); }
	return (*func_ptr)( location, v0, v1, v2, v3 );
}

inline void APIENTRY glUniform1iARB(GLint location, GLint v0)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLint v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1iARB" ); }
	return (*func_ptr)( location, v0 );
}

inline void APIENTRY glUniform2iARB(GLint location, GLint v0, GLint v1)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLint v0, GLint v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2iARB" ); }
	return (*func_ptr)( location, v0, v1 );
}

inline void APIENTRY glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLint v0, GLint v1, GLint v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3iARB" ); }
	return (*func_ptr)( location, v0, v1, v2 );
}

inline void APIENTRY glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4iARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4iARB" ); }
	return (*func_ptr)( location, v0, v1, v2, v3 );
}

inline void APIENTRY glUniform1fvARB(GLint location, GLsizei count, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1fvARB" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform2fvARB(GLint location, GLsizei count, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2fvARB" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform3fvARB(GLint location, GLsizei count, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3fvARB" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform4fvARB(GLint location, GLsizei count, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4fvARB" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform1ivARB(GLint location, GLsizei count, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1ivARB" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform2ivARB(GLint location, GLsizei count, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2ivARB" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform3ivARB(GLint location, GLsizei count, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3ivARB" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform4ivARB(GLint location, GLsizei count, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4ivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4ivARB" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix2fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix2fvARB" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix3fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix3fvARB" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix4fvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix4fvARB" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB obj, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetObjectParameterfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetObjectParameterfvARB" ); }
	return (*func_ptr)( obj, pname, params );
}

inline void APIENTRY glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB obj, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetObjectParameterivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetObjectParameterivARB" ); }
	return (*func_ptr)( obj, pname, params );
}

inline void APIENTRY glGetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetInfoLogARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetInfoLogARB" ); }
	return (*func_ptr)( obj, maxLength, length, infoLog );
}

inline void APIENTRY glGetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetAttachedObjectsARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetAttachedObjectsARB" ); }
	return (*func_ptr)( containerObj, maxCount, count, obj );
}

inline GLint APIENTRY glGetUniformLocationARB(GLhandleARB programObj, const GLcharARB *name)
{
	typedef GLint APIENTRY (*proc_type)(GLhandleARB programObj, const GLcharARB *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformLocationARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformLocationARB" ); }
	return (*func_ptr)( programObj, name );
}

inline void APIENTRY glGetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveUniformARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveUniformARB" ); }
	return (*func_ptr)( programObj, index, maxLength, length, size, type, name );
}

inline void APIENTRY glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB programObj, GLint location, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformfvARB" ); }
	return (*func_ptr)( programObj, location, params );
}

inline void APIENTRY glGetUniformivARB(GLhandleARB programObj, GLint location, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB programObj, GLint location, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformivARB" ); }
	return (*func_ptr)( programObj, location, params );
}

inline void APIENTRY glGetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetShaderSourceARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetShaderSourceARB" ); }
	return (*func_ptr)( obj, maxLength, length, source );
}

inline void APIENTRY glBindAttribLocationARB(GLhandleARB programObj, GLuint index, const GLcharARB *name)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB programObj, GLuint index, const GLcharARB *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindAttribLocationARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindAttribLocationARB" ); }
	return (*func_ptr)( programObj, index, name );
}

inline void APIENTRY glGetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name)
{
	typedef void APIENTRY (*proc_type)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveAttribARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveAttribARB" ); }
	return (*func_ptr)( programObj, index, maxLength, length, size, type, name );
}

inline GLint APIENTRY glGetAttribLocationARB(GLhandleARB programObj, const GLcharARB *name)
{
	typedef GLint APIENTRY (*proc_type)(GLhandleARB programObj, const GLcharARB *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetAttribLocationARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetAttribLocationARB" ); }
	return (*func_ptr)( programObj, name );
}

inline void APIENTRY glDrawBuffersARB(GLsizei n, const GLenum *bufs)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLenum *bufs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawBuffersARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawBuffersARB" ); }
	return (*func_ptr)( n, bufs );
}

inline void APIENTRY glClampColorARB(GLenum target, GLenum clamp)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum clamp);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClampColorARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClampColorARB" ); }
	return (*func_ptr)( target, clamp );
}

inline void APIENTRY glDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawArraysInstancedARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawArraysInstancedARB" ); }
	return (*func_ptr)( mode, first, count, primcount );
}

inline void APIENTRY glDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementsInstancedARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementsInstancedARB" ); }
	return (*func_ptr)( mode, count, type, indices, primcount );
}

inline GLboolean APIENTRY glIsRenderbuffer(GLuint renderbuffer)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsRenderbuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsRenderbuffer" ); }
	return (*func_ptr)( renderbuffer );
}

inline void APIENTRY glBindRenderbuffer(GLenum target, GLuint renderbuffer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindRenderbuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindRenderbuffer" ); }
	return (*func_ptr)( target, renderbuffer );
}

inline void APIENTRY glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *renderbuffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteRenderbuffers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteRenderbuffers" ); }
	return (*func_ptr)( n, renderbuffers );
}

inline void APIENTRY glGenRenderbuffers(GLsizei n, GLuint *renderbuffers)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *renderbuffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenRenderbuffers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenRenderbuffers" ); }
	return (*func_ptr)( n, renderbuffers );
}

inline void APIENTRY glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glRenderbufferStorage" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glRenderbufferStorage" ); }
	return (*func_ptr)( target, internalformat, width, height );
}

inline void APIENTRY glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetRenderbufferParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetRenderbufferParameteriv" ); }
	return (*func_ptr)( target, pname, params );
}

inline GLboolean APIENTRY glIsFramebuffer(GLuint framebuffer)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint framebuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsFramebuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsFramebuffer" ); }
	return (*func_ptr)( framebuffer );
}

inline void APIENTRY glBindFramebuffer(GLenum target, GLuint framebuffer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint framebuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindFramebuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindFramebuffer" ); }
	return (*func_ptr)( target, framebuffer );
}

inline void APIENTRY glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *framebuffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteFramebuffers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteFramebuffers" ); }
	return (*func_ptr)( n, framebuffers );
}

inline void APIENTRY glGenFramebuffers(GLsizei n, GLuint *framebuffers)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *framebuffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenFramebuffers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenFramebuffers" ); }
	return (*func_ptr)( n, framebuffers );
}

inline GLenum APIENTRY glCheckFramebufferStatus(GLenum target)
{
	typedef GLenum APIENTRY (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCheckFramebufferStatus" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCheckFramebufferStatus" ); }
	return (*func_ptr)( target );
}

inline void APIENTRY glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTexture1D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTexture1D" ); }
	return (*func_ptr)( target, attachment, textarget, texture, level );
}

inline void APIENTRY glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTexture2D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTexture2D" ); }
	return (*func_ptr)( target, attachment, textarget, texture, level );
}

inline void APIENTRY glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTexture3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTexture3D" ); }
	return (*func_ptr)( target, attachment, textarget, texture, level, zoffset );
}

inline void APIENTRY glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferRenderbuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferRenderbuffer" ); }
	return (*func_ptr)( target, attachment, renderbuffertarget, renderbuffer );
}

inline void APIENTRY glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFramebufferAttachmentParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFramebufferAttachmentParameteriv" ); }
	return (*func_ptr)( target, attachment, pname, params );
}

inline void APIENTRY glGenerateMipmap(GLenum target)
{
	typedef void APIENTRY (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenerateMipmap" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenerateMipmap" ); }
	return (*func_ptr)( target );
}

inline void APIENTRY glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
{
	typedef void APIENTRY (*proc_type)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlitFramebuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlitFramebuffer" ); }
	return (*func_ptr)( srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter );
}

inline void APIENTRY glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glRenderbufferStorageMultisample" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glRenderbufferStorageMultisample" ); }
	return (*func_ptr)( target, samples, internalformat, width, height );
}

inline void APIENTRY glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTextureLayer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTextureLayer" ); }
	return (*func_ptr)( target, attachment, texture, level, layer );
}

inline void APIENTRY glProgramParameteriARB(GLuint program, GLenum pname, GLint value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum pname, GLint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameteriARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameteriARB" ); }
	return (*func_ptr)( program, pname, value );
}

inline void APIENTRY glFramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLuint texture, GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTextureARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTextureARB" ); }
	return (*func_ptr)( target, attachment, texture, level );
}

inline void APIENTRY glFramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTextureLayerARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTextureLayerARB" ); }
	return (*func_ptr)( target, attachment, texture, level, layer );
}

inline void APIENTRY glFramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTextureFaceARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTextureFaceARB" ); }
	return (*func_ptr)( target, attachment, texture, level, face );
}

inline void APIENTRY glVertexAttribDivisorARB(GLuint index, GLuint divisor)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint divisor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribDivisorARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribDivisorARB" ); }
	return (*func_ptr)( index, divisor );
}

inline GLvoid* APIENTRY glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
	typedef GLvoid* APIENTRY (*proc_type)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapBufferRange" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapBufferRange" ); }
	return (*func_ptr)( target, offset, length, access );
}

inline void APIENTRY glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLintptr offset, GLsizeiptr length);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFlushMappedBufferRange" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFlushMappedBufferRange" ); }
	return (*func_ptr)( target, offset, length );
}

inline void APIENTRY glTexBufferARB(GLenum target, GLenum internalformat, GLuint buffer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexBufferARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexBufferARB" ); }
	return (*func_ptr)( target, internalformat, buffer );
}

inline void APIENTRY glBindVertexArray(GLuint array)
{
	typedef void APIENTRY (*proc_type)(GLuint array);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindVertexArray" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindVertexArray" ); }
	return (*func_ptr)( array );
}

inline void APIENTRY glDeleteVertexArrays(GLsizei n, const GLuint *arrays)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *arrays);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteVertexArrays" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteVertexArrays" ); }
	return (*func_ptr)( n, arrays );
}

inline void APIENTRY glGenVertexArrays(GLsizei n, GLuint *arrays)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *arrays);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenVertexArrays" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenVertexArrays" ); }
	return (*func_ptr)( n, arrays );
}

inline GLboolean APIENTRY glIsVertexArray(GLuint array)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint array);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsVertexArray" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsVertexArray" ); }
	return (*func_ptr)( array );
}

inline void APIENTRY glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar* *uniformNames, GLuint *uniformIndices)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLsizei uniformCount, const GLchar* *uniformNames, GLuint *uniformIndices);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformIndices" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformIndices" ); }
	return (*func_ptr)( program, uniformCount, uniformNames, uniformIndices );
}

inline void APIENTRY glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveUniformsiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveUniformsiv" ); }
	return (*func_ptr)( program, uniformCount, uniformIndices, pname, params );
}

inline void APIENTRY glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveUniformName" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveUniformName" ); }
	return (*func_ptr)( program, uniformIndex, bufSize, length, uniformName );
}

inline GLuint APIENTRY glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName)
{
	typedef GLuint APIENTRY (*proc_type)(GLuint program, const GLchar *uniformBlockName);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformBlockIndex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformBlockIndex" ); }
	return (*func_ptr)( program, uniformBlockName );
}

inline void APIENTRY glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveUniformBlockiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveUniformBlockiv" ); }
	return (*func_ptr)( program, uniformBlockIndex, pname, params );
}

inline void APIENTRY glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveUniformBlockName" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveUniformBlockName" ); }
	return (*func_ptr)( program, uniformBlockIndex, bufSize, length, uniformBlockName );
}

inline void APIENTRY glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformBlockBinding" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformBlockBinding" ); }
	return (*func_ptr)( program, uniformBlockIndex, uniformBlockBinding );
}

inline void APIENTRY glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
{
	typedef void APIENTRY (*proc_type)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyBufferSubData" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyBufferSubData" ); }
	return (*func_ptr)( readTarget, writeTarget, readOffset, writeOffset, size );
}

inline void APIENTRY glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLint basevertex)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLint basevertex);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementsBaseVertex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementsBaseVertex" ); }
	return (*func_ptr)( mode, count, type, indices, basevertex );
}

inline void APIENTRY glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices, GLint basevertex)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices, GLint basevertex);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawRangeElementsBaseVertex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawRangeElementsBaseVertex" ); }
	return (*func_ptr)( mode, start, end, count, type, indices, basevertex );
}

inline void APIENTRY glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount, GLint basevertex)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount, GLint basevertex);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementsInstancedBaseVertex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementsInstancedBaseVertex" ); }
	return (*func_ptr)( mode, count, type, indices, primcount, basevertex );
}

inline void APIENTRY glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount, const GLint *basevertex)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount, const GLint *basevertex);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawElementsBaseVertex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawElementsBaseVertex" ); }
	return (*func_ptr)( mode, count, type, indices, primcount, basevertex );
}

inline void APIENTRY glProvokingVertex(GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProvokingVertex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProvokingVertex" ); }
	return (*func_ptr)( mode );
}

inline GLsync APIENTRY glFenceSync(GLenum condition, GLbitfield flags)
{
	typedef GLsync APIENTRY (*proc_type)(GLenum condition, GLbitfield flags);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFenceSync" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFenceSync" ); }
	return (*func_ptr)( condition, flags );
}

inline GLboolean APIENTRY glIsSync(GLsync sync)
{
	typedef GLboolean APIENTRY (*proc_type)(GLsync sync);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsSync" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsSync" ); }
	return (*func_ptr)( sync );
}

inline void APIENTRY glDeleteSync(GLsync sync)
{
	typedef void APIENTRY (*proc_type)(GLsync sync);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteSync" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteSync" ); }
	return (*func_ptr)( sync );
}

inline GLenum APIENTRY glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
{
	typedef GLenum APIENTRY (*proc_type)(GLsync sync, GLbitfield flags, GLuint64 timeout);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClientWaitSync" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClientWaitSync" ); }
	return (*func_ptr)( sync, flags, timeout );
}

inline void APIENTRY glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
{
	typedef void APIENTRY (*proc_type)(GLsync sync, GLbitfield flags, GLuint64 timeout);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWaitSync" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWaitSync" ); }
	return (*func_ptr)( sync, flags, timeout );
}

inline void APIENTRY glGetInteger64v(GLenum pname, GLint64 *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLint64 *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetInteger64v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetInteger64v" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values)
{
	typedef void APIENTRY (*proc_type)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSynciv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSynciv" ); }
	return (*func_ptr)( sync, pname, bufSize, length, values );
}

inline void APIENTRY glTexImage2DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexImage2DMultisample" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexImage2DMultisample" ); }
	return (*func_ptr)( target, samples, internalformat, width, height, fixedsamplelocations );
}

inline void APIENTRY glTexImage3DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexImage3DMultisample" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexImage3DMultisample" ); }
	return (*func_ptr)( target, samples, internalformat, width, height, depth, fixedsamplelocations );
}

inline void APIENTRY glGetMultisamplefv(GLenum pname, GLuint index, GLfloat *val)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLuint index, GLfloat *val);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultisamplefv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultisamplefv" ); }
	return (*func_ptr)( pname, index, val );
}

inline void APIENTRY glSampleMaski(GLuint index, GLbitfield mask)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLbitfield mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSampleMaski" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSampleMaski" ); }
	return (*func_ptr)( index, mask );
}

inline void APIENTRY glBlendEquationiARB(GLuint buf, GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLuint buf, GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationiARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationiARB" ); }
	return (*func_ptr)( buf, mode );
}

inline void APIENTRY glBlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
{
	typedef void APIENTRY (*proc_type)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationSeparateiARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationSeparateiARB" ); }
	return (*func_ptr)( buf, modeRGB, modeAlpha );
}

inline void APIENTRY glBlendFunciARB(GLuint buf, GLenum src, GLenum dst)
{
	typedef void APIENTRY (*proc_type)(GLuint buf, GLenum src, GLenum dst);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFunciARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFunciARB" ); }
	return (*func_ptr)( buf, src, dst );
}

inline void APIENTRY glBlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
	typedef void APIENTRY (*proc_type)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFuncSeparateiARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFuncSeparateiARB" ); }
	return (*func_ptr)( buf, srcRGB, dstRGB, srcAlpha, dstAlpha );
}

inline void APIENTRY glMinSampleShadingARB(GLfloat value)
{
	typedef void APIENTRY (*proc_type)(GLfloat value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMinSampleShadingARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMinSampleShadingARB" ); }
	return (*func_ptr)( value );
}

inline void APIENTRY glNamedStringARB(GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedStringARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedStringARB" ); }
	return (*func_ptr)( type, namelen, name, stringlen, string );
}

inline void APIENTRY glDeleteNamedStringARB(GLint namelen, const GLchar *name)
{
	typedef void APIENTRY (*proc_type)(GLint namelen, const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteNamedStringARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteNamedStringARB" ); }
	return (*func_ptr)( namelen, name );
}

inline void APIENTRY glCompileShaderIncludeARB(GLuint shader, GLsizei count, const GLchar* *path, const GLint *length)
{
	typedef void APIENTRY (*proc_type)(GLuint shader, GLsizei count, const GLchar* *path, const GLint *length);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompileShaderIncludeARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompileShaderIncludeARB" ); }
	return (*func_ptr)( shader, count, path, length );
}

inline GLboolean APIENTRY glIsNamedStringARB(GLint namelen, const GLchar *name)
{
	typedef GLboolean APIENTRY (*proc_type)(GLint namelen, const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsNamedStringARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsNamedStringARB" ); }
	return (*func_ptr)( namelen, name );
}

inline void APIENTRY glGetNamedStringARB(GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string)
{
	typedef void APIENTRY (*proc_type)(GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedStringARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedStringARB" ); }
	return (*func_ptr)( namelen, name, bufSize, stringlen, string );
}

inline void APIENTRY glGetNamedStringivARB(GLint namelen, const GLchar *name, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLint namelen, const GLchar *name, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedStringivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedStringivARB" ); }
	return (*func_ptr)( namelen, name, pname, params );
}

inline void APIENTRY glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindFragDataLocationIndexed" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindFragDataLocationIndexed" ); }
	return (*func_ptr)( program, colorNumber, index, name );
}

inline GLint APIENTRY glGetFragDataIndex(GLuint program, const GLchar *name)
{
	typedef GLint APIENTRY (*proc_type)(GLuint program, const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFragDataIndex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFragDataIndex" ); }
	return (*func_ptr)( program, name );
}

inline void APIENTRY glGenSamplers(GLsizei count, GLuint *samplers)
{
	typedef void APIENTRY (*proc_type)(GLsizei count, GLuint *samplers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenSamplers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenSamplers" ); }
	return (*func_ptr)( count, samplers );
}

inline void APIENTRY glDeleteSamplers(GLsizei count, const GLuint *samplers)
{
	typedef void APIENTRY (*proc_type)(GLsizei count, const GLuint *samplers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteSamplers" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteSamplers" ); }
	return (*func_ptr)( count, samplers );
}

inline GLboolean APIENTRY glIsSampler(GLuint sampler)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint sampler);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsSampler" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsSampler" ); }
	return (*func_ptr)( sampler );
}

inline void APIENTRY glBindSampler(GLuint unit, GLuint sampler)
{
	typedef void APIENTRY (*proc_type)(GLuint unit, GLuint sampler);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindSampler" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindSampler" ); }
	return (*func_ptr)( unit, sampler );
}

inline void APIENTRY glSamplerParameteri(GLuint sampler, GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLuint sampler, GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSamplerParameteri" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSamplerParameteri" ); }
	return (*func_ptr)( sampler, pname, param );
}

inline void APIENTRY glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint *param)
{
	typedef void APIENTRY (*proc_type)(GLuint sampler, GLenum pname, const GLint *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSamplerParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSamplerParameteriv" ); }
	return (*func_ptr)( sampler, pname, param );
}

inline void APIENTRY glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLuint sampler, GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSamplerParameterf" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSamplerParameterf" ); }
	return (*func_ptr)( sampler, pname, param );
}

inline void APIENTRY glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param)
{
	typedef void APIENTRY (*proc_type)(GLuint sampler, GLenum pname, const GLfloat *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSamplerParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSamplerParameterfv" ); }
	return (*func_ptr)( sampler, pname, param );
}

inline void APIENTRY glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint *param)
{
	typedef void APIENTRY (*proc_type)(GLuint sampler, GLenum pname, const GLint *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSamplerParameterIiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSamplerParameterIiv" ); }
	return (*func_ptr)( sampler, pname, param );
}

inline void APIENTRY glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint *param)
{
	typedef void APIENTRY (*proc_type)(GLuint sampler, GLenum pname, const GLuint *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSamplerParameterIuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSamplerParameterIuiv" ); }
	return (*func_ptr)( sampler, pname, param );
}

inline void APIENTRY glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint sampler, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSamplerParameteriv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSamplerParameteriv" ); }
	return (*func_ptr)( sampler, pname, params );
}

inline void APIENTRY glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint sampler, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSamplerParameterIiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSamplerParameterIiv" ); }
	return (*func_ptr)( sampler, pname, params );
}

inline void APIENTRY glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint sampler, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSamplerParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSamplerParameterfv" ); }
	return (*func_ptr)( sampler, pname, params );
}

inline void APIENTRY glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint sampler, GLenum pname, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSamplerParameterIuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSamplerParameterIuiv" ); }
	return (*func_ptr)( sampler, pname, params );
}

inline void APIENTRY glQueryCounter(GLuint id, GLenum target)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glQueryCounter" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glQueryCounter" ); }
	return (*func_ptr)( id, target );
}

inline void APIENTRY glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 *params)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum pname, GLint64 *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryObjecti64v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryObjecti64v" ); }
	return (*func_ptr)( id, pname, params );
}

inline void APIENTRY glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 *params)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum pname, GLuint64 *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryObjectui64v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryObjectui64v" ); }
	return (*func_ptr)( id, pname, params );
}

inline void APIENTRY glVertexP2ui(GLenum type, GLuint value)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLuint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexP2ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexP2ui" ); }
	return (*func_ptr)( type, value );
}

inline void APIENTRY glVertexP2uiv(GLenum type, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLenum type, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexP2uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexP2uiv" ); }
	return (*func_ptr)( type, value );
}

inline void APIENTRY glVertexP3ui(GLenum type, GLuint value)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLuint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexP3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexP3ui" ); }
	return (*func_ptr)( type, value );
}

inline void APIENTRY glVertexP3uiv(GLenum type, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLenum type, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexP3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexP3uiv" ); }
	return (*func_ptr)( type, value );
}

inline void APIENTRY glVertexP4ui(GLenum type, GLuint value)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLuint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexP4ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexP4ui" ); }
	return (*func_ptr)( type, value );
}

inline void APIENTRY glVertexP4uiv(GLenum type, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLenum type, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexP4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexP4uiv" ); }
	return (*func_ptr)( type, value );
}

inline void APIENTRY glTexCoordP1ui(GLenum type, GLuint coords)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordP1ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordP1ui" ); }
	return (*func_ptr)( type, coords );
}

inline void APIENTRY glTexCoordP1uiv(GLenum type, const GLuint *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum type, const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordP1uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordP1uiv" ); }
	return (*func_ptr)( type, coords );
}

inline void APIENTRY glTexCoordP2ui(GLenum type, GLuint coords)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordP2ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordP2ui" ); }
	return (*func_ptr)( type, coords );
}

inline void APIENTRY glTexCoordP2uiv(GLenum type, const GLuint *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum type, const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordP2uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordP2uiv" ); }
	return (*func_ptr)( type, coords );
}

inline void APIENTRY glTexCoordP3ui(GLenum type, GLuint coords)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordP3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordP3ui" ); }
	return (*func_ptr)( type, coords );
}

inline void APIENTRY glTexCoordP3uiv(GLenum type, const GLuint *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum type, const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordP3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordP3uiv" ); }
	return (*func_ptr)( type, coords );
}

inline void APIENTRY glTexCoordP4ui(GLenum type, GLuint coords)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordP4ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordP4ui" ); }
	return (*func_ptr)( type, coords );
}

inline void APIENTRY glTexCoordP4uiv(GLenum type, const GLuint *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum type, const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordP4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordP4uiv" ); }
	return (*func_ptr)( type, coords );
}

inline void APIENTRY glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords)
{
	typedef void APIENTRY (*proc_type)(GLenum texture, GLenum type, GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordP1ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordP1ui" ); }
	return (*func_ptr)( texture, type, coords );
}

inline void APIENTRY glMultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum texture, GLenum type, const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordP1uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordP1uiv" ); }
	return (*func_ptr)( texture, type, coords );
}

inline void APIENTRY glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords)
{
	typedef void APIENTRY (*proc_type)(GLenum texture, GLenum type, GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordP2ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordP2ui" ); }
	return (*func_ptr)( texture, type, coords );
}

inline void APIENTRY glMultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum texture, GLenum type, const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordP2uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordP2uiv" ); }
	return (*func_ptr)( texture, type, coords );
}

inline void APIENTRY glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords)
{
	typedef void APIENTRY (*proc_type)(GLenum texture, GLenum type, GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordP3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordP3ui" ); }
	return (*func_ptr)( texture, type, coords );
}

inline void APIENTRY glMultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum texture, GLenum type, const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordP3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordP3uiv" ); }
	return (*func_ptr)( texture, type, coords );
}

inline void APIENTRY glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords)
{
	typedef void APIENTRY (*proc_type)(GLenum texture, GLenum type, GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordP4ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordP4ui" ); }
	return (*func_ptr)( texture, type, coords );
}

inline void APIENTRY glMultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum texture, GLenum type, const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordP4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordP4uiv" ); }
	return (*func_ptr)( texture, type, coords );
}

inline void APIENTRY glNormalP3ui(GLenum type, GLuint coords)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLuint coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalP3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalP3ui" ); }
	return (*func_ptr)( type, coords );
}

inline void APIENTRY glNormalP3uiv(GLenum type, const GLuint *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum type, const GLuint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalP3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalP3uiv" ); }
	return (*func_ptr)( type, coords );
}

inline void APIENTRY glColorP3ui(GLenum type, GLuint color)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLuint color);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorP3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorP3ui" ); }
	return (*func_ptr)( type, color );
}

inline void APIENTRY glColorP3uiv(GLenum type, const GLuint *color)
{
	typedef void APIENTRY (*proc_type)(GLenum type, const GLuint *color);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorP3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorP3uiv" ); }
	return (*func_ptr)( type, color );
}

inline void APIENTRY glColorP4ui(GLenum type, GLuint color)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLuint color);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorP4ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorP4ui" ); }
	return (*func_ptr)( type, color );
}

inline void APIENTRY glColorP4uiv(GLenum type, const GLuint *color)
{
	typedef void APIENTRY (*proc_type)(GLenum type, const GLuint *color);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorP4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorP4uiv" ); }
	return (*func_ptr)( type, color );
}

inline void APIENTRY glSecondaryColorP3ui(GLenum type, GLuint color)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLuint color);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColorP3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColorP3ui" ); }
	return (*func_ptr)( type, color );
}

inline void APIENTRY glSecondaryColorP3uiv(GLenum type, const GLuint *color)
{
	typedef void APIENTRY (*proc_type)(GLenum type, const GLuint *color);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColorP3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColorP3uiv" ); }
	return (*func_ptr)( type, color );
}

inline void APIENTRY glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribP1ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribP1ui" ); }
	return (*func_ptr)( index, type, normalized, value );
}

inline void APIENTRY glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribP1uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribP1uiv" ); }
	return (*func_ptr)( index, type, normalized, value );
}

inline void APIENTRY glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribP2ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribP2ui" ); }
	return (*func_ptr)( index, type, normalized, value );
}

inline void APIENTRY glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribP2uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribP2uiv" ); }
	return (*func_ptr)( index, type, normalized, value );
}

inline void APIENTRY glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribP3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribP3ui" ); }
	return (*func_ptr)( index, type, normalized, value );
}

inline void APIENTRY glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribP3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribP3uiv" ); }
	return (*func_ptr)( index, type, normalized, value );
}

inline void APIENTRY glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribP4ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribP4ui" ); }
	return (*func_ptr)( index, type, normalized, value );
}

inline void APIENTRY glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribP4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribP4uiv" ); }
	return (*func_ptr)( index, type, normalized, value );
}

inline void APIENTRY glDrawArraysIndirect(GLenum mode, const GLvoid *indirect)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, const GLvoid *indirect);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawArraysIndirect" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawArraysIndirect" ); }
	return (*func_ptr)( mode, indirect );
}

inline void APIENTRY glDrawElementsIndirect(GLenum mode, GLenum type, const GLvoid *indirect)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLenum type, const GLvoid *indirect);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementsIndirect" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementsIndirect" ); }
	return (*func_ptr)( mode, type, indirect );
}

inline void APIENTRY glUniform1d(GLint location, GLdouble x)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLdouble x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1d" ); }
	return (*func_ptr)( location, x );
}

inline void APIENTRY glUniform2d(GLint location, GLdouble x, GLdouble y)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLdouble x, GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2d" ); }
	return (*func_ptr)( location, x, y );
}

inline void APIENTRY glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLdouble x, GLdouble y, GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3d" ); }
	return (*func_ptr)( location, x, y, z );
}

inline void APIENTRY glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4d" ); }
	return (*func_ptr)( location, x, y, z, w );
}

inline void APIENTRY glUniform1dv(GLint location, GLsizei count, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1dv" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform2dv(GLint location, GLsizei count, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2dv" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform3dv(GLint location, GLsizei count, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3dv" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform4dv(GLint location, GLsizei count, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4dv" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix2dv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix3dv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix4dv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix2x3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix2x3dv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix2x4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix2x4dv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix3x2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix3x2dv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix3x4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix3x4dv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix4x2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix4x2dv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformMatrix4x3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformMatrix4x3dv" ); }
	return (*func_ptr)( location, count, transpose, value );
}

inline void APIENTRY glGetUniformdv(GLuint program, GLint location, GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformdv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformdv" ); }
	return (*func_ptr)( program, location, params );
}

inline GLint APIENTRY glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar *name)
{
	typedef GLint APIENTRY (*proc_type)(GLuint program, GLenum shadertype, const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSubroutineUniformLocation" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSubroutineUniformLocation" ); }
	return (*func_ptr)( program, shadertype, name );
}

inline GLuint APIENTRY glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar *name)
{
	typedef GLuint APIENTRY (*proc_type)(GLuint program, GLenum shadertype, const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSubroutineIndex" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSubroutineIndex" ); }
	return (*func_ptr)( program, shadertype, name );
}

inline void APIENTRY glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveSubroutineUniformiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveSubroutineUniformiv" ); }
	return (*func_ptr)( program, shadertype, index, pname, values );
}

inline void APIENTRY glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveSubroutineUniformName" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveSubroutineUniformName" ); }
	return (*func_ptr)( program, shadertype, index, bufsize, length, name );
}

inline void APIENTRY glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveSubroutineName" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveSubroutineName" ); }
	return (*func_ptr)( program, shadertype, index, bufsize, length, name );
}

inline void APIENTRY glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint *indices)
{
	typedef void APIENTRY (*proc_type)(GLenum shadertype, GLsizei count, const GLuint *indices);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformSubroutinesuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformSubroutinesuiv" ); }
	return (*func_ptr)( shadertype, count, indices );
}

inline void APIENTRY glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum shadertype, GLint location, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformSubroutineuiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformSubroutineuiv" ); }
	return (*func_ptr)( shadertype, location, params );
}

inline void APIENTRY glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint *values)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum shadertype, GLenum pname, GLint *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramStageiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramStageiv" ); }
	return (*func_ptr)( program, shadertype, pname, values );
}

inline void APIENTRY glPatchParameteri(GLenum pname, GLint value)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPatchParameteri" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPatchParameteri" ); }
	return (*func_ptr)( pname, value );
}

inline void APIENTRY glPatchParameterfv(GLenum pname, const GLfloat *values)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLfloat *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPatchParameterfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPatchParameterfv" ); }
	return (*func_ptr)( pname, values );
}

inline void APIENTRY glBindTransformFeedback(GLenum target, GLuint id)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindTransformFeedback" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindTransformFeedback" ); }
	return (*func_ptr)( target, id );
}

inline void APIENTRY glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteTransformFeedbacks" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteTransformFeedbacks" ); }
	return (*func_ptr)( n, ids );
}

inline void APIENTRY glGenTransformFeedbacks(GLsizei n, GLuint *ids)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenTransformFeedbacks" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenTransformFeedbacks" ); }
	return (*func_ptr)( n, ids );
}

inline GLboolean APIENTRY glIsTransformFeedback(GLuint id)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsTransformFeedback" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsTransformFeedback" ); }
	return (*func_ptr)( id );
}

inline void APIENTRY glPauseTransformFeedback(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPauseTransformFeedback" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPauseTransformFeedback" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glResumeTransformFeedback(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glResumeTransformFeedback" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glResumeTransformFeedback" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glDrawTransformFeedback(GLenum mode, GLuint id)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawTransformFeedback" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawTransformFeedback" ); }
	return (*func_ptr)( mode, id );
}

inline void APIENTRY glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLuint id, GLuint stream);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawTransformFeedbackStream" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawTransformFeedbackStream" ); }
	return (*func_ptr)( mode, id, stream );
}

inline void APIENTRY glBeginQueryIndexed(GLenum target, GLuint index, GLuint id)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginQueryIndexed" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginQueryIndexed" ); }
	return (*func_ptr)( target, index, id );
}

inline void APIENTRY glEndQueryIndexed(GLenum target, GLuint index)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndQueryIndexed" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndQueryIndexed" ); }
	return (*func_ptr)( target, index );
}

inline void APIENTRY glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryIndexediv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryIndexediv" ); }
	return (*func_ptr)( target, index, pname, params );
}

inline void APIENTRY glReleaseShaderCompiler(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReleaseShaderCompiler" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReleaseShaderCompiler" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryformat, const GLvoid *binary, GLsizei length)
{
	typedef void APIENTRY (*proc_type)(GLsizei count, const GLuint *shaders, GLenum binaryformat, const GLvoid *binary, GLsizei length);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glShaderBinary" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glShaderBinary" ); }
	return (*func_ptr)( count, shaders, binaryformat, binary, length );
}

inline void APIENTRY glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision)
{
	typedef void APIENTRY (*proc_type)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetShaderPrecisionFormat" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetShaderPrecisionFormat" ); }
	return (*func_ptr)( shadertype, precisiontype, range, precision );
}

inline void APIENTRY glDepthRangef(GLfloat n, GLfloat f)
{
	typedef void APIENTRY (*proc_type)(GLfloat n, GLfloat f);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDepthRangef" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDepthRangef" ); }
	return (*func_ptr)( n, f );
}

inline void APIENTRY glClearDepthf(GLfloat d)
{
	typedef void APIENTRY (*proc_type)(GLfloat d);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClearDepthf" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClearDepthf" ); }
	return (*func_ptr)( d );
}

inline void APIENTRY glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, GLvoid *binary)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, GLvoid *binary);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramBinary" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramBinary" ); }
	return (*func_ptr)( program, bufSize, length, binaryFormat, binary );
}

inline void APIENTRY glProgramBinary(GLuint program, GLenum binaryFormat, const GLvoid *binary, GLsizei length)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum binaryFormat, const GLvoid *binary, GLsizei length);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramBinary" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramBinary" ); }
	return (*func_ptr)( program, binaryFormat, binary, length );
}

inline void APIENTRY glProgramParameteri(GLuint program, GLenum pname, GLint value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum pname, GLint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameteri" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameteri" ); }
	return (*func_ptr)( program, pname, value );
}

inline void APIENTRY glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program)
{
	typedef void APIENTRY (*proc_type)(GLuint pipeline, GLbitfield stages, GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUseProgramStages" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUseProgramStages" ); }
	return (*func_ptr)( pipeline, stages, program );
}

inline void APIENTRY glActiveShaderProgram(GLuint pipeline, GLuint program)
{
	typedef void APIENTRY (*proc_type)(GLuint pipeline, GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glActiveShaderProgram" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glActiveShaderProgram" ); }
	return (*func_ptr)( pipeline, program );
}

inline GLuint APIENTRY glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar* *strings)
{
	typedef GLuint APIENTRY (*proc_type)(GLenum type, GLsizei count, const GLchar* *strings);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCreateShaderProgramv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCreateShaderProgramv" ); }
	return (*func_ptr)( type, count, strings );
}

inline void APIENTRY glBindProgramPipeline(GLuint pipeline)
{
	typedef void APIENTRY (*proc_type)(GLuint pipeline);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindProgramPipeline" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindProgramPipeline" ); }
	return (*func_ptr)( pipeline );
}

inline void APIENTRY glDeleteProgramPipelines(GLsizei n, const GLuint *pipelines)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *pipelines);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteProgramPipelines" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteProgramPipelines" ); }
	return (*func_ptr)( n, pipelines );
}

inline void APIENTRY glGenProgramPipelines(GLsizei n, GLuint *pipelines)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *pipelines);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenProgramPipelines" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenProgramPipelines" ); }
	return (*func_ptr)( n, pipelines );
}

inline GLboolean APIENTRY glIsProgramPipeline(GLuint pipeline)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint pipeline);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsProgramPipeline" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsProgramPipeline" ); }
	return (*func_ptr)( pipeline );
}

inline void APIENTRY glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint pipeline, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramPipelineiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramPipelineiv" ); }
	return (*func_ptr)( pipeline, pname, params );
}

inline void APIENTRY glProgramUniform1i(GLuint program, GLint location, GLint v0)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLint v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1i" ); }
	return (*func_ptr)( program, location, v0 );
}

inline void APIENTRY glProgramUniform1iv(GLuint program, GLint location, GLsizei count, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1iv" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform1f(GLuint program, GLint location, GLfloat v0)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLfloat v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1f" ); }
	return (*func_ptr)( program, location, v0 );
}

inline void APIENTRY glProgramUniform1fv(GLuint program, GLint location, GLsizei count, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1fv" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform1d(GLuint program, GLint location, GLdouble v0)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLdouble v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1d" ); }
	return (*func_ptr)( program, location, v0 );
}

inline void APIENTRY glProgramUniform1dv(GLuint program, GLint location, GLsizei count, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1dv" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform1ui(GLuint program, GLint location, GLuint v0)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1ui" ); }
	return (*func_ptr)( program, location, v0 );
}

inline void APIENTRY glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1uiv" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLint v0, GLint v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2i" ); }
	return (*func_ptr)( program, location, v0, v1 );
}

inline void APIENTRY glProgramUniform2iv(GLuint program, GLint location, GLsizei count, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2iv" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2f" ); }
	return (*func_ptr)( program, location, v0, v1 );
}

inline void APIENTRY glProgramUniform2fv(GLuint program, GLint location, GLsizei count, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2fv" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2d" ); }
	return (*func_ptr)( program, location, v0, v1 );
}

inline void APIENTRY glProgramUniform2dv(GLuint program, GLint location, GLsizei count, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2dv" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint v0, GLuint v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2ui" ); }
	return (*func_ptr)( program, location, v0, v1 );
}

inline void APIENTRY glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2uiv" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3i" ); }
	return (*func_ptr)( program, location, v0, v1, v2 );
}

inline void APIENTRY glProgramUniform3iv(GLuint program, GLint location, GLsizei count, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3iv" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3f" ); }
	return (*func_ptr)( program, location, v0, v1, v2 );
}

inline void APIENTRY glProgramUniform3fv(GLuint program, GLint location, GLsizei count, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3fv" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3d" ); }
	return (*func_ptr)( program, location, v0, v1, v2 );
}

inline void APIENTRY glProgramUniform3dv(GLuint program, GLint location, GLsizei count, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3dv" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3ui" ); }
	return (*func_ptr)( program, location, v0, v1, v2 );
}

inline void APIENTRY glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3uiv" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4i" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4i" ); }
	return (*func_ptr)( program, location, v0, v1, v2, v3 );
}

inline void APIENTRY glProgramUniform4iv(GLuint program, GLint location, GLsizei count, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4iv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4iv" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4f" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4f" ); }
	return (*func_ptr)( program, location, v0, v1, v2, v3 );
}

inline void APIENTRY glProgramUniform4fv(GLuint program, GLint location, GLsizei count, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4fv" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4d" ); }
	return (*func_ptr)( program, location, v0, v1, v2, v3 );
}

inline void APIENTRY glProgramUniform4dv(GLuint program, GLint location, GLsizei count, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4dv" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4ui" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4ui" ); }
	return (*func_ptr)( program, location, v0, v1, v2, v3 );
}

inline void APIENTRY glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4uiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4uiv" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2fv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3fv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4fv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2dv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3dv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4dv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2x3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2x3fv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3x2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3x2fv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2x4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2x4fv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4x2fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4x2fv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3x4fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3x4fv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4x3fv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4x3fv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2x3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2x3dv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3x2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3x2dv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2x4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2x4dv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4x2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4x2dv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3x4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3x4dv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4x3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4x3dv" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glValidateProgramPipeline(GLuint pipeline)
{
	typedef void APIENTRY (*proc_type)(GLuint pipeline);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glValidateProgramPipeline" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glValidateProgramPipeline" ); }
	return (*func_ptr)( pipeline );
}

inline void APIENTRY glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
	typedef void APIENTRY (*proc_type)(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramPipelineInfoLog" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramPipelineInfoLog" ); }
	return (*func_ptr)( pipeline, bufSize, length, infoLog );
}

inline void APIENTRY glVertexAttribL1d(GLuint index, GLdouble x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL1d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL1d" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x, GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL2d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL2d" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL3d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL3d" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL4d" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL4d" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttribL1dv(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL1dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL1dv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribL2dv(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL2dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL2dv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribL3dv(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL3dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL3dv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribL4dv(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL4dv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL4dv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribLPointer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribLPointer" ); }
	return (*func_ptr)( index, size, type, stride, pointer );
}

inline void APIENTRY glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribLdv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribLdv" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glViewportArrayv(GLuint first, GLsizei count, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint first, GLsizei count, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glViewportArrayv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glViewportArrayv" ); }
	return (*func_ptr)( first, count, v );
}

inline void APIENTRY glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glViewportIndexedf" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glViewportIndexedf" ); }
	return (*func_ptr)( index, x, y, w, h );
}

inline void APIENTRY glViewportIndexedfv(GLuint index, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glViewportIndexedfv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glViewportIndexedfv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glScissorArrayv(GLuint first, GLsizei count, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint first, GLsizei count, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glScissorArrayv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glScissorArrayv" ); }
	return (*func_ptr)( first, count, v );
}

inline void APIENTRY glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glScissorIndexed" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glScissorIndexed" ); }
	return (*func_ptr)( index, left, bottom, width, height );
}

inline void APIENTRY glScissorIndexedv(GLuint index, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glScissorIndexedv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glScissorIndexedv" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glDepthRangeArrayv(GLuint first, GLsizei count, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint first, GLsizei count, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDepthRangeArrayv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDepthRangeArrayv" ); }
	return (*func_ptr)( first, count, v );
}

inline void APIENTRY glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble n, GLdouble f);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDepthRangeIndexed" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDepthRangeIndexed" ); }
	return (*func_ptr)( index, n, f );
}

inline void APIENTRY glGetFloati_v(GLenum target, GLuint index, GLfloat *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLfloat *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFloati_v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFloati_v" ); }
	return (*func_ptr)( target, index, data );
}

inline void APIENTRY glGetDoublei_v(GLenum target, GLuint index, GLdouble *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLdouble *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetDoublei_v" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetDoublei_v" ); }
	return (*func_ptr)( target, index, data );
}

inline GLsync APIENTRY glCreateSyncFromCLeventARB(struct _cl_context * context, struct _cl_event * event, GLbitfield flags)
{
	typedef GLsync APIENTRY (*proc_type)(struct _cl_context * context, struct _cl_event * event, GLbitfield flags);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCreateSyncFromCLeventARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCreateSyncFromCLeventARB" ); }
	return (*func_ptr)( context, event, flags );
}

inline void APIENTRY glDebugMessageControlARB(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled)
{
	typedef void APIENTRY (*proc_type)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDebugMessageControlARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDebugMessageControlARB" ); }
	return (*func_ptr)( source, type, severity, count, ids, enabled );
}

inline void APIENTRY glDebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf)
{
	typedef void APIENTRY (*proc_type)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDebugMessageInsertARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDebugMessageInsertARB" ); }
	return (*func_ptr)( source, type, id, severity, length, buf );
}

inline void APIENTRY glDebugMessageCallbackARB(GLDEBUGPROCARB callback, const GLvoid *userParam)
{
	typedef void APIENTRY (*proc_type)(GLDEBUGPROCARB callback, const GLvoid *userParam);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDebugMessageCallbackARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDebugMessageCallbackARB" ); }
	return (*func_ptr)( callback, userParam );
}

inline GLuint APIENTRY glGetDebugMessageLogARB(GLuint count, GLsizei bufsize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog)
{
	typedef GLuint APIENTRY (*proc_type)(GLuint count, GLsizei bufsize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetDebugMessageLogARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetDebugMessageLogARB" ); }
	return (*func_ptr)( count, bufsize, sources, types, ids, severities, lengths, messageLog );
}

inline GLenum APIENTRY glGetGraphicsResetStatusARB(void)
{
	typedef GLenum APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetGraphicsResetStatusARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetGraphicsResetStatusARB" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glGetnMapdvARB(GLenum target, GLenum query, GLsizei bufSize, GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum query, GLsizei bufSize, GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnMapdvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnMapdvARB" ); }
	return (*func_ptr)( target, query, bufSize, v );
}

inline void APIENTRY glGetnMapfvARB(GLenum target, GLenum query, GLsizei bufSize, GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum query, GLsizei bufSize, GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnMapfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnMapfvARB" ); }
	return (*func_ptr)( target, query, bufSize, v );
}

inline void APIENTRY glGetnMapivARB(GLenum target, GLenum query, GLsizei bufSize, GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum query, GLsizei bufSize, GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnMapivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnMapivARB" ); }
	return (*func_ptr)( target, query, bufSize, v );
}

inline void APIENTRY glGetnPixelMapfvARB(GLenum map, GLsizei bufSize, GLfloat *values)
{
	typedef void APIENTRY (*proc_type)(GLenum map, GLsizei bufSize, GLfloat *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnPixelMapfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnPixelMapfvARB" ); }
	return (*func_ptr)( map, bufSize, values );
}

inline void APIENTRY glGetnPixelMapuivARB(GLenum map, GLsizei bufSize, GLuint *values)
{
	typedef void APIENTRY (*proc_type)(GLenum map, GLsizei bufSize, GLuint *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnPixelMapuivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnPixelMapuivARB" ); }
	return (*func_ptr)( map, bufSize, values );
}

inline void APIENTRY glGetnPixelMapusvARB(GLenum map, GLsizei bufSize, GLushort *values)
{
	typedef void APIENTRY (*proc_type)(GLenum map, GLsizei bufSize, GLushort *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnPixelMapusvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnPixelMapusvARB" ); }
	return (*func_ptr)( map, bufSize, values );
}

inline void APIENTRY glGetnPolygonStippleARB(GLsizei bufSize, GLubyte *pattern)
{
	typedef void APIENTRY (*proc_type)(GLsizei bufSize, GLubyte *pattern);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnPolygonStippleARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnPolygonStippleARB" ); }
	return (*func_ptr)( bufSize, pattern );
}

inline void APIENTRY glGetnColorTableARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid *table)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid *table);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnColorTableARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnColorTableARB" ); }
	return (*func_ptr)( target, format, type, bufSize, table );
}

inline void APIENTRY glGetnConvolutionFilterARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid *image)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid *image);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnConvolutionFilterARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnConvolutionFilterARB" ); }
	return (*func_ptr)( target, format, type, bufSize, image );
}

inline void APIENTRY glGetnSeparableFilterARB(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, GLvoid *row, GLsizei columnBufSize, GLvoid *column, GLvoid *span)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, GLvoid *row, GLsizei columnBufSize, GLvoid *column, GLvoid *span);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnSeparableFilterARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnSeparableFilterARB" ); }
	return (*func_ptr)( target, format, type, rowBufSize, row, columnBufSize, column, span );
}

inline void APIENTRY glGetnHistogramARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid *values)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnHistogramARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnHistogramARB" ); }
	return (*func_ptr)( target, reset, format, type, bufSize, values );
}

inline void APIENTRY glGetnMinmaxARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid *values)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnMinmaxARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnMinmaxARB" ); }
	return (*func_ptr)( target, reset, format, type, bufSize, values );
}

inline void APIENTRY glGetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid *img)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid *img);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnTexImageARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnTexImageARB" ); }
	return (*func_ptr)( target, level, format, type, bufSize, img );
}

inline void APIENTRY glReadnPixelsARB(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReadnPixelsARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReadnPixelsARB" ); }
	return (*func_ptr)( x, y, width, height, format, type, bufSize, data );
}

inline void APIENTRY glGetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, GLvoid *img)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint lod, GLsizei bufSize, GLvoid *img);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnCompressedTexImageARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnCompressedTexImageARB" ); }
	return (*func_ptr)( target, lod, bufSize, img );
}

inline void APIENTRY glGetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnUniformfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnUniformfvARB" ); }
	return (*func_ptr)( program, location, bufSize, params );
}

inline void APIENTRY glGetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei bufSize, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnUniformivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnUniformivARB" ); }
	return (*func_ptr)( program, location, bufSize, params );
}

inline void APIENTRY glGetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei bufSize, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnUniformuivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnUniformuivARB" ); }
	return (*func_ptr)( program, location, bufSize, params );
}

inline void APIENTRY glGetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetnUniformdvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetnUniformdvARB" ); }
	return (*func_ptr)( program, location, bufSize, params );
}

inline void APIENTRY glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLuint baseinstance)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLuint baseinstance);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawArraysInstancedBaseInstance" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawArraysInstancedBaseInstance" ); }
	return (*func_ptr)( mode, first, count, primcount, baseinstance );
}

inline void APIENTRY glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount, GLuint baseinstance)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount, GLuint baseinstance);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementsInstancedBaseInstance" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementsInstancedBaseInstance" ); }
	return (*func_ptr)( mode, count, type, indices, primcount, baseinstance );
}

inline void APIENTRY glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount, GLint basevertex, GLuint baseinstance)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount, GLint basevertex, GLuint baseinstance);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementsInstancedBaseVertexBaseInstance" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementsInstancedBaseVertexBaseInstance" ); }
	return (*func_ptr)( mode, count, type, indices, primcount, basevertex, baseinstance );
}

inline void APIENTRY glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei primcount)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLuint id, GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawTransformFeedbackInstanced" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawTransformFeedbackInstanced" ); }
	return (*func_ptr)( mode, id, primcount );
}

inline void APIENTRY glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei primcount)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLuint id, GLuint stream, GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawTransformFeedbackStreamInstanced" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawTransformFeedbackStreamInstanced" ); }
	return (*func_ptr)( mode, id, stream, primcount );
}

inline void APIENTRY glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetInternalformativ" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetInternalformativ" ); }
	return (*func_ptr)( target, internalformat, pname, bufSize, params );
}

inline void APIENTRY glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveAtomicCounterBufferiv" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveAtomicCounterBufferiv" ); }
	return (*func_ptr)( program, bufferIndex, pname, params );
}

inline void APIENTRY glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format)
{
	typedef void APIENTRY (*proc_type)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindImageTexture" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindImageTexture" ); }
	return (*func_ptr)( unit, texture, level, layered, layer, access, format );
}

inline void APIENTRY glMemoryBarrier(GLbitfield barriers)
{
	typedef void APIENTRY (*proc_type)(GLbitfield barriers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMemoryBarrier" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMemoryBarrier" ); }
	return (*func_ptr)( barriers );
}

inline void APIENTRY glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexStorage1D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexStorage1D" ); }
	return (*func_ptr)( target, levels, internalformat, width );
}

inline void APIENTRY glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexStorage2D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexStorage2D" ); }
	return (*func_ptr)( target, levels, internalformat, width, height );
}

inline void APIENTRY glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexStorage3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexStorage3D" ); }
	return (*func_ptr)( target, levels, internalformat, width, height, depth );
}

inline void APIENTRY glTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureStorage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureStorage1DEXT" ); }
	return (*func_ptr)( texture, target, levels, internalformat, width );
}

inline void APIENTRY glTextureStorage2DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureStorage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureStorage2DEXT" ); }
	return (*func_ptr)( texture, target, levels, internalformat, width, height );
}

inline void APIENTRY glTextureStorage3DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureStorage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureStorage3DEXT" ); }
	return (*func_ptr)( texture, target, levels, internalformat, width, height, depth );
}

inline void APIENTRY glBlendColorEXT(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	typedef void APIENTRY (*proc_type)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendColorEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendColorEXT" ); }
	return (*func_ptr)( red, green, blue, alpha );
}

inline void APIENTRY glPolygonOffsetEXT(GLfloat factor, GLfloat bias)
{
	typedef void APIENTRY (*proc_type)(GLfloat factor, GLfloat bias);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPolygonOffsetEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPolygonOffsetEXT" ); }
	return (*func_ptr)( factor, bias );
}

inline void APIENTRY glTexImage3DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexImage3DEXT" ); }
	return (*func_ptr)( target, level, internalformat, width, height, depth, border, format, type, pixels );
}

inline void APIENTRY glTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexSubImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexSubImage3DEXT" ); }
	return (*func_ptr)( target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels );
}

inline void APIENTRY glGetTexFilterFuncSGIS(GLenum target, GLenum filter, GLfloat *weights)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum filter, GLfloat *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTexFilterFuncSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTexFilterFuncSGIS" ); }
	return (*func_ptr)( target, filter, weights );
}

inline void APIENTRY glTexFilterFuncSGIS(GLenum target, GLenum filter, GLsizei n, const GLfloat *weights)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum filter, GLsizei n, const GLfloat *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexFilterFuncSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexFilterFuncSGIS" ); }
	return (*func_ptr)( target, filter, n, weights );
}

inline void APIENTRY glTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexSubImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexSubImage1DEXT" ); }
	return (*func_ptr)( target, level, xoffset, width, format, type, pixels );
}

inline void APIENTRY glTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexSubImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexSubImage2DEXT" ); }
	return (*func_ptr)( target, level, xoffset, yoffset, width, height, format, type, pixels );
}

inline void APIENTRY glCopyTexImage1DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTexImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTexImage1DEXT" ); }
	return (*func_ptr)( target, level, internalformat, x, y, width, border );
}

inline void APIENTRY glCopyTexImage2DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTexImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTexImage2DEXT" ); }
	return (*func_ptr)( target, level, internalformat, x, y, width, height, border );
}

inline void APIENTRY glCopyTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTexSubImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTexSubImage1DEXT" ); }
	return (*func_ptr)( target, level, xoffset, x, y, width );
}

inline void APIENTRY glCopyTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTexSubImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTexSubImage2DEXT" ); }
	return (*func_ptr)( target, level, xoffset, yoffset, x, y, width, height );
}

inline void APIENTRY glCopyTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTexSubImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTexSubImage3DEXT" ); }
	return (*func_ptr)( target, level, xoffset, yoffset, zoffset, x, y, width, height );
}

inline void APIENTRY glGetHistogramEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetHistogramEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetHistogramEXT" ); }
	return (*func_ptr)( target, reset, format, type, values );
}

inline void APIENTRY glGetHistogramParameterfvEXT(GLenum target, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetHistogramParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetHistogramParameterfvEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetHistogramParameterivEXT(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetHistogramParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetHistogramParameterivEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetMinmaxEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMinmaxEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMinmaxEXT" ); }
	return (*func_ptr)( target, reset, format, type, values );
}

inline void APIENTRY glGetMinmaxParameterfvEXT(GLenum target, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMinmaxParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMinmaxParameterfvEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetMinmaxParameterivEXT(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMinmaxParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMinmaxParameterivEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glHistogramEXT(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glHistogramEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glHistogramEXT" ); }
	return (*func_ptr)( target, width, internalformat, sink );
}

inline void APIENTRY glMinmaxEXT(GLenum target, GLenum internalformat, GLboolean sink)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLboolean sink);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMinmaxEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMinmaxEXT" ); }
	return (*func_ptr)( target, internalformat, sink );
}

inline void APIENTRY glResetHistogramEXT(GLenum target)
{
	typedef void APIENTRY (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glResetHistogramEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glResetHistogramEXT" ); }
	return (*func_ptr)( target );
}

inline void APIENTRY glResetMinmaxEXT(GLenum target)
{
	typedef void APIENTRY (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glResetMinmaxEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glResetMinmaxEXT" ); }
	return (*func_ptr)( target );
}

inline void APIENTRY glConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionFilter1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionFilter1DEXT" ); }
	return (*func_ptr)( target, internalformat, width, format, type, image );
}

inline void APIENTRY glConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionFilter2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionFilter2DEXT" ); }
	return (*func_ptr)( target, internalformat, width, height, format, type, image );
}

inline void APIENTRY glConvolutionParameterfEXT(GLenum target, GLenum pname, GLfloat params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLfloat params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionParameterfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionParameterfEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glConvolutionParameterfvEXT(GLenum target, GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionParameterfvEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glConvolutionParameteriEXT(GLenum target, GLenum pname, GLint params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionParameteriEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionParameteriEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glConvolutionParameterivEXT(GLenum target, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glConvolutionParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glConvolutionParameterivEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glCopyConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyConvolutionFilter1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyConvolutionFilter1DEXT" ); }
	return (*func_ptr)( target, internalformat, x, y, width );
}

inline void APIENTRY glCopyConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyConvolutionFilter2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyConvolutionFilter2DEXT" ); }
	return (*func_ptr)( target, internalformat, x, y, width, height );
}

inline void APIENTRY glGetConvolutionFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid *image)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum format, GLenum type, GLvoid *image);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetConvolutionFilterEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetConvolutionFilterEXT" ); }
	return (*func_ptr)( target, format, type, image );
}

inline void APIENTRY glGetConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetConvolutionParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetConvolutionParameterfvEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetConvolutionParameterivEXT(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetConvolutionParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetConvolutionParameterivEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetSeparableFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSeparableFilterEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSeparableFilterEXT" ); }
	return (*func_ptr)( target, format, type, row, column, span );
}

inline void APIENTRY glSeparableFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSeparableFilter2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSeparableFilter2DEXT" ); }
	return (*func_ptr)( target, internalformat, width, height, format, type, row, column );
}

inline void APIENTRY glColorTableSGI(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorTableSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorTableSGI" ); }
	return (*func_ptr)( target, internalformat, width, format, type, table );
}

inline void APIENTRY glColorTableParameterfvSGI(GLenum target, GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorTableParameterfvSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorTableParameterfvSGI" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glColorTableParameterivSGI(GLenum target, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorTableParameterivSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorTableParameterivSGI" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glCopyColorTableSGI(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyColorTableSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyColorTableSGI" ); }
	return (*func_ptr)( target, internalformat, x, y, width );
}

inline void APIENTRY glGetColorTableSGI(GLenum target, GLenum format, GLenum type, GLvoid *table)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum format, GLenum type, GLvoid *table);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTableSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTableSGI" ); }
	return (*func_ptr)( target, format, type, table );
}

inline void APIENTRY glGetColorTableParameterfvSGI(GLenum target, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTableParameterfvSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTableParameterfvSGI" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetColorTableParameterivSGI(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTableParameterivSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTableParameterivSGI" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glPixelTexGenSGIX(GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTexGenSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTexGenSGIX" ); }
	return (*func_ptr)( mode );
}

inline void APIENTRY glPixelTexGenParameteriSGIS(GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTexGenParameteriSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTexGenParameteriSGIS" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glPixelTexGenParameterivSGIS(GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTexGenParameterivSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTexGenParameterivSGIS" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glPixelTexGenParameterfSGIS(GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTexGenParameterfSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTexGenParameterfSGIS" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glPixelTexGenParameterfvSGIS(GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTexGenParameterfvSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTexGenParameterfvSGIS" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glGetPixelTexGenParameterivSGIS(GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPixelTexGenParameterivSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPixelTexGenParameterivSGIS" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glGetPixelTexGenParameterfvSGIS(GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPixelTexGenParameterfvSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPixelTexGenParameterfvSGIS" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glTexImage4DSGIS(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexImage4DSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexImage4DSGIS" ); }
	return (*func_ptr)( target, level, internalformat, width, height, depth, size4d, border, format, type, pixels );
}

inline void APIENTRY glTexSubImage4DSGIS(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexSubImage4DSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexSubImage4DSGIS" ); }
	return (*func_ptr)( target, level, xoffset, yoffset, zoffset, woffset, width, height, depth, size4d, format, type, pixels );
}

inline GLboolean APIENTRY glAreTexturesResidentEXT(GLsizei n, const GLuint *textures, GLboolean *residences)
{
	typedef GLboolean APIENTRY (*proc_type)(GLsizei n, const GLuint *textures, GLboolean *residences);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glAreTexturesResidentEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glAreTexturesResidentEXT" ); }
	return (*func_ptr)( n, textures, residences );
}

inline void APIENTRY glBindTextureEXT(GLenum target, GLuint texture)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindTextureEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindTextureEXT" ); }
	return (*func_ptr)( target, texture );
}

inline void APIENTRY glDeleteTexturesEXT(GLsizei n, const GLuint *textures)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *textures);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteTexturesEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteTexturesEXT" ); }
	return (*func_ptr)( n, textures );
}

inline void APIENTRY glGenTexturesEXT(GLsizei n, GLuint *textures)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *textures);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenTexturesEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenTexturesEXT" ); }
	return (*func_ptr)( n, textures );
}

inline GLboolean APIENTRY glIsTextureEXT(GLuint texture)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsTextureEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsTextureEXT" ); }
	return (*func_ptr)( texture );
}

inline void APIENTRY glPrioritizeTexturesEXT(GLsizei n, const GLuint *textures, const GLclampf *priorities)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *textures, const GLclampf *priorities);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPrioritizeTexturesEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPrioritizeTexturesEXT" ); }
	return (*func_ptr)( n, textures, priorities );
}

inline void APIENTRY glDetailTexFuncSGIS(GLenum target, GLsizei n, const GLfloat *points)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei n, const GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDetailTexFuncSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDetailTexFuncSGIS" ); }
	return (*func_ptr)( target, n, points );
}

inline void APIENTRY glGetDetailTexFuncSGIS(GLenum target, GLfloat *points)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetDetailTexFuncSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetDetailTexFuncSGIS" ); }
	return (*func_ptr)( target, points );
}

inline void APIENTRY glSharpenTexFuncSGIS(GLenum target, GLsizei n, const GLfloat *points)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei n, const GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSharpenTexFuncSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSharpenTexFuncSGIS" ); }
	return (*func_ptr)( target, n, points );
}

inline void APIENTRY glGetSharpenTexFuncSGIS(GLenum target, GLfloat *points)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetSharpenTexFuncSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetSharpenTexFuncSGIS" ); }
	return (*func_ptr)( target, points );
}

inline void APIENTRY glSampleMaskSGIS(GLclampf value, GLboolean invert)
{
	typedef void APIENTRY (*proc_type)(GLclampf value, GLboolean invert);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSampleMaskSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSampleMaskSGIS" ); }
	return (*func_ptr)( value, invert );
}

inline void APIENTRY glSamplePatternSGIS(GLenum pattern)
{
	typedef void APIENTRY (*proc_type)(GLenum pattern);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSamplePatternSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSamplePatternSGIS" ); }
	return (*func_ptr)( pattern );
}

inline void APIENTRY glArrayElementEXT(GLint i)
{
	typedef void APIENTRY (*proc_type)(GLint i);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glArrayElementEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glArrayElementEXT" ); }
	return (*func_ptr)( i );
}

inline void APIENTRY glColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorPointerEXT" ); }
	return (*func_ptr)( size, type, stride, count, pointer );
}

inline void APIENTRY glDrawArraysEXT(GLenum mode, GLint first, GLsizei count)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLint first, GLsizei count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawArraysEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawArraysEXT" ); }
	return (*func_ptr)( mode, first, count );
}

inline void APIENTRY glEdgeFlagPointerEXT(GLsizei stride, GLsizei count, const GLboolean *pointer)
{
	typedef void APIENTRY (*proc_type)(GLsizei stride, GLsizei count, const GLboolean *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEdgeFlagPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEdgeFlagPointerEXT" ); }
	return (*func_ptr)( stride, count, pointer );
}

inline void APIENTRY glGetPointervEXT(GLenum pname, GLvoid* *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLvoid* *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPointervEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPointervEXT" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glIndexPointerEXT(GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIndexPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIndexPointerEXT" ); }
	return (*func_ptr)( type, stride, count, pointer );
}

inline void APIENTRY glNormalPointerEXT(GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalPointerEXT" ); }
	return (*func_ptr)( type, stride, count, pointer );
}

inline void APIENTRY glTexCoordPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordPointerEXT" ); }
	return (*func_ptr)( size, type, stride, count, pointer );
}

inline void APIENTRY glVertexPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexPointerEXT" ); }
	return (*func_ptr)( size, type, stride, count, pointer );
}

inline void APIENTRY glBlendEquationEXT(GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationEXT" ); }
	return (*func_ptr)( mode );
}

inline void APIENTRY glSpriteParameterfSGIX(GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSpriteParameterfSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSpriteParameterfSGIX" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glSpriteParameterfvSGIX(GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSpriteParameterfvSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSpriteParameterfvSGIX" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glSpriteParameteriSGIX(GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSpriteParameteriSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSpriteParameteriSGIX" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glSpriteParameterivSGIX(GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSpriteParameterivSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSpriteParameterivSGIX" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glPointParameterfEXT(GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterfEXT" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glPointParameterfvEXT(GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterfvEXT" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glPointParameterfSGIS(GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterfSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterfSGIS" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glPointParameterfvSGIS(GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterfvSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterfvSGIS" ); }
	return (*func_ptr)( pname, params );
}

inline GLint APIENTRY glGetInstrumentsSGIX(void)
{
	typedef GLint APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetInstrumentsSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetInstrumentsSGIX" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glInstrumentsBufferSGIX(GLsizei size, GLint *buffer)
{
	typedef void APIENTRY (*proc_type)(GLsizei size, GLint *buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glInstrumentsBufferSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glInstrumentsBufferSGIX" ); }
	return (*func_ptr)( size, buffer );
}

inline GLint APIENTRY glPollInstrumentsSGIX(GLint *marker_p)
{
	typedef GLint APIENTRY (*proc_type)(GLint *marker_p);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPollInstrumentsSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPollInstrumentsSGIX" ); }
	return (*func_ptr)( marker_p );
}

inline void APIENTRY glReadInstrumentsSGIX(GLint marker)
{
	typedef void APIENTRY (*proc_type)(GLint marker);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReadInstrumentsSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReadInstrumentsSGIX" ); }
	return (*func_ptr)( marker );
}

inline void APIENTRY glStartInstrumentsSGIX(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStartInstrumentsSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStartInstrumentsSGIX" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glStopInstrumentsSGIX(GLint marker)
{
	typedef void APIENTRY (*proc_type)(GLint marker);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStopInstrumentsSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStopInstrumentsSGIX" ); }
	return (*func_ptr)( marker );
}

inline void APIENTRY glFrameZoomSGIX(GLint factor)
{
	typedef void APIENTRY (*proc_type)(GLint factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFrameZoomSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFrameZoomSGIX" ); }
	return (*func_ptr)( factor );
}

inline void APIENTRY glTagSampleBufferSGIX(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTagSampleBufferSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTagSampleBufferSGIX" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glDeformationMap3dSGIX(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble *points)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeformationMap3dSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeformationMap3dSGIX" ); }
	return (*func_ptr)( target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points );
}

inline void APIENTRY glDeformationMap3fSGIX(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat *points)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeformationMap3fSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeformationMap3fSGIX" ); }
	return (*func_ptr)( target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points );
}

inline void APIENTRY glDeformSGIX(GLbitfield mask)
{
	typedef void APIENTRY (*proc_type)(GLbitfield mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeformSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeformSGIX" ); }
	return (*func_ptr)( mask );
}

inline void APIENTRY glLoadIdentityDeformationMapSGIX(GLbitfield mask)
{
	typedef void APIENTRY (*proc_type)(GLbitfield mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLoadIdentityDeformationMapSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLoadIdentityDeformationMapSGIX" ); }
	return (*func_ptr)( mask );
}

inline void APIENTRY glReferencePlaneSGIX(const GLdouble *equation)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *equation);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReferencePlaneSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReferencePlaneSGIX" ); }
	return (*func_ptr)( equation );
}

inline void APIENTRY glFlushRasterSGIX(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFlushRasterSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFlushRasterSGIX" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glFogFuncSGIS(GLsizei n, const GLfloat *points)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogFuncSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogFuncSGIS" ); }
	return (*func_ptr)( n, points );
}

inline void APIENTRY glGetFogFuncSGIS(GLfloat *points)
{
	typedef void APIENTRY (*proc_type)(GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFogFuncSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFogFuncSGIS" ); }
	return (*func_ptr)( points );
}

inline void APIENTRY glImageTransformParameteriHP(GLenum target, GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glImageTransformParameteriHP" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glImageTransformParameteriHP" ); }
	return (*func_ptr)( target, pname, param );
}

inline void APIENTRY glImageTransformParameterfHP(GLenum target, GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glImageTransformParameterfHP" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glImageTransformParameterfHP" ); }
	return (*func_ptr)( target, pname, param );
}

inline void APIENTRY glImageTransformParameterivHP(GLenum target, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glImageTransformParameterivHP" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glImageTransformParameterivHP" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glImageTransformParameterfvHP(GLenum target, GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glImageTransformParameterfvHP" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glImageTransformParameterfvHP" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetImageTransformParameterivHP(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetImageTransformParameterivHP" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetImageTransformParameterivHP" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetImageTransformParameterfvHP(GLenum target, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetImageTransformParameterfvHP" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetImageTransformParameterfvHP" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glColorSubTableEXT(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorSubTableEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorSubTableEXT" ); }
	return (*func_ptr)( target, start, count, format, type, data );
}

inline void APIENTRY glCopyColorSubTableEXT(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyColorSubTableEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyColorSubTableEXT" ); }
	return (*func_ptr)( target, start, x, y, width );
}

inline void APIENTRY glHintPGI(GLenum target, GLint mode)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glHintPGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glHintPGI" ); }
	return (*func_ptr)( target, mode );
}

inline void APIENTRY glColorTableEXT(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid *table)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorTableEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorTableEXT" ); }
	return (*func_ptr)( target, internalFormat, width, format, type, table );
}

inline void APIENTRY glGetColorTableEXT(GLenum target, GLenum format, GLenum type, GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum format, GLenum type, GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTableEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTableEXT" ); }
	return (*func_ptr)( target, format, type, data );
}

inline void APIENTRY glGetColorTableParameterivEXT(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTableParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTableParameterivEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetColorTableParameterfvEXT(GLenum target, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetColorTableParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetColorTableParameterfvEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetListParameterfvSGIX(GLuint list, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint list, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetListParameterfvSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetListParameterfvSGIX" ); }
	return (*func_ptr)( list, pname, params );
}

inline void APIENTRY glGetListParameterivSGIX(GLuint list, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint list, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetListParameterivSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetListParameterivSGIX" ); }
	return (*func_ptr)( list, pname, params );
}

inline void APIENTRY glListParameterfSGIX(GLuint list, GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLuint list, GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glListParameterfSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glListParameterfSGIX" ); }
	return (*func_ptr)( list, pname, param );
}

inline void APIENTRY glListParameterfvSGIX(GLuint list, GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint list, GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glListParameterfvSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glListParameterfvSGIX" ); }
	return (*func_ptr)( list, pname, params );
}

inline void APIENTRY glListParameteriSGIX(GLuint list, GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLuint list, GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glListParameteriSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glListParameteriSGIX" ); }
	return (*func_ptr)( list, pname, param );
}

inline void APIENTRY glListParameterivSGIX(GLuint list, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint list, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glListParameterivSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glListParameterivSGIX" ); }
	return (*func_ptr)( list, pname, params );
}

inline void APIENTRY glIndexMaterialEXT(GLenum face, GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLenum face, GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIndexMaterialEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIndexMaterialEXT" ); }
	return (*func_ptr)( face, mode );
}

inline void APIENTRY glIndexFuncEXT(GLenum func, GLclampf ref)
{
	typedef void APIENTRY (*proc_type)(GLenum func, GLclampf ref);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIndexFuncEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIndexFuncEXT" ); }
	return (*func_ptr)( func, ref );
}

inline void APIENTRY glLockArraysEXT(GLint first, GLsizei count)
{
	typedef void APIENTRY (*proc_type)(GLint first, GLsizei count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLockArraysEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLockArraysEXT" ); }
	return (*func_ptr)( first, count );
}

inline void APIENTRY glUnlockArraysEXT(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUnlockArraysEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUnlockArraysEXT" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glCullParameterdvEXT(GLenum pname, GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCullParameterdvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCullParameterdvEXT" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glCullParameterfvEXT(GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCullParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCullParameterfvEXT" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glFragmentColorMaterialSGIX(GLenum face, GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLenum face, GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentColorMaterialSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentColorMaterialSGIX" ); }
	return (*func_ptr)( face, mode );
}

inline void APIENTRY glFragmentLightfSGIX(GLenum light, GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLenum light, GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentLightfSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentLightfSGIX" ); }
	return (*func_ptr)( light, pname, param );
}

inline void APIENTRY glFragmentLightfvSGIX(GLenum light, GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum light, GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentLightfvSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentLightfvSGIX" ); }
	return (*func_ptr)( light, pname, params );
}

inline void APIENTRY glFragmentLightiSGIX(GLenum light, GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum light, GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentLightiSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentLightiSGIX" ); }
	return (*func_ptr)( light, pname, param );
}

inline void APIENTRY glFragmentLightivSGIX(GLenum light, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum light, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentLightivSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentLightivSGIX" ); }
	return (*func_ptr)( light, pname, params );
}

inline void APIENTRY glFragmentLightModelfSGIX(GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentLightModelfSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentLightModelfSGIX" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glFragmentLightModelfvSGIX(GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentLightModelfvSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentLightModelfvSGIX" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glFragmentLightModeliSGIX(GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentLightModeliSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentLightModeliSGIX" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glFragmentLightModelivSGIX(GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentLightModelivSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentLightModelivSGIX" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glFragmentMaterialfSGIX(GLenum face, GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLenum face, GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentMaterialfSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentMaterialfSGIX" ); }
	return (*func_ptr)( face, pname, param );
}

inline void APIENTRY glFragmentMaterialfvSGIX(GLenum face, GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum face, GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentMaterialfvSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentMaterialfvSGIX" ); }
	return (*func_ptr)( face, pname, params );
}

inline void APIENTRY glFragmentMaterialiSGIX(GLenum face, GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum face, GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentMaterialiSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentMaterialiSGIX" ); }
	return (*func_ptr)( face, pname, param );
}

inline void APIENTRY glFragmentMaterialivSGIX(GLenum face, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum face, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFragmentMaterialivSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFragmentMaterialivSGIX" ); }
	return (*func_ptr)( face, pname, params );
}

inline void APIENTRY glGetFragmentLightfvSGIX(GLenum light, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum light, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFragmentLightfvSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFragmentLightfvSGIX" ); }
	return (*func_ptr)( light, pname, params );
}

inline void APIENTRY glGetFragmentLightivSGIX(GLenum light, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum light, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFragmentLightivSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFragmentLightivSGIX" ); }
	return (*func_ptr)( light, pname, params );
}

inline void APIENTRY glGetFragmentMaterialfvSGIX(GLenum face, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum face, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFragmentMaterialfvSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFragmentMaterialfvSGIX" ); }
	return (*func_ptr)( face, pname, params );
}

inline void APIENTRY glGetFragmentMaterialivSGIX(GLenum face, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum face, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFragmentMaterialivSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFragmentMaterialivSGIX" ); }
	return (*func_ptr)( face, pname, params );
}

inline void APIENTRY glLightEnviSGIX(GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLightEnviSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLightEnviSGIX" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawRangeElementsEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawRangeElementsEXT" ); }
	return (*func_ptr)( mode, start, end, count, type, indices );
}

inline void APIENTRY glApplyTextureEXT(GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glApplyTextureEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glApplyTextureEXT" ); }
	return (*func_ptr)( mode );
}

inline void APIENTRY glTextureLightEXT(GLenum pname)
{
	typedef void APIENTRY (*proc_type)(GLenum pname);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureLightEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureLightEXT" ); }
	return (*func_ptr)( pname );
}

inline void APIENTRY glTextureMaterialEXT(GLenum face, GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLenum face, GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureMaterialEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureMaterialEXT" ); }
	return (*func_ptr)( face, mode );
}

inline void APIENTRY glAsyncMarkerSGIX(GLuint marker)
{
	typedef void APIENTRY (*proc_type)(GLuint marker);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glAsyncMarkerSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glAsyncMarkerSGIX" ); }
	return (*func_ptr)( marker );
}

inline GLint APIENTRY glFinishAsyncSGIX(GLuint *markerp)
{
	typedef GLint APIENTRY (*proc_type)(GLuint *markerp);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFinishAsyncSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFinishAsyncSGIX" ); }
	return (*func_ptr)( markerp );
}

inline GLint APIENTRY glPollAsyncSGIX(GLuint *markerp)
{
	typedef GLint APIENTRY (*proc_type)(GLuint *markerp);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPollAsyncSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPollAsyncSGIX" ); }
	return (*func_ptr)( markerp );
}

inline GLuint APIENTRY glGenAsyncMarkersSGIX(GLsizei range)
{
	typedef GLuint APIENTRY (*proc_type)(GLsizei range);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenAsyncMarkersSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenAsyncMarkersSGIX" ); }
	return (*func_ptr)( range );
}

inline void APIENTRY glDeleteAsyncMarkersSGIX(GLuint marker, GLsizei range)
{
	typedef void APIENTRY (*proc_type)(GLuint marker, GLsizei range);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteAsyncMarkersSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteAsyncMarkersSGIX" ); }
	return (*func_ptr)( marker, range );
}

inline GLboolean APIENTRY glIsAsyncMarkerSGIX(GLuint marker)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint marker);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsAsyncMarkerSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsAsyncMarkerSGIX" ); }
	return (*func_ptr)( marker );
}

inline void APIENTRY glVertexPointervINTEL(GLint size, GLenum type, const GLvoid* *pointer)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, const GLvoid* *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexPointervINTEL" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexPointervINTEL" ); }
	return (*func_ptr)( size, type, pointer );
}

inline void APIENTRY glNormalPointervINTEL(GLenum type, const GLvoid* *pointer)
{
	typedef void APIENTRY (*proc_type)(GLenum type, const GLvoid* *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalPointervINTEL" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalPointervINTEL" ); }
	return (*func_ptr)( type, pointer );
}

inline void APIENTRY glColorPointervINTEL(GLint size, GLenum type, const GLvoid* *pointer)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, const GLvoid* *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorPointervINTEL" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorPointervINTEL" ); }
	return (*func_ptr)( size, type, pointer );
}

inline void APIENTRY glTexCoordPointervINTEL(GLint size, GLenum type, const GLvoid* *pointer)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, const GLvoid* *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordPointervINTEL" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordPointervINTEL" ); }
	return (*func_ptr)( size, type, pointer );
}

inline void APIENTRY glPixelTransformParameteriEXT(GLenum target, GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTransformParameteriEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTransformParameteriEXT" ); }
	return (*func_ptr)( target, pname, param );
}

inline void APIENTRY glPixelTransformParameterfEXT(GLenum target, GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTransformParameterfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTransformParameterfEXT" ); }
	return (*func_ptr)( target, pname, param );
}

inline void APIENTRY glPixelTransformParameterivEXT(GLenum target, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTransformParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTransformParameterivEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glPixelTransformParameterfvEXT(GLenum target, GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelTransformParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelTransformParameterfvEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glSecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue)
{
	typedef void APIENTRY (*proc_type)(GLbyte red, GLbyte green, GLbyte blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3bEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3bEXT" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glSecondaryColor3bvEXT(const GLbyte *v)
{
	typedef void APIENTRY (*proc_type)(const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3bvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3bvEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glSecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue)
{
	typedef void APIENTRY (*proc_type)(GLdouble red, GLdouble green, GLdouble blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3dEXT" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glSecondaryColor3dvEXT(const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3dvEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glSecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue)
{
	typedef void APIENTRY (*proc_type)(GLfloat red, GLfloat green, GLfloat blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3fEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3fEXT" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glSecondaryColor3fvEXT(const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3fvEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glSecondaryColor3iEXT(GLint red, GLint green, GLint blue)
{
	typedef void APIENTRY (*proc_type)(GLint red, GLint green, GLint blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3iEXT" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glSecondaryColor3ivEXT(const GLint *v)
{
	typedef void APIENTRY (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3ivEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glSecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue)
{
	typedef void APIENTRY (*proc_type)(GLshort red, GLshort green, GLshort blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3sEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3sEXT" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glSecondaryColor3svEXT(const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3svEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3svEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glSecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue)
{
	typedef void APIENTRY (*proc_type)(GLubyte red, GLubyte green, GLubyte blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3ubEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3ubEXT" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glSecondaryColor3ubvEXT(const GLubyte *v)
{
	typedef void APIENTRY (*proc_type)(const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3ubvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3ubvEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glSecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue)
{
	typedef void APIENTRY (*proc_type)(GLuint red, GLuint green, GLuint blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3uiEXT" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glSecondaryColor3uivEXT(const GLuint *v)
{
	typedef void APIENTRY (*proc_type)(const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3uivEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glSecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue)
{
	typedef void APIENTRY (*proc_type)(GLushort red, GLushort green, GLushort blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3usEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3usEXT" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glSecondaryColor3usvEXT(const GLushort *v)
{
	typedef void APIENTRY (*proc_type)(const GLushort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3usvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3usvEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColorPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColorPointerEXT" ); }
	return (*func_ptr)( size, type, stride, pointer );
}

inline void APIENTRY glTextureNormalEXT(GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureNormalEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureNormalEXT" ); }
	return (*func_ptr)( mode );
}

inline void APIENTRY glMultiDrawArraysEXT(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawArraysEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawArraysEXT" ); }
	return (*func_ptr)( mode, first, count, primcount );
}

inline void APIENTRY glMultiDrawElementsEXT(GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawElementsEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawElementsEXT" ); }
	return (*func_ptr)( mode, count, type, indices, primcount );
}

inline void APIENTRY glFogCoordfEXT(GLfloat coord)
{
	typedef void APIENTRY (*proc_type)(GLfloat coord);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordfEXT" ); }
	return (*func_ptr)( coord );
}

inline void APIENTRY glFogCoordfvEXT(const GLfloat *coord)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *coord);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordfvEXT" ); }
	return (*func_ptr)( coord );
}

inline void APIENTRY glFogCoorddEXT(GLdouble coord)
{
	typedef void APIENTRY (*proc_type)(GLdouble coord);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoorddEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoorddEXT" ); }
	return (*func_ptr)( coord );
}

inline void APIENTRY glFogCoorddvEXT(const GLdouble *coord)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *coord);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoorddvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoorddvEXT" ); }
	return (*func_ptr)( coord );
}

inline void APIENTRY glFogCoordPointerEXT(GLenum type, GLsizei stride, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLsizei stride, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordPointerEXT" ); }
	return (*func_ptr)( type, stride, pointer );
}

inline void APIENTRY glTangent3bEXT(GLbyte tx, GLbyte ty, GLbyte tz)
{
	typedef void APIENTRY (*proc_type)(GLbyte tx, GLbyte ty, GLbyte tz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3bEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3bEXT" ); }
	return (*func_ptr)( tx, ty, tz );
}

inline void APIENTRY glTangent3bvEXT(const GLbyte *v)
{
	typedef void APIENTRY (*proc_type)(const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3bvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3bvEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glTangent3dEXT(GLdouble tx, GLdouble ty, GLdouble tz)
{
	typedef void APIENTRY (*proc_type)(GLdouble tx, GLdouble ty, GLdouble tz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3dEXT" ); }
	return (*func_ptr)( tx, ty, tz );
}

inline void APIENTRY glTangent3dvEXT(const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3dvEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glTangent3fEXT(GLfloat tx, GLfloat ty, GLfloat tz)
{
	typedef void APIENTRY (*proc_type)(GLfloat tx, GLfloat ty, GLfloat tz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3fEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3fEXT" ); }
	return (*func_ptr)( tx, ty, tz );
}

inline void APIENTRY glTangent3fvEXT(const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3fvEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glTangent3iEXT(GLint tx, GLint ty, GLint tz)
{
	typedef void APIENTRY (*proc_type)(GLint tx, GLint ty, GLint tz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3iEXT" ); }
	return (*func_ptr)( tx, ty, tz );
}

inline void APIENTRY glTangent3ivEXT(const GLint *v)
{
	typedef void APIENTRY (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3ivEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glTangent3sEXT(GLshort tx, GLshort ty, GLshort tz)
{
	typedef void APIENTRY (*proc_type)(GLshort tx, GLshort ty, GLshort tz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3sEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3sEXT" ); }
	return (*func_ptr)( tx, ty, tz );
}

inline void APIENTRY glTangent3svEXT(const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangent3svEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangent3svEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glBinormal3bEXT(GLbyte bx, GLbyte by, GLbyte bz)
{
	typedef void APIENTRY (*proc_type)(GLbyte bx, GLbyte by, GLbyte bz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3bEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3bEXT" ); }
	return (*func_ptr)( bx, by, bz );
}

inline void APIENTRY glBinormal3bvEXT(const GLbyte *v)
{
	typedef void APIENTRY (*proc_type)(const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3bvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3bvEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glBinormal3dEXT(GLdouble bx, GLdouble by, GLdouble bz)
{
	typedef void APIENTRY (*proc_type)(GLdouble bx, GLdouble by, GLdouble bz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3dEXT" ); }
	return (*func_ptr)( bx, by, bz );
}

inline void APIENTRY glBinormal3dvEXT(const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3dvEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glBinormal3fEXT(GLfloat bx, GLfloat by, GLfloat bz)
{
	typedef void APIENTRY (*proc_type)(GLfloat bx, GLfloat by, GLfloat bz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3fEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3fEXT" ); }
	return (*func_ptr)( bx, by, bz );
}

inline void APIENTRY glBinormal3fvEXT(const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3fvEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glBinormal3iEXT(GLint bx, GLint by, GLint bz)
{
	typedef void APIENTRY (*proc_type)(GLint bx, GLint by, GLint bz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3iEXT" ); }
	return (*func_ptr)( bx, by, bz );
}

inline void APIENTRY glBinormal3ivEXT(const GLint *v)
{
	typedef void APIENTRY (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3ivEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glBinormal3sEXT(GLshort bx, GLshort by, GLshort bz)
{
	typedef void APIENTRY (*proc_type)(GLshort bx, GLshort by, GLshort bz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3sEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3sEXT" ); }
	return (*func_ptr)( bx, by, bz );
}

inline void APIENTRY glBinormal3svEXT(const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormal3svEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormal3svEXT" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glTangentPointerEXT(GLenum type, GLsizei stride, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLsizei stride, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTangentPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTangentPointerEXT" ); }
	return (*func_ptr)( type, stride, pointer );
}

inline void APIENTRY glBinormalPointerEXT(GLenum type, GLsizei stride, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLsizei stride, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBinormalPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBinormalPointerEXT" ); }
	return (*func_ptr)( type, stride, pointer );
}

inline void APIENTRY glFinishTextureSUNX(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFinishTextureSUNX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFinishTextureSUNX" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glGlobalAlphaFactorbSUN(GLbyte factor)
{
	typedef void APIENTRY (*proc_type)(GLbyte factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGlobalAlphaFactorbSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGlobalAlphaFactorbSUN" ); }
	return (*func_ptr)( factor );
}

inline void APIENTRY glGlobalAlphaFactorsSUN(GLshort factor)
{
	typedef void APIENTRY (*proc_type)(GLshort factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGlobalAlphaFactorsSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGlobalAlphaFactorsSUN" ); }
	return (*func_ptr)( factor );
}

inline void APIENTRY glGlobalAlphaFactoriSUN(GLint factor)
{
	typedef void APIENTRY (*proc_type)(GLint factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGlobalAlphaFactoriSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGlobalAlphaFactoriSUN" ); }
	return (*func_ptr)( factor );
}

inline void APIENTRY glGlobalAlphaFactorfSUN(GLfloat factor)
{
	typedef void APIENTRY (*proc_type)(GLfloat factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGlobalAlphaFactorfSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGlobalAlphaFactorfSUN" ); }
	return (*func_ptr)( factor );
}

inline void APIENTRY glGlobalAlphaFactordSUN(GLdouble factor)
{
	typedef void APIENTRY (*proc_type)(GLdouble factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGlobalAlphaFactordSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGlobalAlphaFactordSUN" ); }
	return (*func_ptr)( factor );
}

inline void APIENTRY glGlobalAlphaFactorubSUN(GLubyte factor)
{
	typedef void APIENTRY (*proc_type)(GLubyte factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGlobalAlphaFactorubSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGlobalAlphaFactorubSUN" ); }
	return (*func_ptr)( factor );
}

inline void APIENTRY glGlobalAlphaFactorusSUN(GLushort factor)
{
	typedef void APIENTRY (*proc_type)(GLushort factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGlobalAlphaFactorusSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGlobalAlphaFactorusSUN" ); }
	return (*func_ptr)( factor );
}

inline void APIENTRY glGlobalAlphaFactoruiSUN(GLuint factor)
{
	typedef void APIENTRY (*proc_type)(GLuint factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGlobalAlphaFactoruiSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGlobalAlphaFactoruiSUN" ); }
	return (*func_ptr)( factor );
}

inline void APIENTRY glReplacementCodeuiSUN(GLuint code)
{
	typedef void APIENTRY (*proc_type)(GLuint code);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiSUN" ); }
	return (*func_ptr)( code );
}

inline void APIENTRY glReplacementCodeusSUN(GLushort code)
{
	typedef void APIENTRY (*proc_type)(GLushort code);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeusSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeusSUN" ); }
	return (*func_ptr)( code );
}

inline void APIENTRY glReplacementCodeubSUN(GLubyte code)
{
	typedef void APIENTRY (*proc_type)(GLubyte code);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeubSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeubSUN" ); }
	return (*func_ptr)( code );
}

inline void APIENTRY glReplacementCodeuivSUN(const GLuint *code)
{
	typedef void APIENTRY (*proc_type)(const GLuint *code);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuivSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuivSUN" ); }
	return (*func_ptr)( code );
}

inline void APIENTRY glReplacementCodeusvSUN(const GLushort *code)
{
	typedef void APIENTRY (*proc_type)(const GLushort *code);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeusvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeusvSUN" ); }
	return (*func_ptr)( code );
}

inline void APIENTRY glReplacementCodeubvSUN(const GLubyte *code)
{
	typedef void APIENTRY (*proc_type)(const GLubyte *code);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeubvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeubvSUN" ); }
	return (*func_ptr)( code );
}

inline void APIENTRY glReplacementCodePointerSUN(GLenum type, GLsizei stride, const GLvoid* *pointer)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLsizei stride, const GLvoid* *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodePointerSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodePointerSUN" ); }
	return (*func_ptr)( type, stride, pointer );
}

inline void APIENTRY glColor4ubVertex2fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y)
{
	typedef void APIENTRY (*proc_type)(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor4ubVertex2fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor4ubVertex2fSUN" ); }
	return (*func_ptr)( r, g, b, a, x, y );
}

inline void APIENTRY glColor4ubVertex2fvSUN(const GLubyte *c, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLubyte *c, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor4ubVertex2fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor4ubVertex2fvSUN" ); }
	return (*func_ptr)( c, v );
}

inline void APIENTRY glColor4ubVertex3fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor4ubVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor4ubVertex3fSUN" ); }
	return (*func_ptr)( r, g, b, a, x, y, z );
}

inline void APIENTRY glColor4ubVertex3fvSUN(const GLubyte *c, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLubyte *c, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor4ubVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor4ubVertex3fvSUN" ); }
	return (*func_ptr)( c, v );
}

inline void APIENTRY glColor3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor3fVertex3fSUN" ); }
	return (*func_ptr)( r, g, b, x, y, z );
}

inline void APIENTRY glColor3fVertex3fvSUN(const GLfloat *c, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *c, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor3fVertex3fvSUN" ); }
	return (*func_ptr)( c, v );
}

inline void APIENTRY glNormal3fVertex3fSUN(GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormal3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormal3fVertex3fSUN" ); }
	return (*func_ptr)( nx, ny, nz, x, y, z );
}

inline void APIENTRY glNormal3fVertex3fvSUN(const GLfloat *n, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *n, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormal3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormal3fVertex3fvSUN" ); }
	return (*func_ptr)( n, v );
}

inline void APIENTRY glColor4fNormal3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor4fNormal3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor4fNormal3fVertex3fSUN" ); }
	return (*func_ptr)( r, g, b, a, nx, ny, nz, x, y, z );
}

inline void APIENTRY glColor4fNormal3fVertex3fvSUN(const GLfloat *c, const GLfloat *n, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *c, const GLfloat *n, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor4fNormal3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor4fNormal3fVertex3fvSUN" ); }
	return (*func_ptr)( c, n, v );
}

inline void APIENTRY glTexCoord2fVertex3fSUN(GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fVertex3fSUN" ); }
	return (*func_ptr)( s, t, x, y, z );
}

inline void APIENTRY glTexCoord2fVertex3fvSUN(const GLfloat *tc, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *tc, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fVertex3fvSUN" ); }
	return (*func_ptr)( tc, v );
}

inline void APIENTRY glTexCoord4fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	typedef void APIENTRY (*proc_type)(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord4fVertex4fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord4fVertex4fSUN" ); }
	return (*func_ptr)( s, t, p, q, x, y, z, w );
}

inline void APIENTRY glTexCoord4fVertex4fvSUN(const GLfloat *tc, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *tc, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord4fVertex4fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord4fVertex4fvSUN" ); }
	return (*func_ptr)( tc, v );
}

inline void APIENTRY glTexCoord2fColor4ubVertex3fSUN(GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fColor4ubVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fColor4ubVertex3fSUN" ); }
	return (*func_ptr)( s, t, r, g, b, a, x, y, z );
}

inline void APIENTRY glTexCoord2fColor4ubVertex3fvSUN(const GLfloat *tc, const GLubyte *c, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *tc, const GLubyte *c, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fColor4ubVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fColor4ubVertex3fvSUN" ); }
	return (*func_ptr)( tc, c, v );
}

inline void APIENTRY glTexCoord2fColor3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fColor3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fColor3fVertex3fSUN" ); }
	return (*func_ptr)( s, t, r, g, b, x, y, z );
}

inline void APIENTRY glTexCoord2fColor3fVertex3fvSUN(const GLfloat *tc, const GLfloat *c, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *tc, const GLfloat *c, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fColor3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fColor3fVertex3fvSUN" ); }
	return (*func_ptr)( tc, c, v );
}

inline void APIENTRY glTexCoord2fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fNormal3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fNormal3fVertex3fSUN" ); }
	return (*func_ptr)( s, t, nx, ny, nz, x, y, z );
}

inline void APIENTRY glTexCoord2fNormal3fVertex3fvSUN(const GLfloat *tc, const GLfloat *n, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *tc, const GLfloat *n, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fNormal3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fNormal3fVertex3fvSUN" ); }
	return (*func_ptr)( tc, n, v );
}

inline void APIENTRY glTexCoord2fColor4fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fColor4fNormal3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fColor4fNormal3fVertex3fSUN" ); }
	return (*func_ptr)( s, t, r, g, b, a, nx, ny, nz, x, y, z );
}

inline void APIENTRY glTexCoord2fColor4fNormal3fVertex3fvSUN(const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2fColor4fNormal3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2fColor4fNormal3fVertex3fvSUN" ); }
	return (*func_ptr)( tc, c, n, v );
}

inline void APIENTRY glTexCoord4fColor4fNormal3fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	typedef void APIENTRY (*proc_type)(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord4fColor4fNormal3fVertex4fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord4fColor4fNormal3fVertex4fSUN" ); }
	return (*func_ptr)( s, t, p, q, r, g, b, a, nx, ny, nz, x, y, z, w );
}

inline void APIENTRY glTexCoord4fColor4fNormal3fVertex4fvSUN(const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord4fColor4fNormal3fVertex4fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord4fColor4fNormal3fVertex4fvSUN" ); }
	return (*func_ptr)( tc, c, n, v );
}

inline void APIENTRY glReplacementCodeuiVertex3fSUN(GLuint rc, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLuint rc, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiVertex3fSUN" ); }
	return (*func_ptr)( rc, x, y, z );
}

inline void APIENTRY glReplacementCodeuiVertex3fvSUN(const GLuint *rc, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLuint *rc, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiVertex3fvSUN" ); }
	return (*func_ptr)( rc, v );
}

inline void APIENTRY glReplacementCodeuiColor4ubVertex3fSUN(GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiColor4ubVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiColor4ubVertex3fSUN" ); }
	return (*func_ptr)( rc, r, g, b, a, x, y, z );
}

inline void APIENTRY glReplacementCodeuiColor4ubVertex3fvSUN(const GLuint *rc, const GLubyte *c, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLuint *rc, const GLubyte *c, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiColor4ubVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiColor4ubVertex3fvSUN" ); }
	return (*func_ptr)( rc, c, v );
}

inline void APIENTRY glReplacementCodeuiColor3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiColor3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiColor3fVertex3fSUN" ); }
	return (*func_ptr)( rc, r, g, b, x, y, z );
}

inline void APIENTRY glReplacementCodeuiColor3fVertex3fvSUN(const GLuint *rc, const GLfloat *c, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLuint *rc, const GLfloat *c, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiColor3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiColor3fVertex3fvSUN" ); }
	return (*func_ptr)( rc, c, v );
}

inline void APIENTRY glReplacementCodeuiNormal3fVertex3fSUN(GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiNormal3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiNormal3fVertex3fSUN" ); }
	return (*func_ptr)( rc, nx, ny, nz, x, y, z );
}

inline void APIENTRY glReplacementCodeuiNormal3fVertex3fvSUN(const GLuint *rc, const GLfloat *n, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLuint *rc, const GLfloat *n, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiNormal3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiNormal3fVertex3fvSUN" ); }
	return (*func_ptr)( rc, n, v );
}

inline void APIENTRY glReplacementCodeuiColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiColor4fNormal3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiColor4fNormal3fVertex3fSUN" ); }
	return (*func_ptr)( rc, r, g, b, a, nx, ny, nz, x, y, z );
}

inline void APIENTRY glReplacementCodeuiColor4fNormal3fVertex3fvSUN(const GLuint *rc, const GLfloat *c, const GLfloat *n, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLuint *rc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiColor4fNormal3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiColor4fNormal3fVertex3fvSUN" ); }
	return (*func_ptr)( rc, c, n, v );
}

inline void APIENTRY glReplacementCodeuiTexCoord2fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiTexCoord2fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiTexCoord2fVertex3fSUN" ); }
	return (*func_ptr)( rc, s, t, x, y, z );
}

inline void APIENTRY glReplacementCodeuiTexCoord2fVertex3fvSUN(const GLuint *rc, const GLfloat *tc, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLuint *rc, const GLfloat *tc, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiTexCoord2fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiTexCoord2fVertex3fvSUN" ); }
	return (*func_ptr)( rc, tc, v );
}

inline void APIENTRY glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN" ); }
	return (*func_ptr)( rc, s, t, nx, ny, nz, x, y, z );
}

inline void APIENTRY glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(const GLuint *rc, const GLfloat *tc, const GLfloat *n, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLuint *rc, const GLfloat *tc, const GLfloat *n, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN" ); }
	return (*func_ptr)( rc, tc, n, v );
}

inline void APIENTRY glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN" ); }
	return (*func_ptr)( rc, s, t, r, g, b, a, nx, ny, nz, x, y, z );
}

inline void APIENTRY glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(const GLuint *rc, const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLuint *rc, const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN" ); }
	return (*func_ptr)( rc, tc, c, n, v );
}

inline void APIENTRY glBlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
	typedef void APIENTRY (*proc_type)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFuncSeparateEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFuncSeparateEXT" ); }
	return (*func_ptr)( sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha );
}

inline void APIENTRY glBlendFuncSeparateINGR(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
	typedef void APIENTRY (*proc_type)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFuncSeparateINGR" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFuncSeparateINGR" ); }
	return (*func_ptr)( sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha );
}

inline void APIENTRY glVertexWeightfEXT(GLfloat weight)
{
	typedef void APIENTRY (*proc_type)(GLfloat weight);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexWeightfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexWeightfEXT" ); }
	return (*func_ptr)( weight );
}

inline void APIENTRY glVertexWeightfvEXT(const GLfloat *weight)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *weight);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexWeightfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexWeightfvEXT" ); }
	return (*func_ptr)( weight );
}

inline void APIENTRY glVertexWeightPointerEXT(GLsizei size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLsizei size, GLenum type, GLsizei stride, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexWeightPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexWeightPointerEXT" ); }
	return (*func_ptr)( size, type, stride, pointer );
}

inline void APIENTRY glFlushVertexArrayRangeNV(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFlushVertexArrayRangeNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFlushVertexArrayRangeNV" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glVertexArrayRangeNV(GLsizei length, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLsizei length, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexArrayRangeNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexArrayRangeNV" ); }
	return (*func_ptr)( length, pointer );
}

inline void APIENTRY glCombinerParameterfvNV(GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCombinerParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCombinerParameterfvNV" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glCombinerParameterfNV(GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCombinerParameterfNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCombinerParameterfNV" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glCombinerParameterivNV(GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCombinerParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCombinerParameterivNV" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glCombinerParameteriNV(GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCombinerParameteriNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCombinerParameteriNV" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glCombinerInputNV(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage)
{
	typedef void APIENTRY (*proc_type)(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCombinerInputNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCombinerInputNV" ); }
	return (*func_ptr)( stage, portion, variable, input, mapping, componentUsage );
}

inline void APIENTRY glCombinerOutputNV(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum)
{
	typedef void APIENTRY (*proc_type)(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCombinerOutputNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCombinerOutputNV" ); }
	return (*func_ptr)( stage, portion, abOutput, cdOutput, sumOutput, scale, bias, abDotProduct, cdDotProduct, muxSum );
}

inline void APIENTRY glFinalCombinerInputNV(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage)
{
	typedef void APIENTRY (*proc_type)(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFinalCombinerInputNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFinalCombinerInputNV" ); }
	return (*func_ptr)( variable, input, mapping, componentUsage );
}

inline void APIENTRY glGetCombinerInputParameterfvNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCombinerInputParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCombinerInputParameterfvNV" ); }
	return (*func_ptr)( stage, portion, variable, pname, params );
}

inline void APIENTRY glGetCombinerInputParameterivNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCombinerInputParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCombinerInputParameterivNV" ); }
	return (*func_ptr)( stage, portion, variable, pname, params );
}

inline void APIENTRY glGetCombinerOutputParameterfvNV(GLenum stage, GLenum portion, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum stage, GLenum portion, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCombinerOutputParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCombinerOutputParameterfvNV" ); }
	return (*func_ptr)( stage, portion, pname, params );
}

inline void APIENTRY glGetCombinerOutputParameterivNV(GLenum stage, GLenum portion, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum stage, GLenum portion, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCombinerOutputParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCombinerOutputParameterivNV" ); }
	return (*func_ptr)( stage, portion, pname, params );
}

inline void APIENTRY glGetFinalCombinerInputParameterfvNV(GLenum variable, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum variable, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFinalCombinerInputParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFinalCombinerInputParameterfvNV" ); }
	return (*func_ptr)( variable, pname, params );
}

inline void APIENTRY glGetFinalCombinerInputParameterivNV(GLenum variable, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum variable, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFinalCombinerInputParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFinalCombinerInputParameterivNV" ); }
	return (*func_ptr)( variable, pname, params );
}

inline void APIENTRY glResizeBuffersMESA(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glResizeBuffersMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glResizeBuffersMESA" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glWindowPos2dMESA(GLdouble x, GLdouble y)
{
	typedef void APIENTRY (*proc_type)(GLdouble x, GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2dMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2dMESA" ); }
	return (*func_ptr)( x, y );
}

inline void APIENTRY glWindowPos2dvMESA(const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2dvMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2dvMESA" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos2fMESA(GLfloat x, GLfloat y)
{
	typedef void APIENTRY (*proc_type)(GLfloat x, GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2fMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2fMESA" ); }
	return (*func_ptr)( x, y );
}

inline void APIENTRY glWindowPos2fvMESA(const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2fvMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2fvMESA" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos2iMESA(GLint x, GLint y)
{
	typedef void APIENTRY (*proc_type)(GLint x, GLint y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2iMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2iMESA" ); }
	return (*func_ptr)( x, y );
}

inline void APIENTRY glWindowPos2ivMESA(const GLint *v)
{
	typedef void APIENTRY (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2ivMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2ivMESA" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos2sMESA(GLshort x, GLshort y)
{
	typedef void APIENTRY (*proc_type)(GLshort x, GLshort y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2sMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2sMESA" ); }
	return (*func_ptr)( x, y );
}

inline void APIENTRY glWindowPos2svMESA(const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos2svMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos2svMESA" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos3dMESA(GLdouble x, GLdouble y, GLdouble z)
{
	typedef void APIENTRY (*proc_type)(GLdouble x, GLdouble y, GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3dMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3dMESA" ); }
	return (*func_ptr)( x, y, z );
}

inline void APIENTRY glWindowPos3dvMESA(const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3dvMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3dvMESA" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos3fMESA(GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3fMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3fMESA" ); }
	return (*func_ptr)( x, y, z );
}

inline void APIENTRY glWindowPos3fvMESA(const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3fvMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3fvMESA" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos3iMESA(GLint x, GLint y, GLint z)
{
	typedef void APIENTRY (*proc_type)(GLint x, GLint y, GLint z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3iMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3iMESA" ); }
	return (*func_ptr)( x, y, z );
}

inline void APIENTRY glWindowPos3ivMESA(const GLint *v)
{
	typedef void APIENTRY (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3ivMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3ivMESA" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos3sMESA(GLshort x, GLshort y, GLshort z)
{
	typedef void APIENTRY (*proc_type)(GLshort x, GLshort y, GLshort z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3sMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3sMESA" ); }
	return (*func_ptr)( x, y, z );
}

inline void APIENTRY glWindowPos3svMESA(const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos3svMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos3svMESA" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos4dMESA(GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	typedef void APIENTRY (*proc_type)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos4dMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos4dMESA" ); }
	return (*func_ptr)( x, y, z, w );
}

inline void APIENTRY glWindowPos4dvMESA(const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos4dvMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos4dvMESA" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos4fMESA(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	typedef void APIENTRY (*proc_type)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos4fMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos4fMESA" ); }
	return (*func_ptr)( x, y, z, w );
}

inline void APIENTRY glWindowPos4fvMESA(const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos4fvMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos4fvMESA" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos4iMESA(GLint x, GLint y, GLint z, GLint w)
{
	typedef void APIENTRY (*proc_type)(GLint x, GLint y, GLint z, GLint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos4iMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos4iMESA" ); }
	return (*func_ptr)( x, y, z, w );
}

inline void APIENTRY glWindowPos4ivMESA(const GLint *v)
{
	typedef void APIENTRY (*proc_type)(const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos4ivMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos4ivMESA" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glWindowPos4sMESA(GLshort x, GLshort y, GLshort z, GLshort w)
{
	typedef void APIENTRY (*proc_type)(GLshort x, GLshort y, GLshort z, GLshort w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos4sMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos4sMESA" ); }
	return (*func_ptr)( x, y, z, w );
}

inline void APIENTRY glWindowPos4svMESA(const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWindowPos4svMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWindowPos4svMESA" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glMultiModeDrawArraysIBM(const GLenum *mode, const GLint *first, const GLsizei *count, GLsizei primcount, GLint modestride)
{
	typedef void APIENTRY (*proc_type)(const GLenum *mode, const GLint *first, const GLsizei *count, GLsizei primcount, GLint modestride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiModeDrawArraysIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiModeDrawArraysIBM" ); }
	return (*func_ptr)( mode, first, count, primcount, modestride );
}

inline void APIENTRY glMultiModeDrawElementsIBM(const GLenum *mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei primcount, GLint modestride)
{
	typedef void APIENTRY (*proc_type)(const GLenum *mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei primcount, GLint modestride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiModeDrawElementsIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiModeDrawElementsIBM" ); }
	return (*func_ptr)( mode, count, type, indices, primcount, modestride );
}

inline void APIENTRY glColorPointerListIBM(GLint size, GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorPointerListIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorPointerListIBM" ); }
	return (*func_ptr)( size, type, stride, pointer, ptrstride );
}

inline void APIENTRY glSecondaryColorPointerListIBM(GLint size, GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColorPointerListIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColorPointerListIBM" ); }
	return (*func_ptr)( size, type, stride, pointer, ptrstride );
}

inline void APIENTRY glEdgeFlagPointerListIBM(GLint stride, const GLboolean* *pointer, GLint ptrstride)
{
	typedef void APIENTRY (*proc_type)(GLint stride, const GLboolean* *pointer, GLint ptrstride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEdgeFlagPointerListIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEdgeFlagPointerListIBM" ); }
	return (*func_ptr)( stride, pointer, ptrstride );
}

inline void APIENTRY glFogCoordPointerListIBM(GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordPointerListIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordPointerListIBM" ); }
	return (*func_ptr)( type, stride, pointer, ptrstride );
}

inline void APIENTRY glIndexPointerListIBM(GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIndexPointerListIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIndexPointerListIBM" ); }
	return (*func_ptr)( type, stride, pointer, ptrstride );
}

inline void APIENTRY glNormalPointerListIBM(GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalPointerListIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalPointerListIBM" ); }
	return (*func_ptr)( type, stride, pointer, ptrstride );
}

inline void APIENTRY glTexCoordPointerListIBM(GLint size, GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordPointerListIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordPointerListIBM" ); }
	return (*func_ptr)( size, type, stride, pointer, ptrstride );
}

inline void APIENTRY glVertexPointerListIBM(GLint size, GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexPointerListIBM" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexPointerListIBM" ); }
	return (*func_ptr)( size, type, stride, pointer, ptrstride );
}

inline void APIENTRY glTbufferMask3DFX(GLuint mask)
{
	typedef void APIENTRY (*proc_type)(GLuint mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTbufferMask3DFX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTbufferMask3DFX" ); }
	return (*func_ptr)( mask );
}

inline void APIENTRY glSampleMaskEXT(GLclampf value, GLboolean invert)
{
	typedef void APIENTRY (*proc_type)(GLclampf value, GLboolean invert);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSampleMaskEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSampleMaskEXT" ); }
	return (*func_ptr)( value, invert );
}

inline void APIENTRY glSamplePatternEXT(GLenum pattern)
{
	typedef void APIENTRY (*proc_type)(GLenum pattern);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSamplePatternEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSamplePatternEXT" ); }
	return (*func_ptr)( pattern );
}

inline void APIENTRY glTextureColorMaskSGIS(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
	typedef void APIENTRY (*proc_type)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureColorMaskSGIS" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureColorMaskSGIS" ); }
	return (*func_ptr)( red, green, blue, alpha );
}

inline void APIENTRY glIglooInterfaceSGIX(GLenum pname, const GLvoid *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLvoid *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIglooInterfaceSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIglooInterfaceSGIX" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glDeleteFencesNV(GLsizei n, const GLuint *fences)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *fences);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteFencesNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteFencesNV" ); }
	return (*func_ptr)( n, fences );
}

inline void APIENTRY glGenFencesNV(GLsizei n, GLuint *fences)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *fences);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenFencesNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenFencesNV" ); }
	return (*func_ptr)( n, fences );
}

inline GLboolean APIENTRY glIsFenceNV(GLuint fence)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint fence);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsFenceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsFenceNV" ); }
	return (*func_ptr)( fence );
}

inline GLboolean APIENTRY glTestFenceNV(GLuint fence)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint fence);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTestFenceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTestFenceNV" ); }
	return (*func_ptr)( fence );
}

inline void APIENTRY glGetFenceivNV(GLuint fence, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint fence, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFenceivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFenceivNV" ); }
	return (*func_ptr)( fence, pname, params );
}

inline void APIENTRY glFinishFenceNV(GLuint fence)
{
	typedef void APIENTRY (*proc_type)(GLuint fence);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFinishFenceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFinishFenceNV" ); }
	return (*func_ptr)( fence );
}

inline void APIENTRY glSetFenceNV(GLuint fence, GLenum condition)
{
	typedef void APIENTRY (*proc_type)(GLuint fence, GLenum condition);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSetFenceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSetFenceNV" ); }
	return (*func_ptr)( fence, condition );
}

inline void APIENTRY glMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const GLvoid *points)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const GLvoid *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapControlPointsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapControlPointsNV" ); }
	return (*func_ptr)( target, index, type, ustride, vstride, uorder, vorder, packed, points );
}

inline void APIENTRY glMapParameterivNV(GLenum target, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapParameterivNV" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glMapParameterfvNV(GLenum target, GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapParameterfvNV" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, GLvoid *points)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, GLvoid *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMapControlPointsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMapControlPointsNV" ); }
	return (*func_ptr)( target, index, type, ustride, vstride, packed, points );
}

inline void APIENTRY glGetMapParameterivNV(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMapParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMapParameterivNV" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetMapParameterfvNV(GLenum target, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMapParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMapParameterfvNV" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetMapAttribParameterivNV(GLenum target, GLuint index, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMapAttribParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMapAttribParameterivNV" ); }
	return (*func_ptr)( target, index, pname, params );
}

inline void APIENTRY glGetMapAttribParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMapAttribParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMapAttribParameterfvNV" ); }
	return (*func_ptr)( target, index, pname, params );
}

inline void APIENTRY glEvalMapsNV(GLenum target, GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEvalMapsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEvalMapsNV" ); }
	return (*func_ptr)( target, mode );
}

inline void APIENTRY glCombinerStageParameterfvNV(GLenum stage, GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum stage, GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCombinerStageParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCombinerStageParameterfvNV" ); }
	return (*func_ptr)( stage, pname, params );
}

inline void APIENTRY glGetCombinerStageParameterfvNV(GLenum stage, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum stage, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCombinerStageParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCombinerStageParameterfvNV" ); }
	return (*func_ptr)( stage, pname, params );
}

inline GLboolean APIENTRY glAreProgramsResidentNV(GLsizei n, const GLuint *programs, GLboolean *residences)
{
	typedef GLboolean APIENTRY (*proc_type)(GLsizei n, const GLuint *programs, GLboolean *residences);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glAreProgramsResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glAreProgramsResidentNV" ); }
	return (*func_ptr)( n, programs, residences );
}

inline void APIENTRY glBindProgramNV(GLenum target, GLuint id)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindProgramNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindProgramNV" ); }
	return (*func_ptr)( target, id );
}

inline void APIENTRY glDeleteProgramsNV(GLsizei n, const GLuint *programs)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *programs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteProgramsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteProgramsNV" ); }
	return (*func_ptr)( n, programs );
}

inline void APIENTRY glExecuteProgramNV(GLenum target, GLuint id, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint id, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glExecuteProgramNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glExecuteProgramNV" ); }
	return (*func_ptr)( target, id, params );
}

inline void APIENTRY glGenProgramsNV(GLsizei n, GLuint *programs)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *programs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenProgramsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenProgramsNV" ); }
	return (*func_ptr)( n, programs );
}

inline void APIENTRY glGetProgramParameterdvNV(GLenum target, GLuint index, GLenum pname, GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLenum pname, GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramParameterdvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramParameterdvNV" ); }
	return (*func_ptr)( target, index, pname, params );
}

inline void APIENTRY glGetProgramParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramParameterfvNV" ); }
	return (*func_ptr)( target, index, pname, params );
}

inline void APIENTRY glGetProgramivNV(GLuint id, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramivNV" ); }
	return (*func_ptr)( id, pname, params );
}

inline void APIENTRY glGetProgramStringNV(GLuint id, GLenum pname, GLubyte *program)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum pname, GLubyte *program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramStringNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramStringNV" ); }
	return (*func_ptr)( id, pname, program );
}

inline void APIENTRY glGetTrackMatrixivNV(GLenum target, GLuint address, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint address, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTrackMatrixivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTrackMatrixivNV" ); }
	return (*func_ptr)( target, address, pname, params );
}

inline void APIENTRY glGetVertexAttribdvNV(GLuint index, GLenum pname, GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribdvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribdvNV" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glGetVertexAttribfvNV(GLuint index, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribfvNV" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glGetVertexAttribivNV(GLuint index, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribivNV" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glGetVertexAttribPointervNV(GLuint index, GLenum pname, GLvoid* *pointer)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLvoid* *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribPointervNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribPointervNV" ); }
	return (*func_ptr)( index, pname, pointer );
}

inline GLboolean APIENTRY glIsProgramNV(GLuint id)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsProgramNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsProgramNV" ); }
	return (*func_ptr)( id );
}

inline void APIENTRY glLoadProgramNV(GLenum target, GLuint id, GLsizei len, const GLubyte *program)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint id, GLsizei len, const GLubyte *program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glLoadProgramNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glLoadProgramNV" ); }
	return (*func_ptr)( target, id, len, program );
}

inline void APIENTRY glProgramParameter4dNV(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameter4dNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameter4dNV" ); }
	return (*func_ptr)( target, index, x, y, z, w );
}

inline void APIENTRY glProgramParameter4dvNV(GLenum target, GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameter4dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameter4dvNV" ); }
	return (*func_ptr)( target, index, v );
}

inline void APIENTRY glProgramParameter4fNV(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameter4fNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameter4fNV" ); }
	return (*func_ptr)( target, index, x, y, z, w );
}

inline void APIENTRY glProgramParameter4fvNV(GLenum target, GLuint index, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameter4fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameter4fvNV" ); }
	return (*func_ptr)( target, index, v );
}

inline void APIENTRY glProgramParameters4dvNV(GLenum target, GLuint index, GLsizei count, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLsizei count, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameters4dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameters4dvNV" ); }
	return (*func_ptr)( target, index, count, v );
}

inline void APIENTRY glProgramParameters4fvNV(GLenum target, GLuint index, GLsizei count, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLsizei count, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameters4fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameters4fvNV" ); }
	return (*func_ptr)( target, index, count, v );
}

inline void APIENTRY glRequestResidentProgramsNV(GLsizei n, const GLuint *programs)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *programs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glRequestResidentProgramsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glRequestResidentProgramsNV" ); }
	return (*func_ptr)( n, programs );
}

inline void APIENTRY glTrackMatrixNV(GLenum target, GLuint address, GLenum matrix, GLenum transform)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint address, GLenum matrix, GLenum transform);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTrackMatrixNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTrackMatrixNV" ); }
	return (*func_ptr)( target, address, matrix, transform );
}

inline void APIENTRY glVertexAttribPointerNV(GLuint index, GLint fsize, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint fsize, GLenum type, GLsizei stride, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribPointerNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribPointerNV" ); }
	return (*func_ptr)( index, fsize, type, stride, pointer );
}

inline void APIENTRY glVertexAttrib1dNV(GLuint index, GLdouble x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1dNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1dNV" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttrib1dvNV(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1dvNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib1fNV(GLuint index, GLfloat x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLfloat x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1fNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1fNV" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttrib1fvNV(GLuint index, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1fvNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib1sNV(GLuint index, GLshort x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLshort x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1sNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1sNV" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttrib1svNV(GLuint index, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1svNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1svNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib2dNV(GLuint index, GLdouble x, GLdouble y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x, GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2dNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2dNV" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttrib2dvNV(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2dvNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib2fNV(GLuint index, GLfloat x, GLfloat y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLfloat x, GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2fNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2fNV" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttrib2fvNV(GLuint index, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2fvNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib2sNV(GLuint index, GLshort x, GLshort y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLshort x, GLshort y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2sNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2sNV" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttrib2svNV(GLuint index, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2svNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2svNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib3dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3dNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3dNV" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttrib3dvNV(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3dvNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib3fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3fNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3fNV" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttrib3fvNV(GLuint index, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3fvNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib3sNV(GLuint index, GLshort x, GLshort y, GLshort z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLshort x, GLshort y, GLshort z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3sNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3sNV" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttrib3svNV(GLuint index, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3svNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3svNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4dNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4dNV" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttrib4dvNV(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4dvNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4fNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4fNV" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttrib4fvNV(GLuint index, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4fvNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4sNV(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4sNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4sNV" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttrib4svNV(GLuint index, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4svNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4svNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4ubNV(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4ubNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4ubNV" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttrib4ubvNV(GLuint index, const GLubyte *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4ubvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4ubvNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribs1dvNV(GLuint index, GLsizei count, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLsizei count, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs1dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs1dvNV" ); }
	return (*func_ptr)( index, count, v );
}

inline void APIENTRY glVertexAttribs1fvNV(GLuint index, GLsizei count, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLsizei count, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs1fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs1fvNV" ); }
	return (*func_ptr)( index, count, v );
}

inline void APIENTRY glVertexAttribs1svNV(GLuint index, GLsizei count, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLsizei count, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs1svNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs1svNV" ); }
	return (*func_ptr)( index, count, v );
}

inline void APIENTRY glVertexAttribs2dvNV(GLuint index, GLsizei count, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLsizei count, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs2dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs2dvNV" ); }
	return (*func_ptr)( index, count, v );
}

inline void APIENTRY glVertexAttribs2fvNV(GLuint index, GLsizei count, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLsizei count, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs2fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs2fvNV" ); }
	return (*func_ptr)( index, count, v );
}

inline void APIENTRY glVertexAttribs2svNV(GLuint index, GLsizei count, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLsizei count, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs2svNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs2svNV" ); }
	return (*func_ptr)( index, count, v );
}

inline void APIENTRY glVertexAttribs3dvNV(GLuint index, GLsizei count, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLsizei count, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs3dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs3dvNV" ); }
	return (*func_ptr)( index, count, v );
}

inline void APIENTRY glVertexAttribs3fvNV(GLuint index, GLsizei count, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLsizei count, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs3fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs3fvNV" ); }
	return (*func_ptr)( index, count, v );
}

inline void APIENTRY glVertexAttribs3svNV(GLuint index, GLsizei count, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLsizei count, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs3svNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs3svNV" ); }
	return (*func_ptr)( index, count, v );
}

inline void APIENTRY glVertexAttribs4dvNV(GLuint index, GLsizei count, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLsizei count, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs4dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs4dvNV" ); }
	return (*func_ptr)( index, count, v );
}

inline void APIENTRY glVertexAttribs4fvNV(GLuint index, GLsizei count, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLsizei count, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs4fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs4fvNV" ); }
	return (*func_ptr)( index, count, v );
}

inline void APIENTRY glVertexAttribs4svNV(GLuint index, GLsizei count, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLsizei count, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs4svNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs4svNV" ); }
	return (*func_ptr)( index, count, v );
}

inline void APIENTRY glVertexAttribs4ubvNV(GLuint index, GLsizei count, const GLubyte *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLsizei count, const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs4ubvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs4ubvNV" ); }
	return (*func_ptr)( index, count, v );
}

inline void APIENTRY glTexBumpParameterivATI(GLenum pname, const GLint *param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLint *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexBumpParameterivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexBumpParameterivATI" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glTexBumpParameterfvATI(GLenum pname, const GLfloat *param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLfloat *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexBumpParameterfvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexBumpParameterfvATI" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glGetTexBumpParameterivATI(GLenum pname, GLint *param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLint *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTexBumpParameterivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTexBumpParameterivATI" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glGetTexBumpParameterfvATI(GLenum pname, GLfloat *param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLfloat *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTexBumpParameterfvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTexBumpParameterfvATI" ); }
	return (*func_ptr)( pname, param );
}

inline GLuint APIENTRY glGenFragmentShadersATI(GLuint range)
{
	typedef GLuint APIENTRY (*proc_type)(GLuint range);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenFragmentShadersATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenFragmentShadersATI" ); }
	return (*func_ptr)( range );
}

inline void APIENTRY glBindFragmentShaderATI(GLuint id)
{
	typedef void APIENTRY (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindFragmentShaderATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindFragmentShaderATI" ); }
	return (*func_ptr)( id );
}

inline void APIENTRY glDeleteFragmentShaderATI(GLuint id)
{
	typedef void APIENTRY (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteFragmentShaderATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteFragmentShaderATI" ); }
	return (*func_ptr)( id );
}

inline void APIENTRY glBeginFragmentShaderATI(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginFragmentShaderATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginFragmentShaderATI" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glEndFragmentShaderATI(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndFragmentShaderATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndFragmentShaderATI" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glPassTexCoordATI(GLuint dst, GLuint coord, GLenum swizzle)
{
	typedef void APIENTRY (*proc_type)(GLuint dst, GLuint coord, GLenum swizzle);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPassTexCoordATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPassTexCoordATI" ); }
	return (*func_ptr)( dst, coord, swizzle );
}

inline void APIENTRY glSampleMapATI(GLuint dst, GLuint interp, GLenum swizzle)
{
	typedef void APIENTRY (*proc_type)(GLuint dst, GLuint interp, GLenum swizzle);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSampleMapATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSampleMapATI" ); }
	return (*func_ptr)( dst, interp, swizzle );
}

inline void APIENTRY glColorFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod)
{
	typedef void APIENTRY (*proc_type)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorFragmentOp1ATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorFragmentOp1ATI" ); }
	return (*func_ptr)( op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod );
}

inline void APIENTRY glColorFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod)
{
	typedef void APIENTRY (*proc_type)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorFragmentOp2ATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorFragmentOp2ATI" ); }
	return (*func_ptr)( op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod );
}

inline void APIENTRY glColorFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod)
{
	typedef void APIENTRY (*proc_type)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorFragmentOp3ATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorFragmentOp3ATI" ); }
	return (*func_ptr)( op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod );
}

inline void APIENTRY glAlphaFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod)
{
	typedef void APIENTRY (*proc_type)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glAlphaFragmentOp1ATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glAlphaFragmentOp1ATI" ); }
	return (*func_ptr)( op, dst, dstMod, arg1, arg1Rep, arg1Mod );
}

inline void APIENTRY glAlphaFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod)
{
	typedef void APIENTRY (*proc_type)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glAlphaFragmentOp2ATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glAlphaFragmentOp2ATI" ); }
	return (*func_ptr)( op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod );
}

inline void APIENTRY glAlphaFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod)
{
	typedef void APIENTRY (*proc_type)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glAlphaFragmentOp3ATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glAlphaFragmentOp3ATI" ); }
	return (*func_ptr)( op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod );
}

inline void APIENTRY glSetFragmentShaderConstantATI(GLuint dst, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint dst, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSetFragmentShaderConstantATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSetFragmentShaderConstantATI" ); }
	return (*func_ptr)( dst, value );
}

inline void APIENTRY glPNTrianglesiATI(GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPNTrianglesiATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPNTrianglesiATI" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glPNTrianglesfATI(GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPNTrianglesfATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPNTrianglesfATI" ); }
	return (*func_ptr)( pname, param );
}

inline GLuint APIENTRY glNewObjectBufferATI(GLsizei size, const GLvoid *pointer, GLenum usage)
{
	typedef GLuint APIENTRY (*proc_type)(GLsizei size, const GLvoid *pointer, GLenum usage);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNewObjectBufferATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNewObjectBufferATI" ); }
	return (*func_ptr)( size, pointer, usage );
}

inline GLboolean APIENTRY glIsObjectBufferATI(GLuint buffer)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsObjectBufferATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsObjectBufferATI" ); }
	return (*func_ptr)( buffer );
}

inline void APIENTRY glUpdateObjectBufferATI(GLuint buffer, GLuint offset, GLsizei size, const GLvoid *pointer, GLenum preserve)
{
	typedef void APIENTRY (*proc_type)(GLuint buffer, GLuint offset, GLsizei size, const GLvoid *pointer, GLenum preserve);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUpdateObjectBufferATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUpdateObjectBufferATI" ); }
	return (*func_ptr)( buffer, offset, size, pointer, preserve );
}

inline void APIENTRY glGetObjectBufferfvATI(GLuint buffer, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint buffer, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetObjectBufferfvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetObjectBufferfvATI" ); }
	return (*func_ptr)( buffer, pname, params );
}

inline void APIENTRY glGetObjectBufferivATI(GLuint buffer, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint buffer, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetObjectBufferivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetObjectBufferivATI" ); }
	return (*func_ptr)( buffer, pname, params );
}

inline void APIENTRY glFreeObjectBufferATI(GLuint buffer)
{
	typedef void APIENTRY (*proc_type)(GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFreeObjectBufferATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFreeObjectBufferATI" ); }
	return (*func_ptr)( buffer );
}

inline void APIENTRY glArrayObjectATI(GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset)
{
	typedef void APIENTRY (*proc_type)(GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glArrayObjectATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glArrayObjectATI" ); }
	return (*func_ptr)( array, size, type, stride, buffer, offset );
}

inline void APIENTRY glGetArrayObjectfvATI(GLenum array, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum array, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetArrayObjectfvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetArrayObjectfvATI" ); }
	return (*func_ptr)( array, pname, params );
}

inline void APIENTRY glGetArrayObjectivATI(GLenum array, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum array, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetArrayObjectivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetArrayObjectivATI" ); }
	return (*func_ptr)( array, pname, params );
}

inline void APIENTRY glVariantArrayObjectATI(GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantArrayObjectATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantArrayObjectATI" ); }
	return (*func_ptr)( id, type, stride, buffer, offset );
}

inline void APIENTRY glGetVariantArrayObjectfvATI(GLuint id, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVariantArrayObjectfvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVariantArrayObjectfvATI" ); }
	return (*func_ptr)( id, pname, params );
}

inline void APIENTRY glGetVariantArrayObjectivATI(GLuint id, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVariantArrayObjectivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVariantArrayObjectivATI" ); }
	return (*func_ptr)( id, pname, params );
}

inline void APIENTRY glBeginVertexShaderEXT(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginVertexShaderEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginVertexShaderEXT" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glEndVertexShaderEXT(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndVertexShaderEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndVertexShaderEXT" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glBindVertexShaderEXT(GLuint id)
{
	typedef void APIENTRY (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindVertexShaderEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindVertexShaderEXT" ); }
	return (*func_ptr)( id );
}

inline GLuint APIENTRY glGenVertexShadersEXT(GLuint range)
{
	typedef GLuint APIENTRY (*proc_type)(GLuint range);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenVertexShadersEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenVertexShadersEXT" ); }
	return (*func_ptr)( range );
}

inline void APIENTRY glDeleteVertexShaderEXT(GLuint id)
{
	typedef void APIENTRY (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteVertexShaderEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteVertexShaderEXT" ); }
	return (*func_ptr)( id );
}

inline void APIENTRY glShaderOp1EXT(GLenum op, GLuint res, GLuint arg1)
{
	typedef void APIENTRY (*proc_type)(GLenum op, GLuint res, GLuint arg1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glShaderOp1EXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glShaderOp1EXT" ); }
	return (*func_ptr)( op, res, arg1 );
}

inline void APIENTRY glShaderOp2EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2)
{
	typedef void APIENTRY (*proc_type)(GLenum op, GLuint res, GLuint arg1, GLuint arg2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glShaderOp2EXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glShaderOp2EXT" ); }
	return (*func_ptr)( op, res, arg1, arg2 );
}

inline void APIENTRY glShaderOp3EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3)
{
	typedef void APIENTRY (*proc_type)(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glShaderOp3EXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glShaderOp3EXT" ); }
	return (*func_ptr)( op, res, arg1, arg2, arg3 );
}

inline void APIENTRY glSwizzleEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW)
{
	typedef void APIENTRY (*proc_type)(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSwizzleEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSwizzleEXT" ); }
	return (*func_ptr)( res, in, outX, outY, outZ, outW );
}

inline void APIENTRY glWriteMaskEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW)
{
	typedef void APIENTRY (*proc_type)(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWriteMaskEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWriteMaskEXT" ); }
	return (*func_ptr)( res, in, outX, outY, outZ, outW );
}

inline void APIENTRY glInsertComponentEXT(GLuint res, GLuint src, GLuint num)
{
	typedef void APIENTRY (*proc_type)(GLuint res, GLuint src, GLuint num);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glInsertComponentEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glInsertComponentEXT" ); }
	return (*func_ptr)( res, src, num );
}

inline void APIENTRY glExtractComponentEXT(GLuint res, GLuint src, GLuint num)
{
	typedef void APIENTRY (*proc_type)(GLuint res, GLuint src, GLuint num);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glExtractComponentEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glExtractComponentEXT" ); }
	return (*func_ptr)( res, src, num );
}

inline GLuint APIENTRY glGenSymbolsEXT(GLenum datatype, GLenum storagetype, GLenum range, GLuint components)
{
	typedef GLuint APIENTRY (*proc_type)(GLenum datatype, GLenum storagetype, GLenum range, GLuint components);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenSymbolsEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenSymbolsEXT" ); }
	return (*func_ptr)( datatype, storagetype, range, components );
}

inline void APIENTRY glSetInvariantEXT(GLuint id, GLenum type, const GLvoid *addr)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum type, const GLvoid *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSetInvariantEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSetInvariantEXT" ); }
	return (*func_ptr)( id, type, addr );
}

inline void APIENTRY glSetLocalConstantEXT(GLuint id, GLenum type, const GLvoid *addr)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum type, const GLvoid *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSetLocalConstantEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSetLocalConstantEXT" ); }
	return (*func_ptr)( id, type, addr );
}

inline void APIENTRY glVariantbvEXT(GLuint id, const GLbyte *addr)
{
	typedef void APIENTRY (*proc_type)(GLuint id, const GLbyte *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantbvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantbvEXT" ); }
	return (*func_ptr)( id, addr );
}

inline void APIENTRY glVariantsvEXT(GLuint id, const GLshort *addr)
{
	typedef void APIENTRY (*proc_type)(GLuint id, const GLshort *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantsvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantsvEXT" ); }
	return (*func_ptr)( id, addr );
}

inline void APIENTRY glVariantivEXT(GLuint id, const GLint *addr)
{
	typedef void APIENTRY (*proc_type)(GLuint id, const GLint *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantivEXT" ); }
	return (*func_ptr)( id, addr );
}

inline void APIENTRY glVariantfvEXT(GLuint id, const GLfloat *addr)
{
	typedef void APIENTRY (*proc_type)(GLuint id, const GLfloat *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantfvEXT" ); }
	return (*func_ptr)( id, addr );
}

inline void APIENTRY glVariantdvEXT(GLuint id, const GLdouble *addr)
{
	typedef void APIENTRY (*proc_type)(GLuint id, const GLdouble *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantdvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantdvEXT" ); }
	return (*func_ptr)( id, addr );
}

inline void APIENTRY glVariantubvEXT(GLuint id, const GLubyte *addr)
{
	typedef void APIENTRY (*proc_type)(GLuint id, const GLubyte *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantubvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantubvEXT" ); }
	return (*func_ptr)( id, addr );
}

inline void APIENTRY glVariantusvEXT(GLuint id, const GLushort *addr)
{
	typedef void APIENTRY (*proc_type)(GLuint id, const GLushort *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantusvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantusvEXT" ); }
	return (*func_ptr)( id, addr );
}

inline void APIENTRY glVariantuivEXT(GLuint id, const GLuint *addr)
{
	typedef void APIENTRY (*proc_type)(GLuint id, const GLuint *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantuivEXT" ); }
	return (*func_ptr)( id, addr );
}

inline void APIENTRY glVariantPointerEXT(GLuint id, GLenum type, GLuint stride, const GLvoid *addr)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum type, GLuint stride, const GLvoid *addr);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVariantPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVariantPointerEXT" ); }
	return (*func_ptr)( id, type, stride, addr );
}

inline void APIENTRY glEnableVariantClientStateEXT(GLuint id)
{
	typedef void APIENTRY (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEnableVariantClientStateEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEnableVariantClientStateEXT" ); }
	return (*func_ptr)( id );
}

inline void APIENTRY glDisableVariantClientStateEXT(GLuint id)
{
	typedef void APIENTRY (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDisableVariantClientStateEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDisableVariantClientStateEXT" ); }
	return (*func_ptr)( id );
}

inline GLuint APIENTRY glBindLightParameterEXT(GLenum light, GLenum value)
{
	typedef GLuint APIENTRY (*proc_type)(GLenum light, GLenum value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindLightParameterEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindLightParameterEXT" ); }
	return (*func_ptr)( light, value );
}

inline GLuint APIENTRY glBindMaterialParameterEXT(GLenum face, GLenum value)
{
	typedef GLuint APIENTRY (*proc_type)(GLenum face, GLenum value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindMaterialParameterEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindMaterialParameterEXT" ); }
	return (*func_ptr)( face, value );
}

inline GLuint APIENTRY glBindTexGenParameterEXT(GLenum unit, GLenum coord, GLenum value)
{
	typedef GLuint APIENTRY (*proc_type)(GLenum unit, GLenum coord, GLenum value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindTexGenParameterEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindTexGenParameterEXT" ); }
	return (*func_ptr)( unit, coord, value );
}

inline GLuint APIENTRY glBindTextureUnitParameterEXT(GLenum unit, GLenum value)
{
	typedef GLuint APIENTRY (*proc_type)(GLenum unit, GLenum value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindTextureUnitParameterEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindTextureUnitParameterEXT" ); }
	return (*func_ptr)( unit, value );
}

inline GLuint APIENTRY glBindParameterEXT(GLenum value)
{
	typedef GLuint APIENTRY (*proc_type)(GLenum value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindParameterEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindParameterEXT" ); }
	return (*func_ptr)( value );
}

inline GLboolean APIENTRY glIsVariantEnabledEXT(GLuint id, GLenum cap)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint id, GLenum cap);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsVariantEnabledEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsVariantEnabledEXT" ); }
	return (*func_ptr)( id, cap );
}

inline void APIENTRY glGetVariantBooleanvEXT(GLuint id, GLenum value, GLboolean *data)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum value, GLboolean *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVariantBooleanvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVariantBooleanvEXT" ); }
	return (*func_ptr)( id, value, data );
}

inline void APIENTRY glGetVariantIntegervEXT(GLuint id, GLenum value, GLint *data)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum value, GLint *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVariantIntegervEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVariantIntegervEXT" ); }
	return (*func_ptr)( id, value, data );
}

inline void APIENTRY glGetVariantFloatvEXT(GLuint id, GLenum value, GLfloat *data)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum value, GLfloat *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVariantFloatvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVariantFloatvEXT" ); }
	return (*func_ptr)( id, value, data );
}

inline void APIENTRY glGetVariantPointervEXT(GLuint id, GLenum value, GLvoid* *data)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum value, GLvoid* *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVariantPointervEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVariantPointervEXT" ); }
	return (*func_ptr)( id, value, data );
}

inline void APIENTRY glGetInvariantBooleanvEXT(GLuint id, GLenum value, GLboolean *data)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum value, GLboolean *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetInvariantBooleanvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetInvariantBooleanvEXT" ); }
	return (*func_ptr)( id, value, data );
}

inline void APIENTRY glGetInvariantIntegervEXT(GLuint id, GLenum value, GLint *data)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum value, GLint *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetInvariantIntegervEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetInvariantIntegervEXT" ); }
	return (*func_ptr)( id, value, data );
}

inline void APIENTRY glGetInvariantFloatvEXT(GLuint id, GLenum value, GLfloat *data)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum value, GLfloat *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetInvariantFloatvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetInvariantFloatvEXT" ); }
	return (*func_ptr)( id, value, data );
}

inline void APIENTRY glGetLocalConstantBooleanvEXT(GLuint id, GLenum value, GLboolean *data)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum value, GLboolean *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetLocalConstantBooleanvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetLocalConstantBooleanvEXT" ); }
	return (*func_ptr)( id, value, data );
}

inline void APIENTRY glGetLocalConstantIntegervEXT(GLuint id, GLenum value, GLint *data)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum value, GLint *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetLocalConstantIntegervEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetLocalConstantIntegervEXT" ); }
	return (*func_ptr)( id, value, data );
}

inline void APIENTRY glGetLocalConstantFloatvEXT(GLuint id, GLenum value, GLfloat *data)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum value, GLfloat *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetLocalConstantFloatvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetLocalConstantFloatvEXT" ); }
	return (*func_ptr)( id, value, data );
}

inline void APIENTRY glVertexStream1sATI(GLenum stream, GLshort x)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLshort x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream1sATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream1sATI" ); }
	return (*func_ptr)( stream, x );
}

inline void APIENTRY glVertexStream1svATI(GLenum stream, const GLshort *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLshort *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream1svATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream1svATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glVertexStream1iATI(GLenum stream, GLint x)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLint x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream1iATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream1iATI" ); }
	return (*func_ptr)( stream, x );
}

inline void APIENTRY glVertexStream1ivATI(GLenum stream, const GLint *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream1ivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream1ivATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glVertexStream1fATI(GLenum stream, GLfloat x)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLfloat x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream1fATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream1fATI" ); }
	return (*func_ptr)( stream, x );
}

inline void APIENTRY glVertexStream1fvATI(GLenum stream, const GLfloat *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLfloat *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream1fvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream1fvATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glVertexStream1dATI(GLenum stream, GLdouble x)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLdouble x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream1dATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream1dATI" ); }
	return (*func_ptr)( stream, x );
}

inline void APIENTRY glVertexStream1dvATI(GLenum stream, const GLdouble *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLdouble *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream1dvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream1dvATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glVertexStream2sATI(GLenum stream, GLshort x, GLshort y)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLshort x, GLshort y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream2sATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream2sATI" ); }
	return (*func_ptr)( stream, x, y );
}

inline void APIENTRY glVertexStream2svATI(GLenum stream, const GLshort *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLshort *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream2svATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream2svATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glVertexStream2iATI(GLenum stream, GLint x, GLint y)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLint x, GLint y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream2iATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream2iATI" ); }
	return (*func_ptr)( stream, x, y );
}

inline void APIENTRY glVertexStream2ivATI(GLenum stream, const GLint *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream2ivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream2ivATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glVertexStream2fATI(GLenum stream, GLfloat x, GLfloat y)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLfloat x, GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream2fATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream2fATI" ); }
	return (*func_ptr)( stream, x, y );
}

inline void APIENTRY glVertexStream2fvATI(GLenum stream, const GLfloat *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLfloat *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream2fvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream2fvATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glVertexStream2dATI(GLenum stream, GLdouble x, GLdouble y)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLdouble x, GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream2dATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream2dATI" ); }
	return (*func_ptr)( stream, x, y );
}

inline void APIENTRY glVertexStream2dvATI(GLenum stream, const GLdouble *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLdouble *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream2dvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream2dvATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glVertexStream3sATI(GLenum stream, GLshort x, GLshort y, GLshort z)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLshort x, GLshort y, GLshort z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream3sATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream3sATI" ); }
	return (*func_ptr)( stream, x, y, z );
}

inline void APIENTRY glVertexStream3svATI(GLenum stream, const GLshort *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLshort *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream3svATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream3svATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glVertexStream3iATI(GLenum stream, GLint x, GLint y, GLint z)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLint x, GLint y, GLint z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream3iATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream3iATI" ); }
	return (*func_ptr)( stream, x, y, z );
}

inline void APIENTRY glVertexStream3ivATI(GLenum stream, const GLint *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream3ivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream3ivATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glVertexStream3fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream3fATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream3fATI" ); }
	return (*func_ptr)( stream, x, y, z );
}

inline void APIENTRY glVertexStream3fvATI(GLenum stream, const GLfloat *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLfloat *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream3fvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream3fvATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glVertexStream3dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLdouble x, GLdouble y, GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream3dATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream3dATI" ); }
	return (*func_ptr)( stream, x, y, z );
}

inline void APIENTRY glVertexStream3dvATI(GLenum stream, const GLdouble *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLdouble *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream3dvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream3dvATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glVertexStream4sATI(GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream4sATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream4sATI" ); }
	return (*func_ptr)( stream, x, y, z, w );
}

inline void APIENTRY glVertexStream4svATI(GLenum stream, const GLshort *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLshort *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream4svATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream4svATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glVertexStream4iATI(GLenum stream, GLint x, GLint y, GLint z, GLint w)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLint x, GLint y, GLint z, GLint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream4iATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream4iATI" ); }
	return (*func_ptr)( stream, x, y, z, w );
}

inline void APIENTRY glVertexStream4ivATI(GLenum stream, const GLint *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream4ivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream4ivATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glVertexStream4fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream4fATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream4fATI" ); }
	return (*func_ptr)( stream, x, y, z, w );
}

inline void APIENTRY glVertexStream4fvATI(GLenum stream, const GLfloat *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLfloat *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream4fvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream4fvATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glVertexStream4dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream4dATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream4dATI" ); }
	return (*func_ptr)( stream, x, y, z, w );
}

inline void APIENTRY glVertexStream4dvATI(GLenum stream, const GLdouble *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLdouble *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexStream4dvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexStream4dvATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glNormalStream3bATI(GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3bATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3bATI" ); }
	return (*func_ptr)( stream, nx, ny, nz );
}

inline void APIENTRY glNormalStream3bvATI(GLenum stream, const GLbyte *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLbyte *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3bvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3bvATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glNormalStream3sATI(GLenum stream, GLshort nx, GLshort ny, GLshort nz)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLshort nx, GLshort ny, GLshort nz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3sATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3sATI" ); }
	return (*func_ptr)( stream, nx, ny, nz );
}

inline void APIENTRY glNormalStream3svATI(GLenum stream, const GLshort *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLshort *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3svATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3svATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glNormalStream3iATI(GLenum stream, GLint nx, GLint ny, GLint nz)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLint nx, GLint ny, GLint nz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3iATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3iATI" ); }
	return (*func_ptr)( stream, nx, ny, nz );
}

inline void APIENTRY glNormalStream3ivATI(GLenum stream, const GLint *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLint *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3ivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3ivATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glNormalStream3fATI(GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3fATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3fATI" ); }
	return (*func_ptr)( stream, nx, ny, nz );
}

inline void APIENTRY glNormalStream3fvATI(GLenum stream, const GLfloat *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLfloat *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3fvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3fvATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glNormalStream3dATI(GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3dATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3dATI" ); }
	return (*func_ptr)( stream, nx, ny, nz );
}

inline void APIENTRY glNormalStream3dvATI(GLenum stream, const GLdouble *coords)
{
	typedef void APIENTRY (*proc_type)(GLenum stream, const GLdouble *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalStream3dvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalStream3dvATI" ); }
	return (*func_ptr)( stream, coords );
}

inline void APIENTRY glClientActiveVertexStreamATI(GLenum stream)
{
	typedef void APIENTRY (*proc_type)(GLenum stream);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClientActiveVertexStreamATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClientActiveVertexStreamATI" ); }
	return (*func_ptr)( stream );
}

inline void APIENTRY glVertexBlendEnviATI(GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexBlendEnviATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexBlendEnviATI" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glVertexBlendEnvfATI(GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexBlendEnvfATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexBlendEnvfATI" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glElementPointerATI(GLenum type, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLenum type, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glElementPointerATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glElementPointerATI" ); }
	return (*func_ptr)( type, pointer );
}

inline void APIENTRY glDrawElementArrayATI(GLenum mode, GLsizei count)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLsizei count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementArrayATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementArrayATI" ); }
	return (*func_ptr)( mode, count );
}

inline void APIENTRY glDrawRangeElementArrayATI(GLenum mode, GLuint start, GLuint end, GLsizei count)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLuint start, GLuint end, GLsizei count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawRangeElementArrayATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawRangeElementArrayATI" ); }
	return (*func_ptr)( mode, start, end, count );
}

inline void APIENTRY glDrawMeshArraysSUN(GLenum mode, GLint first, GLsizei count, GLsizei width)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLint first, GLsizei count, GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawMeshArraysSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawMeshArraysSUN" ); }
	return (*func_ptr)( mode, first, count, width );
}

inline void APIENTRY glGenOcclusionQueriesNV(GLsizei n, GLuint *ids)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenOcclusionQueriesNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenOcclusionQueriesNV" ); }
	return (*func_ptr)( n, ids );
}

inline void APIENTRY glDeleteOcclusionQueriesNV(GLsizei n, const GLuint *ids)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteOcclusionQueriesNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteOcclusionQueriesNV" ); }
	return (*func_ptr)( n, ids );
}

inline GLboolean APIENTRY glIsOcclusionQueryNV(GLuint id)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsOcclusionQueryNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsOcclusionQueryNV" ); }
	return (*func_ptr)( id );
}

inline void APIENTRY glBeginOcclusionQueryNV(GLuint id)
{
	typedef void APIENTRY (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginOcclusionQueryNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginOcclusionQueryNV" ); }
	return (*func_ptr)( id );
}

inline void APIENTRY glEndOcclusionQueryNV(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndOcclusionQueryNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndOcclusionQueryNV" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glGetOcclusionQueryivNV(GLuint id, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetOcclusionQueryivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetOcclusionQueryivNV" ); }
	return (*func_ptr)( id, pname, params );
}

inline void APIENTRY glGetOcclusionQueryuivNV(GLuint id, GLenum pname, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum pname, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetOcclusionQueryuivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetOcclusionQueryuivNV" ); }
	return (*func_ptr)( id, pname, params );
}

inline void APIENTRY glPointParameteriNV(GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameteriNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameteriNV" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glPointParameterivNV(GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointParameterivNV" ); }
	return (*func_ptr)( pname, params );
}

inline void APIENTRY glActiveStencilFaceEXT(GLenum face)
{
	typedef void APIENTRY (*proc_type)(GLenum face);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glActiveStencilFaceEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glActiveStencilFaceEXT" ); }
	return (*func_ptr)( face );
}

inline void APIENTRY glElementPointerAPPLE(GLenum type, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLenum type, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glElementPointerAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glElementPointerAPPLE" ); }
	return (*func_ptr)( type, pointer );
}

inline void APIENTRY glDrawElementArrayAPPLE(GLenum mode, GLint first, GLsizei count)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLint first, GLsizei count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementArrayAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementArrayAPPLE" ); }
	return (*func_ptr)( mode, first, count );
}

inline void APIENTRY glDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawRangeElementArrayAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawRangeElementArrayAPPLE" ); }
	return (*func_ptr)( mode, start, end, first, count );
}

inline void APIENTRY glMultiDrawElementArrayAPPLE(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawElementArrayAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawElementArrayAPPLE" ); }
	return (*func_ptr)( mode, first, count, primcount );
}

inline void APIENTRY glMultiDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, const GLint *first, const GLsizei *count, GLsizei primcount)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLuint start, GLuint end, const GLint *first, const GLsizei *count, GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawRangeElementArrayAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawRangeElementArrayAPPLE" ); }
	return (*func_ptr)( mode, start, end, first, count, primcount );
}

inline void APIENTRY glGenFencesAPPLE(GLsizei n, GLuint *fences)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *fences);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenFencesAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenFencesAPPLE" ); }
	return (*func_ptr)( n, fences );
}

inline void APIENTRY glDeleteFencesAPPLE(GLsizei n, const GLuint *fences)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *fences);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteFencesAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteFencesAPPLE" ); }
	return (*func_ptr)( n, fences );
}

inline void APIENTRY glSetFenceAPPLE(GLuint fence)
{
	typedef void APIENTRY (*proc_type)(GLuint fence);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSetFenceAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSetFenceAPPLE" ); }
	return (*func_ptr)( fence );
}

inline GLboolean APIENTRY glIsFenceAPPLE(GLuint fence)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint fence);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsFenceAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsFenceAPPLE" ); }
	return (*func_ptr)( fence );
}

inline GLboolean APIENTRY glTestFenceAPPLE(GLuint fence)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint fence);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTestFenceAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTestFenceAPPLE" ); }
	return (*func_ptr)( fence );
}

inline void APIENTRY glFinishFenceAPPLE(GLuint fence)
{
	typedef void APIENTRY (*proc_type)(GLuint fence);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFinishFenceAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFinishFenceAPPLE" ); }
	return (*func_ptr)( fence );
}

inline GLboolean APIENTRY glTestObjectAPPLE(GLenum object, GLuint name)
{
	typedef GLboolean APIENTRY (*proc_type)(GLenum object, GLuint name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTestObjectAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTestObjectAPPLE" ); }
	return (*func_ptr)( object, name );
}

inline void APIENTRY glFinishObjectAPPLE(GLenum object, GLint name)
{
	typedef void APIENTRY (*proc_type)(GLenum object, GLint name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFinishObjectAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFinishObjectAPPLE" ); }
	return (*func_ptr)( object, name );
}

inline void APIENTRY glBindVertexArrayAPPLE(GLuint array)
{
	typedef void APIENTRY (*proc_type)(GLuint array);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindVertexArrayAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindVertexArrayAPPLE" ); }
	return (*func_ptr)( array );
}

inline void APIENTRY glDeleteVertexArraysAPPLE(GLsizei n, const GLuint *arrays)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *arrays);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteVertexArraysAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteVertexArraysAPPLE" ); }
	return (*func_ptr)( n, arrays );
}

inline void APIENTRY glGenVertexArraysAPPLE(GLsizei n, GLuint *arrays)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *arrays);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenVertexArraysAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenVertexArraysAPPLE" ); }
	return (*func_ptr)( n, arrays );
}

inline GLboolean APIENTRY glIsVertexArrayAPPLE(GLuint array)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint array);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsVertexArrayAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsVertexArrayAPPLE" ); }
	return (*func_ptr)( array );
}

inline void APIENTRY glVertexArrayRangeAPPLE(GLsizei length, GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLsizei length, GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexArrayRangeAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexArrayRangeAPPLE" ); }
	return (*func_ptr)( length, pointer );
}

inline void APIENTRY glFlushVertexArrayRangeAPPLE(GLsizei length, GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLsizei length, GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFlushVertexArrayRangeAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFlushVertexArrayRangeAPPLE" ); }
	return (*func_ptr)( length, pointer );
}

inline void APIENTRY glVertexArrayParameteriAPPLE(GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexArrayParameteriAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexArrayParameteriAPPLE" ); }
	return (*func_ptr)( pname, param );
}

inline void APIENTRY glDrawBuffersATI(GLsizei n, const GLenum *bufs)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLenum *bufs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawBuffersATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawBuffersATI" ); }
	return (*func_ptr)( n, bufs );
}

inline void APIENTRY glProgramNamedParameter4fNV(GLuint id, GLsizei len, const GLubyte *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLsizei len, const GLubyte *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramNamedParameter4fNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramNamedParameter4fNV" ); }
	return (*func_ptr)( id, len, name, x, y, z, w );
}

inline void APIENTRY glProgramNamedParameter4dNV(GLuint id, GLsizei len, const GLubyte *name, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLsizei len, const GLubyte *name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramNamedParameter4dNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramNamedParameter4dNV" ); }
	return (*func_ptr)( id, len, name, x, y, z, w );
}

inline void APIENTRY glProgramNamedParameter4fvNV(GLuint id, GLsizei len, const GLubyte *name, const GLfloat *v)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLsizei len, const GLubyte *name, const GLfloat *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramNamedParameter4fvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramNamedParameter4fvNV" ); }
	return (*func_ptr)( id, len, name, v );
}

inline void APIENTRY glProgramNamedParameter4dvNV(GLuint id, GLsizei len, const GLubyte *name, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLsizei len, const GLubyte *name, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramNamedParameter4dvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramNamedParameter4dvNV" ); }
	return (*func_ptr)( id, len, name, v );
}

inline void APIENTRY glGetProgramNamedParameterfvNV(GLuint id, GLsizei len, const GLubyte *name, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLsizei len, const GLubyte *name, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramNamedParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramNamedParameterfvNV" ); }
	return (*func_ptr)( id, len, name, params );
}

inline void APIENTRY glGetProgramNamedParameterdvNV(GLuint id, GLsizei len, const GLubyte *name, GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLsizei len, const GLubyte *name, GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramNamedParameterdvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramNamedParameterdvNV" ); }
	return (*func_ptr)( id, len, name, params );
}

inline void APIENTRY glVertex2hNV(GLhalfNV x, GLhalfNV y)
{
	typedef void APIENTRY (*proc_type)(GLhalfNV x, GLhalfNV y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertex2hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertex2hNV" ); }
	return (*func_ptr)( x, y );
}

inline void APIENTRY glVertex2hvNV(const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertex2hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertex2hvNV" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glVertex3hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z)
{
	typedef void APIENTRY (*proc_type)(GLhalfNV x, GLhalfNV y, GLhalfNV z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertex3hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertex3hNV" ); }
	return (*func_ptr)( x, y, z );
}

inline void APIENTRY glVertex3hvNV(const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertex3hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertex3hvNV" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glVertex4hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w)
{
	typedef void APIENTRY (*proc_type)(GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertex4hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertex4hNV" ); }
	return (*func_ptr)( x, y, z, w );
}

inline void APIENTRY glVertex4hvNV(const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertex4hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertex4hvNV" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glNormal3hNV(GLhalfNV nx, GLhalfNV ny, GLhalfNV nz)
{
	typedef void APIENTRY (*proc_type)(GLhalfNV nx, GLhalfNV ny, GLhalfNV nz);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormal3hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormal3hNV" ); }
	return (*func_ptr)( nx, ny, nz );
}

inline void APIENTRY glNormal3hvNV(const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormal3hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormal3hvNV" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glColor3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue)
{
	typedef void APIENTRY (*proc_type)(GLhalfNV red, GLhalfNV green, GLhalfNV blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor3hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor3hNV" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glColor3hvNV(const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor3hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor3hvNV" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glColor4hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha)
{
	typedef void APIENTRY (*proc_type)(GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor4hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor4hNV" ); }
	return (*func_ptr)( red, green, blue, alpha );
}

inline void APIENTRY glColor4hvNV(const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColor4hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColor4hvNV" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glTexCoord1hNV(GLhalfNV s)
{
	typedef void APIENTRY (*proc_type)(GLhalfNV s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord1hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord1hNV" ); }
	return (*func_ptr)( s );
}

inline void APIENTRY glTexCoord1hvNV(const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord1hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord1hvNV" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glTexCoord2hNV(GLhalfNV s, GLhalfNV t)
{
	typedef void APIENTRY (*proc_type)(GLhalfNV s, GLhalfNV t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2hNV" ); }
	return (*func_ptr)( s, t );
}

inline void APIENTRY glTexCoord2hvNV(const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord2hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord2hvNV" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glTexCoord3hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r)
{
	typedef void APIENTRY (*proc_type)(GLhalfNV s, GLhalfNV t, GLhalfNV r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord3hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord3hNV" ); }
	return (*func_ptr)( s, t, r );
}

inline void APIENTRY glTexCoord3hvNV(const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord3hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord3hvNV" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glTexCoord4hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q)
{
	typedef void APIENTRY (*proc_type)(GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord4hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord4hNV" ); }
	return (*func_ptr)( s, t, r, q );
}

inline void APIENTRY glTexCoord4hvNV(const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoord4hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoord4hvNV" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glMultiTexCoord1hNV(GLenum target, GLhalfNV s)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLhalfNV s);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1hNV" ); }
	return (*func_ptr)( target, s );
}

inline void APIENTRY glMultiTexCoord1hvNV(GLenum target, const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord1hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord1hvNV" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord2hNV(GLenum target, GLhalfNV s, GLhalfNV t)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLhalfNV s, GLhalfNV t);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2hNV" ); }
	return (*func_ptr)( target, s, t );
}

inline void APIENTRY glMultiTexCoord2hvNV(GLenum target, const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord2hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord2hvNV" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord3hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3hNV" ); }
	return (*func_ptr)( target, s, t, r );
}

inline void APIENTRY glMultiTexCoord3hvNV(GLenum target, const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord3hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord3hvNV" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glMultiTexCoord4hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4hNV" ); }
	return (*func_ptr)( target, s, t, r, q );
}

inline void APIENTRY glMultiTexCoord4hvNV(GLenum target, const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(GLenum target, const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoord4hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoord4hvNV" ); }
	return (*func_ptr)( target, v );
}

inline void APIENTRY glFogCoordhNV(GLhalfNV fog)
{
	typedef void APIENTRY (*proc_type)(GLhalfNV fog);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordhNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordhNV" ); }
	return (*func_ptr)( fog );
}

inline void APIENTRY glFogCoordhvNV(const GLhalfNV *fog)
{
	typedef void APIENTRY (*proc_type)(const GLhalfNV *fog);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordhvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordhvNV" ); }
	return (*func_ptr)( fog );
}

inline void APIENTRY glSecondaryColor3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue)
{
	typedef void APIENTRY (*proc_type)(GLhalfNV red, GLhalfNV green, GLhalfNV blue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3hNV" ); }
	return (*func_ptr)( red, green, blue );
}

inline void APIENTRY glSecondaryColor3hvNV(const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColor3hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColor3hvNV" ); }
	return (*func_ptr)( v );
}

inline void APIENTRY glVertexWeighthNV(GLhalfNV weight)
{
	typedef void APIENTRY (*proc_type)(GLhalfNV weight);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexWeighthNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexWeighthNV" ); }
	return (*func_ptr)( weight );
}

inline void APIENTRY glVertexWeighthvNV(const GLhalfNV *weight)
{
	typedef void APIENTRY (*proc_type)(const GLhalfNV *weight);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexWeighthvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexWeighthvNV" ); }
	return (*func_ptr)( weight );
}

inline void APIENTRY glVertexAttrib1hNV(GLuint index, GLhalfNV x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLhalfNV x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1hNV" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttrib1hvNV(GLuint index, const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib1hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib1hvNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib2hNV(GLuint index, GLhalfNV x, GLhalfNV y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLhalfNV x, GLhalfNV y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2hNV" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttrib2hvNV(GLuint index, const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib2hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib2hvNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib3hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3hNV" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttrib3hvNV(GLuint index, const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib3hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib3hvNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttrib4hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4hNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4hNV" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttrib4hvNV(GLuint index, const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttrib4hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttrib4hvNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribs1hvNV(GLuint index, GLsizei n, const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLsizei n, const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs1hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs1hvNV" ); }
	return (*func_ptr)( index, n, v );
}

inline void APIENTRY glVertexAttribs2hvNV(GLuint index, GLsizei n, const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLsizei n, const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs2hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs2hvNV" ); }
	return (*func_ptr)( index, n, v );
}

inline void APIENTRY glVertexAttribs3hvNV(GLuint index, GLsizei n, const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLsizei n, const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs3hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs3hvNV" ); }
	return (*func_ptr)( index, n, v );
}

inline void APIENTRY glVertexAttribs4hvNV(GLuint index, GLsizei n, const GLhalfNV *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLsizei n, const GLhalfNV *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribs4hvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribs4hvNV" ); }
	return (*func_ptr)( index, n, v );
}

inline void APIENTRY glPixelDataRangeNV(GLenum target, GLsizei length, GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei length, GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPixelDataRangeNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPixelDataRangeNV" ); }
	return (*func_ptr)( target, length, pointer );
}

inline void APIENTRY glFlushPixelDataRangeNV(GLenum target)
{
	typedef void APIENTRY (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFlushPixelDataRangeNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFlushPixelDataRangeNV" ); }
	return (*func_ptr)( target );
}

inline void APIENTRY glPrimitiveRestartNV(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPrimitiveRestartNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPrimitiveRestartNV" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glPrimitiveRestartIndexNV(GLuint index)
{
	typedef void APIENTRY (*proc_type)(GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPrimitiveRestartIndexNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPrimitiveRestartIndexNV" ); }
	return (*func_ptr)( index );
}

inline GLvoid* APIENTRY glMapObjectBufferATI(GLuint buffer)
{
	typedef GLvoid* APIENTRY (*proc_type)(GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapObjectBufferATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapObjectBufferATI" ); }
	return (*func_ptr)( buffer );
}

inline void APIENTRY glUnmapObjectBufferATI(GLuint buffer)
{
	typedef void APIENTRY (*proc_type)(GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUnmapObjectBufferATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUnmapObjectBufferATI" ); }
	return (*func_ptr)( buffer );
}

inline void APIENTRY glStencilOpSeparateATI(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
{
	typedef void APIENTRY (*proc_type)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilOpSeparateATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilOpSeparateATI" ); }
	return (*func_ptr)( face, sfail, dpfail, dppass );
}

inline void APIENTRY glStencilFuncSeparateATI(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask)
{
	typedef void APIENTRY (*proc_type)(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilFuncSeparateATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilFuncSeparateATI" ); }
	return (*func_ptr)( frontfunc, backfunc, ref, mask );
}

inline void APIENTRY glVertexAttribArrayObjectATI(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribArrayObjectATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribArrayObjectATI" ); }
	return (*func_ptr)( index, size, type, normalized, stride, buffer, offset );
}

inline void APIENTRY glGetVertexAttribArrayObjectfvATI(GLuint index, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribArrayObjectfvATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribArrayObjectfvATI" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glGetVertexAttribArrayObjectivATI(GLuint index, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribArrayObjectivATI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribArrayObjectivATI" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glDepthBoundsEXT(GLclampd zmin, GLclampd zmax)
{
	typedef void APIENTRY (*proc_type)(GLclampd zmin, GLclampd zmax);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDepthBoundsEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDepthBoundsEXT" ); }
	return (*func_ptr)( zmin, zmax );
}

inline void APIENTRY glBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha)
{
	typedef void APIENTRY (*proc_type)(GLenum modeRGB, GLenum modeAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationSeparateEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationSeparateEXT" ); }
	return (*func_ptr)( modeRGB, modeAlpha );
}

inline GLboolean APIENTRY glIsRenderbufferEXT(GLuint renderbuffer)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsRenderbufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsRenderbufferEXT" ); }
	return (*func_ptr)( renderbuffer );
}

inline void APIENTRY glBindRenderbufferEXT(GLenum target, GLuint renderbuffer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindRenderbufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindRenderbufferEXT" ); }
	return (*func_ptr)( target, renderbuffer );
}

inline void APIENTRY glDeleteRenderbuffersEXT(GLsizei n, const GLuint *renderbuffers)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *renderbuffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteRenderbuffersEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteRenderbuffersEXT" ); }
	return (*func_ptr)( n, renderbuffers );
}

inline void APIENTRY glGenRenderbuffersEXT(GLsizei n, GLuint *renderbuffers)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *renderbuffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenRenderbuffersEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenRenderbuffersEXT" ); }
	return (*func_ptr)( n, renderbuffers );
}

inline void APIENTRY glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glRenderbufferStorageEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glRenderbufferStorageEXT" ); }
	return (*func_ptr)( target, internalformat, width, height );
}

inline void APIENTRY glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetRenderbufferParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetRenderbufferParameterivEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline GLboolean APIENTRY glIsFramebufferEXT(GLuint framebuffer)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint framebuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsFramebufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsFramebufferEXT" ); }
	return (*func_ptr)( framebuffer );
}

inline void APIENTRY glBindFramebufferEXT(GLenum target, GLuint framebuffer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint framebuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindFramebufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindFramebufferEXT" ); }
	return (*func_ptr)( target, framebuffer );
}

inline void APIENTRY glDeleteFramebuffersEXT(GLsizei n, const GLuint *framebuffers)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *framebuffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteFramebuffersEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteFramebuffersEXT" ); }
	return (*func_ptr)( n, framebuffers );
}

inline void APIENTRY glGenFramebuffersEXT(GLsizei n, GLuint *framebuffers)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *framebuffers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenFramebuffersEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenFramebuffersEXT" ); }
	return (*func_ptr)( n, framebuffers );
}

inline GLenum APIENTRY glCheckFramebufferStatusEXT(GLenum target)
{
	typedef GLenum APIENTRY (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCheckFramebufferStatusEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCheckFramebufferStatusEXT" ); }
	return (*func_ptr)( target );
}

inline void APIENTRY glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTexture1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTexture1DEXT" ); }
	return (*func_ptr)( target, attachment, textarget, texture, level );
}

inline void APIENTRY glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTexture2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTexture2DEXT" ); }
	return (*func_ptr)( target, attachment, textarget, texture, level );
}

inline void APIENTRY glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTexture3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTexture3DEXT" ); }
	return (*func_ptr)( target, attachment, textarget, texture, level, zoffset );
}

inline void APIENTRY glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferRenderbufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferRenderbufferEXT" ); }
	return (*func_ptr)( target, attachment, renderbuffertarget, renderbuffer );
}

inline void APIENTRY glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFramebufferAttachmentParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFramebufferAttachmentParameterivEXT" ); }
	return (*func_ptr)( target, attachment, pname, params );
}

inline void APIENTRY glGenerateMipmapEXT(GLenum target)
{
	typedef void APIENTRY (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenerateMipmapEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenerateMipmapEXT" ); }
	return (*func_ptr)( target );
}

inline void APIENTRY glStringMarkerGREMEDY(GLsizei len, const GLvoid *string)
{
	typedef void APIENTRY (*proc_type)(GLsizei len, const GLvoid *string);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStringMarkerGREMEDY" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStringMarkerGREMEDY" ); }
	return (*func_ptr)( len, string );
}

inline void APIENTRY glStencilClearTagEXT(GLsizei stencilTagBits, GLuint stencilClearTag)
{
	typedef void APIENTRY (*proc_type)(GLsizei stencilTagBits, GLuint stencilClearTag);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilClearTagEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilClearTagEXT" ); }
	return (*func_ptr)( stencilTagBits, stencilClearTag );
}

inline void APIENTRY glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
{
	typedef void APIENTRY (*proc_type)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlitFramebufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlitFramebufferEXT" ); }
	return (*func_ptr)( srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter );
}

inline void APIENTRY glRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glRenderbufferStorageMultisampleEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glRenderbufferStorageMultisampleEXT" ); }
	return (*func_ptr)( target, samples, internalformat, width, height );
}

inline void APIENTRY glGetQueryObjecti64vEXT(GLuint id, GLenum pname, GLint64EXT *params)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum pname, GLint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryObjecti64vEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryObjecti64vEXT" ); }
	return (*func_ptr)( id, pname, params );
}

inline void APIENTRY glGetQueryObjectui64vEXT(GLuint id, GLenum pname, GLuint64EXT *params)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum pname, GLuint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetQueryObjectui64vEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetQueryObjectui64vEXT" ); }
	return (*func_ptr)( id, pname, params );
}

inline void APIENTRY glProgramEnvParameters4fvEXT(GLenum target, GLuint index, GLsizei count, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLsizei count, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameters4fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameters4fvEXT" ); }
	return (*func_ptr)( target, index, count, params );
}

inline void APIENTRY glProgramLocalParameters4fvEXT(GLenum target, GLuint index, GLsizei count, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLsizei count, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameters4fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameters4fvEXT" ); }
	return (*func_ptr)( target, index, count, params );
}

inline void APIENTRY glBufferParameteriAPPLE(GLenum target, GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBufferParameteriAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBufferParameteriAPPLE" ); }
	return (*func_ptr)( target, pname, param );
}

inline void APIENTRY glFlushMappedBufferRangeAPPLE(GLenum target, GLintptr offset, GLsizeiptr size)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLintptr offset, GLsizeiptr size);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFlushMappedBufferRangeAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFlushMappedBufferRangeAPPLE" ); }
	return (*func_ptr)( target, offset, size );
}

inline void APIENTRY glProgramLocalParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameterI4iNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameterI4iNV" ); }
	return (*func_ptr)( target, index, x, y, z, w );
}

inline void APIENTRY glProgramLocalParameterI4ivNV(GLenum target, GLuint index, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameterI4ivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameterI4ivNV" ); }
	return (*func_ptr)( target, index, params );
}

inline void APIENTRY glProgramLocalParametersI4ivNV(GLenum target, GLuint index, GLsizei count, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLsizei count, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParametersI4ivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParametersI4ivNV" ); }
	return (*func_ptr)( target, index, count, params );
}

inline void APIENTRY glProgramLocalParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameterI4uiNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameterI4uiNV" ); }
	return (*func_ptr)( target, index, x, y, z, w );
}

inline void APIENTRY glProgramLocalParameterI4uivNV(GLenum target, GLuint index, const GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParameterI4uivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParameterI4uivNV" ); }
	return (*func_ptr)( target, index, params );
}

inline void APIENTRY glProgramLocalParametersI4uivNV(GLenum target, GLuint index, GLsizei count, const GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLsizei count, const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramLocalParametersI4uivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramLocalParametersI4uivNV" ); }
	return (*func_ptr)( target, index, count, params );
}

inline void APIENTRY glProgramEnvParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameterI4iNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameterI4iNV" ); }
	return (*func_ptr)( target, index, x, y, z, w );
}

inline void APIENTRY glProgramEnvParameterI4ivNV(GLenum target, GLuint index, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameterI4ivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameterI4ivNV" ); }
	return (*func_ptr)( target, index, params );
}

inline void APIENTRY glProgramEnvParametersI4ivNV(GLenum target, GLuint index, GLsizei count, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLsizei count, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParametersI4ivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParametersI4ivNV" ); }
	return (*func_ptr)( target, index, count, params );
}

inline void APIENTRY glProgramEnvParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameterI4uiNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameterI4uiNV" ); }
	return (*func_ptr)( target, index, x, y, z, w );
}

inline void APIENTRY glProgramEnvParameterI4uivNV(GLenum target, GLuint index, const GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParameterI4uivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParameterI4uivNV" ); }
	return (*func_ptr)( target, index, params );
}

inline void APIENTRY glProgramEnvParametersI4uivNV(GLenum target, GLuint index, GLsizei count, const GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLsizei count, const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramEnvParametersI4uivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramEnvParametersI4uivNV" ); }
	return (*func_ptr)( target, index, count, params );
}

inline void APIENTRY glGetProgramLocalParameterIivNV(GLenum target, GLuint index, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramLocalParameterIivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramLocalParameterIivNV" ); }
	return (*func_ptr)( target, index, params );
}

inline void APIENTRY glGetProgramLocalParameterIuivNV(GLenum target, GLuint index, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramLocalParameterIuivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramLocalParameterIuivNV" ); }
	return (*func_ptr)( target, index, params );
}

inline void APIENTRY glGetProgramEnvParameterIivNV(GLenum target, GLuint index, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramEnvParameterIivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramEnvParameterIivNV" ); }
	return (*func_ptr)( target, index, params );
}

inline void APIENTRY glGetProgramEnvParameterIuivNV(GLenum target, GLuint index, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramEnvParameterIuivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramEnvParameterIuivNV" ); }
	return (*func_ptr)( target, index, params );
}

inline void APIENTRY glProgramVertexLimitNV(GLenum target, GLint limit)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLint limit);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramVertexLimitNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramVertexLimitNV" ); }
	return (*func_ptr)( target, limit );
}

inline void APIENTRY glFramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLuint texture, GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTextureEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTextureEXT" ); }
	return (*func_ptr)( target, attachment, texture, level );
}

inline void APIENTRY glFramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTextureLayerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTextureLayerEXT" ); }
	return (*func_ptr)( target, attachment, texture, level, layer );
}

inline void APIENTRY glFramebufferTextureFaceEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferTextureFaceEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferTextureFaceEXT" ); }
	return (*func_ptr)( target, attachment, texture, level, face );
}

inline void APIENTRY glProgramParameteriEXT(GLuint program, GLenum pname, GLint value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum pname, GLint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramParameteriEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramParameteriEXT" ); }
	return (*func_ptr)( program, pname, value );
}

inline void APIENTRY glVertexAttribI1iEXT(GLuint index, GLint x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI1iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI1iEXT" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttribI2iEXT(GLuint index, GLint x, GLint y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint x, GLint y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI2iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI2iEXT" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttribI3iEXT(GLuint index, GLint x, GLint y, GLint z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint x, GLint y, GLint z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI3iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI3iEXT" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttribI4iEXT(GLuint index, GLint x, GLint y, GLint z, GLint w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint x, GLint y, GLint z, GLint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4iEXT" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttribI1uiEXT(GLuint index, GLuint x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI1uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI1uiEXT" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttribI2uiEXT(GLuint index, GLuint x, GLuint y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint x, GLuint y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI2uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI2uiEXT" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttribI3uiEXT(GLuint index, GLuint x, GLuint y, GLuint z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint x, GLuint y, GLuint z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI3uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI3uiEXT" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttribI4uiEXT(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4uiEXT" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttribI1ivEXT(GLuint index, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI1ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI1ivEXT" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI2ivEXT(GLuint index, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI2ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI2ivEXT" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI3ivEXT(GLuint index, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI3ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI3ivEXT" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI4ivEXT(GLuint index, const GLint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4ivEXT" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI1uivEXT(GLuint index, const GLuint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI1uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI1uivEXT" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI2uivEXT(GLuint index, const GLuint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI2uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI2uivEXT" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI3uivEXT(GLuint index, const GLuint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI3uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI3uivEXT" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI4uivEXT(GLuint index, const GLuint *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLuint *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4uivEXT" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI4bvEXT(GLuint index, const GLbyte *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLbyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4bvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4bvEXT" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI4svEXT(GLuint index, const GLshort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLshort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4svEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4svEXT" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI4ubvEXT(GLuint index, const GLubyte *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLubyte *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4ubvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4ubvEXT" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribI4usvEXT(GLuint index, const GLushort *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLushort *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribI4usvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribI4usvEXT" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribIPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribIPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribIPointerEXT" ); }
	return (*func_ptr)( index, size, type, stride, pointer );
}

inline void APIENTRY glGetVertexAttribIivEXT(GLuint index, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribIivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribIivEXT" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glGetVertexAttribIuivEXT(GLuint index, GLenum pname, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribIuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribIuivEXT" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glGetUniformuivEXT(GLuint program, GLint location, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformuivEXT" ); }
	return (*func_ptr)( program, location, params );
}

inline void APIENTRY glBindFragDataLocationEXT(GLuint program, GLuint color, const GLchar *name)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLuint color, const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindFragDataLocationEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindFragDataLocationEXT" ); }
	return (*func_ptr)( program, color, name );
}

inline GLint APIENTRY glGetFragDataLocationEXT(GLuint program, const GLchar *name)
{
	typedef GLint APIENTRY (*proc_type)(GLuint program, const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFragDataLocationEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFragDataLocationEXT" ); }
	return (*func_ptr)( program, name );
}

inline void APIENTRY glUniform1uiEXT(GLint location, GLuint v0)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLuint v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1uiEXT" ); }
	return (*func_ptr)( location, v0 );
}

inline void APIENTRY glUniform2uiEXT(GLint location, GLuint v0, GLuint v1)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLuint v0, GLuint v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2uiEXT" ); }
	return (*func_ptr)( location, v0, v1 );
}

inline void APIENTRY glUniform3uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLuint v0, GLuint v1, GLuint v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3uiEXT" ); }
	return (*func_ptr)( location, v0, v1, v2 );
}

inline void APIENTRY glUniform4uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4uiEXT" ); }
	return (*func_ptr)( location, v0, v1, v2, v3 );
}

inline void APIENTRY glUniform1uivEXT(GLint location, GLsizei count, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1uivEXT" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform2uivEXT(GLint location, GLsizei count, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2uivEXT" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform3uivEXT(GLint location, GLsizei count, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3uivEXT" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform4uivEXT(GLint location, GLsizei count, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4uivEXT" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLint start, GLsizei count, GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawArraysInstancedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawArraysInstancedEXT" ); }
	return (*func_ptr)( mode, start, count, primcount );
}

inline void APIENTRY glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawElementsInstancedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawElementsInstancedEXT" ); }
	return (*func_ptr)( mode, count, type, indices, primcount );
}

inline void APIENTRY glTexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum internalformat, GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexBufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexBufferEXT" ); }
	return (*func_ptr)( target, internalformat, buffer );
}

inline void APIENTRY glDepthRangedNV(GLdouble zNear, GLdouble zFar)
{
	typedef void APIENTRY (*proc_type)(GLdouble zNear, GLdouble zFar);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDepthRangedNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDepthRangedNV" ); }
	return (*func_ptr)( zNear, zFar );
}

inline void APIENTRY glClearDepthdNV(GLdouble depth)
{
	typedef void APIENTRY (*proc_type)(GLdouble depth);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClearDepthdNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClearDepthdNV" ); }
	return (*func_ptr)( depth );
}

inline void APIENTRY glDepthBoundsdNV(GLdouble zmin, GLdouble zmax)
{
	typedef void APIENTRY (*proc_type)(GLdouble zmin, GLdouble zmax);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDepthBoundsdNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDepthBoundsdNV" ); }
	return (*func_ptr)( zmin, zmax );
}

inline void APIENTRY glRenderbufferStorageMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glRenderbufferStorageMultisampleCoverageNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glRenderbufferStorageMultisampleCoverageNV" ); }
	return (*func_ptr)( target, coverageSamples, colorSamples, internalformat, width, height );
}

inline void APIENTRY glProgramBufferParametersfvNV(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramBufferParametersfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramBufferParametersfvNV" ); }
	return (*func_ptr)( target, buffer, index, count, params );
}

inline void APIENTRY glProgramBufferParametersIivNV(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramBufferParametersIivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramBufferParametersIivNV" ); }
	return (*func_ptr)( target, buffer, index, count, params );
}

inline void APIENTRY glProgramBufferParametersIuivNV(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramBufferParametersIuivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramBufferParametersIuivNV" ); }
	return (*func_ptr)( target, buffer, index, count, params );
}

inline void APIENTRY glColorMaskIndexedEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorMaskIndexedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorMaskIndexedEXT" ); }
	return (*func_ptr)( index, r, g, b, a );
}

inline void APIENTRY glGetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLboolean *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBooleanIndexedvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBooleanIndexedvEXT" ); }
	return (*func_ptr)( target, index, data );
}

inline void APIENTRY glGetIntegerIndexedvEXT(GLenum target, GLuint index, GLint *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLint *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetIntegerIndexedvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetIntegerIndexedvEXT" ); }
	return (*func_ptr)( target, index, data );
}

inline void APIENTRY glEnableIndexedEXT(GLenum target, GLuint index)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEnableIndexedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEnableIndexedEXT" ); }
	return (*func_ptr)( target, index );
}

inline void APIENTRY glDisableIndexedEXT(GLenum target, GLuint index)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDisableIndexedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDisableIndexedEXT" ); }
	return (*func_ptr)( target, index );
}

inline GLboolean APIENTRY glIsEnabledIndexedEXT(GLenum target, GLuint index)
{
	typedef GLboolean APIENTRY (*proc_type)(GLenum target, GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsEnabledIndexedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsEnabledIndexedEXT" ); }
	return (*func_ptr)( target, index );
}

inline void APIENTRY glBeginTransformFeedbackNV(GLenum primitiveMode)
{
	typedef void APIENTRY (*proc_type)(GLenum primitiveMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginTransformFeedbackNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginTransformFeedbackNV" ); }
	return (*func_ptr)( primitiveMode );
}

inline void APIENTRY glEndTransformFeedbackNV(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndTransformFeedbackNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndTransformFeedbackNV" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glTransformFeedbackAttribsNV(GLuint count, const GLint *attribs, GLenum bufferMode)
{
	typedef void APIENTRY (*proc_type)(GLuint count, const GLint *attribs, GLenum bufferMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTransformFeedbackAttribsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTransformFeedbackAttribsNV" ); }
	return (*func_ptr)( count, attribs, bufferMode );
}

inline void APIENTRY glBindBufferRangeNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferRangeNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferRangeNV" ); }
	return (*func_ptr)( target, index, buffer, offset, size );
}

inline void APIENTRY glBindBufferOffsetNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferOffsetNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferOffsetNV" ); }
	return (*func_ptr)( target, index, buffer, offset );
}

inline void APIENTRY glBindBufferBaseNV(GLenum target, GLuint index, GLuint buffer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferBaseNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferBaseNV" ); }
	return (*func_ptr)( target, index, buffer );
}

inline void APIENTRY glTransformFeedbackVaryingsNV(GLuint program, GLsizei count, const GLint *locations, GLenum bufferMode)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLsizei count, const GLint *locations, GLenum bufferMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTransformFeedbackVaryingsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTransformFeedbackVaryingsNV" ); }
	return (*func_ptr)( program, count, locations, bufferMode );
}

inline void APIENTRY glActiveVaryingNV(GLuint program, const GLchar *name)
{
	typedef void APIENTRY (*proc_type)(GLuint program, const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glActiveVaryingNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glActiveVaryingNV" ); }
	return (*func_ptr)( program, name );
}

inline GLint APIENTRY glGetVaryingLocationNV(GLuint program, const GLchar *name)
{
	typedef GLint APIENTRY (*proc_type)(GLuint program, const GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVaryingLocationNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVaryingLocationNV" ); }
	return (*func_ptr)( program, name );
}

inline void APIENTRY glGetActiveVaryingNV(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetActiveVaryingNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetActiveVaryingNV" ); }
	return (*func_ptr)( program, index, bufSize, length, size, type, name );
}

inline void APIENTRY glGetTransformFeedbackVaryingNV(GLuint program, GLuint index, GLint *location)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLuint index, GLint *location);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTransformFeedbackVaryingNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTransformFeedbackVaryingNV" ); }
	return (*func_ptr)( program, index, location );
}

inline void APIENTRY glTransformFeedbackStreamAttribsNV(GLsizei count, const GLint *attribs, GLsizei nbuffers, const GLint *bufstreams, GLenum bufferMode)
{
	typedef void APIENTRY (*proc_type)(GLsizei count, const GLint *attribs, GLsizei nbuffers, const GLint *bufstreams, GLenum bufferMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTransformFeedbackStreamAttribsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTransformFeedbackStreamAttribsNV" ); }
	return (*func_ptr)( count, attribs, nbuffers, bufstreams, bufferMode );
}

inline void APIENTRY glUniformBufferEXT(GLuint program, GLint location, GLuint buffer)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformBufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformBufferEXT" ); }
	return (*func_ptr)( program, location, buffer );
}

inline GLint APIENTRY glGetUniformBufferSizeEXT(GLuint program, GLint location)
{
	typedef GLint APIENTRY (*proc_type)(GLuint program, GLint location);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformBufferSizeEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformBufferSizeEXT" ); }
	return (*func_ptr)( program, location );
}

inline GLintptr APIENTRY glGetUniformOffsetEXT(GLuint program, GLint location)
{
	typedef GLintptr APIENTRY (*proc_type)(GLuint program, GLint location);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformOffsetEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformOffsetEXT" ); }
	return (*func_ptr)( program, location );
}

inline void APIENTRY glTexParameterIivEXT(GLenum target, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexParameterIivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexParameterIivEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glTexParameterIuivEXT(GLenum target, GLenum pname, const GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexParameterIuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexParameterIuivEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetTexParameterIivEXT(GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTexParameterIivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTexParameterIivEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetTexParameterIuivEXT(GLenum target, GLenum pname, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTexParameterIuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTexParameterIuivEXT" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glClearColorIiEXT(GLint red, GLint green, GLint blue, GLint alpha)
{
	typedef void APIENTRY (*proc_type)(GLint red, GLint green, GLint blue, GLint alpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClearColorIiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClearColorIiEXT" ); }
	return (*func_ptr)( red, green, blue, alpha );
}

inline void APIENTRY glClearColorIuiEXT(GLuint red, GLuint green, GLuint blue, GLuint alpha)
{
	typedef void APIENTRY (*proc_type)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClearColorIuiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClearColorIuiEXT" ); }
	return (*func_ptr)( red, green, blue, alpha );
}

inline void APIENTRY glFrameTerminatorGREMEDY(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFrameTerminatorGREMEDY" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFrameTerminatorGREMEDY" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glBeginConditionalRenderNV(GLuint id, GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLuint id, GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginConditionalRenderNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginConditionalRenderNV" ); }
	return (*func_ptr)( id, mode );
}

inline void APIENTRY glEndConditionalRenderNV(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndConditionalRenderNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndConditionalRenderNV" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glPresentFrameKeyedNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1)
{
	typedef void APIENTRY (*proc_type)(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPresentFrameKeyedNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPresentFrameKeyedNV" ); }
	return (*func_ptr)( video_slot, minPresentTime, beginPresentTimeId, presentDurationId, type, target0, fill0, key0, target1, fill1, key1 );
}

inline void APIENTRY glPresentFrameDualFillNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3)
{
	typedef void APIENTRY (*proc_type)(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPresentFrameDualFillNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPresentFrameDualFillNV" ); }
	return (*func_ptr)( video_slot, minPresentTime, beginPresentTimeId, presentDurationId, type, target0, fill0, target1, fill1, target2, fill2, target3, fill3 );
}

inline void APIENTRY glGetVideoivNV(GLuint video_slot, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint video_slot, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVideoivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVideoivNV" ); }
	return (*func_ptr)( video_slot, pname, params );
}

inline void APIENTRY glGetVideouivNV(GLuint video_slot, GLenum pname, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint video_slot, GLenum pname, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVideouivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVideouivNV" ); }
	return (*func_ptr)( video_slot, pname, params );
}

inline void APIENTRY glGetVideoi64vNV(GLuint video_slot, GLenum pname, GLint64EXT *params)
{
	typedef void APIENTRY (*proc_type)(GLuint video_slot, GLenum pname, GLint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVideoi64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVideoi64vNV" ); }
	return (*func_ptr)( video_slot, pname, params );
}

inline void APIENTRY glGetVideoui64vNV(GLuint video_slot, GLenum pname, GLuint64EXT *params)
{
	typedef void APIENTRY (*proc_type)(GLuint video_slot, GLenum pname, GLuint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVideoui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVideoui64vNV" ); }
	return (*func_ptr)( video_slot, pname, params );
}

inline void APIENTRY glBeginTransformFeedbackEXT(GLenum primitiveMode)
{
	typedef void APIENTRY (*proc_type)(GLenum primitiveMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginTransformFeedbackEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginTransformFeedbackEXT" ); }
	return (*func_ptr)( primitiveMode );
}

inline void APIENTRY glEndTransformFeedbackEXT(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndTransformFeedbackEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndTransformFeedbackEXT" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glBindBufferRangeEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferRangeEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferRangeEXT" ); }
	return (*func_ptr)( target, index, buffer, offset, size );
}

inline void APIENTRY glBindBufferOffsetEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferOffsetEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferOffsetEXT" ); }
	return (*func_ptr)( target, index, buffer, offset );
}

inline void APIENTRY glBindBufferBaseEXT(GLenum target, GLuint index, GLuint buffer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindBufferBaseEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindBufferBaseEXT" ); }
	return (*func_ptr)( target, index, buffer );
}

inline void APIENTRY glTransformFeedbackVaryingsEXT(GLuint program, GLsizei count, const GLchar* *varyings, GLenum bufferMode)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLsizei count, const GLchar* *varyings, GLenum bufferMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTransformFeedbackVaryingsEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTransformFeedbackVaryingsEXT" ); }
	return (*func_ptr)( program, count, varyings, bufferMode );
}

inline void APIENTRY glGetTransformFeedbackVaryingEXT(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTransformFeedbackVaryingEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTransformFeedbackVaryingEXT" ); }
	return (*func_ptr)( program, index, bufSize, length, size, type, name );
}

inline void APIENTRY glClientAttribDefaultEXT(GLbitfield mask)
{
	typedef void APIENTRY (*proc_type)(GLbitfield mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glClientAttribDefaultEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glClientAttribDefaultEXT" ); }
	return (*func_ptr)( mask );
}

inline void APIENTRY glPushClientAttribDefaultEXT(GLbitfield mask)
{
	typedef void APIENTRY (*proc_type)(GLbitfield mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPushClientAttribDefaultEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPushClientAttribDefaultEXT" ); }
	return (*func_ptr)( mask );
}

inline void APIENTRY glMatrixLoadfEXT(GLenum mode, const GLfloat *m)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, const GLfloat *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixLoadfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixLoadfEXT" ); }
	return (*func_ptr)( mode, m );
}

inline void APIENTRY glMatrixLoaddEXT(GLenum mode, const GLdouble *m)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, const GLdouble *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixLoaddEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixLoaddEXT" ); }
	return (*func_ptr)( mode, m );
}

inline void APIENTRY glMatrixMultfEXT(GLenum mode, const GLfloat *m)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, const GLfloat *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixMultfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixMultfEXT" ); }
	return (*func_ptr)( mode, m );
}

inline void APIENTRY glMatrixMultdEXT(GLenum mode, const GLdouble *m)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, const GLdouble *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixMultdEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixMultdEXT" ); }
	return (*func_ptr)( mode, m );
}

inline void APIENTRY glMatrixLoadIdentityEXT(GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixLoadIdentityEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixLoadIdentityEXT" ); }
	return (*func_ptr)( mode );
}

inline void APIENTRY glMatrixRotatefEXT(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixRotatefEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixRotatefEXT" ); }
	return (*func_ptr)( mode, angle, x, y, z );
}

inline void APIENTRY glMatrixRotatedEXT(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixRotatedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixRotatedEXT" ); }
	return (*func_ptr)( mode, angle, x, y, z );
}

inline void APIENTRY glMatrixScalefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixScalefEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixScalefEXT" ); }
	return (*func_ptr)( mode, x, y, z );
}

inline void APIENTRY glMatrixScaledEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixScaledEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixScaledEXT" ); }
	return (*func_ptr)( mode, x, y, z );
}

inline void APIENTRY glMatrixTranslatefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixTranslatefEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixTranslatefEXT" ); }
	return (*func_ptr)( mode, x, y, z );
}

inline void APIENTRY glMatrixTranslatedEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixTranslatedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixTranslatedEXT" ); }
	return (*func_ptr)( mode, x, y, z );
}

inline void APIENTRY glMatrixFrustumEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixFrustumEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixFrustumEXT" ); }
	return (*func_ptr)( mode, left, right, bottom, top, zNear, zFar );
}

inline void APIENTRY glMatrixOrthoEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixOrthoEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixOrthoEXT" ); }
	return (*func_ptr)( mode, left, right, bottom, top, zNear, zFar );
}

inline void APIENTRY glMatrixPopEXT(GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixPopEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixPopEXT" ); }
	return (*func_ptr)( mode );
}

inline void APIENTRY glMatrixPushEXT(GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixPushEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixPushEXT" ); }
	return (*func_ptr)( mode );
}

inline void APIENTRY glMatrixLoadTransposefEXT(GLenum mode, const GLfloat *m)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, const GLfloat *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixLoadTransposefEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixLoadTransposefEXT" ); }
	return (*func_ptr)( mode, m );
}

inline void APIENTRY glMatrixLoadTransposedEXT(GLenum mode, const GLdouble *m)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, const GLdouble *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixLoadTransposedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixLoadTransposedEXT" ); }
	return (*func_ptr)( mode, m );
}

inline void APIENTRY glMatrixMultTransposefEXT(GLenum mode, const GLfloat *m)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, const GLfloat *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixMultTransposefEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixMultTransposefEXT" ); }
	return (*func_ptr)( mode, m );
}

inline void APIENTRY glMatrixMultTransposedEXT(GLenum mode, const GLdouble *m)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, const GLdouble *m);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMatrixMultTransposedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMatrixMultTransposedEXT" ); }
	return (*func_ptr)( mode, m );
}

inline void APIENTRY glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureParameterfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureParameterfEXT" ); }
	return (*func_ptr)( texture, target, pname, param );
}

inline void APIENTRY glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureParameterfvEXT" ); }
	return (*func_ptr)( texture, target, pname, params );
}

inline void APIENTRY glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureParameteriEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureParameteriEXT" ); }
	return (*func_ptr)( texture, target, pname, param );
}

inline void APIENTRY glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureParameterivEXT" ); }
	return (*func_ptr)( texture, target, pname, params );
}

inline void APIENTRY glTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureImage1DEXT" ); }
	return (*func_ptr)( texture, target, level, internalformat, width, border, format, type, pixels );
}

inline void APIENTRY glTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureImage2DEXT" ); }
	return (*func_ptr)( texture, target, level, internalformat, width, height, border, format, type, pixels );
}

inline void APIENTRY glTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureSubImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureSubImage1DEXT" ); }
	return (*func_ptr)( texture, target, level, xoffset, width, format, type, pixels );
}

inline void APIENTRY glTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureSubImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureSubImage2DEXT" ); }
	return (*func_ptr)( texture, target, level, xoffset, yoffset, width, height, format, type, pixels );
}

inline void APIENTRY glCopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTextureImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTextureImage1DEXT" ); }
	return (*func_ptr)( texture, target, level, internalformat, x, y, width, border );
}

inline void APIENTRY glCopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTextureImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTextureImage2DEXT" ); }
	return (*func_ptr)( texture, target, level, internalformat, x, y, width, height, border );
}

inline void APIENTRY glCopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTextureSubImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTextureSubImage1DEXT" ); }
	return (*func_ptr)( texture, target, level, xoffset, x, y, width );
}

inline void APIENTRY glCopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTextureSubImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTextureSubImage2DEXT" ); }
	return (*func_ptr)( texture, target, level, xoffset, yoffset, x, y, width, height );
}

inline void APIENTRY glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureImageEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureImageEXT" ); }
	return (*func_ptr)( texture, target, level, format, type, pixels );
}

inline void APIENTRY glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureParameterfvEXT" ); }
	return (*func_ptr)( texture, target, pname, params );
}

inline void APIENTRY glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureParameterivEXT" ); }
	return (*func_ptr)( texture, target, pname, params );
}

inline void APIENTRY glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureLevelParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureLevelParameterfvEXT" ); }
	return (*func_ptr)( texture, target, level, pname, params );
}

inline void APIENTRY glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureLevelParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureLevelParameterivEXT" ); }
	return (*func_ptr)( texture, target, level, pname, params );
}

inline void APIENTRY glTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureImage3DEXT" ); }
	return (*func_ptr)( texture, target, level, internalformat, width, height, depth, border, format, type, pixels );
}

inline void APIENTRY glTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureSubImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureSubImage3DEXT" ); }
	return (*func_ptr)( texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels );
}

inline void APIENTRY glCopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyTextureSubImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyTextureSubImage3DEXT" ); }
	return (*func_ptr)( texture, target, level, xoffset, yoffset, zoffset, x, y, width, height );
}

inline void APIENTRY glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexParameterfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexParameterfEXT" ); }
	return (*func_ptr)( texunit, target, pname, param );
}

inline void APIENTRY glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexParameterfvEXT" ); }
	return (*func_ptr)( texunit, target, pname, params );
}

inline void APIENTRY glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexParameteriEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexParameteriEXT" ); }
	return (*func_ptr)( texunit, target, pname, param );
}

inline void APIENTRY glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexParameterivEXT" ); }
	return (*func_ptr)( texunit, target, pname, params );
}

inline void APIENTRY glMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexImage1DEXT" ); }
	return (*func_ptr)( texunit, target, level, internalformat, width, border, format, type, pixels );
}

inline void APIENTRY glMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexImage2DEXT" ); }
	return (*func_ptr)( texunit, target, level, internalformat, width, height, border, format, type, pixels );
}

inline void APIENTRY glMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexSubImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexSubImage1DEXT" ); }
	return (*func_ptr)( texunit, target, level, xoffset, width, format, type, pixels );
}

inline void APIENTRY glMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexSubImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexSubImage2DEXT" ); }
	return (*func_ptr)( texunit, target, level, xoffset, yoffset, width, height, format, type, pixels );
}

inline void APIENTRY glCopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyMultiTexImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyMultiTexImage1DEXT" ); }
	return (*func_ptr)( texunit, target, level, internalformat, x, y, width, border );
}

inline void APIENTRY glCopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyMultiTexImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyMultiTexImage2DEXT" ); }
	return (*func_ptr)( texunit, target, level, internalformat, x, y, width, height, border );
}

inline void APIENTRY glCopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyMultiTexSubImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyMultiTexSubImage1DEXT" ); }
	return (*func_ptr)( texunit, target, level, xoffset, x, y, width );
}

inline void APIENTRY glCopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyMultiTexSubImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyMultiTexSubImage2DEXT" ); }
	return (*func_ptr)( texunit, target, level, xoffset, yoffset, x, y, width, height );
}

inline void APIENTRY glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexImageEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexImageEXT" ); }
	return (*func_ptr)( texunit, target, level, format, type, pixels );
}

inline void APIENTRY glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexParameterfvEXT" ); }
	return (*func_ptr)( texunit, target, pname, params );
}

inline void APIENTRY glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexParameterivEXT" ); }
	return (*func_ptr)( texunit, target, pname, params );
}

inline void APIENTRY glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexLevelParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexLevelParameterfvEXT" ); }
	return (*func_ptr)( texunit, target, level, pname, params );
}

inline void APIENTRY glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexLevelParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexLevelParameterivEXT" ); }
	return (*func_ptr)( texunit, target, level, pname, params );
}

inline void APIENTRY glMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexImage3DEXT" ); }
	return (*func_ptr)( texunit, target, level, internalformat, width, height, depth, border, format, type, pixels );
}

inline void APIENTRY glMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexSubImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexSubImage3DEXT" ); }
	return (*func_ptr)( texunit, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels );
}

inline void APIENTRY glCopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyMultiTexSubImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyMultiTexSubImage3DEXT" ); }
	return (*func_ptr)( texunit, target, level, xoffset, yoffset, zoffset, x, y, width, height );
}

inline void APIENTRY glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLuint texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindMultiTextureEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindMultiTextureEXT" ); }
	return (*func_ptr)( texunit, target, texture );
}

inline void APIENTRY glEnableClientStateIndexedEXT(GLenum array, GLuint index)
{
	typedef void APIENTRY (*proc_type)(GLenum array, GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEnableClientStateIndexedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEnableClientStateIndexedEXT" ); }
	return (*func_ptr)( array, index );
}

inline void APIENTRY glDisableClientStateIndexedEXT(GLenum array, GLuint index)
{
	typedef void APIENTRY (*proc_type)(GLenum array, GLuint index);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDisableClientStateIndexedEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDisableClientStateIndexedEXT" ); }
	return (*func_ptr)( array, index );
}

inline void APIENTRY glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexCoordPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexCoordPointerEXT" ); }
	return (*func_ptr)( texunit, size, type, stride, pointer );
}

inline void APIENTRY glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexEnvfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexEnvfEXT" ); }
	return (*func_ptr)( texunit, target, pname, param );
}

inline void APIENTRY glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexEnvfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexEnvfvEXT" ); }
	return (*func_ptr)( texunit, target, pname, params );
}

inline void APIENTRY glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexEnviEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexEnviEXT" ); }
	return (*func_ptr)( texunit, target, pname, param );
}

inline void APIENTRY glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexEnvivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexEnvivEXT" ); }
	return (*func_ptr)( texunit, target, pname, params );
}

inline void APIENTRY glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexGendEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexGendEXT" ); }
	return (*func_ptr)( texunit, coord, pname, param );
}

inline void APIENTRY glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexGendvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexGendvEXT" ); }
	return (*func_ptr)( texunit, coord, pname, params );
}

inline void APIENTRY glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexGenfEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexGenfEXT" ); }
	return (*func_ptr)( texunit, coord, pname, param );
}

inline void APIENTRY glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexGenfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexGenfvEXT" ); }
	return (*func_ptr)( texunit, coord, pname, params );
}

inline void APIENTRY glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum coord, GLenum pname, GLint param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexGeniEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexGeniEXT" ); }
	return (*func_ptr)( texunit, coord, pname, param );
}

inline void APIENTRY glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum coord, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexGenivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexGenivEXT" ); }
	return (*func_ptr)( texunit, coord, pname, params );
}

inline void APIENTRY glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexEnvfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexEnvfvEXT" ); }
	return (*func_ptr)( texunit, target, pname, params );
}

inline void APIENTRY glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexEnvivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexEnvivEXT" ); }
	return (*func_ptr)( texunit, target, pname, params );
}

inline void APIENTRY glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum coord, GLenum pname, GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexGendvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexGendvEXT" ); }
	return (*func_ptr)( texunit, coord, pname, params );
}

inline void APIENTRY glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum coord, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexGenfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexGenfvEXT" ); }
	return (*func_ptr)( texunit, coord, pname, params );
}

inline void APIENTRY glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum coord, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexGenivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexGenivEXT" ); }
	return (*func_ptr)( texunit, coord, pname, params );
}

inline void APIENTRY glGetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLfloat *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFloatIndexedvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFloatIndexedvEXT" ); }
	return (*func_ptr)( target, index, data );
}

inline void APIENTRY glGetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLdouble *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetDoubleIndexedvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetDoubleIndexedvEXT" ); }
	return (*func_ptr)( target, index, data );
}

inline void APIENTRY glGetPointerIndexedvEXT(GLenum target, GLuint index, GLvoid* *data)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLvoid* *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPointerIndexedvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPointerIndexedvEXT" ); }
	return (*func_ptr)( target, index, data );
}

inline void APIENTRY glCompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *bits)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTextureImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTextureImage3DEXT" ); }
	return (*func_ptr)( texture, target, level, internalformat, width, height, depth, border, imageSize, bits );
}

inline void APIENTRY glCompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *bits)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTextureImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTextureImage2DEXT" ); }
	return (*func_ptr)( texture, target, level, internalformat, width, height, border, imageSize, bits );
}

inline void APIENTRY glCompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *bits)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTextureImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTextureImage1DEXT" ); }
	return (*func_ptr)( texture, target, level, internalformat, width, border, imageSize, bits );
}

inline void APIENTRY glCompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *bits)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTextureSubImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTextureSubImage3DEXT" ); }
	return (*func_ptr)( texture, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits );
}

inline void APIENTRY glCompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *bits)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTextureSubImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTextureSubImage2DEXT" ); }
	return (*func_ptr)( texture, target, level, xoffset, yoffset, width, height, format, imageSize, bits );
}

inline void APIENTRY glCompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *bits)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedTextureSubImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedTextureSubImage1DEXT" ); }
	return (*func_ptr)( texture, target, level, xoffset, width, format, imageSize, bits );
}

inline void APIENTRY glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint lod, GLvoid *img)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLint lod, GLvoid *img);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCompressedTextureImageEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCompressedTextureImageEXT" ); }
	return (*func_ptr)( texture, target, lod, img );
}

inline void APIENTRY glCompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *bits)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedMultiTexImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedMultiTexImage3DEXT" ); }
	return (*func_ptr)( texunit, target, level, internalformat, width, height, depth, border, imageSize, bits );
}

inline void APIENTRY glCompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *bits)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedMultiTexImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedMultiTexImage2DEXT" ); }
	return (*func_ptr)( texunit, target, level, internalformat, width, height, border, imageSize, bits );
}

inline void APIENTRY glCompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *bits)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedMultiTexImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedMultiTexImage1DEXT" ); }
	return (*func_ptr)( texunit, target, level, internalformat, width, border, imageSize, bits );
}

inline void APIENTRY glCompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *bits)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedMultiTexSubImage3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedMultiTexSubImage3DEXT" ); }
	return (*func_ptr)( texunit, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, bits );
}

inline void APIENTRY glCompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *bits)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedMultiTexSubImage2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedMultiTexSubImage2DEXT" ); }
	return (*func_ptr)( texunit, target, level, xoffset, yoffset, width, height, format, imageSize, bits );
}

inline void APIENTRY glCompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *bits)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *bits);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCompressedMultiTexSubImage1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCompressedMultiTexSubImage1DEXT" ); }
	return (*func_ptr)( texunit, target, level, xoffset, width, format, imageSize, bits );
}

inline void APIENTRY glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint lod, GLvoid *img)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLint lod, GLvoid *img);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetCompressedMultiTexImageEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetCompressedMultiTexImageEXT" ); }
	return (*func_ptr)( texunit, target, lod, img );
}

inline void APIENTRY glNamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, const GLvoid *string)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLenum format, GLsizei len, const GLvoid *string);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramStringEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramStringEXT" ); }
	return (*func_ptr)( program, target, format, len, string );
}

inline void APIENTRY glNamedProgramLocalParameter4dEXT(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameter4dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameter4dEXT" ); }
	return (*func_ptr)( program, target, index, x, y, z, w );
}

inline void APIENTRY glNamedProgramLocalParameter4dvEXT(GLuint program, GLenum target, GLuint index, const GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLuint index, const GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameter4dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameter4dvEXT" ); }
	return (*func_ptr)( program, target, index, params );
}

inline void APIENTRY glNamedProgramLocalParameter4fEXT(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameter4fEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameter4fEXT" ); }
	return (*func_ptr)( program, target, index, x, y, z, w );
}

inline void APIENTRY glNamedProgramLocalParameter4fvEXT(GLuint program, GLenum target, GLuint index, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLuint index, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameter4fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameter4fvEXT" ); }
	return (*func_ptr)( program, target, index, params );
}

inline void APIENTRY glGetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLuint index, GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedProgramLocalParameterdvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedProgramLocalParameterdvEXT" ); }
	return (*func_ptr)( program, target, index, params );
}

inline void APIENTRY glGetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLuint index, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedProgramLocalParameterfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedProgramLocalParameterfvEXT" ); }
	return (*func_ptr)( program, target, index, params );
}

inline void APIENTRY glGetNamedProgramivEXT(GLuint program, GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedProgramivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedProgramivEXT" ); }
	return (*func_ptr)( program, target, pname, params );
}

inline void APIENTRY glGetNamedProgramStringEXT(GLuint program, GLenum target, GLenum pname, GLvoid *string)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLenum pname, GLvoid *string);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedProgramStringEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedProgramStringEXT" ); }
	return (*func_ptr)( program, target, pname, string );
}

inline void APIENTRY glNamedProgramLocalParameters4fvEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameters4fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameters4fvEXT" ); }
	return (*func_ptr)( program, target, index, count, params );
}

inline void APIENTRY glNamedProgramLocalParameterI4iEXT(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameterI4iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameterI4iEXT" ); }
	return (*func_ptr)( program, target, index, x, y, z, w );
}

inline void APIENTRY glNamedProgramLocalParameterI4ivEXT(GLuint program, GLenum target, GLuint index, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLuint index, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameterI4ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameterI4ivEXT" ); }
	return (*func_ptr)( program, target, index, params );
}

inline void APIENTRY glNamedProgramLocalParametersI4ivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParametersI4ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParametersI4ivEXT" ); }
	return (*func_ptr)( program, target, index, count, params );
}

inline void APIENTRY glNamedProgramLocalParameterI4uiEXT(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameterI4uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameterI4uiEXT" ); }
	return (*func_ptr)( program, target, index, x, y, z, w );
}

inline void APIENTRY glNamedProgramLocalParameterI4uivEXT(GLuint program, GLenum target, GLuint index, const GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLuint index, const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParameterI4uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParameterI4uivEXT" ); }
	return (*func_ptr)( program, target, index, params );
}

inline void APIENTRY glNamedProgramLocalParametersI4uivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedProgramLocalParametersI4uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedProgramLocalParametersI4uivEXT" ); }
	return (*func_ptr)( program, target, index, count, params );
}

inline void APIENTRY glGetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLuint index, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedProgramLocalParameterIivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedProgramLocalParameterIivEXT" ); }
	return (*func_ptr)( program, target, index, params );
}

inline void APIENTRY glGetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLenum target, GLuint index, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedProgramLocalParameterIuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedProgramLocalParameterIuivEXT" ); }
	return (*func_ptr)( program, target, index, params );
}

inline void APIENTRY glTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureParameterIivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureParameterIivEXT" ); }
	return (*func_ptr)( texture, target, pname, params );
}

inline void APIENTRY glTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, const GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLenum pname, const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureParameterIuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureParameterIuivEXT" ); }
	return (*func_ptr)( texture, target, pname, params );
}

inline void APIENTRY glGetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureParameterIivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureParameterIivEXT" ); }
	return (*func_ptr)( texture, target, pname, params );
}

inline void APIENTRY glGetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLenum pname, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureParameterIuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureParameterIuivEXT" ); }
	return (*func_ptr)( texture, target, pname, params );
}

inline void APIENTRY glMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexParameterIivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexParameterIivEXT" ); }
	return (*func_ptr)( texunit, target, pname, params );
}

inline void APIENTRY glMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, const GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLenum pname, const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexParameterIuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexParameterIuivEXT" ); }
	return (*func_ptr)( texunit, target, pname, params );
}

inline void APIENTRY glGetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexParameterIivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexParameterIivEXT" ); }
	return (*func_ptr)( texunit, target, pname, params );
}

inline void APIENTRY glGetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLenum pname, GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultiTexParameterIuivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultiTexParameterIuivEXT" ); }
	return (*func_ptr)( texunit, target, pname, params );
}

inline void APIENTRY glProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLfloat v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1fEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1fEXT" ); }
	return (*func_ptr)( program, location, v0 );
}

inline void APIENTRY glProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2fEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2fEXT" ); }
	return (*func_ptr)( program, location, v0, v1 );
}

inline void APIENTRY glProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3fEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3fEXT" ); }
	return (*func_ptr)( program, location, v0, v1, v2 );
}

inline void APIENTRY glProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4fEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4fEXT" ); }
	return (*func_ptr)( program, location, v0, v1, v2, v3 );
}

inline void APIENTRY glProgramUniform1iEXT(GLuint program, GLint location, GLint v0)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLint v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1iEXT" ); }
	return (*func_ptr)( program, location, v0 );
}

inline void APIENTRY glProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLint v0, GLint v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2iEXT" ); }
	return (*func_ptr)( program, location, v0, v1 );
}

inline void APIENTRY glProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3iEXT" ); }
	return (*func_ptr)( program, location, v0, v1, v2 );
}

inline void APIENTRY glProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4iEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4iEXT" ); }
	return (*func_ptr)( program, location, v0, v1, v2, v3 );
}

inline void APIENTRY glProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1fvEXT" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2fvEXT" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3fvEXT" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4fvEXT" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1ivEXT" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2ivEXT" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3ivEXT" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4ivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4ivEXT" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2fvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3fvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4fvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix2x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2x3fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2x3fvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix3x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3x2fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3x2fvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix2x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2x4fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2x4fvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix4x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4x2fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4x2fvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix3x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3x4fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3x4fvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix4x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4x3fvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4x3fvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint v0);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1uiEXT" ); }
	return (*func_ptr)( program, location, v0 );
}

inline void APIENTRY glProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint v0, GLuint v1);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2uiEXT" ); }
	return (*func_ptr)( program, location, v0, v1 );
}

inline void APIENTRY glProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3uiEXT" ); }
	return (*func_ptr)( program, location, v0, v1, v2 );
}

inline void APIENTRY glProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4uiEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4uiEXT" ); }
	return (*func_ptr)( program, location, v0, v1, v2, v3 );
}

inline void APIENTRY glProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1uivEXT" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2uivEXT" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3uivEXT" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, const GLuint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLuint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4uivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4uivEXT" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glNamedBufferDataEXT(GLuint buffer, GLsizeiptr size, const GLvoid *data, GLenum usage)
{
	typedef void APIENTRY (*proc_type)(GLuint buffer, GLsizeiptr size, const GLvoid *data, GLenum usage);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedBufferDataEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedBufferDataEXT" ); }
	return (*func_ptr)( buffer, size, data, usage );
}

inline void APIENTRY glNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedBufferSubDataEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedBufferSubDataEXT" ); }
	return (*func_ptr)( buffer, offset, size, data );
}

inline GLvoid* APIENTRY glMapNamedBufferEXT(GLuint buffer, GLenum access)
{
	typedef GLvoid* APIENTRY (*proc_type)(GLuint buffer, GLenum access);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapNamedBufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapNamedBufferEXT" ); }
	return (*func_ptr)( buffer, access );
}

inline GLboolean APIENTRY glUnmapNamedBufferEXT(GLuint buffer)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUnmapNamedBufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUnmapNamedBufferEXT" ); }
	return (*func_ptr)( buffer );
}

inline GLvoid* APIENTRY glMapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
	typedef GLvoid* APIENTRY (*proc_type)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapNamedBufferRangeEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapNamedBufferRangeEXT" ); }
	return (*func_ptr)( buffer, offset, length, access );
}

inline void APIENTRY glFlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length)
{
	typedef void APIENTRY (*proc_type)(GLuint buffer, GLintptr offset, GLsizeiptr length);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFlushMappedNamedBufferRangeEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFlushMappedNamedBufferRangeEXT" ); }
	return (*func_ptr)( buffer, offset, length );
}

inline void APIENTRY glNamedCopyBufferSubDataEXT(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
{
	typedef void APIENTRY (*proc_type)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedCopyBufferSubDataEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedCopyBufferSubDataEXT" ); }
	return (*func_ptr)( readBuffer, writeBuffer, readOffset, writeOffset, size );
}

inline void APIENTRY glGetNamedBufferParameterivEXT(GLuint buffer, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint buffer, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedBufferParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedBufferParameterivEXT" ); }
	return (*func_ptr)( buffer, pname, params );
}

inline void APIENTRY glGetNamedBufferPointervEXT(GLuint buffer, GLenum pname, GLvoid* *params)
{
	typedef void APIENTRY (*proc_type)(GLuint buffer, GLenum pname, GLvoid* *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedBufferPointervEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedBufferPointervEXT" ); }
	return (*func_ptr)( buffer, pname, params );
}

inline void APIENTRY glGetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedBufferSubDataEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedBufferSubDataEXT" ); }
	return (*func_ptr)( buffer, offset, size, data );
}

inline void APIENTRY glTextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureBufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureBufferEXT" ); }
	return (*func_ptr)( texture, target, internalformat, buffer );
}

inline void APIENTRY glMultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexBufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexBufferEXT" ); }
	return (*func_ptr)( texunit, target, internalformat, buffer );
}

inline void APIENTRY glNamedRenderbufferStorageEXT(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedRenderbufferStorageEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedRenderbufferStorageEXT" ); }
	return (*func_ptr)( renderbuffer, internalformat, width, height );
}

inline void APIENTRY glGetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint renderbuffer, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedRenderbufferParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedRenderbufferParameterivEXT" ); }
	return (*func_ptr)( renderbuffer, pname, params );
}

inline GLenum APIENTRY glCheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target)
{
	typedef GLenum APIENTRY (*proc_type)(GLuint framebuffer, GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCheckNamedFramebufferStatusEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCheckNamedFramebufferStatusEXT" ); }
	return (*func_ptr)( framebuffer, target );
}

inline void APIENTRY glNamedFramebufferTexture1DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
	typedef void APIENTRY (*proc_type)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedFramebufferTexture1DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedFramebufferTexture1DEXT" ); }
	return (*func_ptr)( framebuffer, attachment, textarget, texture, level );
}

inline void APIENTRY glNamedFramebufferTexture2DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
	typedef void APIENTRY (*proc_type)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedFramebufferTexture2DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedFramebufferTexture2DEXT" ); }
	return (*func_ptr)( framebuffer, attachment, textarget, texture, level );
}

inline void APIENTRY glNamedFramebufferTexture3DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset)
{
	typedef void APIENTRY (*proc_type)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedFramebufferTexture3DEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedFramebufferTexture3DEXT" ); }
	return (*func_ptr)( framebuffer, attachment, textarget, texture, level, zoffset );
}

inline void APIENTRY glNamedFramebufferRenderbufferEXT(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
	typedef void APIENTRY (*proc_type)(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedFramebufferRenderbufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedFramebufferRenderbufferEXT" ); }
	return (*func_ptr)( framebuffer, attachment, renderbuffertarget, renderbuffer );
}

inline void APIENTRY glGetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedFramebufferAttachmentParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedFramebufferAttachmentParameterivEXT" ); }
	return (*func_ptr)( framebuffer, attachment, pname, params );
}

inline void APIENTRY glGenerateTextureMipmapEXT(GLuint texture, GLenum target)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenerateTextureMipmapEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenerateTextureMipmapEXT" ); }
	return (*func_ptr)( texture, target );
}

inline void APIENTRY glGenerateMultiTexMipmapEXT(GLenum texunit, GLenum target)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenerateMultiTexMipmapEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenerateMultiTexMipmapEXT" ); }
	return (*func_ptr)( texunit, target );
}

inline void APIENTRY glFramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLuint framebuffer, GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferDrawBufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferDrawBufferEXT" ); }
	return (*func_ptr)( framebuffer, mode );
}

inline void APIENTRY glFramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, const GLenum *bufs)
{
	typedef void APIENTRY (*proc_type)(GLuint framebuffer, GLsizei n, const GLenum *bufs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferDrawBuffersEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferDrawBuffersEXT" ); }
	return (*func_ptr)( framebuffer, n, bufs );
}

inline void APIENTRY glFramebufferReadBufferEXT(GLuint framebuffer, GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLuint framebuffer, GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFramebufferReadBufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFramebufferReadBufferEXT" ); }
	return (*func_ptr)( framebuffer, mode );
}

inline void APIENTRY glGetFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint framebuffer, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetFramebufferParameterivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetFramebufferParameterivEXT" ); }
	return (*func_ptr)( framebuffer, pname, params );
}

inline void APIENTRY glNamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedRenderbufferStorageMultisampleEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedRenderbufferStorageMultisampleEXT" ); }
	return (*func_ptr)( renderbuffer, samples, internalformat, width, height );
}

inline void APIENTRY glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height)
{
	typedef void APIENTRY (*proc_type)(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedRenderbufferStorageMultisampleCoverageEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedRenderbufferStorageMultisampleCoverageEXT" ); }
	return (*func_ptr)( renderbuffer, coverageSamples, colorSamples, internalformat, width, height );
}

inline void APIENTRY glNamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level)
{
	typedef void APIENTRY (*proc_type)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedFramebufferTextureEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedFramebufferTextureEXT" ); }
	return (*func_ptr)( framebuffer, attachment, texture, level );
}

inline void APIENTRY glNamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
	typedef void APIENTRY (*proc_type)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedFramebufferTextureLayerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedFramebufferTextureLayerEXT" ); }
	return (*func_ptr)( framebuffer, attachment, texture, level, layer );
}

inline void APIENTRY glNamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face)
{
	typedef void APIENTRY (*proc_type)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNamedFramebufferTextureFaceEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNamedFramebufferTextureFaceEXT" ); }
	return (*func_ptr)( framebuffer, attachment, texture, level, face );
}

inline void APIENTRY glTextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureRenderbufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureRenderbufferEXT" ); }
	return (*func_ptr)( texture, target, renderbuffer );
}

inline void APIENTRY glMultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer)
{
	typedef void APIENTRY (*proc_type)(GLenum texunit, GLenum target, GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiTexRenderbufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiTexRenderbufferEXT" ); }
	return (*func_ptr)( texunit, target, renderbuffer );
}

inline void APIENTRY glProgramUniform1dEXT(GLuint program, GLint location, GLdouble x)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLdouble x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1dEXT" ); }
	return (*func_ptr)( program, location, x );
}

inline void APIENTRY glProgramUniform2dEXT(GLuint program, GLint location, GLdouble x, GLdouble y)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLdouble x, GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2dEXT" ); }
	return (*func_ptr)( program, location, x, y );
}

inline void APIENTRY glProgramUniform3dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3dEXT" ); }
	return (*func_ptr)( program, location, x, y, z );
}

inline void APIENTRY glProgramUniform4dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4dEXT" ); }
	return (*func_ptr)( program, location, x, y, z, w );
}

inline void APIENTRY glProgramUniform1dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1dvEXT" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform2dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2dvEXT" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform3dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3dvEXT" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform4dvEXT(GLuint program, GLint location, GLsizei count, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4dvEXT" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniformMatrix2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2dvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3dvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4dvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix2x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2x3dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2x3dvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix2x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix2x4dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix2x4dvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix3x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3x2dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3x2dvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix3x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix3x4dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix3x4dvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix4x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4x2dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4x2dvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glProgramUniformMatrix4x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformMatrix4x3dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformMatrix4x3dvEXT" ); }
	return (*func_ptr)( program, location, count, transpose, value );
}

inline void APIENTRY glGetMultisamplefvNV(GLenum pname, GLuint index, GLfloat *val)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLuint index, GLfloat *val);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetMultisamplefvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetMultisamplefvNV" ); }
	return (*func_ptr)( pname, index, val );
}

inline void APIENTRY glSampleMaskIndexedNV(GLuint index, GLbitfield mask)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLbitfield mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSampleMaskIndexedNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSampleMaskIndexedNV" ); }
	return (*func_ptr)( index, mask );
}

inline void APIENTRY glTexRenderbufferNV(GLenum target, GLuint renderbuffer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint renderbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexRenderbufferNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexRenderbufferNV" ); }
	return (*func_ptr)( target, renderbuffer );
}

inline void APIENTRY glBindTransformFeedbackNV(GLenum target, GLuint id)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindTransformFeedbackNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindTransformFeedbackNV" ); }
	return (*func_ptr)( target, id );
}

inline void APIENTRY glDeleteTransformFeedbacksNV(GLsizei n, const GLuint *ids)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, const GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteTransformFeedbacksNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteTransformFeedbacksNV" ); }
	return (*func_ptr)( n, ids );
}

inline void APIENTRY glGenTransformFeedbacksNV(GLsizei n, GLuint *ids)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenTransformFeedbacksNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenTransformFeedbacksNV" ); }
	return (*func_ptr)( n, ids );
}

inline GLboolean APIENTRY glIsTransformFeedbackNV(GLuint id)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsTransformFeedbackNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsTransformFeedbackNV" ); }
	return (*func_ptr)( id );
}

inline void APIENTRY glPauseTransformFeedbackNV(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPauseTransformFeedbackNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPauseTransformFeedbackNV" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glResumeTransformFeedbackNV(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glResumeTransformFeedbackNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glResumeTransformFeedbackNV" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glDrawTransformFeedbackNV(GLenum mode, GLuint id)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLuint id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDrawTransformFeedbackNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDrawTransformFeedbackNV" ); }
	return (*func_ptr)( mode, id );
}

inline void APIENTRY glGetPerfMonitorGroupsAMD(GLint *numGroups, GLsizei groupsSize, GLuint *groups)
{
	typedef void APIENTRY (*proc_type)(GLint *numGroups, GLsizei groupsSize, GLuint *groups);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPerfMonitorGroupsAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPerfMonitorGroupsAMD" ); }
	return (*func_ptr)( numGroups, groupsSize, groups );
}

inline void APIENTRY glGetPerfMonitorCountersAMD(GLuint group, GLint *numCounters, GLint *maxActiveCounters, GLsizei counterSize, GLuint *counters)
{
	typedef void APIENTRY (*proc_type)(GLuint group, GLint *numCounters, GLint *maxActiveCounters, GLsizei counterSize, GLuint *counters);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPerfMonitorCountersAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPerfMonitorCountersAMD" ); }
	return (*func_ptr)( group, numCounters, maxActiveCounters, counterSize, counters );
}

inline void APIENTRY glGetPerfMonitorGroupStringAMD(GLuint group, GLsizei bufSize, GLsizei *length, GLchar *groupString)
{
	typedef void APIENTRY (*proc_type)(GLuint group, GLsizei bufSize, GLsizei *length, GLchar *groupString);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPerfMonitorGroupStringAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPerfMonitorGroupStringAMD" ); }
	return (*func_ptr)( group, bufSize, length, groupString );
}

inline void APIENTRY glGetPerfMonitorCounterStringAMD(GLuint group, GLuint counter, GLsizei bufSize, GLsizei *length, GLchar *counterString)
{
	typedef void APIENTRY (*proc_type)(GLuint group, GLuint counter, GLsizei bufSize, GLsizei *length, GLchar *counterString);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPerfMonitorCounterStringAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPerfMonitorCounterStringAMD" ); }
	return (*func_ptr)( group, counter, bufSize, length, counterString );
}

inline void APIENTRY glGetPerfMonitorCounterInfoAMD(GLuint group, GLuint counter, GLenum pname, GLvoid *data)
{
	typedef void APIENTRY (*proc_type)(GLuint group, GLuint counter, GLenum pname, GLvoid *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPerfMonitorCounterInfoAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPerfMonitorCounterInfoAMD" ); }
	return (*func_ptr)( group, counter, pname, data );
}

inline void APIENTRY glGenPerfMonitorsAMD(GLsizei n, GLuint *monitors)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *monitors);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenPerfMonitorsAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenPerfMonitorsAMD" ); }
	return (*func_ptr)( n, monitors );
}

inline void APIENTRY glDeletePerfMonitorsAMD(GLsizei n, GLuint *monitors)
{
	typedef void APIENTRY (*proc_type)(GLsizei n, GLuint *monitors);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeletePerfMonitorsAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeletePerfMonitorsAMD" ); }
	return (*func_ptr)( n, monitors );
}

inline void APIENTRY glSelectPerfMonitorCountersAMD(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint *counterList)
{
	typedef void APIENTRY (*proc_type)(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint *counterList);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSelectPerfMonitorCountersAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSelectPerfMonitorCountersAMD" ); }
	return (*func_ptr)( monitor, enable, group, numCounters, counterList );
}

inline void APIENTRY glBeginPerfMonitorAMD(GLuint monitor)
{
	typedef void APIENTRY (*proc_type)(GLuint monitor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginPerfMonitorAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginPerfMonitorAMD" ); }
	return (*func_ptr)( monitor );
}

inline void APIENTRY glEndPerfMonitorAMD(GLuint monitor)
{
	typedef void APIENTRY (*proc_type)(GLuint monitor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndPerfMonitorAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndPerfMonitorAMD" ); }
	return (*func_ptr)( monitor );
}

inline void APIENTRY glGetPerfMonitorCounterDataAMD(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint *data, GLint *bytesWritten)
{
	typedef void APIENTRY (*proc_type)(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint *data, GLint *bytesWritten);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPerfMonitorCounterDataAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPerfMonitorCounterDataAMD" ); }
	return (*func_ptr)( monitor, pname, dataSize, data, bytesWritten );
}

inline void APIENTRY glTessellationFactorAMD(GLfloat factor)
{
	typedef void APIENTRY (*proc_type)(GLfloat factor);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTessellationFactorAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTessellationFactorAMD" ); }
	return (*func_ptr)( factor );
}

inline void APIENTRY glTessellationModeAMD(GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTessellationModeAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTessellationModeAMD" ); }
	return (*func_ptr)( mode );
}

inline void APIENTRY glProvokingVertexEXT(GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProvokingVertexEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProvokingVertexEXT" ); }
	return (*func_ptr)( mode );
}

inline void APIENTRY glBlendFuncIndexedAMD(GLuint buf, GLenum src, GLenum dst)
{
	typedef void APIENTRY (*proc_type)(GLuint buf, GLenum src, GLenum dst);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFuncIndexedAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFuncIndexedAMD" ); }
	return (*func_ptr)( buf, src, dst );
}

inline void APIENTRY glBlendFuncSeparateIndexedAMD(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
	typedef void APIENTRY (*proc_type)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendFuncSeparateIndexedAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendFuncSeparateIndexedAMD" ); }
	return (*func_ptr)( buf, srcRGB, dstRGB, srcAlpha, dstAlpha );
}

inline void APIENTRY glBlendEquationIndexedAMD(GLuint buf, GLenum mode)
{
	typedef void APIENTRY (*proc_type)(GLuint buf, GLenum mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationIndexedAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationIndexedAMD" ); }
	return (*func_ptr)( buf, mode );
}

inline void APIENTRY glBlendEquationSeparateIndexedAMD(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
{
	typedef void APIENTRY (*proc_type)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBlendEquationSeparateIndexedAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBlendEquationSeparateIndexedAMD" ); }
	return (*func_ptr)( buf, modeRGB, modeAlpha );
}

inline void APIENTRY glTextureRangeAPPLE(GLenum target, GLsizei length, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei length, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureRangeAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureRangeAPPLE" ); }
	return (*func_ptr)( target, length, pointer );
}

inline void APIENTRY glGetTexParameterPointervAPPLE(GLenum target, GLenum pname, GLvoid* *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLvoid* *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTexParameterPointervAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTexParameterPointervAPPLE" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glEnableVertexAttribAPPLE(GLuint index, GLenum pname)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEnableVertexAttribAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEnableVertexAttribAPPLE" ); }
	return (*func_ptr)( index, pname );
}

inline void APIENTRY glDisableVertexAttribAPPLE(GLuint index, GLenum pname)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDisableVertexAttribAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDisableVertexAttribAPPLE" ); }
	return (*func_ptr)( index, pname );
}

inline GLboolean APIENTRY glIsVertexAttribEnabledAPPLE(GLuint index, GLenum pname)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint index, GLenum pname);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsVertexAttribEnabledAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsVertexAttribEnabledAPPLE" ); }
	return (*func_ptr)( index, pname );
}

inline void APIENTRY glMapVertexAttrib1dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapVertexAttrib1dAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapVertexAttrib1dAPPLE" ); }
	return (*func_ptr)( index, size, u1, u2, stride, order, points );
}

inline void APIENTRY glMapVertexAttrib1fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapVertexAttrib1fAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapVertexAttrib1fAPPLE" ); }
	return (*func_ptr)( index, size, u1, u2, stride, order, points );
}

inline void APIENTRY glMapVertexAttrib2dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapVertexAttrib2dAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapVertexAttrib2dAPPLE" ); }
	return (*func_ptr)( index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points );
}

inline void APIENTRY glMapVertexAttrib2fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMapVertexAttrib2fAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMapVertexAttrib2fAPPLE" ); }
	return (*func_ptr)( index, size, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points );
}

inline GLenum APIENTRY glObjectPurgeableAPPLE(GLenum objectType, GLuint name, GLenum option)
{
	typedef GLenum APIENTRY (*proc_type)(GLenum objectType, GLuint name, GLenum option);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glObjectPurgeableAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glObjectPurgeableAPPLE" ); }
	return (*func_ptr)( objectType, name, option );
}

inline GLenum APIENTRY glObjectUnpurgeableAPPLE(GLenum objectType, GLuint name, GLenum option)
{
	typedef GLenum APIENTRY (*proc_type)(GLenum objectType, GLuint name, GLenum option);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glObjectUnpurgeableAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glObjectUnpurgeableAPPLE" ); }
	return (*func_ptr)( objectType, name, option );
}

inline void APIENTRY glGetObjectParameterivAPPLE(GLenum objectType, GLuint name, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum objectType, GLuint name, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetObjectParameterivAPPLE" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetObjectParameterivAPPLE" ); }
	return (*func_ptr)( objectType, name, pname, params );
}

inline void APIENTRY glBeginVideoCaptureNV(GLuint video_capture_slot)
{
	typedef void APIENTRY (*proc_type)(GLuint video_capture_slot);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBeginVideoCaptureNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBeginVideoCaptureNV" ); }
	return (*func_ptr)( video_capture_slot );
}

inline void APIENTRY glBindVideoCaptureStreamBufferNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset)
{
	typedef void APIENTRY (*proc_type)(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindVideoCaptureStreamBufferNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindVideoCaptureStreamBufferNV" ); }
	return (*func_ptr)( video_capture_slot, stream, frame_region, offset );
}

inline void APIENTRY glBindVideoCaptureStreamTextureNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture)
{
	typedef void APIENTRY (*proc_type)(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindVideoCaptureStreamTextureNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindVideoCaptureStreamTextureNV" ); }
	return (*func_ptr)( video_capture_slot, stream, frame_region, target, texture );
}

inline void APIENTRY glEndVideoCaptureNV(GLuint video_capture_slot)
{
	typedef void APIENTRY (*proc_type)(GLuint video_capture_slot);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEndVideoCaptureNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEndVideoCaptureNV" ); }
	return (*func_ptr)( video_capture_slot );
}

inline void APIENTRY glGetVideoCaptureivNV(GLuint video_capture_slot, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint video_capture_slot, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVideoCaptureivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVideoCaptureivNV" ); }
	return (*func_ptr)( video_capture_slot, pname, params );
}

inline void APIENTRY glGetVideoCaptureStreamivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVideoCaptureStreamivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVideoCaptureStreamivNV" ); }
	return (*func_ptr)( video_capture_slot, stream, pname, params );
}

inline void APIENTRY glGetVideoCaptureStreamfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVideoCaptureStreamfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVideoCaptureStreamfvNV" ); }
	return (*func_ptr)( video_capture_slot, stream, pname, params );
}

inline void APIENTRY glGetVideoCaptureStreamdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVideoCaptureStreamdvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVideoCaptureStreamdvNV" ); }
	return (*func_ptr)( video_capture_slot, stream, pname, params );
}

inline GLenum APIENTRY glVideoCaptureNV(GLuint video_capture_slot, GLuint *sequence_num, GLuint64EXT *capture_time)
{
	typedef GLenum APIENTRY (*proc_type)(GLuint video_capture_slot, GLuint *sequence_num, GLuint64EXT *capture_time);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVideoCaptureNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVideoCaptureNV" ); }
	return (*func_ptr)( video_capture_slot, sequence_num, capture_time );
}

inline void APIENTRY glVideoCaptureStreamParameterivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint *params)
{
	typedef void APIENTRY (*proc_type)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVideoCaptureStreamParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVideoCaptureStreamParameterivNV" ); }
	return (*func_ptr)( video_capture_slot, stream, pname, params );
}

inline void APIENTRY glVideoCaptureStreamParameterfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat *params)
{
	typedef void APIENTRY (*proc_type)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVideoCaptureStreamParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVideoCaptureStreamParameterfvNV" ); }
	return (*func_ptr)( video_capture_slot, stream, pname, params );
}

inline void APIENTRY glVideoCaptureStreamParameterdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVideoCaptureStreamParameterdvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVideoCaptureStreamParameterdvNV" ); }
	return (*func_ptr)( video_capture_slot, stream, pname, params );
}

inline void APIENTRY glCopyImageSubDataNV(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth)
{
	typedef void APIENTRY (*proc_type)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyImageSubDataNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyImageSubDataNV" ); }
	return (*func_ptr)( srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth );
}

inline void APIENTRY glUseShaderProgramEXT(GLenum type, GLuint program)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUseShaderProgramEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUseShaderProgramEXT" ); }
	return (*func_ptr)( type, program );
}

inline void APIENTRY glActiveProgramEXT(GLuint program)
{
	typedef void APIENTRY (*proc_type)(GLuint program);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glActiveProgramEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glActiveProgramEXT" ); }
	return (*func_ptr)( program );
}

inline GLuint APIENTRY glCreateShaderProgramEXT(GLenum type, const GLchar *string)
{
	typedef GLuint APIENTRY (*proc_type)(GLenum type, const GLchar *string);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCreateShaderProgramEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCreateShaderProgramEXT" ); }
	return (*func_ptr)( type, string );
}

inline void APIENTRY glMakeBufferResidentNV(GLenum target, GLenum access)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum access);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMakeBufferResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMakeBufferResidentNV" ); }
	return (*func_ptr)( target, access );
}

inline void APIENTRY glMakeBufferNonResidentNV(GLenum target)
{
	typedef void APIENTRY (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMakeBufferNonResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMakeBufferNonResidentNV" ); }
	return (*func_ptr)( target );
}

inline GLboolean APIENTRY glIsBufferResidentNV(GLenum target)
{
	typedef GLboolean APIENTRY (*proc_type)(GLenum target);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsBufferResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsBufferResidentNV" ); }
	return (*func_ptr)( target );
}

inline void APIENTRY glMakeNamedBufferResidentNV(GLuint buffer, GLenum access)
{
	typedef void APIENTRY (*proc_type)(GLuint buffer, GLenum access);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMakeNamedBufferResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMakeNamedBufferResidentNV" ); }
	return (*func_ptr)( buffer, access );
}

inline void APIENTRY glMakeNamedBufferNonResidentNV(GLuint buffer)
{
	typedef void APIENTRY (*proc_type)(GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMakeNamedBufferNonResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMakeNamedBufferNonResidentNV" ); }
	return (*func_ptr)( buffer );
}

inline GLboolean APIENTRY glIsNamedBufferResidentNV(GLuint buffer)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsNamedBufferResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsNamedBufferResidentNV" ); }
	return (*func_ptr)( buffer );
}

inline void APIENTRY glGetBufferParameterui64vNV(GLenum target, GLenum pname, GLuint64EXT *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLenum pname, GLuint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetBufferParameterui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetBufferParameterui64vNV" ); }
	return (*func_ptr)( target, pname, params );
}

inline void APIENTRY glGetNamedBufferParameterui64vNV(GLuint buffer, GLenum pname, GLuint64EXT *params)
{
	typedef void APIENTRY (*proc_type)(GLuint buffer, GLenum pname, GLuint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetNamedBufferParameterui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetNamedBufferParameterui64vNV" ); }
	return (*func_ptr)( buffer, pname, params );
}

inline void APIENTRY glGetIntegerui64vNV(GLenum value, GLuint64EXT *result)
{
	typedef void APIENTRY (*proc_type)(GLenum value, GLuint64EXT *result);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetIntegerui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetIntegerui64vNV" ); }
	return (*func_ptr)( value, result );
}

inline void APIENTRY glUniformui64NV(GLint location, GLuint64EXT value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLuint64EXT value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformui64NV" ); }
	return (*func_ptr)( location, value );
}

inline void APIENTRY glUniformui64vNV(GLint location, GLsizei count, const GLuint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformui64vNV" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glGetUniformui64vNV(GLuint program, GLint location, GLuint64EXT *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformui64vNV" ); }
	return (*func_ptr)( program, location, params );
}

inline void APIENTRY glProgramUniformui64NV(GLuint program, GLint location, GLuint64EXT value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint64EXT value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformui64NV" ); }
	return (*func_ptr)( program, location, value );
}

inline void APIENTRY glProgramUniformui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformui64vNV" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glBufferAddressRangeNV(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBufferAddressRangeNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBufferAddressRangeNV" ); }
	return (*func_ptr)( pname, index, address, length );
}

inline void APIENTRY glVertexFormatNV(GLint size, GLenum type, GLsizei stride)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexFormatNV" ); }
	return (*func_ptr)( size, type, stride );
}

inline void APIENTRY glNormalFormatNV(GLenum type, GLsizei stride)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glNormalFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glNormalFormatNV" ); }
	return (*func_ptr)( type, stride );
}

inline void APIENTRY glColorFormatNV(GLint size, GLenum type, GLsizei stride)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glColorFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glColorFormatNV" ); }
	return (*func_ptr)( size, type, stride );
}

inline void APIENTRY glIndexFormatNV(GLenum type, GLsizei stride)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIndexFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIndexFormatNV" ); }
	return (*func_ptr)( type, stride );
}

inline void APIENTRY glTexCoordFormatNV(GLint size, GLenum type, GLsizei stride)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexCoordFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexCoordFormatNV" ); }
	return (*func_ptr)( size, type, stride );
}

inline void APIENTRY glEdgeFlagFormatNV(GLsizei stride)
{
	typedef void APIENTRY (*proc_type)(GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glEdgeFlagFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glEdgeFlagFormatNV" ); }
	return (*func_ptr)( stride );
}

inline void APIENTRY glSecondaryColorFormatNV(GLint size, GLenum type, GLsizei stride)
{
	typedef void APIENTRY (*proc_type)(GLint size, GLenum type, GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSecondaryColorFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSecondaryColorFormatNV" ); }
	return (*func_ptr)( size, type, stride );
}

inline void APIENTRY glFogCoordFormatNV(GLenum type, GLsizei stride)
{
	typedef void APIENTRY (*proc_type)(GLenum type, GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glFogCoordFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glFogCoordFormatNV" ); }
	return (*func_ptr)( type, stride );
}

inline void APIENTRY glVertexAttribFormatNV(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribFormatNV" ); }
	return (*func_ptr)( index, size, type, normalized, stride );
}

inline void APIENTRY glVertexAttribIFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint size, GLenum type, GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribIFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribIFormatNV" ); }
	return (*func_ptr)( index, size, type, stride );
}

inline void APIENTRY glGetIntegerui64i_vNV(GLenum value, GLuint index, GLuint64EXT *result)
{
	typedef void APIENTRY (*proc_type)(GLenum value, GLuint index, GLuint64EXT *result);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetIntegerui64i_vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetIntegerui64i_vNV" ); }
	return (*func_ptr)( value, index, result );
}

inline void APIENTRY glTextureBarrierNV(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureBarrierNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureBarrierNV" ); }
	return (*func_ptr)(  );
}

inline void APIENTRY glBindImageTextureEXT(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glBindImageTextureEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glBindImageTextureEXT" ); }
	return (*func_ptr)( index, texture, level, layered, layer, access, format );
}

inline void APIENTRY glMemoryBarrierEXT(GLbitfield barriers)
{
	typedef void APIENTRY (*proc_type)(GLbitfield barriers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMemoryBarrierEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMemoryBarrierEXT" ); }
	return (*func_ptr)( barriers );
}

inline void APIENTRY glVertexAttribL1dEXT(GLuint index, GLdouble x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL1dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL1dEXT" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttribL2dEXT(GLuint index, GLdouble x, GLdouble y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x, GLdouble y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL2dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL2dEXT" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttribL3dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL3dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL3dEXT" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttribL4dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL4dEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL4dEXT" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttribL1dvEXT(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL1dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL1dvEXT" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribL2dvEXT(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL2dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL2dvEXT" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribL3dvEXT(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL3dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL3dvEXT" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribL4dvEXT(GLuint index, const GLdouble *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLdouble *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL4dvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL4dvEXT" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribLPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribLPointerEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribLPointerEXT" ); }
	return (*func_ptr)( index, size, type, stride, pointer );
}

inline void APIENTRY glGetVertexAttribLdvEXT(GLuint index, GLenum pname, GLdouble *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLdouble *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribLdvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribLdvEXT" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glVertexArrayVertexAttribLOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset)
{
	typedef void APIENTRY (*proc_type)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexArrayVertexAttribLOffsetEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexArrayVertexAttribLOffsetEXT" ); }
	return (*func_ptr)( vaobj, buffer, index, size, type, stride, offset );
}

inline void APIENTRY glProgramSubroutineParametersuivNV(GLenum target, GLsizei count, const GLuint *params)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei count, const GLuint *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramSubroutineParametersuivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramSubroutineParametersuivNV" ); }
	return (*func_ptr)( target, count, params );
}

inline void APIENTRY glGetProgramSubroutineParameteruivNV(GLenum target, GLuint index, GLuint *param)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLuint index, GLuint *param);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetProgramSubroutineParameteruivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetProgramSubroutineParameteruivNV" ); }
	return (*func_ptr)( target, index, param );
}

inline void APIENTRY glUniform1i64NV(GLint location, GLint64EXT x)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLint64EXT x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1i64NV" ); }
	return (*func_ptr)( location, x );
}

inline void APIENTRY glUniform2i64NV(GLint location, GLint64EXT x, GLint64EXT y)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLint64EXT x, GLint64EXT y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2i64NV" ); }
	return (*func_ptr)( location, x, y );
}

inline void APIENTRY glUniform3i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3i64NV" ); }
	return (*func_ptr)( location, x, y, z );
}

inline void APIENTRY glUniform4i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4i64NV" ); }
	return (*func_ptr)( location, x, y, z, w );
}

inline void APIENTRY glUniform1i64vNV(GLint location, GLsizei count, const GLint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1i64vNV" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform2i64vNV(GLint location, GLsizei count, const GLint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2i64vNV" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform3i64vNV(GLint location, GLsizei count, const GLint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3i64vNV" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform4i64vNV(GLint location, GLsizei count, const GLint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4i64vNV" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform1ui64NV(GLint location, GLuint64EXT x)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLuint64EXT x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1ui64NV" ); }
	return (*func_ptr)( location, x );
}

inline void APIENTRY glUniform2ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLuint64EXT x, GLuint64EXT y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2ui64NV" ); }
	return (*func_ptr)( location, x, y );
}

inline void APIENTRY glUniform3ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3ui64NV" ); }
	return (*func_ptr)( location, x, y, z );
}

inline void APIENTRY glUniform4ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4ui64NV" ); }
	return (*func_ptr)( location, x, y, z, w );
}

inline void APIENTRY glUniform1ui64vNV(GLint location, GLsizei count, const GLuint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform1ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform1ui64vNV" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform2ui64vNV(GLint location, GLsizei count, const GLuint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform2ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform2ui64vNV" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform3ui64vNV(GLint location, GLsizei count, const GLuint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform3ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform3ui64vNV" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glUniform4ui64vNV(GLint location, GLsizei count, const GLuint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniform4ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniform4ui64vNV" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glGetUniformi64vNV(GLuint program, GLint location, GLint64EXT *params)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetUniformi64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetUniformi64vNV" ); }
	return (*func_ptr)( program, location, params );
}

inline void APIENTRY glProgramUniform1i64NV(GLuint program, GLint location, GLint64EXT x)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLint64EXT x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1i64NV" ); }
	return (*func_ptr)( program, location, x );
}

inline void APIENTRY glProgramUniform2i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2i64NV" ); }
	return (*func_ptr)( program, location, x, y );
}

inline void APIENTRY glProgramUniform3i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3i64NV" ); }
	return (*func_ptr)( program, location, x, y, z );
}

inline void APIENTRY glProgramUniform4i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4i64NV" ); }
	return (*func_ptr)( program, location, x, y, z, w );
}

inline void APIENTRY glProgramUniform1i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1i64vNV" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform2i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2i64vNV" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform3i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3i64vNV" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform4i64vNV(GLuint program, GLint location, GLsizei count, const GLint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4i64vNV" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform1ui64NV(GLuint program, GLint location, GLuint64EXT x)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint64EXT x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1ui64NV" ); }
	return (*func_ptr)( program, location, x );
}

inline void APIENTRY glProgramUniform2ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2ui64NV" ); }
	return (*func_ptr)( program, location, x, y );
}

inline void APIENTRY glProgramUniform3ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3ui64NV" ); }
	return (*func_ptr)( program, location, x, y, z );
}

inline void APIENTRY glProgramUniform4ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4ui64NV" ); }
	return (*func_ptr)( program, location, x, y, z, w );
}

inline void APIENTRY glProgramUniform1ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform1ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform1ui64vNV" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform2ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform2ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform2ui64vNV" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform3ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform3ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform3ui64vNV" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glProgramUniform4ui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniform4ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniform4ui64vNV" ); }
	return (*func_ptr)( program, location, count, value );
}

inline void APIENTRY glVertexAttribL1i64NV(GLuint index, GLint64EXT x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint64EXT x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL1i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL1i64NV" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttribL2i64NV(GLuint index, GLint64EXT x, GLint64EXT y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint64EXT x, GLint64EXT y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL2i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL2i64NV" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttribL3i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL3i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL3i64NV" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttribL4i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL4i64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL4i64NV" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttribL1i64vNV(GLuint index, const GLint64EXT *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLint64EXT *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL1i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL1i64vNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribL2i64vNV(GLuint index, const GLint64EXT *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLint64EXT *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL2i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL2i64vNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribL3i64vNV(GLuint index, const GLint64EXT *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLint64EXT *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL3i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL3i64vNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribL4i64vNV(GLuint index, const GLint64EXT *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLint64EXT *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL4i64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL4i64vNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribL1ui64NV(GLuint index, GLuint64EXT x)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint64EXT x);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL1ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL1ui64NV" ); }
	return (*func_ptr)( index, x );
}

inline void APIENTRY glVertexAttribL2ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint64EXT x, GLuint64EXT y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL2ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL2ui64NV" ); }
	return (*func_ptr)( index, x, y );
}

inline void APIENTRY glVertexAttribL3ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL3ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL3ui64NV" ); }
	return (*func_ptr)( index, x, y, z );
}

inline void APIENTRY glVertexAttribL4ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL4ui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL4ui64NV" ); }
	return (*func_ptr)( index, x, y, z, w );
}

inline void APIENTRY glVertexAttribL1ui64vNV(GLuint index, const GLuint64EXT *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLuint64EXT *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL1ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL1ui64vNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribL2ui64vNV(GLuint index, const GLuint64EXT *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLuint64EXT *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL2ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL2ui64vNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribL3ui64vNV(GLuint index, const GLuint64EXT *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLuint64EXT *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL3ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL3ui64vNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glVertexAttribL4ui64vNV(GLuint index, const GLuint64EXT *v)
{
	typedef void APIENTRY (*proc_type)(GLuint index, const GLuint64EXT *v);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribL4ui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribL4ui64vNV" ); }
	return (*func_ptr)( index, v );
}

inline void APIENTRY glGetVertexAttribLi64vNV(GLuint index, GLenum pname, GLint64EXT *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribLi64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribLi64vNV" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glGetVertexAttribLui64vNV(GLuint index, GLenum pname, GLuint64EXT *params)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLenum pname, GLuint64EXT *params);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetVertexAttribLui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetVertexAttribLui64vNV" ); }
	return (*func_ptr)( index, pname, params );
}

inline void APIENTRY glVertexAttribLFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride)
{
	typedef void APIENTRY (*proc_type)(GLuint index, GLint size, GLenum type, GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVertexAttribLFormatNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVertexAttribLFormatNV" ); }
	return (*func_ptr)( index, size, type, stride );
}

inline void APIENTRY glGenNamesAMD(GLenum identifier, GLuint num, GLuint *names)
{
	typedef void APIENTRY (*proc_type)(GLenum identifier, GLuint num, GLuint *names);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenNamesAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenNamesAMD" ); }
	return (*func_ptr)( identifier, num, names );
}

inline void APIENTRY glDeleteNamesAMD(GLenum identifier, GLuint num, const GLuint *names)
{
	typedef void APIENTRY (*proc_type)(GLenum identifier, GLuint num, const GLuint *names);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeleteNamesAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeleteNamesAMD" ); }
	return (*func_ptr)( identifier, num, names );
}

inline GLboolean APIENTRY glIsNameAMD(GLenum identifier, GLuint name)
{
	typedef GLboolean APIENTRY (*proc_type)(GLenum identifier, GLuint name);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsNameAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsNameAMD" ); }
	return (*func_ptr)( identifier, name );
}

inline void APIENTRY glDebugMessageEnableAMD(GLenum category, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled)
{
	typedef void APIENTRY (*proc_type)(GLenum category, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDebugMessageEnableAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDebugMessageEnableAMD" ); }
	return (*func_ptr)( category, severity, count, ids, enabled );
}

inline void APIENTRY glDebugMessageInsertAMD(GLenum category, GLenum severity, GLuint id, GLsizei length, const GLchar *buf)
{
	typedef void APIENTRY (*proc_type)(GLenum category, GLenum severity, GLuint id, GLsizei length, const GLchar *buf);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDebugMessageInsertAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDebugMessageInsertAMD" ); }
	return (*func_ptr)( category, severity, id, length, buf );
}

inline void APIENTRY glDebugMessageCallbackAMD(GLDEBUGPROCAMD callback, GLvoid *userParam)
{
	typedef void APIENTRY (*proc_type)(GLDEBUGPROCAMD callback, GLvoid *userParam);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDebugMessageCallbackAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDebugMessageCallbackAMD" ); }
	return (*func_ptr)( callback, userParam );
}

inline GLuint APIENTRY glGetDebugMessageLogAMD(GLuint count, GLsizei bufsize, GLenum *categories, GLuint *severities, GLuint *ids, GLsizei *lengths, GLchar *message)
{
	typedef GLuint APIENTRY (*proc_type)(GLuint count, GLsizei bufsize, GLenum *categories, GLuint *severities, GLuint *ids, GLsizei *lengths, GLchar *message);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetDebugMessageLogAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetDebugMessageLogAMD" ); }
	return (*func_ptr)( count, bufsize, categories, severities, ids, lengths, message );
}

inline void APIENTRY glVDPAUInitNV(const GLvoid *vdpDevice, const GLvoid *getProcAddress)
{
	typedef void APIENTRY (*proc_type)(const GLvoid *vdpDevice, const GLvoid *getProcAddress);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAUInitNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAUInitNV" ); }
	return (*func_ptr)( vdpDevice, getProcAddress );
}

inline void APIENTRY glVDPAUFiniNV(void)
{
	typedef void APIENTRY (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAUFiniNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAUFiniNV" ); }
	return (*func_ptr)(  );
}

inline GLvdpauSurfaceNV APIENTRY glVDPAURegisterVideoSurfaceNV(GLvoid *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames)
{
	typedef GLvdpauSurfaceNV APIENTRY (*proc_type)(GLvoid *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAURegisterVideoSurfaceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAURegisterVideoSurfaceNV" ); }
	return (*func_ptr)( vdpSurface, target, numTextureNames, textureNames );
}

inline GLvdpauSurfaceNV APIENTRY glVDPAURegisterOutputSurfaceNV(GLvoid *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames)
{
	typedef GLvdpauSurfaceNV APIENTRY (*proc_type)(GLvoid *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAURegisterOutputSurfaceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAURegisterOutputSurfaceNV" ); }
	return (*func_ptr)( vdpSurface, target, numTextureNames, textureNames );
}

inline void APIENTRY glVDPAUIsSurfaceNV(GLvdpauSurfaceNV surface)
{
	typedef void APIENTRY (*proc_type)(GLvdpauSurfaceNV surface);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAUIsSurfaceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAUIsSurfaceNV" ); }
	return (*func_ptr)( surface );
}

inline void APIENTRY glVDPAUUnregisterSurfaceNV(GLvdpauSurfaceNV surface)
{
	typedef void APIENTRY (*proc_type)(GLvdpauSurfaceNV surface);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAUUnregisterSurfaceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAUUnregisterSurfaceNV" ); }
	return (*func_ptr)( surface );
}

inline void APIENTRY glVDPAUGetSurfaceivNV(GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values)
{
	typedef void APIENTRY (*proc_type)(GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAUGetSurfaceivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAUGetSurfaceivNV" ); }
	return (*func_ptr)( surface, pname, bufSize, length, values );
}

inline void APIENTRY glVDPAUSurfaceAccessNV(GLvdpauSurfaceNV surface, GLenum access)
{
	typedef void APIENTRY (*proc_type)(GLvdpauSurfaceNV surface, GLenum access);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAUSurfaceAccessNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAUSurfaceAccessNV" ); }
	return (*func_ptr)( surface, access );
}

inline void APIENTRY glVDPAUMapSurfacesNV(GLsizei numSurfaces, const GLvdpauSurfaceNV *surfaces)
{
	typedef void APIENTRY (*proc_type)(GLsizei numSurfaces, const GLvdpauSurfaceNV *surfaces);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAUMapSurfacesNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAUMapSurfacesNV" ); }
	return (*func_ptr)( numSurfaces, surfaces );
}

inline void APIENTRY glVDPAUUnmapSurfacesNV(GLsizei numSurface, const GLvdpauSurfaceNV *surfaces)
{
	typedef void APIENTRY (*proc_type)(GLsizei numSurface, const GLvdpauSurfaceNV *surfaces);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glVDPAUUnmapSurfacesNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glVDPAUUnmapSurfacesNV" ); }
	return (*func_ptr)( numSurface, surfaces );
}

inline void APIENTRY glTexImage2DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexImage2DMultisampleCoverageNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexImage2DMultisampleCoverageNV" ); }
	return (*func_ptr)( target, coverageSamples, colorSamples, internalFormat, width, height, fixedSampleLocations );
}

inline void APIENTRY glTexImage3DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations)
{
	typedef void APIENTRY (*proc_type)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTexImage3DMultisampleCoverageNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTexImage3DMultisampleCoverageNV" ); }
	return (*func_ptr)( target, coverageSamples, colorSamples, internalFormat, width, height, depth, fixedSampleLocations );
}

inline void APIENTRY glTextureImage2DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureImage2DMultisampleNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureImage2DMultisampleNV" ); }
	return (*func_ptr)( texture, target, samples, internalFormat, width, height, fixedSampleLocations );
}

inline void APIENTRY glTextureImage3DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureImage3DMultisampleNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureImage3DMultisampleNV" ); }
	return (*func_ptr)( texture, target, samples, internalFormat, width, height, depth, fixedSampleLocations );
}

inline void APIENTRY glTextureImage2DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureImage2DMultisampleCoverageNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureImage2DMultisampleCoverageNV" ); }
	return (*func_ptr)( texture, target, coverageSamples, colorSamples, internalFormat, width, height, fixedSampleLocations );
}

inline void APIENTRY glTextureImage3DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations)
{
	typedef void APIENTRY (*proc_type)(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTextureImage3DMultisampleCoverageNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTextureImage3DMultisampleCoverageNV" ); }
	return (*func_ptr)( texture, target, coverageSamples, colorSamples, internalFormat, width, height, depth, fixedSampleLocations );
}

inline void APIENTRY glSetMultisamplefvAMD(GLenum pname, GLuint index, const GLfloat *val)
{
	typedef void APIENTRY (*proc_type)(GLenum pname, GLuint index, const GLfloat *val);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glSetMultisamplefvAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glSetMultisamplefvAMD" ); }
	return (*func_ptr)( pname, index, val );
}

inline GLsync APIENTRY glImportSyncEXT(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags)
{
	typedef GLsync APIENTRY (*proc_type)(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glImportSyncEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glImportSyncEXT" ); }
	return (*func_ptr)( external_sync_type, external_sync, flags );
}

inline void APIENTRY glMultiDrawArraysIndirectAMD(GLenum mode, const GLvoid *indirect, GLsizei primcount, GLsizei stride)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, const GLvoid *indirect, GLsizei primcount, GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawArraysIndirectAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawArraysIndirectAMD" ); }
	return (*func_ptr)( mode, indirect, primcount, stride );
}

inline void APIENTRY glMultiDrawElementsIndirectAMD(GLenum mode, GLenum type, const GLvoid *indirect, GLsizei primcount, GLsizei stride)
{
	typedef void APIENTRY (*proc_type)(GLenum mode, GLenum type, const GLvoid *indirect, GLsizei primcount, GLsizei stride);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMultiDrawElementsIndirectAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMultiDrawElementsIndirectAMD" ); }
	return (*func_ptr)( mode, type, indirect, primcount, stride );
}

inline GLuint APIENTRY glGenPathsNV(GLsizei range)
{
	typedef GLuint APIENTRY (*proc_type)(GLsizei range);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGenPathsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGenPathsNV" ); }
	return (*func_ptr)( range );
}

inline void APIENTRY glDeletePathsNV(GLuint path, GLsizei range)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLsizei range);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glDeletePathsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glDeletePathsNV" ); }
	return (*func_ptr)( path, range );
}

inline GLboolean APIENTRY glIsPathNV(GLuint path)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint path);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsPathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsPathNV" ); }
	return (*func_ptr)( path );
}

inline void APIENTRY glPathCommandsNV(GLuint path, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const GLvoid *coords)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const GLvoid *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathCommandsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathCommandsNV" ); }
	return (*func_ptr)( path, numCommands, commands, numCoords, coordType, coords );
}

inline void APIENTRY glPathCoordsNV(GLuint path, GLsizei numCoords, GLenum coordType, const GLvoid *coords)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLsizei numCoords, GLenum coordType, const GLvoid *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathCoordsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathCoordsNV" ); }
	return (*func_ptr)( path, numCoords, coordType, coords );
}

inline void APIENTRY glPathSubCommandsNV(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const GLvoid *coords)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const GLvoid *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathSubCommandsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathSubCommandsNV" ); }
	return (*func_ptr)( path, commandStart, commandsToDelete, numCommands, commands, numCoords, coordType, coords );
}

inline void APIENTRY glPathSubCoordsNV(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const GLvoid *coords)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const GLvoid *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathSubCoordsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathSubCoordsNV" ); }
	return (*func_ptr)( path, coordStart, numCoords, coordType, coords );
}

inline void APIENTRY glPathStringNV(GLuint path, GLenum format, GLsizei length, const GLvoid *pathString)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLenum format, GLsizei length, const GLvoid *pathString);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathStringNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathStringNV" ); }
	return (*func_ptr)( path, format, length, pathString );
}

inline void APIENTRY glPathGlyphsNV(GLuint firstPathName, GLenum fontTarget, const GLvoid *fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const GLvoid *charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale)
{
	typedef void APIENTRY (*proc_type)(GLuint firstPathName, GLenum fontTarget, const GLvoid *fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const GLvoid *charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathGlyphsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathGlyphsNV" ); }
	return (*func_ptr)( firstPathName, fontTarget, fontName, fontStyle, numGlyphs, type, charcodes, handleMissingGlyphs, pathParameterTemplate, emScale );
}

inline void APIENTRY glPathGlyphRangeNV(GLuint firstPathName, GLenum fontTarget, const GLvoid *fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale)
{
	typedef void APIENTRY (*proc_type)(GLuint firstPathName, GLenum fontTarget, const GLvoid *fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathGlyphRangeNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathGlyphRangeNV" ); }
	return (*func_ptr)( firstPathName, fontTarget, fontName, fontStyle, firstGlyph, numGlyphs, handleMissingGlyphs, pathParameterTemplate, emScale );
}

inline void APIENTRY glWeightPathsNV(GLuint resultPath, GLsizei numPaths, const GLuint *paths, const GLfloat *weights)
{
	typedef void APIENTRY (*proc_type)(GLuint resultPath, GLsizei numPaths, const GLuint *paths, const GLfloat *weights);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glWeightPathsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glWeightPathsNV" ); }
	return (*func_ptr)( resultPath, numPaths, paths, weights );
}

inline void APIENTRY glCopyPathNV(GLuint resultPath, GLuint srcPath)
{
	typedef void APIENTRY (*proc_type)(GLuint resultPath, GLuint srcPath);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCopyPathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCopyPathNV" ); }
	return (*func_ptr)( resultPath, srcPath );
}

inline void APIENTRY glInterpolatePathsNV(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight)
{
	typedef void APIENTRY (*proc_type)(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glInterpolatePathsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glInterpolatePathsNV" ); }
	return (*func_ptr)( resultPath, pathA, pathB, weight );
}

inline void APIENTRY glTransformPathNV(GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat *transformValues)
{
	typedef void APIENTRY (*proc_type)(GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat *transformValues);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glTransformPathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glTransformPathNV" ); }
	return (*func_ptr)( resultPath, srcPath, transformType, transformValues );
}

inline void APIENTRY glPathParameterivNV(GLuint path, GLenum pname, const GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLenum pname, const GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathParameterivNV" ); }
	return (*func_ptr)( path, pname, value );
}

inline void APIENTRY glPathParameteriNV(GLuint path, GLenum pname, GLint value)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLenum pname, GLint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathParameteriNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathParameteriNV" ); }
	return (*func_ptr)( path, pname, value );
}

inline void APIENTRY glPathParameterfvNV(GLuint path, GLenum pname, const GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLenum pname, const GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathParameterfvNV" ); }
	return (*func_ptr)( path, pname, value );
}

inline void APIENTRY glPathParameterfNV(GLuint path, GLenum pname, GLfloat value)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLenum pname, GLfloat value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathParameterfNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathParameterfNV" ); }
	return (*func_ptr)( path, pname, value );
}

inline void APIENTRY glPathDashArrayNV(GLuint path, GLsizei dashCount, const GLfloat *dashArray)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLsizei dashCount, const GLfloat *dashArray);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathDashArrayNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathDashArrayNV" ); }
	return (*func_ptr)( path, dashCount, dashArray );
}

inline void APIENTRY glPathStencilFuncNV(GLenum func, GLint ref, GLuint mask)
{
	typedef void APIENTRY (*proc_type)(GLenum func, GLint ref, GLuint mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathStencilFuncNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathStencilFuncNV" ); }
	return (*func_ptr)( func, ref, mask );
}

inline void APIENTRY glPathStencilDepthOffsetNV(GLfloat factor, GLfloat units)
{
	typedef void APIENTRY (*proc_type)(GLfloat factor, GLfloat units);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathStencilDepthOffsetNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathStencilDepthOffsetNV" ); }
	return (*func_ptr)( factor, units );
}

inline void APIENTRY glStencilFillPathNV(GLuint path, GLenum fillMode, GLuint mask)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLenum fillMode, GLuint mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilFillPathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilFillPathNV" ); }
	return (*func_ptr)( path, fillMode, mask );
}

inline void APIENTRY glStencilStrokePathNV(GLuint path, GLint reference, GLuint mask)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLint reference, GLuint mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilStrokePathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilStrokePathNV" ); }
	return (*func_ptr)( path, reference, mask );
}

inline void APIENTRY glStencilFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const GLvoid *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat *transformValues)
{
	typedef void APIENTRY (*proc_type)(GLsizei numPaths, GLenum pathNameType, const GLvoid *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat *transformValues);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilFillPathInstancedNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilFillPathInstancedNV" ); }
	return (*func_ptr)( numPaths, pathNameType, paths, pathBase, fillMode, mask, transformType, transformValues );
}

inline void APIENTRY glStencilStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const GLvoid *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat *transformValues)
{
	typedef void APIENTRY (*proc_type)(GLsizei numPaths, GLenum pathNameType, const GLvoid *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat *transformValues);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilStrokePathInstancedNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilStrokePathInstancedNV" ); }
	return (*func_ptr)( numPaths, pathNameType, paths, pathBase, reference, mask, transformType, transformValues );
}

inline void APIENTRY glPathCoverDepthFuncNV(GLenum func)
{
	typedef void APIENTRY (*proc_type)(GLenum func);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathCoverDepthFuncNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathCoverDepthFuncNV" ); }
	return (*func_ptr)( func );
}

inline void APIENTRY glPathColorGenNV(GLenum color, GLenum genMode, GLenum colorFormat, const GLfloat *coeffs)
{
	typedef void APIENTRY (*proc_type)(GLenum color, GLenum genMode, GLenum colorFormat, const GLfloat *coeffs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathColorGenNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathColorGenNV" ); }
	return (*func_ptr)( color, genMode, colorFormat, coeffs );
}

inline void APIENTRY glPathTexGenNV(GLenum texCoordSet, GLenum genMode, GLint components, const GLfloat *coeffs)
{
	typedef void APIENTRY (*proc_type)(GLenum texCoordSet, GLenum genMode, GLint components, const GLfloat *coeffs);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathTexGenNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathTexGenNV" ); }
	return (*func_ptr)( texCoordSet, genMode, components, coeffs );
}

inline void APIENTRY glPathFogGenNV(GLenum genMode)
{
	typedef void APIENTRY (*proc_type)(GLenum genMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPathFogGenNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPathFogGenNV" ); }
	return (*func_ptr)( genMode );
}

inline void APIENTRY glCoverFillPathNV(GLuint path, GLenum coverMode)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLenum coverMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCoverFillPathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCoverFillPathNV" ); }
	return (*func_ptr)( path, coverMode );
}

inline void APIENTRY glCoverStrokePathNV(GLuint path, GLenum coverMode)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLenum coverMode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCoverStrokePathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCoverStrokePathNV" ); }
	return (*func_ptr)( path, coverMode );
}

inline void APIENTRY glCoverFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const GLvoid *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues)
{
	typedef void APIENTRY (*proc_type)(GLsizei numPaths, GLenum pathNameType, const GLvoid *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCoverFillPathInstancedNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCoverFillPathInstancedNV" ); }
	return (*func_ptr)( numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues );
}

inline void APIENTRY glCoverStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const GLvoid *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues)
{
	typedef void APIENTRY (*proc_type)(GLsizei numPaths, GLenum pathNameType, const GLvoid *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glCoverStrokePathInstancedNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glCoverStrokePathInstancedNV" ); }
	return (*func_ptr)( numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues );
}

inline void APIENTRY glGetPathParameterivNV(GLuint path, GLenum pname, GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLenum pname, GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathParameterivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathParameterivNV" ); }
	return (*func_ptr)( path, pname, value );
}

inline void APIENTRY glGetPathParameterfvNV(GLuint path, GLenum pname, GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLenum pname, GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathParameterfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathParameterfvNV" ); }
	return (*func_ptr)( path, pname, value );
}

inline void APIENTRY glGetPathCommandsNV(GLuint path, GLubyte *commands)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLubyte *commands);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathCommandsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathCommandsNV" ); }
	return (*func_ptr)( path, commands );
}

inline void APIENTRY glGetPathCoordsNV(GLuint path, GLfloat *coords)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLfloat *coords);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathCoordsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathCoordsNV" ); }
	return (*func_ptr)( path, coords );
}

inline void APIENTRY glGetPathDashArrayNV(GLuint path, GLfloat *dashArray)
{
	typedef void APIENTRY (*proc_type)(GLuint path, GLfloat *dashArray);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathDashArrayNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathDashArrayNV" ); }
	return (*func_ptr)( path, dashArray );
}

inline void APIENTRY glGetPathMetricsNV(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const GLvoid *paths, GLuint pathBase, GLsizei stride, GLfloat *metrics)
{
	typedef void APIENTRY (*proc_type)(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const GLvoid *paths, GLuint pathBase, GLsizei stride, GLfloat *metrics);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathMetricsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathMetricsNV" ); }
	return (*func_ptr)( metricQueryMask, numPaths, pathNameType, paths, pathBase, stride, metrics );
}

inline void APIENTRY glGetPathMetricRangeNV(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat *metrics)
{
	typedef void APIENTRY (*proc_type)(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat *metrics);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathMetricRangeNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathMetricRangeNV" ); }
	return (*func_ptr)( metricQueryMask, firstPathName, numPaths, stride, metrics );
}

inline void APIENTRY glGetPathSpacingNV(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const GLvoid *paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat *returnedSpacing)
{
	typedef void APIENTRY (*proc_type)(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const GLvoid *paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat *returnedSpacing);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathSpacingNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathSpacingNV" ); }
	return (*func_ptr)( pathListMode, numPaths, pathNameType, paths, pathBase, advanceScale, kerningScale, transformType, returnedSpacing );
}

inline void APIENTRY glGetPathColorGenivNV(GLenum color, GLenum pname, GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLenum color, GLenum pname, GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathColorGenivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathColorGenivNV" ); }
	return (*func_ptr)( color, pname, value );
}

inline void APIENTRY glGetPathColorGenfvNV(GLenum color, GLenum pname, GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLenum color, GLenum pname, GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathColorGenfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathColorGenfvNV" ); }
	return (*func_ptr)( color, pname, value );
}

inline void APIENTRY glGetPathTexGenivNV(GLenum texCoordSet, GLenum pname, GLint *value)
{
	typedef void APIENTRY (*proc_type)(GLenum texCoordSet, GLenum pname, GLint *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathTexGenivNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathTexGenivNV" ); }
	return (*func_ptr)( texCoordSet, pname, value );
}

inline void APIENTRY glGetPathTexGenfvNV(GLenum texCoordSet, GLenum pname, GLfloat *value)
{
	typedef void APIENTRY (*proc_type)(GLenum texCoordSet, GLenum pname, GLfloat *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathTexGenfvNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathTexGenfvNV" ); }
	return (*func_ptr)( texCoordSet, pname, value );
}

inline GLboolean APIENTRY glIsPointInFillPathNV(GLuint path, GLuint mask, GLfloat x, GLfloat y)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint path, GLuint mask, GLfloat x, GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsPointInFillPathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsPointInFillPathNV" ); }
	return (*func_ptr)( path, mask, x, y );
}

inline GLboolean APIENTRY glIsPointInStrokePathNV(GLuint path, GLfloat x, GLfloat y)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint path, GLfloat x, GLfloat y);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsPointInStrokePathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsPointInStrokePathNV" ); }
	return (*func_ptr)( path, x, y );
}

inline GLfloat APIENTRY glGetPathLengthNV(GLuint path, GLsizei startSegment, GLsizei numSegments)
{
	typedef GLfloat APIENTRY (*proc_type)(GLuint path, GLsizei startSegment, GLsizei numSegments);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetPathLengthNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetPathLengthNV" ); }
	return (*func_ptr)( path, startSegment, numSegments );
}

inline GLboolean APIENTRY glPointAlongPathNV(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat *x, GLfloat *y, GLfloat *tangentX, GLfloat *tangentY)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat *x, GLfloat *y, GLfloat *tangentX, GLfloat *tangentY);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glPointAlongPathNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glPointAlongPathNV" ); }
	return (*func_ptr)( path, startSegment, numSegments, distance, x, y, tangentX, tangentY );
}

inline void APIENTRY glStencilOpValueAMD(GLenum face, GLuint value)
{
	typedef void APIENTRY (*proc_type)(GLenum face, GLuint value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glStencilOpValueAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glStencilOpValueAMD" ); }
	return (*func_ptr)( face, value );
}

inline GLuint64 APIENTRY glGetTextureHandleNV(GLuint texture)
{
	typedef GLuint64 APIENTRY (*proc_type)(GLuint texture);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureHandleNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureHandleNV" ); }
	return (*func_ptr)( texture );
}

inline GLuint64 APIENTRY glGetTextureSamplerHandleNV(GLuint texture, GLuint sampler)
{
	typedef GLuint64 APIENTRY (*proc_type)(GLuint texture, GLuint sampler);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetTextureSamplerHandleNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetTextureSamplerHandleNV" ); }
	return (*func_ptr)( texture, sampler );
}

inline void APIENTRY glMakeTextureHandleResidentNV(GLuint64 handle)
{
	typedef void APIENTRY (*proc_type)(GLuint64 handle);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMakeTextureHandleResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMakeTextureHandleResidentNV" ); }
	return (*func_ptr)( handle );
}

inline void APIENTRY glMakeTextureHandleNonResidentNV(GLuint64 handle)
{
	typedef void APIENTRY (*proc_type)(GLuint64 handle);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMakeTextureHandleNonResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMakeTextureHandleNonResidentNV" ); }
	return (*func_ptr)( handle );
}

inline GLuint64 APIENTRY glGetImageHandleNV(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format)
{
	typedef GLuint64 APIENTRY (*proc_type)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glGetImageHandleNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glGetImageHandleNV" ); }
	return (*func_ptr)( texture, level, layered, layer, format );
}

inline void APIENTRY glMakeImageHandleResidentNV(GLuint64 handle, GLenum access)
{
	typedef void APIENTRY (*proc_type)(GLuint64 handle, GLenum access);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMakeImageHandleResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMakeImageHandleResidentNV" ); }
	return (*func_ptr)( handle, access );
}

inline void APIENTRY glMakeImageHandleNonResidentNV(GLuint64 handle)
{
	typedef void APIENTRY (*proc_type)(GLuint64 handle);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glMakeImageHandleNonResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glMakeImageHandleNonResidentNV" ); }
	return (*func_ptr)( handle );
}

inline void APIENTRY glUniformHandleui64NV(GLint location, GLuint64 value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLuint64 value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformHandleui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformHandleui64NV" ); }
	return (*func_ptr)( location, value );
}

inline void APIENTRY glUniformHandleui64vNV(GLint location, GLsizei count, const GLuint64 *value)
{
	typedef void APIENTRY (*proc_type)(GLint location, GLsizei count, const GLuint64 *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glUniformHandleui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glUniformHandleui64vNV" ); }
	return (*func_ptr)( location, count, value );
}

inline void APIENTRY glProgramUniformHandleui64NV(GLuint program, GLint location, GLuint64 value)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLuint64 value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformHandleui64NV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformHandleui64NV" ); }
	return (*func_ptr)( program, location, value );
}

inline void APIENTRY glProgramUniformHandleui64vNV(GLuint program, GLint location, GLsizei count, const GLuint64 *values)
{
	typedef void APIENTRY (*proc_type)(GLuint program, GLint location, GLsizei count, const GLuint64 *values);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glProgramUniformHandleui64vNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glProgramUniformHandleui64vNV" ); }
	return (*func_ptr)( program, location, count, values );
}

inline GLboolean APIENTRY glIsTextureHandleResidentNV(GLuint64 handle)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint64 handle);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsTextureHandleResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsTextureHandleResidentNV" ); }
	return (*func_ptr)( handle );
}

inline GLboolean APIENTRY glIsImageHandleResidentNV(GLuint64 handle)
{
	typedef GLboolean APIENTRY (*proc_type)(GLuint64 handle);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glIsImageHandleResidentNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glIsImageHandleResidentNV" ); }
	return (*func_ptr)( handle );
}


#endif // GLEWLLE_HPP_
