//
// Created by apasemko on 4/23/2022.
//

#ifndef COMPUTERGRAPHICS_POLYGON_H
#define COMPUTERGRAPHICS_POLYGON_H

#include "../utils/Point.h"
#include "vector"

class Polygon
{
public:
    Polygon(const Coordinates &center, float radius, unsigned int sides = 5);
    void gl_draw();

private:
    void refresh();
    Coordinates get_vertex_coords_by_index(unsigned int index) const;
    void gl_draw_polygon();
    void gl_specify_vertices();
    void gl_draw_shape();

private:
    Point center;
    float radius;
    unsigned int sides_number;
    std::vector<Point> vertices_cache;
    Color primary_color{};
    Color secondary_color{};
};


#endif //COMPUTERGRAPHICS_POLYGON_H
