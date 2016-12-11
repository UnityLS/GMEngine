#pragma once

#include "GMRenderWindow.h"

#if GM_TARGET_PLATFORM == GM_PLATFORM_MAC

#if defined(GM_USE_OPENGL) || defined(GM_USE_OPENGLES)

#include "glfw3/glfw3.h"
#ifndef GLFW_EXPOSE_NATIVE_NSGL
#define GLFW_EXPOSE_NATIVE_NSGL
#endif
#ifndef GLFW_EXPOSE_NATIVE_COCOA
#define GLFW_EXPOSE_NATIVE_COCOA
#endif
#include "glfw3/glfw3native.h"

namespace game
{
	class GM_DLL MacRenderWindow : public RenderWindow
	{
	public:
		MacRenderWindow(Parameters& param);
		virtual ~MacRenderWindow();

		virtual void setFullScreen(bool fullScreen) { mFullScreen = fullScreen; }
		virtual void setSyncInterval(unsigned int syncInterval) { mSyncInterval = syncInterval; }
	public:
		virtual bool initialize() override;
		virtual void terminate() override;

		virtual bool windowShouldClose() override;
		virtual void swapBuffers() override;
	protected:
		friend class GLFWEventHandler;

		void onGLFWError(int errorID, const char* errorDesc);
		void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int modify);
		void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y);
		void onGLFWMouseScrollCallback(GLFWwindow* window, double x, double y);
		void onGLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void onGLFWCharCallback(GLFWwindow* window, unsigned int character);
		void onGLFWWindowPosCallback(GLFWwindow* windows, int x, int y);
		void onGLFWframebuffersize(GLFWwindow* window, int w, int h);
		void onGLFWWindowSizeFunCallback(GLFWwindow *window, int width, int height);
		void onGLFWWindowIconifyCallback(GLFWwindow* window, int iconified);
	protected:
		GLFWwindow* mMainWindow;
		GLFWmonitor* mMonitor;
		int mSyncInterval;
	};
}
#endif // defined(GM_USE_OPENGL) || defined(GM_USE_OPENGLES)
#endif // GM_TARGET_PLATFORM == GM_PLATFORM_MAC