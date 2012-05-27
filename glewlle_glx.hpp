// glewlle_glx
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

#ifndef GLEWLLE_GLX_HPP_
#define GLEWLLE_GLX_HPP_

#include <glewlle.hpp>

#include <glxext.h>

inline GLXFBConfig * glXGetFBConfigs(Display *dpy, int screen, int *nelements)
{
	typedef GLXFBConfig * (*proc_type)(Display *dpy, int screen, int *nelements);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetFBConfigs" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetFBConfigs" ); }
	return (*func_ptr)( dpy, screen, nelements );
}

inline GLXFBConfig * glXChooseFBConfig(Display *dpy, int screen, const int *attrib_list, int *nelements)
{
	typedef GLXFBConfig * (*proc_type)(Display *dpy, int screen, const int *attrib_list, int *nelements);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXChooseFBConfig" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXChooseFBConfig" ); }
	return (*func_ptr)( dpy, screen, attrib_list, nelements );
}

inline int glXGetFBConfigAttrib(Display *dpy, GLXFBConfig config, int attribute, int *value)
{
	typedef int (*proc_type)(Display *dpy, GLXFBConfig config, int attribute, int *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetFBConfigAttrib" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetFBConfigAttrib" ); }
	return (*func_ptr)( dpy, config, attribute, value );
}

inline XVisualInfo * glXGetVisualFromFBConfig(Display *dpy, GLXFBConfig config)
{
	typedef XVisualInfo * (*proc_type)(Display *dpy, GLXFBConfig config);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetVisualFromFBConfig" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetVisualFromFBConfig" ); }
	return (*func_ptr)( dpy, config );
}

inline GLXWindow glXCreateWindow(Display *dpy, GLXFBConfig config, Window win, const int *attrib_list)
{
	typedef GLXWindow (*proc_type)(Display *dpy, GLXFBConfig config, Window win, const int *attrib_list);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXCreateWindow" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXCreateWindow" ); }
	return (*func_ptr)( dpy, config, win, attrib_list );
}

inline void glXDestroyWindow(Display *dpy, GLXWindow win)
{
	typedef void (*proc_type)(Display *dpy, GLXWindow win);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXDestroyWindow" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXDestroyWindow" ); }
	(*func_ptr)( dpy, win );
}

inline GLXPixmap glXCreatePixmap(Display *dpy, GLXFBConfig config, Pixmap pixmap, const int *attrib_list)
{
	typedef GLXPixmap (*proc_type)(Display *dpy, GLXFBConfig config, Pixmap pixmap, const int *attrib_list);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXCreatePixmap" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXCreatePixmap" ); }
	return (*func_ptr)( dpy, config, pixmap, attrib_list );
}

inline void glXDestroyPixmap(Display *dpy, GLXPixmap pixmap)
{
	typedef void (*proc_type)(Display *dpy, GLXPixmap pixmap);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXDestroyPixmap" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXDestroyPixmap" ); }
	(*func_ptr)( dpy, pixmap );
}

inline GLXPbuffer glXCreatePbuffer(Display *dpy, GLXFBConfig config, const int *attrib_list)
{
	typedef GLXPbuffer (*proc_type)(Display *dpy, GLXFBConfig config, const int *attrib_list);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXCreatePbuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXCreatePbuffer" ); }
	return (*func_ptr)( dpy, config, attrib_list );
}

inline void glXDestroyPbuffer(Display *dpy, GLXPbuffer pbuf)
{
	typedef void (*proc_type)(Display *dpy, GLXPbuffer pbuf);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXDestroyPbuffer" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXDestroyPbuffer" ); }
	(*func_ptr)( dpy, pbuf );
}

inline void glXQueryDrawable(Display *dpy, GLXDrawable draw, int attribute, unsigned int *value)
{
	typedef void (*proc_type)(Display *dpy, GLXDrawable draw, int attribute, unsigned int *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXQueryDrawable" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXQueryDrawable" ); }
	(*func_ptr)( dpy, draw, attribute, value );
}

inline GLXContext glXCreateNewContext(Display *dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct)
{
	typedef GLXContext (*proc_type)(Display *dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXCreateNewContext" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXCreateNewContext" ); }
	return (*func_ptr)( dpy, config, render_type, share_list, direct );
}

