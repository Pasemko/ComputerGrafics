//
// Created by apasemko on 4/16/2022.
//

#ifndef COMPUTERGRAPHICS_WINDOWMANAGER_H
#define COMPUTERGRAPHICS_WINDOWMANAGER_H

#include <GL/glut.h>
#include <iostream>

class WindowManager
{
public:
    virtual ~WindowManager() = default;

    virtual void on_display() = 0;
    virtual void on_mouse_input(int button, int state, float x, float y) = 0;
    virtual void on_keyboard_input(unsigned char key, float x, float y) = 0;
    virtual void on_special_key_triggered(int specialKey, float x, float y) = 0;
    virtual void on_select_menu_option(int option) = 0;
};


#endif //COMPUTERGRAPHICS_WINDOWMANAGER_H
