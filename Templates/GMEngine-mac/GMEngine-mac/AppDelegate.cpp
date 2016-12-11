#include "AppDelegate.h"
#include "GMDirector.h"
using namespace game;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
}

// if you want a different context, modify the value of ContextAttrs
// it will affect all platforms
void AppDelegate::initContextAttrs()
{
	// set context attributes: red,green,blue,alpha,depth,stencil
}

bool AppDelegate::applicationDidFinishLaunching()
{
	// initialize director
	Director* director = Director::getInstance();
	RenderWindow* renderWindow = director->getRenderWindow();
	if (!renderWindow)
	{
#if (GM_TARGET_PLATFORM == GM_PLATFORM_WIN32) || (GM_TARGET_PLATFORM == GM_PLATFORM_MAC)
        RenderWindow::Parameters paramWnd("MyGame", 0, 0, 960, 640);
		director->setRenderWindow(paramWnd);
#else
        director->setRenderWindow(RenderWindow::Parameters("MyGame"));
#endif
        GraphicsEngine::Parameters paramRenderer(480, 320, { 0.75f, 0.75f, 0.75f, 1.0f }, 1.0f, 0);
		director->setRenderer(paramRenderer);
	}

	Application::setAnimationInterval(1.0 / 60.0);
	
	return true;
}

void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground()
{
	Director::getInstance()->startAnimation();
}


