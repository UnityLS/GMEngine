#pragma once

/**
Config of GMEngine project, per target platform.

THIS FILE MUST NOT INCLUDE ANY OTHER FILE
*/

//////////////////////////////////////////////////////////////////////////
// pre configure
//////////////////////////////////////////////////////////////////////////

// define supported target platform macro which GM uses.
#define GM_PLATFORM_UNKNOWN            0
#define GM_PLATFORM_IOS                1
#define GM_PLATFORM_ANDROID            2
#define GM_PLATFORM_WIN32              3
#define GM_PLATFORM_MARMALADE          4
#define GM_PLATFORM_LINUX              5
#define GM_PLATFORM_BADA               6
#define GM_PLATFORM_BLACKBERRY         7
#define GM_PLATFORM_MAC                8
#define GM_PLATFORM_NACL               9
#define GM_PLATFORM_EMSCRIPTEN        10
#define GM_PLATFORM_TIZEN             11
#define GM_PLATFORM_QT5               12
#define GM_PLATFORM_WINRT             13

// Determine target platform by compile environment macro.
#define GM_TARGET_PLATFORM             GM_PLATFORM_UNKNOWN

#if defined(__APPLE_CC__)

#   if __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= 60000 || __IPHONE_OS_VERSION_MIN_REQUIRED >= 60000
// ios
#   undef  GM_TARGET_PLATFORM
#   define GM_TARGET_PLATFORM         GM_PLATFORM_IOS
#   else
// mac
#   undef  GM_TARGET_PLATFORM
#   define GM_TARGET_PLATFORM         GM_PLATFORM_MAC
#   endif
#endif

// android
#if defined(ANDROID)
#undef  GM_TARGET_PLATFORM
#define GM_TARGET_PLATFORM         GM_PLATFORM_ANDROID
#endif

// win32
#if defined(_WIN32) && defined(_WINDOWS)
#undef  GM_TARGET_PLATFORM
#define GM_TARGET_PLATFORM         GM_PLATFORM_WIN32
#endif

// linux
#if defined(LINUX) && !defined(__APPLE__)
#undef  GM_TARGET_PLATFORM
#define GM_TARGET_PLATFORM         GM_PLATFORM_LINUX
#endif

// marmalade
#if defined(MARMALADE)
#undef  GM_TARGET_PLATFORM
#define GM_TARGET_PLATFORM         GM_PLATFORM_MARMALADE
#endif

// bada
#if defined(SHP)
#undef  GM_TARGET_PLATFORM
#define GM_TARGET_PLATFORM         GM_PLATFORM_BADA
#endif

// qnx
#if defined(__QNX__)
#undef  GM_TARGET_PLATFORM
#define GM_TARGET_PLATFORM     GM_PLATFORM_BLACKBERRY
#endif

// native client
#if defined(__native_client__)
#undef  GM_TARGET_PLATFORM
#define GM_TARGET_PLATFORM     GM_PLATFORM_NACL
#endif

// Emscripten
#if defined(EMSCRIPTEN)
#undef  GM_TARGET_PLATFORM
#define GM_TARGET_PLATFORM     GM_PLATFORM_EMSCRIPTEN
#endif

// tizen
#if defined(TIZEN)
#undef  GM_TARGET_PLATFORM
#define GM_TARGET_PLATFORM     GM_PLATFORM_TIZEN
#endif

// qt5
#if defined(GM_TARGET_QT5)
#undef  GM_TARGET_PLATFORM
#define GM_TARGET_PLATFORM     GM_PLATFORM_QT5
#endif

// WinRT (Windows 8.1 Store/Phone App)
#if defined(WINRT)
#undef  GM_TARGET_PLATFORM
#define GM_TARGET_PLATFORM			GM_PLATFORM_WINRT
#endif

//////////////////////////////////////////////////////////////////////////
// post configure
//////////////////////////////////////////////////////////////////////////

// check user set platform
#if ! GM_TARGET_PLATFORM
#error  "Cannot recognize the target platform; are you targeting an unsupported platform?"
#endif 

#if (GM_TARGET_PLATFORM == GM_PLATFORM_WIN32)
#ifndef __MINGW32__
#pragma warning (disable:4127) 
#endif 
#endif  // GM_PLATFORM_WIN32