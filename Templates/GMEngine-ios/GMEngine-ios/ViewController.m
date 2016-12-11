//
//  ViewController.m
//  case02
//
//  Created by Shun on 16/1/7.
//  Copyright © 2016年 Shun. All rights reserved.
//

#import "ViewController.h"

@interface ViewController () <GLKViewDelegate>
{
}
@end


@implementation ViewController

@synthesize context, glView;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
    
    [EAGLContext setCurrentContext:context];
    
    glView = (GLKView *)self.view;
    glView.context = self.context;
    
    glView = [[GLKView alloc] initWithFrame:[[UIScreen mainScreen] bounds] context:context];
    self.view = glView;
}

- (void) glkView:(GLKView *)view drawInRect:(CGRect)rect {
    
    
}

@end
