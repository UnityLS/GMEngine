#include "GMGLESGraphics-ios.h"

#if defined(GM_USE_OPENGLES) && (GM_TARGET_PLATFORM == GM_PLATFORM_IOS)

namespace game
{
	GraphicsEngine* GraphicsEngine::create(GraphicsEngine::Parameters& param)
	{
		GraphicsEngine* ret = new (std::nothrow)GLGraphics(param);
		if (ret)
			return ret;
		GM_SAFE_DELETE(ret);
		return ret;
	}
}

static id g_Instance;

@implementation GLESGraphics

@synthesize context;

+(id) getInstance
{
    if (g_Instance == nil)
    {
        g_Instance = [GLESGraphics new];
    }
    return g_Instance;
}

-(void) terminate
{
    
}

@end

#endif // defined(GM_USE_OPENGLES) && (GM_TARGET_PLATFORM == GM_PLATFORM_IOS)