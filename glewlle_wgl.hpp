// glewlle_wgl
// Copyright (C) 2012 LNSEAB

#ifndef GLEWLLE_WGL_HPP_
#define GLEWLLE_WGL_HPP_

#include <glewlle.hpp>

#include <wglext.h>

inline HANDLE WINAPI wglCreateBufferRegionARB(HDC hDC, int iLayerPlane, UINT uType)
{
	typedef HANDLE WINAPI (*proc_type)(HDC hDC, int iLayerPlane, UINT uType);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglCreateBufferRegionARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglCreateBufferRegionARB" ); }
	return (*func_ptr)( hDC, iLayerPlane, uType );
}

inline VOID WINAPI wglDeleteBufferRegionARB(HANDLE hRegion)
{
	typedef VOID WINAPI (*proc_type)(HANDLE hRegion);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglDeleteBufferRegionARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglDeleteBufferRegionARB" ); }
	return (*func_ptr)( hRegion );
}

inline BOOL WINAPI wglSaveBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height)
{
	typedef BOOL WINAPI (*proc_type)(HANDLE hRegion, int x, int y, int width, int height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglSaveBufferRegionARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglSaveBufferRegionARB" ); }
	return (*func_ptr)( hRegion, x, y, width, height );
}

inline BOOL WINAPI wglRestoreBufferRegionARB(HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc)
{
	typedef BOOL WINAPI (*proc_type)(HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglRestoreBufferRegionARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglRestoreBufferRegionARB" ); }
	return (*func_ptr)( hRegion, x, y, width, height, xSrc, ySrc );
}

inline const char * WINAPI wglGetExtensionsStringARB(HDC hdc)
{
	typedef const char * WINAPI (*proc_type)(HDC hdc);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetExtensionsStringARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetExtensionsStringARB" ); }
	return (*func_ptr)( hdc );
}

inline BOOL WINAPI wglGetPixelFormatAttribivARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues)
{
	typedef BOOL WINAPI (*proc_type)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetPixelFormatAttribivARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetPixelFormatAttribivARB" ); }
	return (*func_ptr)( hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues );
}

inline BOOL WINAPI wglGetPixelFormatAttribfvARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues)
{
	typedef BOOL WINAPI (*proc_type)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetPixelFormatAttribfvARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetPixelFormatAttribfvARB" ); }
	return (*func_ptr)( hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues );
}

inline BOOL WINAPI wglChoosePixelFormatARB(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats)
{
	typedef BOOL WINAPI (*proc_type)(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglChoosePixelFormatARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglChoosePixelFormatARB" ); }
	return (*func_ptr)( hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats );
}

inline BOOL WINAPI wglMakeContextCurrentARB(HDC hDrawDC, HDC hReadDC, HGLRC hglrc)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglMakeContextCurrentARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglMakeContextCurrentARB" ); }
	return (*func_ptr)( hDrawDC, hReadDC, hglrc );
}

