#include "GMRenderWindow-mac.h"

#if GM_TARGET_PLATFORM == GM_PLATFORM_MAC

#if defined(GM_USE_OPENGL) || defined(GM_USE_OPENGLES)
namespace game
{
	RenderWindow* RenderWindow::create(Parameters& param)
	{
		RenderWindow* ret = new (std::nothrow)MacRenderWindow(param);
		if (ret && ret->initialize())
			return ret;
		GM_SAFE_DELETE(ret);
		return ret;
	}

	// GLFWEventHandler

	class GLFWEventHandler
	{
	public:
		static void onGLFWError(int errorID, const char* errorDesc)
		{
			if (_view)
				_view->onGLFWError(errorID, errorDesc);
		}

		static void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int modify)
		{
			if (_view)
				_view->onGLFWMouseCallBack(window, button, action, modify);
		}

		static void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y)
		{
			if (_view)
				_view->onGLFWMouseMoveCallBack(window, x, y);
		}

		static void onGLFWMouseScrollCallback(GLFWwindow* window, double x, double y)
		{
			if (_view)
				_view->onGLFWMouseScrollCallback(window, x, y);
		}

		static void onGLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (_view)
				_view->onGLFWKeyCallback(window, key, scancode, action, mods);
		}

		static void onGLFWCharCallback(GLFWwindow* window, unsigned int character)
		{
			if (_view)
				_view->onGLFWCharCallback(window, character);
		}

		static void onGLFWWindowPosCallback(GLFWwindow* windows, int x, int y)
		{
			if (_view)
				_view->onGLFWWindowPosCallback(windows, x, y);
		}

		static void onGLFWframebuffersize(GLFWwindow* window, int w, int h)
		{
			if (_view)
				_view->onGLFWframebuffersize(window, w, h);
		}

		static void onGLFWWindowSizeFunCallback(GLFWwindow *window, int width, int height)
		{
			if (_view)
				_view->onGLFWWindowSizeFunCallback(window, width, height);
		}

		static void setRenderWindow(MacRenderWindow* view)
		{
			_view = view;
		}

		static void onGLFWWindowIconifyCallback(GLFWwindow* window, int iconified)
		{
			if (_view)
			{
				_view->onGLFWWindowIconifyCallback(window, iconified);
			}
		}

	private:
		static MacRenderWindow* _view;
	};

	MacRenderWindow* GLFWEventHandler::_view = nullptr;

	MacRenderWindow::MacRenderWindow(Parameters& param) :
		RenderWindow(param),
		mMainWindow(NULL),
		mMonitor(NULL),
		mSyncInterval(1)
	{
		GLFWEventHandler::setRenderWindow(this);
		glfwSetErrorCallback(GLFWEventHandler::onGLFWError);
		glfwInit();
	}

	MacRenderWindow::~MacRenderWindow()
	{
		GLFWEventHandler::setRenderWindow(nullptr);
		glfwTerminate();
	}

	bool MacRenderWindow::initialize()
	{
		if (mFullScreen)
		{
			mMonitor = glfwGetPrimaryMonitor();
			if (nullptr == mMonitor)
				return false;
			const GLFWvidmode* videoMode = glfwGetVideoMode(mMonitor);
			mWidth = videoMode->width;
			mHeight = videoMode->height;
			mAllowResize = false;
		}

		glfwWindowHint(GLFW_RESIZABLE, mAllowResize ? GL_TRUE : GL_FALSE);
		glfwWindowHint(GLFW_RED_BITS, 8);
		glfwWindowHint(GLFW_GREEN_BITS, 8);
		glfwWindowHint(GLFW_BLUE_BITS, 8);
		glfwWindowHint(GLFW_ALPHA_BITS, 8);
		glfwWindowHint(GLFW_DEPTH_BITS, 24);
		glfwWindowHint(GLFW_STENCIL_BITS, 8);

		mMainWindow = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), mMonitor, nullptr);
		if (mMainWindow == nullptr)
		{
			return false;
		}

		glfwMakeContextCurrent(mMainWindow);

		glfwSetMouseButtonCallback(mMainWindow, GLFWEventHandler::onGLFWMouseCallBack);
		glfwSetCursorPosCallback(mMainWindow, GLFWEventHandler::onGLFWMouseMoveCallBack);
		glfwSetScrollCallback(mMainWindow, GLFWEventHandler::onGLFWMouseScrollCallback);
		glfwSetCharCallback(mMainWindow, GLFWEventHandler::onGLFWCharCallback);
		glfwSetKeyCallback(mMainWindow, GLFWEventHandler::onGLFWKeyCallback);
		glfwSetWindowPosCallback(mMainWindow, GLFWEventHandler::onGLFWWindowPosCallback);
		glfwSetFramebufferSizeCallback(mMainWindow, GLFWEventHandler::onGLFWframebuffersize);
		glfwSetWindowSizeCallback(mMainWindow, GLFWEventHandler::onGLFWWindowSizeFunCallback);
		glfwSetWindowIconifyCallback(mMainWindow, GLFWEventHandler::onGLFWWindowIconifyCallback);

		return true;
	}

	void MacRenderWindow::terminate()
	{

	}

	bool MacRenderWindow::windowShouldClose()
	{
		if (mMainWindow)
			return glfwWindowShouldClose(mMainWindow) ? true : false;
		return true;
	}

	void MacRenderWindow::swapBuffers()
	{
		if (mMainWindow)
		{
			glfwPollEvents();
			glfwSwapInterval(mSyncInterval > 0 ? 1 : 0);
			glfwSwapBuffers(mMainWindow);
		}
	}

	void MacRenderWindow::onGLFWError(int errorID, const char* errorDesc)
	{

	}

	void MacRenderWindow::onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int modify)
	{

	}

	void MacRenderWindow::onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y)
	{

	}

	void MacRenderWindow::onGLFWMouseScrollCallback(GLFWwindow* window, double x, double y)
	{

	}

	void MacRenderWindow::onGLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{

	}

	void MacRenderWindow::onGLFWCharCallback(GLFWwindow* window, unsigned int character)
	{

	}

	void MacRenderWindow::onGLFWWindowPosCallback(GLFWwindow* windows, int x, int y)
	{

	}

	void MacRenderWindow::onGLFWframebuffersize(GLFWwindow* window, int w, int h)
	{

	}

	void MacRenderWindow::onGLFWWindowSizeFunCallback(GLFWwindow *window, int width, int height)
	{

	}

	void MacRenderWindow::onGLFWWindowIconifyCallback(GLFWwindow* window, int iconified)
	{

	}
}
#endif // defined(GM_USE_OPENGL)  || defined(GM_USE_OPENGLES)
#endif // GM_TARGET_PLATFORM == GM_PLATFORM_MAC