//
//  ViewController.m
//  case02
//
//  Created by Shun on 16/1/7.
//  Copyright © 2016年 Shun. All rights reserved.
//

#import "GMDirector.h"
#import "ios/GMRenderWindow-ios.h"
#import "GL/GLES/GMGLESGraphics-ios.h"
#import "ViewController.h"

@interface ViewController () <GLKViewDelegate>
{
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    GLESGraphics* graphics = [GLESGraphics getInstance];
    graphics.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES3];
    [EAGLContext setCurrentContext:graphics.context];
    
    game::Director* dir = game::Director::getInstance();
    game::IosRenderWindow* wnd = (game::IosRenderWindow*)dir->getRenderWindow();
    game::GLGraphics* renderer = (game::GLGraphics*)dir->getRenderer();
    
    if (wnd)
    {
        self.view = [[GLKView alloc] initWithFrame:[[UIScreen mainScreen] bounds] context:graphics.context];
        wnd->setGLKView(self.view);
        
        glGenFramebuffers(1, &defaultFrameBuffer);
        NSAssert( defaultFrameBuffer, @"Can't create default frame buffer");
        
        glGenFramebuffers(1, &colorRenderBuffer);
        NSAssert( colorRenderBuffer, @"Can't create default render buffer");
        
        glBindFramebuffer(GL_FRAMEBUFFER, defaultFrameBuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, colorRenderBuffer);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, colorRenderBuffer);
        
//        if (multiSampling_)
//        {
//            GLint maxSamplesAllowed;
//            glGetIntegerv(GL_MAX_SAMPLES_APPLE, &maxSamplesAllowed);
//            samplesToUse_ = MIN(maxSamplesAllowed,requestedSamples);
//            
//            /* Create the MSAA framebuffer (offscreen) */
//            glGenFramebuffers(1, &msaaFramebuffer_);
//            NSAssert( msaaFramebuffer_, @"Can't create default MSAA frame buffer");
//            glBindFramebuffer(GL_FRAMEBUFFER, msaaFramebuffer_);
//            
//        }
    }
    
}

- (void) glkView:(GLKView *)view drawInRect:(CGRect)rect {
    
    GLESGraphics* graphics = [GLESGraphics getInstance];
    [EAGLContext setCurrentContext:graphics.context];
    
    game::Director::getInstance()->mainLoop();
    
    [self swapBuffers];
}

- (void) swapBuffers
{
    GLESGraphics* graphics = [GLESGraphics getInstance];
    [EAGLContext setCurrentContext:graphics.context];
    
#ifdef __IPHONE_4_0
    
#endif // __IPHONE_4_0
    
    [graphics.context presentRenderbuffer:GL_RENDERBUFFER];
}

@end
