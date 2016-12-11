#pragma once

#include "GMPlatformConfig.h"

#if GM_TARGET_PLATFORM == GM_PLATFORM_MAC
#include "mac/GMStdC-mac.h"
#elif GM_TARGET_PLATFORM == GM_PLATFORM_IOS
#include "ios/GMStdC-ios.h"
#elif GM_TARGET_PLATFORM == GM_PLATFORM_ANDROID
#include "android/GMStdC-android.h"
#elif GM_TARGET_PLATFORM == GM_PLATFORM_WIN32
#include "win32/GMStdC-win32.h"
#elif GM_TARGET_PLATFORM == GM_PLATFORM_WINRT
#include "winrt/GMStdC-winrt.h"
#elif GM_TARGET_PLATFORM == GM_PLATFORM_LINUX
#include "linux/GMStdC-linux.h"
#endif

#if defined(DEBUG) || defined(_DEBUG)
#	define GM_DEBUG		1
#endif // DEBUG || _DEBUG

#define GM_SAFE_DELETE(p)           do { delete (p); (p) = nullptr; } while(0)
#define GM_SAFE_DELETE_ARRAY(p)     do { if(p) { delete[] (p); (p) = nullptr; } } while(0)
#define GM_SAFE_FREE(p)             do { if(p) { free(p); (p) = nullptr; } } while(0)

#define gmlog(msg)	printf(msg)
#define GM_ASSERT(cond) assert(cond)
#define GMASSERT(cond, msg)

#ifdef MessageBox
#	undef MessageBox
#endif // MessageBox

#ifndef MIN
#define MIN(x,y) (((x) > (y)) ? (y) : (x))
#endif  // MIN

#ifndef MAX
#define MAX(x,y) (((x) < (y)) ? (y) : (x))
#endif  // MAX

#define MessageBox(msg, title)