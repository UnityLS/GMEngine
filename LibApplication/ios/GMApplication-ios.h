#pragma once

#include "GMPlatformConfig.h"
#if GM_TARGET_PLATFORM == GM_PLATFORM_IOS

#include "GMApplicationProtocol.h"

namespace game
{
	class GM_DLL Application : public ApplicationProtocol
	{
	public:
		Application();
		Application(const Application&) = delete;
		virtual ~Application();

		/**
		@brief    Get current applicaiton instance.
		@return Current application instance pointer.
		*/
		static Application* getInstance();

		/**
		@brief    Run the message loop.
		*/
		int run();

		/* override functions */
		virtual void setAnimationInterval(double interval);
		virtual LanguageType getCurrentLanguage();

		virtual const char * getCurrentLanguageCode();

		/**
		@brief Get target platform
		*/
		virtual Platform getTargetPlatform();

		/**
		@brief Get application version
		*/
		virtual std::string getVersion();

		/**
		@brief Open url in default browser
		@param String with url to open.
		@return true if the resource located by the URL was successfully opened; otherwise false.
		*/
		virtual bool openURL(const std::string &url);
		
	protected:
		static Application* mInstance;
		long mAnimationInterval;
	};
}
#endif	// GM_TARGET_PLATFORM == GM_PLATFORM_IOS