inline Bool glXMakeContextCurrent(Display *dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx)
{
	typedef Bool (*proc_type)(Display *dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXMakeContextCurrent" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXMakeContextCurrent" ); }
	return (*func_ptr)( dpy, draw, read, ctx );
}

inline GLXDrawable glXGetCurrentReadDrawable(void)
{
	typedef GLXDrawable (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetCurrentReadDrawable" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetCurrentReadDrawable" ); }
	return (*func_ptr)(  );
}

inline Display * glXGetCurrentDisplay(void)
{
	typedef Display * (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetCurrentDisplay" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetCurrentDisplay" ); }
	return (*func_ptr)(  );
}

inline int glXQueryContext(Display *dpy, GLXContext ctx, int attribute, int *value)
{
	typedef int (*proc_type)(Display *dpy, GLXContext ctx, int attribute, int *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXQueryContext" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXQueryContext" ); }
	return (*func_ptr)( dpy, ctx, attribute, value );
}

inline void glXSelectEvent(Display *dpy, GLXDrawable draw, unsigned long event_mask)
{
	typedef void (*proc_type)(Display *dpy, GLXDrawable draw, unsigned long event_mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXSelectEvent" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXSelectEvent" ); }
	(*func_ptr)( dpy, draw, event_mask );
}

inline void glXGetSelectedEvent(Display *dpy, GLXDrawable draw, unsigned long *event_mask)
{
	typedef void (*proc_type)(Display *dpy, GLXDrawable draw, unsigned long *event_mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetSelectedEvent" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetSelectedEvent" ); }
	(*func_ptr)( dpy, draw, event_mask );
}

inline __GLXextFuncPtr glXGetProcAddress(const GLubyte *procName)
{
	typedef __GLXextFuncPtr (*proc_type)(const GLubyte *procName);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetProcAddress" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetProcAddress" ); }
	return (*func_ptr)( procName );
}

inline __GLXextFuncPtr glXGetProcAddressARB(const GLubyte *procName)
{
	typedef __GLXextFuncPtr (*proc_type)(const GLubyte *procName);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetProcAddressARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetProcAddressARB" ); }
	return (*func_ptr)( procName );
}

inline GLXContext glXCreateContextAttribsARB(Display *dpy, GLXFBConfig config, GLXContext share_context, Bool direct, const int *attrib_list)
{
	typedef GLXContext (*proc_type)(Display *dpy, GLXFBConfig config, GLXContext share_context, Bool direct, const int *attrib_list);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXCreateContextAttribsARB" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXCreateContextAttribsARB" ); }
	return (*func_ptr)( dpy, config, share_context, direct, attrib_list );
}

inline int glXSwapIntervalSGI(int interval)
{
	typedef int (*proc_type)(int interval);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXSwapIntervalSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXSwapIntervalSGI" ); }
	return (*func_ptr)( interval );
}

