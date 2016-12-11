//
//  ViewController.h
//  case02
//
//  Created by Shun on 16/1/7.
//  Copyright © 2016年 Shun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>

@interface ViewController : GLKViewController
{
    unsigned int colorRenderBuffer;
    unsigned int defaultFrameBuffer;
    unsigned int msaaFrameBuffer;
    unsigned int msaaColorBuffer;
}

- (void) swapBuffers;

@end

