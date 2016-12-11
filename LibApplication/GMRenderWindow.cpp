#include "GMRenderWindow.h"

namespace game
{
	RenderWindow::Parameters::Parameters() :
		title(""),
		xOrigin(0),
		yOrigin(0),
		Width(0),
		Height(0),
		allowResize(false),
		created(false),
		fullScreen(false)
	{
	}
    
    RenderWindow::Parameters::Parameters(String const& inTitle) :
        title(inTitle),
        xOrigin(0),
        yOrigin(0),
        Width(0),
        Height(0),
        allowResize(false),
        created(false),
        fullScreen(true)
    {
    }

	RenderWindow::Parameters::Parameters(String const& inTitle, int inXOrigin, int inYOrigin, int inWidth, int inHeight) :
		title(inTitle),
		xOrigin(inXOrigin),
		yOrigin(inYOrigin),
		Width(inWidth),
		Height(inHeight),
		allowResize(false),
		created(false),
		fullScreen(false)
	{
	}

	RenderWindow::RenderWindow(Parameters& param) :
		mTitle(param.title),
		mXOrigin(param.xOrigin),
		mYOrigin(param.yOrigin),
		mWidth(param.Width),
		mHeight(param.Height),
		mAllowResize(param.allowResize),
		mFullScreen(param.fullScreen)
	{
	}

	RenderWindow::~RenderWindow()
	{
	}

}