inline int glXGetVideoSyncSGI(unsigned int *count)
{
	typedef int (*proc_type)(unsigned int *count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetVideoSyncSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetVideoSyncSGI" ); }
	return (*func_ptr)( count );
}

inline int glXWaitVideoSyncSGI(int divisor, int remainder, unsigned int *count)
{
	typedef int (*proc_type)(int divisor, int remainder, unsigned int *count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXWaitVideoSyncSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXWaitVideoSyncSGI" ); }
	return (*func_ptr)( divisor, remainder, count );
}

inline Bool glXMakeCurrentReadSGI(Display *dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx)
{
	typedef Bool (*proc_type)(Display *dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXMakeCurrentReadSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXMakeCurrentReadSGI" ); }
	return (*func_ptr)( dpy, draw, read, ctx );
}

inline GLXDrawable glXGetCurrentReadDrawableSGI(void)
{
	typedef GLXDrawable (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetCurrentReadDrawableSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetCurrentReadDrawableSGI" ); }
	return (*func_ptr)(  );
}

#ifdef _VL_H
inline GLXVideoSourceSGIX glXCreateGLXVideoSourceSGIX(Display *display, int screen, VLServer server, VLPath path, int nodeClass, VLNode drainNode)
{
	typedef GLXVideoSourceSGIX (*proc_type)(Display *display, int screen, VLServer server, VLPath path, int nodeClass, VLNode drainNode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXCreateGLXVideoSourceSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXCreateGLXVideoSourceSGIX" ); }
	return (*func_ptr)( display, screen, server, path, nodeClass, drainNode );
}

inline void glXDestroyGLXVideoSourceSGIX(Display *dpy, GLXVideoSourceSGIX glxvideosource)
{
	typedef void (*proc_type)(Display *dpy, GLXVideoSourceSGIX glxvideosource);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXDestroyGLXVideoSourceSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXDestroyGLXVideoSourceSGIX" ); }
	(*func_ptr)( dpy, glxvideosource );
}

#endif /* _VL_H */
inline Display * glXGetCurrentDisplayEXT(void)
{
	typedef Display * (*proc_type)(void);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetCurrentDisplayEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetCurrentDisplayEXT" ); }
	return (*func_ptr)(  );
}

inline int glXQueryContextInfoEXT(Display *dpy, GLXContext context, int attribute, int *value)
{
	typedef int (*proc_type)(Display *dpy, GLXContext context, int attribute, int *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXQueryContextInfoEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXQueryContextInfoEXT" ); }
	return (*func_ptr)( dpy, context, attribute, value );
}

inline GLXContextID glXGetContextIDEXT(const GLXContext context)
{
	typedef GLXContextID (*proc_type)(const GLXContext context);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetContextIDEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetContextIDEXT" ); }
	return (*func_ptr)( context );
}

inline GLXContext glXImportContextEXT(Display *dpy, GLXContextID contextID)
{
	typedef GLXContext (*proc_type)(Display *dpy, GLXContextID contextID);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXImportContextEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXImportContextEXT" ); }
	return (*func_ptr)( dpy, contextID );
}

inline void glXFreeContextEXT(Display *dpy, GLXContext context)
{
	typedef void (*proc_type)(Display *dpy, GLXContext context);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXFreeContextEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXFreeContextEXT" ); }
	(*func_ptr)( dpy, context );
}

inline int glXGetFBConfigAttribSGIX(Display *dpy, GLXFBConfigSGIX config, int attribute, int *value)
{
	typedef int (*proc_type)(Display *dpy, GLXFBConfigSGIX config, int attribute, int *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetFBConfigAttribSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetFBConfigAttribSGIX" ); }
	return (*func_ptr)( dpy, config, attribute, value );
}

inline GLXFBConfigSGIX * glXChooseFBConfigSGIX(Display *dpy, int screen, int *attrib_list, int *nelements)
{
	typedef GLXFBConfigSGIX * (*proc_type)(Display *dpy, int screen, int *attrib_list, int *nelements);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXChooseFBConfigSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXChooseFBConfigSGIX" ); }
	return (*func_ptr)( dpy, screen, attrib_list, nelements );
}

inline GLXPixmap glXCreateGLXPixmapWithConfigSGIX(Display *dpy, GLXFBConfigSGIX config, Pixmap pixmap)
{
	typedef GLXPixmap (*proc_type)(Display *dpy, GLXFBConfigSGIX config, Pixmap pixmap);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXCreateGLXPixmapWithConfigSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXCreateGLXPixmapWithConfigSGIX" ); }
	return (*func_ptr)( dpy, config, pixmap );
}

inline GLXContext glXCreateContextWithConfigSGIX(Display *dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct)
{
	typedef GLXContext (*proc_type)(Display *dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXCreateContextWithConfigSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXCreateContextWithConfigSGIX" ); }
	return (*func_ptr)( dpy, config, render_type, share_list, direct );
}

inline XVisualInfo * glXGetVisualFromFBConfigSGIX(Display *dpy, GLXFBConfigSGIX config)
{
	typedef XVisualInfo * (*proc_type)(Display *dpy, GLXFBConfigSGIX config);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetVisualFromFBConfigSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetVisualFromFBConfigSGIX" ); }
	return (*func_ptr)( dpy, config );
}

inline GLXFBConfigSGIX glXGetFBConfigFromVisualSGIX(Display *dpy, XVisualInfo *vis)
{
	typedef GLXFBConfigSGIX (*proc_type)(Display *dpy, XVisualInfo *vis);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetFBConfigFromVisualSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetFBConfigFromVisualSGIX" ); }
	return (*func_ptr)( dpy, vis );
}

inline GLXPbufferSGIX glXCreateGLXPbufferSGIX(Display *dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int *attrib_list)
{
	typedef GLXPbufferSGIX (*proc_type)(Display *dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int *attrib_list);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXCreateGLXPbufferSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXCreateGLXPbufferSGIX" ); }
	return (*func_ptr)( dpy, config, width, height, attrib_list );
}

inline void glXDestroyGLXPbufferSGIX(Display *dpy, GLXPbufferSGIX pbuf)
{
	typedef void (*proc_type)(Display *dpy, GLXPbufferSGIX pbuf);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXDestroyGLXPbufferSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXDestroyGLXPbufferSGIX" ); }
	(*func_ptr)( dpy, pbuf );
}

inline int glXQueryGLXPbufferSGIX(Display *dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int *value)
{
	typedef int (*proc_type)(Display *dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXQueryGLXPbufferSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXQueryGLXPbufferSGIX" ); }
	return (*func_ptr)( dpy, pbuf, attribute, value );
}

inline void glXSelectEventSGIX(Display *dpy, GLXDrawable drawable, unsigned long mask)
{
	typedef void (*proc_type)(Display *dpy, GLXDrawable drawable, unsigned long mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXSelectEventSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXSelectEventSGIX" ); }
	(*func_ptr)( dpy, drawable, mask );
}

inline void glXGetSelectedEventSGIX(Display *dpy, GLXDrawable drawable, unsigned long *mask)
{
	typedef void (*proc_type)(Display *dpy, GLXDrawable drawable, unsigned long *mask);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetSelectedEventSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetSelectedEventSGIX" ); }
	(*func_ptr)( dpy, drawable, mask );
}

inline void glXCushionSGI(Display *dpy, Window window, float cushion)
{
	typedef void (*proc_type)(Display *dpy, Window window, float cushion);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXCushionSGI" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXCushionSGI" ); }
	(*func_ptr)( dpy, window, cushion );
}

inline int glXBindChannelToWindowSGIX(Display *display, int screen, int channel, Window window)
{
	typedef int (*proc_type)(Display *display, int screen, int channel, Window window);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXBindChannelToWindowSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXBindChannelToWindowSGIX" ); }
	return (*func_ptr)( display, screen, channel, window );
}

inline int glXChannelRectSGIX(Display *display, int screen, int channel, int x, int y, int w, int h)
{
	typedef int (*proc_type)(Display *display, int screen, int channel, int x, int y, int w, int h);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXChannelRectSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXChannelRectSGIX" ); }
	return (*func_ptr)( display, screen, channel, x, y, w, h );
}

inline int glXQueryChannelRectSGIX(Display *display, int screen, int channel, int *dx, int *dy, int *dw, int *dh)
{
	typedef int (*proc_type)(Display *display, int screen, int channel, int *dx, int *dy, int *dw, int *dh);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXQueryChannelRectSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXQueryChannelRectSGIX" ); }
	return (*func_ptr)( display, screen, channel, dx, dy, dw, dh );
}

inline int glXQueryChannelDeltasSGIX(Display *display, int screen, int channel, int *x, int *y, int *w, int *h)
{
	typedef int (*proc_type)(Display *display, int screen, int channel, int *x, int *y, int *w, int *h);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXQueryChannelDeltasSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXQueryChannelDeltasSGIX" ); }
	return (*func_ptr)( display, screen, channel, x, y, w, h );
}

inline int glXChannelRectSyncSGIX(Display *display, int screen, int channel, GLenum synctype)
{
	typedef int (*proc_type)(Display *display, int screen, int channel, GLenum synctype);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXChannelRectSyncSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXChannelRectSyncSGIX" ); }
	return (*func_ptr)( display, screen, channel, synctype );
}

#ifdef _DM_BUFFER_H_
inline Bool glXAssociateDMPbufferSGIX(Display *dpy, GLXPbufferSGIX pbuffer, DMparams *params, DMbuffer dmbuffer)
{
	typedef Bool (*proc_type)(Display *dpy, GLXPbufferSGIX pbuffer, DMparams *params, DMbuffer dmbuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXAssociateDMPbufferSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXAssociateDMPbufferSGIX" ); }
	return (*func_ptr)( dpy, pbuffer, params, dmbuffer );
}

#endif /* _DM_BUFFER_H_ */
inline void glXJoinSwapGroupSGIX(Display *dpy, GLXDrawable drawable, GLXDrawable member)
{
	typedef void (*proc_type)(Display *dpy, GLXDrawable drawable, GLXDrawable member);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXJoinSwapGroupSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXJoinSwapGroupSGIX" ); }
	(*func_ptr)( dpy, drawable, member );
}

inline void glXBindSwapBarrierSGIX(Display *dpy, GLXDrawable drawable, int barrier)
{
	typedef void (*proc_type)(Display *dpy, GLXDrawable drawable, int barrier);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXBindSwapBarrierSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXBindSwapBarrierSGIX" ); }
	(*func_ptr)( dpy, drawable, barrier );
}

inline Bool glXQueryMaxSwapBarriersSGIX(Display *dpy, int screen, int *max)
{
	typedef Bool (*proc_type)(Display *dpy, int screen, int *max);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXQueryMaxSwapBarriersSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXQueryMaxSwapBarriersSGIX" ); }
	return (*func_ptr)( dpy, screen, max );
}

inline Status glXGetTransparentIndexSUN(Display *dpy, Window overlay, Window underlay, long *pTransparentIndex)
{
	typedef Status (*proc_type)(Display *dpy, Window overlay, Window underlay, long *pTransparentIndex);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetTransparentIndexSUN" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetTransparentIndexSUN" ); }
	return (*func_ptr)( dpy, overlay, underlay, pTransparentIndex );
}

inline void glXCopySubBufferMESA(Display *dpy, GLXDrawable drawable, int x, int y, int width, int height)
{
	typedef void (*proc_type)(Display *dpy, GLXDrawable drawable, int x, int y, int width, int height);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXCopySubBufferMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXCopySubBufferMESA" ); }
	(*func_ptr)( dpy, drawable, x, y, width, height );
}

inline GLXPixmap glXCreateGLXPixmapMESA(Display *dpy, XVisualInfo *visual, Pixmap pixmap, Colormap cmap)
{
	typedef GLXPixmap (*proc_type)(Display *dpy, XVisualInfo *visual, Pixmap pixmap, Colormap cmap);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXCreateGLXPixmapMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXCreateGLXPixmapMESA" ); }
	return (*func_ptr)( dpy, visual, pixmap, cmap );
}

inline Bool glXReleaseBuffersMESA(Display *dpy, GLXDrawable drawable)
{
	typedef Bool (*proc_type)(Display *dpy, GLXDrawable drawable);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXReleaseBuffersMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXReleaseBuffersMESA" ); }
	return (*func_ptr)( dpy, drawable );
}

inline Bool glXSet3DfxModeMESA(int mode)
{
	typedef Bool (*proc_type)(int mode);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXSet3DfxModeMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXSet3DfxModeMESA" ); }
	return (*func_ptr)( mode );
}

inline Bool glXGetSyncValuesOML(Display *dpy, GLXDrawable drawable, int64_t *ust, int64_t *msc, int64_t *sbc)
{
	typedef Bool (*proc_type)(Display *dpy, GLXDrawable drawable, int64_t *ust, int64_t *msc, int64_t *sbc);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetSyncValuesOML" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetSyncValuesOML" ); }
	return (*func_ptr)( dpy, drawable, ust, msc, sbc );
}

inline Bool glXGetMscRateOML(Display *dpy, GLXDrawable drawable, int32_t *numerator, int32_t *denominator)
{
	typedef Bool (*proc_type)(Display *dpy, GLXDrawable drawable, int32_t *numerator, int32_t *denominator);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetMscRateOML" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetMscRateOML" ); }
	return (*func_ptr)( dpy, drawable, numerator, denominator );
}

inline int64_t glXSwapBuffersMscOML(Display *dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder)
{
	typedef int64_t (*proc_type)(Display *dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXSwapBuffersMscOML" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXSwapBuffersMscOML" ); }
	return (*func_ptr)( dpy, drawable, target_msc, divisor, remainder );
}

inline Bool glXWaitForMscOML(Display *dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t *ust, int64_t *msc, int64_t *sbc)
{
	typedef Bool (*proc_type)(Display *dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t *ust, int64_t *msc, int64_t *sbc);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXWaitForMscOML" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXWaitForMscOML" ); }
	return (*func_ptr)( dpy, drawable, target_msc, divisor, remainder, ust, msc, sbc );
}

