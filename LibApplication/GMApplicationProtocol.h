#pragma once

#include "GMStdC.h"
#include <string>

namespace game
{
	/**
	@brief Enum the language type supported now
	*/
	enum class LanguageType
	{
		ENGLISH = 0,
		CHINESE,
		FRENCH,
		ITALIAN,
		GERMAN,
		SPANISH,
		DUTCH,
		RUSSIAN,
		KOREAN,
		JAPANESE,
		HUNGARIAN,
		PORTUGUESE,
		ARABIC,
		NORWEGIAN,
		POLISH,
		TURKISH,
		UKRAINIAN,
		ROMANIAN,
		BULGARIAN
	};

	/**
	* @addtogroup LibApplication
	* @{
	*/

	class GM_DLL ApplicationProtocol
	{
	public:
		/** Since WINDOWS and ANDROID are defined as macros, we could not just use these keywords in enumeration(Platform).
		*  Therefore, 'OS_' prefix is added to avoid conflicts with the definitions of system macros.
		*/
		enum Platform
		{
			OS_WINDOWS,/** Windows */
			OS_LINUX,/** Linux */
			OS_MAC,/** Mac*/
			OS_ANDROID,/** Android */
			OS_IPHONE,/** Iphone */
			OS_IPAD,/** Ipad */
			OS_BLACKBERRY,/** BLACKBERRY */
			OS_NACL,/** Nacl */
			OS_EMSCRIPTEN,/** Emscripten */
			OS_TIZEN,/** Tizen */
			OS_WINRT,/** Windows Store Applications */
			OS_WP8/** Windows Phone Applications */
		};

	public:
		ApplicationProtocol(){}
		//ApplicationProtocol(const ApplicationProtocol&);
		virtual ~ApplicationProtocol(){}

		/**
		* @brief    Implement Director and Scene init code here.
		* @return true    Initialize success, app continue.
		* @return false   Initialize failed, app terminate.
		*/
		virtual bool applicationDidFinishLaunching() = 0;

		/**
		* @brief  This function will be called when the application enters background.
		*/
		virtual void applicationDidEnterBackground() = 0;

		/**
		* @brief  This function will be called when the application enters foreground.
		*/
		virtual void applicationWillEnterForeground() = 0;

		/**
		* @brief    Callback by Director for limit FPS.
		* @param interval The time, expressed in seconds, between current frame and next.
		*/
		virtual void setAnimationInterval(double interval) = 0;

		/** Subclass override the function to set context attribution instead of use default value.
		* And now can only set six attributions:redBits,greenBits,blueBits,alphaBits,depthBits,stencilBits.
		* Default value are(5,6,5,0,16,0), usually use as follows:
		* void AppDelegate::initContextAttrs(){
		*     ContextAttrs contextAttrs = {8, 8, 8, 8, 24, 8};
		*     RenderWindow::setContextAttrs(contextAttrs);
		* }
		*/
		virtual void initContextAttrs() {}

		/**
		@brief Get current language config.
		@return Current language config.
		*/
		virtual LanguageType getCurrentLanguage() = 0;

		/**
		@brief Get current language iso 639-1 code.
		@return Current language iso 639-1 code.
		*/
		virtual const char * getCurrentLanguageCode() = 0;

		/**
		@brief Get target platform.
		*/
		virtual Platform getTargetPlatform() = 0;

		/**
		@brief Get application version.
		*/
		//virtual std::string getVersion() = 0;

		/**
		@brief Open url in default browser.
		@param String with url to open.
		@return True if the resource located by the URL was successfully opened; otherwise false.
		*/
		virtual bool openURL(const std::string &url) = 0;
	};

	// END of LibApplication group
	/// @}

}