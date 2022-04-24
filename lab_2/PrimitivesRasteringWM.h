//
// Created by apasemko on 4/23/2022.
//

#ifndef COMPUTERGRAPHICS_PRIMITIVESRASTERINGWM_H
#define COMPUTERGRAPHICS_PRIMITIVESRASTERINGWM_H

#include "../utils/WindowManager.h"
#include "PolygonManager.h"


class PrimitivesRasteringWM :
        public WindowManager
{
public:
    PrimitivesRasteringWM();

    void on_display() override;
    void on_mouse_input(int button, int state, float x, float y) override;
    void on_keyboard_input(unsigned char key, float x, float y) override;
    void on_special_key_triggered(int specialKey, float x, float y) override;
    void on_select_menu_option(int option) override;

private:
    PolygonManager polygon_manager;
};


#endif //COMPUTERGRAPHICS_PRIMITIVESRASTERINGWM_H
