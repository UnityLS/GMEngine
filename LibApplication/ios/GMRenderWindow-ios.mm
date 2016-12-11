#include "GMRenderWindow-ios.h"

#if GM_TARGET_PLATFORM == GM_PLATFORM_IOS

#import <UIKit/UIKit.h>

namespace game
{
	RenderWindow* RenderWindow::create(Parameters& param)
	{
		RenderWindow* ret = new (std::nothrow)IosRenderWindow(param);
		if (ret)
			return ret;
		GM_SAFE_DELETE(ret);
		return ret;
	}

	IosRenderWindow::IosRenderWindow(Parameters& param) :
		RenderWindow(param),
        mGLView(nullptr),
		mSyncInterval(1)
	{
	}

	IosRenderWindow::~IosRenderWindow()
	{
	}

	bool IosRenderWindow::initialize()
	{
        CGRect rect = [[UIScreen mainScreen] bounds];
        
        mWidth = rect.size.width;
        mHeight = rect.size.height;
        
		return true;
	}

	void IosRenderWindow::terminate()
	{

	}

    void IosRenderWindow::setGLKView(GLKView* view)
    {
        mGLView = view;
        initialize();
    }
    
	bool IosRenderWindow::windowShouldClose()
	{
		return true;
	}

	void IosRenderWindow::swapBuffers()
	{
		
	}
}
#endif // GM_TARGET_PLATFORM == GM_PLATFORM_IOS