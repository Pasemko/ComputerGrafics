//
// Created by apasemko on 4/16/2022.
//

#ifndef COMPUTERGRAPHICS_PRIMITIVESWM_H
#define COMPUTERGRAPHICS_PRIMITIVESWM_H

#include "../util/WindowManager.h"
#include "TriangleStripManager.h"


class PrimitivesWM :
        public WindowManager
{
public:
    PrimitivesWM();

    void on_display() override;
    void on_mouse_input(int button, int state, float x, float y) override;
    void on_keyboard_input(unsigned char key, float x, float y) override;
    void on_special_key_triggered(int specialKey, float x, float y) override;
    void on_select_menu_option(int option) override;

private:
    TriangleStripManager ts_manager {};
};


#endif //COMPUTERGRAPHICS_PRIMITIVESWM_H
