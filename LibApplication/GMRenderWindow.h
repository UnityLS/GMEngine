#pragma once

#include "GMStdC.h"

namespace game
{
	class GM_DLL RenderWindow
	{
		friend class Director;
	public:
		struct GM_DLL Parameters
		{
			Parameters();
            Parameters(String const& inTitle);
			Parameters(String const& inTitle, int inXOrigin, int inYOrigin, int inWidth, int inHeight);

			String title;
			int xOrigin, yOrigin, Width, Height;
			bool allowResize, created, fullScreen;
		};
	public:
		virtual ~RenderWindow();

		virtual bool initialize() = 0;
		virtual void terminate() = 0;

		virtual bool windowShouldClose() = 0;
		virtual void swapBuffers() = 0;
	protected:
		RenderWindow(Parameters& param);

		static RenderWindow* create(Parameters& param);
	protected:
		String mTitle;
		int mXOrigin, mYOrigin, mWidth, mHeight;
		bool mAllowResize, mFullScreen;
	};

}