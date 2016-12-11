#include "GMApplication-ios.h"

#if GM_TARGET_PLATFORM == GM_PLATFORM_IOS

#include "GMDirector.h"
#import <UIKit/UIKit.h>

namespace game
{
	Application* Application::mInstance = nullptr;

	Application::Application()
        : mAnimationInterval(1.0f/60.0f*1000.0f)
	{
		GM_ASSERT(! mInstance);
		mInstance = this;
	}

	Application::~Application()
	{
		GM_ASSERT(this == mInstance);
		mInstance = nullptr;
	}

	Application* Application::getInstance()
	{
		GM_ASSERT(mInstance);
		return mInstance;
	}

	int Application::run()
	{
		initContextAttrs();

		// Initialize instance and GMEngine.
		if (!applicationDidFinishLaunching())
		{
			return 1;
		}

		return 0;
	}

	void Application::setAnimationInterval(double interval)
	{
		mAnimationInterval = interval*1000.0f;
	}

	LanguageType Application::getCurrentLanguage()
	{
        // get the current language and country config
        NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
        NSArray *languages = [defaults objectForKey:@"AppleLanguages"];
        NSString *currentLanguage = [languages objectAtIndex:0];
        
        // get the current language code.(such as English is "en", Chinese is "zh" and so on)
        NSDictionary* temp = [NSLocale componentsFromLocaleIdentifier:currentLanguage];
        NSString * languageCode = [temp objectForKey:NSLocaleLanguageCode];
        
        if ([languageCode isEqualToString:@"zh"]) return LanguageType::CHINESE;
        if ([languageCode isEqualToString:@"en"]) return LanguageType::ENGLISH;
        if ([languageCode isEqualToString:@"fr"]) return LanguageType::FRENCH;
        if ([languageCode isEqualToString:@"it"]) return LanguageType::ITALIAN;
        if ([languageCode isEqualToString:@"de"]) return LanguageType::GERMAN;
        if ([languageCode isEqualToString:@"es"]) return LanguageType::SPANISH;
        if ([languageCode isEqualToString:@"nl"]) return LanguageType::DUTCH;
        if ([languageCode isEqualToString:@"ru"]) return LanguageType::RUSSIAN;
        if ([languageCode isEqualToString:@"ko"]) return LanguageType::KOREAN;
        if ([languageCode isEqualToString:@"ja"]) return LanguageType::JAPANESE;
        if ([languageCode isEqualToString:@"hu"]) return LanguageType::HUNGARIAN;
        if ([languageCode isEqualToString:@"pt"]) return LanguageType::PORTUGUESE;
        if ([languageCode isEqualToString:@"ar"]) return LanguageType::ARABIC;
        if ([languageCode isEqualToString:@"nb"]) return LanguageType::NORWEGIAN;
        if ([languageCode isEqualToString:@"pl"]) return LanguageType::POLISH;
        if ([languageCode isEqualToString:@"tr"]) return LanguageType::TURKISH;
        if ([languageCode isEqualToString:@"uk"]) return LanguageType::UKRAINIAN;
        if ([languageCode isEqualToString:@"ro"]) return LanguageType::ROMANIAN;
        if ([languageCode isEqualToString:@"bg"]) return LanguageType::BULGARIAN;
        return LanguageType::ENGLISH;
	}

	const char * Application::getCurrentLanguageCode()
	{
        static char code[3]={0};
        NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
        NSArray *languages = [defaults objectForKey:@"AppleLanguages"];
        NSString *currentLanguage = [languages objectAtIndex:0];
        
        // get the current language code.(such as English is "en", Chinese is "zh" and so on)
        NSDictionary* temp = [NSLocale componentsFromLocaleIdentifier:currentLanguage];
        NSString * languageCode = [temp objectForKey:NSLocaleLanguageCode];
        [languageCode getCString:code maxLength:3 encoding:NSASCIIStringEncoding];
        code[2]='\0';
        return code;
	}

	Application::Platform Application::getTargetPlatform()
	{
        if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) // idiom for iOS <= 3.2, otherwise: [UIDevice userInterfaceIdiom] is faster.
        {
            return Platform::OS_IPAD;
        }
        else
        {
            return Platform::OS_IPHONE;
        }
	}

	std::string Application::getVersion()
	{
        NSString* version = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"];
        if (version) {
            return [version UTF8String];
        }
        return "";
	}

	bool Application::openURL(const std::string &url)
	{
        NSString* msg = [NSString stringWithCString:url.c_str() encoding:NSUTF8StringEncoding];
        NSURL* nsUrl = [NSURL URLWithString:msg];
        return [[UIApplication sharedApplication] openURL:nsUrl];
	}

}
#endif	// GM_TARGET_PLATFORM == GM_PLATFORM_IOS