inline Bool glXWaitForSbcOML(Display *dpy, GLXDrawable drawable, int64_t target_sbc, int64_t *ust, int64_t *msc, int64_t *sbc)
{
	typedef Bool (*proc_type)(Display *dpy, GLXDrawable drawable, int64_t target_sbc, int64_t *ust, int64_t *msc, int64_t *sbc);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXWaitForSbcOML" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXWaitForSbcOML" ); }
	return (*func_ptr)( dpy, drawable, target_sbc, ust, msc, sbc );
}

inline GLXHyperpipeNetworkSGIX * glXQueryHyperpipeNetworkSGIX(Display *dpy, int *npipes)
{
	typedef GLXHyperpipeNetworkSGIX * (*proc_type)(Display *dpy, int *npipes);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXQueryHyperpipeNetworkSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXQueryHyperpipeNetworkSGIX" ); }
	return (*func_ptr)( dpy, npipes );
}

inline int glXHyperpipeConfigSGIX(Display *dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX *cfg, int *hpId)
{
	typedef int (*proc_type)(Display *dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX *cfg, int *hpId);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXHyperpipeConfigSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXHyperpipeConfigSGIX" ); }
	return (*func_ptr)( dpy, networkId, npipes, cfg, hpId );
}

inline GLXHyperpipeConfigSGIX * glXQueryHyperpipeConfigSGIX(Display *dpy, int hpId, int *npipes)
{
	typedef GLXHyperpipeConfigSGIX * (*proc_type)(Display *dpy, int hpId, int *npipes);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXQueryHyperpipeConfigSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXQueryHyperpipeConfigSGIX" ); }
	return (*func_ptr)( dpy, hpId, npipes );
}

