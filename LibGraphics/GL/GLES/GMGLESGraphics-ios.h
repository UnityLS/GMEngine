#pragma once

#include "GMGLGraphics.h"

#if defined(GM_USE_OPENGLES) && (GM_TARGET_PLATFORM == GM_PLATFORM_IOS)

namespace game
{
	class GM_DLL GLESGraphics : public GLGraphics
    {
	public:
		GLESGraphics(GraphicsEngine::Parameters& param);
		virtual ~GLESGraphics();

		virtual bool initialize() override;
		virtual void terminate() override;
        
        inline EAGLContext * getEAGLContext() const { return mContext; }
        
    protected:
        EAGLContext * mContext;
	};
}

#endif // defined(GM_USE_OPENGLES) && (GM_TARGET_PLATFORM == GM_PLATFORM_IOS)