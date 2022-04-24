//
// Created by apasemko on 4/16/2022.
//

#include "PrimitivesWM.h"

namespace
{
    enum MenuOption
    {
        TOGGLE_EDIT_MODE,
        REMOVE_ALL,
        REMOVE_CURRENT_TS,
        REMOVE_VERTEX,
        UNKNOWN_OPTION
    };

    MenuOption g_current_option;

    void setup_menu()
    {
        g_current_option = UNKNOWN_OPTION;

        // Add menu items
        glutAddMenuEntry("Toggle Edit Mode (or press 'a')", TOGGLE_EDIT_MODE);
        glutAddMenuEntry("Clear All (or press 'z')", REMOVE_ALL);
        glutAddMenuEntry("Remove Current TS (or press 'x')", REMOVE_CURRENT_TS);
        glutAddMenuEntry("Remove Selected Vertex (or press 'c')", REMOVE_VERTEX);

        glutAttachMenu(GLUT_MIDDLE_BUTTON);
    }
}

PrimitivesWM::PrimitivesWM()
{
    glutSetWindowTitle("Lab #1: Triangle Strip");
    setup_menu();
}

void PrimitivesWM::on_display()
{
    ts_manager.gl_draw();
}

void PrimitivesWM::on_mouse_input(int button, int state, float x, float y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        if (!ts_manager.is_edit_mode_enabled())
        {
            ts_manager.on_new_vertex_arrived({x, y});
        }
        else
        {
            ts_manager.on_select_vertex({x, y});
        }
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
    {
        if (!ts_manager.is_edit_mode_enabled())
        {
            ts_manager.start_new_ts();
        }
        else
        {
            ts_manager.on_vertex_coords_changed({x, y});
        }
    }
}

void PrimitivesWM::on_keyboard_input(unsigned char key, float x, float y)
{
    if (key == 'a' || g_current_option == MenuOption::TOGGLE_EDIT_MODE)
    {
        ts_manager.toggle_edit_mode_state();
    }
    else if (key == 'z' || g_current_option == MenuOption::REMOVE_ALL)
    {
        ts_manager.remove_all();
    }
    else if (key == 'x' || g_current_option == MenuOption::REMOVE_CURRENT_TS)
    {
        ts_manager.remove_current_ts();
    }
    else if (key == 'c' || g_current_option == MenuOption::REMOVE_VERTEX)
    {
        ts_manager.on_remove_vertex();
    }
    glutPostRedisplay();
}

void PrimitivesWM::on_special_key_triggered(int specialKey, float x, float y)
{
    if (specialKey == GLUT_KEY_LEFT)
    {
        ts_manager.move_back();
    }
    else if (specialKey == GLUT_KEY_RIGHT)
    {
        ts_manager.move_forward();
    }
    glutPostRedisplay();
}

void PrimitivesWM::on_select_menu_option(int option)
{
    g_current_option = (MenuOption)option;

    // Simulate input to perform the necessary action
    // TODO: Refactor the code to remove this workaround
    on_keyboard_input(' ', 0, 0);

    glutPostRedisplay();
}

