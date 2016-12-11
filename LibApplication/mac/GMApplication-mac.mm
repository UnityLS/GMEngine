#include "GMApplication-mac.h"

#if GM_TARGET_PLATFORM == GM_PLATFORM_MAC

#import <Cocoa/Cocoa.h>
#include "GMDirector.h"

static long getCurrentMillSecond();

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
        long lastTime = 0L;
        long curTime = 0L;

		initContextAttrs();

		// Initialize instance and GMEngine.
		if (!applicationDidFinishLaunching())
		{
			return 1;
		}

		Director* director = Director::getInstance();
		RenderWindow* renderWindow = director->getRenderWindow();

		while (!renderWindow->windowShouldClose())
		{
			lastTime = getCurrentMillSecond();
            
            director->mainLoop();
            renderWindow->swapBuffers();
            
            curTime = getCurrentMillSecond();
            if (curTime - lastTime < mAnimationInterval)
            {
                usleep(static_cast<useconds_t>((mAnimationInterval - curTime + lastTime)*1000));
            }
		}

		director->terminate();
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
		return Platform::OS_MAC;
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
        return [[NSWorkspace sharedWorkspace] openURL:nsUrl];
	}

}

//////////////////////////////////////////////////////////////////////////
// Local function
//////////////////////////////////////////////////////////////////////////
static long getCurrentMillSecond()
{
    long lLastTime = 0;
    struct timeval stCurrentTime;
    
    gettimeofday(&stCurrentTime,NULL);
    lLastTime = stCurrentTime.tv_sec*1000+stCurrentTime.tv_usec*0.001; //millseconds
    return lLastTime;
}

#endif	// GM_TARGET_PLATFORM == GM_PLATFORM_WIN32