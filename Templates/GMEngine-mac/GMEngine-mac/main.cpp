//
//  main.cpp
//  GMEngine-mac
//
//  Created by Shun on 16/12/11.
//  Copyright © 2016年 Shun. All rights reserved.
//

#include "AppDelegate.h"

int main(int argc, const char * argv[]) {
    
    AppDelegate app;
    return game::Application::getInstance()->run();
}
