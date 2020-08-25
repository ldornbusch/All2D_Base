#include "GFX_Base/GFX_BaseController.hpp"

int main() {
    GFX_BaseController gfxBaseCtrl;
    Image img;
    img.loadImage("icon.png");
   	All2D_init(800, 600, "All2D_Base App", &img);

    int retval = All2D_main(gfxBaseCtrl);
    return retval;
}