inline HDC WINAPI wglGetCurrentReadDCARB(void)
{
	typedef HDC WINAPI (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetCurrentReadDCARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetCurrentReadDCARB" ); }
	return (*func_ptr)(  );
}

inline HPBUFFERARB WINAPI wglCreatePbufferARB(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList)
{
	typedef HPBUFFERARB WINAPI (*proc_type)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglCreatePbufferARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglCreatePbufferARB" ); }
	return (*func_ptr)( hDC, iPixelFormat, iWidth, iHeight, piAttribList );
}

inline HDC WINAPI wglGetPbufferDCARB(HPBUFFERARB hPbuffer)
{
	typedef HDC WINAPI (*proc_type)(HPBUFFERARB hPbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetPbufferDCARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetPbufferDCARB" ); }
	return (*func_ptr)( hPbuffer );
}

inline int WINAPI wglReleasePbufferDCARB(HPBUFFERARB hPbuffer, HDC hDC)
{
	typedef int WINAPI (*proc_type)(HPBUFFERARB hPbuffer, HDC hDC);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglReleasePbufferDCARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglReleasePbufferDCARB" ); }
	return (*func_ptr)( hPbuffer, hDC );
}

inline BOOL WINAPI wglDestroyPbufferARB(HPBUFFERARB hPbuffer)
{
	typedef BOOL WINAPI (*proc_type)(HPBUFFERARB hPbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglDestroyPbufferARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglDestroyPbufferARB" ); }
	return (*func_ptr)( hPbuffer );
}

inline BOOL WINAPI wglQueryPbufferARB(HPBUFFERARB hPbuffer, int iAttribute, int *piValue)
{
	typedef BOOL WINAPI (*proc_type)(HPBUFFERARB hPbuffer, int iAttribute, int *piValue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglQueryPbufferARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglQueryPbufferARB" ); }
	return (*func_ptr)( hPbuffer, iAttribute, piValue );
}

inline BOOL WINAPI wglBindTexImageARB(HPBUFFERARB hPbuffer, int iBuffer)
{
	typedef BOOL WINAPI (*proc_type)(HPBUFFERARB hPbuffer, int iBuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglBindTexImageARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglBindTexImageARB" ); }
	return (*func_ptr)( hPbuffer, iBuffer );
}

inline BOOL WINAPI wglReleaseTexImageARB(HPBUFFERARB hPbuffer, int iBuffer)
{
	typedef BOOL WINAPI (*proc_type)(HPBUFFERARB hPbuffer, int iBuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglReleaseTexImageARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglReleaseTexImageARB" ); }
	return (*func_ptr)( hPbuffer, iBuffer );
}

inline BOOL WINAPI wglSetPbufferAttribARB(HPBUFFERARB hPbuffer, const int *piAttribList)
{
	typedef BOOL WINAPI (*proc_type)(HPBUFFERARB hPbuffer, const int *piAttribList);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglSetPbufferAttribARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglSetPbufferAttribARB" ); }
	return (*func_ptr)( hPbuffer, piAttribList );
}

inline HGLRC WINAPI wglCreateContextAttribsARB(HDC hDC, HGLRC hShareContext, const int *attribList)
{
	typedef HGLRC WINAPI (*proc_type)(HDC hDC, HGLRC hShareContext, const int *attribList);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglCreateContextAttribsARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglCreateContextAttribsARB" ); }
	return (*func_ptr)( hDC, hShareContext, attribList );
}

inline GLboolean WINAPI wglCreateDisplayColorTableEXT(GLushort id)
{
	typedef GLboolean WINAPI (*proc_type)(GLushort id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglCreateDisplayColorTableEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglCreateDisplayColorTableEXT" ); }
	return (*func_ptr)( id );
}

inline GLboolean WINAPI wglLoadDisplayColorTableEXT(const GLushort *table, GLuint length)
{
	typedef GLboolean WINAPI (*proc_type)(const GLushort *table, GLuint length);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglLoadDisplayColorTableEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglLoadDisplayColorTableEXT" ); }
	return (*func_ptr)( table, length );
}

inline GLboolean WINAPI wglBindDisplayColorTableEXT(GLushort id)
{
	typedef GLboolean WINAPI (*proc_type)(GLushort id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglBindDisplayColorTableEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglBindDisplayColorTableEXT" ); }
	return (*func_ptr)( id );
}

inline VOID WINAPI wglDestroyDisplayColorTableEXT(GLushort id)
{
	typedef VOID WINAPI (*proc_type)(GLushort id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglDestroyDisplayColorTableEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglDestroyDisplayColorTableEXT" ); }
	return (*func_ptr)( id );
}

inline const char * WINAPI wglGetExtensionsStringEXT(void)
{
	typedef const char * WINAPI (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetExtensionsStringEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetExtensionsStringEXT" ); }
	return (*func_ptr)(  );
}

inline BOOL WINAPI wglMakeContextCurrentEXT(HDC hDrawDC, HDC hReadDC, HGLRC hglrc)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglMakeContextCurrentEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglMakeContextCurrentEXT" ); }
	return (*func_ptr)( hDrawDC, hReadDC, hglrc );
}

inline HDC WINAPI wglGetCurrentReadDCEXT(void)
{
	typedef HDC WINAPI (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetCurrentReadDCEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetCurrentReadDCEXT" ); }
	return (*func_ptr)(  );
}

inline HPBUFFEREXT WINAPI wglCreatePbufferEXT(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList)
{
	typedef HPBUFFEREXT WINAPI (*proc_type)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglCreatePbufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglCreatePbufferEXT" ); }
	return (*func_ptr)( hDC, iPixelFormat, iWidth, iHeight, piAttribList );
}

inline HDC WINAPI wglGetPbufferDCEXT(HPBUFFEREXT hPbuffer)
{
	typedef HDC WINAPI (*proc_type)(HPBUFFEREXT hPbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetPbufferDCEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetPbufferDCEXT" ); }
	return (*func_ptr)( hPbuffer );
}

inline int WINAPI wglReleasePbufferDCEXT(HPBUFFEREXT hPbuffer, HDC hDC)
{
	typedef int WINAPI (*proc_type)(HPBUFFEREXT hPbuffer, HDC hDC);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglReleasePbufferDCEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglReleasePbufferDCEXT" ); }
	return (*func_ptr)( hPbuffer, hDC );
}

inline BOOL WINAPI wglDestroyPbufferEXT(HPBUFFEREXT hPbuffer)
{
	typedef BOOL WINAPI (*proc_type)(HPBUFFEREXT hPbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglDestroyPbufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglDestroyPbufferEXT" ); }
	return (*func_ptr)( hPbuffer );
}

inline BOOL WINAPI wglQueryPbufferEXT(HPBUFFEREXT hPbuffer, int iAttribute, int *piValue)
{
	typedef BOOL WINAPI (*proc_type)(HPBUFFEREXT hPbuffer, int iAttribute, int *piValue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglQueryPbufferEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglQueryPbufferEXT" ); }
	return (*func_ptr)( hPbuffer, iAttribute, piValue );
}

inline BOOL WINAPI wglGetPixelFormatAttribivEXT(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, int *piValues)
{
	typedef BOOL WINAPI (*proc_type)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, int *piValues);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetPixelFormatAttribivEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetPixelFormatAttribivEXT" ); }
	return (*func_ptr)( hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues );
}

inline BOOL WINAPI wglGetPixelFormatAttribfvEXT(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, FLOAT *pfValues)
{
	typedef BOOL WINAPI (*proc_type)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, FLOAT *pfValues);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetPixelFormatAttribfvEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetPixelFormatAttribfvEXT" ); }
	return (*func_ptr)( hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues );
}

inline BOOL WINAPI wglChoosePixelFormatEXT(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats)
{
	typedef BOOL WINAPI (*proc_type)(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglChoosePixelFormatEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglChoosePixelFormatEXT" ); }
	return (*func_ptr)( hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats );
}

inline BOOL WINAPI wglSwapIntervalEXT(int interval)
{
	typedef BOOL WINAPI (*proc_type)(int interval);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglSwapIntervalEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglSwapIntervalEXT" ); }
	return (*func_ptr)( interval );
}

inline int WINAPI wglGetSwapIntervalEXT(void)
{
	typedef int WINAPI (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetSwapIntervalEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetSwapIntervalEXT" ); }
	return (*func_ptr)(  );
}

inline void* WINAPI wglAllocateMemoryNV(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority)
{
	typedef void* WINAPI (*proc_type)(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglAllocateMemoryNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglAllocateMemoryNV" ); }
	return (*func_ptr)( size, readfreq, writefreq, priority );
}

inline void WINAPI wglFreeMemoryNV(void *pointer)
{
	typedef void WINAPI (*proc_type)(void *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglFreeMemoryNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglFreeMemoryNV" ); }
	return (*func_ptr)( pointer );
}

inline BOOL WINAPI wglGetSyncValuesOML(HDC hdc, INT64 *ust, INT64 *msc, INT64 *sbc)
{
	typedef BOOL WINAPI (*proc_type)(HDC hdc, INT64 *ust, INT64 *msc, INT64 *sbc);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetSyncValuesOML" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetSyncValuesOML" ); }
	return (*func_ptr)( hdc, ust, msc, sbc );
}

inline BOOL WINAPI wglGetMscRateOML(HDC hdc, INT32 *numerator, INT32 *denominator)
{
	typedef BOOL WINAPI (*proc_type)(HDC hdc, INT32 *numerator, INT32 *denominator);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetMscRateOML" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetMscRateOML" ); }
	return (*func_ptr)( hdc, numerator, denominator );
}

inline INT64 WINAPI wglSwapBuffersMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder)
{
	typedef INT64 WINAPI (*proc_type)(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglSwapBuffersMscOML" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglSwapBuffersMscOML" ); }
	return (*func_ptr)( hdc, target_msc, divisor, remainder );
}

inline INT64 WINAPI wglSwapLayerBuffersMscOML(HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder)
{
	typedef INT64 WINAPI (*proc_type)(HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglSwapLayerBuffersMscOML" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglSwapLayerBuffersMscOML" ); }
	return (*func_ptr)( hdc, fuPlanes, target_msc, divisor, remainder );
}

inline BOOL WINAPI wglWaitForMscOML(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 *ust, INT64 *msc, INT64 *sbc)
{
	typedef BOOL WINAPI (*proc_type)(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 *ust, INT64 *msc, INT64 *sbc);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglWaitForMscOML" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglWaitForMscOML" ); }
	return (*func_ptr)( hdc, target_msc, divisor, remainder, ust, msc, sbc );
}

inline BOOL WINAPI wglWaitForSbcOML(HDC hdc, INT64 target_sbc, INT64 *ust, INT64 *msc, INT64 *sbc)
{
	typedef BOOL WINAPI (*proc_type)(HDC hdc, INT64 target_sbc, INT64 *ust, INT64 *msc, INT64 *sbc);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglWaitForSbcOML" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglWaitForSbcOML" ); }
	return (*func_ptr)( hdc, target_sbc, ust, msc, sbc );
}

inline BOOL WINAPI wglGetDigitalVideoParametersI3D(HDC hDC, int iAttribute, int *piValue)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, int iAttribute, int *piValue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetDigitalVideoParametersI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetDigitalVideoParametersI3D" ); }
	return (*func_ptr)( hDC, iAttribute, piValue );
}

inline BOOL WINAPI wglSetDigitalVideoParametersI3D(HDC hDC, int iAttribute, const int *piValue)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, int iAttribute, const int *piValue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglSetDigitalVideoParametersI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglSetDigitalVideoParametersI3D" ); }
	return (*func_ptr)( hDC, iAttribute, piValue );
}

inline BOOL WINAPI wglGetGammaTableParametersI3D(HDC hDC, int iAttribute, int *piValue)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, int iAttribute, int *piValue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetGammaTableParametersI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetGammaTableParametersI3D" ); }
	return (*func_ptr)( hDC, iAttribute, piValue );
}

inline BOOL WINAPI wglSetGammaTableParametersI3D(HDC hDC, int iAttribute, const int *piValue)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, int iAttribute, const int *piValue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglSetGammaTableParametersI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglSetGammaTableParametersI3D" ); }
	return (*func_ptr)( hDC, iAttribute, piValue );
}

