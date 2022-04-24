//
// Created by apasemko on 4/16/2022.
//

#include "TriangleStrip.h"
#include "../utils/VerticesDelimiter.h"

TriangleStrip::TriangleStrip() :
    edit_mode_enabled(false),
    selected_vertex_ind(-1)
{
    primary_color = Color(ColorType::PRIMARY);
    secondary_color = Color(primary_color, ColorType::SECONDARY);
}

void TriangleStrip::add_vertex_with_coords(const Coordinates &coords)
{
    vertices.emplace_back(coords, primary_color);
}

void TriangleStrip::gl_draw() const
{
    gl_draw_ts();
    gl_draw_shape();

    if (edit_mode_enabled || vertices.size() == 1)
    {
        gl_draw_points();
    }
}

void TriangleStrip::gl_draw_ts() const
{
    if (vertices.size() < 3)
        return;

    {
        VerticesDelimiter delimiter(GL_TRIANGLE_STRIP);

        secondary_color.gl_specify();
        gl_specify_coords();
    }
}

void TriangleStrip::gl_specify_coords() const
{
    for (const auto &vertex : vertices)
    {
        vertex.get_coordinates().gl_specify();
    }
}

void TriangleStrip::gl_draw_shape() const
{
    if (vertices.size() < 2)
        return;

    {
        VerticesDelimiter delimiter(GL_LINES);
        gl_specify_ts_lines();
    }
}

void TriangleStrip::gl_specify_ts_lines() const
{
    primary_color.gl_specify();

    for (int i = 0; i < vertices.size(); ++i)
    {
        if (i + 1 < vertices.size())
        {
            vertices[i].get_coordinates().gl_specify();
            vertices[i + 1].get_coordinates().gl_specify();
        }
        if (i + 2 < vertices.size())
        {
            vertices[i].get_coordinates().gl_specify();
            vertices[i + 2].get_coordinates().gl_specify();
        }
    }
}

void TriangleStrip::gl_draw_points() const
{
    {
        glPointSize(20.0f);
        VerticesDelimiter delimiter(GL_POINTS);
        gl_specify_points();
    }
}

void TriangleStrip::gl_specify_points() const
{
    for (const auto &vertex : vertices)
    {
        vertex.gl_specify();
    }
}

void TriangleStrip::set_edit_mode_enabled(bool enabled)
{
    edit_mode_enabled = enabled;
}

void TriangleStrip::highlight()
{
    highlight_colors();
}

void TriangleStrip::highlight_colors()
{
    primary_color.highlight();
    secondary_color.highlight();
}

void TriangleStrip::unhighlight()
{
    unhighlight_colors();

    if (edit_mode_enabled)
    {
        unhighlight_vertices();
    }
}

void TriangleStrip::unhighlight_vertices()
{
    for (auto &vertex : vertices)
    {
        vertex.unhighlight();
    }
}

void TriangleStrip::unhighlight_colors()
{
    primary_color.unhighlight();
    secondary_color.unhighlight();
}

const std::vector<Point> &TriangleStrip::get_vertices() const
{
    return vertices;
}

void TriangleStrip::select_vertex_with_appropriate_coords(const Coordinates &coords)
{
    unhighlight_selected_vertex();
    select_nearest_vertex(coords);
    highlight_selected_vertex();
}

void TriangleStrip::select_nearest_vertex(const Coordinates &coords)
{
    float min_distance = 0.02;
    selected_vertex_ind = -1;
    for (int i = 0; i < vertices.size(); ++i)
    {
        float current_distance = coords.distance_to(vertices[i].get_coordinates());
        if (current_distance <= min_distance)
        {
            selected_vertex_ind = i;
            min_distance = current_distance;
        }
    }
}

void TriangleStrip::highlight_selected_vertex()
{
    if (is_vertex_selected())
    {
        vertices[selected_vertex_ind].highlight();
    }
}

void TriangleStrip::unhighlight_selected_vertex()
{
    if (is_vertex_selected())
    {
        vertices[selected_vertex_ind].unhighlight();
    }
}

bool TriangleStrip::is_vertex_selected() const
{
    return selected_vertex_ind != -1;
}

void TriangleStrip::change_selected_vertex_coords(const Coordinates &coords)
{
    if (is_vertex_selected())
    {
        vertices[selected_vertex_ind].set_coordinates(coords);
    }
}

void TriangleStrip::remove_current_vertex()
{
    if (is_vertex_selected())
    {
        vertices.erase(vertices.begin() + selected_vertex_ind);
        selected_vertex_ind = -1;
    }
}
