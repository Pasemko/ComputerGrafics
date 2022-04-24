//
// Created by apasemko on 4/16/2022.
//

#include "utils.h"
#include <tuple>
#include "VerticesDelimiter.h"
#include "../lab_1/PrimitivesWMHolder.h"
#include "../lab_2/PrimitivesRasteringWMHolder.h"

namespace util
{
    namespace
    {
        std::shared_ptr<WMHolder> window_manager_holder;

        /// GLUT HANDLERS

        std::tuple<float, float> convert_mp_location_to_gl(int x, int y)
        {
            auto current_win_width = glutGet(GLUT_WINDOW_WIDTH);
            float gl_x = (float) x / ((float) current_win_width / 2) - 1.0;

            auto current_win_height = glutGet(GLUT_WINDOW_HEIGHT);
            float gl_y = -((float) y / ((float) current_win_height / 2) - 1.0);

            return {gl_x, gl_y};
        }

        void on_display()
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            {
                // The color cannot be cleared if no primitives are specified.
                // This workaround is needed to clear the window after all the user added primitives are removed.
                // TODO: Get rid of this as soon as possible.
                VerticesDelimiter delimiter(GL_POINT);
                glVertex2f(0, 0);
            }

            window_manager_holder->get_window_manager_ptr()->on_display();
            glFlush();

        }

        void on_mouse_input(int button, int state, int x, int y)
        {
            float gl_x, gl_y;
            std::tie(gl_x, gl_y) = convert_mp_location_to_gl(x, y);
            window_manager_holder->get_window_manager_ptr()->on_mouse_input(button, state, gl_x, gl_y);
        }

        void on_keyboard_input(unsigned char key, int x, int y)
        {
            float gl_x, gl_y;
            std::tie(gl_x, gl_y) = convert_mp_location_to_gl(x, y);
            window_manager_holder->get_window_manager_ptr()->on_keyboard_input(key, gl_x, gl_y);
        }

        void on_special_key_triggered(int specialKey, int x, int y)
        {
            float gl_x, gl_y;
            std::tie(gl_x, gl_y) = convert_mp_location_to_gl(x, y);
            window_manager_holder->get_window_manager_ptr()->on_special_key_triggered(specialKey, gl_x, gl_y);
        }

        void on_select_menu_option(int option)
        {
            window_manager_holder->get_window_manager_ptr()->on_select_menu_option(option);
        }

        /// GLUT WINDOW SETUP

        void init_window_manager()
        {
            /// For now to check out between labs windows we need manually replace the WMH.
//            window_manager_holder = std::make_shared<PrimitivesWMHolder>();
            window_manager_holder = std::make_shared<PrimitivesRasteringWMHolder>();
            window_manager_holder->init();
        }

        void glut_init_window()
        {
            glutInitWindowSize(1280, 640);
            glutInitWindowPosition(50, 50);
            glutCreateWindow("WINDOW");
        }

        void glut_setup_properties()
        {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glEnable(GL_BLEND);
            glEnable(GL_POINT_SMOOTH);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        }

        void glut_register_handlers()
        {
            glutDisplayFunc(on_display);
            glutMouseFunc(on_mouse_input);
            glutKeyboardFunc(on_keyboard_input);
            glutSpecialFunc(on_special_key_triggered);
            glutCreateMenu(on_select_menu_option);
        }

        void start_processing_window_events()
        {
            init_window_manager();
            glutMainLoop();
        }

        void glut_setup_window()
        {
            glut_init_window();

            glut_setup_properties();

            glut_register_handlers();
        }
    }

    void run_window()
    {
        glut_setup_window();

        start_processing_window_events();
    }

}