inline BOOL WINAPI wglGetGammaTableI3D(HDC hDC, int iEntries, USHORT *puRed, USHORT *puGreen, USHORT *puBlue)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, int iEntries, USHORT *puRed, USHORT *puGreen, USHORT *puBlue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetGammaTableI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetGammaTableI3D" ); }
	return (*func_ptr)( hDC, iEntries, puRed, puGreen, puBlue );
}

inline BOOL WINAPI wglSetGammaTableI3D(HDC hDC, int iEntries, const USHORT *puRed, const USHORT *puGreen, const USHORT *puBlue)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, int iEntries, const USHORT *puRed, const USHORT *puGreen, const USHORT *puBlue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglSetGammaTableI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglSetGammaTableI3D" ); }
	return (*func_ptr)( hDC, iEntries, puRed, puGreen, puBlue );
}

inline BOOL WINAPI wglEnableGenlockI3D(HDC hDC)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglEnableGenlockI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglEnableGenlockI3D" ); }
	return (*func_ptr)( hDC );
}

inline BOOL WINAPI wglDisableGenlockI3D(HDC hDC)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglDisableGenlockI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglDisableGenlockI3D" ); }
	return (*func_ptr)( hDC );
}

inline BOOL WINAPI wglIsEnabledGenlockI3D(HDC hDC, BOOL *pFlag)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, BOOL *pFlag);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglIsEnabledGenlockI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglIsEnabledGenlockI3D" ); }
	return (*func_ptr)( hDC, pFlag );
}

