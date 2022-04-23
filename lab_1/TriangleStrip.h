//
// Created by apasemko on 4/16/2022.
//

#ifndef COMPUTERGRAPHICS_TRIANGLESTRIP_H
#define COMPUTERGRAPHICS_TRIANGLESTRIP_H

#include "Point.h"
#include <vector>


class TriangleStrip
{
public:
    TriangleStrip();
    void add_vertex_with_coords(const Coordinates &coords);
    void set_edit_mode_enabled(bool enabled);
    const std::vector<Point> &get_vertices() const;
    void gl_draw() const;
    void highlight();
    void unhighlight();
    void select_vertex_with_appropriate_coords(const Coordinates &coords);
    bool is_vertex_selected() const;
    void change_selected_vertex_coords(const Coordinates &coords);
    void remove_current_vertex();

private:
    void gl_draw_ts() const;
    void gl_draw_shape() const;
    void gl_draw_points() const;
    void gl_specify_coords() const;
    void gl_specify_points() const;
    void gl_specify_ts_lines() const;
    void highlight_colors();
    void highlight_selected_vertex();
    void unhighlight_selected_vertex();
    void unhighlight_colors();
    void unhighlight_vertices();

private:
    std::vector<Point> vertices;
    Color primary_color{};
    Color secondary_color{};
    bool edit_mode_enabled;
    int selected_vertex_ind;

    void select_nearest_vertex(const Coordinates &coords);
};


#endif //COMPUTERGRAPHICS_TRIANGLESTRIP_H
