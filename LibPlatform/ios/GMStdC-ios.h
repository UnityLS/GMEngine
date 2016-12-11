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

#define GM_GL_DEPTH24_STENCIL8      -1

#define glDeleteVertexArrays            glDeleteVertexArraysAPPLE
#define glGenVertexArrays               glGenVertexArraysAPPLE
#define glBindVertexArray               glBindVertexArrayAPPLE
#define glClearDepthf                   glClearDepth
#define glDepthRangef                   glDepthRange
#define glReleaseShaderCompiler(xxx)


#endif // GM_TARGET_PLATFORM == GM_PLATFORM_IOS