inline BOOL WINAPI wglGenlockSourceI3D(HDC hDC, UINT uSource)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, UINT uSource);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGenlockSourceI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGenlockSourceI3D" ); }
	return (*func_ptr)( hDC, uSource );
}

inline BOOL WINAPI wglGetGenlockSourceI3D(HDC hDC, UINT *uSource)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, UINT *uSource);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetGenlockSourceI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetGenlockSourceI3D" ); }
	return (*func_ptr)( hDC, uSource );
}

inline BOOL WINAPI wglGenlockSourceEdgeI3D(HDC hDC, UINT uEdge)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, UINT uEdge);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGenlockSourceEdgeI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGenlockSourceEdgeI3D" ); }
	return (*func_ptr)( hDC, uEdge );
}

inline BOOL WINAPI wglGetGenlockSourceEdgeI3D(HDC hDC, UINT *uEdge)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, UINT *uEdge);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetGenlockSourceEdgeI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetGenlockSourceEdgeI3D" ); }
	return (*func_ptr)( hDC, uEdge );
}

inline BOOL WINAPI wglGenlockSampleRateI3D(HDC hDC, UINT uRate)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, UINT uRate);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGenlockSampleRateI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGenlockSampleRateI3D" ); }
	return (*func_ptr)( hDC, uRate );
}

inline BOOL WINAPI wglGetGenlockSampleRateI3D(HDC hDC, UINT *uRate)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, UINT *uRate);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetGenlockSampleRateI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetGenlockSampleRateI3D" ); }
	return (*func_ptr)( hDC, uRate );
}

inline BOOL WINAPI wglGenlockSourceDelayI3D(HDC hDC, UINT uDelay)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, UINT uDelay);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGenlockSourceDelayI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGenlockSourceDelayI3D" ); }
	return (*func_ptr)( hDC, uDelay );
}

inline BOOL WINAPI wglGetGenlockSourceDelayI3D(HDC hDC, UINT *uDelay)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, UINT *uDelay);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetGenlockSourceDelayI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetGenlockSourceDelayI3D" ); }
	return (*func_ptr)( hDC, uDelay );
}

