#pragma once

#include "GMGLGraphics.h"

#if defined(GM_USE_OPENGLES) && (GM_TARGET_PLATFORM != GM_PLATFORM_IOS)

#if GM_TARGET_PLATFORM == GM_PLATFORM_WIN32
#include "gles/glew.h"
#pragma comment(lib, "glew32.lib")
#endif // GM_TARGET_PLATFORM == GM_PLATFORM_WIN32

namespace game
{
	class GM_DLL GLESGraphics : public GLGraphics
    {
	public:
		GLESGraphics(GraphicsEngine::Parameters& param);
		virtual ~GLESGraphics();

		virtual bool initialize() override;
		virtual void terminate() override;		
	};
}

#endif // defined(GM_USE_OPENGLES) && (GM_TARGET_PLATFORM != GM_PLATFORM_IOS)