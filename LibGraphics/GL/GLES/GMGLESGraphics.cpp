#include "GMGLESGraphics.h"

#if defined(GM_USE_OPENGLES) && (GM_TARGET_PLATFORM != GM_PLATFORM_IOS)

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
		GLGraphics(param)
	{
	}

	GLESGraphics::~GLESGraphics()
	{
	}

	bool GLESGraphics::initialize()
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

	void GLESGraphics::terminate()
	{

	}
}

#endif // defined(GM_USE_OPENGLES) && (GM_TARGET_PLATFORM != GM_PLATFORM_IOS)