inline BOOL WINAPI wglQueryGenlockMaxSourceDelayI3D(HDC hDC, UINT *uMaxLineDelay, UINT *uMaxPixelDelay)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, UINT *uMaxLineDelay, UINT *uMaxPixelDelay);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglQueryGenlockMaxSourceDelayI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglQueryGenlockMaxSourceDelayI3D" ); }
	return (*func_ptr)( hDC, uMaxLineDelay, uMaxPixelDelay );
}

inline LPVOID WINAPI wglCreateImageBufferI3D(HDC hDC, DWORD dwSize, UINT uFlags)
{
	typedef LPVOID WINAPI (*proc_type)(HDC hDC, DWORD dwSize, UINT uFlags);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglCreateImageBufferI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglCreateImageBufferI3D" ); }
	return (*func_ptr)( hDC, dwSize, uFlags );
}

inline BOOL WINAPI wglDestroyImageBufferI3D(HDC hDC, LPVOID pAddress)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, LPVOID pAddress);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglDestroyImageBufferI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglDestroyImageBufferI3D" ); }
	return (*func_ptr)( hDC, pAddress );
}

inline BOOL WINAPI wglAssociateImageBufferEventsI3D(HDC hDC, const HANDLE *pEvent, const LPVOID *pAddress, const DWORD *pSize, UINT count)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, const HANDLE *pEvent, const LPVOID *pAddress, const DWORD *pSize, UINT count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglAssociateImageBufferEventsI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglAssociateImageBufferEventsI3D" ); }
	return (*func_ptr)( hDC, pEvent, pAddress, pSize, count );
}

inline BOOL WINAPI wglReleaseImageBufferEventsI3D(HDC hDC, const LPVOID *pAddress, UINT count)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, const LPVOID *pAddress, UINT count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglReleaseImageBufferEventsI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglReleaseImageBufferEventsI3D" ); }
	return (*func_ptr)( hDC, pAddress, count );
}

inline BOOL WINAPI wglEnableFrameLockI3D(void)
{
	typedef BOOL WINAPI (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglEnableFrameLockI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglEnableFrameLockI3D" ); }
	return (*func_ptr)(  );
}

inline BOOL WINAPI wglDisableFrameLockI3D(void)
{
	typedef BOOL WINAPI (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglDisableFrameLockI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglDisableFrameLockI3D" ); }
	return (*func_ptr)(  );
}

inline BOOL WINAPI wglIsEnabledFrameLockI3D(BOOL *pFlag)
{
	typedef BOOL WINAPI (*proc_type)(BOOL *pFlag);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglIsEnabledFrameLockI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglIsEnabledFrameLockI3D" ); }
	return (*func_ptr)( pFlag );
}

inline BOOL WINAPI wglQueryFrameLockMasterI3D(BOOL *pFlag)
{
	typedef BOOL WINAPI (*proc_type)(BOOL *pFlag);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglQueryFrameLockMasterI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglQueryFrameLockMasterI3D" ); }
	return (*func_ptr)( pFlag );
}

inline BOOL WINAPI wglGetFrameUsageI3D(float *pUsage)
{
	typedef BOOL WINAPI (*proc_type)(float *pUsage);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetFrameUsageI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetFrameUsageI3D" ); }
	return (*func_ptr)( pUsage );
}

inline BOOL WINAPI wglBeginFrameTrackingI3D(void)
{
	typedef BOOL WINAPI (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglBeginFrameTrackingI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglBeginFrameTrackingI3D" ); }
	return (*func_ptr)(  );
}

inline BOOL WINAPI wglEndFrameTrackingI3D(void)
{
	typedef BOOL WINAPI (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglEndFrameTrackingI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglEndFrameTrackingI3D" ); }
	return (*func_ptr)(  );
}

inline BOOL WINAPI wglQueryFrameTrackingI3D(DWORD *pFrameCount, DWORD *pMissedFrames, float *pLastMissedUsage)
{
	typedef BOOL WINAPI (*proc_type)(DWORD *pFrameCount, DWORD *pMissedFrames, float *pLastMissedUsage);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglQueryFrameTrackingI3D" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglQueryFrameTrackingI3D" ); }
	return (*func_ptr)( pFrameCount, pMissedFrames, pLastMissedUsage );
}

inline BOOL WINAPI wglSetStereoEmitterState3DL(HDC hDC, UINT uState)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, UINT uState);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglSetStereoEmitterState3DL" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglSetStereoEmitterState3DL" ); }
	return (*func_ptr)( hDC, uState );
}

inline int WINAPI wglEnumerateVideoDevicesNV(HDC hDC, HVIDEOOUTPUTDEVICENV *phDeviceList)
{
	typedef int WINAPI (*proc_type)(HDC hDC, HVIDEOOUTPUTDEVICENV *phDeviceList);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglEnumerateVideoDevicesNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglEnumerateVideoDevicesNV" ); }
	return (*func_ptr)( hDC, phDeviceList );
}

