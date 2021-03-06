#include "All2D/All2D_System.h"
#include "All2D/All2D_HAL/All2Dwin.h"

#define NAME    "All3DInterface"
#define TITLE   "SFML to All2D Window/Screen"

//LRESULT CALLBACK MainWndProc (HWND ,UINT,WPARAM ,LPARAM);
bool fullscreen = false;	// app is in fullscreen mode
All2DWin *myWin;			// Window-class for SFML Window

//
// initialize static system object
// ------------------------------------------------------
// get and set registry defaults if not present
//
bool All2D_init(int xres, int yres, std::string WinTitle, Image* icon)
{
	All2D_System::fixedX=xres;
	All2D_System::fixedY=yres;
	All2D_System::fixedBits=32;
	All2D_System::WinTitle=WinTitle;

	myWin = new All2DWin();
	myWin->init();
	if (icon){
        myWin->setIcon(*icon);
	}
	PicLoader::init();
	return true;
}

int All2D_main(All2D_Controller& ctrl)
{
	/*
	 * load all buffered images and post progress
	 */
    ctrl.init();

	int counter=0;
	while (counter>=0)
	{
		counter=PicLoader::loadAllBitMaps();
		ctrl.updateProgress(counter);
	}

	/*
	 * init window and game controller and start main loop
	 */
	myWin->startApp(ctrl);
	ctrl.finish();			// drawableElement aufr�umen

	delete myWin;
	return 0;
}

