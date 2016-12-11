#pragma once

#include "GMPlatformConfig.h"

#if GM_TARGET_PLATFORM == GM_PLATFORM_MAC
#include "mac/GMApplication-mac.h"
#include "mac/GMRenderWindow-mac.h"
#elif GM_TARGET_PLATFORM == GM_PLATFORM_IOS
#include "ios/GMApplication-ios.h"
#elif GM_TARGET_PLATFORM == GM_PLATFORM_ANDROID
//#include "android/GMApplication-android.h"
#elif GM_TARGET_PLATFORM == GM_PLATFORM_WIN32
#include "platform/win32/GMApplication-win32.h"
#include "platform/win32/GMRenderWindow-win32.h"
#elif GM_TARGET_PLATFORM == GM_PLATFORM_WINRT
//#include "winrt/GMApplication.h"
#elif GM_TARGET_PLATFORM == GM_PLATFORM_LINUX
//#include "linux/GMApplication-linux.h"
#endif