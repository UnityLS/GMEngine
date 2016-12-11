#pragma once

#include "GMPlatformConfig.h"
#include "GMGraphics.h"
#include "GMRenderWindow.h"

namespace game
{
	class GM_DLL Director
	{
	public:
		Director();
		Director(const Director&) = delete;
		virtual ~Director();

		/**
		* Returns a shared instance of the director.
		*/
		static Director* getInstance();

		virtual bool initialize();
		virtual void terminate();

		virtual void mainLoop();

		virtual void startAnimation(){};
		virtual void stopAnimation(){};
	public:
		void setRenderWindow(RenderWindow::Parameters& param);
		inline RenderWindow* getRenderWindow() { return mRenderWindow; }
		void setRenderer(GraphicsEngine::Parameters& param);
		inline GraphicsEngine* getRenderer() { return mRenderer; }
	protected:
		static Director * mInstance;
		RenderWindow * mRenderWindow;
		GraphicsEngine * mRenderer;
	};
}