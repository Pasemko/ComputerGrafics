//
// Created by apasemko on 4/23/2022.
//

#include "Polygon.h"
#include "../utils/VerticesDelimiter.h"
#include <cmath>

Polygon::Polygon(const Coordinates &center, float radius, unsigned int sides) :
    radius(radius),
    sides_number(sides)
{
    primary_color = Color(ColorType::PRIMARY);
    secondary_color = Color(primary_color, ColorType::SECONDARY);
    this->center = Point(center, primary_color);

    refresh();
}

void Polygon::refresh()
{
    vertices_cache.clear();
    for (unsigned int i = 0; i < sides_number; ++i)
    {
        Coordinates vertex_coords = get_vertex_coords_by_index(i);
        vertices_cache.emplace_back(vertex_coords, secondary_color);
    }
}

Coordinates Polygon::get_vertex_coords_by_index(unsigned int index) const
{
    Coordinates center_coords = center.get_coordinates();
    float x = center_coords.get_x() + radius * (float)sin(2.0 * M_PI * index / sides_number);
    float y = center_coords.get_y() + radius * (float)cos(2.0 * M_PI * index / sides_number);
    return {x, y};
}

void Polygon::gl_draw()
{
    gl_draw_polygon();
    gl_draw_shape();
}

void Polygon::gl_draw_shape()
{
    VerticesDelimiter delimiter(GL_LINE_LOOP);
    primary_color.gl_specify();
    gl_specify_vertices();
}

void Polygon::gl_draw_polygon()
{
    VerticesDelimiter delimiter(GL_POLYGON);
    secondary_color.gl_specify();
    gl_specify_vertices();
}

void Polygon::gl_specify_vertices()
{
    for (const auto &vertex : vertices_cache)
    {
        vertex.gl_specify();
    }
}
