#pragma once

#include "game.h"

class AppDelegate : private game::Application
{
public:
	AppDelegate();
	virtual ~AppDelegate();

	virtual void initContextAttrs() override;

	/**
	@brief    Implement Director and Scene init code here.
	@return true    Initialize success, app continue.
	@return false   Initialize failed, app terminate.
	*/
	virtual bool applicationDidFinishLaunching();

	/**
	@brief  Called when the application moves to the background
	@param  the pointer of the application
	*/
	virtual void applicationDidEnterBackground();

	/**
	@brief  Called when the application reenters the foreground
	@param  the pointer of the application
	*/
	virtual void applicationWillEnterForeground();
};