inline int glXDestroyHyperpipeConfigSGIX(Display *dpy, int hpId)
{
	typedef int (*proc_type)(Display *dpy, int hpId);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXDestroyHyperpipeConfigSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXDestroyHyperpipeConfigSGIX" ); }
	return (*func_ptr)( dpy, hpId );
}

inline int glXBindHyperpipeSGIX(Display *dpy, int hpId)
{
	typedef int (*proc_type)(Display *dpy, int hpId);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXBindHyperpipeSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXBindHyperpipeSGIX" ); }
	return (*func_ptr)( dpy, hpId );
}

inline int glXQueryHyperpipeBestAttribSGIX(Display *dpy, int timeSlice, int attrib, int size, void *attribList, void *returnAttribList)
{
	typedef int (*proc_type)(Display *dpy, int timeSlice, int attrib, int size, void *attribList, void *returnAttribList);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXQueryHyperpipeBestAttribSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXQueryHyperpipeBestAttribSGIX" ); }
	return (*func_ptr)( dpy, timeSlice, attrib, size, attribList, returnAttribList );
}

inline int glXHyperpipeAttribSGIX(Display *dpy, int timeSlice, int attrib, int size, void *attribList)
{
	typedef int (*proc_type)(Display *dpy, int timeSlice, int attrib, int size, void *attribList);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXHyperpipeAttribSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXHyperpipeAttribSGIX" ); }
	return (*func_ptr)( dpy, timeSlice, attrib, size, attribList );
}

