//
// Created by apasemko on 4/16/2022.
//

#ifndef COMPUTERGRAPHICS_TRIANGLESTRIPMANAGER_H
#define COMPUTERGRAPHICS_TRIANGLESTRIPMANAGER_H

#include "TriangleStrip.h"

class TriangleStripManager
{
public:
    TriangleStripManager();
    void gl_draw();
    bool is_edit_mode_enabled() const;
//    bool is_vertex_selected() const;
    void on_new_vertex_arrived(const Coordinates &coords);
    void on_select_vertex(const Coordinates &coords);
    void start_new_ts();
    void on_vertex_coords_changed(const Coordinates &coords);
    void toggle_edit_mode_state();
    void remove_all();
    void remove_current_ts();
    void on_remove_vertex();
    void move_back();
    void move_forward();

private:
    void deactivate_current_ts();
    void activate_current_ts();

private:
    std::vector<TriangleStrip> triangle_strips;
    int current_ts_ind;
    bool edit_mode_enabled;
};


#endif //COMPUTERGRAPHICS_TRIANGLESTRIPMANAGER_H
