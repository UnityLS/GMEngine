#pragma once

#include "GMRenderWindow.h"

#if GM_TARGET_PLATFORM == GM_PLATFORM_IOS

#import <GLKit/GLKit.h>

namespace game
{
	class GM_DLL IosRenderWindow : public RenderWindow
	{
	public:
		IosRenderWindow(Parameters& param);
		virtual ~IosRenderWindow();

		virtual void setFullScreen(bool fullScreen) { mFullScreen = fullScreen; }
		virtual void setSyncInterval(unsigned int syncInterval) { mSyncInterval = syncInterval; }

        void setGLKView(GLKView* view);
        inline GLKView* getGLKView() { return mGLView; }
    public:
		virtual bool initialize() override;
		virtual void terminate() override;

		virtual bool windowShouldClose() override;
		virtual void swapBuffers() override;
	protected:
        GLKView* mGLView;
		int mSyncInterval;
	};
}
#endif // GM_TARGET_PLATFORM == GM_PLATFORM_IOS