inline BOOL WINAPI wglBindVideoDeviceNV(HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int *piAttribList)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int *piAttribList);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglBindVideoDeviceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglBindVideoDeviceNV" ); }
	return (*func_ptr)( hDC, uVideoSlot, hVideoDevice, piAttribList );
}

inline BOOL WINAPI wglQueryCurrentContextNV(int iAttribute, int *piValue)
{
	typedef BOOL WINAPI (*proc_type)(int iAttribute, int *piValue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglQueryCurrentContextNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglQueryCurrentContextNV" ); }
	return (*func_ptr)( iAttribute, piValue );
}

inline BOOL WINAPI wglGetVideoDeviceNV(HDC hDC, int numDevices, HPVIDEODEV *hVideoDevice)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, int numDevices, HPVIDEODEV *hVideoDevice);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetVideoDeviceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetVideoDeviceNV" ); }
	return (*func_ptr)( hDC, numDevices, hVideoDevice );
}

inline BOOL WINAPI wglReleaseVideoDeviceNV(HPVIDEODEV hVideoDevice)
{
	typedef BOOL WINAPI (*proc_type)(HPVIDEODEV hVideoDevice);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglReleaseVideoDeviceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglReleaseVideoDeviceNV" ); }
	return (*func_ptr)( hVideoDevice );
}

inline BOOL WINAPI wglBindVideoImageNV(HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer)
{
	typedef BOOL WINAPI (*proc_type)(HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglBindVideoImageNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglBindVideoImageNV" ); }
	return (*func_ptr)( hVideoDevice, hPbuffer, iVideoBuffer );
}

inline BOOL WINAPI wglReleaseVideoImageNV(HPBUFFERARB hPbuffer, int iVideoBuffer)
{
	typedef BOOL WINAPI (*proc_type)(HPBUFFERARB hPbuffer, int iVideoBuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglReleaseVideoImageNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglReleaseVideoImageNV" ); }
	return (*func_ptr)( hPbuffer, iVideoBuffer );
}

inline BOOL WINAPI wglSendPbufferToVideoNV(HPBUFFERARB hPbuffer, int iBufferType, unsigned long *pulCounterPbuffer, BOOL bBlock)
{
	typedef BOOL WINAPI (*proc_type)(HPBUFFERARB hPbuffer, int iBufferType, unsigned long *pulCounterPbuffer, BOOL bBlock);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglSendPbufferToVideoNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglSendPbufferToVideoNV" ); }
	return (*func_ptr)( hPbuffer, iBufferType, pulCounterPbuffer, bBlock );
}

inline BOOL WINAPI wglGetVideoInfoNV(HPVIDEODEV hpVideoDevice, unsigned long *pulCounterOutputPbuffer, unsigned long *pulCounterOutputVideo)
{
	typedef BOOL WINAPI (*proc_type)(HPVIDEODEV hpVideoDevice, unsigned long *pulCounterOutputPbuffer, unsigned long *pulCounterOutputVideo);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetVideoInfoNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetVideoInfoNV" ); }
	return (*func_ptr)( hpVideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo );
}

inline BOOL WINAPI wglJoinSwapGroupNV(HDC hDC, GLuint group)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, GLuint group);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglJoinSwapGroupNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglJoinSwapGroupNV" ); }
	return (*func_ptr)( hDC, group );
}

inline BOOL WINAPI wglBindSwapBarrierNV(GLuint group, GLuint barrier)
{
	typedef BOOL WINAPI (*proc_type)(GLuint group, GLuint barrier);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglBindSwapBarrierNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglBindSwapBarrierNV" ); }
	return (*func_ptr)( group, barrier );
}

inline BOOL WINAPI wglQuerySwapGroupNV(HDC hDC, GLuint *group, GLuint *barrier)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, GLuint *group, GLuint *barrier);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglQuerySwapGroupNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglQuerySwapGroupNV" ); }
	return (*func_ptr)( hDC, group, barrier );
}

inline BOOL WINAPI wglQueryMaxSwapGroupsNV(HDC hDC, GLuint *maxGroups, GLuint *maxBarriers)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, GLuint *maxGroups, GLuint *maxBarriers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglQueryMaxSwapGroupsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglQueryMaxSwapGroupsNV" ); }
	return (*func_ptr)( hDC, maxGroups, maxBarriers );
}

inline BOOL WINAPI wglQueryFrameCountNV(HDC hDC, GLuint *count)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC, GLuint *count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglQueryFrameCountNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglQueryFrameCountNV" ); }
	return (*func_ptr)( hDC, count );
}

inline BOOL WINAPI wglResetFrameCountNV(HDC hDC)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDC);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglResetFrameCountNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglResetFrameCountNV" ); }
	return (*func_ptr)( hDC );
}

