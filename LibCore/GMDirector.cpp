#include "GMDirector.h"
//#include "renderer/GMProgramFactory.h"

namespace game
{
	Director * Director::mInstance = nullptr;

	Director::Director() :
		mRenderWindow(nullptr),
		mRenderer(nullptr)
	{
	}

	Director::~Director()
	{
	}

	Director* Director::getInstance()
	{
		if (!mInstance)
		{
			mInstance = new (std::nothrow) Director();
			GMASSERT(mInstance, "GM: Fatal! Not enough memory.");
		}

		return mInstance;
	}
	static const char *szIdentityShaderVP = "attribute vec4 a_position;"
		"void main(void) "
		"{ gl_Position = a_position; "
		"}";

	static const char *szIdentityShaderFP =
		"precision mediump float;"
		"uniform vec4 GM_AmbientColor;"
		"void main(void) "
		"{ gl_FragColor = GM_AmbientColor;"
		"}";
	bool Director::initialize()
	{
		do
		{
			
			return true;
		} while (0);
		return false;
	}

	void Director::terminate()
	{
		if (mRenderWindow)
		{
			mRenderWindow->terminate();
			GM_SAFE_DELETE(mRenderWindow);
		}
	}

	void Director::mainLoop()
	{
		mRenderer->clearBuffers();


		mRenderer->displayColorBuffer(0);
	}

	void Director::setRenderWindow(RenderWindow::Parameters& param)
	{
		if (mRenderWindow)
		{
			mRenderWindow->terminate();
			GM_SAFE_DELETE(mRenderWindow);
		}
        mRenderWindow = RenderWindow::create(param);
		GMASSERT(mRenderer, "FATAL: Invalid RenderWindow initialize.");
	}

	void Director::setRenderer(GraphicsEngine::Parameters& param)
	{
		if (mRenderer)
		{
			mRenderer->terminate();
			GM_SAFE_DELETE(mRenderer);
		}
		mRenderer = GraphicsEngine::create(param);
		GMASSERT(mRenderer, "FATAL: Invalid GraphicsEngine initialize.");
	}

}