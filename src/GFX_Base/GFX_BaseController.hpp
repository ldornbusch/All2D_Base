// GFX_BaseController.hpp: Interface for class GFX_BaseController.

//////////////////////////////////////////////////////////////////////
#pragma once
#include "../All2DEngine/All2D/All2D_Controller.h"

class GFX_BaseController : public All2D_Controller
{
public:
	virtual bool paint(Image& backBuffer);
	GFX_BaseController();
};
