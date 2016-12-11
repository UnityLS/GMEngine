#pragma once

#include "GMPlatformConfig.h"

#ifdef defined(GM_USE_OPENGL)
#include "GL/GMGLGraphics.h"
#elif defined(GM_USE_OPENGLES)
#include "GL/GLES/GMGLESGraphics.h"
#include "GL/GLES/GMGLESGraphics-ios.h"
#else

#endif

#if GM_TARGET_PLATFORM == GM_PLATFORM_MAC

#elif GM_TARGET_PLATFORM == GM_PLATFORM_IOS

#elif GM_TARGET_PLATFORM == GM_PLATFORM_ANDROID

#elif GM_TARGET_PLATFORM == GM_PLATFORM_WIN32

#elif GM_TARGET_PLATFORM == GM_PLATFORM_WINRT

#elif GM_TARGET_PLATFORM == GM_PLATFORM_LINUX

#endif