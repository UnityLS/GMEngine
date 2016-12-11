#pragma once

#include "GMGLGraphics.h"

#if defined(GM_USE_OPENGLES) && (GM_TARGET_PLATFORM == GM_PLATFORM_IOS)

#import <Foundation/Foundation.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES3/gl.h>
#import <OpenGLES/ES3/glext.h>

@interface GLESGraphics : NSObject {
    game::GLGraphics* mGLGraphics;
    EAGLContext* mContext;
}
@property (readwrite) EAGLContext* context;
+(id) getInstance;
-(void) terminate;

@end

#endif // defined(GM_USE_OPENGLES) && (GM_TARGET_PLATFORM == GM_PLATFORM_IOS)