#include "GMGLESGraphics-ios.h"

#if defined(GM_USE_OPENGLES) && (GM_TARGET_PLATFORM == GM_PLATFORM_IOS)

namespace game
{
	GraphicsEngine* GraphicsEngine::create(GraphicsEngine::Parameters& param)
	{
		GraphicsEngine* ret = new (std::nothrow)GLESGraphics(param);
		if (ret && ret->initialize())
			return ret;
		GM_SAFE_DELETE(ret);
		return ret;
	}

	GLESGraphics::GLESGraphics(GraphicsEngine::Parameters& param) :
		GLGraphics(param),
        mContext(nullptr)
	{
	}

	GLESGraphics::~GLESGraphics()
	{
	}

	bool GLESGraphics::initialize()
	{
        mContext = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES3];
        
		setViewport(0, 0, mViewWidth, mViewHeight);
		setDepthRange(0.0f, mClearDepth);

		// Enable point size by default.
		//glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);

		return true;
	}

	void GLESGraphics::terminate()
	{

	}
}

#endif // defined(GM_USE_OPENGLES) && (GM_TARGET_PLATFORM == GM_PLATFORM_IOS)