inline int glXQueryHyperpipeAttribSGIX(Display *dpy, int timeSlice, int attrib, int size, void *returnAttribList)
{
	typedef int (*proc_type)(Display *dpy, int timeSlice, int attrib, int size, void *returnAttribList);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXQueryHyperpipeAttribSGIX" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXQueryHyperpipeAttribSGIX" ); }
	return (*func_ptr)( dpy, timeSlice, attrib, size, returnAttribList );
}

inline unsigned int glXGetAGPOffsetMESA(const void *pointer)
{
	typedef unsigned int (*proc_type)(const void *pointer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetAGPOffsetMESA" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetAGPOffsetMESA" ); }
	return (*func_ptr)( pointer );
}

inline void glXBindTexImageEXT(Display *dpy, GLXDrawable drawable, int buffer, const int *attrib_list)
{
	typedef void (*proc_type)(Display *dpy, GLXDrawable drawable, int buffer, const int *attrib_list);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXBindTexImageEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXBindTexImageEXT" ); }
	(*func_ptr)( dpy, drawable, buffer, attrib_list );
}

inline void glXReleaseTexImageEXT(Display *dpy, GLXDrawable drawable, int buffer)
{
	typedef void (*proc_type)(Display *dpy, GLXDrawable drawable, int buffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXReleaseTexImageEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXReleaseTexImageEXT" ); }
	(*func_ptr)( dpy, drawable, buffer );
}

inline unsigned int * glXEnumerateVideoDevicesNV(Display *dpy, int screen, int *nelements)
{
	typedef unsigned int * (*proc_type)(Display *dpy, int screen, int *nelements);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXEnumerateVideoDevicesNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXEnumerateVideoDevicesNV" ); }
	return (*func_ptr)( dpy, screen, nelements );
}

inline int glXBindVideoDeviceNV(Display *dpy, unsigned int video_slot, unsigned int video_device, const int *attrib_list)
{
	typedef int (*proc_type)(Display *dpy, unsigned int video_slot, unsigned int video_device, const int *attrib_list);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXBindVideoDeviceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXBindVideoDeviceNV" ); }
	return (*func_ptr)( dpy, video_slot, video_device, attrib_list );
}

inline int glXGetVideoDeviceNV(Display *dpy, int screen, int numVideoDevices, GLXVideoDeviceNV *pVideoDevice)
{
	typedef int (*proc_type)(Display *dpy, int screen, int numVideoDevices, GLXVideoDeviceNV *pVideoDevice);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetVideoDeviceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetVideoDeviceNV" ); }
	return (*func_ptr)( dpy, screen, numVideoDevices, pVideoDevice );
}

inline int glXReleaseVideoDeviceNV(Display *dpy, int screen, GLXVideoDeviceNV VideoDevice)
{
	typedef int (*proc_type)(Display *dpy, int screen, GLXVideoDeviceNV VideoDevice);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXReleaseVideoDeviceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXReleaseVideoDeviceNV" ); }
	return (*func_ptr)( dpy, screen, VideoDevice );
}

inline int glXBindVideoImageNV(Display *dpy, GLXVideoDeviceNV VideoDevice, GLXPbuffer pbuf, int iVideoBuffer)
{
	typedef int (*proc_type)(Display *dpy, GLXVideoDeviceNV VideoDevice, GLXPbuffer pbuf, int iVideoBuffer);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXBindVideoImageNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXBindVideoImageNV" ); }
	return (*func_ptr)( dpy, VideoDevice, pbuf, iVideoBuffer );
}

inline int glXReleaseVideoImageNV(Display *dpy, GLXPbuffer pbuf)
{
	typedef int (*proc_type)(Display *dpy, GLXPbuffer pbuf);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXReleaseVideoImageNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXReleaseVideoImageNV" ); }
	return (*func_ptr)( dpy, pbuf );
}

inline int glXSendPbufferToVideoNV(Display *dpy, GLXPbuffer pbuf, int iBufferType, unsigned long *pulCounterPbuffer, GLboolean bBlock)
{
	typedef int (*proc_type)(Display *dpy, GLXPbuffer pbuf, int iBufferType, unsigned long *pulCounterPbuffer, GLboolean bBlock);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXSendPbufferToVideoNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXSendPbufferToVideoNV" ); }
	return (*func_ptr)( dpy, pbuf, iBufferType, pulCounterPbuffer, bBlock );
}

inline int glXGetVideoInfoNV(Display *dpy, int screen, GLXVideoDeviceNV VideoDevice, unsigned long *pulCounterOutputPbuffer, unsigned long *pulCounterOutputVideo)
{
	typedef int (*proc_type)(Display *dpy, int screen, GLXVideoDeviceNV VideoDevice, unsigned long *pulCounterOutputPbuffer, unsigned long *pulCounterOutputVideo);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXGetVideoInfoNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXGetVideoInfoNV" ); }
	return (*func_ptr)( dpy, screen, VideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo );
}

inline Bool glXJoinSwapGroupNV(Display *dpy, GLXDrawable drawable, GLuint group)
{
	typedef Bool (*proc_type)(Display *dpy, GLXDrawable drawable, GLuint group);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXJoinSwapGroupNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXJoinSwapGroupNV" ); }
	return (*func_ptr)( dpy, drawable, group );
}

inline Bool glXBindSwapBarrierNV(Display *dpy, GLuint group, GLuint barrier)
{
	typedef Bool (*proc_type)(Display *dpy, GLuint group, GLuint barrier);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXBindSwapBarrierNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXBindSwapBarrierNV" ); }
	return (*func_ptr)( dpy, group, barrier );
}

inline Bool glXQuerySwapGroupNV(Display *dpy, GLXDrawable drawable, GLuint *group, GLuint *barrier)
{
	typedef Bool (*proc_type)(Display *dpy, GLXDrawable drawable, GLuint *group, GLuint *barrier);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXQuerySwapGroupNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXQuerySwapGroupNV" ); }
	return (*func_ptr)( dpy, drawable, group, barrier );
}

inline Bool glXQueryMaxSwapGroupsNV(Display *dpy, int screen, GLuint *maxGroups, GLuint *maxBarriers)
{
	typedef Bool (*proc_type)(Display *dpy, int screen, GLuint *maxGroups, GLuint *maxBarriers);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXQueryMaxSwapGroupsNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXQueryMaxSwapGroupsNV" ); }
	return (*func_ptr)( dpy, screen, maxGroups, maxBarriers );
}

inline Bool glXQueryFrameCountNV(Display *dpy, int screen, GLuint *count)
{
	typedef Bool (*proc_type)(Display *dpy, int screen, GLuint *count);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXQueryFrameCountNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXQueryFrameCountNV" ); }
	return (*func_ptr)( dpy, screen, count );
}

inline Bool glXResetFrameCountNV(Display *dpy, int screen)
{
	typedef Bool (*proc_type)(Display *dpy, int screen);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXResetFrameCountNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXResetFrameCountNV" ); }
	return (*func_ptr)( dpy, screen );
}

inline int glXBindVideoCaptureDeviceNV(Display *dpy, unsigned int video_capture_slot, GLXVideoCaptureDeviceNV device)
{
	typedef int (*proc_type)(Display *dpy, unsigned int video_capture_slot, GLXVideoCaptureDeviceNV device);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXBindVideoCaptureDeviceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXBindVideoCaptureDeviceNV" ); }
	return (*func_ptr)( dpy, video_capture_slot, device );
}

inline GLXVideoCaptureDeviceNV * glXEnumerateVideoCaptureDevicesNV(Display *dpy, int screen, int *nelements)
{
	typedef GLXVideoCaptureDeviceNV * (*proc_type)(Display *dpy, int screen, int *nelements);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXEnumerateVideoCaptureDevicesNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXEnumerateVideoCaptureDevicesNV" ); }
	return (*func_ptr)( dpy, screen, nelements );
}

inline void glXLockVideoCaptureDeviceNV(Display *dpy, GLXVideoCaptureDeviceNV device)
{
	typedef void (*proc_type)(Display *dpy, GLXVideoCaptureDeviceNV device);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXLockVideoCaptureDeviceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXLockVideoCaptureDeviceNV" ); }
	(*func_ptr)( dpy, device );
}

inline int glXQueryVideoCaptureDeviceNV(Display *dpy, GLXVideoCaptureDeviceNV device, int attribute, int *value)
{
	typedef int (*proc_type)(Display *dpy, GLXVideoCaptureDeviceNV device, int attribute, int *value);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXQueryVideoCaptureDeviceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXQueryVideoCaptureDeviceNV" ); }
	return (*func_ptr)( dpy, device, attribute, value );
}

inline void glXReleaseVideoCaptureDeviceNV(Display *dpy, GLXVideoCaptureDeviceNV device)
{
	typedef void (*proc_type)(Display *dpy, GLXVideoCaptureDeviceNV device);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXReleaseVideoCaptureDeviceNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXReleaseVideoCaptureDeviceNV" ); }
	(*func_ptr)( dpy, device );
}

inline void glXSwapIntervalEXT(Display *dpy, GLXDrawable drawable, int interval)
{
	typedef void (*proc_type)(Display *dpy, GLXDrawable drawable, int interval);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXSwapIntervalEXT" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXSwapIntervalEXT" ); }
	(*func_ptr)( dpy, drawable, interval );
}

inline void glXCopyImageSubDataNV(Display *dpy, GLXContext srcCtx, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLXContext dstCtx, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth)
{
	typedef void (*proc_type)(Display *dpy, GLXContext srcCtx, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLXContext dstCtx, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
	static proc_type func_ptr = reinterpret_cast<proc_type>( glewlle::get_proc_address( "glXCopyImageSubDataNV" ) );
	if( !func_ptr ) { throw std::runtime_error( "glewlle error : glXCopyImageSubDataNV" ); }
	(*func_ptr)( dpy, srcCtx, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstCtx, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth );
}


#endif // GLEWLLE_GLX_HPP_
