// GFX_BaseController.cpp: Implementierung der Klasse GFX_BaseController.
//
//////////////////////////////////////////////////////////////////////
#include "GFX_BaseController.hpp"
#include "../All2DEngine/All2D/All2D_System.h"
//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////

GFX_BaseController::GFX_BaseController(): All2D_Controller("GFX_Base")
{
}

bool GFX_BaseController::paint(Image& backBuffer)
{
    int x_max=All2D_System::fixedX-1, y_max=All2D_System::fixedY-1;
    static int t = 0;
    t++;
    int x = t*6 % x_max;
    int y = (int)(((float)x / x_max) * y_max);
    backBuffer.clear();
    backBuffer.getBitMap()->Line(x,0,x_max/2,y_max/2,0x000000,0xffffff);
    backBuffer.getBitMap()->Line(0,y_max-y,x_max/2,y_max/2,0x000000,0xffffff);
    backBuffer.getBitMap()->Line(x_max,y,x_max/2,y_max/2,0x000000,0xffffff);
    backBuffer.getBitMap()->Line(x_max-x,y_max,x_max/2,y_max/2,0x000000,0xffffff);

	return (!isExit);
}
