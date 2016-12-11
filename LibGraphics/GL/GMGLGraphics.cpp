#include "GMGLGraphics.h"

#if defined(GM_USE_OPENGL) || defined(GM_USE_OPENGLES)

namespace game
{
#if defined(GM_USE_OPENGL)
	GraphicsEngine* GraphicsEngine::create(GraphicsEngine::Parameters& param)
	{
		GraphicsEngine* ret = new (std::nothrow)GLGraphics(param);
		if (ret && ret->initialize())
			return ret;
		GM_SAFE_DELETE(ret);
		return ret;
	}
#endif // defined(GM_USE_OPENGL)

	GLGraphics::GLGraphics(GraphicsEngine::Parameters& param) :
		GraphicsEngine(param)
	{
	}

	GLGraphics::~GLGraphics()
	{
	}

	bool GLGraphics::initialize()
	{
		// check OpenGL version at first
		const GLubyte* glVersion = glGetString(GL_VERSION);

		if (atof((const char*)glVersion) < 2.0)
		{
			char strComplain[256] = { 0 };
			sprintf(strComplain,
				"OpenGL 2.0 or higher is required (your version is %s). Please upgrade the driver of your video card.",
				glVersion);
			MessageBox(strComplain, "OpenGL version too old");
			return false;
		}

#if (GM_TARGET_PLATFORM != GM_PLATFORM_MAC)
		GLenum GlewInitResult = glewInit();
		if (GLEW_OK != GlewInitResult)
		{
			MessageBox((char *)glewGetErrorString(GlewInitResult), "OpenGL error");
			return false;
		}
        if (GLEW_ARB_vertex_shader && GLEW_ARB_fragment_shader)
        {
            gmlog("Ready for GLSL");
        }
        else
        {
            gmlog("Not totally ready :(");
        }
        
        if (glewIsSupported("GL_VERSION_2_0"))
        {
            gmlog("Ready for OpenGL 2.0");
        }
        else
        {
            gmlog("OpenGL 2.0 not supported");
        }
#endif // GM_TARGET_PLATFORM != GM_PLATFORM_MAC

		setViewport(0, 0, mViewWidth, mViewHeight);
		setDepthRange(0.0f, mClearDepth);

		// Enable point size by default.
		glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);

		return true;
	}

	void GLGraphics::terminate()
	{

	}

	void GLGraphics::setViewport(int x, int y, int w, int h)
	{
		mViewWidth = w;
		mViewHeight = h;
		glViewport(x, y, w, h);
	}

	void GLGraphics::getViewport(int& x, int& y, int& w, int& h) const
	{
		int param[4];
		glGetIntegerv(GL_VIEWPORT, param);

		x = param[0];
		y = param[1];
		w = param[2];
		h = param[3];
	}

	void GLGraphics::setDepthRange(float zMin, float zMax)
	{
		glDepthRange((GLclampd)zMin, (GLclampd)zMax);
	}

	void GLGraphics::getDepthRange(float& zMin, float& zMax) const
	{
		GLclampd param[2];
		glGetDoublev(GL_DEPTH_RANGE, param);

		zMin = (float)param[0];
		zMax = (float)param[1];
	}

	bool GLGraphics::resize(unsigned int w, unsigned int h)
	{
		mViewWidth = w;
		mViewHeight = h;

		int param[4];
		glGetIntegerv(GL_VIEWPORT, param);
		glViewport(param[0], param[1], static_cast<GLint>(w), static_cast<GLint>(h));
		return true;
	}

	void GLGraphics::displayColorBuffer(unsigned int syncInterval)
	{
	}

	void GLGraphics::clearColorBuffer()
	{
		glClearColor(mClearColor[0], mClearColor[1], mClearColor[2], mClearColor[3]);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void GLGraphics::clearDepthBuffer()
	{
		glClearDepth(mClearDepth);
		glClear(GL_DEPTH_BUFFER_BIT);
	}

	void GLGraphics::clearStencilBuffer()
	{
		glClearStencil(static_cast<GLint>(mClearStencil));
		glClear(GL_STENCIL_BUFFER_BIT);
	}

	void GLGraphics::clearBuffers()
	{
		glClearColor(mClearColor[0], mClearColor[1], mClearColor[2], mClearColor[3]);
		glClearDepth(mClearDepth);
		glClearStencil(static_cast<GLint>(mClearStencil));
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	void GLGraphics::flush()
	{
		glFlush();
	}

}

#endif // defined(GM_USE_OPENGL) || defined(GM_USE_OPENGLES)