inline BOOL WINAPI wglEnumGpusNV(UINT iGpuIndex, HGPUNV *phGpu)
{
	typedef BOOL WINAPI (*proc_type)(UINT iGpuIndex, HGPUNV *phGpu);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglEnumGpusNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglEnumGpusNV" ); }
	return (*func_ptr)( iGpuIndex, phGpu );
}

inline BOOL WINAPI wglEnumGpuDevicesNV(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice)
{
	typedef BOOL WINAPI (*proc_type)(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglEnumGpuDevicesNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglEnumGpuDevicesNV" ); }
	return (*func_ptr)( hGpu, iDeviceIndex, lpGpuDevice );
}

inline HDC WINAPI wglCreateAffinityDCNV(const HGPUNV *phGpuList)
{
	typedef HDC WINAPI (*proc_type)(const HGPUNV *phGpuList);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglCreateAffinityDCNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglCreateAffinityDCNV" ); }
	return (*func_ptr)( phGpuList );
}

inline BOOL WINAPI wglEnumGpusFromAffinityDCNV(HDC hAffinityDC, UINT iGpuIndex, HGPUNV *hGpu)
{
	typedef BOOL WINAPI (*proc_type)(HDC hAffinityDC, UINT iGpuIndex, HGPUNV *hGpu);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglEnumGpusFromAffinityDCNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglEnumGpusFromAffinityDCNV" ); }
	return (*func_ptr)( hAffinityDC, iGpuIndex, hGpu );
}

inline BOOL WINAPI wglDeleteDCNV(HDC hdc)
{
	typedef BOOL WINAPI (*proc_type)(HDC hdc);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglDeleteDCNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglDeleteDCNV" ); }
	return (*func_ptr)( hdc );
}

inline UINT WINAPI wglGetGPUIDsAMD(UINT maxCount, UINT *ids)
{
	typedef UINT WINAPI (*proc_type)(UINT maxCount, UINT *ids);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetGPUIDsAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetGPUIDsAMD" ); }
	return (*func_ptr)( maxCount, ids );
}

inline INT WINAPI wglGetGPUInfoAMD(UINT id, int property, GLenum dataType, UINT size, void *data)
{
	typedef INT WINAPI (*proc_type)(UINT id, int property, GLenum dataType, UINT size, void *data);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetGPUInfoAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetGPUInfoAMD" ); }
	return (*func_ptr)( id, property, dataType, size, data );
}

inline UINT WINAPI wglGetContextGPUIDAMD(HGLRC hglrc)
{
	typedef UINT WINAPI (*proc_type)(HGLRC hglrc);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetContextGPUIDAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetContextGPUIDAMD" ); }
	return (*func_ptr)( hglrc );
}

inline HGLRC WINAPI wglCreateAssociatedContextAMD(UINT id)
{
	typedef HGLRC WINAPI (*proc_type)(UINT id);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglCreateAssociatedContextAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglCreateAssociatedContextAMD" ); }
	return (*func_ptr)( id );
}

inline HGLRC WINAPI wglCreateAssociatedContextAttribsAMD(UINT id, HGLRC hShareContext, const int *attribList)
{
	typedef HGLRC WINAPI (*proc_type)(UINT id, HGLRC hShareContext, const int *attribList);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglCreateAssociatedContextAttribsAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglCreateAssociatedContextAttribsAMD" ); }
	return (*func_ptr)( id, hShareContext, attribList );
}

inline BOOL WINAPI wglDeleteAssociatedContextAMD(HGLRC hglrc)
{
	typedef BOOL WINAPI (*proc_type)(HGLRC hglrc);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglDeleteAssociatedContextAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglDeleteAssociatedContextAMD" ); }
	return (*func_ptr)( hglrc );
}

inline BOOL WINAPI wglMakeAssociatedContextCurrentAMD(HGLRC hglrc)
{
	typedef BOOL WINAPI (*proc_type)(HGLRC hglrc);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglMakeAssociatedContextCurrentAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglMakeAssociatedContextCurrentAMD" ); }
	return (*func_ptr)( hglrc );
}

inline HGLRC WINAPI wglGetCurrentAssociatedContextAMD(void)
{
	typedef HGLRC WINAPI (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglGetCurrentAssociatedContextAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglGetCurrentAssociatedContextAMD" ); }
	return (*func_ptr)(  );
}

inline VOID WINAPI wglBlitContextFramebufferAMD(HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
{
	typedef VOID WINAPI (*proc_type)(HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglBlitContextFramebufferAMD" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglBlitContextFramebufferAMD" ); }
	return (*func_ptr)( dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter );
}

inline BOOL WINAPI wglBindVideoCaptureDeviceNV(UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice)
{
	typedef BOOL WINAPI (*proc_type)(UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglBindVideoCaptureDeviceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglBindVideoCaptureDeviceNV" ); }
	return (*func_ptr)( uVideoSlot, hDevice );
}

inline UINT WINAPI wglEnumerateVideoCaptureDevicesNV(HDC hDc, HVIDEOINPUTDEVICENV *phDeviceList)
{
	typedef UINT WINAPI (*proc_type)(HDC hDc, HVIDEOINPUTDEVICENV *phDeviceList);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglEnumerateVideoCaptureDevicesNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglEnumerateVideoCaptureDevicesNV" ); }
	return (*func_ptr)( hDc, phDeviceList );
}

inline BOOL WINAPI wglLockVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDc, HVIDEOINPUTDEVICENV hDevice);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglLockVideoCaptureDeviceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglLockVideoCaptureDeviceNV" ); }
	return (*func_ptr)( hDc, hDevice );
}

inline BOOL WINAPI wglQueryVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int *piValue)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int *piValue);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglQueryVideoCaptureDeviceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglQueryVideoCaptureDeviceNV" ); }
	return (*func_ptr)( hDc, hDevice, iAttribute, piValue );
}

