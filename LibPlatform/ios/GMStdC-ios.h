#pragma once

#include "GMPlatformConfig.h"
#if GM_TARGET_PLATFORM == GM_PLATFORM_IOS

#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <string>
#include <sys/time.h>

typedef std::string String;
typedef std::wstring WString;

#define GM_DLL

#define glClearDepth                glClearDepthf
#define glDepthRange                glDepthRangef
#define glDeleteVertexArrays        glDeleteVertexArraysOES
#define glGenVertexArrays           glGenVertexArraysOES
#define glBindVertexArray           glBindVertexArrayOES
#define glMapBuffer                 glMapBufferOES
#define glUnmapBuffer               glUnmapBufferOES

#define GL_DEPTH24_STENCIL8         GL_DEPTH24_STENCIL8_OES
#define GL_WRITE_ONLY               GL_WRITE_ONLY_OES

#endif // GM_TARGET_PLATFORM == GM_PLATFORM_IOS