#pragma once

#include "GMGraphicsEngine.h"

#if defined(GM_USE_OPENGL) || defined(GM_USE_OPENGLES)

#if GM_TARGET_PLATFORM == GM_PLATFORM_WIN32

#endif // GM_TARGET_PLATFORM == GM_PLATFORM_WIN32

#if GM_TARGET_PLATFORM == GM_PLATFORM_MAC
#import <OpenGL/gl.h>
#import <OpenGL/glu.h>
#import <OpenGL/glext.h>
#endif // GM_TARGET_PLATFORM == GM_PLATFORM_MAC

namespace game
{
	class GM_DLL GLGraphics : public GraphicsEngine
	{
	public:
		GLGraphics(GraphicsEngine::Parameters& param);
		virtual ~GLGraphics();

		virtual bool initialize() override;
		virtual void terminate() override;

		virtual void setViewport(int x, int y, int w, int h) override;
		virtual void getViewport(int& x, int& y, int& w, int& h) const override;
		virtual void setDepthRange(float zMin, float zMax) override;
		virtual void getDepthRange(float& zMin, float& zMax) const override;

		virtual bool resize(unsigned int w, unsigned int h) override;

		virtual void displayColorBuffer(unsigned int syncInterval) override;

		virtual void clearColorBuffer() override;

		virtual void clearDepthBuffer() override;

		virtual void clearStencilBuffer() override;

		virtual void clearBuffers() override;

		virtual void flush() override;
	};
}

#endif // defined(GM_USE_OPENGL) || defined(GM_USE_OPENGLES)