inline BOOL WINAPI wglReleaseVideoCaptureDeviceNV(HDC hDc, HVIDEOINPUTDEVICENV hDevice)
{
	typedef BOOL WINAPI (*proc_type)(HDC hDc, HVIDEOINPUTDEVICENV hDevice);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglReleaseVideoCaptureDeviceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglReleaseVideoCaptureDeviceNV" ); }
	return (*func_ptr)( hDc, hDevice );
}

inline BOOL WINAPI wglCopyImageSubDataNV(HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth)
{
	typedef BOOL WINAPI (*proc_type)(HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglCopyImageSubDataNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglCopyImageSubDataNV" ); }
	return (*func_ptr)( hSrcRC, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, hDstRC, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth );
}

inline BOOL WINAPI wglDXSetResourceShareHandleNV(void *dxObject, HANDLE shareHandle)
{
	typedef BOOL WINAPI (*proc_type)(void *dxObject, HANDLE shareHandle);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglDXSetResourceShareHandleNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglDXSetResourceShareHandleNV" ); }
	return (*func_ptr)( dxObject, shareHandle );
}

inline HANDLE WINAPI wglDXOpenDeviceNV(void *dxDevice)
{
	typedef HANDLE WINAPI (*proc_type)(void *dxDevice);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglDXOpenDeviceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglDXOpenDeviceNV" ); }
	return (*func_ptr)( dxDevice );
}

inline BOOL WINAPI wglDXCloseDeviceNV(HANDLE hDevice)
{
	typedef BOOL WINAPI (*proc_type)(HANDLE hDevice);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglDXCloseDeviceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglDXCloseDeviceNV" ); }
	return (*func_ptr)( hDevice );
}

inline HANDLE WINAPI wglDXRegisterObjectNV(HANDLE hDevice, void *dxObject, GLuint name, GLenum type, GLenum access)
{
	typedef HANDLE WINAPI (*proc_type)(HANDLE hDevice, void *dxObject, GLuint name, GLenum type, GLenum access);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglDXRegisterObjectNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglDXRegisterObjectNV" ); }
	return (*func_ptr)( hDevice, dxObject, name, type, access );
}

inline BOOL WINAPI wglDXUnregisterObjectNV(HANDLE hDevice, HANDLE hObject)
{
	typedef BOOL WINAPI (*proc_type)(HANDLE hDevice, HANDLE hObject);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglDXUnregisterObjectNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglDXUnregisterObjectNV" ); }
	return (*func_ptr)( hDevice, hObject );
}

inline BOOL WINAPI wglDXObjectAccessNV(HANDLE hObject, GLenum access)
{
	typedef BOOL WINAPI (*proc_type)(HANDLE hObject, GLenum access);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglDXObjectAccessNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglDXObjectAccessNV" ); }
	return (*func_ptr)( hObject, access );
}

inline BOOL WINAPI wglDXLockObjectsNV(HANDLE hDevice, GLint count, HANDLE *hObjects)
{
	typedef BOOL WINAPI (*proc_type)(HANDLE hDevice, GLint count, HANDLE *hObjects);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglDXLockObjectsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglDXLockObjectsNV" ); }
	return (*func_ptr)( hDevice, count, hObjects );
}

inline BOOL WINAPI wglDXUnlockObjectsNV(HANDLE hDevice, GLint count, HANDLE *hObjects)
{
	typedef BOOL WINAPI (*proc_type)(HANDLE hDevice, GLint count, HANDLE *hObjects);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "wglDXUnlockObjectsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : wglDXUnlockObjectsNV" ); }
	return (*func_ptr)( hDevice, count, hObjects );
}


#endif // GLEWLLE_WGL_HPP_
