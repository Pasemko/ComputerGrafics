//
// Created by apasemko on 4/16/2022.
//

#include "TriangleStripManager.h"
#include <GL/glut.h>


TriangleStripManager::TriangleStripManager():
        edit_mode_enabled(false)
{
    start_new_ts();
}

void TriangleStripManager::gl_draw()
{
    if (triangle_strips.empty())
        return;

    for (unsigned int i = 0; i < triangle_strips.size(); ++i)
    {
        if (i != current_ts_ind)
        {
            triangle_strips[i].gl_draw();
        }
    }

    // Drawing the current TS the last to make it foreground
    triangle_strips[current_ts_ind].gl_draw();
}

void TriangleStripManager::toggle_edit_mode_state()
{
    edit_mode_enabled = !edit_mode_enabled;
    triangle_strips[current_ts_ind].set_edit_mode_enabled(edit_mode_enabled);
}

void TriangleStripManager::start_new_ts()
{
    if (!triangle_strips.empty())
    {
        triangle_strips[current_ts_ind].unhighlight();
    }

    triangle_strips.emplace_back();
    current_ts_ind = (int)triangle_strips.size() - 1;
    triangle_strips[current_ts_ind].highlight();
}

void TriangleStripManager::move_back()
{
    if (current_ts_ind >= 1)
    {
        deactivate_current_ts();
        current_ts_ind--;
        activate_current_ts();
    }
}

void TriangleStripManager::move_forward()
{
    if (current_ts_ind < triangle_strips.size() - 1)
    {
        deactivate_current_ts();
        current_ts_ind++;
        activate_current_ts();
    }
}

void TriangleStripManager::activate_current_ts()
{
    triangle_strips[current_ts_ind].highlight();
    triangle_strips[current_ts_ind].set_edit_mode_enabled(edit_mode_enabled);
}

void TriangleStripManager::deactivate_current_ts()
{
    triangle_strips[current_ts_ind].unhighlight();

    if (edit_mode_enabled)
    {
        triangle_strips[current_ts_ind].set_edit_mode_enabled(!edit_mode_enabled);
    }
}

void TriangleStripManager::remove_current_ts()
{
    triangle_strips.erase(triangle_strips.begin() + current_ts_ind);
    current_ts_ind = (int)triangle_strips.size() - 1;

    if (triangle_strips.empty())
    {
        start_new_ts();
    }
}

void TriangleStripManager::remove_all()
{
    triangle_strips.erase(triangle_strips.begin(), triangle_strips.end());
    start_new_ts();
}

bool TriangleStripManager::is_edit_mode_enabled() const
{
    return edit_mode_enabled;
}

void TriangleStripManager::on_new_vertex_arrived(const Coordinates &coords)
{
    triangle_strips[current_ts_ind].add_vertex_with_coords(coords);
}

void TriangleStripManager::on_select_vertex(const Coordinates &coords)
{
    triangle_strips[current_ts_ind].select_vertex_with_appropriate_coords(coords);
}

void TriangleStripManager::on_vertex_coords_changed(const Coordinates &coords)
{
    triangle_strips[current_ts_ind].change_selected_vertex_coords(coords);
}

void TriangleStripManager::on_remove_vertex()
{
    triangle_strips[current_ts_ind].remove_current_vertex();
}

//bool TriangleStripManager::is_vertex_selected() const
//{
//    return triangle_strips[current_ts_ind].is_vertex_selected();
//}
